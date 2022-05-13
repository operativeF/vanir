//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Volt;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.BaseUnit;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename RatioTypeT, typename P>
    struct volt_impl : base_unit_<RatioTypeT, P> {

        using base_unit_<RatioTypeT, P>::base_unit_;
        template <typename U, typename R>
        constexpr const volt_impl<RatioTypeT, P>(const volt_impl<U, R>& other) {
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

        static constexpr auto pretty = "V";

        using is_any_impl = false_;

        using mod_ratio = RatioTypeT;
        using numer_type = base_unit_<RatioTypeT, P>::value_type;
        using impl      = list_<list_<meter_l, meter_l, gram_l>, list_<second_l, second_l, second_l, ampere_l>>;
    };

    using exavolt_ld    =     volt_impl<std::exa, long double>;
    using petavolt_ld    =     volt_impl<std::peta, long double>;
    using teravolt_ld    =     volt_impl<std::tera, long double>;
    using gigavolt_ld    =     volt_impl<std::giga, long double>;
    using megavolt_ld    =     volt_impl<std::mega, long double>;
    using kilovolt_ld    =     volt_impl<std::kilo, long double>;
    using hectovolt_ld    =     volt_impl<std::hecto, long double>;
    using decavolt_ld    =     volt_impl<std::deca, long double>;
    using volt_ld    =     volt_impl<unity_ratio, long double>;
    using decivolt_ld    =     volt_impl<std::deci, long double>;
    using centivolt_ld    =     volt_impl<std::centi, long double>;
    using millivolt_ld    =     volt_impl<std::milli, long double>;
    using microvolt_ld    =     volt_impl<std::micro, long double>;
    using nanovolt_ld    =     volt_impl<std::nano, long double>;
    using picovolt_ld    =     volt_impl<std::pico, long double>;
    using femtovolt_ld    =     volt_impl<std::femto, long double>;
    using attovolt_ld    =     volt_impl<std::atto, long double>;
    using exavolt_ull    =     volt_impl<std::exa, unsigned long long>;
    using petavolt_ull    =     volt_impl<std::peta, unsigned long long>;
    using teravolt_ull    =     volt_impl<std::tera, unsigned long long>;
    using gigavolt_ull    =     volt_impl<std::giga, unsigned long long>;
    using megavolt_ull    =     volt_impl<std::mega, unsigned long long>;
    using kilovolt_ull    =     volt_impl<std::kilo, unsigned long long>;
    using hectovolt_ull    =     volt_impl<std::hecto, unsigned long long>;
    using decavolt_ull    =     volt_impl<std::deca, unsigned long long>;
    using volt_ull    =     volt_impl<unity_ratio, unsigned long long>;
    using decivolt_ull    =     volt_impl<std::deci, unsigned long long>;
    using centivolt_ull    =     volt_impl<std::centi, unsigned long long>;
    using millivolt_ull    =     volt_impl<std::milli, unsigned long long>;
    using microvolt_ull    =     volt_impl<std::micro, unsigned long long>;
    using nanovolt_ull    =     volt_impl<std::nano, unsigned long long>;
    using picovolt_ull    =     volt_impl<std::pico, unsigned long long>;
    using femtovolt_ull    =     volt_impl<std::femto, unsigned long long>;
    using attovolt_ull    =     volt_impl<std::atto, unsigned long long>;

    constexpr exavolt_ld operator""_EV(long double val) {
        return static_cast<exavolt_ld>(val);
    }
    constexpr petavolt_ld operator""_PV(long double val) {
        return static_cast<petavolt_ld>(val);
    }
    constexpr teravolt_ld operator""_TV(long double val) {
        return static_cast<teravolt_ld>(val);
    }
    constexpr gigavolt_ld operator""_GV(long double val) {
        return static_cast<gigavolt_ld>(val);
    }
    constexpr megavolt_ld operator""_MV(long double val) {
        return static_cast<megavolt_ld>(val);
    }
    constexpr kilovolt_ld operator""_kV(long double val) {
        return static_cast<kilovolt_ld>(val);
    }
    constexpr hectovolt_ld operator""_hV(long double val) {
        return static_cast<hectovolt_ld>(val);
    }
    constexpr decavolt_ld operator""_daV(long double val) {
        return static_cast<decavolt_ld>(val);
    }
    constexpr volt_ld operator""_V(long double val) {
        return static_cast<volt_ld>(val);
    }
    constexpr decivolt_ld operator""_dV(long double val) {
        return static_cast<decivolt_ld>(val);
    }
    constexpr centivolt_ld operator""_cV(long double val) {
        return static_cast<centivolt_ld>(val);
    }
    constexpr millivolt_ld operator""_mV(long double val) {
        return static_cast<millivolt_ld>(val);
    }
    constexpr microvolt_ld operator""_uV(long double val) {
        return static_cast<microvolt_ld>(val);
    }
    constexpr nanovolt_ld operator""_nV(long double val) {
        return static_cast<nanovolt_ld>(val);
    }
    constexpr picovolt_ld operator""_pV(long double val) {
        return static_cast<picovolt_ld>(val);
    }
    constexpr femtovolt_ld operator""_fV(long double val) {
        return static_cast<femtovolt_ld>(val);
    }
    constexpr attovolt_ld operator""_aV(long double val) {
        return static_cast<attovolt_ld>(val);
    }
    constexpr exavolt_ull operator""_EV(unsigned long long val) {
        return static_cast<exavolt_ull>(val);
    }
    constexpr petavolt_ull operator""_PV(unsigned long long val) {
        return static_cast<petavolt_ull>(val);
    }
    constexpr teravolt_ull operator""_TV(unsigned long long val) {
        return static_cast<teravolt_ull>(val);
    }
    constexpr gigavolt_ull operator""_GV(unsigned long long val) {
        return static_cast<gigavolt_ull>(val);
    }
    constexpr megavolt_ull operator""_MV(unsigned long long val) {
        return static_cast<megavolt_ull>(val);
    }
    constexpr kilovolt_ull operator""_kV(unsigned long long val) {
        return static_cast<kilovolt_ull>(val);
    }
    constexpr hectovolt_ull operator""_hV(unsigned long long val) {
        return static_cast<hectovolt_ull>(val);
    }
    constexpr decavolt_ull operator""_daV(unsigned long long val) {
        return static_cast<decavolt_ull>(val);
    }
    constexpr volt_ull operator""_V(unsigned long long val) {
        return static_cast<volt_ull>(val);
    }
    constexpr decivolt_ull operator""_dV(unsigned long long val) {
        return static_cast<decivolt_ull>(val);
    }
    constexpr centivolt_ull operator""_cV(unsigned long long val) {
        return static_cast<centivolt_ull>(val);
    }
    constexpr millivolt_ull operator""_mV(unsigned long long val) {
        return static_cast<millivolt_ull>(val);
    }
    constexpr microvolt_ull operator""_uV(unsigned long long val) {
        return static_cast<microvolt_ull>(val);
    }
    constexpr nanovolt_ull operator""_nV(unsigned long long val) {
        return static_cast<nanovolt_ull>(val);
    }
    constexpr picovolt_ull operator""_pV(unsigned long long val) {
        return static_cast<picovolt_ull>(val);
    }
    constexpr femtovolt_ull operator""_fV(unsigned long long val) {
        return static_cast<femtovolt_ull>(val);
    }
    constexpr attovolt_ull operator""_aV(unsigned long long val) {
        return static_cast<attovolt_ull>(val);
    }

} // namespace potato::units
