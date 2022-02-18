
export module Pupple;

import std.core;
import std.memory;

import Boost.TMP;

import Pupple.Element;

// TODO: Tuple element
// TODO: Accept std::ignore
// TODO: std::tie
// TODO: forward_as_tuple
// TODO: Tuple concatenation
// TODO: std::apply
// TODO: Construct from range
// TODO: Construct from std::tuple

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

    template<std::size_t... Indices, typename... Params>
    struct pupple_impl<std::integer_sequence<std::size_t, Indices...>, Params...>
            : pupple_element<Indices, Params>...
    {
        constexpr pupple_impl() = default;

        template<typename Other>
        explicit constexpr pupple_impl(from_other, Other&& other) : pupple_element<Indices, Params>(
                get<Indices>(std::move(other)))...
        {
        }

        template<typename... Ns>
        constexpr pupple_impl(Ns&&... ns)
                : pupple_element<Indices, Params>(std::move(ns))...
        {
        }

        auto operator<=>(const pupple_impl&) const = default;
    };
} // namespace detail
} // namespace aux

template<>
struct pupple<>
{
};

template<typename... Params>
struct pupple : aux::detail::pupple_impl<std::make_integer_sequence<std::size_t, sizeof...(Params)>, Params...>
{
    using Base = typename aux::detail::pupple_impl<std::make_integer_sequence<std::size_t, sizeof...(Params)>,
            Params...>;

    template <typename Other> requires(std::same_as<typename tmp::decay<Other>::type, pupple<Params...>>)
    constexpr pupple(Other&& other) : Base(aux::detail::from_other{}, std::move(other))
    {
    }

    template <typename... Ns>
    constexpr pupple(Ns&&... ns) : Base(std::move(ns)...)
    {
    }

    auto operator<=>(const pupple&) const = default;
};

template<std::size_t I, typename... Ts>
using indexed_at = tmp::call_<tmp::index_<tmp::sizet_<I>>, Ts...>;

template<typename... Params>
[[nodiscard]] constexpr auto make_pupple(Params&&... params)
{
    return pupple<typename tmp::decay<decltype(params)>::type...>(std::forward<Params>(params)...);
}

template<std::size_t I, typename... Ts, typename VT = indexed_at<I, Ts...>>
[[nodiscard]] constexpr const auto& get(const pupple<Ts...>& t) noexcept
{
    return get(static_cast<pupple_element<I, VT> const&>(t));
}

template<std::size_t I, typename... Ts, typename VT = indexed_at<I, Ts...>>
[[nodiscard]] constexpr auto& get(pupple<Ts...>& t) noexcept
{
    return get(static_cast<pupple_element<I, VT>&>(t));
}

template<std::size_t I, typename... Ts, typename VT = indexed_at<I, Ts...>>
[[nodiscard]] constexpr auto get(pupple<Ts...>&& t) noexcept
{
    return get(std::move(static_cast<pupple_element<I, VT>>(t)));
}

template<typename Mapping, typename Pupple>
struct PuppleBase {};

template<unsigned... Is, typename... Ts>
struct PuppleBase<tmp::list_<tmp::sizet_<Is>...>, pupple<Ts...>>
{
    template<typename I, typename NL = tmp::list_<tmp::sizet_<Is>...>>
    using actual_index = tmp::call_<tmp::unpack_<tmp::find_if_<tmp::is_<I>>>, NL>;

    template<std::size_t I>
    using type_at_index = tmp::call_<tmp::index_<tmp::sizet_<I>>, Ts...>;

    constexpr PuppleBase() = default;

    template<typename... Params>
    constexpr PuppleBase(pupple<Params...>&& p) : m_pupple{static_cast<indexed_at<Is, Params...>&&>(get<Is>(p))...}
    {
    }

    template<typename... Params>
    constexpr PuppleBase(Params&&... params) : PuppleBase{make_pupple(std::move(params)...)}
    {
    }

    template<typename... Params>
    constexpr PuppleBase(const pupple<Params...>& p) : m_pupple{static_cast<const indexed_at<Is, Params...>&>(get<Is>(p))...}
    {
    }

    template<typename... Params>
    constexpr PuppleBase(const Params&... params) : PuppleBase{make_pupple(static_cast<const Params&>(params)...)}
    {
    }

    auto operator<=>(const PuppleBase&) const = default;
    
