
export module Pupple;

import std.core;
import std.memory;

import Boost.TMP;

import Pupple.Element;

namespace tmp = boost::tmp;

template<typename... Ts>
struct pupple_impl;

struct from_other {};

template<std::size_t... Indices, typename... Params>
struct pupple_impl<std::index_sequence<Indices...>, Params...>
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

template <typename... Params>
struct pupple;

template<>
struct pupple<>
{
};

template<typename... Params>
struct pupple : pupple_impl<std::make_index_sequence<sizeof...(Params)>, Params...>
{
    using Base = pupple_impl<std::make_index_sequence<sizeof...(Params)>, Params...>;

    template <typename Other> requires(std::same_as<typename tmp::decay<Other>::type, pupple<Params...>>)
    constexpr pupple(Other&& other) : Base(from_other{}, std::move(other))
    {
    }

    template <typename... Ns>
    constexpr pupple(Ns&&... ns) : Base(std::move(ns)...)
    {
    }
};

template<std::size_t I, typename... Ts>
using indexed_at = tmp::call_<tmp::index_<tmp::sizet_<I>>, Ts...>;

template<typename... Params>
constexpr auto make_pupple(Params&&... params)
{
    return pupple<typename tmp::decay<decltype(params)>::type...>(std::forward<Params>(params)...);
}

template<std::size_t I, typename... Ts, typename VT = indexed_at<I, Ts...>>
constexpr const auto& get(const pupple<Ts...>& t) noexcept
{
    return get(static_cast<pupple_element<I, VT> const&>(t));
}

template<std::size_t I, typename... Ts, typename VT = indexed_at<I, Ts...>>
constexpr auto& get(pupple<Ts...>& t) noexcept
{
    return get(static_cast<pupple_element<I, VT>&>(t));
}

template<std::size_t I, typename... Ts, typename VT = indexed_at<I, Ts...>>
constexpr auto get(pupple<Ts...>&& t) noexcept
{
    return get(std::move(static_cast<pupple_element<I, VT>>(t)));
}

template<typename Mapping, typename Pupple>
struct PuppleBase {};

template<std::size_t... Is, typename... Ts>
struct PuppleBase<tmp::list_<tmp::sizet_<Is>...>, pupple<Ts...>>
{
    template<std::size_t I>
    using actual_index = tmp::call_<tmp::find_if_<tmp::is_<tmp::sizet_<I>>>, tmp::sizet_<Is>...>;

    template<std::size_t I>
    using type_at_index = tmp::call_<tmp::index_<tmp::sizet_<I>>, Ts...>;

    constexpr PuppleBase() = default;

    template<typename... Params>
    constexpr PuppleBase(pupple<Params...>&& p)
        : m_pupple{static_cast<indexed_at<Is, Params...>&&>(get<Is>(p))...}
    {
    }

    template<typename... Params>
    constexpr PuppleBase(Params&&... params)
        : PuppleBase{make_pupple(std::move(params)...)}
    {
    }

    template<typename... Params>
    constexpr PuppleBase(const pupple<Params...>& p)
        : m_pupple{static_cast<const indexed_at<Is, Params...>&>(get<Is>(p))...}
    {
    }

