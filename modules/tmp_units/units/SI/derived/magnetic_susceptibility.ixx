//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Meter_Per_Henry;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.BaseUnit;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename RatioTypeT, typename P>
    struct meter_per_henry_impl : base_unit_<RatioTypeT, P> {

        using base_unit_<RatioTypeT, P>::base_unit_;
        template <typename U, typename R>
        constexpr const meter_per_henry_impl<RatioTypeT, P>(const meter_per_henry_impl<U, R>& other) {
            using scale_greater = call_<if_<lift_<std::ratio_greater>,
                always_<std::ratio_divide<U, RatioTypeT>>,
                always_<unity_ratio>>,
                RatioTypeT, U>;
            using scale_lesser = call_<if_<lift_<std::ratio_less>,
                always_<std::ratio_divide<RatioTypeT, U>>,
                always_<unity_ratio>>,
                RatioTypeT, U>;
            this->value = (other.value * scale_greater::num * scale_lesser::den) / (scale_greater::den * scale_lesser::num);
        }

        static constexpr auto pretty = "m/H";

        using is_any_impl = false_;

        using mod_ratio = RatioTypeT;
        using numer_type = base_unit_<RatioTypeT, P>::value_type;
        using impl      = list_<list_<second_l, second_l, ampere_l, ampere_l>, list_<meter_l, gram_l>>;
    };

    using exameter_per_henry_ld    =     meter_per_henry_impl<std::exa, long double>;
    using petameter_per_henry_ld    =     meter_per_henry_impl<std::peta, long double>;
    using terameter_per_henry_ld    =     meter_per_henry_impl<std::tera, long double>;
    using gigameter_per_henry_ld    =     meter_per_henry_impl<std::giga, long double>;
    using megameter_per_henry_ld    =     meter_per_henry_impl<std::mega, long double>;
    using kilometer_per_henry_ld    =     meter_per_henry_impl<std::kilo, long double>;
    using hectometer_per_henry_ld    =     meter_per_henry_impl<std::hecto, long double>;
    using decameter_per_henry_ld    =     meter_per_henry_impl<std::deca, long double>;
    using meter_per_henry_ld    =     meter_per_henry_impl<unity_ratio, long double>;
    using decimeter_per_henry_ld    =     meter_per_henry_impl<std::deci, long double>;
    using centimeter_per_henry_ld    =     meter_per_henry_impl<std::centi, long double>;
    using millimeter_per_henry_ld    =     meter_per_henry_impl<std::milli, long double>;
    using micrometer_per_henry_ld    =     meter_per_henry_impl<std::micro, long double>;
    using nanometer_per_henry_ld    =     meter_per_henry_impl<std::nano, long double>;
    using picometer_per_henry_ld    =     meter_per_henry_impl<std::pico, long double>;
    using femtometer_per_henry_ld    =     meter_per_henry_impl<std::femto, long double>;
    using attometer_per_henry_ld    =     meter_per_henry_impl<std::atto, long double>;
    using exameter_per_henry_ull    =     meter_per_henry_impl<std::exa, unsigned long long>;
    using petameter_per_henry_ull    =     meter_per_henry_impl<std::peta, unsigned long long>;
    using terameter_per_henry_ull    =     meter_per_henry_impl<std::tera, unsigned long long>;
    using gigameter_per_henry_ull    =     meter_per_henry_impl<std::giga, unsigned long long>;
    using megameter_per_henry_ull    =     meter_per_henry_impl<std::mega, unsigned long long>;
    using kilometer_per_henry_ull    =     meter_per_henry_impl<std::kilo, unsigned long long>;
    using hectometer_per_henry_ull    =     meter_per_henry_impl<std::hecto, unsigned long long>;
    using decameter_per_henry_ull    =     meter_per_henry_impl<std::deca, unsigned long long>;
    using meter_per_henry_ull    =     meter_per_henry_impl<unity_ratio, unsigned long long>;
    using decimeter_per_henry_ull    =     meter_per_henry_impl<std::deci, unsigned long long>;
    using centimeter_per_henry_ull    =     meter_per_henry_impl<std::centi, unsigned long long>;
    using millimeter_per_henry_ull    =     meter_per_henry_impl<std::milli, unsigned long long>;
    using micrometer_per_henry_ull    =     meter_per_henry_impl<std::micro, unsigned long long>;
    using nanometer_per_henry_ull    =     meter_per_henry_impl<std::nano, unsigned long long>;
    using picometer_per_henry_ull    =     meter_per_henry_impl<std::pico, unsigned long long>;
    using femtometer_per_henry_ull    =     meter_per_henry_impl<std::femto, unsigned long long>;
    using attometer_per_henry_ull    =     meter_per_henry_impl<std::atto, unsigned long long>;

    constexpr exameter_per_henry_ld operator""_Em_per_H(long double val) {
        return static_cast<exameter_per_henry_ld>(val);
    }
    constexpr petameter_per_henry_ld operator""_Pm_per_H(long double val) {
        return static_cast<petameter_per_henry_ld>(val);
    }
    constexpr terameter_per_henry_ld operator""_Tm_per_H(long double val) {
        return static_cast<terameter_per_henry_ld>(val);
    }
    constexpr gigameter_per_henry_ld operator""_Gm_per_H(long double val) {
        return static_cast<gigameter_per_henry_ld>(val);
    }
    constexpr megameter_per_henry_ld operator""_Mm_per_H(long double val) {
        return static_cast<megameter_per_henry_ld>(val);
    }
    constexpr kilometer_per_henry_ld operator""_km_per_H(long double val) {
        return static_cast<kilometer_per_henry_ld>(val);
    }
    constexpr hectometer_per_henry_ld operator""_hm_per_H(long double val) {
        return static_cast<hectometer_per_henry_ld>(val);
    }
    constexpr decameter_per_henry_ld operator""_dam_per_H(long double val) {
        return static_cast<decameter_per_henry_ld>(val);
    }
    constexpr meter_per_henry_ld operator""_m_per_H(long double val) {
        return static_cast<meter_per_henry_ld>(val);
    }
    constexpr decimeter_per_henry_ld operator""_dm_per_H(long double val) {
        return static_cast<decimeter_per_henry_ld>(val);
    }
    constexpr centimeter_per_henry_ld operator""_cm_per_H(long double val) {
        return static_cast<centimeter_per_henry_ld>(val);
    }
    constexpr millimeter_per_henry_ld operator""_mm_per_H(long double val) {
        return static_cast<millimeter_per_henry_ld>(val);
    }
    constexpr micrometer_per_henry_ld operator""_um_per_H(long double val) {
        return static_cast<micrometer_per_henry_ld>(val);
    }
    constexpr nanometer_per_henry_ld operator""_nm_per_H(long double val) {
        return static_cast<nanometer_per_henry_ld>(val);
    }
    constexpr picometer_per_henry_ld operator""_pm_per_H(long double val) {
        return static_cast<picometer_per_henry_ld>(val);
    }
    constexpr femtometer_per_henry_ld operator""_fm_per_H(long double val) {
        return static_cast<femtometer_per_henry_ld>(val);
    }
    constexpr attometer_per_henry_ld operator""_am_per_H(long double val) {
        return static_cast<attometer_per_henry_ld>(val);
    }
    constexpr exameter_per_henry_ull operator""_Em_per_H(unsigned long long val) {
        return static_cast<exameter_per_henry_ull>(val);
    }
    constexpr petameter_per_henry_ull operator""_Pm_per_H(unsigned long long val) {
        return static_cast<petameter_per_henry_ull>(val);
    }
    constexpr terameter_per_henry_ull operator""_Tm_per_H(unsigned long long val) {
        return static_cast<terameter_per_henry_ull>(val);
    }
    constexpr gigameter_per_henry_ull operator""_Gm_per_H(unsigned long long val) {
        return static_cast<gigameter_per_henry_ull>(val);
    }
    constexpr megameter_per_henry_ull operator""_Mm_per_H(unsigned long long val) {
        return static_cast<megameter_per_henry_ull>(val);
    }
    constexpr kilometer_per_henry_ull operator""_km_per_H(unsigned long long val) {
        return static_cast<kilometer_per_henry_ull>(val);
    }
    constexpr hectometer_per_henry_ull operator""_hm_per_H(unsigned long long val) {
        return static_cast<hectometer_per_henry_ull>(val);
    }
    constexpr decameter_per_henry_ull operator""_dam_per_H(unsigned long long val) {
        return static_cast<decameter_per_henry_ull>(val);
    }
    constexpr meter_per_henry_ull operator""_m_per_H(unsigned long long val) {
        return static_cast<meter_per_henry_ull>(val);
    }
    constexpr decimeter_per_henry_ull operator""_dm_per_H(unsigned long long val) {
        return static_cast<decimeter_per_henry_ull>(val);
    }
    constexpr centimeter_per_henry_ull operator""_cm_per_H(unsigned long long val) {
        return static_cast<centimeter_per_henry_ull>(val);
    }
    constexpr millimeter_per_henry_ull operator""_mm_per_H(unsigned long long val) {
        return static_cast<millimeter_per_henry_ull>(val);
    }
    constexpr micrometer_per_henry_ull operator""_um_per_H(unsigned long long val) {
        return static_cast<micrometer_per_henry_ull>(val);
    }
    constexpr nanometer_per_henry_ull operator""_nm_per_H(unsigned long long val) {
        return static_cast<nanometer_per_henry_ull>(val);
    }
    constexpr picometer_per_henry_ull operator""_pm_per_H(unsigned long long val) {
        return static_cast<picometer_per_henry_ull>(val);
    }
    constexpr femtometer_per_henry_ull operator""_fm_per_H(unsigned long long val) {
        return static_cast<femtometer_per_henry_ull>(val);
    }
    constexpr attometer_per_henry_ull operator""_am_per_H(unsigned long long val) {
        return static_cast<attometer_per_henry_ull>(val);
    }

} // namespace potato::units