    pupple<Ts...> m_pupple;
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

template<std::size_t I, typename... Us>
[[nodiscard]] constexpr auto get(const Tuple<Us...>& pup) noexcept
{
    return get<Tuple<Us...>::template actual_index<tmp::sizet_<I>>::value>(pup.m_pupple);
}

template<std::size_t I, typename... Us>
[[nodiscard]] constexpr auto get(Tuple<Us...>&& pup) noexcept
{
    return get<Tuple<Us...>::template actual_index<tmp::sizet_<I>>::value>(std::move(pup.m_pupple));
}

namespace aux::detail
{

// TODO: Determine the alignment of objects after appending.
template<typename... Ts, std::size_t... Is, typename... Us>
constexpr auto append_impl(std::integer_sequence<std::size_t, Is...>, Tuple<Ts...>&& elements, Us&&... params)
{
    return Tuple<typename tmp::decay<Ts>::type..., typename tmp::decay<Us>::type...>(
            get<Is>(elements)..., std::forward<Us>(params)...);
}

template<typename... Ts, std::size_t... Is, typename... Us>
constexpr auto append_impl(std::integer_sequence<std::size_t, Is...>, const Tuple<Ts...>& elements, Us&&... params)
{
    return Tuple<typename tmp::decay<Ts>::type..., typename tmp::decay<Us>::type...>(
            get<Is>(elements)..., std::forward<Us>(params)...);
}

} // namespace aux::detail

template<typename... Ts, typename... Us>
[[nodiscard]] constexpr auto append(Tuple<Ts...>&& elements, Us&&... params) noexcept
{
    return aux::detail::append_impl(std::make_integer_sequence<std::size_t, sizeof...(Ts)>(), std::move(elements), std::forward<Us>(params)...);
}

template<typename... Ts, typename... Us>
[[nodiscard]] constexpr auto append(const Tuple<Ts...>& elements, Us&&... params) noexcept
{
    return aux::detail::append_impl(std::make_integer_sequence<std::size_t, sizeof...(Ts)>(), elements, std::forward<Us>(params)...);
}

template<typename... Ts>
void swap(Tuple<Ts...>& a, Tuple<Ts...>& b) noexcept(std::is_nothrow_move_constructible<Tuple<Ts...>>::value &&
                                                     std::is_nothrow_move_assignable<Tuple<Ts...>>::value)
{
    using tuple_type = Tuple<Ts...>;

    tuple_type temp{std::move(a)};
    a = std::move(b);
    b = std::move(temp);
}

namespace std
{
    template<class... Ts>
    struct tuple_size<Tuple<Ts...>> : integral_constant<std::size_t, sizeof...(Ts)>
    {
    };

    template<std::size_t I, class... Ts>
    struct tuple_element<I, Tuple<Ts...>>
    {
        using type = typename Tuple<Ts...>::template type_at_index<I>;
    };
} // namespace std

template <class T, class P, std::size_t... I> requires(std::is_constructible_v<T,
                                                        decltype(get<I>(std::declval<P>()))...>)
constexpr T make_from_pupple_impl(P&& t, std::index_sequence<I...>)
{
    return T(get<I>(std::forward<P>(t))...);
}

template<class T, class P>
constexpr T make_from_pupple(P&& p)
{
    return make_from_pupple_impl<T>(std::forward<P>(p),
           std::make_index_sequence<std::tuple_size<std::remove_cvref_t<P>>::value>{});
}

template<class... Ts>
constexpr Tuple<Ts&...> puptie(Ts&... ts)
{
    return {ts...};
}

// CTAD
template<typename... Ts>
Tuple(Ts... ts) -> Tuple<Ts...>;

template<typename P1, typename P2, std::size_t... Is, std::size_t... Js>
constexpr auto pupple_cat_impl(P1&& a, P2&& b, std::index_sequence<Is...>, std::index_sequence<Js...>)
{
    return Tuple{get<Is>(std::forward<P1>(a))..., get<Js>(std::forward<P2>(b))...};
}

template<typename... Ts, typename... Us>
constexpr auto pupple_cat(Tuple<Ts...> p1, Tuple<Us...> p2)
{
    return pupple_cat_impl(p1, p2, std::make_index_sequence<sizeof...(Ts)>{}, std::make_index_sequence<sizeof...(Us)>{});
}

} // export
