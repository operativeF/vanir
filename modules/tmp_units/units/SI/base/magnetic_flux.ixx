//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Weber;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.BaseUnit;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename RatioTypeT, typename P>
    struct weber_impl : base_unit_<RatioTypeT, P> {

        using base_unit_<RatioTypeT, P>::base_unit_;
        template <typename U, typename R>
        constexpr const weber_impl<RatioTypeT, P>(const weber_impl<U, R>& other) {
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

        static constexpr auto pretty = "Wb";

        using is_any_impl = false_;

        using mod_ratio = RatioTypeT;
        using numer_type = base_unit_<RatioTypeT, P>::value_type;
        using impl      = list_<list_<meter_l, meter_l, gram_l>, list_<second_l, second_l, ampere_l>>;
    };

    using exaweber_ld    =     weber_impl<std::exa, long double>;
    using petaweber_ld    =     weber_impl<std::peta, long double>;
    using teraweber_ld    =     weber_impl<std::tera, long double>;
    using gigaweber_ld    =     weber_impl<std::giga, long double>;
    using megaweber_ld    =     weber_impl<std::mega, long double>;
    using kiloweber_ld    =     weber_impl<std::kilo, long double>;
    using hectoweber_ld    =     weber_impl<std::hecto, long double>;
    using decaweber_ld    =     weber_impl<std::deca, long double>;
    using weber_ld    =     weber_impl<unity_ratio, long double>;
    using deciweber_ld    =     weber_impl<std::deci, long double>;
    using centiweber_ld    =     weber_impl<std::centi, long double>;
    using milliweber_ld    =     weber_impl<std::milli, long double>;
    using microweber_ld    =     weber_impl<std::micro, long double>;
    using nanoweber_ld    =     weber_impl<std::nano, long double>;
    using picoweber_ld    =     weber_impl<std::pico, long double>;
    using femtoweber_ld    =     weber_impl<std::femto, long double>;
    using attoweber_ld    =     weber_impl<std::atto, long double>;
    using exaweber_ull    =     weber_impl<std::exa, unsigned long long>;
    using petaweber_ull    =     weber_impl<std::peta, unsigned long long>;
    using teraweber_ull    =     weber_impl<std::tera, unsigned long long>;
    using gigaweber_ull    =     weber_impl<std::giga, unsigned long long>;
    using megaweber_ull    =     weber_impl<std::mega, unsigned long long>;
    using kiloweber_ull    =     weber_impl<std::kilo, unsigned long long>;
    using hectoweber_ull    =     weber_impl<std::hecto, unsigned long long>;
    using decaweber_ull    =     weber_impl<std::deca, unsigned long long>;
    using weber_ull    =     weber_impl<unity_ratio, unsigned long long>;
    using deciweber_ull    =     weber_impl<std::deci, unsigned long long>;
    using centiweber_ull    =     weber_impl<std::centi, unsigned long long>;
    using milliweber_ull    =     weber_impl<std::milli, unsigned long long>;
    using microweber_ull    =     weber_impl<std::micro, unsigned long long>;
    using nanoweber_ull    =     weber_impl<std::nano, unsigned long long>;
    using picoweber_ull    =     weber_impl<std::pico, unsigned long long>;
    using femtoweber_ull    =     weber_impl<std::femto, unsigned long long>;
    using attoweber_ull    =     weber_impl<std::atto, unsigned long long>;

    constexpr exaweber_ld operator""_EWb(long double val) {
        return static_cast<exaweber_ld>(val);
    }
    constexpr petaweber_ld operator""_PWb(long double val) {
        return static_cast<petaweber_ld>(val);
    }
    constexpr teraweber_ld operator""_TWb(long double val) {
        return static_cast<teraweber_ld>(val);
    }
    constexpr gigaweber_ld operator""_GWb(long double val) {
        return static_cast<gigaweber_ld>(val);
    }
    constexpr megaweber_ld operator""_MWb(long double val) {
        return static_cast<megaweber_ld>(val);
    }
    constexpr kiloweber_ld operator""_kWb(long double val) {
        return static_cast<kiloweber_ld>(val);
    }
    constexpr hectoweber_ld operator""_hWb(long double val) {
        return static_cast<hectoweber_ld>(val);
    }
    constexpr decaweber_ld operator""_daWb(long double val) {
        return static_cast<decaweber_ld>(val);
    }
    constexpr weber_ld operator""_Wb(long double val) {
        return static_cast<weber_ld>(val);
    }
    constexpr deciweber_ld operator""_dWb(long double val) {
        return static_cast<deciweber_ld>(val);
    }
    constexpr centiweber_ld operator""_cWb(long double val) {
        return static_cast<centiweber_ld>(val);
    }
    constexpr milliweber_ld operator""_mWb(long double val) {
        return static_cast<milliweber_ld>(val);
    }
    constexpr microweber_ld operator""_uWb(long double val) {
        return static_cast<microweber_ld>(val);
    }
    constexpr nanoweber_ld operator""_nWb(long double val) {
        return static_cast<nanoweber_ld>(val);
    }
    constexpr picoweber_ld operator""_pWb(long double val) {
        return static_cast<picoweber_ld>(val);
    }
    constexpr femtoweber_ld operator""_fWb(long double val) {
        return static_cast<femtoweber_ld>(val);
    }
    constexpr attoweber_ld operator""_aWb(long double val) {
        return static_cast<attoweber_ld>(val);
    }
    constexpr exaweber_ull operator""_EWb(unsigned long long val) {
        return static_cast<exaweber_ull>(val);
    }
    constexpr petaweber_ull operator""_PWb(unsigned long long val) {
        return static_cast<petaweber_ull>(val);
    }
    constexpr teraweber_ull operator""_TWb(unsigned long long val) {
        return static_cast<teraweber_ull>(val);
    }
    constexpr gigaweber_ull operator""_GWb(unsigned long long val) {
        return static_cast<gigaweber_ull>(val);
    }
    constexpr megaweber_ull operator""_MWb(unsigned long long val) {
        return static_cast<megaweber_ull>(val);
    }
    constexpr kiloweber_ull operator""_kWb(unsigned long long val) {
        return static_cast<kiloweber_ull>(val);
    }
    constexpr hectoweber_ull operator""_hWb(unsigned long long val) {
        return static_cast<hectoweber_ull>(val);
    }
    constexpr decaweber_ull operator""_daWb(unsigned long long val) {
        return static_cast<decaweber_ull>(val);
    }
    constexpr weber_ull operator""_Wb(unsigned long long val) {
        return static_cast<weber_ull>(val);
    }
    constexpr deciweber_ull operator""_dWb(unsigned long long val) {
        return static_cast<deciweber_ull>(val);
    }
    constexpr centiweber_ull operator""_cWb(unsigned long long val) {
        return static_cast<centiweber_ull>(val);
    }
    constexpr milliweber_ull operator""_mWb(unsigned long long val) {
        return static_cast<milliweber_ull>(val);
    }
    constexpr microweber_ull operator""_uWb(unsigned long long val) {
        return static_cast<microweber_ull>(val);
    }
    constexpr nanoweber_ull operator""_nWb(unsigned long long val) {
        return static_cast<nanoweber_ull>(val);
    }
    constexpr picoweber_ull operator""_pWb(unsigned long long val) {
        return static_cast<picoweber_ull>(val);
    }
    constexpr femtoweber_ull operator""_fWb(unsigned long long val) {
        return static_cast<femtoweber_ull>(val);
    }
    constexpr attoweber_ull operator""_aWb(unsigned long long val) {
        return static_cast<attoweber_ull>(val);
    }

} // namespace potato::units
