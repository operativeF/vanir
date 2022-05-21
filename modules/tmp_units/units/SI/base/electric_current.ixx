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

    using electric_current_tag_t = tmp::list_<Length<std::ratio<0, 1>>,
                                         Time<std::ratio<0, 1>>,
                                         Mass<std::ratio<0, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<1, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept AmpereC = std::same_as<typename T::impl, electric_current_tag_t>;

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
        using impl       = electric_current_tag_t;

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

    consteval exaampere_ld operator""_EA(long double val) {
        return static_cast<exaampere_ld>(val);
    }
    consteval petaampere_ld operator""_PA(long double val) {
        return static_cast<petaampere_ld>(val);
    }
    consteval teraampere_ld operator""_TA(long double val) {
        return static_cast<teraampere_ld>(val);
    }
    consteval gigaampere_ld operator""_GA(long double val) {
        return static_cast<gigaampere_ld>(val);
    }
    consteval megaampere_ld operator""_MA(long double val) {
        return static_cast<megaampere_ld>(val);
    }
    consteval kiloampere_ld operator""_kA(long double val) {
        return static_cast<kiloampere_ld>(val);
    }
    consteval hectoampere_ld operator""_hA(long double val) {
        return static_cast<hectoampere_ld>(val);
    }
    consteval decaampere_ld operator""_daA(long double val) {
        return static_cast<decaampere_ld>(val);
    }
    consteval ampere_ld operator""_A(long double val) {
        return static_cast<ampere_ld>(val);
    }
    consteval deciampere_ld operator""_dA(long double val) {
        return static_cast<deciampere_ld>(val);
    }
    consteval centiampere_ld operator""_cA(long double val) {
        return static_cast<centiampere_ld>(val);
    }
    consteval milliampere_ld operator""_mA(long double val) {
        return static_cast<milliampere_ld>(val);
    }
    consteval microampere_ld operator""_uA(long double val) {
        return static_cast<microampere_ld>(val);
    }
    consteval nanoampere_ld operator""_nA(long double val) {
        return static_cast<nanoampere_ld>(val);
    }
    consteval picoampere_ld operator""_pA(long double val) {
        return static_cast<picoampere_ld>(val);
    }
    consteval femtoampere_ld operator""_fA(long double val) {
        return static_cast<femtoampere_ld>(val);
    }
    consteval attoampere_ld operator""_aA(long double val) {
        return static_cast<attoampere_ld>(val);
    }
    consteval exaampere_ull operator""_EA(unsigned long long val) {
        return static_cast<exaampere_ull>(val);
    }
    consteval petaampere_ull operator""_PA(unsigned long long val) {
        return static_cast<petaampere_ull>(val);
    }
    consteval teraampere_ull operator""_TA(unsigned long long val) {
        return static_cast<teraampere_ull>(val);
    }
    consteval gigaampere_ull operator""_GA(unsigned long long val) {
        return static_cast<gigaampere_ull>(val);
    }
    consteval megaampere_ull operator""_MA(unsigned long long val) {
        return static_cast<megaampere_ull>(val);
    }
    consteval kiloampere_ull operator""_kA(unsigned long long val) {
        return static_cast<kiloampere_ull>(val);
    }
    consteval hectoampere_ull operator""_hA(unsigned long long val) {
        return static_cast<hectoampere_ull>(val);
    }
    consteval decaampere_ull operator""_daA(unsigned long long val) {
        return static_cast<decaampere_ull>(val);
    }
    consteval ampere_ull operator""_A(unsigned long long val) {
        return static_cast<ampere_ull>(val);
    }
    consteval deciampere_ull operator""_dA(unsigned long long val) {
        return static_cast<deciampere_ull>(val);
    }
    consteval centiampere_ull operator""_cA(unsigned long long val) {
        return static_cast<centiampere_ull>(val);
    }
    consteval milliampere_ull operator""_mA(unsigned long long val) {
        return static_cast<milliampere_ull>(val);
    }
    consteval microampere_ull operator""_uA(unsigned long long val) {
        return static_cast<microampere_ull>(val);
    }
    consteval nanoampere_ull operator""_nA(unsigned long long val) {
        return static_cast<nanoampere_ull>(val);
    }
    consteval picoampere_ull operator""_pA(unsigned long long val) {
        return static_cast<picoampere_ull>(val);
    }
    consteval femtoampere_ull operator""_fA(unsigned long long val) {
        return static_cast<femtoampere_ull>(val);
    }
    consteval attoampere_ull operator""_aA(unsigned long long val) {
        return static_cast<attoampere_ull>(val);
    }

} // namespace potato::units
