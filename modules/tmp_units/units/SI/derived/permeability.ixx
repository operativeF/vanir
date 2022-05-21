//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Henry_Per_Meter;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using permeability_tag_t = tmp::list_<Length<std::ratio<1, 1>>,
                                         Time<std::ratio<-2, 1>>,
                                         Mass<std::ratio<1, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<-2, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept Henry_Per_MeterC = std::same_as<typename T::impl, permeability_tag_t>;

    template <typename RatioTypeT, typename P>
    struct henry_per_meter_impl {

        static constexpr auto pretty = "H/m";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = permeability_tag_t;

        constexpr henry_per_meter_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exahenry_per_meter_ld    =     henry_per_meter_impl<std::exa, long double>;
    using petahenry_per_meter_ld    =     henry_per_meter_impl<std::peta, long double>;
    using terahenry_per_meter_ld    =     henry_per_meter_impl<std::tera, long double>;
    using gigahenry_per_meter_ld    =     henry_per_meter_impl<std::giga, long double>;
    using megahenry_per_meter_ld    =     henry_per_meter_impl<std::mega, long double>;
    using kilohenry_per_meter_ld    =     henry_per_meter_impl<std::kilo, long double>;
    using hectohenry_per_meter_ld    =     henry_per_meter_impl<std::hecto, long double>;
    using decahenry_per_meter_ld    =     henry_per_meter_impl<std::deca, long double>;
    using henry_per_meter_ld    =     henry_per_meter_impl<unity_ratio, long double>;
    using decihenry_per_meter_ld    =     henry_per_meter_impl<std::deci, long double>;
    using centihenry_per_meter_ld    =     henry_per_meter_impl<std::centi, long double>;
    using millihenry_per_meter_ld    =     henry_per_meter_impl<std::milli, long double>;
    using microhenry_per_meter_ld    =     henry_per_meter_impl<std::micro, long double>;
    using nanohenry_per_meter_ld    =     henry_per_meter_impl<std::nano, long double>;
    using picohenry_per_meter_ld    =     henry_per_meter_impl<std::pico, long double>;
    using femtohenry_per_meter_ld    =     henry_per_meter_impl<std::femto, long double>;
    using attohenry_per_meter_ld    =     henry_per_meter_impl<std::atto, long double>;
    using exahenry_per_meter_ull    =     henry_per_meter_impl<std::exa, unsigned long long>;
    using petahenry_per_meter_ull    =     henry_per_meter_impl<std::peta, unsigned long long>;
    using terahenry_per_meter_ull    =     henry_per_meter_impl<std::tera, unsigned long long>;
    using gigahenry_per_meter_ull    =     henry_per_meter_impl<std::giga, unsigned long long>;
    using megahenry_per_meter_ull    =     henry_per_meter_impl<std::mega, unsigned long long>;
    using kilohenry_per_meter_ull    =     henry_per_meter_impl<std::kilo, unsigned long long>;
    using hectohenry_per_meter_ull    =     henry_per_meter_impl<std::hecto, unsigned long long>;
    using decahenry_per_meter_ull    =     henry_per_meter_impl<std::deca, unsigned long long>;
    using henry_per_meter_ull    =     henry_per_meter_impl<unity_ratio, unsigned long long>;
    using decihenry_per_meter_ull    =     henry_per_meter_impl<std::deci, unsigned long long>;
    using centihenry_per_meter_ull    =     henry_per_meter_impl<std::centi, unsigned long long>;
    using millihenry_per_meter_ull    =     henry_per_meter_impl<std::milli, unsigned long long>;
    using microhenry_per_meter_ull    =     henry_per_meter_impl<std::micro, unsigned long long>;
    using nanohenry_per_meter_ull    =     henry_per_meter_impl<std::nano, unsigned long long>;
    using picohenry_per_meter_ull    =     henry_per_meter_impl<std::pico, unsigned long long>;
    using femtohenry_per_meter_ull    =     henry_per_meter_impl<std::femto, unsigned long long>;
    using attohenry_per_meter_ull    =     henry_per_meter_impl<std::atto, unsigned long long>;

    consteval exahenry_per_meter_ld operator""_EH_per_m(long double val) {
        return static_cast<exahenry_per_meter_ld>(val);
    }
    consteval petahenry_per_meter_ld operator""_PH_per_m(long double val) {
        return static_cast<petahenry_per_meter_ld>(val);
    }
    consteval terahenry_per_meter_ld operator""_TH_per_m(long double val) {
        return static_cast<terahenry_per_meter_ld>(val);
    }
    consteval gigahenry_per_meter_ld operator""_GH_per_m(long double val) {
        return static_cast<gigahenry_per_meter_ld>(val);
    }
    consteval megahenry_per_meter_ld operator""_MH_per_m(long double val) {
        return static_cast<megahenry_per_meter_ld>(val);
    }
    consteval kilohenry_per_meter_ld operator""_kH_per_m(long double val) {
        return static_cast<kilohenry_per_meter_ld>(val);
    }
    consteval hectohenry_per_meter_ld operator""_hH_per_m(long double val) {
        return static_cast<hectohenry_per_meter_ld>(val);
    }
    consteval decahenry_per_meter_ld operator""_daH_per_m(long double val) {
        return static_cast<decahenry_per_meter_ld>(val);
    }
    consteval henry_per_meter_ld operator""_H_per_m(long double val) {
        return static_cast<henry_per_meter_ld>(val);
    }
    consteval decihenry_per_meter_ld operator""_dH_per_m(long double val) {
        return static_cast<decihenry_per_meter_ld>(val);
    }
    consteval centihenry_per_meter_ld operator""_cH_per_m(long double val) {
        return static_cast<centihenry_per_meter_ld>(val);
    }
    consteval millihenry_per_meter_ld operator""_mH_per_m(long double val) {
        return static_cast<millihenry_per_meter_ld>(val);
    }
    consteval microhenry_per_meter_ld operator""_uH_per_m(long double val) {
        return static_cast<microhenry_per_meter_ld>(val);
    }
    consteval nanohenry_per_meter_ld operator""_nH_per_m(long double val) {
        return static_cast<nanohenry_per_meter_ld>(val);
    }
    consteval picohenry_per_meter_ld operator""_pH_per_m(long double val) {
        return static_cast<picohenry_per_meter_ld>(val);
    }
    consteval femtohenry_per_meter_ld operator""_fH_per_m(long double val) {
        return static_cast<femtohenry_per_meter_ld>(val);
    }
    consteval attohenry_per_meter_ld operator""_aH_per_m(long double val) {
        return static_cast<attohenry_per_meter_ld>(val);
    }
    consteval exahenry_per_meter_ull operator""_EH_per_m(unsigned long long val) {
        return static_cast<exahenry_per_meter_ull>(val);
    }
    consteval petahenry_per_meter_ull operator""_PH_per_m(unsigned long long val) {
        return static_cast<petahenry_per_meter_ull>(val);
    }
    consteval terahenry_per_meter_ull operator""_TH_per_m(unsigned long long val) {
        return static_cast<terahenry_per_meter_ull>(val);
    }
    consteval gigahenry_per_meter_ull operator""_GH_per_m(unsigned long long val) {
        return static_cast<gigahenry_per_meter_ull>(val);
    }
    consteval megahenry_per_meter_ull operator""_MH_per_m(unsigned long long val) {
        return static_cast<megahenry_per_meter_ull>(val);
    }
    consteval kilohenry_per_meter_ull operator""_kH_per_m(unsigned long long val) {
        return static_cast<kilohenry_per_meter_ull>(val);
    }
    consteval hectohenry_per_meter_ull operator""_hH_per_m(unsigned long long val) {
        return static_cast<hectohenry_per_meter_ull>(val);
    }
    consteval decahenry_per_meter_ull operator""_daH_per_m(unsigned long long val) {
        return static_cast<decahenry_per_meter_ull>(val);
    }
    consteval henry_per_meter_ull operator""_H_per_m(unsigned long long val) {
        return static_cast<henry_per_meter_ull>(val);
    }
    consteval decihenry_per_meter_ull operator""_dH_per_m(unsigned long long val) {
        return static_cast<decihenry_per_meter_ull>(val);
    }
    consteval centihenry_per_meter_ull operator""_cH_per_m(unsigned long long val) {
        return static_cast<centihenry_per_meter_ull>(val);
    }
    consteval millihenry_per_meter_ull operator""_mH_per_m(unsigned long long val) {
        return static_cast<millihenry_per_meter_ull>(val);
    }
    consteval microhenry_per_meter_ull operator""_uH_per_m(unsigned long long val) {
        return static_cast<microhenry_per_meter_ull>(val);
    }
    consteval nanohenry_per_meter_ull operator""_nH_per_m(unsigned long long val) {
        return static_cast<nanohenry_per_meter_ull>(val);
    }
    consteval picohenry_per_meter_ull operator""_pH_per_m(unsigned long long val) {
        return static_cast<picohenry_per_meter_ull>(val);
    }
    consteval femtohenry_per_meter_ull operator""_fH_per_m(unsigned long long val) {
        return static_cast<femtohenry_per_meter_ull>(val);
    }
    consteval attohenry_per_meter_ull operator""_aH_per_m(unsigned long long val) {
        return static_cast<attohenry_per_meter_ull>(val);
    }

} // namespace potato::units
