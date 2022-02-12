
export module Pupple.Map;

import <concepts>;
import <type_traits>;

import Boost.TMP;

import Pupple.Element;

export
{

template<typename T, typename U>
using alignment_greater = tmp::bool_<((std::alignment_of_v<T>) > (std::alignment_of_v<U>))>;

template <auto Key>
struct is_key
{
    template <typename T>
    struct f_impl;

    template <typename Value>
    struct f_impl<pupple_element<Key, Value>> : tmp::true_
    {
    };

    template <auto OtherKey, typename Value>
    struct f_impl<pupple_element<OtherKey, Value>> : tmp::false_
    {
    };

    template <typename T>
    using f = f_impl<T>;
};

template <typename... Params>
struct map;

template<typename Map, typename... Others>
concept IsEquivalentMap = std::is_same_v<Map, map<typename tmp::decay<Others>::type...>>;

template <typename... Params>
struct map : Params...
{
    using this_map_t = map<Params...>;

    template <typename... Others> requires IsEquivalentMap<this_map_t, Others...>
    constexpr map(Others&&... other) : Params(std::move(other))...
    {
    }

    // FIXME: Not sure if this makes sense.
    template <typename... Others> requires IsEquivalentMap<this_map_t, Others...>
    constexpr map(const map<Others...>& other) : Params(static_cast<Others&&>(other))...
    {
    }
};

template<typename L>
using nmap = tmp::call_<tmp::unpack_<tmp::lift_<map>>, L>;

template<typename L>
using smap = tmp::call_<tmp::unpack_<tmp::sort_<tmp::lift_<alignment_greater>, tmp::lift_<map>>>, L>;

template <unsigned int Name, typename Parameters>
struct value_type;

template <unsigned int Name, typename... Params>
struct value_type<Name, map<Params...>>
{
    using type = tmp::call_<tmp::find_if_<is_key<Name>, tmp::lift_<tmp::index_>>, Params...>;
};

template <unsigned int Key, typename... Params>
[[nodiscard]] constexpr auto get(map<Params...>& parameter_map) -> typename value_type<Key, Params...>::type&
{
    return get(parameter_map);
}

template <auto Key, typename... Params>
[[nodiscard]] constexpr auto get(const map<Params...>& parameter_map) ->
        typename const value_type<Key, Params...>::type&
{
    return get(parameter_map);
}

template <typename Name, typename Parameters>
struct has_key;

template <typename Name, typename... Params>
struct has_key<Name, map<Params...>> : tmp::call_<tmp::contains_<Name>, typename Params::key...>
{
};

} // export
