//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Watt_Per_Steradian_Cubic_Meter;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using spectral_radiance_tag_t = tmp::list_<Length<std::ratio<-1, 1>>,
                                         Time<std::ratio<-3, 1>>,
                                         Mass<std::ratio<1, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<1, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept Watt_Per_Steradian_Cubic_MeterC = std::same_as<typename T::impl, spectral_radiance_tag_t>;

    template <typename RatioTypeT, typename P>
    struct watt_per_steradian_cubic_meter_impl {

        static constexpr auto pretty = "W/(sr·m³)";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = spectral_radiance_tag_t;

        constexpr watt_per_steradian_cubic_meter_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exawatt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<std::exa, long double>;
    using petawatt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<std::peta, long double>;
    using terawatt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<std::tera, long double>;
    using gigawatt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<std::giga, long double>;
    using megawatt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<std::mega, long double>;
    using kilowatt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<std::kilo, long double>;
    using hectowatt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<std::hecto, long double>;
    using decawatt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<std::deca, long double>;
    using watt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<unity_ratio, long double>;
    using deciwatt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<std::deci, long double>;
    using centiwatt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<std::centi, long double>;
    using milliwatt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<std::milli, long double>;
    using microwatt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<std::micro, long double>;
    using nanowatt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<std::nano, long double>;
    using picowatt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<std::pico, long double>;
    using femtowatt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<std::femto, long double>;
    using attowatt_per_steradian_cubic_meter_ld    =     watt_per_steradian_cubic_meter_impl<std::atto, long double>;
    using exawatt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<std::exa, unsigned long long>;
    using petawatt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<std::peta, unsigned long long>;
    using terawatt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<std::tera, unsigned long long>;
    using gigawatt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<std::giga, unsigned long long>;
    using megawatt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<std::mega, unsigned long long>;
    using kilowatt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<std::kilo, unsigned long long>;
    using hectowatt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<std::hecto, unsigned long long>;
    using decawatt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<std::deca, unsigned long long>;
    using watt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<unity_ratio, unsigned long long>;
    using deciwatt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<std::deci, unsigned long long>;
    using centiwatt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<std::centi, unsigned long long>;
    using milliwatt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<std::milli, unsigned long long>;
    using microwatt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<std::micro, unsigned long long>;
    using nanowatt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<std::nano, unsigned long long>;
    using picowatt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<std::pico, unsigned long long>;
    using femtowatt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<std::femto, unsigned long long>;
    using attowatt_per_steradian_cubic_meter_ull    =     watt_per_steradian_cubic_meter_impl<std::atto, unsigned long long>;

    consteval exawatt_per_steradian_cubic_meter_ld operator""_EW_per_sr_cubic_m(long double val) {
        return static_cast<exawatt_per_steradian_cubic_meter_ld>(val);
    }
    consteval petawatt_per_steradian_cubic_meter_ld operator""_PW_per_sr_cubic_m(long double val) {
        return static_cast<petawatt_per_steradian_cubic_meter_ld>(val);
    }
    consteval terawatt_per_steradian_cubic_meter_ld operator""_TW_per_sr_cubic_m(long double val) {
        return static_cast<terawatt_per_steradian_cubic_meter_ld>(val);
    }
    consteval gigawatt_per_steradian_cubic_meter_ld operator""_GW_per_sr_cubic_m(long double val) {
        return static_cast<gigawatt_per_steradian_cubic_meter_ld>(val);
    }
    consteval megawatt_per_steradian_cubic_meter_ld operator""_MW_per_sr_cubic_m(long double val) {
        return static_cast<megawatt_per_steradian_cubic_meter_ld>(val);
    }
    consteval kilowatt_per_steradian_cubic_meter_ld operator""_kW_per_sr_cubic_m(long double val) {
        return static_cast<kilowatt_per_steradian_cubic_meter_ld>(val);
    }
    consteval hectowatt_per_steradian_cubic_meter_ld operator""_hW_per_sr_cubic_m(long double val) {
        return static_cast<hectowatt_per_steradian_cubic_meter_ld>(val);
    }
    consteval decawatt_per_steradian_cubic_meter_ld operator""_daW_per_sr_cubic_m(long double val) {
        return static_cast<decawatt_per_steradian_cubic_meter_ld>(val);
    }
    consteval watt_per_steradian_cubic_meter_ld operator""_W_per_sr_cubic_m(long double val) {
        return static_cast<watt_per_steradian_cubic_meter_ld>(val);
    }
    consteval deciwatt_per_steradian_cubic_meter_ld operator""_dW_per_sr_cubic_m(long double val) {
        return static_cast<deciwatt_per_steradian_cubic_meter_ld>(val);
    }
    consteval centiwatt_per_steradian_cubic_meter_ld operator""_cW_per_sr_cubic_m(long double val) {
        return static_cast<centiwatt_per_steradian_cubic_meter_ld>(val);
    }
    consteval milliwatt_per_steradian_cubic_meter_ld operator""_mW_per_sr_cubic_m(long double val) {
        return static_cast<milliwatt_per_steradian_cubic_meter_ld>(val);
    }
    consteval microwatt_per_steradian_cubic_meter_ld operator""_uW_per_sr_cubic_m(long double val) {
        return static_cast<microwatt_per_steradian_cubic_meter_ld>(val);
    }
    consteval nanowatt_per_steradian_cubic_meter_ld operator""_nW_per_sr_cubic_m(long double val) {
        return static_cast<nanowatt_per_steradian_cubic_meter_ld>(val);
    }
    consteval picowatt_per_steradian_cubic_meter_ld operator""_pW_per_sr_cubic_m(long double val) {
        return static_cast<picowatt_per_steradian_cubic_meter_ld>(val);
    }
    consteval femtowatt_per_steradian_cubic_meter_ld operator""_fW_per_sr_cubic_m(long double val) {
        return static_cast<femtowatt_per_steradian_cubic_meter_ld>(val);
    }
    consteval attowatt_per_steradian_cubic_meter_ld operator""_aW_per_sr_cubic_m(long double val) {
        return static_cast<attowatt_per_steradian_cubic_meter_ld>(val);
    }
    consteval exawatt_per_steradian_cubic_meter_ull operator""_EW_per_sr_cubic_m(unsigned long long val) {
        return static_cast<exawatt_per_steradian_cubic_meter_ull>(val);
    }
    consteval petawatt_per_steradian_cubic_meter_ull operator""_PW_per_sr_cubic_m(unsigned long long val) {
        return static_cast<petawatt_per_steradian_cubic_meter_ull>(val);
    }
    consteval terawatt_per_steradian_cubic_meter_ull operator""_TW_per_sr_cubic_m(unsigned long long val) {
        return static_cast<terawatt_per_steradian_cubic_meter_ull>(val);
    }
    consteval gigawatt_per_steradian_cubic_meter_ull operator""_GW_per_sr_cubic_m(unsigned long long val) {
        return static_cast<gigawatt_per_steradian_cubic_meter_ull>(val);
    }
    consteval megawatt_per_steradian_cubic_meter_ull operator""_MW_per_sr_cubic_m(unsigned long long val) {
        return static_cast<megawatt_per_steradian_cubic_meter_ull>(val);
    }
    consteval kilowatt_per_steradian_cubic_meter_ull operator""_kW_per_sr_cubic_m(unsigned long long val) {
        return static_cast<kilowatt_per_steradian_cubic_meter_ull>(val);
    }
    consteval hectowatt_per_steradian_cubic_meter_ull operator""_hW_per_sr_cubic_m(unsigned long long val) {
        return static_cast<hectowatt_per_steradian_cubic_meter_ull>(val);
    }
    consteval decawatt_per_steradian_cubic_meter_ull operator""_daW_per_sr_cubic_m(unsigned long long val) {
        return static_cast<decawatt_per_steradian_cubic_meter_ull>(val);
    }
    consteval watt_per_steradian_cubic_meter_ull operator""_W_per_sr_cubic_m(unsigned long long val) {
        return static_cast<watt_per_steradian_cubic_meter_ull>(val);
    }
    consteval deciwatt_per_steradian_cubic_meter_ull operator""_dW_per_sr_cubic_m(unsigned long long val) {
        return static_cast<deciwatt_per_steradian_cubic_meter_ull>(val);
    }
    consteval centiwatt_per_steradian_cubic_meter_ull operator""_cW_per_sr_cubic_m(unsigned long long val) {
        return static_cast<centiwatt_per_steradian_cubic_meter_ull>(val);
    }
    consteval milliwatt_per_steradian_cubic_meter_ull operator""_mW_per_sr_cubic_m(unsigned long long val) {
        return static_cast<milliwatt_per_steradian_cubic_meter_ull>(val);
    }
    consteval microwatt_per_steradian_cubic_meter_ull operator""_uW_per_sr_cubic_m(unsigned long long val) {
        return static_cast<microwatt_per_steradian_cubic_meter_ull>(val);
    }
    consteval nanowatt_per_steradian_cubic_meter_ull operator""_nW_per_sr_cubic_m(unsigned long long val) {
        return static_cast<nanowatt_per_steradian_cubic_meter_ull>(val);
    }
    consteval picowatt_per_steradian_cubic_meter_ull operator""_pW_per_sr_cubic_m(unsigned long long val) {
        return static_cast<picowatt_per_steradian_cubic_meter_ull>(val);
    }
    consteval femtowatt_per_steradian_cubic_meter_ull operator""_fW_per_sr_cubic_m(unsigned long long val) {
        return static_cast<femtowatt_per_steradian_cubic_meter_ull>(val);
    }
    consteval attowatt_per_steradian_cubic_meter_ull operator""_aW_per_sr_cubic_m(unsigned long long val) {
        return static_cast<attowatt_per_steradian_cubic_meter_ull>(val);
    }

} // namespace potato::units
