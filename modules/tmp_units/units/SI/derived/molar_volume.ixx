//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Cubic_Meter_Per_Mole;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using molar_volume_tag_t = tmp::list_<Length<std::ratio<3, 1>>,
                                         Time<std::ratio<0, 1>>,
                                         Mass<std::ratio<0, 1>>,
                                         AmountOfSubstance<std::ratio<-1, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept Cubic_Meter_Per_MoleC = std::same_as<typename T::impl, molar_volume_tag_t>;

    template <typename RatioTypeT, typename P>
    struct cubic_meter_per_mole_impl {

        static constexpr auto pretty = "m³/mol";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = molar_volume_tag_t;

        constexpr cubic_meter_per_mole_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using cubic_exameter_per_mole_ld    =     cubic_meter_per_mole_impl<std::exa, long double>;
    using cubic_petameter_per_mole_ld    =     cubic_meter_per_mole_impl<std::peta, long double>;
    using cubic_terameter_per_mole_ld    =     cubic_meter_per_mole_impl<std::tera, long double>;
    using cubic_gigameter_per_mole_ld    =     cubic_meter_per_mole_impl<std::giga, long double>;
    using cubic_megameter_per_mole_ld    =     cubic_meter_per_mole_impl<std::mega, long double>;
    using cubic_kilometer_per_mole_ld    =     cubic_meter_per_mole_impl<std::kilo, long double>;
    using cubic_hectometer_per_mole_ld    =     cubic_meter_per_mole_impl<std::hecto, long double>;
    using cubic_decameter_per_mole_ld    =     cubic_meter_per_mole_impl<std::deca, long double>;
    using cubic_meter_per_mole_ld    =     cubic_meter_per_mole_impl<unity_ratio, long double>;
    using cubic_decimeter_per_mole_ld    =     cubic_meter_per_mole_impl<std::deci, long double>;
    using cubic_centimeter_per_mole_ld    =     cubic_meter_per_mole_impl<std::centi, long double>;
    using cubic_millimeter_per_mole_ld    =     cubic_meter_per_mole_impl<std::milli, long double>;
    using cubic_micrometer_per_mole_ld    =     cubic_meter_per_mole_impl<std::micro, long double>;
    using cubic_nanometer_per_mole_ld    =     cubic_meter_per_mole_impl<std::nano, long double>;
    using cubic_picometer_per_mole_ld    =     cubic_meter_per_mole_impl<std::pico, long double>;
    using cubic_femtometer_per_mole_ld    =     cubic_meter_per_mole_impl<std::femto, long double>;
    using cubic_attometer_per_mole_ld    =     cubic_meter_per_mole_impl<std::atto, long double>;
    using cubic_exameter_per_mole_ull    =     cubic_meter_per_mole_impl<std::exa, unsigned long long>;
    using cubic_petameter_per_mole_ull    =     cubic_meter_per_mole_impl<std::peta, unsigned long long>;
    using cubic_terameter_per_mole_ull    =     cubic_meter_per_mole_impl<std::tera, unsigned long long>;
    using cubic_gigameter_per_mole_ull    =     cubic_meter_per_mole_impl<std::giga, unsigned long long>;
    using cubic_megameter_per_mole_ull    =     cubic_meter_per_mole_impl<std::mega, unsigned long long>;
    using cubic_kilometer_per_mole_ull    =     cubic_meter_per_mole_impl<std::kilo, unsigned long long>;
    using cubic_hectometer_per_mole_ull    =     cubic_meter_per_mole_impl<std::hecto, unsigned long long>;
    using cubic_decameter_per_mole_ull    =     cubic_meter_per_mole_impl<std::deca, unsigned long long>;
    using cubic_meter_per_mole_ull    =     cubic_meter_per_mole_impl<unity_ratio, unsigned long long>;
    using cubic_decimeter_per_mole_ull    =     cubic_meter_per_mole_impl<std::deci, unsigned long long>;
    using cubic_centimeter_per_mole_ull    =     cubic_meter_per_mole_impl<std::centi, unsigned long long>;
    using cubic_millimeter_per_mole_ull    =     cubic_meter_per_mole_impl<std::milli, unsigned long long>;
    using cubic_micrometer_per_mole_ull    =     cubic_meter_per_mole_impl<std::micro, unsigned long long>;
    using cubic_nanometer_per_mole_ull    =     cubic_meter_per_mole_impl<std::nano, unsigned long long>;
    using cubic_picometer_per_mole_ull    =     cubic_meter_per_mole_impl<std::pico, unsigned long long>;
    using cubic_femtometer_per_mole_ull    =     cubic_meter_per_mole_impl<std::femto, unsigned long long>;
    using cubic_attometer_per_mole_ull    =     cubic_meter_per_mole_impl<std::atto, unsigned long long>;

    consteval cubic_exameter_per_mole_ld operator""_cubic_Em_per_mol(long double val) {
        return static_cast<cubic_exameter_per_mole_ld>(val);
    }
    consteval cubic_petameter_per_mole_ld operator""_cubic_Pm_per_mol(long double val) {
        return static_cast<cubic_petameter_per_mole_ld>(val);
    }
    consteval cubic_terameter_per_mole_ld operator""_cubic_Tm_per_mol(long double val) {
        return static_cast<cubic_terameter_per_mole_ld>(val);
    }
    consteval cubic_gigameter_per_mole_ld operator""_cubic_Gm_per_mol(long double val) {
        return static_cast<cubic_gigameter_per_mole_ld>(val);
    }
    consteval cubic_megameter_per_mole_ld operator""_cubic_Mm_per_mol(long double val) {
        return static_cast<cubic_megameter_per_mole_ld>(val);
    }
    consteval cubic_kilometer_per_mole_ld operator""_cubic_km_per_mol(long double val) {
        return static_cast<cubic_kilometer_per_mole_ld>(val);
    }
    consteval cubic_hectometer_per_mole_ld operator""_cubic_hm_per_mol(long double val) {
        return static_cast<cubic_hectometer_per_mole_ld>(val);
    }
    consteval cubic_decameter_per_mole_ld operator""_cubic_dam_per_mol(long double val) {
        return static_cast<cubic_decameter_per_mole_ld>(val);
    }
    consteval cubic_meter_per_mole_ld operator""_cubic_m_per_mol(long double val) {
        return static_cast<cubic_meter_per_mole_ld>(val);
    }
    consteval cubic_decimeter_per_mole_ld operator""_cubic_dm_per_mol(long double val) {
        return static_cast<cubic_decimeter_per_mole_ld>(val);
    }
    consteval cubic_centimeter_per_mole_ld operator""_cubic_cm_per_mol(long double val) {
        return static_cast<cubic_centimeter_per_mole_ld>(val);
    }
    consteval cubic_millimeter_per_mole_ld operator""_cubic_mm_per_mol(long double val) {
        return static_cast<cubic_millimeter_per_mole_ld>(val);
    }
    consteval cubic_micrometer_per_mole_ld operator""_cubic_um_per_mol(long double val) {
        return static_cast<cubic_micrometer_per_mole_ld>(val);
    }
    consteval cubic_nanometer_per_mole_ld operator""_cubic_nm_per_mol(long double val) {
        return static_cast<cubic_nanometer_per_mole_ld>(val);
    }
    consteval cubic_picometer_per_mole_ld operator""_cubic_pm_per_mol(long double val) {
        return static_cast<cubic_picometer_per_mole_ld>(val);
    }
    consteval cubic_femtometer_per_mole_ld operator""_cubic_fm_per_mol(long double val) {
        return static_cast<cubic_femtometer_per_mole_ld>(val);
    }
    consteval cubic_attometer_per_mole_ld operator""_cubic_am_per_mol(long double val) {
        return static_cast<cubic_attometer_per_mole_ld>(val);
    }
    consteval cubic_exameter_per_mole_ull operator""_cubic_Em_per_mol(unsigned long long val) {
        return static_cast<cubic_exameter_per_mole_ull>(val);
    }
    consteval cubic_petameter_per_mole_ull operator""_cubic_Pm_per_mol(unsigned long long val) {
        return static_cast<cubic_petameter_per_mole_ull>(val);
    }
    consteval cubic_terameter_per_mole_ull operator""_cubic_Tm_per_mol(unsigned long long val) {
        return static_cast<cubic_terameter_per_mole_ull>(val);
    }
    consteval cubic_gigameter_per_mole_ull operator""_cubic_Gm_per_mol(unsigned long long val) {
        return static_cast<cubic_gigameter_per_mole_ull>(val);
    }
    consteval cubic_megameter_per_mole_ull operator""_cubic_Mm_per_mol(unsigned long long val) {
        return static_cast<cubic_megameter_per_mole_ull>(val);
    }
    consteval cubic_kilometer_per_mole_ull operator""_cubic_km_per_mol(unsigned long long val) {
        return static_cast<cubic_kilometer_per_mole_ull>(val);
    }
    consteval cubic_hectometer_per_mole_ull operator""_cubic_hm_per_mol(unsigned long long val) {
        return static_cast<cubic_hectometer_per_mole_ull>(val);
    }
    consteval cubic_decameter_per_mole_ull operator""_cubic_dam_per_mol(unsigned long long val) {
        return static_cast<cubic_decameter_per_mole_ull>(val);
    }
    consteval cubic_meter_per_mole_ull operator""_cubic_m_per_mol(unsigned long long val) {
        return static_cast<cubic_meter_per_mole_ull>(val);
    }
    consteval cubic_decimeter_per_mole_ull operator""_cubic_dm_per_mol(unsigned long long val) {
        return static_cast<cubic_decimeter_per_mole_ull>(val);
    }
    consteval cubic_centimeter_per_mole_ull operator""_cubic_cm_per_mol(unsigned long long val) {
        return static_cast<cubic_centimeter_per_mole_ull>(val);
    }
    consteval cubic_millimeter_per_mole_ull operator""_cubic_mm_per_mol(unsigned long long val) {
        return static_cast<cubic_millimeter_per_mole_ull>(val);
    }
    consteval cubic_micrometer_per_mole_ull operator""_cubic_um_per_mol(unsigned long long val) {
        return static_cast<cubic_micrometer_per_mole_ull>(val);
    }
    consteval cubic_nanometer_per_mole_ull operator""_cubic_nm_per_mol(unsigned long long val) {
        return static_cast<cubic_nanometer_per_mole_ull>(val);
    }
    consteval cubic_picometer_per_mole_ull operator""_cubic_pm_per_mol(unsigned long long val) {
        return static_cast<cubic_picometer_per_mole_ull>(val);
    }
    consteval cubic_femtometer_per_mole_ull operator""_cubic_fm_per_mol(unsigned long long val) {
        return static_cast<cubic_femtometer_per_mole_ull>(val);
    }
    consteval cubic_attometer_per_mole_ull operator""_cubic_am_per_mol(unsigned long long val) {
        return static_cast<cubic_attometer_per_mole_ull>(val);
    }

} // namespace potato::units
