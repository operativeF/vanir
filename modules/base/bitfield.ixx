
export module Utils.Bitfield;

import Boost.TMP;

import <algorithm>;
import <compare>;
import <type_traits>;

template<typename Enum>
concept BitfieldCompatible =  requires
{
    requires(std::is_enum_v<Enum>);
    {Enum::_max_size};
};

export namespace nil::utils
{

template<BitfieldCompatible Enum>
class Bitfield;

template<typename Enum>
using InclBitfield = Bitfield<Enum>;

template<BitfieldCompatible Enum> 
class Bitfield
{
public:
    using value_type = std::underlying_type_t<Enum>;
    using type = Enum;
    using underlying_type = std::underlying_type_t<Enum>;

    constexpr Bitfield() {}

    explicit constexpr Bitfield(value_type bits) : m_fields{bits}
    {
    }

    explicit constexpr Bitfield(const Enum& e)
    {
        set(e);
    }

    constexpr Bitfield(const auto&... es)
    {
        (set(es), ...);
    }

    static constexpr value_type bitmask(const Enum& e) noexcept
    {
        return value_type{1} << static_cast<value_type>(e);
    }

    constexpr explicit operator bool() const noexcept
    {
        return m_fields != value_type{0};
    }

    template<BitfieldCompatible... Enums>
    static constexpr value_type bitmask(const Enums&... es) noexcept
    {
        return ((value_type{ 1 } << static_cast<value_type>(es)) | ...);
    }

    static constexpr value_type AllFlagsSet = bitmask(Enum::_max_size) - value_type{1};

    constexpr auto& operator|=(const Enum& e) noexcept
    {
        m_fields |= bitmask(e);

        return *this;
    }

    constexpr bool is_set(const Enum& e) const noexcept
    {
        auto fields = m_fields;
        fields &= bitmask(e);
        return fields != value_type{0};
    }

    constexpr auto& operator|=(const Bitfield& otherBf) noexcept
    {
        m_fields |= otherBf.as_value();

        return *this;
    }

    constexpr auto& operator&=(const Bitfield& otherBf) noexcept
    {
        m_fields &= otherBf.as_value();

        return *this;
    }

    constexpr auto& operator&=(const Enum& e) noexcept
    {
        m_fields &= bitmask(e);

        return *this;
    }

    constexpr auto& operator^=(const Enum& e) noexcept
    {
        m_fields ^= bitmask(e);

        return *this;
    }

    constexpr bool empty() const noexcept
    {
        return m_fields == value_type{0};
    };

    constexpr auto clear() noexcept
    {
        m_fields = value_type{0};
    }

    constexpr void set(const Enum& e) noexcept
    {
        m_fields |= bitmask(e);
    }

    template<BitfieldCompatible... Enums>
    constexpr void set(const Enums&... es) noexcept
    {
        m_fields |= (bitmask(es), ...);
    }

    constexpr void reset(const Enum& e) noexcept
    {
        m_fields &= ~bitmask(e);
    }

    constexpr void toggle(const Enum& e) noexcept
    {
        m_fields ^= bitmask(e);
    }

    constexpr void set_all() noexcept
    {
        m_fields = (value_type{1} << static_cast<value_type>(Enum::_max_size)) - value_type{1};
    }

    constexpr void toggle_all() noexcept
    {
        m_fields ^= AllFlagsSet;
    }

    constexpr auto as_value() const noexcept
    {
        return m_fields;
    }

private:
    value_type m_fields{};
};

using namespace boost::tmp;

template <typename T, typename U>
using less = bool_<(T::value < U::value)>;

template<auto... Es> requires(std::is_enum_v<decltype(Es)> || ...)
using enum_list = call_<sort_<lift_<less>>, int_<static_cast<std::underlying_type_t<decltype(Es)>>(Es)>...>;

template<auto E1, auto E2, auto... Es>
using conflict_list = enum_list<E1, E2, Es...>;

template<typename InputFields, typename ConflictFields>
concept check_conflicts = requires
{
    requires call_<unpack_<or_<is_<InputFields>, not_<>>>, ConflictFields>;
};

#define FAIL_CONSTEVAL throw

consteval void exclusive_check_(auto t, auto u)
{

}

template <auto... T>
struct Checker {
    consteval void check_(auto t, auto u)
    {
        std::ranges::sort(t);
        std::ranges::sort(u);

        if(std::ranges::includes(t, u))
        {
            FAIL_CONSTEVAL; // #1 Invalid pattern found.
        }
    }

