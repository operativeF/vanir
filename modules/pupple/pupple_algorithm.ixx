

export module Pupple.Algorithm;

import Pupple;

import Boost.TMP;

import std.core;
import std.memory;

// make_from_pupple impl
template <class T, class P, std::size_t... Is> requires(std::is_constructible_v<T,
                                                       decltype(get<Is>(std::declval<P>()))...>)
constexpr T make_from_pupple_impl(P&& t, std::index_sequence<Is...>)
{
    return T(get<Is>(std::forward<P>(t))...);
}

template<typename TP>
using tuple_indexer = std::make_index_sequence<std::tuple_size_v<TP>>;

export
{

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

// Append
template<typename... Ts, typename... Us>
constexpr auto append(Tuple<Ts...>&& elements, Us&&... params) noexcept
{
    return []<typename... TParams, typename... Params, std::size_t... Is>(Tuple<TParams...>&& tp, std::index_sequence<Is...>, Params&&... ps)
        {
            return Tuple<typename tmp::decay<TParams>::type..., typename tmp::decay<Params>::type...>(
                         get<Is>(tp)..., std::forward<Params>(ps)...);
        } (std::forward<Tuple<Ts...>>(elements), std::index_sequence_for<Ts...>{}, std::forward<Us>(params)...);
}

template<typename... Ts, typename... Us>
constexpr auto append(const Tuple<Ts...>& elements, const Us&... params) noexcept
{
    return []<typename... TParams, typename... Params, std::size_t... Is>(const Tuple<TParams...>& tp, std::index_sequence<Is...>, const Params&... ps)
        {
            return Tuple<typename tmp::decay<TParams>::type..., typename tmp::decay<Params>::type...>(
                         get<Is>(tp)..., ps...);
        } (elements, std::index_sequence_for<Ts...>{}, params...);
}

template<typename... Ts, typename... Us>
constexpr auto append(const Tuple<Ts...>& elements, Us&&... params) noexcept
{
    return []<typename... TParams, typename... Params, std::size_t... Is>(const Tuple<TParams...>& tp, std::index_sequence<Is...>, Params&&... ps)
        {
            return Tuple<typename tmp::decay<TParams>::type..., typename tmp::decay<Params>::type...>(
                         get<Is>(tp)..., std::forward<Params>(ps)...);
        } (elements, std::index_sequence_for<Ts...>{}, std::forward<Us>(params)...);
}

template<class T, class P>
constexpr T make_from_pupple(P&& p)
{
    return make_from_pupple_impl<T>(std::forward<P>(p),
           std::make_index_sequence<std::tuple_size_v<std::remove_cvref_t<P>>>{});
}

// Swapping
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

// Concatenation
template<typename TupleA, typename TupleB>
constexpr auto pupple_cat(TupleA&& p1, TupleB&& p2)
{
    return []<typename TP0, typename TP1, std::size_t... Is, std::size_t... Js>
        (TP0&& tp0, TP1&& tp1, std::index_sequence<Is...>, std::index_sequence<Js...>)
        {
            return Tuple{get<Is>(tp0)...,
                         get<Js>(tp1)...};
        } (std::forward<TupleA>(p1),
           std::forward<TupleB>(p2),
           tuple_indexer<std::remove_reference_t<TupleA>>{},
           tuple_indexer<std::remove_reference_t<TupleB>>{});
}

template<typename TupleA, typename TupleB, typename... Others>
constexpr auto pupple_cat(TupleA&& p1, TupleB&& p2, Others&&... others)
{
    return pupple_cat(pupple_cat(std::forward<TupleA>(p1),
                                 std::forward<TupleB>(p2)),
                                 std::forward<Others>(others)...);
}

} // export