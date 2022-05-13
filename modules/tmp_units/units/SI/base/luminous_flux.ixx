//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Lumen;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

export namespace potato::units {
    namespace tmp = boost::tmp;

    template <typename RatioTypeT, typename P>
    struct lumen_impl {

        static constexpr auto pretty = "lm";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = tmp::list_<tmp::list_<candela_l, steradian_l>, tmp::list_<>>;

        constexpr lumen_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exalumen_ld    =     lumen_impl<std::exa, long double>;
    using petalumen_ld    =     lumen_impl<std::peta, long double>;
    using teralumen_ld    =     lumen_impl<std::tera, long double>;
    using gigalumen_ld    =     lumen_impl<std::giga, long double>;
    using megalumen_ld    =     lumen_impl<std::mega, long double>;
    using kilolumen_ld    =     lumen_impl<std::kilo, long double>;
    using hectolumen_ld    =     lumen_impl<std::hecto, long double>;
    using decalumen_ld    =     lumen_impl<std::deca, long double>;
    using lumen_ld    =     lumen_impl<unity_ratio, long double>;
    using decilumen_ld    =     lumen_impl<std::deci, long double>;
    using centilumen_ld    =     lumen_impl<std::centi, long double>;
    using millilumen_ld    =     lumen_impl<std::milli, long double>;
    using microlumen_ld    =     lumen_impl<std::micro, long double>;
    using nanolumen_ld    =     lumen_impl<std::nano, long double>;
    using picolumen_ld    =     lumen_impl<std::pico, long double>;
    using femtolumen_ld    =     lumen_impl<std::femto, long double>;
    using attolumen_ld    =     lumen_impl<std::atto, long double>;
    using exalumen_ull    =     lumen_impl<std::exa, unsigned long long>;
    using petalumen_ull    =     lumen_impl<std::peta, unsigned long long>;
    using teralumen_ull    =     lumen_impl<std::tera, unsigned long long>;
    using gigalumen_ull    =     lumen_impl<std::giga, unsigned long long>;
    using megalumen_ull    =     lumen_impl<std::mega, unsigned long long>;
    using kilolumen_ull    =     lumen_impl<std::kilo, unsigned long long>;
    using hectolumen_ull    =     lumen_impl<std::hecto, unsigned long long>;
    using decalumen_ull    =     lumen_impl<std::deca, unsigned long long>;
    using lumen_ull    =     lumen_impl<unity_ratio, unsigned long long>;
    using decilumen_ull    =     lumen_impl<std::deci, unsigned long long>;
    using centilumen_ull    =     lumen_impl<std::centi, unsigned long long>;
    using millilumen_ull    =     lumen_impl<std::milli, unsigned long long>;
    using microlumen_ull    =     lumen_impl<std::micro, unsigned long long>;
    using nanolumen_ull    =     lumen_impl<std::nano, unsigned long long>;
    using picolumen_ull    =     lumen_impl<std::pico, unsigned long long>;
    using femtolumen_ull    =     lumen_impl<std::femto, unsigned long long>;
    using attolumen_ull    =     lumen_impl<std::atto, unsigned long long>;

    constexpr exalumen_ld operator""_Elm(long double val) {
        return static_cast<exalumen_ld>(val);
    }
    constexpr petalumen_ld operator""_Plm(long double val) {
        return static_cast<petalumen_ld>(val);
    }
    constexpr teralumen_ld operator""_Tlm(long double val) {
        return static_cast<teralumen_ld>(val);
    }
    constexpr gigalumen_ld operator""_Glm(long double val) {
        return static_cast<gigalumen_ld>(val);
    }
    constexpr megalumen_ld operator""_Mlm(long double val) {
        return static_cast<megalumen_ld>(val);
    }
    constexpr kilolumen_ld operator""_klm(long double val) {
        return static_cast<kilolumen_ld>(val);
    }
    constexpr hectolumen_ld operator""_hlm(long double val) {
        return static_cast<hectolumen_ld>(val);
    }
    constexpr decalumen_ld operator""_dalm(long double val) {
        return static_cast<decalumen_ld>(val);
    }
    constexpr lumen_ld operator""_lm(long double val) {
        return static_cast<lumen_ld>(val);
    }
    constexpr decilumen_ld operator""_dlm(long double val) {
        return static_cast<decilumen_ld>(val);
    }
    constexpr centilumen_ld operator""_clm(long double val) {
        return static_cast<centilumen_ld>(val);
    }
    constexpr millilumen_ld operator""_mlm(long double val) {
        return static_cast<millilumen_ld>(val);
    }
    constexpr microlumen_ld operator""_ulm(long double val) {
        return static_cast<microlumen_ld>(val);
    }
    constexpr nanolumen_ld operator""_nlm(long double val) {
        return static_cast<nanolumen_ld>(val);
    }
    constexpr picolumen_ld operator""_plm(long double val) {
        return static_cast<picolumen_ld>(val);
    }
    constexpr femtolumen_ld operator""_flm(long double val) {
        return static_cast<femtolumen_ld>(val);
    }
    constexpr attolumen_ld operator""_alm(long double val) {
        return static_cast<attolumen_ld>(val);
    }
    constexpr exalumen_ull operator""_Elm(unsigned long long val) {
        return static_cast<exalumen_ull>(val);
    }
    constexpr petalumen_ull operator""_Plm(unsigned long long val) {
        return static_cast<petalumen_ull>(val);
    }
    constexpr teralumen_ull operator""_Tlm(unsigned long long val) {
        return static_cast<teralumen_ull>(val);
    }
    constexpr gigalumen_ull operator""_Glm(unsigned long long val) {
        return static_cast<gigalumen_ull>(val);
    }
    constexpr megalumen_ull operator""_Mlm(unsigned long long val) {
        return static_cast<megalumen_ull>(val);
    }
    constexpr kilolumen_ull operator""_klm(unsigned long long val) {
        return static_cast<kilolumen_ull>(val);
    }
    constexpr hectolumen_ull operator""_hlm(unsigned long long val) {
        return static_cast<hectolumen_ull>(val);
    }
    constexpr decalumen_ull operator""_dalm(unsigned long long val) {
        return static_cast<decalumen_ull>(val);
    }
    constexpr lumen_ull operator""_lm(unsigned long long val) {
        return static_cast<lumen_ull>(val);
    }
    constexpr decilumen_ull operator""_dlm(unsigned long long val) {
        return static_cast<decilumen_ull>(val);
    }
    constexpr centilumen_ull operator""_clm(unsigned long long val) {
        return static_cast<centilumen_ull>(val);
    }
    constexpr millilumen_ull operator""_mlm(unsigned long long val) {
        return static_cast<millilumen_ull>(val);
    }
    constexpr microlumen_ull operator""_ulm(unsigned long long val) {
        return static_cast<microlumen_ull>(val);
    }
    constexpr nanolumen_ull operator""_nlm(unsigned long long val) {
        return static_cast<nanolumen_ull>(val);
    }
    constexpr picolumen_ull operator""_plm(unsigned long long val) {
        return static_cast<picolumen_ull>(val);
    }
    constexpr femtolumen_ull operator""_flm(unsigned long long val) {
        return static_cast<femtolumen_ull>(val);
    }
    constexpr attolumen_ull operator""_alm(unsigned long long val) {
        return static_cast<attolumen_ull>(val);
    }

} // namespace potato::units