    consteval Checker(auto vals) {
        (check_(T, vals), ...);
    }
};

template <auto... T>
void fmt(std::type_identity_t<Checker<T...>> checked)
{
    
}

template<BitfieldCompatible Enum>
constexpr auto operator|(InclBitfield<Enum> bf, const Enum& e) noexcept
{
    bf |= e;
    return bf;
}

template<BitfieldCompatible Enum>
constexpr auto operator&(InclBitfield<Enum> bf, const Enum& e) noexcept
{
    bf &= e;
    return bf;
}

template<BitfieldCompatible Enum>
constexpr auto operator&(InclBitfield<Enum> bf, const InclBitfield<Enum>& otherBf) noexcept
{
    bf &= otherBf;
    return bf;
}

template<BitfieldCompatible Enum>
constexpr auto operator&(const Enum& e, InclBitfield<Enum> bf) noexcept
{
    return bf & e;
}

template<BitfieldCompatible Enum>
constexpr auto operator^(InclBitfield<Enum> bf, const Enum& e) noexcept
{
    bf ^= e;
    return bf;
}

template<BitfieldCompatible Enum>
constexpr auto operator==(const Bitfield<Enum>& lhbf, const Bitfield<Enum>& rhbf) noexcept
{
    return lhbf.as_value() == rhbf.as_value();
}

template<BitfieldCompatible Enum> 
constexpr auto operator!=(const Bitfield<Enum>& lhbf, const Bitfield<Enum>& rhbf) noexcept
{
    return !(lhbf.as_value() == rhbf.as_value());
}

template<typename... Enums>
concept CombinableBitfield = requires
{
    requires(BitfieldCompatible<Enums> && ...);
};

template<typename Enum, typename... Enums>
concept IsValidEnumForBitfield = requires
{
    requires(boost::tmp::call_<boost::tmp::contains_<Enum>, Enums...>::value == true);
};

// Only a single field may be set at any time.
// Use with CombineBitfield to have Singular Bitfields with combinations of other,
// possibly non-singular, bitfields.
template<typename Enum> requires(BitfieldCompatible<Enum>)
class SingularBitfield
{
public:
    using value_type = std::underlying_type_t<Enum>;

    constexpr SingularBitfield() {}

    constexpr SingularBitfield(const Enum& e)
    {
        set(e);
    }

private:
    value_type m_fields;
};

} // export

// A bitfield that takes multiple options, but has some option combinations
// that are invalid.
//template<typename Enum, typename... ConflictValues>
//class ConflictBitfield
//{
//public:
//private:
//};

namespace
{

template<typename Enum, typename... Enums>
struct IndexOfEnum
{
    using index = boost::tmp::call_<boost::tmp::find_if_<boost::tmp::is_<Enum>>, Enums...>;
};

template<unsigned int N, typename... Enums>
struct OffsetOfEnum
{
    using as_ints = boost::tmp::list_<boost::tmp::uint_<static_cast<unsigned int>(Enums::_max_size)>...>;
    using offset = boost::tmp::call_<boost::tmp::take_<boost::tmp::uint_<N>, boost::tmp::accumulate_<>>, as_ints>;
};

template<typename... Enums>
struct EnumOptionsCount
{
    using as_type = boost::tmp::list_<boost::tmp::uint_<static_cast<unsigned int>(Enums::_max_size)>...>;

    using count = boost::tmp::call_<boost::tmp::unpack_<boost::tmp::accumulate_<>>, as_type>;
};

}

