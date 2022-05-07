

export module Pupple.Algorithm;

import Pupple;

import Boost.TMP;

#ifdef __GNUC__
import <cstdint>;
import <type_traits>;
#elif __clang__
import std;
#elif _MSC_VER
import std.core;
import std.memory;
#endif

// make_from_pupple impl
template <class T, class P, std::size_t... Is> requires(std::is_constructible_v<T,
                                                       decltype(get<Is>(std::declval<P>()))...>)
constexpr T make_from_pupple_impl(P&& t, std::index_sequence<Is...>)
{
    return T(get<Is>(std::forward<P>(t))...);
}

template<typename TP>
using tuple_indexer = std::make_index_sequence<std::tuple_size_v<TP>>;

template<std::size_t V, std::size_t... Is>
constexpr auto make_repeated_sequence(std::index_sequence<Is...>) -> std::index_sequence<(Is, V)...>
{
    return {};
}

template<std::size_t N, std::size_t V>
using repeated_sequence = decltype(make_repeated_sequence<V>(std::make_index_sequence<N>{}));

template<std::size_t... Is, std::size_t... Js>
constexpr std::index_sequence<Is..., Js...> concat_sequences(std::index_sequence<Is...>, std::index_sequence<Js...>)
{
    return {};
}

template<std::size_t... Is, std::size_t... Js, typename... Others>
constexpr auto concat_sequences(std::index_sequence<Is...>, std::index_sequence<Js...>, Others...)
{
    return concat_sequences(std::index_sequence<Is..., Js...>{}, Others{}...);
}

template<typename T>
constexpr std::index_sequence<> concat_sequences(std::index_sequence<>)
{
    return {};
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
    return []<typename TP, typename... Params, std::size_t... Is>(TP&& tp, std::index_sequence<Is...>, Params&&... ps)
        {
            return Tuple{get<Is>(tp)..., std::forward<Params>(ps)...};
        } (std::forward<TupleT>(elements), tuple_indexer<std::remove_reference_t<TupleT>>{}, std::forward<Us>(params)...);
}

template<class T, class P>
constexpr T make_from_pupple(P&& p)
{
    return make_from_pupple_impl<T>(std::forward<P>(p),
           std::make_index_sequence<std::tuple_size_v<std::remove_cvref_t<P>>>{});
}

// Forward As Pupple
template<typename... Ts>
constexpr Tuple<Ts&&...> forward_as_pupple(Ts&&... ts) noexcept // TODO: Conditionally noexcept?
{
    return Tuple<Ts&&...>(std::forward<Ts>(ts)...);
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
template<typename... TupleTs, std::size_t... Ns>
constexpr auto pupple_cat_impl(std::index_sequence<Ns...>, TupleTs&&... tps)
{
    auto cc_seq = concat_sequences(repeated_sequence<std::tuple_size_v<std::remove_reference_t<TupleTs>>, Ns>{}...);
    auto ts_seq = concat_sequences(std::make_index_sequence<std::tuple_size_v<std::remove_reference_t<TupleTs>>>{}...);

    return []<typename FullTuple, std::size_t... Is, std::size_t... Js>
        (FullTuple&& ft, std::index_sequence<Is...>, std::index_sequence<Js...>)
        {
            return Tuple{get<Is>(get<Js>(ft))...};
        } (Tuple{std::forward<TupleTs>(tps)...}, ts_seq, cc_seq);
}

template<typename... TupleTs>
constexpr auto pupple_cat(TupleTs&&... tps)
{
    return pupple_cat_impl(std::index_sequence_for<TupleTs...>{}, std::forward<TupleTs>(tps)...);
}

} // export