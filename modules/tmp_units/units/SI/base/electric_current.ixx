//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Ampere;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using ampere_tag_t = tmp::list_<tmp::list_<ampere_l>, tmp::list_<>>;

    template<typename T>
    concept AmpereC = std::same_as<typename T::impl, ampere_tag_t>;

    template <typename RatioTypeT, typename P>
    struct ampere_impl {

        static constexpr auto pretty = "I";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = ampere_tag_t;

        constexpr ampere_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exaampere_ld    =     ampere_impl<std::exa, long double>;
    using petaampere_ld    =     ampere_impl<std::peta, long double>;
    using teraampere_ld    =     ampere_impl<std::tera, long double>;
    using gigaampere_ld    =     ampere_impl<std::giga, long double>;
    using megaampere_ld    =     ampere_impl<std::mega, long double>;
    using kiloampere_ld    =     ampere_impl<std::kilo, long double>;
    using hectoampere_ld    =     ampere_impl<std::hecto, long double>;
    using decaampere_ld    =     ampere_impl<std::deca, long double>;
    using ampere_ld    =     ampere_impl<unity_ratio, long double>;
    using deciampere_ld    =     ampere_impl<std::deci, long double>;
    using centiampere_ld    =     ampere_impl<std::centi, long double>;
    using milliampere_ld    =     ampere_impl<std::milli, long double>;
    using microampere_ld    =     ampere_impl<std::micro, long double>;
    using nanoampere_ld    =     ampere_impl<std::nano, long double>;
    using picoampere_ld    =     ampere_impl<std::pico, long double>;
    using femtoampere_ld    =     ampere_impl<std::femto, long double>;
    using attoampere_ld    =     ampere_impl<std::atto, long double>;
    using exaampere_ull    =     ampere_impl<std::exa, unsigned long long>;
    using petaampere_ull    =     ampere_impl<std::peta, unsigned long long>;
    using teraampere_ull    =     ampere_impl<std::tera, unsigned long long>;
    using gigaampere_ull    =     ampere_impl<std::giga, unsigned long long>;
    using megaampere_ull    =     ampere_impl<std::mega, unsigned long long>;
    using kiloampere_ull    =     ampere_impl<std::kilo, unsigned long long>;
    using hectoampere_ull    =     ampere_impl<std::hecto, unsigned long long>;
    using decaampere_ull    =     ampere_impl<std::deca, unsigned long long>;
    using ampere_ull    =     ampere_impl<unity_ratio, unsigned long long>;
    using deciampere_ull    =     ampere_impl<std::deci, unsigned long long>;
    using centiampere_ull    =     ampere_impl<std::centi, unsigned long long>;
    using milliampere_ull    =     ampere_impl<std::milli, unsigned long long>;
    using microampere_ull    =     ampere_impl<std::micro, unsigned long long>;
    using nanoampere_ull    =     ampere_impl<std::nano, unsigned long long>;
    using picoampere_ull    =     ampere_impl<std::pico, unsigned long long>;
    using femtoampere_ull    =     ampere_impl<std::femto, unsigned long long>;
    using attoampere_ull    =     ampere_impl<std::atto, unsigned long long>;

    constexpr exaampere_ld operator""_EA(long double val) {
        return static_cast<exaampere_ld>(val);
    }
    constexpr petaampere_ld operator""_PA(long double val) {
        return static_cast<petaampere_ld>(val);
    }
    constexpr teraampere_ld operator""_TA(long double val) {
        return static_cast<teraampere_ld>(val);
    }
    constexpr gigaampere_ld operator""_GA(long double val) {
        return static_cast<gigaampere_ld>(val);
    }
    constexpr megaampere_ld operator""_MA(long double val) {
        return static_cast<megaampere_ld>(val);
    }
    constexpr kiloampere_ld operator""_kA(long double val) {
        return static_cast<kiloampere_ld>(val);
    }
    constexpr hectoampere_ld operator""_hA(long double val) {
        return static_cast<hectoampere_ld>(val);
    }
    constexpr decaampere_ld operator""_daA(long double val) {
        return static_cast<decaampere_ld>(val);
    }
    constexpr ampere_ld operator""_A(long double val) {
        return static_cast<ampere_ld>(val);
    }
    constexpr deciampere_ld operator""_dA(long double val) {
        return static_cast<deciampere_ld>(val);
    }
    constexpr centiampere_ld operator""_cA(long double val) {
        return static_cast<centiampere_ld>(val);
    }
    constexpr milliampere_ld operator""_mA(long double val) {
        return static_cast<milliampere_ld>(val);
    }
    constexpr microampere_ld operator""_uA(long double val) {
        return static_cast<microampere_ld>(val);
    }
    constexpr nanoampere_ld operator""_nA(long double val) {
        return static_cast<nanoampere_ld>(val);
    }
    constexpr picoampere_ld operator""_pA(long double val) {
        return static_cast<picoampere_ld>(val);
    }
    constexpr femtoampere_ld operator""_fA(long double val) {
        return static_cast<femtoampere_ld>(val);
    }
    constexpr attoampere_ld operator""_aA(long double val) {
        return static_cast<attoampere_ld>(val);
    }
    constexpr exaampere_ull operator""_EA(unsigned long long val) {
        return static_cast<exaampere_ull>(val);
    }
    constexpr petaampere_ull operator""_PA(unsigned long long val) {
        return static_cast<petaampere_ull>(val);
    }
    constexpr teraampere_ull operator""_TA(unsigned long long val) {
        return static_cast<teraampere_ull>(val);
    }
    constexpr gigaampere_ull operator""_GA(unsigned long long val) {
        return static_cast<gigaampere_ull>(val);
    }
    constexpr megaampere_ull operator""_MA(unsigned long long val) {
        return static_cast<megaampere_ull>(val);
    }
    constexpr kiloampere_ull operator""_kA(unsigned long long val) {
        return static_cast<kiloampere_ull>(val);
    }
    constexpr hectoampere_ull operator""_hA(unsigned long long val) {
        return static_cast<hectoampere_ull>(val);
    }
    constexpr decaampere_ull operator""_daA(unsigned long long val) {
        return static_cast<decaampere_ull>(val);
    }
    constexpr ampere_ull operator""_A(unsigned long long val) {
        return static_cast<ampere_ull>(val);
    }
    constexpr deciampere_ull operator""_dA(unsigned long long val) {
        return static_cast<deciampere_ull>(val);
    }
    constexpr centiampere_ull operator""_cA(unsigned long long val) {
        return static_cast<centiampere_ull>(val);
    }
    constexpr milliampere_ull operator""_mA(unsigned long long val) {
        return static_cast<milliampere_ull>(val);
    }
    constexpr microampere_ull operator""_uA(unsigned long long val) {
        return static_cast<microampere_ull>(val);
    }
    constexpr nanoampere_ull operator""_nA(unsigned long long val) {
        return static_cast<nanoampere_ull>(val);
    }
    constexpr picoampere_ull operator""_pA(unsigned long long val) {
        return static_cast<picoampere_ull>(val);
    }
    constexpr femtoampere_ull operator""_fA(unsigned long long val) {
        return static_cast<femtoampere_ull>(val);
    }
    constexpr attoampere_ull operator""_aA(unsigned long long val) {
        return static_cast<attoampere_ull>(val);
    }

} // namespace potato::units
