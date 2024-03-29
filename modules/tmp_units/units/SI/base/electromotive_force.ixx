//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Volt;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using electromotive_force_tag_t = tmp::list_<Length<std::ratio<2, 1>>,
                                         Time<std::ratio<-3, 1>>,
                                         Mass<std::ratio<1, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<-1, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept VoltC = std::same_as<typename T::impl, electromotive_force_tag_t>;

    template <typename RatioTypeT, typename P>
    struct volt_impl {

        static constexpr auto pretty = "V";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = electromotive_force_tag_t;

        constexpr volt_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exavolt_ld    =     volt_impl<std::exa, long double>;
    using petavolt_ld    =     volt_impl<std::peta, long double>;
    using teravolt_ld    =     volt_impl<std::tera, long double>;
    using gigavolt_ld    =     volt_impl<std::giga, long double>;
    using megavolt_ld    =     volt_impl<std::mega, long double>;
    using kilovolt_ld    =     volt_impl<std::kilo, long double>;
    using hectovolt_ld    =     volt_impl<std::hecto, long double>;
    using decavolt_ld    =     volt_impl<std::deca, long double>;
    using volt_ld    =     volt_impl<unity_ratio, long double>;
    using decivolt_ld    =     volt_impl<std::deci, long double>;
    using centivolt_ld    =     volt_impl<std::centi, long double>;
    using millivolt_ld    =     volt_impl<std::milli, long double>;
    using microvolt_ld    =     volt_impl<std::micro, long double>;
    using nanovolt_ld    =     volt_impl<std::nano, long double>;
    using picovolt_ld    =     volt_impl<std::pico, long double>;
    using femtovolt_ld    =     volt_impl<std::femto, long double>;
    using attovolt_ld    =     volt_impl<std::atto, long double>;
    using exavolt_ull    =     volt_impl<std::exa, unsigned long long>;
    using petavolt_ull    =     volt_impl<std::peta, unsigned long long>;
    using teravolt_ull    =     volt_impl<std::tera, unsigned long long>;
    using gigavolt_ull    =     volt_impl<std::giga, unsigned long long>;
    using megavolt_ull    =     volt_impl<std::mega, unsigned long long>;
    using kilovolt_ull    =     volt_impl<std::kilo, unsigned long long>;
    using hectovolt_ull    =     volt_impl<std::hecto, unsigned long long>;
    using decavolt_ull    =     volt_impl<std::deca, unsigned long long>;
    using volt_ull    =     volt_impl<unity_ratio, unsigned long long>;
    using decivolt_ull    =     volt_impl<std::deci, unsigned long long>;
    using centivolt_ull    =     volt_impl<std::centi, unsigned long long>;
    using millivolt_ull    =     volt_impl<std::milli, unsigned long long>;
    using microvolt_ull    =     volt_impl<std::micro, unsigned long long>;
    using nanovolt_ull    =     volt_impl<std::nano, unsigned long long>;
    using picovolt_ull    =     volt_impl<std::pico, unsigned long long>;
    using femtovolt_ull    =     volt_impl<std::femto, unsigned long long>;
    using attovolt_ull    =     volt_impl<std::atto, unsigned long long>;

    consteval exavolt_ld operator""_EV(long double val) {
        return static_cast<exavolt_ld>(val);
    }
    consteval petavolt_ld operator""_PV(long double val) {
        return static_cast<petavolt_ld>(val);
    }
    consteval teravolt_ld operator""_TV(long double val) {
        return static_cast<teravolt_ld>(val);
    }
    consteval gigavolt_ld operator""_GV(long double val) {
        return static_cast<gigavolt_ld>(val);
    }
    consteval megavolt_ld operator""_MV(long double val) {
        return static_cast<megavolt_ld>(val);
    }
    consteval kilovolt_ld operator""_kV(long double val) {
        return static_cast<kilovolt_ld>(val);
    }
    consteval hectovolt_ld operator""_hV(long double val) {
        return static_cast<hectovolt_ld>(val);
    }
    consteval decavolt_ld operator""_daV(long double val) {
        return static_cast<decavolt_ld>(val);
    }
    consteval volt_ld operator""_V(long double val) {
        return static_cast<volt_ld>(val);
    }
    consteval decivolt_ld operator""_dV(long double val) {
        return static_cast<decivolt_ld>(val);
    }
    consteval centivolt_ld operator""_cV(long double val) {
        return static_cast<centivolt_ld>(val);
    }
    consteval millivolt_ld operator""_mV(long double val) {
        return static_cast<millivolt_ld>(val);
    }
    consteval microvolt_ld operator""_uV(long double val) {
        return static_cast<microvolt_ld>(val);
    }
    consteval nanovolt_ld operator""_nV(long double val) {
        return static_cast<nanovolt_ld>(val);
    }
    consteval picovolt_ld operator""_pV(long double val) {
        return static_cast<picovolt_ld>(val);
    }
    consteval femtovolt_ld operator""_fV(long double val) {
        return static_cast<femtovolt_ld>(val);
    }
    consteval attovolt_ld operator""_aV(long double val) {
        return static_cast<attovolt_ld>(val);
    }
    consteval exavolt_ull operator""_EV(unsigned long long val) {
        return static_cast<exavolt_ull>(val);
    }
    consteval petavolt_ull operator""_PV(unsigned long long val) {
        return static_cast<petavolt_ull>(val);
    }
    consteval teravolt_ull operator""_TV(unsigned long long val) {
        return static_cast<teravolt_ull>(val);
    }
    consteval gigavolt_ull operator""_GV(unsigned long long val) {
        return static_cast<gigavolt_ull>(val);
    }
    consteval megavolt_ull operator""_MV(unsigned long long val) {
        return static_cast<megavolt_ull>(val);
    }
    consteval kilovolt_ull operator""_kV(unsigned long long val) {
        return static_cast<kilovolt_ull>(val);
    }
    consteval hectovolt_ull operator""_hV(unsigned long long val) {
        return static_cast<hectovolt_ull>(val);
    }
    consteval decavolt_ull operator""_daV(unsigned long long val) {
        return static_cast<decavolt_ull>(val);
    }
    consteval volt_ull operator""_V(unsigned long long val) {
        return static_cast<volt_ull>(val);
    }
    consteval decivolt_ull operator""_dV(unsigned long long val) {
        return static_cast<decivolt_ull>(val);
    }
    consteval centivolt_ull operator""_cV(unsigned long long val) {
        return static_cast<centivolt_ull>(val);
    }
    consteval millivolt_ull operator""_mV(unsigned long long val) {
        return static_cast<millivolt_ull>(val);
    }
    consteval microvolt_ull operator""_uV(unsigned long long val) {
        return static_cast<microvolt_ull>(val);
    }
    consteval nanovolt_ull operator""_nV(unsigned long long val) {
        return static_cast<nanovolt_ull>(val);
    }
    consteval picovolt_ull operator""_pV(unsigned long long val) {
        return static_cast<picovolt_ull>(val);
    }
    consteval femtovolt_ull operator""_fV(unsigned long long val) {
        return static_cast<femtovolt_ull>(val);
    }
    consteval attovolt_ull operator""_aV(unsigned long long val) {
        return static_cast<attovolt_ull>(val);
    }

} // namespace potato::units
