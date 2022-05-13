//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.BaseUnit;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename RatioTypeT, typename P>
    struct second_impl : base_unit_<RatioTypeT, P> {

        using base_unit_<RatioTypeT, P>::base_unit_;
        template <typename U, typename R>
        constexpr const second_impl<RatioTypeT, P>(const second_impl<U, R>& other) {
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

        static constexpr auto pretty = "t";

        using is_any_impl = false_;

        using mod_ratio = RatioTypeT;
        using numer_type = base_unit_<RatioTypeT, P>::value_type;
        using impl      = list_<list_<second_l>, list_<>>;
    };

    using exasecond_ld    =     second_impl<std::exa, long double>;
    using petasecond_ld    =     second_impl<std::peta, long double>;
    using terasecond_ld    =     second_impl<std::tera, long double>;
    using gigasecond_ld    =     second_impl<std::giga, long double>;
    using megasecond_ld    =     second_impl<std::mega, long double>;
    using kilosecond_ld    =     second_impl<std::kilo, long double>;
    using hectosecond_ld    =     second_impl<std::hecto, long double>;
    using decasecond_ld    =     second_impl<std::deca, long double>;
    using second_ld    =     second_impl<unity_ratio, long double>;
    using decisecond_ld    =     second_impl<std::deci, long double>;
    using centisecond_ld    =     second_impl<std::centi, long double>;
    using millisecond_ld    =     second_impl<std::milli, long double>;
    using microsecond_ld    =     second_impl<std::micro, long double>;
    using nanosecond_ld    =     second_impl<std::nano, long double>;
    using picosecond_ld    =     second_impl<std::pico, long double>;
    using femtosecond_ld    =     second_impl<std::femto, long double>;
    using attosecond_ld    =     second_impl<std::atto, long double>;
    using exasecond_ull    =     second_impl<std::exa, unsigned long long>;
    using petasecond_ull    =     second_impl<std::peta, unsigned long long>;
    using terasecond_ull    =     second_impl<std::tera, unsigned long long>;
    using gigasecond_ull    =     second_impl<std::giga, unsigned long long>;
    using megasecond_ull    =     second_impl<std::mega, unsigned long long>;
    using kilosecond_ull    =     second_impl<std::kilo, unsigned long long>;
    using hectosecond_ull    =     second_impl<std::hecto, unsigned long long>;
    using decasecond_ull    =     second_impl<std::deca, unsigned long long>;
    using second_ull    =     second_impl<unity_ratio, unsigned long long>;
    using decisecond_ull    =     second_impl<std::deci, unsigned long long>;
    using centisecond_ull    =     second_impl<std::centi, unsigned long long>;
    using millisecond_ull    =     second_impl<std::milli, unsigned long long>;
    using microsecond_ull    =     second_impl<std::micro, unsigned long long>;
    using nanosecond_ull    =     second_impl<std::nano, unsigned long long>;
    using picosecond_ull    =     second_impl<std::pico, unsigned long long>;
    using femtosecond_ull    =     second_impl<std::femto, unsigned long long>;
    using attosecond_ull    =     second_impl<std::atto, unsigned long long>;

    constexpr exasecond_ld operator""_Es(long double val) {
        return static_cast<exasecond_ld>(val);
    }
    constexpr petasecond_ld operator""_Ps(long double val) {
        return static_cast<petasecond_ld>(val);
    }
    constexpr terasecond_ld operator""_Ts(long double val) {
        return static_cast<terasecond_ld>(val);
    }
    constexpr gigasecond_ld operator""_Gs(long double val) {
        return static_cast<gigasecond_ld>(val);
    }
    constexpr megasecond_ld operator""_Ms(long double val) {
        return static_cast<megasecond_ld>(val);
    }
    constexpr kilosecond_ld operator""_ks(long double val) {
        return static_cast<kilosecond_ld>(val);
    }
    constexpr hectosecond_ld operator""_hs(long double val) {
        return static_cast<hectosecond_ld>(val);
    }
    constexpr decasecond_ld operator""_das(long double val) {
        return static_cast<decasecond_ld>(val);
    }
    constexpr second_ld operator""_s(long double val) {
        return static_cast<second_ld>(val);
    }
    constexpr decisecond_ld operator""_ds(long double val) {
        return static_cast<decisecond_ld>(val);
    }
    constexpr centisecond_ld operator""_cs(long double val) {
        return static_cast<centisecond_ld>(val);
    }
    constexpr millisecond_ld operator""_ms(long double val) {
        return static_cast<millisecond_ld>(val);
    }
    constexpr microsecond_ld operator""_us(long double val) {
        return static_cast<microsecond_ld>(val);
    }
    constexpr nanosecond_ld operator""_ns(long double val) {
        return static_cast<nanosecond_ld>(val);
    }
    constexpr picosecond_ld operator""_ps(long double val) {
        return static_cast<picosecond_ld>(val);
    }
    constexpr femtosecond_ld operator""_fs(long double val) {
        return static_cast<femtosecond_ld>(val);
    }
    constexpr attosecond_ld operator""_as(long double val) {
        return static_cast<attosecond_ld>(val);
    }
    constexpr exasecond_ull operator""_Es(unsigned long long val) {
        return static_cast<exasecond_ull>(val);
    }
    constexpr petasecond_ull operator""_Ps(unsigned long long val) {
        return static_cast<petasecond_ull>(val);
    }
    constexpr terasecond_ull operator""_Ts(unsigned long long val) {
        return static_cast<terasecond_ull>(val);
    }
    constexpr gigasecond_ull operator""_Gs(unsigned long long val) {
        return static_cast<gigasecond_ull>(val);
    }
    constexpr megasecond_ull operator""_Ms(unsigned long long val) {
        return static_cast<megasecond_ull>(val);
    }
    constexpr kilosecond_ull operator""_ks(unsigned long long val) {
        return static_cast<kilosecond_ull>(val);
    }
    constexpr hectosecond_ull operator""_hs(unsigned long long val) {
        return static_cast<hectosecond_ull>(val);
    }
    constexpr decasecond_ull operator""_das(unsigned long long val) {
        return static_cast<decasecond_ull>(val);
    }
    constexpr second_ull operator""_s(unsigned long long val) {
        return static_cast<second_ull>(val);
    }
    constexpr decisecond_ull operator""_ds(unsigned long long val) {
        return static_cast<decisecond_ull>(val);
    }
    constexpr centisecond_ull operator""_cs(unsigned long long val) {
        return static_cast<centisecond_ull>(val);
    }
    constexpr millisecond_ull operator""_ms(unsigned long long val) {
        return static_cast<millisecond_ull>(val);
    }
    constexpr microsecond_ull operator""_us(unsigned long long val) {
        return static_cast<microsecond_ull>(val);
    }
    constexpr nanosecond_ull operator""_ns(unsigned long long val) {
        return static_cast<nanosecond_ull>(val);
    }
    constexpr picosecond_ull operator""_ps(unsigned long long val) {
        return static_cast<picosecond_ull>(val);
    }
    constexpr femtosecond_ull operator""_fs(unsigned long long val) {
        return static_cast<femtosecond_ull>(val);
    }
    constexpr attosecond_ull operator""_as(unsigned long long val) {
        return static_cast<attosecond_ull>(val);
    }

} // namespace potato::units
