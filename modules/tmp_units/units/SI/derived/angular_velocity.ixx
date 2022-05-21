//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Radian_Per_Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using angular_velocity_tag_t = tmp::list_<Length<std::ratio<0, 1>>,
                                         Time<std::ratio<-1, 1>>,
                                         Mass<std::ratio<0, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<1, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept Radian_Per_SecondC = std::same_as<typename T::impl, angular_velocity_tag_t>;

    template <typename RatioTypeT, typename P>
    struct radian_per_second_impl {

        static constexpr auto pretty = "rad/s";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = angular_velocity_tag_t;

        constexpr radian_per_second_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exaradian_per_second_ld    =     radian_per_second_impl<std::exa, long double>;
    using petaradian_per_second_ld    =     radian_per_second_impl<std::peta, long double>;
    using teraradian_per_second_ld    =     radian_per_second_impl<std::tera, long double>;
    using gigaradian_per_second_ld    =     radian_per_second_impl<std::giga, long double>;
    using megaradian_per_second_ld    =     radian_per_second_impl<std::mega, long double>;
    using kiloradian_per_second_ld    =     radian_per_second_impl<std::kilo, long double>;
    using hectoradian_per_second_ld    =     radian_per_second_impl<std::hecto, long double>;
    using decaradian_per_second_ld    =     radian_per_second_impl<std::deca, long double>;
    using radian_per_second_ld    =     radian_per_second_impl<unity_ratio, long double>;
    using deciradian_per_second_ld    =     radian_per_second_impl<std::deci, long double>;
    using centiradian_per_second_ld    =     radian_per_second_impl<std::centi, long double>;
    using milliradian_per_second_ld    =     radian_per_second_impl<std::milli, long double>;
    using microradian_per_second_ld    =     radian_per_second_impl<std::micro, long double>;
    using nanoradian_per_second_ld    =     radian_per_second_impl<std::nano, long double>;
    using picoradian_per_second_ld    =     radian_per_second_impl<std::pico, long double>;
    using femtoradian_per_second_ld    =     radian_per_second_impl<std::femto, long double>;
    using attoradian_per_second_ld    =     radian_per_second_impl<std::atto, long double>;
    using exaradian_per_second_ull    =     radian_per_second_impl<std::exa, unsigned long long>;
    using petaradian_per_second_ull    =     radian_per_second_impl<std::peta, unsigned long long>;
    using teraradian_per_second_ull    =     radian_per_second_impl<std::tera, unsigned long long>;
    using gigaradian_per_second_ull    =     radian_per_second_impl<std::giga, unsigned long long>;
    using megaradian_per_second_ull    =     radian_per_second_impl<std::mega, unsigned long long>;
    using kiloradian_per_second_ull    =     radian_per_second_impl<std::kilo, unsigned long long>;
    using hectoradian_per_second_ull    =     radian_per_second_impl<std::hecto, unsigned long long>;
    using decaradian_per_second_ull    =     radian_per_second_impl<std::deca, unsigned long long>;
    using radian_per_second_ull    =     radian_per_second_impl<unity_ratio, unsigned long long>;
    using deciradian_per_second_ull    =     radian_per_second_impl<std::deci, unsigned long long>;
    using centiradian_per_second_ull    =     radian_per_second_impl<std::centi, unsigned long long>;
    using milliradian_per_second_ull    =     radian_per_second_impl<std::milli, unsigned long long>;
    using microradian_per_second_ull    =     radian_per_second_impl<std::micro, unsigned long long>;
    using nanoradian_per_second_ull    =     radian_per_second_impl<std::nano, unsigned long long>;
    using picoradian_per_second_ull    =     radian_per_second_impl<std::pico, unsigned long long>;
    using femtoradian_per_second_ull    =     radian_per_second_impl<std::femto, unsigned long long>;
    using attoradian_per_second_ull    =     radian_per_second_impl<std::atto, unsigned long long>;

    consteval exaradian_per_second_ld operator""_Erad_per_s(long double val) {
        return static_cast<exaradian_per_second_ld>(val);
    }
    consteval petaradian_per_second_ld operator""_Prad_per_s(long double val) {
        return static_cast<petaradian_per_second_ld>(val);
    }
    consteval teraradian_per_second_ld operator""_Trad_per_s(long double val) {
        return static_cast<teraradian_per_second_ld>(val);
    }
    consteval gigaradian_per_second_ld operator""_Grad_per_s(long double val) {
        return static_cast<gigaradian_per_second_ld>(val);
    }
    consteval megaradian_per_second_ld operator""_Mrad_per_s(long double val) {
        return static_cast<megaradian_per_second_ld>(val);
    }
    consteval kiloradian_per_second_ld operator""_krad_per_s(long double val) {
        return static_cast<kiloradian_per_second_ld>(val);
    }
    consteval hectoradian_per_second_ld operator""_hrad_per_s(long double val) {
        return static_cast<hectoradian_per_second_ld>(val);
    }
    consteval decaradian_per_second_ld operator""_darad_per_s(long double val) {
        return static_cast<decaradian_per_second_ld>(val);
    }
    consteval radian_per_second_ld operator""_rad_per_s(long double val) {
        return static_cast<radian_per_second_ld>(val);
    }
    consteval deciradian_per_second_ld operator""_drad_per_s(long double val) {
        return static_cast<deciradian_per_second_ld>(val);
    }
    consteval centiradian_per_second_ld operator""_crad_per_s(long double val) {
        return static_cast<centiradian_per_second_ld>(val);
    }
    consteval milliradian_per_second_ld operator""_mrad_per_s(long double val) {
        return static_cast<milliradian_per_second_ld>(val);
    }
    consteval microradian_per_second_ld operator""_urad_per_s(long double val) {
        return static_cast<microradian_per_second_ld>(val);
    }
    consteval nanoradian_per_second_ld operator""_nrad_per_s(long double val) {
        return static_cast<nanoradian_per_second_ld>(val);
    }
    consteval picoradian_per_second_ld operator""_prad_per_s(long double val) {
        return static_cast<picoradian_per_second_ld>(val);
    }
    consteval femtoradian_per_second_ld operator""_frad_per_s(long double val) {
        return static_cast<femtoradian_per_second_ld>(val);
    }
    consteval attoradian_per_second_ld operator""_arad_per_s(long double val) {
        return static_cast<attoradian_per_second_ld>(val);
    }
    consteval exaradian_per_second_ull operator""_Erad_per_s(unsigned long long val) {
        return static_cast<exaradian_per_second_ull>(val);
    }
    consteval petaradian_per_second_ull operator""_Prad_per_s(unsigned long long val) {
        return static_cast<petaradian_per_second_ull>(val);
    }
    consteval teraradian_per_second_ull operator""_Trad_per_s(unsigned long long val) {
        return static_cast<teraradian_per_second_ull>(val);
    }
    consteval gigaradian_per_second_ull operator""_Grad_per_s(unsigned long long val) {
        return static_cast<gigaradian_per_second_ull>(val);
    }
    consteval megaradian_per_second_ull operator""_Mrad_per_s(unsigned long long val) {
        return static_cast<megaradian_per_second_ull>(val);
    }
    consteval kiloradian_per_second_ull operator""_krad_per_s(unsigned long long val) {
        return static_cast<kiloradian_per_second_ull>(val);
    }
    consteval hectoradian_per_second_ull operator""_hrad_per_s(unsigned long long val) {
        return static_cast<hectoradian_per_second_ull>(val);
    }
    consteval decaradian_per_second_ull operator""_darad_per_s(unsigned long long val) {
        return static_cast<decaradian_per_second_ull>(val);
    }
    consteval radian_per_second_ull operator""_rad_per_s(unsigned long long val) {
        return static_cast<radian_per_second_ull>(val);
    }
    consteval deciradian_per_second_ull operator""_drad_per_s(unsigned long long val) {
        return static_cast<deciradian_per_second_ull>(val);
    }
    consteval centiradian_per_second_ull operator""_crad_per_s(unsigned long long val) {
        return static_cast<centiradian_per_second_ull>(val);
    }
    consteval milliradian_per_second_ull operator""_mrad_per_s(unsigned long long val) {
        return static_cast<milliradian_per_second_ull>(val);
    }
    consteval microradian_per_second_ull operator""_urad_per_s(unsigned long long val) {
        return static_cast<microradian_per_second_ull>(val);
    }
    consteval nanoradian_per_second_ull operator""_nrad_per_s(unsigned long long val) {
        return static_cast<nanoradian_per_second_ull>(val);
    }
    consteval picoradian_per_second_ull operator""_prad_per_s(unsigned long long val) {
        return static_cast<picoradian_per_second_ull>(val);
    }
    consteval femtoradian_per_second_ull operator""_frad_per_s(unsigned long long val) {
        return static_cast<femtoradian_per_second_ull>(val);
    }
    consteval attoradian_per_second_ull operator""_arad_per_s(unsigned long long val) {
        return static_cast<attoradian_per_second_ull>(val);
    }

} // namespace potato::units
