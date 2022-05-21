//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Joule;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using energy_tag_t = tmp::list_<Length<std::ratio<2, 1>>,
                                         Time<std::ratio<-2, 1>>,
                                         Mass<std::ratio<1, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept JouleC = std::same_as<typename T::impl, energy_tag_t>;

    template <typename RatioTypeT, typename P>
    struct joule_impl {

        static constexpr auto pretty = "J";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = energy_tag_t;

        constexpr joule_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exajoule_ld    =     joule_impl<std::exa, long double>;
    using petajoule_ld    =     joule_impl<std::peta, long double>;
    using terajoule_ld    =     joule_impl<std::tera, long double>;
    using gigajoule_ld    =     joule_impl<std::giga, long double>;
    using megajoule_ld    =     joule_impl<std::mega, long double>;
    using kilojoule_ld    =     joule_impl<std::kilo, long double>;
    using hectojoule_ld    =     joule_impl<std::hecto, long double>;
    using decajoule_ld    =     joule_impl<std::deca, long double>;
    using joule_ld    =     joule_impl<unity_ratio, long double>;
    using decijoule_ld    =     joule_impl<std::deci, long double>;
    using centijoule_ld    =     joule_impl<std::centi, long double>;
    using millijoule_ld    =     joule_impl<std::milli, long double>;
    using microjoule_ld    =     joule_impl<std::micro, long double>;
    using nanojoule_ld    =     joule_impl<std::nano, long double>;
    using picojoule_ld    =     joule_impl<std::pico, long double>;
    using femtojoule_ld    =     joule_impl<std::femto, long double>;
    using attojoule_ld    =     joule_impl<std::atto, long double>;
    using exajoule_ull    =     joule_impl<std::exa, unsigned long long>;
    using petajoule_ull    =     joule_impl<std::peta, unsigned long long>;
    using terajoule_ull    =     joule_impl<std::tera, unsigned long long>;
    using gigajoule_ull    =     joule_impl<std::giga, unsigned long long>;
    using megajoule_ull    =     joule_impl<std::mega, unsigned long long>;
    using kilojoule_ull    =     joule_impl<std::kilo, unsigned long long>;
    using hectojoule_ull    =     joule_impl<std::hecto, unsigned long long>;
    using decajoule_ull    =     joule_impl<std::deca, unsigned long long>;
    using joule_ull    =     joule_impl<unity_ratio, unsigned long long>;
    using decijoule_ull    =     joule_impl<std::deci, unsigned long long>;
    using centijoule_ull    =     joule_impl<std::centi, unsigned long long>;
    using millijoule_ull    =     joule_impl<std::milli, unsigned long long>;
    using microjoule_ull    =     joule_impl<std::micro, unsigned long long>;
    using nanojoule_ull    =     joule_impl<std::nano, unsigned long long>;
    using picojoule_ull    =     joule_impl<std::pico, unsigned long long>;
    using femtojoule_ull    =     joule_impl<std::femto, unsigned long long>;
    using attojoule_ull    =     joule_impl<std::atto, unsigned long long>;

    consteval exajoule_ld operator""_EJ(long double val) {
        return static_cast<exajoule_ld>(val);
    }
    consteval petajoule_ld operator""_PJ(long double val) {
        return static_cast<petajoule_ld>(val);
    }
    consteval terajoule_ld operator""_TJ(long double val) {
        return static_cast<terajoule_ld>(val);
    }
    consteval gigajoule_ld operator""_GJ(long double val) {
        return static_cast<gigajoule_ld>(val);
    }
    consteval megajoule_ld operator""_MJ(long double val) {
        return static_cast<megajoule_ld>(val);
    }
    consteval kilojoule_ld operator""_kJ(long double val) {
        return static_cast<kilojoule_ld>(val);
    }
    consteval hectojoule_ld operator""_hJ(long double val) {
        return static_cast<hectojoule_ld>(val);
    }
    consteval decajoule_ld operator""_daJ(long double val) {
        return static_cast<decajoule_ld>(val);
    }
    consteval joule_ld operator""_J(long double val) {
        return static_cast<joule_ld>(val);
    }
    consteval decijoule_ld operator""_dJ(long double val) {
        return static_cast<decijoule_ld>(val);
    }
    consteval centijoule_ld operator""_cJ(long double val) {
        return static_cast<centijoule_ld>(val);
    }
    consteval millijoule_ld operator""_mJ(long double val) {
        return static_cast<millijoule_ld>(val);
    }
    consteval microjoule_ld operator""_uJ(long double val) {
        return static_cast<microjoule_ld>(val);
    }
    consteval nanojoule_ld operator""_nJ(long double val) {
        return static_cast<nanojoule_ld>(val);
    }
    consteval picojoule_ld operator""_pJ(long double val) {
        return static_cast<picojoule_ld>(val);
    }
    consteval femtojoule_ld operator""_fJ(long double val) {
        return static_cast<femtojoule_ld>(val);
    }
    consteval attojoule_ld operator""_aJ(long double val) {
        return static_cast<attojoule_ld>(val);
    }
    consteval exajoule_ull operator""_EJ(unsigned long long val) {
        return static_cast<exajoule_ull>(val);
    }
    consteval petajoule_ull operator""_PJ(unsigned long long val) {
        return static_cast<petajoule_ull>(val);
    }
    consteval terajoule_ull operator""_TJ(unsigned long long val) {
        return static_cast<terajoule_ull>(val);
    }
    consteval gigajoule_ull operator""_GJ(unsigned long long val) {
        return static_cast<gigajoule_ull>(val);
    }
    consteval megajoule_ull operator""_MJ(unsigned long long val) {
        return static_cast<megajoule_ull>(val);
    }
    consteval kilojoule_ull operator""_kJ(unsigned long long val) {
        return static_cast<kilojoule_ull>(val);
    }
    consteval hectojoule_ull operator""_hJ(unsigned long long val) {
        return static_cast<hectojoule_ull>(val);
    }
    consteval decajoule_ull operator""_daJ(unsigned long long val) {
        return static_cast<decajoule_ull>(val);
    }
    consteval joule_ull operator""_J(unsigned long long val) {
        return static_cast<joule_ull>(val);
    }
    consteval decijoule_ull operator""_dJ(unsigned long long val) {
        return static_cast<decijoule_ull>(val);
    }
    consteval centijoule_ull operator""_cJ(unsigned long long val) {
        return static_cast<centijoule_ull>(val);
    }
    consteval millijoule_ull operator""_mJ(unsigned long long val) {
        return static_cast<millijoule_ull>(val);
    }
    consteval microjoule_ull operator""_uJ(unsigned long long val) {
        return static_cast<microjoule_ull>(val);
    }
    consteval nanojoule_ull operator""_nJ(unsigned long long val) {
        return static_cast<nanojoule_ull>(val);
    }
    consteval picojoule_ull operator""_pJ(unsigned long long val) {
        return static_cast<picojoule_ull>(val);
    }
    consteval femtojoule_ull operator""_fJ(unsigned long long val) {
        return static_cast<femtojoule_ull>(val);
    }
    consteval attojoule_ull operator""_aJ(unsigned long long val) {
        return static_cast<attojoule_ull>(val);
    }

} // namespace potato::units
