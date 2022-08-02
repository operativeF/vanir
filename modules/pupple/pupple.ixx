//  Copyright 2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

module;

#if defined(__GNUC__) || defined(__clang__)
#include <cstdint>
#endif // defined(__GNUC__ ) || defined(__clang__)

export module Pupple;

import Boost.TMP;

import Pupple.Element;

import Vanir.Utils.ThreeWayImpl;

#if _MSC_VER
import std;
#endif // _MSC_VER

namespace tmp = boost::tmp;

template<typename... Ts>
struct pupple_impl;

template<std::size_t... Indices, typename... Params>
struct pupple_impl<std::index_sequence<Indices...>, Params...>
        : pupple_element<Indices, Params>...
{
    template<typename... Ns>
    constexpr pupple_impl(Ns&&... ns)
            : pupple_element<Indices, Params>(std::forward<Ns>(ns))...
    {
    }
};

template<typename... Params>
struct pupple : pupple_impl<std::make_index_sequence<sizeof...(Params)>, Params...>
{
    using Base = pupple_impl<std::make_index_sequence<sizeof...(Params)>, Params...>;

    using Base::Base;
};

template<std::size_t I, typename... Ts>
using indexed_at = tmp::call_<tmp::index_<tmp::sizet_<I>>, Ts...>;

template<typename... Params>
constexpr auto make_pupple(Params&&... params)
{
    return pupple<std::remove_reference_t<Params>...>(std::forward<Params>(params)...);
}

template<std::size_t I, typename... Ts, typename VT = indexed_at<I, Ts...>>
constexpr const VT& get(const pupple<Ts...>& t) noexcept
{
    return get(static_cast<const pupple_element<I, VT>&>(t));
}

template<std::size_t I, typename... Ts, typename VT = indexed_at<I, Ts...>>
constexpr VT& get(pupple<Ts...>& t) noexcept
{
    return get(static_cast<pupple_element<I, VT>&>(t));
}

template<std::size_t I, typename... Ts, typename VT = indexed_at<I, Ts...>>
constexpr VT&& get(pupple<Ts...>&& t) noexcept
{
    return get(static_cast<pupple_element<I, VT>&&>(t));
}

template<std::size_t I, typename... Ts, typename VT = indexed_at<I, Ts...>>
constexpr const VT&& get(const pupple<Ts...>&& t) noexcept
{
    return get(static_cast<const pupple_element<I, VT>&&>(t));
}

template<std::size_t I, std::size_t... Is>
using actual_index = tmp::call_<tmp::find_if_<tmp::is_<tmp::sizet_<I>>>, tmp::sizet_<Is>...>;

template<typename It, std::size_t... Is>
using actual_index_t = tmp::call_<tmp::find_if_<tmp::is_<It>>, tmp::sizet_<Is>...>;

template<typename TypeToFind>
struct is_indexed_type
{
    template<typename InputType>
    using f = tmp::call_<tmp::ui1_<tmp::is_<TypeToFind>>, InputType>;
};

template<typename Mapping, typename Pupple>
struct PuppleBase;

template<std::size_t... Is, typename... Ts>
struct PuppleBase<tmp::list_<tmp::sizet_<Is>...>, pupple<Ts...>>
{
    template<std::size_t I>
    using actual_index_t = actual_index<I, Is...>;

    template<std::size_t I>
    using type_at_index = tmp::call_<tmp::index_<tmp::sizet_<I>>, Ts...>;

    // TODO: Multiple types
    // TODO: What if empty?
    template<typename T>
    using get_indexes_of_type = tmp::call_<
        tmp::zip_<tmp::listify_,
            tmp::filter_<typename tmp::lift_<is_indexed_type<T>::template f>,
                tmp::transform_<tmp::ui0_<>,
                    tmp::lift_<tmp::into_sequence>
                >
            >
        >, tmp::list_<tmp::sizet_<Is>...>, tmp::list_<Ts...>>;

    template<typename... Params>
    constexpr PuppleBase(Params&&... params)
        : PuppleBase{pupple<Params...>(std::forward<Params>(params)...)}
    {
    }
    
    template<typename... Params>
    explicit constexpr PuppleBase(pupple<Params...>&& p)
        : m_pupple{static_cast<indexed_at<Is, Params...>&&>(get<Is>(p))...}
    {
    }