export
{

template<typename... Enums> requires(CombinableBitfield<Enums...>)
class CombineBitfield
{
public:
    template<typename Enum>
    using enum_index = IndexOfEnum<Enum, Enums...>::index;

    template<unsigned int N>
    using enum_offset = OffsetOfEnum<N, Enums...>::offset;

    using enum_count = boost::tmp::uint_<sizeof...(Enums)>;

    using value_type = std::common_type_t<std::underlying_type_t<Enums>...>;

    using max_options_t = typename EnumOptionsCount<Enums...>::count;

    constexpr CombineBitfield() {}
    
    template<typename Enum> requires(IsValidEnumForBitfield<Enum, Enums...>)
    explicit constexpr CombineBitfield(const Enum& e)
    {
        set(e);
    }

    explicit constexpr CombineBitfield(value_type bits) : m_fields{bits} {}

    template<typename... OtherEnums> requires(IsValidEnumForBitfield<OtherEnums, Enums...> && ...)
    constexpr CombineBitfield(const OtherEnums&... es)
    {
        (set(es), ...);
    }

    template<typename Enum> requires(IsValidEnumForBitfield<Enum, Enums...>)
    static constexpr value_type bitmask(const Enum& e) noexcept
    {
        return value_type{1} << static_cast<value_type>(e);
    }

    constexpr explicit operator bool() const noexcept
    {
        return m_fields != value_type{0};
    }

    template<typename... OtherEnums> requires(IsValidEnumForBitfield<OtherEnums, Enums...> && ...)
    static constexpr value_type bitmask(const OtherEnums&... es) noexcept
    {
        return ((value_type{ 1 } << static_cast<value_type>(es)) | ...);
    }

    //static constexpr value_type AllFlagsSet = bitmask(Enum::_max_size) - value_type{1};

    template<typename Enum> requires(IsValidEnumForBitfield<Enum, Enums...>)
    constexpr auto& operator|=(const Enum& e) noexcept
    {
        m_fields |= bitmask(e);

        return *this;
    }

    template<typename Enum> requires(IsValidEnumForBitfield<Enum, Enums...>)
    constexpr bool is_set(const Enum& e) const noexcept
    {
        auto fields = m_fields;
        fields &= bitmask(e);
        return fields != value_type{0};
    }

    constexpr auto& operator|=(const CombineBitfield& otherBf) noexcept
    {
        m_fields |= otherBf.as_value();

        return *this;
    }

    constexpr auto& operator&=(const CombineBitfield& otherBf) noexcept
    {
        m_fields &= otherBf.as_value();

        return *this;
    }

    template<typename Enum> requires(IsValidEnumForBitfield<Enum, Enums...>)
    constexpr auto& operator&=(const Enum& e) noexcept
    {
        m_fields &= bitmask(e);

        return *this;
    }

    template<typename Enum> requires(IsValidEnumForBitfield<Enum, Enums...>)
    constexpr auto& operator^=(const Enum& e) noexcept
    {
        m_fields ^= bitmask(e);

        return *this;
    }

    constexpr bool empty() const noexcept
    {
        return m_fields == value_type{0};
    }

    constexpr auto clear() noexcept
    {
        m_fields = value_type{0};
    }

    template<typename Enum> requires(IsValidEnumForBitfield<Enum, Enums...>)
    constexpr void set(const Enum& e) noexcept
    {
        m_fields |= bitmask(e);
    }

    template<typename... OtherEnums> requires(IsValidEnumForBitfield<OtherEnums, Enums...> && ...)
    constexpr void set(const OtherEnums&... es) noexcept
    {
        m_fields |= (bitmask(es), ...);
    }

    template<typename Enum> requires(IsValidEnumForBitfield<Enum, Enums...>)
    constexpr void reset(const Enum& e) noexcept
    {
        m_fields &= ~bitmask(e);
    }

    template<typename Enum> requires(IsValidEnumForBitfield<Enum, Enums...>)
    constexpr void toggle(const Enum& e) noexcept
    {
        m_fields ^= bitmask(e);
    }

    constexpr void set_all() noexcept
    {
        m_fields = (value_type{1} << max_options_t::value) - value_type{1};
    }

    constexpr void toggle_all() noexcept
    {
        m_fields ^= ((value_type{1} << max_options_t::value) - value_type{1});
    }

    constexpr auto as_value() const noexcept
    {
        return m_fields;
    }

    auto operator<=>(const CombineBitfield&) const noexcept = default;
    
private:
    template<typename Enum> requires(IsValidEnumForBitfield<Enum, Enums...>)
    constexpr auto GetEnumIndex() const noexcept
    {
        return enum_index<Enum>::value;
    }

    value_type m_fields{};
};

template<typename Enum, typename... Enums> requires(CombinableBitfield<Enum, Enums...>)
constexpr auto operator&(CombineBitfield<Enums...> bf, const Enum& e) noexcept
{
    bf &= e;
    return bf;
}

template<typename... Enums> requires(CombinableBitfield<Enums...>)
constexpr auto operator&(CombineBitfield<Enums...> bf, const CombineBitfield<Enums...>& otherBf) noexcept
{
    bf &= otherBf;
    return bf;
}

} // export
