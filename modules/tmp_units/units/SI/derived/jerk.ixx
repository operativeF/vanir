//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Meter_Per_Cubic_Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

export namespace potato::units {
    namespace tmp = boost::tmp;

    template <typename RatioTypeT, typename P>
    struct meter_per_cubic_second_impl {

        static constexpr auto pretty = "m/s³";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = tmp::list_<tmp::list_<meter_l>, tmp::list_<second_l, second_l, second_l>>;

        constexpr meter_per_cubic_second_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exameter_per_cubic_second_ld    =     meter_per_cubic_second_impl<std::exa, long double>;
    using petameter_per_cubic_second_ld    =     meter_per_cubic_second_impl<std::peta, long double>;
    using terameter_per_cubic_second_ld    =     meter_per_cubic_second_impl<std::tera, long double>;
    using gigameter_per_cubic_second_ld    =     meter_per_cubic_second_impl<std::giga, long double>;
    using megameter_per_cubic_second_ld    =     meter_per_cubic_second_impl<std::mega, long double>;
    using kilometer_per_cubic_second_ld    =     meter_per_cubic_second_impl<std::kilo, long double>;
    using hectometer_per_cubic_second_ld    =     meter_per_cubic_second_impl<std::hecto, long double>;
    using decameter_per_cubic_second_ld    =     meter_per_cubic_second_impl<std::deca, long double>;
    using meter_per_cubic_second_ld    =     meter_per_cubic_second_impl<unity_ratio, long double>;
    using decimeter_per_cubic_second_ld    =     meter_per_cubic_second_impl<std::deci, long double>;
    using centimeter_per_cubic_second_ld    =     meter_per_cubic_second_impl<std::centi, long double>;
    using millimeter_per_cubic_second_ld    =     meter_per_cubic_second_impl<std::milli, long double>;
    using micrometer_per_cubic_second_ld    =     meter_per_cubic_second_impl<std::micro, long double>;
    using nanometer_per_cubic_second_ld    =     meter_per_cubic_second_impl<std::nano, long double>;
    using picometer_per_cubic_second_ld    =     meter_per_cubic_second_impl<std::pico, long double>;
    using femtometer_per_cubic_second_ld    =     meter_per_cubic_second_impl<std::femto, long double>;
    using attometer_per_cubic_second_ld    =     meter_per_cubic_second_impl<std::atto, long double>;
    using exameter_per_cubic_second_ull    =     meter_per_cubic_second_impl<std::exa, unsigned long long>;
    using petameter_per_cubic_second_ull    =     meter_per_cubic_second_impl<std::peta, unsigned long long>;
    using terameter_per_cubic_second_ull    =     meter_per_cubic_second_impl<std::tera, unsigned long long>;
    using gigameter_per_cubic_second_ull    =     meter_per_cubic_second_impl<std::giga, unsigned long long>;
    using megameter_per_cubic_second_ull    =     meter_per_cubic_second_impl<std::mega, unsigned long long>;
    using kilometer_per_cubic_second_ull    =     meter_per_cubic_second_impl<std::kilo, unsigned long long>;
    using hectometer_per_cubic_second_ull    =     meter_per_cubic_second_impl<std::hecto, unsigned long long>;
    using decameter_per_cubic_second_ull    =     meter_per_cubic_second_impl<std::deca, unsigned long long>;
    using meter_per_cubic_second_ull    =     meter_per_cubic_second_impl<unity_ratio, unsigned long long>;
    using decimeter_per_cubic_second_ull    =     meter_per_cubic_second_impl<std::deci, unsigned long long>;
    using centimeter_per_cubic_second_ull    =     meter_per_cubic_second_impl<std::centi, unsigned long long>;
    using millimeter_per_cubic_second_ull    =     meter_per_cubic_second_impl<std::milli, unsigned long long>;
    using micrometer_per_cubic_second_ull    =     meter_per_cubic_second_impl<std::micro, unsigned long long>;
    using nanometer_per_cubic_second_ull    =     meter_per_cubic_second_impl<std::nano, unsigned long long>;
    using picometer_per_cubic_second_ull    =     meter_per_cubic_second_impl<std::pico, unsigned long long>;
    using femtometer_per_cubic_second_ull    =     meter_per_cubic_second_impl<std::femto, unsigned long long>;
    using attometer_per_cubic_second_ull    =     meter_per_cubic_second_impl<std::atto, unsigned long long>;

