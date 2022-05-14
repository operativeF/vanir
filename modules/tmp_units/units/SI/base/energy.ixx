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

    using joule_tag_t = tmp::list_<tmp::list_<meter_l, meter_l, gram_l>, tmp::list_<second_l, second_l>>;

    template<typename T>
    concept JouleC = std::same_as<typename T::impl, joule_tag_t>;

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
        using numer_type = DerivedValueType;
        using impl       = joule_tag_t;

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

    constexpr exajoule_ld operator""_EJ(long double val) {
        return static_cast<exajoule_ld>(val);
    }
    constexpr petajoule_ld operator""_PJ(long double val) {
        return static_cast<petajoule_ld>(val);
    }
    constexpr terajoule_ld operator""_TJ(long double val) {
        return static_cast<terajoule_ld>(val);
    }
    constexpr gigajoule_ld operator""_GJ(long double val) {
        return static_cast<gigajoule_ld>(val);
    }
    constexpr megajoule_ld operator""_MJ(long double val) {
        return static_cast<megajoule_ld>(val);
    }
    constexpr kilojoule_ld operator""_kJ(long double val) {
        return static_cast<kilojoule_ld>(val);
    }
    constexpr hectojoule_ld operator""_hJ(long double val) {
        return static_cast<hectojoule_ld>(val);
    }
    constexpr decajoule_ld operator""_daJ(long double val) {
        return static_cast<decajoule_ld>(val);
    }
    constexpr joule_ld operator""_J(long double val) {
        return static_cast<joule_ld>(val);
    }
    constexpr decijoule_ld operator""_dJ(long double val) {
        return static_cast<decijoule_ld>(val);
    }
    constexpr centijoule_ld operator""_cJ(long double val) {
        return static_cast<centijoule_ld>(val);
    }
    constexpr millijoule_ld operator""_mJ(long double val) {
        return static_cast<millijoule_ld>(val);
    }
    constexpr microjoule_ld operator""_uJ(long double val) {
        return static_cast<microjoule_ld>(val);
    }
    constexpr nanojoule_ld operator""_nJ(long double val) {
        return static_cast<nanojoule_ld>(val);
    }
    constexpr picojoule_ld operator""_pJ(long double val) {
        return static_cast<picojoule_ld>(val);
    }
    constexpr femtojoule_ld operator""_fJ(long double val) {
        return static_cast<femtojoule_ld>(val);
    }
    constexpr attojoule_ld operator""_aJ(long double val) {
        return static_cast<attojoule_ld>(val);
    }
    constexpr exajoule_ull operator""_EJ(unsigned long long val) {
        return static_cast<exajoule_ull>(val);
    }
    constexpr petajoule_ull operator""_PJ(unsigned long long val) {
        return static_cast<petajoule_ull>(val);
    }
    constexpr terajoule_ull operator""_TJ(unsigned long long val) {
        return static_cast<terajoule_ull>(val);
    }
    constexpr gigajoule_ull operator""_GJ(unsigned long long val) {
        return static_cast<gigajoule_ull>(val);
    }
    constexpr megajoule_ull operator""_MJ(unsigned long long val) {
        return static_cast<megajoule_ull>(val);
    }
    constexpr kilojoule_ull operator""_kJ(unsigned long long val) {
        return static_cast<kilojoule_ull>(val);
    }
    constexpr hectojoule_ull operator""_hJ(unsigned long long val) {
        return static_cast<hectojoule_ull>(val);
    }
    constexpr decajoule_ull operator""_daJ(unsigned long long val) {
        return static_cast<decajoule_ull>(val);
    }
    constexpr joule_ull operator""_J(unsigned long long val) {
        return static_cast<joule_ull>(val);
    }
    constexpr decijoule_ull operator""_dJ(unsigned long long val) {
        return static_cast<decijoule_ull>(val);
    }
    constexpr centijoule_ull operator""_cJ(unsigned long long val) {
        return static_cast<centijoule_ull>(val);
    }
    constexpr millijoule_ull operator""_mJ(unsigned long long val) {
        return static_cast<millijoule_ull>(val);
    }
    constexpr microjoule_ull operator""_uJ(unsigned long long val) {
        return static_cast<microjoule_ull>(val);
    }
    constexpr nanojoule_ull operator""_nJ(unsigned long long val) {
        return static_cast<nanojoule_ull>(val);
    }
    constexpr picojoule_ull operator""_pJ(unsigned long long val) {
        return static_cast<picojoule_ull>(val);
    }
    constexpr femtojoule_ull operator""_fJ(unsigned long long val) {
        return static_cast<femtojoule_ull>(val);
    }
    constexpr attojoule_ull operator""_aJ(unsigned long long val) {
        return static_cast<attojoule_ull>(val);
    }

} // namespace potato::units
