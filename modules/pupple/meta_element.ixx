
export module Pupple.Element;

import std.core;

import Boost.TMP;

export
{

namespace tmp = boost::tmp;

// FIXME: Reference values?
template<typename Data>
struct pupple_data
{
    auto operator<=>(const pupple_data&) const = default;

    Data value;
};

template<typename T>
using IsEmptyAndInheritible = tmp::bool_<(std::is_empty_v<T> && !std::is_final_v<T>)>;

template<typename T>
using PuppleDataT = tmp::call_<tmp::if_<tmp::lift_<IsEmptyAndInheritible>, tmp::identity_, tmp::always_<pupple_data<T>>>, T>;

template<std::size_t Key, typename Value, typename IV = PuppleDataT<Value>>
struct pupple_element : IV
{
    constexpr pupple_element() = default;

    template<typename OV = Value>
    explicit(!std::convertible_to<OV, Value>) constexpr pupple_element(const OV& v) : IV{v}
    {
    }

    template<typename OV = Value>
    explicit(!std::convertible_to<OV, Value>) constexpr pupple_element(OV&& v) : IV{std::forward<OV>(v)}
    {
    }

    template<unsigned OtherKey, typename OtherValue>
    [[nodiscard]] constexpr auto operator<=>(const pupple_element<OtherKey, OtherValue>& otherPupple) const
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
    [[nodiscard]] constexpr auto operator==(const pupple_element<OtherKey, OtherValue>& otherPupple) const
    {
        if constexpr(std::derived_from<pupple_element<OtherKey, OtherValue>, pupple_data<OtherValue>>)
        {
            return this->value == otherPupple.value;
        }
        else
        {
            return *this == otherPupple;
        }
    }
};

template<std::size_t Key, typename Value>
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

template<std::size_t Key, typename Value>
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

template<std::size_t Key, typename Value>
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
