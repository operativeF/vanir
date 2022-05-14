//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Meter;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using meter_tag_t = tmp::list_<tmp::list_<meter_l>, tmp::list_<>>;

    template<typename T>
    concept MeterC = std::same_as<typename T::impl, meter_tag_t>;

    template <typename RatioTypeT, typename P>
    struct meter_impl {

        static constexpr auto pretty = "l";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = meter_tag_t;

        constexpr meter_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exameter_ld    =     meter_impl<std::exa, long double>;
    using petameter_ld    =     meter_impl<std::peta, long double>;
    using terameter_ld    =     meter_impl<std::tera, long double>;
    using gigameter_ld    =     meter_impl<std::giga, long double>;
    using megameter_ld    =     meter_impl<std::mega, long double>;
    using kilometer_ld    =     meter_impl<std::kilo, long double>;
    using hectometer_ld    =     meter_impl<std::hecto, long double>;
    using decameter_ld    =     meter_impl<std::deca, long double>;
    using meter_ld    =     meter_impl<unity_ratio, long double>;
    using decimeter_ld    =     meter_impl<std::deci, long double>;
    using centimeter_ld    =     meter_impl<std::centi, long double>;
    using millimeter_ld    =     meter_impl<std::milli, long double>;
    using micrometer_ld    =     meter_impl<std::micro, long double>;
    using nanometer_ld    =     meter_impl<std::nano, long double>;
    using picometer_ld    =     meter_impl<std::pico, long double>;
    using femtometer_ld    =     meter_impl<std::femto, long double>;
    using attometer_ld    =     meter_impl<std::atto, long double>;
    using exameter_ull    =     meter_impl<std::exa, unsigned long long>;
    using petameter_ull    =     meter_impl<std::peta, unsigned long long>;
    using terameter_ull    =     meter_impl<std::tera, unsigned long long>;
    using gigameter_ull    =     meter_impl<std::giga, unsigned long long>;
    using megameter_ull    =     meter_impl<std::mega, unsigned long long>;
    using kilometer_ull    =     meter_impl<std::kilo, unsigned long long>;
    using hectometer_ull    =     meter_impl<std::hecto, unsigned long long>;
    using decameter_ull    =     meter_impl<std::deca, unsigned long long>;
    using meter_ull    =     meter_impl<unity_ratio, unsigned long long>;
    using decimeter_ull    =     meter_impl<std::deci, unsigned long long>;
    using centimeter_ull    =     meter_impl<std::centi, unsigned long long>;
    using millimeter_ull    =     meter_impl<std::milli, unsigned long long>;
    using micrometer_ull    =     meter_impl<std::micro, unsigned long long>;
    using nanometer_ull    =     meter_impl<std::nano, unsigned long long>;
    using picometer_ull    =     meter_impl<std::pico, unsigned long long>;
    using femtometer_ull    =     meter_impl<std::femto, unsigned long long>;
    using attometer_ull    =     meter_impl<std::atto, unsigned long long>;

    constexpr exameter_ld operator""_Em(long double val) {
        return static_cast<exameter_ld>(val);
    }
    constexpr petameter_ld operator""_Pm(long double val) {
        return static_cast<petameter_ld>(val);
    }
    constexpr terameter_ld operator""_Tm(long double val) {
        return static_cast<terameter_ld>(val);
    }
    constexpr gigameter_ld operator""_Gm(long double val) {
        return static_cast<gigameter_ld>(val);
    }
    constexpr megameter_ld operator""_Mm(long double val) {
        return static_cast<megameter_ld>(val);
    }
    constexpr kilometer_ld operator""_km(long double val) {
        return static_cast<kilometer_ld>(val);
    }
    constexpr hectometer_ld operator""_hm(long double val) {
        return static_cast<hectometer_ld>(val);
    }
    constexpr decameter_ld operator""_dam(long double val) {
        return static_cast<decameter_ld>(val);
    }
    constexpr meter_ld operator""_m(long double val) {
        return static_cast<meter_ld>(val);
    }
    constexpr decimeter_ld operator""_dm(long double val) {
        return static_cast<decimeter_ld>(val);
    }
    constexpr centimeter_ld operator""_cm(long double val) {
        return static_cast<centimeter_ld>(val);
    }
    constexpr millimeter_ld operator""_mm(long double val) {
        return static_cast<millimeter_ld>(val);
    }
    constexpr micrometer_ld operator""_um(long double val) {
        return static_cast<micrometer_ld>(val);
    }
    constexpr nanometer_ld operator""_nm(long double val) {
        return static_cast<nanometer_ld>(val);
    }
    constexpr picometer_ld operator""_pm(long double val) {
        return static_cast<picometer_ld>(val);
    }
    constexpr femtometer_ld operator""_fm(long double val) {
        return static_cast<femtometer_ld>(val);
    }
    constexpr attometer_ld operator""_am(long double val) {
        return static_cast<attometer_ld>(val);
    }
    constexpr exameter_ull operator""_Em(unsigned long long val) {
        return static_cast<exameter_ull>(val);
    }
    constexpr petameter_ull operator""_Pm(unsigned long long val) {
        return static_cast<petameter_ull>(val);
    }
    constexpr terameter_ull operator""_Tm(unsigned long long val) {
        return static_cast<terameter_ull>(val);
    }
    constexpr gigameter_ull operator""_Gm(unsigned long long val) {
        return static_cast<gigameter_ull>(val);
    }
    constexpr megameter_ull operator""_Mm(unsigned long long val) {
        return static_cast<megameter_ull>(val);
    }
    constexpr kilometer_ull operator""_km(unsigned long long val) {
        return static_cast<kilometer_ull>(val);
    }
    constexpr hectometer_ull operator""_hm(unsigned long long val) {
        return static_cast<hectometer_ull>(val);
    }
    constexpr decameter_ull operator""_dam(unsigned long long val) {
        return static_cast<decameter_ull>(val);
    }
    constexpr meter_ull operator""_m(unsigned long long val) {
        return static_cast<meter_ull>(val);
    }
    constexpr decimeter_ull operator""_dm(unsigned long long val) {
        return static_cast<decimeter_ull>(val);
    }
    constexpr centimeter_ull operator""_cm(unsigned long long val) {
        return static_cast<centimeter_ull>(val);
    }
    constexpr millimeter_ull operator""_mm(unsigned long long val) {
        return static_cast<millimeter_ull>(val);
    }
    constexpr micrometer_ull operator""_um(unsigned long long val) {
        return static_cast<micrometer_ull>(val);
    }
    constexpr nanometer_ull operator""_nm(unsigned long long val) {
        return static_cast<nanometer_ull>(val);
    }
    constexpr picometer_ull operator""_pm(unsigned long long val) {
        return static_cast<picometer_ull>(val);
    }
    constexpr femtometer_ull operator""_fm(unsigned long long val) {
        return static_cast<femtometer_ull>(val);
    }
    constexpr attometer_ull operator""_am(unsigned long long val) {
        return static_cast<attometer_ull>(val);
    }

} // namespace potato::units
