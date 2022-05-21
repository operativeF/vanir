//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using time_tag_t = tmp::list_<Length<std::ratio<0, 1>>,
                                         Time<std::ratio<1, 1>>,
                                         Mass<std::ratio<0, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept SecondC = std::same_as<typename T::impl, time_tag_t>;

    template <typename RatioTypeT, typename P>
    struct second_impl {

        static constexpr auto pretty = "t";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = time_tag_t;

        constexpr second_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
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

    consteval exasecond_ld operator""_Es(long double val) {
        return static_cast<exasecond_ld>(val);
    }
    consteval petasecond_ld operator""_Ps(long double val) {
        return static_cast<petasecond_ld>(val);
    }
    consteval terasecond_ld operator""_Ts(long double val) {
        return static_cast<terasecond_ld>(val);
    }
    consteval gigasecond_ld operator""_Gs(long double val) {
        return static_cast<gigasecond_ld>(val);
    }
    consteval megasecond_ld operator""_Ms(long double val) {
        return static_cast<megasecond_ld>(val);
    }
    consteval kilosecond_ld operator""_ks(long double val) {
        return static_cast<kilosecond_ld>(val);
    }
    consteval hectosecond_ld operator""_hs(long double val) {
        return static_cast<hectosecond_ld>(val);
    }
    consteval decasecond_ld operator""_das(long double val) {
        return static_cast<decasecond_ld>(val);
    }
    consteval second_ld operator""_s(long double val) {
        return static_cast<second_ld>(val);
    }
    consteval decisecond_ld operator""_ds(long double val) {
        return static_cast<decisecond_ld>(val);
    }
    consteval centisecond_ld operator""_cs(long double val) {
        return static_cast<centisecond_ld>(val);
    }
    consteval millisecond_ld operator""_ms(long double val) {
        return static_cast<millisecond_ld>(val);
    }
    consteval microsecond_ld operator""_us(long double val) {
        return static_cast<microsecond_ld>(val);
    }
    consteval nanosecond_ld operator""_ns(long double val) {
        return static_cast<nanosecond_ld>(val);
    }
    consteval picosecond_ld operator""_ps(long double val) {
        return static_cast<picosecond_ld>(val);
    }
    consteval femtosecond_ld operator""_fs(long double val) {
        return static_cast<femtosecond_ld>(val);
    }
    consteval attosecond_ld operator""_as(long double val) {
        return static_cast<attosecond_ld>(val);
    }
    consteval exasecond_ull operator""_Es(unsigned long long val) {
        return static_cast<exasecond_ull>(val);
    }
    consteval petasecond_ull operator""_Ps(unsigned long long val) {
        return static_cast<petasecond_ull>(val);
    }
    consteval terasecond_ull operator""_Ts(unsigned long long val) {
        return static_cast<terasecond_ull>(val);
    }
    consteval gigasecond_ull operator""_Gs(unsigned long long val) {
        return static_cast<gigasecond_ull>(val);
    }
    consteval megasecond_ull operator""_Ms(unsigned long long val) {
        return static_cast<megasecond_ull>(val);
    }
    consteval kilosecond_ull operator""_ks(unsigned long long val) {
        return static_cast<kilosecond_ull>(val);
    }
    consteval hectosecond_ull operator""_hs(unsigned long long val) {
        return static_cast<hectosecond_ull>(val);
    }
    consteval decasecond_ull operator""_das(unsigned long long val) {
        return static_cast<decasecond_ull>(val);
    }
    consteval second_ull operator""_s(unsigned long long val) {
        return static_cast<second_ull>(val);
    }
    consteval decisecond_ull operator""_ds(unsigned long long val) {
        return static_cast<decisecond_ull>(val);
    }
    consteval centisecond_ull operator""_cs(unsigned long long val) {
        return static_cast<centisecond_ull>(val);
    }
    consteval millisecond_ull operator""_ms(unsigned long long val) {
        return static_cast<millisecond_ull>(val);
    }
    consteval microsecond_ull operator""_us(unsigned long long val) {
        return static_cast<microsecond_ull>(val);
    }
    consteval nanosecond_ull operator""_ns(unsigned long long val) {
        return static_cast<nanosecond_ull>(val);
    }
    consteval picosecond_ull operator""_ps(unsigned long long val) {
        return static_cast<picosecond_ull>(val);
    }
    consteval femtosecond_ull operator""_fs(unsigned long long val) {
        return static_cast<femtosecond_ull>(val);
    }
    consteval attosecond_ull operator""_as(unsigned long long val) {
        return static_cast<attosecond_ull>(val);
    }

} // namespace potato::units