    using param_list = boost::tmp::list_<Ts...>;

    pupple<Ts...> m_pupple{};
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

export
{

template<typename... Ts>
struct Tuple : remap_by_size_<Ts...>
{
    using remap_by_size_<Ts...>::remap_by_size_;

    template<class... Others, std::size_t... Is>
    constexpr bool equals(const Tuple<Others...>& Right, std::index_sequence<Is...>) const
    {
        return ((get<Is>(this->m_pupple) == get<Is>(Right.m_pupple)) && ...);
    }

    template<typename... Others, std::size_t... Is>
    constexpr auto three_way_comp(const Tuple<Others...>& Right, std::index_sequence<Is...>) const
    {
        std::common_comparison_category_t<Vanir::Utils::synth_three_way_result<Ts, Others>...> c;
        std::ignore = (((c = Vanir::Utils::synth_three_way{}(get<Is>(this->m_pupple), get<Is>(Right.m_pupple))) != 0) || ...);

        return c;
    }
};

template <class... Ts, class... Us>
[[nodiscard]] constexpr auto operator<=>(const Tuple<Ts...>& Left, const Tuple<Us...>& Right)
{
    static_assert(sizeof...(Ts) == sizeof...(Us), "cannot compare tuples of different sizes");

    if constexpr(sizeof...(Ts) != 0 && sizeof...(Us) != 0)
    {
        return Left.three_way_comp(Right, std::index_sequence_for<Ts...>{});
    }
    else // Tuple<>
    {
        return std::strong_ordering::equal;
    }
}

template <class... Ts, class... Us>
[[nodiscard]] constexpr bool operator==(const Tuple<Ts...>& Left, const Tuple<Us...>& Right)
{
    static_assert(sizeof...(Ts) == sizeof...(Us), "cannot compare tuples of different sizes");
    
    if constexpr(sizeof...(Ts) != 0 && sizeof...(Us) != 0)
    {
        return Left.equals(Right, std::index_sequence_for<Ts...>{});
    }
    else // Tuple<>
    {
        return true;
    }
}

// Deduction Guides
template<class... Ts>
Tuple(Ts... ts) -> Tuple<Ts...>;

template<std::size_t I, typename... Us>
constexpr const auto& get(const Tuple<Us...>& pup) noexcept
{
    return get<Tuple<Us...>::template actual_index_t<I>::value>(pup.m_pupple);
}

template<std::size_t I, typename... Us>
constexpr auto& get(Tuple<Us...>& pup) noexcept
{
    return get<Tuple<Us...>::template actual_index_t<I>::value>(pup.m_pupple);
}

template<std::size_t I, typename... Us>
constexpr auto get(Tuple<Us...>&& pup) noexcept
{
    return get<Tuple<Us...>::template actual_index_t<I>::value>(pup.m_pupple);
}

template<std::size_t I, typename... Us>
constexpr const auto&& get(const Tuple<Us...>&& pup) noexcept
{
    return get<Tuple<Us...>::template actual_index_t<I>::value>(pup.m_pupple);
}

template<typename F>
struct tuple_func_nothrow_invocable
{
    template<typename TupleArg>
    using f = std::is_nothrow_invocable<F, TupleArg>;
};

template<class F, class T>
using tuple_func_invoke_noexcept = boost::tmp::call_<
    boost::tmp::unpack_<
        boost::tmp::and_<
            boost::tmp::lift_<typename tuple_func_nothrow_invocable<std::remove_reference_t<F>>::template f>>
    >, typename std::remove_reference_t<T>::param_list>;

template<class F, class TupleType>
constexpr decltype(auto) tapply(F&& f, TupleType&& t) noexcept(tuple_func_invoke_noexcept<F, TupleType>::value)
{
    return []<std::size_t... Ns>(auto&& func, auto&& tup, std::index_sequence<Ns...>)
        {
            return std::invoke(std::forward<decltype(func)>(func), get<Ns>(std::forward<decltype(tup)>(tup))...);
        } (std::forward<F>(f),
           std::forward<TupleType>(t),
           std::make_index_sequence<std::tuple_size_v<std::remove_reference_t<TupleType>>>{});
}

} // export
