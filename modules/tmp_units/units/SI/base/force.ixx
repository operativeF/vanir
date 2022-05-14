//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Newton;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using newton_tag_t = tmp::list_<tmp::list_<gram_l, meter_l>, tmp::list_<second_l, second_l>>;

    template<typename T>
    concept NewtonC = std::same_as<typename T::impl, newton_tag_t>;

    template <typename RatioTypeT, typename P>
    struct newton_impl {

        static constexpr auto pretty = "F";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = newton_tag_t;

        constexpr newton_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exanewton_ld    =     newton_impl<std::exa, long double>;
    using petanewton_ld    =     newton_impl<std::peta, long double>;
    using teranewton_ld    =     newton_impl<std::tera, long double>;
    using giganewton_ld    =     newton_impl<std::giga, long double>;
    using meganewton_ld    =     newton_impl<std::mega, long double>;
    using kilonewton_ld    =     newton_impl<std::kilo, long double>;
    using hectonewton_ld    =     newton_impl<std::hecto, long double>;
    using decanewton_ld    =     newton_impl<std::deca, long double>;
    using newton_ld    =     newton_impl<unity_ratio, long double>;
    using decinewton_ld    =     newton_impl<std::deci, long double>;
    using centinewton_ld    =     newton_impl<std::centi, long double>;
    using millinewton_ld    =     newton_impl<std::milli, long double>;
    using micronewton_ld    =     newton_impl<std::micro, long double>;
    using nanonewton_ld    =     newton_impl<std::nano, long double>;
    using piconewton_ld    =     newton_impl<std::pico, long double>;
    using femtonewton_ld    =     newton_impl<std::femto, long double>;
    using attonewton_ld    =     newton_impl<std::atto, long double>;
    using exanewton_ull    =     newton_impl<std::exa, unsigned long long>;
    using petanewton_ull    =     newton_impl<std::peta, unsigned long long>;
    using teranewton_ull    =     newton_impl<std::tera, unsigned long long>;
    using giganewton_ull    =     newton_impl<std::giga, unsigned long long>;
    using meganewton_ull    =     newton_impl<std::mega, unsigned long long>;
    using kilonewton_ull    =     newton_impl<std::kilo, unsigned long long>;
    using hectonewton_ull    =     newton_impl<std::hecto, unsigned long long>;
    using decanewton_ull    =     newton_impl<std::deca, unsigned long long>;
    using newton_ull    =     newton_impl<unity_ratio, unsigned long long>;
    using decinewton_ull    =     newton_impl<std::deci, unsigned long long>;
    using centinewton_ull    =     newton_impl<std::centi, unsigned long long>;
    using millinewton_ull    =     newton_impl<std::milli, unsigned long long>;
    using micronewton_ull    =     newton_impl<std::micro, unsigned long long>;
    using nanonewton_ull    =     newton_impl<std::nano, unsigned long long>;
    using piconewton_ull    =     newton_impl<std::pico, unsigned long long>;
    using femtonewton_ull    =     newton_impl<std::femto, unsigned long long>;
    using attonewton_ull    =     newton_impl<std::atto, unsigned long long>;

    constexpr exanewton_ld operator""_EN(long double val) {
        return static_cast<exanewton_ld>(val);
    }
    constexpr petanewton_ld operator""_PN(long double val) {
        return static_cast<petanewton_ld>(val);
    }
    constexpr teranewton_ld operator""_TN(long double val) {
        return static_cast<teranewton_ld>(val);
    }
    constexpr giganewton_ld operator""_GN(long double val) {
        return static_cast<giganewton_ld>(val);
    }
    constexpr meganewton_ld operator""_MN(long double val) {
        return static_cast<meganewton_ld>(val);
    }
    constexpr kilonewton_ld operator""_kN(long double val) {
        return static_cast<kilonewton_ld>(val);
    }
    constexpr hectonewton_ld operator""_hN(long double val) {
        return static_cast<hectonewton_ld>(val);
    }
    constexpr decanewton_ld operator""_daN(long double val) {
        return static_cast<decanewton_ld>(val);
    }
    constexpr newton_ld operator""_N(long double val) {
        return static_cast<newton_ld>(val);
    }
    constexpr decinewton_ld operator""_dN(long double val) {
        return static_cast<decinewton_ld>(val);
    }
    constexpr centinewton_ld operator""_cN(long double val) {
        return static_cast<centinewton_ld>(val);
    }
    constexpr millinewton_ld operator""_mN(long double val) {
        return static_cast<millinewton_ld>(val);
    }
    constexpr micronewton_ld operator""_uN(long double val) {
        return static_cast<micronewton_ld>(val);
    }
    constexpr nanonewton_ld operator""_nN(long double val) {
        return static_cast<nanonewton_ld>(val);
    }
    constexpr piconewton_ld operator""_pN(long double val) {
        return static_cast<piconewton_ld>(val);
    }
    constexpr femtonewton_ld operator""_fN(long double val) {
        return static_cast<femtonewton_ld>(val);
    }
    constexpr attonewton_ld operator""_aN(long double val) {
        return static_cast<attonewton_ld>(val);
    }
    constexpr exanewton_ull operator""_EN(unsigned long long val) {
        return static_cast<exanewton_ull>(val);
    }
    constexpr petanewton_ull operator""_PN(unsigned long long val) {
        return static_cast<petanewton_ull>(val);
    }
    constexpr teranewton_ull operator""_TN(unsigned long long val) {
        return static_cast<teranewton_ull>(val);
    }
    constexpr giganewton_ull operator""_GN(unsigned long long val) {
        return static_cast<giganewton_ull>(val);
    }
    constexpr meganewton_ull operator""_MN(unsigned long long val) {
        return static_cast<meganewton_ull>(val);
    }
    constexpr kilonewton_ull operator""_kN(unsigned long long val) {
        return static_cast<kilonewton_ull>(val);
    }
    constexpr hectonewton_ull operator""_hN(unsigned long long val) {
        return static_cast<hectonewton_ull>(val);
    }
    constexpr decanewton_ull operator""_daN(unsigned long long val) {
        return static_cast<decanewton_ull>(val);
    }
    constexpr newton_ull operator""_N(unsigned long long val) {
        return static_cast<newton_ull>(val);
    }
    constexpr decinewton_ull operator""_dN(unsigned long long val) {
        return static_cast<decinewton_ull>(val);
    }
    constexpr centinewton_ull operator""_cN(unsigned long long val) {
        return static_cast<centinewton_ull>(val);
    }
    constexpr millinewton_ull operator""_mN(unsigned long long val) {
        return static_cast<millinewton_ull>(val);
    }
    constexpr micronewton_ull operator""_uN(unsigned long long val) {
        return static_cast<micronewton_ull>(val);
    }
    constexpr nanonewton_ull operator""_nN(unsigned long long val) {
        return static_cast<nanonewton_ull>(val);
    }
    constexpr piconewton_ull operator""_pN(unsigned long long val) {
        return static_cast<piconewton_ull>(val);
    }
    constexpr femtonewton_ull operator""_fN(unsigned long long val) {
        return static_cast<femtonewton_ull>(val);
    }
    constexpr attonewton_ull operator""_aN(unsigned long long val) {
        return static_cast<attonewton_ull>(val);
    }

} // namespace potato::units
