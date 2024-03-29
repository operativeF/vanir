//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Cubic_Meter;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using volume_tag_t = tmp::list_<Length<std::ratio<3, 1>>,
                                         Time<std::ratio<0, 1>>,
                                         Mass<std::ratio<0, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept Cubic_MeterC = std::same_as<typename T::impl, volume_tag_t>;

    template <typename RatioTypeT, typename P>
    struct cubic_meter_impl {

        static constexpr auto pretty = "m³";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = volume_tag_t;

        constexpr cubic_meter_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using cubic_exameter_ld    =     cubic_meter_impl<std::exa, long double>;
    using cubic_petameter_ld    =     cubic_meter_impl<std::peta, long double>;
    using cubic_terameter_ld    =     cubic_meter_impl<std::tera, long double>;
    using cubic_gigameter_ld    =     cubic_meter_impl<std::giga, long double>;
    using cubic_megameter_ld    =     cubic_meter_impl<std::mega, long double>;
    using cubic_kilometer_ld    =     cubic_meter_impl<std::kilo, long double>;
    using cubic_hectometer_ld    =     cubic_meter_impl<std::hecto, long double>;
    using cubic_decameter_ld    =     cubic_meter_impl<std::deca, long double>;
    using cubic_meter_ld    =     cubic_meter_impl<unity_ratio, long double>;
    using cubic_decimeter_ld    =     cubic_meter_impl<std::deci, long double>;
    using cubic_centimeter_ld    =     cubic_meter_impl<std::centi, long double>;
    using cubic_millimeter_ld    =     cubic_meter_impl<std::milli, long double>;
    using cubic_micrometer_ld    =     cubic_meter_impl<std::micro, long double>;
    using cubic_nanometer_ld    =     cubic_meter_impl<std::nano, long double>;
    using cubic_picometer_ld    =     cubic_meter_impl<std::pico, long double>;
    using cubic_femtometer_ld    =     cubic_meter_impl<std::femto, long double>;
    using cubic_attometer_ld    =     cubic_meter_impl<std::atto, long double>;
    using cubic_exameter_ull    =     cubic_meter_impl<std::exa, unsigned long long>;
    using cubic_petameter_ull    =     cubic_meter_impl<std::peta, unsigned long long>;
    using cubic_terameter_ull    =     cubic_meter_impl<std::tera, unsigned long long>;
    using cubic_gigameter_ull    =     cubic_meter_impl<std::giga, unsigned long long>;
    using cubic_megameter_ull    =     cubic_meter_impl<std::mega, unsigned long long>;
    using cubic_kilometer_ull    =     cubic_meter_impl<std::kilo, unsigned long long>;
    using cubic_hectometer_ull    =     cubic_meter_impl<std::hecto, unsigned long long>;
    using cubic_decameter_ull    =     cubic_meter_impl<std::deca, unsigned long long>;
    using cubic_meter_ull    =     cubic_meter_impl<unity_ratio, unsigned long long>;
    using cubic_decimeter_ull    =     cubic_meter_impl<std::deci, unsigned long long>;
    using cubic_centimeter_ull    =     cubic_meter_impl<std::centi, unsigned long long>;
    using cubic_millimeter_ull    =     cubic_meter_impl<std::milli, unsigned long long>;
    using cubic_micrometer_ull    =     cubic_meter_impl<std::micro, unsigned long long>;
    using cubic_nanometer_ull    =     cubic_meter_impl<std::nano, unsigned long long>;
    using cubic_picometer_ull    =     cubic_meter_impl<std::pico, unsigned long long>;
    using cubic_femtometer_ull    =     cubic_meter_impl<std::femto, unsigned long long>;
    using cubic_attometer_ull    =     cubic_meter_impl<std::atto, unsigned long long>;

    consteval cubic_exameter_ld operator""_cubic_Em(long double val) {
        return static_cast<cubic_exameter_ld>(val);
    }
    consteval cubic_petameter_ld operator""_cubic_Pm(long double val) {
        return static_cast<cubic_petameter_ld>(val);
    }
    consteval cubic_terameter_ld operator""_cubic_Tm(long double val) {
        return static_cast<cubic_terameter_ld>(val);
    }
    consteval cubic_gigameter_ld operator""_cubic_Gm(long double val) {
        return static_cast<cubic_gigameter_ld>(val);
    }
    consteval cubic_megameter_ld operator""_cubic_Mm(long double val) {
        return static_cast<cubic_megameter_ld>(val);
    }
    consteval cubic_kilometer_ld operator""_cubic_km(long double val) {
        return static_cast<cubic_kilometer_ld>(val);
    }
    consteval cubic_hectometer_ld operator""_cubic_hm(long double val) {
        return static_cast<cubic_hectometer_ld>(val);
    }
    consteval cubic_decameter_ld operator""_cubic_dam(long double val) {
        return static_cast<cubic_decameter_ld>(val);
    }
    consteval cubic_meter_ld operator""_cubic_m(long double val) {
        return static_cast<cubic_meter_ld>(val);
    }
    consteval cubic_decimeter_ld operator""_cubic_dm(long double val) {
        return static_cast<cubic_decimeter_ld>(val);
    }
    consteval cubic_centimeter_ld operator""_cubic_cm(long double val) {
        return static_cast<cubic_centimeter_ld>(val);
    }
    consteval cubic_millimeter_ld operator""_cubic_mm(long double val) {
        return static_cast<cubic_millimeter_ld>(val);
    }
    consteval cubic_micrometer_ld operator""_cubic_um(long double val) {
        return static_cast<cubic_micrometer_ld>(val);
    }
    consteval cubic_nanometer_ld operator""_cubic_nm(long double val) {
        return static_cast<cubic_nanometer_ld>(val);
    }
    consteval cubic_picometer_ld operator""_cubic_pm(long double val) {
        return static_cast<cubic_picometer_ld>(val);
    }
    consteval cubic_femtometer_ld operator""_cubic_fm(long double val) {
        return static_cast<cubic_femtometer_ld>(val);
    }
    consteval cubic_attometer_ld operator""_cubic_am(long double val) {
        return static_cast<cubic_attometer_ld>(val);
    }
    consteval cubic_exameter_ull operator""_cubic_Em(unsigned long long val) {
        return static_cast<cubic_exameter_ull>(val);
    }
    consteval cubic_petameter_ull operator""_cubic_Pm(unsigned long long val) {
        return static_cast<cubic_petameter_ull>(val);
    }
    consteval cubic_terameter_ull operator""_cubic_Tm(unsigned long long val) {
        return static_cast<cubic_terameter_ull>(val);
    }
    consteval cubic_gigameter_ull operator""_cubic_Gm(unsigned long long val) {
        return static_cast<cubic_gigameter_ull>(val);
    }
    consteval cubic_megameter_ull operator""_cubic_Mm(unsigned long long val) {
        return static_cast<cubic_megameter_ull>(val);
    }
    consteval cubic_kilometer_ull operator""_cubic_km(unsigned long long val) {
        return static_cast<cubic_kilometer_ull>(val);
    }
    consteval cubic_hectometer_ull operator""_cubic_hm(unsigned long long val) {
        return static_cast<cubic_hectometer_ull>(val);
    }
    consteval cubic_decameter_ull operator""_cubic_dam(unsigned long long val) {
        return static_cast<cubic_decameter_ull>(val);
    }
    consteval cubic_meter_ull operator""_cubic_m(unsigned long long val) {
        return static_cast<cubic_meter_ull>(val);
    }
    consteval cubic_decimeter_ull operator""_cubic_dm(unsigned long long val) {
        return static_cast<cubic_decimeter_ull>(val);
    }
    consteval cubic_centimeter_ull operator""_cubic_cm(unsigned long long val) {
        return static_cast<cubic_centimeter_ull>(val);
    }
    consteval cubic_millimeter_ull operator""_cubic_mm(unsigned long long val) {
        return static_cast<cubic_millimeter_ull>(val);
    }
    consteval cubic_micrometer_ull operator""_cubic_um(unsigned long long val) {
        return static_cast<cubic_micrometer_ull>(val);
    }
    consteval cubic_nanometer_ull operator""_cubic_nm(unsigned long long val) {
        return static_cast<cubic_nanometer_ull>(val);
    }
    consteval cubic_picometer_ull operator""_cubic_pm(unsigned long long val) {
        return static_cast<cubic_picometer_ull>(val);
    }
    consteval cubic_femtometer_ull operator""_cubic_fm(unsigned long long val) {
        return static_cast<cubic_femtometer_ull>(val);
    }
    consteval cubic_attometer_ull operator""_cubic_am(unsigned long long val) {
        return static_cast<cubic_attometer_ull>(val);
    }

} // namespace potato::units
