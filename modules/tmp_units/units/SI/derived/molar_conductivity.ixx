//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Siemens_Square_Meter_Per_Mole;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

export namespace potato::units {
    namespace tmp = boost::tmp;

    template <typename RatioTypeT, typename P>
    struct siemens_square_meter_per_mole_impl {

        static constexpr auto pretty = "S·m²/mol";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = tmp::list_<tmp::list_<second_l, second_l, second_l, ampere_l, ampere_l>, tmp::list_<gram_l, mole_l>>;

        constexpr siemens_square_meter_per_mole_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using siemens_square_exameter_per_mole_ld    =     siemens_square_meter_per_mole_impl<std::exa, long double>;
    using siemens_square_petameter_per_mole_ld    =     siemens_square_meter_per_mole_impl<std::peta, long double>;
    using siemens_square_terameter_per_mole_ld    =     siemens_square_meter_per_mole_impl<std::tera, long double>;
    using siemens_square_gigameter_per_mole_ld    =     siemens_square_meter_per_mole_impl<std::giga, long double>;
    using siemens_square_megameter_per_mole_ld    =     siemens_square_meter_per_mole_impl<std::mega, long double>;
    using siemens_square_kilometer_per_mole_ld    =     siemens_square_meter_per_mole_impl<std::kilo, long double>;
    using siemens_square_hectometer_per_mole_ld    =     siemens_square_meter_per_mole_impl<std::hecto, long double>;
    using siemens_square_decameter_per_mole_ld    =     siemens_square_meter_per_mole_impl<std::deca, long double>;
    using siemens_square_meter_per_mole_ld    =     siemens_square_meter_per_mole_impl<unity_ratio, long double>;
    using siemens_square_decimeter_per_mole_ld    =     siemens_square_meter_per_mole_impl<std::deci, long double>;
    using siemens_square_centimeter_per_mole_ld    =     siemens_square_meter_per_mole_impl<std::centi, long double>;
    using siemens_square_millimeter_per_mole_ld    =     siemens_square_meter_per_mole_impl<std::milli, long double>;
    using siemens_square_micrometer_per_mole_ld    =     siemens_square_meter_per_mole_impl<std::micro, long double>;
    using siemens_square_nanometer_per_mole_ld    =     siemens_square_meter_per_mole_impl<std::nano, long double>;
    using siemens_square_picometer_per_mole_ld    =     siemens_square_meter_per_mole_impl<std::pico, long double>;
    using siemens_square_femtometer_per_mole_ld    =     siemens_square_meter_per_mole_impl<std::femto, long double>;
    using siemens_square_attometer_per_mole_ld    =     siemens_square_meter_per_mole_impl<std::atto, long double>;
    using siemens_square_exameter_per_mole_ull    =     siemens_square_meter_per_mole_impl<std::exa, unsigned long long>;
    using siemens_square_petameter_per_mole_ull    =     siemens_square_meter_per_mole_impl<std::peta, unsigned long long>;
    using siemens_square_terameter_per_mole_ull    =     siemens_square_meter_per_mole_impl<std::tera, unsigned long long>;
    using siemens_square_gigameter_per_mole_ull    =     siemens_square_meter_per_mole_impl<std::giga, unsigned long long>;
    using siemens_square_megameter_per_mole_ull    =     siemens_square_meter_per_mole_impl<std::mega, unsigned long long>;
    using siemens_square_kilometer_per_mole_ull    =     siemens_square_meter_per_mole_impl<std::kilo, unsigned long long>;
    using siemens_square_hectometer_per_mole_ull    =     siemens_square_meter_per_mole_impl<std::hecto, unsigned long long>;
    using siemens_square_decameter_per_mole_ull    =     siemens_square_meter_per_mole_impl<std::deca, unsigned long long>;
    using siemens_square_meter_per_mole_ull    =     siemens_square_meter_per_mole_impl<unity_ratio, unsigned long long>;
    using siemens_square_decimeter_per_mole_ull    =     siemens_square_meter_per_mole_impl<std::deci, unsigned long long>;
    using siemens_square_centimeter_per_mole_ull    =     siemens_square_meter_per_mole_impl<std::centi, unsigned long long>;
    using siemens_square_millimeter_per_mole_ull    =     siemens_square_meter_per_mole_impl<std::milli, unsigned long long>;
    using siemens_square_micrometer_per_mole_ull    =     siemens_square_meter_per_mole_impl<std::micro, unsigned long long>;
    using siemens_square_nanometer_per_mole_ull    =     siemens_square_meter_per_mole_impl<std::nano, unsigned long long>;
    using siemens_square_picometer_per_mole_ull    =     siemens_square_meter_per_mole_impl<std::pico, unsigned long long>;
    using siemens_square_femtometer_per_mole_ull    =     siemens_square_meter_per_mole_impl<std::femto, unsigned long long>;
    using siemens_square_attometer_per_mole_ull    =     siemens_square_meter_per_mole_impl<std::atto, unsigned long long>;

