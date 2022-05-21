//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Joule_Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using action_tag_t = tmp::list_<Length<std::ratio<2, 1>>,
                                         Time<std::ratio<-1, 1>>,
                                         Mass<std::ratio<1, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept Joule_SecondC = std::same_as<typename T::impl, action_tag_t>;

    template <typename RatioTypeT, typename P>
    struct joule_second_impl {

        static constexpr auto pretty = "J·s";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = action_tag_t;

        constexpr joule_second_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exajoule_second_ld    =     joule_second_impl<std::exa, long double>;
    using petajoule_second_ld    =     joule_second_impl<std::peta, long double>;
    using terajoule_second_ld    =     joule_second_impl<std::tera, long double>;
    using gigajoule_second_ld    =     joule_second_impl<std::giga, long double>;
    using megajoule_second_ld    =     joule_second_impl<std::mega, long double>;
    using kilojoule_second_ld    =     joule_second_impl<std::kilo, long double>;
    using hectojoule_second_ld    =     joule_second_impl<std::hecto, long double>;
    using decajoule_second_ld    =     joule_second_impl<std::deca, long double>;
    using joule_second_ld    =     joule_second_impl<unity_ratio, long double>;
    using decijoule_second_ld    =     joule_second_impl<std::deci, long double>;
    using centijoule_second_ld    =     joule_second_impl<std::centi, long double>;
    using millijoule_second_ld    =     joule_second_impl<std::milli, long double>;
    using microjoule_second_ld    =     joule_second_impl<std::micro, long double>;
    using nanojoule_second_ld    =     joule_second_impl<std::nano, long double>;
    using picojoule_second_ld    =     joule_second_impl<std::pico, long double>;
    using femtojoule_second_ld    =     joule_second_impl<std::femto, long double>;
    using attojoule_second_ld    =     joule_second_impl<std::atto, long double>;
    using exajoule_second_ull    =     joule_second_impl<std::exa, unsigned long long>;
    using petajoule_second_ull    =     joule_second_impl<std::peta, unsigned long long>;
    using terajoule_second_ull    =     joule_second_impl<std::tera, unsigned long long>;
    using gigajoule_second_ull    =     joule_second_impl<std::giga, unsigned long long>;
    using megajoule_second_ull    =     joule_second_impl<std::mega, unsigned long long>;
    using kilojoule_second_ull    =     joule_second_impl<std::kilo, unsigned long long>;
    using hectojoule_second_ull    =     joule_second_impl<std::hecto, unsigned long long>;
    using decajoule_second_ull    =     joule_second_impl<std::deca, unsigned long long>;
    using joule_second_ull    =     joule_second_impl<unity_ratio, unsigned long long>;
    using decijoule_second_ull    =     joule_second_impl<std::deci, unsigned long long>;
    using centijoule_second_ull    =     joule_second_impl<std::centi, unsigned long long>;
    using millijoule_second_ull    =     joule_second_impl<std::milli, unsigned long long>;
    using microjoule_second_ull    =     joule_second_impl<std::micro, unsigned long long>;
    using nanojoule_second_ull    =     joule_second_impl<std::nano, unsigned long long>;
    using picojoule_second_ull    =     joule_second_impl<std::pico, unsigned long long>;
    using femtojoule_second_ull    =     joule_second_impl<std::femto, unsigned long long>;
    using attojoule_second_ull    =     joule_second_impl<std::atto, unsigned long long>;

    consteval exajoule_second_ld operator""_EJ_s(long double val) {
        return static_cast<exajoule_second_ld>(val);
    }
    consteval petajoule_second_ld operator""_PJ_s(long double val) {
        return static_cast<petajoule_second_ld>(val);
    }
    consteval terajoule_second_ld operator""_TJ_s(long double val) {
        return static_cast<terajoule_second_ld>(val);
    }
    consteval gigajoule_second_ld operator""_GJ_s(long double val) {
        return static_cast<gigajoule_second_ld>(val);
    }
    consteval megajoule_second_ld operator""_MJ_s(long double val) {
        return static_cast<megajoule_second_ld>(val);
    }
    consteval kilojoule_second_ld operator""_kJ_s(long double val) {
        return static_cast<kilojoule_second_ld>(val);
    }
    consteval hectojoule_second_ld operator""_hJ_s(long double val) {
        return static_cast<hectojoule_second_ld>(val);
    }
    consteval decajoule_second_ld operator""_daJ_s(long double val) {
        return static_cast<decajoule_second_ld>(val);
    }
    consteval joule_second_ld operator""_J_s(long double val) {
        return static_cast<joule_second_ld>(val);
    }
    consteval decijoule_second_ld operator""_dJ_s(long double val) {
        return static_cast<decijoule_second_ld>(val);
    }
    consteval centijoule_second_ld operator""_cJ_s(long double val) {
        return static_cast<centijoule_second_ld>(val);
    }
    consteval millijoule_second_ld operator""_mJ_s(long double val) {
        return static_cast<millijoule_second_ld>(val);
    }
    consteval microjoule_second_ld operator""_uJ_s(long double val) {
        return static_cast<microjoule_second_ld>(val);
    }
    consteval nanojoule_second_ld operator""_nJ_s(long double val) {
        return static_cast<nanojoule_second_ld>(val);
    }
    consteval picojoule_second_ld operator""_pJ_s(long double val) {
        return static_cast<picojoule_second_ld>(val);
    }
    consteval femtojoule_second_ld operator""_fJ_s(long double val) {
        return static_cast<femtojoule_second_ld>(val);
    }
    consteval attojoule_second_ld operator""_aJ_s(long double val) {
        return static_cast<attojoule_second_ld>(val);
    }
    consteval exajoule_second_ull operator""_EJ_s(unsigned long long val) {
        return static_cast<exajoule_second_ull>(val);
    }
    consteval petajoule_second_ull operator""_PJ_s(unsigned long long val) {
        return static_cast<petajoule_second_ull>(val);
    }
    consteval terajoule_second_ull operator""_TJ_s(unsigned long long val) {
        return static_cast<terajoule_second_ull>(val);
    }
    consteval gigajoule_second_ull operator""_GJ_s(unsigned long long val) {
        return static_cast<gigajoule_second_ull>(val);
    }
    consteval megajoule_second_ull operator""_MJ_s(unsigned long long val) {
        return static_cast<megajoule_second_ull>(val);
    }
    consteval kilojoule_second_ull operator""_kJ_s(unsigned long long val) {
        return static_cast<kilojoule_second_ull>(val);
    }
    consteval hectojoule_second_ull operator""_hJ_s(unsigned long long val) {
        return static_cast<hectojoule_second_ull>(val);
    }
    consteval decajoule_second_ull operator""_daJ_s(unsigned long long val) {
        return static_cast<decajoule_second_ull>(val);
    }
    consteval joule_second_ull operator""_J_s(unsigned long long val) {
        return static_cast<joule_second_ull>(val);
    }
    consteval decijoule_second_ull operator""_dJ_s(unsigned long long val) {
        return static_cast<decijoule_second_ull>(val);
    }
    consteval centijoule_second_ull operator""_cJ_s(unsigned long long val) {
        return static_cast<centijoule_second_ull>(val);
    }
    consteval millijoule_second_ull operator""_mJ_s(unsigned long long val) {
        return static_cast<millijoule_second_ull>(val);
    }
    consteval microjoule_second_ull operator""_uJ_s(unsigned long long val) {
        return static_cast<microjoule_second_ull>(val);
    }
    consteval nanojoule_second_ull operator""_nJ_s(unsigned long long val) {
        return static_cast<nanojoule_second_ull>(val);
    }
    consteval picojoule_second_ull operator""_pJ_s(unsigned long long val) {
        return static_cast<picojoule_second_ull>(val);
    }
    consteval femtojoule_second_ull operator""_fJ_s(unsigned long long val) {
        return static_cast<femtojoule_second_ull>(val);
    }
    consteval attojoule_second_ull operator""_aJ_s(unsigned long long val) {
        return static_cast<attojoule_second_ull>(val);
    }

} // namespace potato::units
