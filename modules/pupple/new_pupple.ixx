//  Copyright 2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

module;

#if defined(__GNUC__) || defined(__clang__)
#include <compare>
#include <cstdint>
#include <type_traits>
#include <utility>
#endif // defined(__GNUC__ ) || defined(__clang__)

export module NewPupple;

import Boost.TMP;

import Vanir.Utils.ThreeWayImpl;

#if _MSC_VER
import std;
#endif // _MSC_VER

namespace tmp = boost::tmp;

template<typename Data>
struct pupple_data
{
    Data value;
};

template<typename T>
using IsEmptyAndInheritible = tmp::bool_<(std::is_empty_v<T> && !std::is_final_v<T>)>;

template<typename T>
using PuppleDataT = tmp::call_<
    tmp::if_<
        tmp::lift_<IsEmptyAndInheritible>,
        tmp::identity_,
        tmp::always_<pupple_data<T>>
    >, T>;

template<std::size_t Key, typename Value, typename IV = PuppleDataT<Value>>
struct new_pupple_element : IV
{
    template<typename OV = Value>
    explicit(!std::convertible_to<OV, Value>) constexpr new_pupple_element(const OV& v)
        noexcept(std::is_nothrow_copy_constructible<OV>)
        : IV{v}
    {
    }

    constexpr new_pupple_element() = default;
};

template<std::size_t Key, typename Value>
constexpr decltype(auto) get_np(const new_pupple_element<Key, Value>& p)
{
    if constexpr(std::derived_from<new_pupple_element<Key, Value>, Value>)
    {
        return static_cast<Value>(p);
    }
    else
    {
        return static_cast<Value>(p.value);
    }
}

template<typename... Params>
struct PuppleDataContainer : new_pupple_element<typename Params::init_pos::value, typename Params::value>...
{
};


template<typename... PuppleMap>
struct PuppleBase;

template<typename InputPos>
struct matches_input_pos {
    template<typename T>
    using f = tmp::bool_<(InputPos::value == T::value)>;
};

template<typename InputPos, typename... MapElements>
using get_memory_pos = tmp::call_<tmp::find_if_<tmp::lift_<matches_input_pos<InputPos>::template f>>, typename MapElements::init_pos...>;

template<typename InputPos, typename... MapElements>
using get_type_from_input_pos = tmp::call_<tmp::index_<get_memory_pos<InputPos>>, typename MapElements::value...>;

template<std::size_t I, typename... Ts>
constexpr decltype(auto) get(PuppleDataContainer<Ts...> cont)
{
    return static_cast<new_pupple_element<I, tmp::call_<tmp::index_<tmp::sizet_<I>>, Ts...>>>(cont);
}

// MapElements are already pre-sorted when the map is generated.
template<typename... OGSequence, typename... MapElements>
struct PuppleBase<tmp::list_<OGSequence...>, MapElements...>
{
    template<typename ElemA, typename ElemB>
    using compare_init_pos = tmp::bool_<(ElemA::init_pos::value < ElemB::init_pos::value)>;

    template<typename... Ns>
    explicit constexpr PuppleBase(PuppleDataContainer<Ns...>&& cont)
        : m_pupple{get<typename OGSequence::value...>(cont)}
    {
    }

    template<typename... Ns>
    constexpr PuppleBase(Ns&&... ns)
        : PuppleBase{PuppleDataContainer<Ns...>{std::forward<Ns>(ns)...}}
    {
    }
    
    // using mapping      = MapType<MapElements...>;
    using element_list = tmp::list_<MapElements...>;

    PuppleDataContainer<MapElements...> m_pupple;
};

template<typename T, typename U>
using alignment_greater = tmp::bool_<((std::alignment_of_v<typename U::value>) < (std::alignment_of_v<typename T::value>))>;

// Sorts input types from greatest to least and maps their 
// original input order.
// For a given input:
// remap_by_size_<int, double, char>
// will output list_<sizet_<1>, sizet_<0>, sizet_<2>>
// as the mapping. In other words:
// int (0) -> (1)
// double (1) -> (0)
// char (2) -> (2)
// and the second part generated, pupple_data<double, int, char>
// actually represents how the types are stored.
template<typename... Ts>
using remap_by_size_ = tmp::call_<
    tmp::tee_<
        tmp::size_<tmp::make_sequence_<>>,
        tmp::map_<tmp::lift_<alignment_greater>>,
        tmp::lift_<PuppleBase>
    >, Ts...>;

export
{

template<typename... Ts>
struct NewTuple : remap_by_size_<Ts...>
{
    using remap_by_size_<Ts...>::remap_by_size_;

    template<class... Others, std::size_t... Is>
    constexpr bool equals(const NewTuple<Others...>& Right, std::index_sequence<Is...>) const
    {
        return ((get<Is>(this->m_pupple) == get<Is>(Right.m_pupple)) && ...);
    }

    template<typename... Others, std::size_t... Is>
    constexpr auto three_way_comp(const NewTuple<Others...>& Right, std::index_sequence<Is...>) const
    {
        std::common_comparison_category_t<Vanir::Utils::synth_three_way_result<Ts, Others>...> c;
        std::ignore = (((c = Vanir::Utils::synth_three_way{}(get<Is>(this->m_pupple), get<Is>(Right.m_pupple))) != 0) || ...);

        return c;
    }
};

template <class... Ts, class... Us>
[[nodiscard]] constexpr auto operator<=>(const NewTuple<Ts...>& Left, const NewTuple<Us...>& Right)
{
    static_assert(sizeof...(Ts) == sizeof...(Us), "cannot compare tuples of different sizes");

    if constexpr(sizeof...(Ts) != 0 && sizeof...(Us) != 0)
    {
        return Left.three_way_comp(Right, std::index_sequence_for<Ts...>{});
    }
    else // NewTuple<>
    {
        return std::strong_ordering::equal;
    }
}

template <class... Ts, class... Us>
[[nodiscard]] constexpr bool operator==(const NewTuple<Ts...>& Left, const NewTuple<Us...>& Right)
{
    static_assert(sizeof...(Ts) == sizeof...(Us), "cannot compare tuples of different sizes");
    
    if constexpr(sizeof...(Ts) != 0 && sizeof...(Us) != 0)
    {
        return Left.equals(Right, std::index_sequence_for<Ts...>{});
    }
    else // NewTuple<>
    {
        return true;
    }
}

} // export

constexpr NewTuple<char, double> nt{'c', 1.0};
