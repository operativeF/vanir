//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Volt_Meter;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using electric_flux_tag_t = tmp::list_<Length<std::ratio<3, 1>>,
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
    concept Volt_MeterC = std::same_as<typename T::impl, electric_flux_tag_t>;

    template <typename RatioTypeT, typename P>
    struct volt_meter_impl {

        static constexpr auto pretty = "V·m";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = electric_flux_tag_t;

        constexpr volt_meter_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exavolt_meter_ld    =     volt_meter_impl<std::exa, long double>;
    using petavolt_meter_ld    =     volt_meter_impl<std::peta, long double>;
    using teravolt_meter_ld    =     volt_meter_impl<std::tera, long double>;
    using gigavolt_meter_ld    =     volt_meter_impl<std::giga, long double>;
    using megavolt_meter_ld    =     volt_meter_impl<std::mega, long double>;
    using kilovolt_meter_ld    =     volt_meter_impl<std::kilo, long double>;
    using hectovolt_meter_ld    =     volt_meter_impl<std::hecto, long double>;
    using decavolt_meter_ld    =     volt_meter_impl<std::deca, long double>;
    using volt_meter_ld    =     volt_meter_impl<unity_ratio, long double>;
    using decivolt_meter_ld    =     volt_meter_impl<std::deci, long double>;
    using centivolt_meter_ld    =     volt_meter_impl<std::centi, long double>;
    using millivolt_meter_ld    =     volt_meter_impl<std::milli, long double>;
    using microvolt_meter_ld    =     volt_meter_impl<std::micro, long double>;
    using nanovolt_meter_ld    =     volt_meter_impl<std::nano, long double>;
    using picovolt_meter_ld    =     volt_meter_impl<std::pico, long double>;
    using femtovolt_meter_ld    =     volt_meter_impl<std::femto, long double>;
    using attovolt_meter_ld    =     volt_meter_impl<std::atto, long double>;
    using exavolt_meter_ull    =     volt_meter_impl<std::exa, unsigned long long>;
    using petavolt_meter_ull    =     volt_meter_impl<std::peta, unsigned long long>;
    using teravolt_meter_ull    =     volt_meter_impl<std::tera, unsigned long long>;
    using gigavolt_meter_ull    =     volt_meter_impl<std::giga, unsigned long long>;
    using megavolt_meter_ull    =     volt_meter_impl<std::mega, unsigned long long>;
    using kilovolt_meter_ull    =     volt_meter_impl<std::kilo, unsigned long long>;
    using hectovolt_meter_ull    =     volt_meter_impl<std::hecto, unsigned long long>;
    using decavolt_meter_ull    =     volt_meter_impl<std::deca, unsigned long long>;
    using volt_meter_ull    =     volt_meter_impl<unity_ratio, unsigned long long>;
    using decivolt_meter_ull    =     volt_meter_impl<std::deci, unsigned long long>;
    using centivolt_meter_ull    =     volt_meter_impl<std::centi, unsigned long long>;
    using millivolt_meter_ull    =     volt_meter_impl<std::milli, unsigned long long>;
    using microvolt_meter_ull    =     volt_meter_impl<std::micro, unsigned long long>;
    using nanovolt_meter_ull    =     volt_meter_impl<std::nano, unsigned long long>;
    using picovolt_meter_ull    =     volt_meter_impl<std::pico, unsigned long long>;
    using femtovolt_meter_ull    =     volt_meter_impl<std::femto, unsigned long long>;
    using attovolt_meter_ull    =     volt_meter_impl<std::atto, unsigned long long>;

    constexpr exavolt_meter_ld operator""_EV_m(long double val) {
        return static_cast<exavolt_meter_ld>(val);
    }
    constexpr petavolt_meter_ld operator""_PV_m(long double val) {
        return static_cast<petavolt_meter_ld>(val);
    }
    constexpr teravolt_meter_ld operator""_TV_m(long double val) {
        return static_cast<teravolt_meter_ld>(val);
    }
    constexpr gigavolt_meter_ld operator""_GV_m(long double val) {
        return static_cast<gigavolt_meter_ld>(val);
    }
    constexpr megavolt_meter_ld operator""_MV_m(long double val) {
        return static_cast<megavolt_meter_ld>(val);
    }
    constexpr kilovolt_meter_ld operator""_kV_m(long double val) {
        return static_cast<kilovolt_meter_ld>(val);
    }
    constexpr hectovolt_meter_ld operator""_hV_m(long double val) {
        return static_cast<hectovolt_meter_ld>(val);
    }
    constexpr decavolt_meter_ld operator""_daV_m(long double val) {
        return static_cast<decavolt_meter_ld>(val);
    }
    constexpr volt_meter_ld operator""_V_m(long double val) {
        return static_cast<volt_meter_ld>(val);
    }
    constexpr decivolt_meter_ld operator""_dV_m(long double val) {
        return static_cast<decivolt_meter_ld>(val);
    }
    constexpr centivolt_meter_ld operator""_cV_m(long double val) {
        return static_cast<centivolt_meter_ld>(val);
    }
    constexpr millivolt_meter_ld operator""_mV_m(long double val) {
        return static_cast<millivolt_meter_ld>(val);
    }
    constexpr microvolt_meter_ld operator""_uV_m(long double val) {
        return static_cast<microvolt_meter_ld>(val);
    }
    constexpr nanovolt_meter_ld operator""_nV_m(long double val) {
        return static_cast<nanovolt_meter_ld>(val);
    }
    constexpr picovolt_meter_ld operator""_pV_m(long double val) {
        return static_cast<picovolt_meter_ld>(val);
    }
    constexpr femtovolt_meter_ld operator""_fV_m(long double val) {
        return static_cast<femtovolt_meter_ld>(val);
    }
    constexpr attovolt_meter_ld operator""_aV_m(long double val) {
        return static_cast<attovolt_meter_ld>(val);
    }
    constexpr exavolt_meter_ull operator""_EV_m(unsigned long long val) {
        return static_cast<exavolt_meter_ull>(val);
    }
    constexpr petavolt_meter_ull operator""_PV_m(unsigned long long val) {
        return static_cast<petavolt_meter_ull>(val);
    }
    constexpr teravolt_meter_ull operator""_TV_m(unsigned long long val) {
        return static_cast<teravolt_meter_ull>(val);
    }
    constexpr gigavolt_meter_ull operator""_GV_m(unsigned long long val) {
        return static_cast<gigavolt_meter_ull>(val);
    }
    constexpr megavolt_meter_ull operator""_MV_m(unsigned long long val) {
        return static_cast<megavolt_meter_ull>(val);
    }
    constexpr kilovolt_meter_ull operator""_kV_m(unsigned long long val) {
        return static_cast<kilovolt_meter_ull>(val);
    }
    constexpr hectovolt_meter_ull operator""_hV_m(unsigned long long val) {
        return static_cast<hectovolt_meter_ull>(val);
    }
    constexpr decavolt_meter_ull operator""_daV_m(unsigned long long val) {
        return static_cast<decavolt_meter_ull>(val);
    }
    constexpr volt_meter_ull operator""_V_m(unsigned long long val) {
        return static_cast<volt_meter_ull>(val);
    }
    constexpr decivolt_meter_ull operator""_dV_m(unsigned long long val) {
        return static_cast<decivolt_meter_ull>(val);
    }
    constexpr centivolt_meter_ull operator""_cV_m(unsigned long long val) {
        return static_cast<centivolt_meter_ull>(val);
    }
    constexpr millivolt_meter_ull operator""_mV_m(unsigned long long val) {
        return static_cast<millivolt_meter_ull>(val);
    }
    constexpr microvolt_meter_ull operator""_uV_m(unsigned long long val) {
        return static_cast<microvolt_meter_ull>(val);
    }
    constexpr nanovolt_meter_ull operator""_nV_m(unsigned long long val) {
        return static_cast<nanovolt_meter_ull>(val);
    }
    constexpr picovolt_meter_ull operator""_pV_m(unsigned long long val) {
        return static_cast<picovolt_meter_ull>(val);
    }
    constexpr femtovolt_meter_ull operator""_fV_m(unsigned long long val) {
        return static_cast<femtovolt_meter_ull>(val);
    }
    constexpr attovolt_meter_ull operator""_aV_m(unsigned long long val) {
        return static_cast<attovolt_meter_ull>(val);
    }

} // namespace potato::units
