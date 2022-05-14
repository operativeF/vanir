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

    using henry_tag_t = tmp::list_<tmp::list_<meter_l, meter_l, gram_l>, tmp::list_<second_l, second_l, ampere_l, ampere_l>>;

    template<typename T>
    concept HenryC = std::same_as<typename T::impl, henry_tag_t>;

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
        using numer_type = DerivedValueType;
        using impl       = henry_tag_t;

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

    constexpr exahenry_ld operator""_EH(long double val) {
        return static_cast<exahenry_ld>(val);
    }
    constexpr petahenry_ld operator""_PH(long double val) {
        return static_cast<petahenry_ld>(val);
    }
    constexpr terahenry_ld operator""_TH(long double val) {
        return static_cast<terahenry_ld>(val);
    }
    constexpr gigahenry_ld operator""_GH(long double val) {
        return static_cast<gigahenry_ld>(val);
    }
    constexpr megahenry_ld operator""_MH(long double val) {
        return static_cast<megahenry_ld>(val);
    }
    constexpr kilohenry_ld operator""_kH(long double val) {
        return static_cast<kilohenry_ld>(val);
    }
    constexpr hectohenry_ld operator""_hH(long double val) {
        return static_cast<hectohenry_ld>(val);
    }
    constexpr decahenry_ld operator""_daH(long double val) {
        return static_cast<decahenry_ld>(val);
    }
    constexpr henry_ld operator""_H(long double val) {
        return static_cast<henry_ld>(val);
    }
    constexpr decihenry_ld operator""_dH(long double val) {
        return static_cast<decihenry_ld>(val);
    }
    constexpr centihenry_ld operator""_cH(long double val) {
        return static_cast<centihenry_ld>(val);
    }
    constexpr millihenry_ld operator""_mH(long double val) {
        return static_cast<millihenry_ld>(val);
    }
    constexpr microhenry_ld operator""_uH(long double val) {
        return static_cast<microhenry_ld>(val);
    }
    constexpr nanohenry_ld operator""_nH(long double val) {
        return static_cast<nanohenry_ld>(val);
    }
    constexpr picohenry_ld operator""_pH(long double val) {
        return static_cast<picohenry_ld>(val);
    }
    constexpr femtohenry_ld operator""_fH(long double val) {
        return static_cast<femtohenry_ld>(val);
    }
    constexpr attohenry_ld operator""_aH(long double val) {
        return static_cast<attohenry_ld>(val);
    }
    constexpr exahenry_ull operator""_EH(unsigned long long val) {
        return static_cast<exahenry_ull>(val);
    }
    constexpr petahenry_ull operator""_PH(unsigned long long val) {
        return static_cast<petahenry_ull>(val);
    }
    constexpr terahenry_ull operator""_TH(unsigned long long val) {
        return static_cast<terahenry_ull>(val);
    }
    constexpr gigahenry_ull operator""_GH(unsigned long long val) {
        return static_cast<gigahenry_ull>(val);
    }
    constexpr megahenry_ull operator""_MH(unsigned long long val) {
        return static_cast<megahenry_ull>(val);
    }
    constexpr kilohenry_ull operator""_kH(unsigned long long val) {
        return static_cast<kilohenry_ull>(val);
    }
    constexpr hectohenry_ull operator""_hH(unsigned long long val) {
        return static_cast<hectohenry_ull>(val);
    }
    constexpr decahenry_ull operator""_daH(unsigned long long val) {
        return static_cast<decahenry_ull>(val);
    }
    constexpr henry_ull operator""_H(unsigned long long val) {
        return static_cast<henry_ull>(val);
    }
    constexpr decihenry_ull operator""_dH(unsigned long long val) {
        return static_cast<decihenry_ull>(val);
    }
    constexpr centihenry_ull operator""_cH(unsigned long long val) {
        return static_cast<centihenry_ull>(val);
    }
    constexpr millihenry_ull operator""_mH(unsigned long long val) {
        return static_cast<millihenry_ull>(val);
    }
    constexpr microhenry_ull operator""_uH(unsigned long long val) {
        return static_cast<microhenry_ull>(val);
    }
    constexpr nanohenry_ull operator""_nH(unsigned long long val) {
        return static_cast<nanohenry_ull>(val);
    }
    constexpr picohenry_ull operator""_pH(unsigned long long val) {
        return static_cast<picohenry_ull>(val);
    }
    constexpr femtohenry_ull operator""_fH(unsigned long long val) {
        return static_cast<femtohenry_ull>(val);
    }
    constexpr attohenry_ull operator""_aH(unsigned long long val) {
        return static_cast<attohenry_ull>(val);
    }

} // namespace potato::units