    template<typename... Params>
    constexpr PuppleBase(const Params&... params)
        : PuppleBase{make_pupple(static_cast<const Params&>(params)...)}
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

// Sorts input types from greatest to least and maps their 
// original input order.
// For a given input:
// remap_by_size_<int, double, char>
// will output list_<sizet_<1>, sizet_<0>, sizet_<2>>
// as the mapping. In other words:
// int (0) -> (1)
// double (1) -> (0)
// char (2) -> (2)
// and the second part generated, pupple<double, int, char>
// actually represents how the types are stored.
template<typename... Ts>
using remap_by_size_ = tmp::call_<
    tmp::zip_with_index_<tmp::listify_,
        tmp::sort_<tmp::lift_<align_greater_>,
            tmp::tee_<
                tmp::transform_<tmp::ui0_<>>,
                tmp::transform_<tmp::ui1_<>, tmp::lift_<pupple>>,
                tmp::lift_<PuppleBase>
            >
        >
    >, Ts...>;

template <class T, class P, std::size_t... Is> requires(std::is_constructible_v<T,
                                                       decltype(get<Is>(std::declval<P>()))...>)
constexpr T make_from_pupple_impl(P&& t, std::index_sequence<Is...>)
{
    return T(get<Is>(std::forward<P>(t))...);
}

template <class F, class T, std::size_t... Is>
constexpr decltype(auto) tapply_impl(F&& f, T&& t, std::index_sequence<Is...>)
{
    return std::invoke(std::forward<F>(f), get<Is>(std::forward<T>(t))...);
}

export
{

template<typename... Ts>
struct Tuple : remap_by_size_<Ts...>
{
    using remap_by_size_<Ts...>::remap_by_size_;
};

} // export

template<typename... Ts, std::size_t... Is, typename... Us>
constexpr auto append_impl(std::index_sequence<Is...>, Tuple<Ts...>&& elements, Us&&... params)
{
    return Tuple<typename tmp::decay<Ts>::type..., typename tmp::decay<Us>::type...>(
            get<Is>(elements)..., std::forward<Us>(params)...);
}

template<typename... Ts, std::size_t... Is, typename... Us>
constexpr auto append_impl(std::index_sequence<Is...>, const Tuple<Ts...>& elements, Us&&... params)
{
    return Tuple<typename tmp::decay<Ts>::type..., typename tmp::decay<Us>::type...>(
            get<Is>(elements)..., std::forward<Us>(params)...);
}

template<typename P1, typename P2, std::size_t... Is, std::size_t... Js>
constexpr auto pupple_cat_impl(P1&& a, P2&& b, std::index_sequence<Is...>, std::index_sequence<Js...>)
{
    return Tuple{get<Is>(std::forward<P1>(a))...,
                 get<Js>(std::forward<P2>(b))...};
}

template<typename P1, typename P2, std::size_t... Is, std::size_t... Js>
constexpr auto pupple_cat_impl(const P1& a, const P2& b, std::index_sequence<Is...>, std::index_sequence<Js...>)
{
    return Tuple{get<Is>(a)...,
                 get<Js>(b)...};
}

export
{

template<std::size_t I, typename... Us>
constexpr auto get(const Tuple<Us...>& pup) noexcept
{
    return get<Tuple<Us...>::template actual_index<I>::value>(pup.m_pupple);
}

template<std::size_t I, typename... Us>
constexpr auto& get(Tuple<Us...>& pup) noexcept
{
    return get<Tuple<Us...>::template actual_index<I>::value>(pup.m_pupple);
}

template<std::size_t I, typename... Us>
constexpr auto get(Tuple<Us...>&& pup) noexcept
{
    return get<Tuple<Us...>::template actual_index<I>::value>(std::move(pup.m_pupple));
}

template<typename... Ts, typename... Us>
constexpr auto append(Tuple<Ts...>&& elements, Us&&... params) noexcept
{
    return append_impl(std::make_index_sequence<sizeof...(Ts)>(), std::move(elements), std::forward<Us>(params)...);
}

template<typename... Ts, typename... Us>
constexpr auto append(const Tuple<Ts...>& elements, Us&&... params) noexcept
{
    return append_impl(std::make_index_sequence<sizeof...(Ts)>(), elements, std::forward<Us>(params)...);
}

template<std::swappable... Ts>
constexpr void swap(Tuple<Ts...>& a, Tuple<Ts...>& b) noexcept((std::is_nothrow_swappable_v<Ts> && ...))
{
    using tuple_type = Tuple<Ts...>;

    tuple_type temp{std::move(a)};
    a = std::move(b);
    b = std::move(temp);
}

template<std::swappable... Ts>
constexpr void swap(const Tuple<Ts...>& a, const Tuple<Ts...>& b) noexcept((std::is_nothrow_swappable_v<const Ts> && ...))
{
    using tuple_type = Tuple<Ts...>;

    tuple_type temp{std::move(a)};
    a = std::move(b);
    b = std::move(temp);
}

namespace std
{
    template<class... Ts>
    struct tuple_size<Tuple<Ts...>>
        : integral_constant<std::size_t, sizeof...(Ts)>
    {
    };

    template<std::size_t I, class... Ts>
    struct tuple_element<I, Tuple<Ts...>>
    {
        using type = typename Tuple<Ts...>::template type_at_index<I>;
    };   
} // namespace std

template<class T, class P>
constexpr T make_from_pupple(P&& p)
{
    return make_from_pupple_impl<T>(std::forward<P>(p),
           std::make_index_sequence<std::tuple_size_v<std::remove_cvref_t<P>>>{});
}

// CTAD
template<class... Ts>
Tuple(Ts... ts) -> Tuple<Ts...>;

template <class F, class T>
constexpr decltype(auto) tapply(F&& f, T&& t)
{
    return tapply_impl(std::forward<F>(f), std::forward<T>(t),
        std::make_index_sequence<std::tuple_size_v<std::remove_reference_t<T>>>{});
}

template<typename... Ts, typename... Us>
constexpr auto pupple_cat(Tuple<Ts...>&& p1, Tuple<Us...>&& p2)
{
    return pupple_cat_impl(std::forward<Tuple<Ts...>>(p1), std::forward<Tuple<Us...>>(p2),
        std::make_index_sequence<sizeof...(Ts)>{},
        std::make_index_sequence<sizeof...(Us)>{});
}

template<typename... Ts, typename... Us>
constexpr auto pupple_cat(const Tuple<Ts...>& p1, const Tuple<Us...>& p2)
{
    return pupple_cat_impl(p1, p2,
        std::make_index_sequence<sizeof...(Ts)>{},
        std::make_index_sequence<sizeof...(Us)>{});
}

template<typename... Ts, typename... Us, typename... Others>
constexpr auto pupple_cat(Tuple<Ts...>&& p1, Tuple<Us...>&& p2, Others&&... others)
{
    return pupple_cat(pupple_cat(std::forward<Tuple<Ts...>>(p1),
                                 std::forward<Tuple<Us...>>(p2)),
                                 std::forward<Others>(others)...);
}

template<typename... Ts, typename... Us, typename... Others>
constexpr auto pupple_cat(const Tuple<Ts...>& p1, const Tuple<Us...>& p2, const Others&... others)
{
    return pupple_cat(pupple_cat(p1, p2), others...);
}

} // export
