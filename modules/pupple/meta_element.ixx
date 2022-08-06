
export module Pupple.Element;

import Boost.TMP;

#ifdef __GNUC__
import <cstdint>;
import <type_traits>;
#elif __clang__
import std;
#elif _MSC_VER
import std;
#endif

namespace tmp = boost::tmp;

// FIXME: Reference values?
export template<typename Data>
struct pupple_data
{
    [[msvc::no_unique_address]] Data value;
};

export template<typename T>
using IsEmptyAndInheritible = tmp::bool_<(std::is_empty_v<T> && !std::is_final_v<T>)>;

export template<typename T>
using PuppleDataT = tmp::call_<
    tmp::if_<
        tmp::lift_<IsEmptyAndInheritible>,
        tmp::identity_,
        tmp::always_<pupple_data<T>>
    >, T>;

export
{

template<std::size_t Key, typename Value, typename IV = PuppleDataT<Value>>
struct pupple_element : IV
{
    template<typename OV = Value>
    explicit(!std::convertible_to<OV, Value>) constexpr pupple_element(const OV& v)
        noexcept(std::is_nothrow_copy_constructible<OV>)
        : IV{v}
    {
    }

    template<typename OV = Value>
    explicit(!std::convertible_to<OV, Value>) constexpr pupple_element(OV&& v)
        noexcept(std::is_nothrow_move_constructible<OV>)
        : IV{std::forward<OV>(v)}
    {
    }
};

template<std::size_t Key, typename Value>
constexpr const Value& get(const pupple_element<Key, Value>& p)
{
    if constexpr(std::derived_from<pupple_element<Key, Value>, Value>)
    {
        return static_cast<const Value&>(p);
    }
    else
    {
        return static_cast<const Value&>(p.value);
    }
}

template<std::size_t Key, typename Value>
constexpr Value& get(pupple_element<Key, Value>& p)
{
    if constexpr(std::derived_from<pupple_element<Key, Value>, Value>)
    {
        return static_cast<Value&>(p);
    }
    else
    {
        return static_cast<Value&>(p.value);
    }
}

template<std::size_t Key, typename Value>
constexpr Value&& get(pupple_element<Key, Value>&& p)
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

template<std::size_t Key, typename Value>
constexpr const Value&& get(const pupple_element<Key, Value>&& p)
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
