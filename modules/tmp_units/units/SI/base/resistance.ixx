//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Ohm;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using resistance_tag_t = tmp::list_<Length<std::ratio<2, 1>>,
                                         Time<std::ratio<-3, 1>>,
                                         Mass<std::ratio<1, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<-2, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept OhmC = std::same_as<typename T::impl, resistance_tag_t>;

    template <typename RatioTypeT, typename P>
    struct ohm_impl {

        static constexpr auto pretty = "Ω";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = resistance_tag_t;

        constexpr ohm_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exaohm_ld    =     ohm_impl<std::exa, long double>;
    using petaohm_ld    =     ohm_impl<std::peta, long double>;
    using teraohm_ld    =     ohm_impl<std::tera, long double>;
    using gigaohm_ld    =     ohm_impl<std::giga, long double>;
    using megaohm_ld    =     ohm_impl<std::mega, long double>;
    using kiloohm_ld    =     ohm_impl<std::kilo, long double>;
    using hectoohm_ld    =     ohm_impl<std::hecto, long double>;
    using decaohm_ld    =     ohm_impl<std::deca, long double>;
    using ohm_ld    =     ohm_impl<unity_ratio, long double>;
    using deciohm_ld    =     ohm_impl<std::deci, long double>;
    using centiohm_ld    =     ohm_impl<std::centi, long double>;
    using milliohm_ld    =     ohm_impl<std::milli, long double>;
    using microohm_ld    =     ohm_impl<std::micro, long double>;
    using nanoohm_ld    =     ohm_impl<std::nano, long double>;
    using picoohm_ld    =     ohm_impl<std::pico, long double>;
    using femtoohm_ld    =     ohm_impl<std::femto, long double>;
    using attoohm_ld    =     ohm_impl<std::atto, long double>;
    using exaohm_ull    =     ohm_impl<std::exa, unsigned long long>;
    using petaohm_ull    =     ohm_impl<std::peta, unsigned long long>;
    using teraohm_ull    =     ohm_impl<std::tera, unsigned long long>;
    using gigaohm_ull    =     ohm_impl<std::giga, unsigned long long>;
    using megaohm_ull    =     ohm_impl<std::mega, unsigned long long>;
    using kiloohm_ull    =     ohm_impl<std::kilo, unsigned long long>;
    using hectoohm_ull    =     ohm_impl<std::hecto, unsigned long long>;
    using decaohm_ull    =     ohm_impl<std::deca, unsigned long long>;
    using ohm_ull    =     ohm_impl<unity_ratio, unsigned long long>;
    using deciohm_ull    =     ohm_impl<std::deci, unsigned long long>;
    using centiohm_ull    =     ohm_impl<std::centi, unsigned long long>;
    using milliohm_ull    =     ohm_impl<std::milli, unsigned long long>;
    using microohm_ull    =     ohm_impl<std::micro, unsigned long long>;
    using nanoohm_ull    =     ohm_impl<std::nano, unsigned long long>;
    using picoohm_ull    =     ohm_impl<std::pico, unsigned long long>;
    using femtoohm_ull    =     ohm_impl<std::femto, unsigned long long>;
    using attoohm_ull    =     ohm_impl<std::atto, unsigned long long>;

    consteval exaohm_ld operator""_Eohm(long double val) {
        return static_cast<exaohm_ld>(val);
    }
    consteval petaohm_ld operator""_Pohm(long double val) {
        return static_cast<petaohm_ld>(val);
    }
    consteval teraohm_ld operator""_Tohm(long double val) {
        return static_cast<teraohm_ld>(val);
    }
    consteval gigaohm_ld operator""_Gohm(long double val) {
        return static_cast<gigaohm_ld>(val);
    }
    consteval megaohm_ld operator""_Mohm(long double val) {
        return static_cast<megaohm_ld>(val);
    }
    consteval kiloohm_ld operator""_kohm(long double val) {
        return static_cast<kiloohm_ld>(val);
    }
    consteval hectoohm_ld operator""_hohm(long double val) {
        return static_cast<hectoohm_ld>(val);
    }
    consteval decaohm_ld operator""_daohm(long double val) {
        return static_cast<decaohm_ld>(val);
    }
    consteval ohm_ld operator""_ohm(long double val) {
        return static_cast<ohm_ld>(val);
    }
    consteval deciohm_ld operator""_dohm(long double val) {
        return static_cast<deciohm_ld>(val);
    }
    consteval centiohm_ld operator""_cohm(long double val) {
        return static_cast<centiohm_ld>(val);
    }
    consteval milliohm_ld operator""_mohm(long double val) {
        return static_cast<milliohm_ld>(val);
    }
    consteval microohm_ld operator""_uohm(long double val) {
        return static_cast<microohm_ld>(val);
    }
    consteval nanoohm_ld operator""_nohm(long double val) {
        return static_cast<nanoohm_ld>(val);
    }
    consteval picoohm_ld operator""_pohm(long double val) {
        return static_cast<picoohm_ld>(val);
    }
    consteval femtoohm_ld operator""_fohm(long double val) {
        return static_cast<femtoohm_ld>(val);
    }
    consteval attoohm_ld operator""_aohm(long double val) {
        return static_cast<attoohm_ld>(val);
    }
    consteval exaohm_ull operator""_Eohm(unsigned long long val) {
        return static_cast<exaohm_ull>(val);
    }
    consteval petaohm_ull operator""_Pohm(unsigned long long val) {
        return static_cast<petaohm_ull>(val);
    }
    consteval teraohm_ull operator""_Tohm(unsigned long long val) {
        return static_cast<teraohm_ull>(val);
    }
    consteval gigaohm_ull operator""_Gohm(unsigned long long val) {
        return static_cast<gigaohm_ull>(val);
    }
    consteval megaohm_ull operator""_Mohm(unsigned long long val) {
        return static_cast<megaohm_ull>(val);
    }
    consteval kiloohm_ull operator""_kohm(unsigned long long val) {
        return static_cast<kiloohm_ull>(val);
    }
    consteval hectoohm_ull operator""_hohm(unsigned long long val) {
        return static_cast<hectoohm_ull>(val);
    }
    consteval decaohm_ull operator""_daohm(unsigned long long val) {
        return static_cast<decaohm_ull>(val);
    }
    consteval ohm_ull operator""_ohm(unsigned long long val) {
        return static_cast<ohm_ull>(val);
    }
    consteval deciohm_ull operator""_dohm(unsigned long long val) {
        return static_cast<deciohm_ull>(val);
    }
    consteval centiohm_ull operator""_cohm(unsigned long long val) {
        return static_cast<centiohm_ull>(val);
    }
    consteval milliohm_ull operator""_mohm(unsigned long long val) {
        return static_cast<milliohm_ull>(val);
    }
    consteval microohm_ull operator""_uohm(unsigned long long val) {
        return static_cast<microohm_ull>(val);
    }
    consteval nanoohm_ull operator""_nohm(unsigned long long val) {
        return static_cast<nanoohm_ull>(val);
    }
    consteval picoohm_ull operator""_pohm(unsigned long long val) {
        return static_cast<picoohm_ull>(val);
    }
    consteval femtoohm_ull operator""_fohm(unsigned long long val) {
        return static_cast<femtoohm_ull>(val);
    }
    consteval attoohm_ull operator""_aohm(unsigned long long val) {
        return static_cast<attoohm_ull>(val);
    }

} // namespace potato::units