    constexpr exameter_per_cubic_second_ld operator""_Em_per_cubic_s(long double val) {
        return static_cast<exameter_per_cubic_second_ld>(val);
    }
    constexpr petameter_per_cubic_second_ld operator""_Pm_per_cubic_s(long double val) {
        return static_cast<petameter_per_cubic_second_ld>(val);
    }
    constexpr terameter_per_cubic_second_ld operator""_Tm_per_cubic_s(long double val) {
        return static_cast<terameter_per_cubic_second_ld>(val);
    }
    constexpr gigameter_per_cubic_second_ld operator""_Gm_per_cubic_s(long double val) {
        return static_cast<gigameter_per_cubic_second_ld>(val);
    }
    constexpr megameter_per_cubic_second_ld operator""_Mm_per_cubic_s(long double val) {
        return static_cast<megameter_per_cubic_second_ld>(val);
    }
    constexpr kilometer_per_cubic_second_ld operator""_km_per_cubic_s(long double val) {
        return static_cast<kilometer_per_cubic_second_ld>(val);
    }
    constexpr hectometer_per_cubic_second_ld operator""_hm_per_cubic_s(long double val) {
        return static_cast<hectometer_per_cubic_second_ld>(val);
    }
    constexpr decameter_per_cubic_second_ld operator""_dam_per_cubic_s(long double val) {
        return static_cast<decameter_per_cubic_second_ld>(val);
    }
    constexpr meter_per_cubic_second_ld operator""_m_per_cubic_s(long double val) {
        return static_cast<meter_per_cubic_second_ld>(val);
    }
    constexpr decimeter_per_cubic_second_ld operator""_dm_per_cubic_s(long double val) {
        return static_cast<decimeter_per_cubic_second_ld>(val);
    }
    constexpr centimeter_per_cubic_second_ld operator""_cm_per_cubic_s(long double val) {
        return static_cast<centimeter_per_cubic_second_ld>(val);
    }
    constexpr millimeter_per_cubic_second_ld operator""_mm_per_cubic_s(long double val) {
        return static_cast<millimeter_per_cubic_second_ld>(val);
    }
    constexpr micrometer_per_cubic_second_ld operator""_um_per_cubic_s(long double val) {
        return static_cast<micrometer_per_cubic_second_ld>(val);
    }
    constexpr nanometer_per_cubic_second_ld operator""_nm_per_cubic_s(long double val) {
        return static_cast<nanometer_per_cubic_second_ld>(val);
    }
    constexpr picometer_per_cubic_second_ld operator""_pm_per_cubic_s(long double val) {
        return static_cast<picometer_per_cubic_second_ld>(val);
    }
    constexpr femtometer_per_cubic_second_ld operator""_fm_per_cubic_s(long double val) {
        return static_cast<femtometer_per_cubic_second_ld>(val);
    }
    constexpr attometer_per_cubic_second_ld operator""_am_per_cubic_s(long double val) {
        return static_cast<attometer_per_cubic_second_ld>(val);
    }
    constexpr exameter_per_cubic_second_ull operator""_Em_per_cubic_s(unsigned long long val) {
        return static_cast<exameter_per_cubic_second_ull>(val);
    }
    constexpr petameter_per_cubic_second_ull operator""_Pm_per_cubic_s(unsigned long long val) {
        return static_cast<petameter_per_cubic_second_ull>(val);
    }
    constexpr terameter_per_cubic_second_ull operator""_Tm_per_cubic_s(unsigned long long val) {
        return static_cast<terameter_per_cubic_second_ull>(val);
    }
    constexpr gigameter_per_cubic_second_ull operator""_Gm_per_cubic_s(unsigned long long val) {
        return static_cast<gigameter_per_cubic_second_ull>(val);
    }
    constexpr megameter_per_cubic_second_ull operator""_Mm_per_cubic_s(unsigned long long val) {
        return static_cast<megameter_per_cubic_second_ull>(val);
    }
    constexpr kilometer_per_cubic_second_ull operator""_km_per_cubic_s(unsigned long long val) {
        return static_cast<kilometer_per_cubic_second_ull>(val);
    }
    constexpr hectometer_per_cubic_second_ull operator""_hm_per_cubic_s(unsigned long long val) {
        return static_cast<hectometer_per_cubic_second_ull>(val);
    }
    constexpr decameter_per_cubic_second_ull operator""_dam_per_cubic_s(unsigned long long val) {
        return static_cast<decameter_per_cubic_second_ull>(val);
    }
    constexpr meter_per_cubic_second_ull operator""_m_per_cubic_s(unsigned long long val) {
        return static_cast<meter_per_cubic_second_ull>(val);
    }
    constexpr decimeter_per_cubic_second_ull operator""_dm_per_cubic_s(unsigned long long val) {
        return static_cast<decimeter_per_cubic_second_ull>(val);
    }
    constexpr centimeter_per_cubic_second_ull operator""_cm_per_cubic_s(unsigned long long val) {
        return static_cast<centimeter_per_cubic_second_ull>(val);
    }
    constexpr millimeter_per_cubic_second_ull operator""_mm_per_cubic_s(unsigned long long val) {
        return static_cast<millimeter_per_cubic_second_ull>(val);
    }
    constexpr micrometer_per_cubic_second_ull operator""_um_per_cubic_s(unsigned long long val) {
        return static_cast<micrometer_per_cubic_second_ull>(val);
    }
    constexpr nanometer_per_cubic_second_ull operator""_nm_per_cubic_s(unsigned long long val) {
        return static_cast<nanometer_per_cubic_second_ull>(val);
    }
    constexpr picometer_per_cubic_second_ull operator""_pm_per_cubic_s(unsigned long long val) {
        return static_cast<picometer_per_cubic_second_ull>(val);
    }
    constexpr femtometer_per_cubic_second_ull operator""_fm_per_cubic_s(unsigned long long val) {
        return static_cast<femtometer_per_cubic_second_ull>(val);
    }
    constexpr attometer_per_cubic_second_ull operator""_am_per_cubic_s(unsigned long long val) {
        return static_cast<attometer_per_cubic_second_ull>(val);
    }

} // namespace potato::units
