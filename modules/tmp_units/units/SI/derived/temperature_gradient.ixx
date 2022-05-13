//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Kelvin_Per_Watt;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.BaseUnit;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename RatioTypeT, typename P>
    struct kelvin_per_watt_impl : base_unit_<RatioTypeT, P> {

        using base_unit_<RatioTypeT, P>::base_unit_;
        template <typename U, typename R>
        constexpr const kelvin_per_watt_impl<RatioTypeT, P>(const kelvin_per_watt_impl<U, R>& other) {
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

        static constexpr auto pretty = "K/W";

        using is_any_impl = false_;

        using mod_ratio = RatioTypeT;
        using numer_type = base_unit_<RatioTypeT, P>::value_type;
        using impl      = list_<list_<second_l, second_l, second_l, kelvin_l>, list_<meter_l, meter_l, gram_l>>;
    };

    using exakelvin_per_watt_ld    =     kelvin_per_watt_impl<std::exa, long double>;
    using petakelvin_per_watt_ld    =     kelvin_per_watt_impl<std::peta, long double>;
    using terakelvin_per_watt_ld    =     kelvin_per_watt_impl<std::tera, long double>;
    using gigakelvin_per_watt_ld    =     kelvin_per_watt_impl<std::giga, long double>;
    using megakelvin_per_watt_ld    =     kelvin_per_watt_impl<std::mega, long double>;
    using kilokelvin_per_watt_ld    =     kelvin_per_watt_impl<std::kilo, long double>;
    using hectokelvin_per_watt_ld    =     kelvin_per_watt_impl<std::hecto, long double>;
    using decakelvin_per_watt_ld    =     kelvin_per_watt_impl<std::deca, long double>;
    using kelvin_per_watt_ld    =     kelvin_per_watt_impl<unity_ratio, long double>;
    using decikelvin_per_watt_ld    =     kelvin_per_watt_impl<std::deci, long double>;
    using centikelvin_per_watt_ld    =     kelvin_per_watt_impl<std::centi, long double>;
    using millikelvin_per_watt_ld    =     kelvin_per_watt_impl<std::milli, long double>;
    using microkelvin_per_watt_ld    =     kelvin_per_watt_impl<std::micro, long double>;
    using nanokelvin_per_watt_ld    =     kelvin_per_watt_impl<std::nano, long double>;
    using picokelvin_per_watt_ld    =     kelvin_per_watt_impl<std::pico, long double>;
    using femtokelvin_per_watt_ld    =     kelvin_per_watt_impl<std::femto, long double>;
    using attokelvin_per_watt_ld    =     kelvin_per_watt_impl<std::atto, long double>;
    using exakelvin_per_watt_ull    =     kelvin_per_watt_impl<std::exa, unsigned long long>;
    using petakelvin_per_watt_ull    =     kelvin_per_watt_impl<std::peta, unsigned long long>;
    using terakelvin_per_watt_ull    =     kelvin_per_watt_impl<std::tera, unsigned long long>;
    using gigakelvin_per_watt_ull    =     kelvin_per_watt_impl<std::giga, unsigned long long>;
    using megakelvin_per_watt_ull    =     kelvin_per_watt_impl<std::mega, unsigned long long>;
    using kilokelvin_per_watt_ull    =     kelvin_per_watt_impl<std::kilo, unsigned long long>;
    using hectokelvin_per_watt_ull    =     kelvin_per_watt_impl<std::hecto, unsigned long long>;
    using decakelvin_per_watt_ull    =     kelvin_per_watt_impl<std::deca, unsigned long long>;
    using kelvin_per_watt_ull    =     kelvin_per_watt_impl<unity_ratio, unsigned long long>;
    using decikelvin_per_watt_ull    =     kelvin_per_watt_impl<std::deci, unsigned long long>;
    using centikelvin_per_watt_ull    =     kelvin_per_watt_impl<std::centi, unsigned long long>;
    using millikelvin_per_watt_ull    =     kelvin_per_watt_impl<std::milli, unsigned long long>;
    using microkelvin_per_watt_ull    =     kelvin_per_watt_impl<std::micro, unsigned long long>;
    using nanokelvin_per_watt_ull    =     kelvin_per_watt_impl<std::nano, unsigned long long>;
    using picokelvin_per_watt_ull    =     kelvin_per_watt_impl<std::pico, unsigned long long>;
    using femtokelvin_per_watt_ull    =     kelvin_per_watt_impl<std::femto, unsigned long long>;
    using attokelvin_per_watt_ull    =     kelvin_per_watt_impl<std::atto, unsigned long long>;

    constexpr exakelvin_per_watt_ld operator""_EK_per_W(long double val) {
        return static_cast<exakelvin_per_watt_ld>(val);
    }
    constexpr petakelvin_per_watt_ld operator""_PK_per_W(long double val) {
        return static_cast<petakelvin_per_watt_ld>(val);
    }
    constexpr terakelvin_per_watt_ld operator""_TK_per_W(long double val) {
        return static_cast<terakelvin_per_watt_ld>(val);
    }
    constexpr gigakelvin_per_watt_ld operator""_GK_per_W(long double val) {
        return static_cast<gigakelvin_per_watt_ld>(val);
    }
    constexpr megakelvin_per_watt_ld operator""_MK_per_W(long double val) {
        return static_cast<megakelvin_per_watt_ld>(val);
    }
    constexpr kilokelvin_per_watt_ld operator""_kK_per_W(long double val) {
        return static_cast<kilokelvin_per_watt_ld>(val);
    }
    constexpr hectokelvin_per_watt_ld operator""_hK_per_W(long double val) {
        return static_cast<hectokelvin_per_watt_ld>(val);
    }
    constexpr decakelvin_per_watt_ld operator""_daK_per_W(long double val) {
        return static_cast<decakelvin_per_watt_ld>(val);
    }
    constexpr kelvin_per_watt_ld operator""_K_per_W(long double val) {
        return static_cast<kelvin_per_watt_ld>(val);
    }
    constexpr decikelvin_per_watt_ld operator""_dK_per_W(long double val) {
        return static_cast<decikelvin_per_watt_ld>(val);
    }
    constexpr centikelvin_per_watt_ld operator""_cK_per_W(long double val) {
        return static_cast<centikelvin_per_watt_ld>(val);
    }
    constexpr millikelvin_per_watt_ld operator""_mK_per_W(long double val) {
        return static_cast<millikelvin_per_watt_ld>(val);
    }
    constexpr microkelvin_per_watt_ld operator""_uK_per_W(long double val) {
        return static_cast<microkelvin_per_watt_ld>(val);
    }
    constexpr nanokelvin_per_watt_ld operator""_nK_per_W(long double val) {
        return static_cast<nanokelvin_per_watt_ld>(val);
    }
    constexpr picokelvin_per_watt_ld operator""_pK_per_W(long double val) {
        return static_cast<picokelvin_per_watt_ld>(val);
    }
    constexpr femtokelvin_per_watt_ld operator""_fK_per_W(long double val) {
        return static_cast<femtokelvin_per_watt_ld>(val);
    }
    constexpr attokelvin_per_watt_ld operator""_aK_per_W(long double val) {
        return static_cast<attokelvin_per_watt_ld>(val);
    }
    constexpr exakelvin_per_watt_ull operator""_EK_per_W(unsigned long long val) {
        return static_cast<exakelvin_per_watt_ull>(val);
    }
    constexpr petakelvin_per_watt_ull operator""_PK_per_W(unsigned long long val) {
        return static_cast<petakelvin_per_watt_ull>(val);
    }
    constexpr terakelvin_per_watt_ull operator""_TK_per_W(unsigned long long val) {
        return static_cast<terakelvin_per_watt_ull>(val);
    }
    constexpr gigakelvin_per_watt_ull operator""_GK_per_W(unsigned long long val) {
        return static_cast<gigakelvin_per_watt_ull>(val);
    }
    constexpr megakelvin_per_watt_ull operator""_MK_per_W(unsigned long long val) {
        return static_cast<megakelvin_per_watt_ull>(val);
    }
    constexpr kilokelvin_per_watt_ull operator""_kK_per_W(unsigned long long val) {
        return static_cast<kilokelvin_per_watt_ull>(val);
    }
    constexpr hectokelvin_per_watt_ull operator""_hK_per_W(unsigned long long val) {
        return static_cast<hectokelvin_per_watt_ull>(val);
    }
    constexpr decakelvin_per_watt_ull operator""_daK_per_W(unsigned long long val) {
        return static_cast<decakelvin_per_watt_ull>(val);
    }
    constexpr kelvin_per_watt_ull operator""_K_per_W(unsigned long long val) {
        return static_cast<kelvin_per_watt_ull>(val);
    }
    constexpr decikelvin_per_watt_ull operator""_dK_per_W(unsigned long long val) {
        return static_cast<decikelvin_per_watt_ull>(val);
    }
    constexpr centikelvin_per_watt_ull operator""_cK_per_W(unsigned long long val) {
        return static_cast<centikelvin_per_watt_ull>(val);
    }
    constexpr millikelvin_per_watt_ull operator""_mK_per_W(unsigned long long val) {
        return static_cast<millikelvin_per_watt_ull>(val);
    }
    constexpr microkelvin_per_watt_ull operator""_uK_per_W(unsigned long long val) {
        return static_cast<microkelvin_per_watt_ull>(val);
    }
    constexpr nanokelvin_per_watt_ull operator""_nK_per_W(unsigned long long val) {
        return static_cast<nanokelvin_per_watt_ull>(val);
    }
    constexpr picokelvin_per_watt_ull operator""_pK_per_W(unsigned long long val) {
        return static_cast<picokelvin_per_watt_ull>(val);
    }
    constexpr femtokelvin_per_watt_ull operator""_fK_per_W(unsigned long long val) {
        return static_cast<femtokelvin_per_watt_ull>(val);
    }
    constexpr attokelvin_per_watt_ull operator""_aK_per_W(unsigned long long val) {
        return static_cast<attokelvin_per_watt_ull>(val);
    }

} // namespace potato::units
