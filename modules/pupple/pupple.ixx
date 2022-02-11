
export module Pupple;

import <utility>;

import Boost.TMP;

import Pupple.Element;
import Pupple.Map;

export
{

namespace tmp = boost::tmp;

template <typename... Params>
struct pupple;

namespace aux
{
namespace detail
{
    template<typename Index, typename... Params>
    struct pupple_impl;

    struct from_other
    {
    };

    template<int... Indices, typename... Params>
    struct pupple_impl<std::integer_sequence<int, Indices...>, Params...>
            : pupple_element<tmp::uint_<Indices>, Params>...
    {
        constexpr pupple_impl() = default;

        template<typename Other>
        explicit constexpr pupple_impl(from_other, Other&& other) : pupple_element<tmp::uint_<Indices>, Params>(
                get<tmp::uint_<Indices>>(std::move(other)))...
        {
        }

        template<typename... Ns>
        constexpr pupple_impl(Ns&&... ns)
                : pupple_element<tmp::uint_<Indices>, Params>(std::move(ns))...
        {
        }

        auto operator<=>(const pupple_impl&) const = default;
    };

    // TODO: Determine the alignment of objects after appending.
    template<typename... Ts, int... Is, typename... Us>
    constexpr auto append_impl(std::integer_sequence<int, Is...>, pupple<Ts...>&& elements, Us&&... params)
    {
        return pupple<typename tmp::decay<Ts>::type..., typename tmp::decay<Us>::type...>(
                get<Is>(elements)..., std::forward<Us>(params)...);
    }

    template<typename... Ts, int... Is, typename... Us>
    constexpr auto append_impl(std::integer_sequence<int, Is...>, const pupple<Ts...>& elements, Us&&... params)
    {
        return pupple<typename tmp::decay<Ts>::type..., typename tmp::decay<Us>::type...>(
                get<Is>(elements)..., std::forward<Us>(params)...);
    }
} // namespace detail
} // namespace aux

template<typename... Params>
struct pupple : aux::detail::pupple_impl<std::make_integer_sequence<int, sizeof...(Params)>, Params...>
{
    using Base = typename aux::detail::pupple_impl<std::make_integer_sequence<int, sizeof...(Params)>,
            Params...>;

    // TODO: Replace with concepts when the time comes.
    template <typename Other, typename = typename std::enable_if_t<
                                      std::is_same_v<typename tmp::decay<Other>::type, pupple<Params...>>>>
    constexpr pupple(Other&& other) : Base(aux::detail::from_other{}, std::move(other))
    {
    }

    template <typename... Ns>
    constexpr pupple(Ns&&... ns) : Base(std::move(ns)...)
    {
    }

    auto operator<=>(const pupple&) const = default;

    // TODO: Add swapping.
};

template<typename... Params>
[[nodiscard]] constexpr auto make_pupple(Params&&... params)
{
    return pupple<typename tmp::decay<decltype(params)>::type...>(std::forward<Params>(params)...);
}

template<unsigned I, typename... Ts, typename VT = tmp::call_<tmp::index_<tmp::uint_<I>>, Ts...>>
[[nodiscard]] constexpr const auto& get(const pupple<Ts...>& t) noexcept
{
    return get(static_cast<pupple_element<tmp::uint_<I>, VT> const&>(t));
}

template<unsigned I, typename... Ts, typename VT = tmp::call_<tmp::index_<tmp::uint_<I>>, Ts...>>
[[nodiscard]] constexpr auto& get(pupple<Ts...>& t) noexcept
{
    return get(static_cast<pupple_element<tmp::uint_<I>, VT>&>(t));
}

template<unsigned I, typename... Ts, typename VT = tmp::call_<tmp::index_<tmp::uint_<I>>, Ts...>>
[[nodiscard]] constexpr auto&& get(pupple<Ts...>&& t) noexcept
{
    return get(std::move(static_cast<pupple_element<tmp::uint_<I>, VT>>(t)));
}

template<typename... Ts, typename... Us>
[[nodiscard]] constexpr auto append(pupple<Ts...>&& elements, Us&&... params) noexcept
{
    return aux::detail::append_impl(std::make_integer_sequence<int, sizeof...(Ts)>(), std::move(elements), std::forward<Us>(params)...);
}

template<typename... Ts, typename... Us>
[[nodiscard]] constexpr auto append(const pupple<Ts...>& elements, Us&&... params) noexcept
{
    return aux::detail::append_impl(std::make_integer_sequence<int, sizeof...(Ts)>(), elements, std::forward<Us>(params)...);
}

template<typename Mapping, typename Pupple>
struct PuppleBase {};

template<unsigned... Is, typename... Ts>
struct PuppleBase<tmp::list_<tmp::uint_<Is>...>, pupple<Ts...>>
{
    pupple<Ts...> m_pupple;

    using rep = tmp::list_<Ts...>;

    template<typename... Params>
    constexpr PuppleBase(pupple<Params...>&& p) : m_pupple{static_cast<tmp::call_<tmp::index_<tmp::uint_<Is>>, Params...>&&>(get<Is>(p))...}
    {
    }

    template<typename... Params>
    constexpr PuppleBase(Params&&... params) : PuppleBase{make_pupple(std::move(params)...)}
    {
    }

    template<typename... Params>
    constexpr PuppleBase(const pupple<Params...>& p) : m_pupple{static_cast<const tmp::call_<tmp::index_<tmp::uint_<Is>>, Params...>&>(get<Is>(p))...}
    {
    }

    template<typename... Params>
    constexpr PuppleBase(const Params&... params) : PuppleBase{make_pupple(static_cast<const Params&>(params)...)}
    {
    }
    
    template<typename I, typename NL = tmp::list_<tmp::uint_<Is>...>>
    using actual_index = tmp::call_<tmp::unpack_<tmp::find_if_<tmp::is_<I>>>, NL>;
};

template<typename T, typename U>
using alignment_greater = tmp::bool_<((std::alignment_of_v<T>) > (std::alignment_of_v<U>))>;

template<typename T, typename U>
using align_greater_ = tmp::call_<
    tmp::tee_<
        tmp::i0_<tmp::ui1_<>>,
        tmp::i1_<tmp::ui1_<>>,
        tmp::lift_<alignment_greater>
    >, T, U>;

template<typename... Ts>
using pair_with_index = tmp::call_<
    tmp::tee_<
        tmp::size_<tmp::make_sequence_<>>,
        tmp::listify_, 
        tmp::pairing_<tmp::listify_,
            tmp::sort_<tmp::lift_<align_greater_>,
                tmp::tee_<
                    tmp::transform_<tmp::ui0_<>>,
                    tmp::transform_<tmp::ui1_<>, tmp::lift_<pupple>>,
                    tmp::lift_<PuppleBase>
                >
            >
        >
    >, Ts...>;

template<typename... Ts>
struct Tuple : pair_with_index<Ts...>
{
    using pair_with_index<Ts...>::pair_with_index;
};

template<unsigned I, typename... Us>
[[nodiscard]] constexpr auto get(const Tuple<Us...>& pup) noexcept
{
    return get<typename Tuple<Us...>::template actual_index<tmp::uint_<I>>>(pup.m_pupple);
}

template<unsigned I, typename... Us>
[[nodiscard]] constexpr auto get(Tuple<Us...>&& pup) noexcept
{
    return get<typename Tuple<Us...>::template actual_index<tmp::uint_<I>>>(std::move(pup.m_pupple));
}

} // export
