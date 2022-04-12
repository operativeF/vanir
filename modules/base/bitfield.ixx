
export module Utils.Bitfield;

import Boost.TMP;

import std.core;

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

    static constexpr value_type bitmask(const Enum& e)
    {
        return value_type{1} << static_cast<value_type>(e);
    }

    constexpr explicit operator bool() const
    {
        return m_fields != value_type{0};
    }

    template<BitfieldCompatible... Enums>
    static constexpr value_type bitmask(const Enums&... es)
    {
        return ((value_type{ 1 } << static_cast<value_type>(es)) | ...);
    }

    static constexpr value_type AllFlagsSet = bitmask(Enum::_max_size) - value_type{1};

    constexpr auto& operator|=(const Enum& e)
    {
        m_fields |= bitmask(e);

        return *this;
    }

    constexpr bool is_set(const Enum& e) const
    {
        auto fields = m_fields;
        fields &= bitmask(e);
        return fields != value_type{0};
    }

    constexpr auto& operator|=(const Bitfield& otherBf)
    {
        m_fields |= otherBf.as_value();

        return *this;
    }

    constexpr auto& operator&=(const Bitfield& otherBf)
    {
        m_fields &= otherBf.as_value();

        return *this;
    }

    constexpr auto& operator&=(const Enum& e)
    {
        m_fields &= bitmask(e);

        return *this;
    }

    constexpr auto& operator^=(const Enum& e)
    {
        m_fields ^= bitmask(e);

        return *this;
    }

    constexpr bool empty() const
    {
        return m_fields == value_type{0};
    };

    constexpr auto clear()
    {
        m_fields = value_type{0};
    }

    constexpr void set(const Enum& e)
    {
        m_fields |= bitmask(e);
    }

    template<BitfieldCompatible... Enums>
    constexpr void set(const Enums&... es)
    {
        m_fields |= (bitmask(es), ...);
    }

    constexpr void reset(const Enum& e)
    {
        m_fields &= ~bitmask(e);
    }

    constexpr void toggle(const Enum& e)
    {
        m_fields ^= bitmask(e);
    }

    // FIXME: Not correct for bitfields with invalid values.
    constexpr void set_all()
    {
        m_fields = (value_type{1} << static_cast<value_type>(Enum::_max_size)) - value_type{1};
    }

    // FIXME: Not correct for bitfields with invalid values.
    constexpr void toggle_all()
    {
        m_fields ^= AllFlagsSet;
    }

    constexpr auto as_value() const
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

template<auto T, auto...>
struct identity_type
{
    using type = typename decltype(T)::value_type;
};

template<auto... Conflicts>
struct resolver
{
    using base_conflict_type = typename identity_type<Conflicts...>::type;

    template<typename T, std::size_t N>
    consteval resolver(std::array<T, N> args)
    {
        std::vector<std::vector<base_conflict_type>> newarr{{std::ranges::begin(Conflicts), std::ranges::end(Conflicts)}...};

        std::ranges::for_each(newarr, [](auto&& cfs){ std::ranges::sort(cfs); });

        std::ranges::sort(args);

        std::ranges::for_each(newarr, [args](auto&& cfs){ if(std::ranges::includes(args, cfs)) { FAIL_CONSTEVAL; } }); // #1 Bitfield contains conflicting arguments.
    }
};

template<auto... Us>
struct bitfield
{
    // FIXME: common_type_t not currently working in 17.1.0?
    // using under_type = std::common_type<std::remove_all_extents_t<decltype(Us)>...>;

    // Delegated constructor that does nothing more than check whether or not
    // a set of passed in values (array) satisfy a set of arrays passed in (Us)
    // that act as checks.
    consteval bitfield(std::type_identity_t<resolver<Us...>> val)
    {
    }

    template<typename... Args> requires(!std::is_aggregate_v<Args> && ...) // NOTE: Prevent recursion.
    consteval bitfield(Args&&... args) : bitfield(std::array<std::common_type_t<Args...>, sizeof...(Args)>{args...})
    {
        value = (static_cast<int>(args) + ... + 0);
    }

    int value{};
};


