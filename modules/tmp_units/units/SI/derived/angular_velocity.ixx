//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Radian_Per_Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.BaseUnit;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename RatioTypeT, typename P>
    struct radian_per_second_impl : base_unit_<RatioTypeT, P> {

        using base_unit_<RatioTypeT, P>::base_unit_;
        template <typename U, typename R>
        constexpr const radian_per_second_impl<RatioTypeT, P>(const radian_per_second_impl<U, R>& other) {
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

        static constexpr auto pretty = "rad/s";

        using is_any_impl = false_;

        using mod_ratio = RatioTypeT;
        using numer_type = base_unit_<RatioTypeT, P>::value_type;
        using impl      = list_<list_<radian_l>, list_<second_l>>;
    };

    using exaradian_per_second_ld    =     radian_per_second_impl<std::exa, long double>;
    using petaradian_per_second_ld    =     radian_per_second_impl<std::peta, long double>;
    using teraradian_per_second_ld    =     radian_per_second_impl<std::tera, long double>;
    using gigaradian_per_second_ld    =     radian_per_second_impl<std::giga, long double>;
    using megaradian_per_second_ld    =     radian_per_second_impl<std::mega, long double>;
    using kiloradian_per_second_ld    =     radian_per_second_impl<std::kilo, long double>;
    using hectoradian_per_second_ld    =     radian_per_second_impl<std::hecto, long double>;
    using decaradian_per_second_ld    =     radian_per_second_impl<std::deca, long double>;
    using radian_per_second_ld    =     radian_per_second_impl<unity_ratio, long double>;
    using deciradian_per_second_ld    =     radian_per_second_impl<std::deci, long double>;
    using centiradian_per_second_ld    =     radian_per_second_impl<std::centi, long double>;
    using milliradian_per_second_ld    =     radian_per_second_impl<std::milli, long double>;
    using microradian_per_second_ld    =     radian_per_second_impl<std::micro, long double>;
    using nanoradian_per_second_ld    =     radian_per_second_impl<std::nano, long double>;
    using picoradian_per_second_ld    =     radian_per_second_impl<std::pico, long double>;
    using femtoradian_per_second_ld    =     radian_per_second_impl<std::femto, long double>;
    using attoradian_per_second_ld    =     radian_per_second_impl<std::atto, long double>;
    using exaradian_per_second_ull    =     radian_per_second_impl<std::exa, unsigned long long>;
    using petaradian_per_second_ull    =     radian_per_second_impl<std::peta, unsigned long long>;
    using teraradian_per_second_ull    =     radian_per_second_impl<std::tera, unsigned long long>;
    using gigaradian_per_second_ull    =     radian_per_second_impl<std::giga, unsigned long long>;
    using megaradian_per_second_ull    =     radian_per_second_impl<std::mega, unsigned long long>;
    using kiloradian_per_second_ull    =     radian_per_second_impl<std::kilo, unsigned long long>;
    using hectoradian_per_second_ull    =     radian_per_second_impl<std::hecto, unsigned long long>;
    using decaradian_per_second_ull    =     radian_per_second_impl<std::deca, unsigned long long>;
    using radian_per_second_ull    =     radian_per_second_impl<unity_ratio, unsigned long long>;
    using deciradian_per_second_ull    =     radian_per_second_impl<std::deci, unsigned long long>;
    using centiradian_per_second_ull    =     radian_per_second_impl<std::centi, unsigned long long>;
    using milliradian_per_second_ull    =     radian_per_second_impl<std::milli, unsigned long long>;
    using microradian_per_second_ull    =     radian_per_second_impl<std::micro, unsigned long long>;
    using nanoradian_per_second_ull    =     radian_per_second_impl<std::nano, unsigned long long>;
    using picoradian_per_second_ull    =     radian_per_second_impl<std::pico, unsigned long long>;
    using femtoradian_per_second_ull    =     radian_per_second_impl<std::femto, unsigned long long>;
    using attoradian_per_second_ull    =     radian_per_second_impl<std::atto, unsigned long long>;

    constexpr exaradian_per_second_ld operator""_Erad_per_s(long double val) {
        return static_cast<exaradian_per_second_ld>(val);
    }
    constexpr petaradian_per_second_ld operator""_Prad_per_s(long double val) {
        return static_cast<petaradian_per_second_ld>(val);
    }
    constexpr teraradian_per_second_ld operator""_Trad_per_s(long double val) {
        return static_cast<teraradian_per_second_ld>(val);
    }
    constexpr gigaradian_per_second_ld operator""_Grad_per_s(long double val) {
        return static_cast<gigaradian_per_second_ld>(val);
    }
    constexpr megaradian_per_second_ld operator""_Mrad_per_s(long double val) {
        return static_cast<megaradian_per_second_ld>(val);
    }
    constexpr kiloradian_per_second_ld operator""_krad_per_s(long double val) {
        return static_cast<kiloradian_per_second_ld>(val);
    }
    constexpr hectoradian_per_second_ld operator""_hrad_per_s(long double val) {
        return static_cast<hectoradian_per_second_ld>(val);
    }
    constexpr decaradian_per_second_ld operator""_darad_per_s(long double val) {
        return static_cast<decaradian_per_second_ld>(val);
    }
    constexpr radian_per_second_ld operator""_rad_per_s(long double val) {
        return static_cast<radian_per_second_ld>(val);
    }
    constexpr deciradian_per_second_ld operator""_drad_per_s(long double val) {
        return static_cast<deciradian_per_second_ld>(val);
    }
    constexpr centiradian_per_second_ld operator""_crad_per_s(long double val) {
        return static_cast<centiradian_per_second_ld>(val);
    }
    constexpr milliradian_per_second_ld operator""_mrad_per_s(long double val) {
        return static_cast<milliradian_per_second_ld>(val);
    }
    constexpr microradian_per_second_ld operator""_urad_per_s(long double val) {
        return static_cast<microradian_per_second_ld>(val);
    }
    constexpr nanoradian_per_second_ld operator""_nrad_per_s(long double val) {
        return static_cast<nanoradian_per_second_ld>(val);
    }
    constexpr picoradian_per_second_ld operator""_prad_per_s(long double val) {
        return static_cast<picoradian_per_second_ld>(val);
    }
    constexpr femtoradian_per_second_ld operator""_frad_per_s(long double val) {
        return static_cast<femtoradian_per_second_ld>(val);
    }
    constexpr attoradian_per_second_ld operator""_arad_per_s(long double val) {
        return static_cast<attoradian_per_second_ld>(val);
    }
    constexpr exaradian_per_second_ull operator""_Erad_per_s(unsigned long long val) {
        return static_cast<exaradian_per_second_ull>(val);
    }
    constexpr petaradian_per_second_ull operator""_Prad_per_s(unsigned long long val) {
        return static_cast<petaradian_per_second_ull>(val);
    }
    constexpr teraradian_per_second_ull operator""_Trad_per_s(unsigned long long val) {
        return static_cast<teraradian_per_second_ull>(val);
    }
    constexpr gigaradian_per_second_ull operator""_Grad_per_s(unsigned long long val) {
        return static_cast<gigaradian_per_second_ull>(val);
    }
    constexpr megaradian_per_second_ull operator""_Mrad_per_s(unsigned long long val) {
        return static_cast<megaradian_per_second_ull>(val);
    }
    constexpr kiloradian_per_second_ull operator""_krad_per_s(unsigned long long val) {
        return static_cast<kiloradian_per_second_ull>(val);
    }
    constexpr hectoradian_per_second_ull operator""_hrad_per_s(unsigned long long val) {
        return static_cast<hectoradian_per_second_ull>(val);
    }
    constexpr decaradian_per_second_ull operator""_darad_per_s(unsigned long long val) {
        return static_cast<decaradian_per_second_ull>(val);
    }
    constexpr radian_per_second_ull operator""_rad_per_s(unsigned long long val) {
        return static_cast<radian_per_second_ull>(val);
    }
    constexpr deciradian_per_second_ull operator""_drad_per_s(unsigned long long val) {
        return static_cast<deciradian_per_second_ull>(val);
    }
    constexpr centiradian_per_second_ull operator""_crad_per_s(unsigned long long val) {
        return static_cast<centiradian_per_second_ull>(val);
    }
    constexpr milliradian_per_second_ull operator""_mrad_per_s(unsigned long long val) {
        return static_cast<milliradian_per_second_ull>(val);
    }
    constexpr microradian_per_second_ull operator""_urad_per_s(unsigned long long val) {
        return static_cast<microradian_per_second_ull>(val);
    }
    constexpr nanoradian_per_second_ull operator""_nrad_per_s(unsigned long long val) {
        return static_cast<nanoradian_per_second_ull>(val);
    }
    constexpr picoradian_per_second_ull operator""_prad_per_s(unsigned long long val) {
        return static_cast<picoradian_per_second_ull>(val);
    }
    constexpr femtoradian_per_second_ull operator""_frad_per_s(unsigned long long val) {
        return static_cast<femtoradian_per_second_ull>(val);
    }
    constexpr attoradian_per_second_ull operator""_arad_per_s(unsigned long long val) {
        return static_cast<attoradian_per_second_ull>(val);
    }

} // namespace potato::units
