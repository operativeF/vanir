
//  Copyright 2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

module;

#if defined(__GNUC__) || defined(__clang__)
#include <concepts>
#include <cstdint>
#include <tuple>
#include <type_traits>
#include <utility>
#endif // defined(__GNUC__ ) || defined(__clang__)

export module Pupple:Algorithm;

import :PuppleImpl;

import Boost.TMP;

#if _MSC_VER
import std;
#endif // _MSC_VER

// make_from_pupple impl
template <class T, class P, std::size_t... Is> requires(std::is_constructible_v<T,
                                                       decltype(get<Is>(std::declval<P>()))...>)
constexpr T make_from_pupple_impl(P&& t, std::index_sequence<Is...>)
{
    return T(get<Is>(std::forward<P>(t))...);
}
    
template<typename TP>
using tuple_indexer = std::make_index_sequence<std::tuple_size_v<TP>>;

template<std::size_t N, std::size_t V>
using repeated_sequence = boost::tmp::call_<
    boost::tmp::repeat_sequence_<boost::tmp::sizet_<N>, 
        boost::tmp::lift_<boost::tmp::into_sequence>
    >, boost::tmp::sizet_<V>>;

template<typename... IndexSeqs>
using concat_seqs = boost::tmp::call_<
    boost::tmp::join_seq_<boost::tmp::lift_<boost::tmp::into_sequence>
    >, IndexSeqs...>;

template<typename... TupleTs, std::size_t... Ns>
constexpr auto pupple_cat_impl(std::index_sequence<Ns...>, TupleTs&&... tps)
{
    using cc_seq = concat_seqs<
        repeated_sequence<std::tuple_size_v<std::remove_cvref_t<TupleTs>>, Ns>...>;
    using ts_seq = concat_seqs<
        std::make_index_sequence<std::tuple_size_v<std::remove_cvref_t<TupleTs>>>...>;

    return []<typename FullTuple, std::size_t... Is, std::size_t... Js>
        (FullTuple&& ft, std::index_sequence<Is...>, std::index_sequence<Js...>)
        {
            return Tuple{get<Is>(get<Js>(std::forward<FullTuple>(ft)))...};
        } (Tuple{std::forward<TupleTs>(tps)...},
           ts_seq{},
           cc_seq{});
}

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
template<typename TupleT, typename... Us>
constexpr auto append(TupleT&& elements, Us&&... params) noexcept
{
    return []<typename TP, typename... Params, std::size_t... Is>
        (TP&& tp, std::index_sequence<Is...>, Params&&... ps)
        {
            return Tuple{get<Is>(tp)..., std::forward<Params>(ps)...};
        } (std::forward<TupleT>(elements),
           tuple_indexer<std::remove_cvref_t<TupleT>>{},
           std::forward<Us>(params)...);
}

template<class T, class P>
constexpr T make_from_pupple(P&& p)
{
    return make_from_pupple_impl<T>(std::forward<P>(p),
           std::make_index_sequence<std::tuple_size_v<std::remove_cvref_t<P>>>{});
}

// Forward As Pupple
template<typename... Ts>
constexpr decltype(auto) forward_as_pupple(Ts&&... ts) noexcept // TODO: Conditionally noexcept?
{
    return Tuple<Ts&&...>(std::forward<Ts>(ts)...);
}

// Swapping
template<std::swappable... Ts>
constexpr void swap(Tuple<Ts...>& a, Tuple<Ts...>& b)
    noexcept((std::is_nothrow_swappable_v<Ts> && ...))
{
    using tuple_type = Tuple<Ts...>;

    tuple_type temp{std::move(a)};
    a = std::move(b);
    b = std::move(temp);
}

template<std::swappable... Ts>
constexpr void swap(const Tuple<Ts...>& a, const Tuple<Ts...>& b)
    noexcept((std::is_nothrow_swappable_v<const Ts> && ...))
{
    using tuple_type = Tuple<Ts...>;

    tuple_type temp{std::move(a)};
    a = std::move(b);
    b = std::move(temp);
}

// Concatenation
template<typename... TupleTs>
constexpr decltype(auto) pupple_cat(TupleTs&&... tps)
{
    return pupple_cat_impl(std::index_sequence_for<TupleTs...>{}, std::forward<TupleTs>(tps)...);
}

// Concatenation operator+
template<typename TupleLeft, typename TupleRight>
constexpr decltype(auto) operator+(TupleLeft&& left, TupleRight&& right)
{
    return pupple_cat(std::forward<TupleLeft>(left), std::forward<TupleRight>(right));
}

// Gather
template<typename GatherType, typename... GatherTypes>
constexpr decltype(auto) gather(auto&& tps)
{
    using concatted = concat_seqs<
        typename std::remove_reference_t<decltype(tps)>::template get_indexes_of_type<GatherType>,
        typename std::remove_reference_t<decltype(tps)>::template get_indexes_of_type<GatherTypes>...>;

    return []<typename TT, std::size_t... Is>
        (TT&& tt, std::index_sequence<Is...>)
        {
            return Tuple{get<Is>(std::forward<TT>(tt))...};
        } (std::forward<decltype(tps)>(tps),
           concatted{});
}

} // export
