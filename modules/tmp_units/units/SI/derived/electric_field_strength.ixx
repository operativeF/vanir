//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Volt_Per_Meter;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using electric_field_strength_tag_t = tmp::list_<Length<std::ratio<1, 1>>,
                                         Time<std::ratio<-3, 1>>,
                                         Mass<std::ratio<1, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<1, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept Volt_Per_MeterC = std::same_as<typename T::impl, electric_field_strength_tag_t>;

    template <typename RatioTypeT, typename P>
    struct volt_per_meter_impl {

        static constexpr auto pretty = "V/m";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = electric_field_strength_tag_t;

        constexpr volt_per_meter_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exavolt_per_meter_ld    =     volt_per_meter_impl<std::exa, long double>;
    using petavolt_per_meter_ld    =     volt_per_meter_impl<std::peta, long double>;
    using teravolt_per_meter_ld    =     volt_per_meter_impl<std::tera, long double>;
    using gigavolt_per_meter_ld    =     volt_per_meter_impl<std::giga, long double>;
    using megavolt_per_meter_ld    =     volt_per_meter_impl<std::mega, long double>;
    using kilovolt_per_meter_ld    =     volt_per_meter_impl<std::kilo, long double>;
    using hectovolt_per_meter_ld    =     volt_per_meter_impl<std::hecto, long double>;
    using decavolt_per_meter_ld    =     volt_per_meter_impl<std::deca, long double>;
    using volt_per_meter_ld    =     volt_per_meter_impl<unity_ratio, long double>;
    using decivolt_per_meter_ld    =     volt_per_meter_impl<std::deci, long double>;
    using centivolt_per_meter_ld    =     volt_per_meter_impl<std::centi, long double>;
    using millivolt_per_meter_ld    =     volt_per_meter_impl<std::milli, long double>;
    using microvolt_per_meter_ld    =     volt_per_meter_impl<std::micro, long double>;
    using nanovolt_per_meter_ld    =     volt_per_meter_impl<std::nano, long double>;
    using picovolt_per_meter_ld    =     volt_per_meter_impl<std::pico, long double>;
    using femtovolt_per_meter_ld    =     volt_per_meter_impl<std::femto, long double>;
    using attovolt_per_meter_ld    =     volt_per_meter_impl<std::atto, long double>;
    using exavolt_per_meter_ull    =     volt_per_meter_impl<std::exa, unsigned long long>;
    using petavolt_per_meter_ull    =     volt_per_meter_impl<std::peta, unsigned long long>;
    using teravolt_per_meter_ull    =     volt_per_meter_impl<std::tera, unsigned long long>;
    using gigavolt_per_meter_ull    =     volt_per_meter_impl<std::giga, unsigned long long>;
    using megavolt_per_meter_ull    =     volt_per_meter_impl<std::mega, unsigned long long>;
    using kilovolt_per_meter_ull    =     volt_per_meter_impl<std::kilo, unsigned long long>;
    using hectovolt_per_meter_ull    =     volt_per_meter_impl<std::hecto, unsigned long long>;
    using decavolt_per_meter_ull    =     volt_per_meter_impl<std::deca, unsigned long long>;
    using volt_per_meter_ull    =     volt_per_meter_impl<unity_ratio, unsigned long long>;
    using decivolt_per_meter_ull    =     volt_per_meter_impl<std::deci, unsigned long long>;
    using centivolt_per_meter_ull    =     volt_per_meter_impl<std::centi, unsigned long long>;
    using millivolt_per_meter_ull    =     volt_per_meter_impl<std::milli, unsigned long long>;
    using microvolt_per_meter_ull    =     volt_per_meter_impl<std::micro, unsigned long long>;
    using nanovolt_per_meter_ull    =     volt_per_meter_impl<std::nano, unsigned long long>;
    using picovolt_per_meter_ull    =     volt_per_meter_impl<std::pico, unsigned long long>;
    using femtovolt_per_meter_ull    =     volt_per_meter_impl<std::femto, unsigned long long>;
    using attovolt_per_meter_ull    =     volt_per_meter_impl<std::atto, unsigned long long>;

    constexpr exavolt_per_meter_ld operator""_EV_per_m(long double val) {
        return static_cast<exavolt_per_meter_ld>(val);
    }
    constexpr petavolt_per_meter_ld operator""_PV_per_m(long double val) {
        return static_cast<petavolt_per_meter_ld>(val);
    }
    constexpr teravolt_per_meter_ld operator""_TV_per_m(long double val) {
        return static_cast<teravolt_per_meter_ld>(val);
    }
    constexpr gigavolt_per_meter_ld operator""_GV_per_m(long double val) {
        return static_cast<gigavolt_per_meter_ld>(val);
    }
    constexpr megavolt_per_meter_ld operator""_MV_per_m(long double val) {
        return static_cast<megavolt_per_meter_ld>(val);
    }
    constexpr kilovolt_per_meter_ld operator""_kV_per_m(long double val) {
        return static_cast<kilovolt_per_meter_ld>(val);
    }
    constexpr hectovolt_per_meter_ld operator""_hV_per_m(long double val) {
        return static_cast<hectovolt_per_meter_ld>(val);
    }
    constexpr decavolt_per_meter_ld operator""_daV_per_m(long double val) {
        return static_cast<decavolt_per_meter_ld>(val);
    }
    constexpr volt_per_meter_ld operator""_V_per_m(long double val) {
        return static_cast<volt_per_meter_ld>(val);
    }
    constexpr decivolt_per_meter_ld operator""_dV_per_m(long double val) {
        return static_cast<decivolt_per_meter_ld>(val);
    }
    constexpr centivolt_per_meter_ld operator""_cV_per_m(long double val) {
        return static_cast<centivolt_per_meter_ld>(val);
    }
    constexpr millivolt_per_meter_ld operator""_mV_per_m(long double val) {
        return static_cast<millivolt_per_meter_ld>(val);
    }
    constexpr microvolt_per_meter_ld operator""_uV_per_m(long double val) {
        return static_cast<microvolt_per_meter_ld>(val);
    }
    constexpr nanovolt_per_meter_ld operator""_nV_per_m(long double val) {
        return static_cast<nanovolt_per_meter_ld>(val);
    }
    constexpr picovolt_per_meter_ld operator""_pV_per_m(long double val) {
        return static_cast<picovolt_per_meter_ld>(val);
    }
    constexpr femtovolt_per_meter_ld operator""_fV_per_m(long double val) {
        return static_cast<femtovolt_per_meter_ld>(val);
    }
    constexpr attovolt_per_meter_ld operator""_aV_per_m(long double val) {
        return static_cast<attovolt_per_meter_ld>(val);
    }
    constexpr exavolt_per_meter_ull operator""_EV_per_m(unsigned long long val) {
        return static_cast<exavolt_per_meter_ull>(val);
    }
    constexpr petavolt_per_meter_ull operator""_PV_per_m(unsigned long long val) {
        return static_cast<petavolt_per_meter_ull>(val);
    }
    constexpr teravolt_per_meter_ull operator""_TV_per_m(unsigned long long val) {
        return static_cast<teravolt_per_meter_ull>(val);
    }
    constexpr gigavolt_per_meter_ull operator""_GV_per_m(unsigned long long val) {
        return static_cast<gigavolt_per_meter_ull>(val);
    }
    constexpr megavolt_per_meter_ull operator""_MV_per_m(unsigned long long val) {
        return static_cast<megavolt_per_meter_ull>(val);
    }
    constexpr kilovolt_per_meter_ull operator""_kV_per_m(unsigned long long val) {
        return static_cast<kilovolt_per_meter_ull>(val);
    }
    constexpr hectovolt_per_meter_ull operator""_hV_per_m(unsigned long long val) {
        return static_cast<hectovolt_per_meter_ull>(val);
    }
    constexpr decavolt_per_meter_ull operator""_daV_per_m(unsigned long long val) {
        return static_cast<decavolt_per_meter_ull>(val);
    }
    constexpr volt_per_meter_ull operator""_V_per_m(unsigned long long val) {
        return static_cast<volt_per_meter_ull>(val);
    }
    constexpr decivolt_per_meter_ull operator""_dV_per_m(unsigned long long val) {
        return static_cast<decivolt_per_meter_ull>(val);
    }
    constexpr centivolt_per_meter_ull operator""_cV_per_m(unsigned long long val) {
        return static_cast<centivolt_per_meter_ull>(val);
    }
    constexpr millivolt_per_meter_ull operator""_mV_per_m(unsigned long long val) {
        return static_cast<millivolt_per_meter_ull>(val);
    }
    constexpr microvolt_per_meter_ull operator""_uV_per_m(unsigned long long val) {
        return static_cast<microvolt_per_meter_ull>(val);
    }
    constexpr nanovolt_per_meter_ull operator""_nV_per_m(unsigned long long val) {
        return static_cast<nanovolt_per_meter_ull>(val);
    }
    constexpr picovolt_per_meter_ull operator""_pV_per_m(unsigned long long val) {
        return static_cast<picovolt_per_meter_ull>(val);
    }
    constexpr femtovolt_per_meter_ull operator""_fV_per_m(unsigned long long val) {
        return static_cast<femtovolt_per_meter_ull>(val);
    }
    constexpr attovolt_per_meter_ull operator""_aV_per_m(unsigned long long val) {
        return static_cast<attovolt_per_meter_ull>(val);
    }

} // namespace potato::units