    constexpr siemens_square_exameter_per_mole_ld operator""_S_sq_Em_per_mol(long double val) {
        return static_cast<siemens_square_exameter_per_mole_ld>(val);
    }
    constexpr siemens_square_petameter_per_mole_ld operator""_S_sq_Pm_per_mol(long double val) {
        return static_cast<siemens_square_petameter_per_mole_ld>(val);
    }
    constexpr siemens_square_terameter_per_mole_ld operator""_S_sq_Tm_per_mol(long double val) {
        return static_cast<siemens_square_terameter_per_mole_ld>(val);
    }
    constexpr siemens_square_gigameter_per_mole_ld operator""_S_sq_Gm_per_mol(long double val) {
        return static_cast<siemens_square_gigameter_per_mole_ld>(val);
    }
    constexpr siemens_square_megameter_per_mole_ld operator""_S_sq_Mm_per_mol(long double val) {
        return static_cast<siemens_square_megameter_per_mole_ld>(val);
    }
    constexpr siemens_square_kilometer_per_mole_ld operator""_S_sq_km_per_mol(long double val) {
        return static_cast<siemens_square_kilometer_per_mole_ld>(val);
    }
    constexpr siemens_square_hectometer_per_mole_ld operator""_S_sq_hm_per_mol(long double val) {
        return static_cast<siemens_square_hectometer_per_mole_ld>(val);
    }
    constexpr siemens_square_decameter_per_mole_ld operator""_S_sq_dam_per_mol(long double val) {
        return static_cast<siemens_square_decameter_per_mole_ld>(val);
    }
    constexpr siemens_square_meter_per_mole_ld operator""_S_sq_m_per_mol(long double val) {
        return static_cast<siemens_square_meter_per_mole_ld>(val);
    }
    constexpr siemens_square_decimeter_per_mole_ld operator""_S_sq_dm_per_mol(long double val) {
        return static_cast<siemens_square_decimeter_per_mole_ld>(val);
    }
    constexpr siemens_square_centimeter_per_mole_ld operator""_S_sq_cm_per_mol(long double val) {
        return static_cast<siemens_square_centimeter_per_mole_ld>(val);
    }
    constexpr siemens_square_millimeter_per_mole_ld operator""_S_sq_mm_per_mol(long double val) {
        return static_cast<siemens_square_millimeter_per_mole_ld>(val);
    }
    constexpr siemens_square_micrometer_per_mole_ld operator""_S_sq_um_per_mol(long double val) {
        return static_cast<siemens_square_micrometer_per_mole_ld>(val);
    }
    constexpr siemens_square_nanometer_per_mole_ld operator""_S_sq_nm_per_mol(long double val) {
        return static_cast<siemens_square_nanometer_per_mole_ld>(val);
    }
    constexpr siemens_square_picometer_per_mole_ld operator""_S_sq_pm_per_mol(long double val) {
        return static_cast<siemens_square_picometer_per_mole_ld>(val);
    }
    constexpr siemens_square_femtometer_per_mole_ld operator""_S_sq_fm_per_mol(long double val) {
        return static_cast<siemens_square_femtometer_per_mole_ld>(val);
    }
    constexpr siemens_square_attometer_per_mole_ld operator""_S_sq_am_per_mol(long double val) {
        return static_cast<siemens_square_attometer_per_mole_ld>(val);
    }
    constexpr siemens_square_exameter_per_mole_ull operator""_S_sq_Em_per_mol(unsigned long long val) {
        return static_cast<siemens_square_exameter_per_mole_ull>(val);
    }
    constexpr siemens_square_petameter_per_mole_ull operator""_S_sq_Pm_per_mol(unsigned long long val) {
        return static_cast<siemens_square_petameter_per_mole_ull>(val);
    }
    constexpr siemens_square_terameter_per_mole_ull operator""_S_sq_Tm_per_mol(unsigned long long val) {
        return static_cast<siemens_square_terameter_per_mole_ull>(val);
    }
    constexpr siemens_square_gigameter_per_mole_ull operator""_S_sq_Gm_per_mol(unsigned long long val) {
        return static_cast<siemens_square_gigameter_per_mole_ull>(val);
    }
    constexpr siemens_square_megameter_per_mole_ull operator""_S_sq_Mm_per_mol(unsigned long long val) {
        return static_cast<siemens_square_megameter_per_mole_ull>(val);
    }
    constexpr siemens_square_kilometer_per_mole_ull operator""_S_sq_km_per_mol(unsigned long long val) {
        return static_cast<siemens_square_kilometer_per_mole_ull>(val);
    }
    constexpr siemens_square_hectometer_per_mole_ull operator""_S_sq_hm_per_mol(unsigned long long val) {
        return static_cast<siemens_square_hectometer_per_mole_ull>(val);
    }
    constexpr siemens_square_decameter_per_mole_ull operator""_S_sq_dam_per_mol(unsigned long long val) {
        return static_cast<siemens_square_decameter_per_mole_ull>(val);
    }
    constexpr siemens_square_meter_per_mole_ull operator""_S_sq_m_per_mol(unsigned long long val) {
        return static_cast<siemens_square_meter_per_mole_ull>(val);
    }
    constexpr siemens_square_decimeter_per_mole_ull operator""_S_sq_dm_per_mol(unsigned long long val) {
        return static_cast<siemens_square_decimeter_per_mole_ull>(val);
    }
    constexpr siemens_square_centimeter_per_mole_ull operator""_S_sq_cm_per_mol(unsigned long long val) {
        return static_cast<siemens_square_centimeter_per_mole_ull>(val);
    }
    constexpr siemens_square_millimeter_per_mole_ull operator""_S_sq_mm_per_mol(unsigned long long val) {
        return static_cast<siemens_square_millimeter_per_mole_ull>(val);
    }
    constexpr siemens_square_micrometer_per_mole_ull operator""_S_sq_um_per_mol(unsigned long long val) {
        return static_cast<siemens_square_micrometer_per_mole_ull>(val);
    }
    constexpr siemens_square_nanometer_per_mole_ull operator""_S_sq_nm_per_mol(unsigned long long val) {
        return static_cast<siemens_square_nanometer_per_mole_ull>(val);
    }
    constexpr siemens_square_picometer_per_mole_ull operator""_S_sq_pm_per_mol(unsigned long long val) {
        return static_cast<siemens_square_picometer_per_mole_ull>(val);
    }
    constexpr siemens_square_femtometer_per_mole_ull operator""_S_sq_fm_per_mol(unsigned long long val) {
        return static_cast<siemens_square_femtometer_per_mole_ull>(val);
    }
    constexpr siemens_square_attometer_per_mole_ull operator""_S_sq_am_per_mol(unsigned long long val) {
        return static_cast<siemens_square_attometer_per_mole_ull>(val);
    }

} // namespace potato::units
