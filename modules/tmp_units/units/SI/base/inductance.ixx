//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Henry;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using inductance_tag_t = tmp::list_<Length<std::ratio<2, 1>>,
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
    concept HenryC = std::same_as<typename T::impl, inductance_tag_t>;

    template <typename RatioTypeT, typename P>
    struct henry_impl {

        static constexpr auto pretty = "H";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = inductance_tag_t;

        constexpr henry_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exahenry_ld    =     henry_impl<std::exa, long double>;
    using petahenry_ld    =     henry_impl<std::peta, long double>;
    using terahenry_ld    =     henry_impl<std::tera, long double>;
    using gigahenry_ld    =     henry_impl<std::giga, long double>;
    using megahenry_ld    =     henry_impl<std::mega, long double>;
    using kilohenry_ld    =     henry_impl<std::kilo, long double>;
    using hectohenry_ld    =     henry_impl<std::hecto, long double>;
    using decahenry_ld    =     henry_impl<std::deca, long double>;
    using henry_ld    =     henry_impl<unity_ratio, long double>;
    using decihenry_ld    =     henry_impl<std::deci, long double>;
    using centihenry_ld    =     henry_impl<std::centi, long double>;
    using millihenry_ld    =     henry_impl<std::milli, long double>;
    using microhenry_ld    =     henry_impl<std::micro, long double>;
    using nanohenry_ld    =     henry_impl<std::nano, long double>;
    using picohenry_ld    =     henry_impl<std::pico, long double>;
    using femtohenry_ld    =     henry_impl<std::femto, long double>;
    using attohenry_ld    =     henry_impl<std::atto, long double>;
    using exahenry_ull    =     henry_impl<std::exa, unsigned long long>;
    using petahenry_ull    =     henry_impl<std::peta, unsigned long long>;
    using terahenry_ull    =     henry_impl<std::tera, unsigned long long>;
    using gigahenry_ull    =     henry_impl<std::giga, unsigned long long>;
    using megahenry_ull    =     henry_impl<std::mega, unsigned long long>;
    using kilohenry_ull    =     henry_impl<std::kilo, unsigned long long>;
    using hectohenry_ull    =     henry_impl<std::hecto, unsigned long long>;
    using decahenry_ull    =     henry_impl<std::deca, unsigned long long>;
    using henry_ull    =     henry_impl<unity_ratio, unsigned long long>;
    using decihenry_ull    =     henry_impl<std::deci, unsigned long long>;
    using centihenry_ull    =     henry_impl<std::centi, unsigned long long>;
    using millihenry_ull    =     henry_impl<std::milli, unsigned long long>;
    using microhenry_ull    =     henry_impl<std::micro, unsigned long long>;
    using nanohenry_ull    =     henry_impl<std::nano, unsigned long long>;
    using picohenry_ull    =     henry_impl<std::pico, unsigned long long>;
    using femtohenry_ull    =     henry_impl<std::femto, unsigned long long>;
    using attohenry_ull    =     henry_impl<std::atto, unsigned long long>;

    consteval exahenry_ld operator""_EH(long double val) {
        return static_cast<exahenry_ld>(val);
    }
    consteval petahenry_ld operator""_PH(long double val) {
        return static_cast<petahenry_ld>(val);
    }
    consteval terahenry_ld operator""_TH(long double val) {
        return static_cast<terahenry_ld>(val);
    }
    consteval gigahenry_ld operator""_GH(long double val) {
        return static_cast<gigahenry_ld>(val);
    }
    consteval megahenry_ld operator""_MH(long double val) {
        return static_cast<megahenry_ld>(val);
    }
    consteval kilohenry_ld operator""_kH(long double val) {
        return static_cast<kilohenry_ld>(val);
    }
    consteval hectohenry_ld operator""_hH(long double val) {
        return static_cast<hectohenry_ld>(val);
    }
    consteval decahenry_ld operator""_daH(long double val) {
        return static_cast<decahenry_ld>(val);
    }
    consteval henry_ld operator""_H(long double val) {
        return static_cast<henry_ld>(val);
    }
    consteval decihenry_ld operator""_dH(long double val) {
        return static_cast<decihenry_ld>(val);
    }
    consteval centihenry_ld operator""_cH(long double val) {
        return static_cast<centihenry_ld>(val);
    }
    consteval millihenry_ld operator""_mH(long double val) {
        return static_cast<millihenry_ld>(val);
    }
    consteval microhenry_ld operator""_uH(long double val) {
        return static_cast<microhenry_ld>(val);
    }
    consteval nanohenry_ld operator""_nH(long double val) {
        return static_cast<nanohenry_ld>(val);
    }
    consteval picohenry_ld operator""_pH(long double val) {
        return static_cast<picohenry_ld>(val);
    }
    consteval femtohenry_ld operator""_fH(long double val) {
        return static_cast<femtohenry_ld>(val);
    }
    consteval attohenry_ld operator""_aH(long double val) {
        return static_cast<attohenry_ld>(val);
    }
    consteval exahenry_ull operator""_EH(unsigned long long val) {
        return static_cast<exahenry_ull>(val);
    }
    consteval petahenry_ull operator""_PH(unsigned long long val) {
        return static_cast<petahenry_ull>(val);
    }
    consteval terahenry_ull operator""_TH(unsigned long long val) {
        return static_cast<terahenry_ull>(val);
    }
    consteval gigahenry_ull operator""_GH(unsigned long long val) {
        return static_cast<gigahenry_ull>(val);
    }
    consteval megahenry_ull operator""_MH(unsigned long long val) {
        return static_cast<megahenry_ull>(val);
    }
    consteval kilohenry_ull operator""_kH(unsigned long long val) {
        return static_cast<kilohenry_ull>(val);
    }
    consteval hectohenry_ull operator""_hH(unsigned long long val) {
        return static_cast<hectohenry_ull>(val);
    }
    consteval decahenry_ull operator""_daH(unsigned long long val) {
        return static_cast<decahenry_ull>(val);
    }
    consteval henry_ull operator""_H(unsigned long long val) {
        return static_cast<henry_ull>(val);
    }
    consteval decihenry_ull operator""_dH(unsigned long long val) {
        return static_cast<decihenry_ull>(val);
    }
    consteval centihenry_ull operator""_cH(unsigned long long val) {
        return static_cast<centihenry_ull>(val);
    }
    consteval millihenry_ull operator""_mH(unsigned long long val) {
        return static_cast<millihenry_ull>(val);
    }
    consteval microhenry_ull operator""_uH(unsigned long long val) {
        return static_cast<microhenry_ull>(val);
    }
    consteval nanohenry_ull operator""_nH(unsigned long long val) {
        return static_cast<nanohenry_ull>(val);
    }
    consteval picohenry_ull operator""_pH(unsigned long long val) {
        return static_cast<picohenry_ull>(val);
    }
    consteval femtohenry_ull operator""_fH(unsigned long long val) {
        return static_cast<femtohenry_ull>(val);
    }
    consteval attohenry_ull operator""_aH(unsigned long long val) {
        return static_cast<attohenry_ull>(val);
    }

} // namespace potato::units