template<BitfieldCompatible Enum>
constexpr auto operator|(InclBitfield<Enum> bf, const Enum& e)
{
    bf |= e;
    return bf;
}

template<BitfieldCompatible Enum>
constexpr auto operator&(InclBitfield<Enum> bf, const Enum& e)
{
    bf &= e;
    return bf;
}

template<BitfieldCompatible Enum>
constexpr auto operator&(InclBitfield<Enum> bf, const InclBitfield<Enum>& otherBf)
{
    bf &= otherBf;
    return bf;
}

template<BitfieldCompatible Enum>
constexpr auto operator&(const Enum& e, InclBitfield<Enum> bf)
{
    return bf & e;
}

template<BitfieldCompatible Enum>
constexpr auto operator^(InclBitfield<Enum> bf, const Enum& e)
{
    bf ^= e;
    return bf;
}

template<BitfieldCompatible Enum>
constexpr auto operator==(const Bitfield<Enum>& lhbf, const Bitfield<Enum>& rhbf)
{
    return lhbf.as_value() == rhbf.as_value();
}

template<BitfieldCompatible Enum> 
constexpr auto operator!=(const Bitfield<Enum>& lhbf, const Bitfield<Enum>& rhbf)
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
template<BitfieldCompatible Enum>
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

export
{

using namespace boost::tmp;

template<std::size_t Capacity>
using size_type = call_<
                   if_<less_eq_<sizet_<std::numeric_limits<std::uint8_t>::max()>>,
                    always_<std::uint8_t>,
                    if_<less_eq_<sizet_<std::numeric_limits<std::uint16_t>::max()>>,
                     always_<std::uint16_t>,
                     if_<less_eq_<sizet_<std::numeric_limits<std::uint32_t>::max()>>,
                      always_<std::uint32_t>,
                      if_<less_eq_<sizet_<std::numeric_limits<std::uint64_t>::max()>>,
                       always_<std::uint64_t>,
                       always_<std::size_t>
                      >
                     >
                    >
                   >, sizet_<Capacity>
                  >;

template<typename Enum, typename... Enums>
static constexpr bool enum_is_present = std::disjunction<std::is_same<Enum, Enums>...>::value;

// FIXME: For enums with a larger than usual initial value,
// there also needs to be an initial offset (a range).
// This happens in cases like Windows where enums are a set value,
// Values will be set like usual, but they will be converted upon
// access (so we only need to keep the offset).

template<BitfieldCompatible... Enums>
class CombineBitfield
{
public:
    // FIXME: What if _max_size == 0?
    // FIXME: Not correct.
    using value_type = size_type<(static_cast<size_t>(Enums::_max_size) + ... + 0)>;
    using enum_list = list_<Enums...>;
    
    template<typename Enum>
    using enum_index = call_<unpack_<find_if_<is_<Enum>>>, enum_list>;

    static constexpr auto max_options = (static_cast<value_type>(Enums::_max_size) + ... + 0);
    static constexpr auto total_enums = sizeof...(Enums);

    // TODO: What if enum is not part of bitfield collection?
    template<typename Enum, auto idx = enum_index<Enum>::value> requires(enum_is_present<Enum, Enums...>)
    constexpr value_type enum_offset(Enum e)
    {
        static constexpr auto enum_maximums = {static_cast<value_type>(Enums::_max_size)...};

        // value_type offset{};

        // ICE: Serious error occurs when using impromptu ranges. Crashes the compiler cl
        // and emits a weird error. 
        // for(auto enummax : std::views::counted(std::ranges::begin(enum_maximums), idx))
        // {
        //     offset += enummax;
        // }
        // return offset;

        return std::accumulate(std::begin(enum_maximums), std::begin(enum_maximums) + idx, value_type{0});
    }

    template<typename Enum> requires(enum_is_present<Enum, Enums...>)
    constexpr auto enum_offset_value(const Enum& e)
    {
        return static_cast<value_type>(e) + enum_offset(e);
    };

    constexpr CombineBitfield() {}
    
    template<typename Enum> requires(enum_is_present<Enum, Enums...>)
    explicit constexpr CombineBitfield(const Enum& e)
    {
        set(e);
    }

    // TODO: Should this *really* be available?
    // explicit constexpr CombineBitfield(value_type bits) : m_fields{bits} {}

    template<typename... OtherEnums> requires(enum_is_present<OtherEnums, Enums...> && ...)
    constexpr CombineBitfield(const OtherEnums&... es)
    {
        (set(es), ...);
    }

    template<typename Enum> requires(enum_is_present<Enum, Enums...>)
    constexpr value_type bitmask(const Enum& e)
    {
        return value_type{1} << enum_offset_value(e);
    }

    constexpr explicit operator bool() const
    {
        return m_fields != value_type{0};
    }

    template<typename... OtherEnums> requires(enum_is_present<OtherEnums, Enums...> && ...)
    constexpr value_type bitmask(const OtherEnums&... es)
    {
        return ((value_type{ 1 } << enum_offset_value(es)) | ...);
    }

    //static constexpr value_type AllFlagsSet = bitmask(Enum::_max_size) - value_type{1};

    template<typename Enum> requires(enum_is_present<Enum, Enums...>)
    constexpr auto& operator|=(const Enum& e)
    {
        m_fields |= bitmask(e);

        return *this;
    }

    template<typename Enum> requires(enum_is_present<Enum, Enums...>)
    constexpr bool is_set(const Enum& e) const
    {
        auto fields = m_fields;
        fields &= bitmask(e);
        return fields != value_type{0};
    }

    constexpr auto& operator|=(const CombineBitfield& otherBf)
    {
        m_fields |= otherBf.as_value();

        return *this;
    }

    constexpr auto& operator&=(const CombineBitfield& otherBf)
    {
        m_fields &= otherBf.as_value();

        return *this;
    }

    template<typename Enum> requires(enum_is_present<Enum, Enums...>)
    constexpr auto& operator&=(const Enum& e)
    {
        m_fields &= bitmask(e);

        return *this;
    }

    template<typename Enum> requires(enum_is_present<Enum, Enums...>)
    constexpr auto& operator^=(const Enum& e)
    {
        m_fields ^= bitmask(e);

        return *this;
    }

    constexpr bool empty() const
    {
        return m_fields == value_type{0};
    }

    constexpr auto clear()
    {
        m_fields = value_type{0};
    }

    template<typename Enum> requires(enum_is_present<Enum, Enums...>)
    constexpr void set(const Enum& e)
    {
        m_fields |= bitmask(e);
    }

    template<typename... OtherEnums> requires(enum_is_present<OtherEnums, Enums...> && ...)
    constexpr void set(const OtherEnums&... es)
    {
        m_fields |= (bitmask(es), ...);
    }

    template<typename Enum> requires(enum_is_present<Enum, Enums...>)
    constexpr void reset(const Enum& e)
    {
        m_fields &= ~bitmask(e);
    }

    template<typename Enum> requires(enum_is_present<Enum, Enums...>)
    constexpr void toggle(const Enum& e)
    {
        m_fields ^= bitmask(e);
    }

    constexpr void set_all()
    {
        m_fields = (value_type{1} << max_options) - value_type{1};
    }

    constexpr void toggle_all()
    {
        m_fields ^= ((value_type{1} << max_options) - value_type{1});
    }

    constexpr value_type as_enum_value() const
    {
        if(m_fields == 0)
            return 0;
        else
        {
            return m_fields - value_type{1};
        }
    }

    constexpr auto as_value() const
    {
        return m_fields;
    }

    constexpr bool operator==(const CombineBitfield& other) const
    {
        return m_fields == other.as_value();
    }
    
private:
    template<typename Enum> requires(enum_is_present<Enum, Enums...>)
    constexpr auto GetEnumIndex() const
    {
        return enum_index<Enum>::value;
    }

    value_type m_fields{};
};

template<BitfieldCompatible Enum, typename... Enums>
constexpr auto operator&(CombineBitfield<Enums...> bf, const Enum& e)
{
    bf &= e;
    return bf;
}

template<typename... Enums>
constexpr auto operator&(CombineBitfield<Enums...> bf, const CombineBitfield<Enums...>& otherBf)
{
    bf &= otherBf;
    return bf;
}

} // export
