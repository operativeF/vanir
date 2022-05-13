//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Newton_Per_Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.BaseUnit;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename RatioTypeT, typename P>
    struct newton_per_second_impl : base_unit_<RatioTypeT, P> {

        using base_unit_<RatioTypeT, P>::base_unit_;
        template <typename U, typename R>
        constexpr const newton_per_second_impl<RatioTypeT, P>(const newton_per_second_impl<U, R>& other) {
            using scale_greater = call_<if_<lift_<std::ratio_greater>,
                always_<std::ratio_divide<U, RatioTypeT>>,
                always_<unity_ratio>>,
                RatioTypeT, U>;
            using scale_lesser = call_<if_<lift_<std::ratio_less>,
                always_<std::ratio_divide<RatioTypeT, U>>,
                always_<unity_ratio>>,
                RatioTypeT, U>;
            this->value = (other.value * scale_greater::num * scale_lesser::den) / (scale_greater::den * scale_lesser::num);
        }

        static constexpr auto pretty = "N/s";

        using is_any_impl = false_;

        using mod_ratio = RatioTypeT;
        using numer_type = base_unit_<RatioTypeT, P>::value_type;
        using impl      = list_<list_<meter_l, gram_l>, list_<second_l, second_l, second_l>>;
    };

    using exanewton_per_second_ld    =     newton_per_second_impl<std::exa, long double>;
    using petanewton_per_second_ld    =     newton_per_second_impl<std::peta, long double>;
    using teranewton_per_second_ld    =     newton_per_second_impl<std::tera, long double>;
    using giganewton_per_second_ld    =     newton_per_second_impl<std::giga, long double>;
    using meganewton_per_second_ld    =     newton_per_second_impl<std::mega, long double>;
    using kilonewton_per_second_ld    =     newton_per_second_impl<std::kilo, long double>;
    using hectonewton_per_second_ld    =     newton_per_second_impl<std::hecto, long double>;
    using decanewton_per_second_ld    =     newton_per_second_impl<std::deca, long double>;
    using newton_per_second_ld    =     newton_per_second_impl<unity_ratio, long double>;
    using decinewton_per_second_ld    =     newton_per_second_impl<std::deci, long double>;
    using centinewton_per_second_ld    =     newton_per_second_impl<std::centi, long double>;
    using millinewton_per_second_ld    =     newton_per_second_impl<std::milli, long double>;
    using micronewton_per_second_ld    =     newton_per_second_impl<std::micro, long double>;
    using nanonewton_per_second_ld    =     newton_per_second_impl<std::nano, long double>;
    using piconewton_per_second_ld    =     newton_per_second_impl<std::pico, long double>;
    using femtonewton_per_second_ld    =     newton_per_second_impl<std::femto, long double>;
    using attonewton_per_second_ld    =     newton_per_second_impl<std::atto, long double>;
    using exanewton_per_second_ull    =     newton_per_second_impl<std::exa, unsigned long long>;
    using petanewton_per_second_ull    =     newton_per_second_impl<std::peta, unsigned long long>;
    using teranewton_per_second_ull    =     newton_per_second_impl<std::tera, unsigned long long>;
    using giganewton_per_second_ull    =     newton_per_second_impl<std::giga, unsigned long long>;
    using meganewton_per_second_ull    =     newton_per_second_impl<std::mega, unsigned long long>;
    using kilonewton_per_second_ull    =     newton_per_second_impl<std::kilo, unsigned long long>;
    using hectonewton_per_second_ull    =     newton_per_second_impl<std::hecto, unsigned long long>;
    using decanewton_per_second_ull    =     newton_per_second_impl<std::deca, unsigned long long>;
    using newton_per_second_ull    =     newton_per_second_impl<unity_ratio, unsigned long long>;
    using decinewton_per_second_ull    =     newton_per_second_impl<std::deci, unsigned long long>;
    using centinewton_per_second_ull    =     newton_per_second_impl<std::centi, unsigned long long>;
    using millinewton_per_second_ull    =     newton_per_second_impl<std::milli, unsigned long long>;
    using micronewton_per_second_ull    =     newton_per_second_impl<std::micro, unsigned long long>;
    using nanonewton_per_second_ull    =     newton_per_second_impl<std::nano, unsigned long long>;
    using piconewton_per_second_ull    =     newton_per_second_impl<std::pico, unsigned long long>;
    using femtonewton_per_second_ull    =     newton_per_second_impl<std::femto, unsigned long long>;
    using attonewton_per_second_ull    =     newton_per_second_impl<std::atto, unsigned long long>;

    constexpr exanewton_per_second_ld operator""_EN_per_s(long double val) {
        return static_cast<exanewton_per_second_ld>(val);
    }
    constexpr petanewton_per_second_ld operator""_PN_per_s(long double val) {
        return static_cast<petanewton_per_second_ld>(val);
    }
    constexpr teranewton_per_second_ld operator""_TN_per_s(long double val) {
        return static_cast<teranewton_per_second_ld>(val);
    }
    constexpr giganewton_per_second_ld operator""_GN_per_s(long double val) {
        return static_cast<giganewton_per_second_ld>(val);
    }
    constexpr meganewton_per_second_ld operator""_MN_per_s(long double val) {
        return static_cast<meganewton_per_second_ld>(val);
    }
    constexpr kilonewton_per_second_ld operator""_kN_per_s(long double val) {
        return static_cast<kilonewton_per_second_ld>(val);
    }
    constexpr hectonewton_per_second_ld operator""_hN_per_s(long double val) {
        return static_cast<hectonewton_per_second_ld>(val);
    }
    constexpr decanewton_per_second_ld operator""_daN_per_s(long double val) {
        return static_cast<decanewton_per_second_ld>(val);
    }
    constexpr newton_per_second_ld operator""_N_per_s(long double val) {
        return static_cast<newton_per_second_ld>(val);
    }
    constexpr decinewton_per_second_ld operator""_dN_per_s(long double val) {
        return static_cast<decinewton_per_second_ld>(val);
    }
    constexpr centinewton_per_second_ld operator""_cN_per_s(long double val) {
        return static_cast<centinewton_per_second_ld>(val);
    }
    constexpr millinewton_per_second_ld operator""_mN_per_s(long double val) {
        return static_cast<millinewton_per_second_ld>(val);
    }
    constexpr micronewton_per_second_ld operator""_uN_per_s(long double val) {
        return static_cast<micronewton_per_second_ld>(val);
    }
    constexpr nanonewton_per_second_ld operator""_nN_per_s(long double val) {
        return static_cast<nanonewton_per_second_ld>(val);
    }
    constexpr piconewton_per_second_ld operator""_pN_per_s(long double val) {
        return static_cast<piconewton_per_second_ld>(val);
    }
    constexpr femtonewton_per_second_ld operator""_fN_per_s(long double val) {
        return static_cast<femtonewton_per_second_ld>(val);
    }
    constexpr attonewton_per_second_ld operator""_aN_per_s(long double val) {
        return static_cast<attonewton_per_second_ld>(val);
    }
    constexpr exanewton_per_second_ull operator""_EN_per_s(unsigned long long val) {
        return static_cast<exanewton_per_second_ull>(val);
    }
    constexpr petanewton_per_second_ull operator""_PN_per_s(unsigned long long val) {
        return static_cast<petanewton_per_second_ull>(val);
    }
    constexpr teranewton_per_second_ull operator""_TN_per_s(unsigned long long val) {
        return static_cast<teranewton_per_second_ull>(val);
    }
    constexpr giganewton_per_second_ull operator""_GN_per_s(unsigned long long val) {
        return static_cast<giganewton_per_second_ull>(val);
    }
    constexpr meganewton_per_second_ull operator""_MN_per_s(unsigned long long val) {
        return static_cast<meganewton_per_second_ull>(val);
    }
    constexpr kilonewton_per_second_ull operator""_kN_per_s(unsigned long long val) {
        return static_cast<kilonewton_per_second_ull>(val);
    }
    constexpr hectonewton_per_second_ull operator""_hN_per_s(unsigned long long val) {
        return static_cast<hectonewton_per_second_ull>(val);
    }
    constexpr decanewton_per_second_ull operator""_daN_per_s(unsigned long long val) {
        return static_cast<decanewton_per_second_ull>(val);
    }
    constexpr newton_per_second_ull operator""_N_per_s(unsigned long long val) {
        return static_cast<newton_per_second_ull>(val);
    }
    constexpr decinewton_per_second_ull operator""_dN_per_s(unsigned long long val) {
        return static_cast<decinewton_per_second_ull>(val);
    }
    constexpr centinewton_per_second_ull operator""_cN_per_s(unsigned long long val) {
        return static_cast<centinewton_per_second_ull>(val);
    }
    constexpr millinewton_per_second_ull operator""_mN_per_s(unsigned long long val) {
        return static_cast<millinewton_per_second_ull>(val);
    }
    constexpr micronewton_per_second_ull operator""_uN_per_s(unsigned long long val) {
        return static_cast<micronewton_per_second_ull>(val);
    }
    constexpr nanonewton_per_second_ull operator""_nN_per_s(unsigned long long val) {
        return static_cast<nanonewton_per_second_ull>(val);
    }
    constexpr piconewton_per_second_ull operator""_pN_per_s(unsigned long long val) {
        return static_cast<piconewton_per_second_ull>(val);
    }
    constexpr femtonewton_per_second_ull operator""_fN_per_s(unsigned long long val) {
        return static_cast<femtonewton_per_second_ull>(val);
    }
    constexpr attonewton_per_second_ull operator""_aN_per_s(unsigned long long val) {
        return static_cast<attonewton_per_second_ull>(val);
    }

} // namespace potato::units
