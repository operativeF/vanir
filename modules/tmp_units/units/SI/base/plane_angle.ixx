//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Radian;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using radian_tag_t = tmp::list_<tmp::list_<radian_l>, tmp::list_<>>;

    template<typename T>
    concept RadianC = std::same_as<typename T::impl, radian_tag_t>;

    template <typename RatioTypeT, typename P>
    struct radian_impl {

        static constexpr auto pretty = "rad";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = radian_tag_t;

        constexpr radian_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exaradian_ld    =     radian_impl<std::exa, long double>;
    using petaradian_ld    =     radian_impl<std::peta, long double>;
    using teraradian_ld    =     radian_impl<std::tera, long double>;
    using gigaradian_ld    =     radian_impl<std::giga, long double>;
    using megaradian_ld    =     radian_impl<std::mega, long double>;
    using kiloradian_ld    =     radian_impl<std::kilo, long double>;
    using hectoradian_ld    =     radian_impl<std::hecto, long double>;
    using decaradian_ld    =     radian_impl<std::deca, long double>;
    using radian_ld    =     radian_impl<unity_ratio, long double>;
    using deciradian_ld    =     radian_impl<std::deci, long double>;
    using centiradian_ld    =     radian_impl<std::centi, long double>;
    using milliradian_ld    =     radian_impl<std::milli, long double>;
    using microradian_ld    =     radian_impl<std::micro, long double>;
    using nanoradian_ld    =     radian_impl<std::nano, long double>;
    using picoradian_ld    =     radian_impl<std::pico, long double>;
    using femtoradian_ld    =     radian_impl<std::femto, long double>;
    using attoradian_ld    =     radian_impl<std::atto, long double>;
    using exaradian_ull    =     radian_impl<std::exa, unsigned long long>;
    using petaradian_ull    =     radian_impl<std::peta, unsigned long long>;
    using teraradian_ull    =     radian_impl<std::tera, unsigned long long>;
    using gigaradian_ull    =     radian_impl<std::giga, unsigned long long>;
    using megaradian_ull    =     radian_impl<std::mega, unsigned long long>;
    using kiloradian_ull    =     radian_impl<std::kilo, unsigned long long>;
    using hectoradian_ull    =     radian_impl<std::hecto, unsigned long long>;
    using decaradian_ull    =     radian_impl<std::deca, unsigned long long>;
    using radian_ull    =     radian_impl<unity_ratio, unsigned long long>;
    using deciradian_ull    =     radian_impl<std::deci, unsigned long long>;
    using centiradian_ull    =     radian_impl<std::centi, unsigned long long>;
    using milliradian_ull    =     radian_impl<std::milli, unsigned long long>;
    using microradian_ull    =     radian_impl<std::micro, unsigned long long>;
    using nanoradian_ull    =     radian_impl<std::nano, unsigned long long>;
    using picoradian_ull    =     radian_impl<std::pico, unsigned long long>;
    using femtoradian_ull    =     radian_impl<std::femto, unsigned long long>;
    using attoradian_ull    =     radian_impl<std::atto, unsigned long long>;

    constexpr exaradian_ld operator""_Erad(long double val) {
        return static_cast<exaradian_ld>(val);
    }
    constexpr petaradian_ld operator""_Prad(long double val) {
        return static_cast<petaradian_ld>(val);
    }
    constexpr teraradian_ld operator""_Trad(long double val) {
        return static_cast<teraradian_ld>(val);
    }
    constexpr gigaradian_ld operator""_Grad(long double val) {
        return static_cast<gigaradian_ld>(val);
    }
    constexpr megaradian_ld operator""_Mrad(long double val) {
        return static_cast<megaradian_ld>(val);
    }
    constexpr kiloradian_ld operator""_krad(long double val) {
        return static_cast<kiloradian_ld>(val);
    }
    constexpr hectoradian_ld operator""_hrad(long double val) {
        return static_cast<hectoradian_ld>(val);
    }
    constexpr decaradian_ld operator""_darad(long double val) {
        return static_cast<decaradian_ld>(val);
    }
    constexpr radian_ld operator""_rad(long double val) {
        return static_cast<radian_ld>(val);
    }
    constexpr deciradian_ld operator""_drad(long double val) {
        return static_cast<deciradian_ld>(val);
    }
    constexpr centiradian_ld operator""_crad(long double val) {
        return static_cast<centiradian_ld>(val);
    }
    constexpr milliradian_ld operator""_mrad(long double val) {
        return static_cast<milliradian_ld>(val);
    }
    constexpr microradian_ld operator""_urad(long double val) {
        return static_cast<microradian_ld>(val);
    }
    constexpr nanoradian_ld operator""_nrad(long double val) {
        return static_cast<nanoradian_ld>(val);
    }
    constexpr picoradian_ld operator""_prad(long double val) {
        return static_cast<picoradian_ld>(val);
    }
    constexpr femtoradian_ld operator""_frad(long double val) {
        return static_cast<femtoradian_ld>(val);
    }
    constexpr attoradian_ld operator""_arad(long double val) {
        return static_cast<attoradian_ld>(val);
    }
    constexpr exaradian_ull operator""_Erad(unsigned long long val) {
        return static_cast<exaradian_ull>(val);
    }
    constexpr petaradian_ull operator""_Prad(unsigned long long val) {
        return static_cast<petaradian_ull>(val);
    }
    constexpr teraradian_ull operator""_Trad(unsigned long long val) {
        return static_cast<teraradian_ull>(val);
    }
    constexpr gigaradian_ull operator""_Grad(unsigned long long val) {
        return static_cast<gigaradian_ull>(val);
    }
    constexpr megaradian_ull operator""_Mrad(unsigned long long val) {
        return static_cast<megaradian_ull>(val);
    }
    constexpr kiloradian_ull operator""_krad(unsigned long long val) {
        return static_cast<kiloradian_ull>(val);
    }
    constexpr hectoradian_ull operator""_hrad(unsigned long long val) {
        return static_cast<hectoradian_ull>(val);
    }
    constexpr decaradian_ull operator""_darad(unsigned long long val) {
        return static_cast<decaradian_ull>(val);
    }
    constexpr radian_ull operator""_rad(unsigned long long val) {
        return static_cast<radian_ull>(val);
    }
    constexpr deciradian_ull operator""_drad(unsigned long long val) {
        return static_cast<deciradian_ull>(val);
    }
    constexpr centiradian_ull operator""_crad(unsigned long long val) {
        return static_cast<centiradian_ull>(val);
    }
    constexpr milliradian_ull operator""_mrad(unsigned long long val) {
        return static_cast<milliradian_ull>(val);
    }
    constexpr microradian_ull operator""_urad(unsigned long long val) {
        return static_cast<microradian_ull>(val);
    }
    constexpr nanoradian_ull operator""_nrad(unsigned long long val) {
        return static_cast<nanoradian_ull>(val);
    }
    constexpr picoradian_ull operator""_prad(unsigned long long val) {
        return static_cast<picoradian_ull>(val);
    }
    constexpr femtoradian_ull operator""_frad(unsigned long long val) {
        return static_cast<femtoradian_ull>(val);
    }
    constexpr attoradian_ull operator""_arad(unsigned long long val) {
        return static_cast<attoradian_ull>(val);
    }

} // namespace potato::units
