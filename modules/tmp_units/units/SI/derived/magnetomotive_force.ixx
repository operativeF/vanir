//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Ampere_Radian;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.BaseUnit;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename RatioTypeT, typename P>
    struct ampere_radian_impl : base_unit_<RatioTypeT, P> {

        using base_unit_<RatioTypeT, P>::base_unit_;
        template <typename U, typename R>
        constexpr const ampere_radian_impl<RatioTypeT, P>(const ampere_radian_impl<U, R>& other) {
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

        static constexpr auto pretty = "A·rad";

        using is_any_impl = false_;

        using mod_ratio = RatioTypeT;
        using numer_type = base_unit_<RatioTypeT, P>::value_type;
        using impl      = list_<list_<ampere_l>, list_<radian_l>>;
    };

    using exaampere_radian_ld    =     ampere_radian_impl<std::exa, long double>;
    using petaampere_radian_ld    =     ampere_radian_impl<std::peta, long double>;
    using teraampere_radian_ld    =     ampere_radian_impl<std::tera, long double>;
    using gigaampere_radian_ld    =     ampere_radian_impl<std::giga, long double>;
    using megaampere_radian_ld    =     ampere_radian_impl<std::mega, long double>;
    using kiloampere_radian_ld    =     ampere_radian_impl<std::kilo, long double>;
    using hectoampere_radian_ld    =     ampere_radian_impl<std::hecto, long double>;
    using decaampere_radian_ld    =     ampere_radian_impl<std::deca, long double>;
    using ampere_radian_ld    =     ampere_radian_impl<unity_ratio, long double>;
    using deciampere_radian_ld    =     ampere_radian_impl<std::deci, long double>;
    using centiampere_radian_ld    =     ampere_radian_impl<std::centi, long double>;
    using milliampere_radian_ld    =     ampere_radian_impl<std::milli, long double>;
    using microampere_radian_ld    =     ampere_radian_impl<std::micro, long double>;
    using nanoampere_radian_ld    =     ampere_radian_impl<std::nano, long double>;
    using picoampere_radian_ld    =     ampere_radian_impl<std::pico, long double>;
    using femtoampere_radian_ld    =     ampere_radian_impl<std::femto, long double>;
    using attoampere_radian_ld    =     ampere_radian_impl<std::atto, long double>;
    using exaampere_radian_ull    =     ampere_radian_impl<std::exa, unsigned long long>;
    using petaampere_radian_ull    =     ampere_radian_impl<std::peta, unsigned long long>;
    using teraampere_radian_ull    =     ampere_radian_impl<std::tera, unsigned long long>;
    using gigaampere_radian_ull    =     ampere_radian_impl<std::giga, unsigned long long>;
    using megaampere_radian_ull    =     ampere_radian_impl<std::mega, unsigned long long>;
    using kiloampere_radian_ull    =     ampere_radian_impl<std::kilo, unsigned long long>;
    using hectoampere_radian_ull    =     ampere_radian_impl<std::hecto, unsigned long long>;
    using decaampere_radian_ull    =     ampere_radian_impl<std::deca, unsigned long long>;
    using ampere_radian_ull    =     ampere_radian_impl<unity_ratio, unsigned long long>;
    using deciampere_radian_ull    =     ampere_radian_impl<std::deci, unsigned long long>;
    using centiampere_radian_ull    =     ampere_radian_impl<std::centi, unsigned long long>;
    using milliampere_radian_ull    =     ampere_radian_impl<std::milli, unsigned long long>;
    using microampere_radian_ull    =     ampere_radian_impl<std::micro, unsigned long long>;
    using nanoampere_radian_ull    =     ampere_radian_impl<std::nano, unsigned long long>;
    using picoampere_radian_ull    =     ampere_radian_impl<std::pico, unsigned long long>;
    using femtoampere_radian_ull    =     ampere_radian_impl<std::femto, unsigned long long>;
    using attoampere_radian_ull    =     ampere_radian_impl<std::atto, unsigned long long>;

    constexpr exaampere_radian_ld operator""_EA_rad(long double val) {
        return static_cast<exaampere_radian_ld>(val);
    }
    constexpr petaampere_radian_ld operator""_PA_rad(long double val) {
        return static_cast<petaampere_radian_ld>(val);
    }
    constexpr teraampere_radian_ld operator""_TA_rad(long double val) {
        return static_cast<teraampere_radian_ld>(val);
    }
    constexpr gigaampere_radian_ld operator""_GA_rad(long double val) {
        return static_cast<gigaampere_radian_ld>(val);
    }
    constexpr megaampere_radian_ld operator""_MA_rad(long double val) {
        return static_cast<megaampere_radian_ld>(val);
    }
    constexpr kiloampere_radian_ld operator""_kA_rad(long double val) {
        return static_cast<kiloampere_radian_ld>(val);
    }
    constexpr hectoampere_radian_ld operator""_hA_rad(long double val) {
        return static_cast<hectoampere_radian_ld>(val);
    }
    constexpr decaampere_radian_ld operator""_daA_rad(long double val) {
        return static_cast<decaampere_radian_ld>(val);
    }
    constexpr ampere_radian_ld operator""_A_rad(long double val) {
        return static_cast<ampere_radian_ld>(val);
    }
    constexpr deciampere_radian_ld operator""_dA_rad(long double val) {
        return static_cast<deciampere_radian_ld>(val);
    }
    constexpr centiampere_radian_ld operator""_cA_rad(long double val) {
        return static_cast<centiampere_radian_ld>(val);
    }
    constexpr milliampere_radian_ld operator""_mA_rad(long double val) {
        return static_cast<milliampere_radian_ld>(val);
    }
    constexpr microampere_radian_ld operator""_uA_rad(long double val) {
        return static_cast<microampere_radian_ld>(val);
    }
    constexpr nanoampere_radian_ld operator""_nA_rad(long double val) {
        return static_cast<nanoampere_radian_ld>(val);
    }
    constexpr picoampere_radian_ld operator""_pA_rad(long double val) {
        return static_cast<picoampere_radian_ld>(val);
    }
    constexpr femtoampere_radian_ld operator""_fA_rad(long double val) {
        return static_cast<femtoampere_radian_ld>(val);
    }
    constexpr attoampere_radian_ld operator""_aA_rad(long double val) {
        return static_cast<attoampere_radian_ld>(val);
    }
    constexpr exaampere_radian_ull operator""_EA_rad(unsigned long long val) {
        return static_cast<exaampere_radian_ull>(val);
    }
    constexpr petaampere_radian_ull operator""_PA_rad(unsigned long long val) {
        return static_cast<petaampere_radian_ull>(val);
    }
    constexpr teraampere_radian_ull operator""_TA_rad(unsigned long long val) {
        return static_cast<teraampere_radian_ull>(val);
    }
    constexpr gigaampere_radian_ull operator""_GA_rad(unsigned long long val) {
        return static_cast<gigaampere_radian_ull>(val);
    }
    constexpr megaampere_radian_ull operator""_MA_rad(unsigned long long val) {
        return static_cast<megaampere_radian_ull>(val);
    }
    constexpr kiloampere_radian_ull operator""_kA_rad(unsigned long long val) {
        return static_cast<kiloampere_radian_ull>(val);
    }
    constexpr hectoampere_radian_ull operator""_hA_rad(unsigned long long val) {
        return static_cast<hectoampere_radian_ull>(val);
    }
    constexpr decaampere_radian_ull operator""_daA_rad(unsigned long long val) {
        return static_cast<decaampere_radian_ull>(val);
    }
    constexpr ampere_radian_ull operator""_A_rad(unsigned long long val) {
        return static_cast<ampere_radian_ull>(val);
    }
    constexpr deciampere_radian_ull operator""_dA_rad(unsigned long long val) {
        return static_cast<deciampere_radian_ull>(val);
    }
    constexpr centiampere_radian_ull operator""_cA_rad(unsigned long long val) {
        return static_cast<centiampere_radian_ull>(val);
    }
    constexpr milliampere_radian_ull operator""_mA_rad(unsigned long long val) {
        return static_cast<milliampere_radian_ull>(val);
    }
    constexpr microampere_radian_ull operator""_uA_rad(unsigned long long val) {
        return static_cast<microampere_radian_ull>(val);
    }
    constexpr nanoampere_radian_ull operator""_nA_rad(unsigned long long val) {
        return static_cast<nanoampere_radian_ull>(val);
    }
    constexpr picoampere_radian_ull operator""_pA_rad(unsigned long long val) {
        return static_cast<picoampere_radian_ull>(val);
    }
    constexpr femtoampere_radian_ull operator""_fA_rad(unsigned long long val) {
        return static_cast<femtoampere_radian_ull>(val);
    }
    constexpr attoampere_radian_ull operator""_aA_rad(unsigned long long val) {
        return static_cast<attoampere_radian_ull>(val);
    }

} // namespace potato::units
