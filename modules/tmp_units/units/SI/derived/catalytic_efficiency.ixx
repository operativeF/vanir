//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Cubic_Meter_Per_Mole_Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.BaseUnit;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename RatioTypeT, typename P>
    struct cubic_meter_per_mole_second_impl : base_unit_<RatioTypeT, P> {

        using base_unit_<RatioTypeT, P>::base_unit_;
        template <typename U, typename R>
        constexpr const cubic_meter_per_mole_second_impl<RatioTypeT, P>(const cubic_meter_per_mole_second_impl<U, R>& other) {
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

        static constexpr auto pretty = "m³/mol·s";

        using is_any_impl = false_;

        using mod_ratio = RatioTypeT;
        using numer_type = base_unit_<RatioTypeT, P>::value_type;
        using impl      = list_<list_<meter_l, meter_l, meter_l>, list_<mole_l, second_l>>;
    };

    using cubic_exameter_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<std::exa, long double>;
    using cubic_petameter_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<std::peta, long double>;
    using cubic_terameter_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<std::tera, long double>;
    using cubic_gigameter_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<std::giga, long double>;
    using cubic_megameter_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<std::mega, long double>;
    using cubic_kilometer_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<std::kilo, long double>;
    using cubic_hectometer_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<std::hecto, long double>;
    using cubic_decameter_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<std::deca, long double>;
    using cubic_meter_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<unity_ratio, long double>;
    using cubic_decimeter_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<std::deci, long double>;
    using cubic_centimeter_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<std::centi, long double>;
    using cubic_millimeter_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<std::milli, long double>;
    using cubic_micrometer_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<std::micro, long double>;
    using cubic_nanometer_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<std::nano, long double>;
    using cubic_picometer_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<std::pico, long double>;
    using cubic_femtometer_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<std::femto, long double>;
    using cubic_attometer_per_mole_second_ld    =     cubic_meter_per_mole_second_impl<std::atto, long double>;
    using cubic_exameter_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<std::exa, unsigned long long>;
    using cubic_petameter_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<std::peta, unsigned long long>;
    using cubic_terameter_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<std::tera, unsigned long long>;
    using cubic_gigameter_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<std::giga, unsigned long long>;
    using cubic_megameter_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<std::mega, unsigned long long>;
    using cubic_kilometer_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<std::kilo, unsigned long long>;
    using cubic_hectometer_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<std::hecto, unsigned long long>;
    using cubic_decameter_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<std::deca, unsigned long long>;
    using cubic_meter_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<unity_ratio, unsigned long long>;
    using cubic_decimeter_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<std::deci, unsigned long long>;
    using cubic_centimeter_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<std::centi, unsigned long long>;
    using cubic_millimeter_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<std::milli, unsigned long long>;
    using cubic_micrometer_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<std::micro, unsigned long long>;
    using cubic_nanometer_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<std::nano, unsigned long long>;
    using cubic_picometer_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<std::pico, unsigned long long>;
    using cubic_femtometer_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<std::femto, unsigned long long>;
    using cubic_attometer_per_mole_second_ull    =     cubic_meter_per_mole_second_impl<std::atto, unsigned long long>;

    constexpr cubic_exameter_per_mole_second_ld operator""_cubic_Em_per_mol_s(long double val) {
        return static_cast<cubic_exameter_per_mole_second_ld>(val);
    }
    constexpr cubic_petameter_per_mole_second_ld operator""_cubic_Pm_per_mol_s(long double val) {
        return static_cast<cubic_petameter_per_mole_second_ld>(val);
    }
    constexpr cubic_terameter_per_mole_second_ld operator""_cubic_Tm_per_mol_s(long double val) {
        return static_cast<cubic_terameter_per_mole_second_ld>(val);
    }
    constexpr cubic_gigameter_per_mole_second_ld operator""_cubic_Gm_per_mol_s(long double val) {
        return static_cast<cubic_gigameter_per_mole_second_ld>(val);
    }
    constexpr cubic_megameter_per_mole_second_ld operator""_cubic_Mm_per_mol_s(long double val) {
        return static_cast<cubic_megameter_per_mole_second_ld>(val);
    }
    constexpr cubic_kilometer_per_mole_second_ld operator""_cubic_km_per_mol_s(long double val) {
        return static_cast<cubic_kilometer_per_mole_second_ld>(val);
    }
    constexpr cubic_hectometer_per_mole_second_ld operator""_cubic_hm_per_mol_s(long double val) {
        return static_cast<cubic_hectometer_per_mole_second_ld>(val);
    }
    constexpr cubic_decameter_per_mole_second_ld operator""_cubic_dam_per_mol_s(long double val) {
        return static_cast<cubic_decameter_per_mole_second_ld>(val);
    }
    constexpr cubic_meter_per_mole_second_ld operator""_cubic_m_per_mol_s(long double val) {
        return static_cast<cubic_meter_per_mole_second_ld>(val);
    }
    constexpr cubic_decimeter_per_mole_second_ld operator""_cubic_dm_per_mol_s(long double val) {
        return static_cast<cubic_decimeter_per_mole_second_ld>(val);
    }
    constexpr cubic_centimeter_per_mole_second_ld operator""_cubic_cm_per_mol_s(long double val) {
        return static_cast<cubic_centimeter_per_mole_second_ld>(val);
    }
    constexpr cubic_millimeter_per_mole_second_ld operator""_cubic_mm_per_mol_s(long double val) {
        return static_cast<cubic_millimeter_per_mole_second_ld>(val);
    }
    constexpr cubic_micrometer_per_mole_second_ld operator""_cubic_um_per_mol_s(long double val) {
        return static_cast<cubic_micrometer_per_mole_second_ld>(val);
    }
    constexpr cubic_nanometer_per_mole_second_ld operator""_cubic_nm_per_mol_s(long double val) {
        return static_cast<cubic_nanometer_per_mole_second_ld>(val);
    }
    constexpr cubic_picometer_per_mole_second_ld operator""_cubic_pm_per_mol_s(long double val) {
        return static_cast<cubic_picometer_per_mole_second_ld>(val);
    }
    constexpr cubic_femtometer_per_mole_second_ld operator""_cubic_fm_per_mol_s(long double val) {
        return static_cast<cubic_femtometer_per_mole_second_ld>(val);
    }
    constexpr cubic_attometer_per_mole_second_ld operator""_cubic_am_per_mol_s(long double val) {
        return static_cast<cubic_attometer_per_mole_second_ld>(val);
    }
    constexpr cubic_exameter_per_mole_second_ull operator""_cubic_Em_per_mol_s(unsigned long long val) {
        return static_cast<cubic_exameter_per_mole_second_ull>(val);
    }
    constexpr cubic_petameter_per_mole_second_ull operator""_cubic_Pm_per_mol_s(unsigned long long val) {
        return static_cast<cubic_petameter_per_mole_second_ull>(val);
    }
    constexpr cubic_terameter_per_mole_second_ull operator""_cubic_Tm_per_mol_s(unsigned long long val) {
        return static_cast<cubic_terameter_per_mole_second_ull>(val);
    }
    constexpr cubic_gigameter_per_mole_second_ull operator""_cubic_Gm_per_mol_s(unsigned long long val) {
        return static_cast<cubic_gigameter_per_mole_second_ull>(val);
    }
    constexpr cubic_megameter_per_mole_second_ull operator""_cubic_Mm_per_mol_s(unsigned long long val) {
        return static_cast<cubic_megameter_per_mole_second_ull>(val);
    }
    constexpr cubic_kilometer_per_mole_second_ull operator""_cubic_km_per_mol_s(unsigned long long val) {
        return static_cast<cubic_kilometer_per_mole_second_ull>(val);
    }
    constexpr cubic_hectometer_per_mole_second_ull operator""_cubic_hm_per_mol_s(unsigned long long val) {
        return static_cast<cubic_hectometer_per_mole_second_ull>(val);
    }
    constexpr cubic_decameter_per_mole_second_ull operator""_cubic_dam_per_mol_s(unsigned long long val) {
        return static_cast<cubic_decameter_per_mole_second_ull>(val);
    }
    constexpr cubic_meter_per_mole_second_ull operator""_cubic_m_per_mol_s(unsigned long long val) {
        return static_cast<cubic_meter_per_mole_second_ull>(val);
    }
    constexpr cubic_decimeter_per_mole_second_ull operator""_cubic_dm_per_mol_s(unsigned long long val) {
        return static_cast<cubic_decimeter_per_mole_second_ull>(val);
    }
    constexpr cubic_centimeter_per_mole_second_ull operator""_cubic_cm_per_mol_s(unsigned long long val) {
        return static_cast<cubic_centimeter_per_mole_second_ull>(val);
    }
    constexpr cubic_millimeter_per_mole_second_ull operator""_cubic_mm_per_mol_s(unsigned long long val) {
        return static_cast<cubic_millimeter_per_mole_second_ull>(val);
    }
    constexpr cubic_micrometer_per_mole_second_ull operator""_cubic_um_per_mol_s(unsigned long long val) {
        return static_cast<cubic_micrometer_per_mole_second_ull>(val);
    }
    constexpr cubic_nanometer_per_mole_second_ull operator""_cubic_nm_per_mol_s(unsigned long long val) {
        return static_cast<cubic_nanometer_per_mole_second_ull>(val);
    }
    constexpr cubic_picometer_per_mole_second_ull operator""_cubic_pm_per_mol_s(unsigned long long val) {
        return static_cast<cubic_picometer_per_mole_second_ull>(val);
    }
    constexpr cubic_femtometer_per_mole_second_ull operator""_cubic_fm_per_mol_s(unsigned long long val) {
        return static_cast<cubic_femtometer_per_mole_second_ull>(val);
    }
    constexpr cubic_attometer_per_mole_second_ull operator""_cubic_am_per_mol_s(unsigned long long val) {
        return static_cast<cubic_attometer_per_mole_second_ull>(val);
    }

} // namespace potato::units
