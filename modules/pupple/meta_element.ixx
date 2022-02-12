
export module Pupple.Element;

import <compare>;
import <type_traits>;
import <utility>;

import Boost.TMP;

export
{

namespace tmp = boost::tmp;

template<typename Data>
struct pupple_data
{
    Data value;
};

template<typename V>
using in_val = tmp::bool_<(std::is_empty_v<V> && !std::is_final_v<V>)>;

template<unsigned int Key, typename Value, typename IV = tmp::call_<tmp::if_<tmp::lift_<in_val>, tmp::identity_, tmp::always_<pupple_data<Value>>>, Value>>
struct pupple_element : IV
{
    constexpr pupple_element() = default;

    constexpr pupple_element(pupple_element<Key, Value>&& p) : IV(std::move(p))
    {
    }
    constexpr pupple_element(const pupple_element<Key, Value>& p) : IV(p)
    {
    }
    explicit constexpr pupple_element(const Value& v) : IV(v)
    {
    }
    explicit constexpr pupple_element(Value&& v) : IV(std::move(v))
    {
    }

    constexpr pupple_element& operator=(const pupple_element&) = default;
    constexpr pupple_element& operator=(pupple_element&&) = default;

    template<unsigned OtherKey, typename OtherValue>
    constexpr auto operator<=>(const pupple_element<OtherKey, OtherValue>& otherPupple) const
    {
        if constexpr(std::derived_from<pupple_element<OtherKey, OtherValue>, pupple_data<OtherValue>>)
        {
            return this->value <=> otherPupple.value;
        }
        else
        {
            return *this <=> otherPupple;
        }
    }

    template<unsigned OtherKey, typename OtherValue>
    constexpr auto operator==(const pupple_element<OtherKey, OtherValue>& otherPupple) const
    {
        if constexpr(std::derived_from<pupple_element<OtherKey, OtherValue>, pupple_data<OtherValue>>)
        {
            return this->value == otherPupple.value;
        }
        else
        {
            return *this <=> otherPupple;
        }
    }
};

template <unsigned int Key, typename Value>
[[nodiscard]] constexpr const Value& get(const pupple_element<Key, Value>& p)
{
    if constexpr(std::derived_from<pupple_element<Key, Value>, Value>)
    {
        return p;
    }
    else
    {
        return p.value;
    }
}

template <unsigned int Key, typename Value>
[[nodiscard]] constexpr Value& get(pupple_element<Key, Value>& p)
{
    if constexpr(std::derived_from<pupple_element<Key, Value>, Value>)
    {
        return p;
    }
    else
    {
        return p.value;
    }
}

template <unsigned int Key, typename Value>
[[nodiscard]] constexpr Value&& get(pupple_element<Key, Value>&& p)
{
    if constexpr(std::derived_from<pupple_element<Key, Value>, Value>)
    {
        return std::move(p);
    }
    else
    {
        return std::move(p.value);
    }
}

} // export
