//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Newton_Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using newton_second_tag_t = tmp::list_<tmp::list_<meter_l, gram_l>, tmp::list_<second_l>>;

    template<typename T>
    concept Newton_SecondC = std::same_as<typename T::impl, newton_second_tag_t>;

    template <typename RatioTypeT, typename P>
    struct newton_second_impl {

        static constexpr auto pretty = "N·s";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = newton_second_tag_t;

        constexpr newton_second_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exanewton_second_ld    =     newton_second_impl<std::exa, long double>;
    using petanewton_second_ld    =     newton_second_impl<std::peta, long double>;
    using teranewton_second_ld    =     newton_second_impl<std::tera, long double>;
    using giganewton_second_ld    =     newton_second_impl<std::giga, long double>;
    using meganewton_second_ld    =     newton_second_impl<std::mega, long double>;
    using kilonewton_second_ld    =     newton_second_impl<std::kilo, long double>;
    using hectonewton_second_ld    =     newton_second_impl<std::hecto, long double>;
    using decanewton_second_ld    =     newton_second_impl<std::deca, long double>;
    using newton_second_ld    =     newton_second_impl<unity_ratio, long double>;
    using decinewton_second_ld    =     newton_second_impl<std::deci, long double>;
    using centinewton_second_ld    =     newton_second_impl<std::centi, long double>;
    using millinewton_second_ld    =     newton_second_impl<std::milli, long double>;
    using micronewton_second_ld    =     newton_second_impl<std::micro, long double>;
    using nanonewton_second_ld    =     newton_second_impl<std::nano, long double>;
    using piconewton_second_ld    =     newton_second_impl<std::pico, long double>;
    using femtonewton_second_ld    =     newton_second_impl<std::femto, long double>;
    using attonewton_second_ld    =     newton_second_impl<std::atto, long double>;
    using exanewton_second_ull    =     newton_second_impl<std::exa, unsigned long long>;
    using petanewton_second_ull    =     newton_second_impl<std::peta, unsigned long long>;
    using teranewton_second_ull    =     newton_second_impl<std::tera, unsigned long long>;
    using giganewton_second_ull    =     newton_second_impl<std::giga, unsigned long long>;
    using meganewton_second_ull    =     newton_second_impl<std::mega, unsigned long long>;
    using kilonewton_second_ull    =     newton_second_impl<std::kilo, unsigned long long>;
    using hectonewton_second_ull    =     newton_second_impl<std::hecto, unsigned long long>;
    using decanewton_second_ull    =     newton_second_impl<std::deca, unsigned long long>;
    using newton_second_ull    =     newton_second_impl<unity_ratio, unsigned long long>;
    using decinewton_second_ull    =     newton_second_impl<std::deci, unsigned long long>;
    using centinewton_second_ull    =     newton_second_impl<std::centi, unsigned long long>;
    using millinewton_second_ull    =     newton_second_impl<std::milli, unsigned long long>;
    using micronewton_second_ull    =     newton_second_impl<std::micro, unsigned long long>;
    using nanonewton_second_ull    =     newton_second_impl<std::nano, unsigned long long>;
    using piconewton_second_ull    =     newton_second_impl<std::pico, unsigned long long>;
    using femtonewton_second_ull    =     newton_second_impl<std::femto, unsigned long long>;
    using attonewton_second_ull    =     newton_second_impl<std::atto, unsigned long long>;

    constexpr exanewton_second_ld operator""_EN_s(long double val) {
        return static_cast<exanewton_second_ld>(val);
    }
    constexpr petanewton_second_ld operator""_PN_s(long double val) {
        return static_cast<petanewton_second_ld>(val);
    }
    constexpr teranewton_second_ld operator""_TN_s(long double val) {
        return static_cast<teranewton_second_ld>(val);
    }
    constexpr giganewton_second_ld operator""_GN_s(long double val) {
        return static_cast<giganewton_second_ld>(val);
    }
    constexpr meganewton_second_ld operator""_MN_s(long double val) {
        return static_cast<meganewton_second_ld>(val);
    }
    constexpr kilonewton_second_ld operator""_kN_s(long double val) {
        return static_cast<kilonewton_second_ld>(val);
    }
    constexpr hectonewton_second_ld operator""_hN_s(long double val) {
        return static_cast<hectonewton_second_ld>(val);
    }
    constexpr decanewton_second_ld operator""_daN_s(long double val) {
        return static_cast<decanewton_second_ld>(val);
    }
    constexpr newton_second_ld operator""_N_s(long double val) {
        return static_cast<newton_second_ld>(val);
    }
    constexpr decinewton_second_ld operator""_dN_s(long double val) {
        return static_cast<decinewton_second_ld>(val);
    }
    constexpr centinewton_second_ld operator""_cN_s(long double val) {
        return static_cast<centinewton_second_ld>(val);
    }
    constexpr millinewton_second_ld operator""_mN_s(long double val) {
        return static_cast<millinewton_second_ld>(val);
    }
    constexpr micronewton_second_ld operator""_uN_s(long double val) {
        return static_cast<micronewton_second_ld>(val);
    }
    constexpr nanonewton_second_ld operator""_nN_s(long double val) {
        return static_cast<nanonewton_second_ld>(val);
    }
    constexpr piconewton_second_ld operator""_pN_s(long double val) {
        return static_cast<piconewton_second_ld>(val);
    }
    constexpr femtonewton_second_ld operator""_fN_s(long double val) {
        return static_cast<femtonewton_second_ld>(val);
    }
    constexpr attonewton_second_ld operator""_aN_s(long double val) {
        return static_cast<attonewton_second_ld>(val);
    }
    constexpr exanewton_second_ull operator""_EN_s(unsigned long long val) {
        return static_cast<exanewton_second_ull>(val);
    }
    constexpr petanewton_second_ull operator""_PN_s(unsigned long long val) {
        return static_cast<petanewton_second_ull>(val);
    }
    constexpr teranewton_second_ull operator""_TN_s(unsigned long long val) {
        return static_cast<teranewton_second_ull>(val);
    }
    constexpr giganewton_second_ull operator""_GN_s(unsigned long long val) {
        return static_cast<giganewton_second_ull>(val);
    }
    constexpr meganewton_second_ull operator""_MN_s(unsigned long long val) {
        return static_cast<meganewton_second_ull>(val);
    }
    constexpr kilonewton_second_ull operator""_kN_s(unsigned long long val) {
        return static_cast<kilonewton_second_ull>(val);
    }
    constexpr hectonewton_second_ull operator""_hN_s(unsigned long long val) {
        return static_cast<hectonewton_second_ull>(val);
    }
    constexpr decanewton_second_ull operator""_daN_s(unsigned long long val) {
        return static_cast<decanewton_second_ull>(val);
    }
    constexpr newton_second_ull operator""_N_s(unsigned long long val) {
        return static_cast<newton_second_ull>(val);
    }
    constexpr decinewton_second_ull operator""_dN_s(unsigned long long val) {
        return static_cast<decinewton_second_ull>(val);
    }
    constexpr centinewton_second_ull operator""_cN_s(unsigned long long val) {
        return static_cast<centinewton_second_ull>(val);
    }
    constexpr millinewton_second_ull operator""_mN_s(unsigned long long val) {
        return static_cast<millinewton_second_ull>(val);
    }
    constexpr micronewton_second_ull operator""_uN_s(unsigned long long val) {
        return static_cast<micronewton_second_ull>(val);
    }
    constexpr nanonewton_second_ull operator""_nN_s(unsigned long long val) {
        return static_cast<nanonewton_second_ull>(val);
    }
    constexpr piconewton_second_ull operator""_pN_s(unsigned long long val) {
        return static_cast<piconewton_second_ull>(val);
    }
    constexpr femtonewton_second_ull operator""_fN_s(unsigned long long val) {
        return static_cast<femtonewton_second_ull>(val);
    }
    constexpr attonewton_second_ull operator""_aN_s(unsigned long long val) {
        return static_cast<attonewton_second_ull>(val);
    }

} // namespace potato::units
