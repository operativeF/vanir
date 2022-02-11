
export module Pupple.Element;

import <type_traits>;
import <utility>;

import Boost.TMP;

export
{

namespace tmp = boost::tmp;

template <typename Key, typename Value, bool = std::is_empty_v<Value> && !std::is_final_v<Value>>
struct pupple_element;

template <typename Key, typename Value>
struct pupple_element<Key, Value, true> : Value
{
    using key   = Key;
    using value = Value;

    constexpr pupple_element() = default;
    constexpr pupple_element(pupple_element<Key, Value, true>&& p) : Value(std::move(p))
    {
    }
    constexpr pupple_element(const pupple_element<Key, Value, true>& p)
            : Value(static_cast<const Value&>(p))
    {
    }
    explicit constexpr pupple_element(const Value& v) : Value(v)
    {
    }
    explicit constexpr pupple_element(Value&& v) : Value(std::move(v))
    {
    }
};

template <typename Key, typename Value>
struct pupple_element<Key, Value, false>
{
    using key   = Key;
    using value = Value;

    constexpr pupple_element() = default;
    constexpr pupple_element(pupple_element<Key, Value>&& p)
            : data(std::forward<decltype(p.data)>(p.data))
    {
    }
    explicit constexpr pupple_element(const Value& v) : data(v)
    {
    }
    explicit constexpr pupple_element(Value&& v) : data(std::move(v))
    {
    }

    Value data{};
};

template<typename Key1, typename Value1, typename Key2, typename Value2>
[[nodiscard]] constexpr bool operator==(const pupple_element<Key1, Value1>& lhs, const pupple_element<Key2, Value2>& rhs)
{
    return lhs.data == rhs.data;
}

template<typename Key1, typename Value1, typename Key2, typename Value2>
[[nodiscard]] constexpr bool operator!=(const pupple_element<Key1, Value1>& lhs, const pupple_element<Key2, Value2>& rhs)
{
    return !(lhs == rhs);
}

template<typename Key1, typename Value1, typename Key2, typename Value2>
[[nodiscard]] constexpr bool operator<(const pupple_element<Key1, Value1>& lhs, const pupple_element<Key2, Value2>& rhs)
{
    return (lhs.data < rhs.data);
}

template<typename Key1, typename Value1, typename Key2, typename Value2>
[[nodiscard]] constexpr bool operator>(const pupple_element<Key1, Value1>& lhs, const pupple_element<Key2, Value2>& rhs)
{
    return !(lhs < rhs);
}

template<typename Key1, typename Value1, typename Key2, typename Value2>
[[nodiscard]] constexpr bool operator<=(const pupple_element<Key1, Value1>& lhs, const pupple_element<Key2, Value2>& rhs)
{
    return (lhs.data <= rhs.data);
}

template<typename Key1, typename Value1, typename Key2, typename Value2>
[[nodiscard]] constexpr bool operator>=(const pupple_element<Key1, Value1>& lhs, const pupple_element<Key2, Value2>& rhs)
{
    return !(lhs <= rhs);
}

template <typename Key, typename Value>
[[nodiscard]] constexpr const Value& get(const pupple_element<Key, Value, true>& p)
{
    return p;
}

template <typename Key, typename Value>
[[nodiscard]] constexpr Value& get(pupple_element<Key, Value, true>& p)
{
    return p;
}

template <typename Key, typename Value>
[[nodiscard]] constexpr Value&& get(pupple_element<Key, Value, true>&& p)
{
    return std::move(p);
}

template <typename Key, typename Value>
[[nodiscard]] constexpr const Value& get(const pupple_element<Key, Value, false>& p)
{
    return p.data;
}

template <typename Key, typename Value>
[[nodiscard]] constexpr Value& get(pupple_element<Key, Value, false>& p)
{
    return p.data;
}

template <typename Key, typename Value>
[[nodiscard]] constexpr Value&& get(pupple_element<Key, Value, false>&& p)
{
    return std::move(p.data);
}

} // export
