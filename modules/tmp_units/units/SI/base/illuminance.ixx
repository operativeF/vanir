//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Lux;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using lux_tag_t = tmp::list_<tmp::list_<candela_l>, tmp::list_<meter_l, meter_l>>;

    template<typename T>
    concept LuxC = std::same_as<typename T::impl, lux_tag_t>;

    template <typename RatioTypeT, typename P>
    struct lux_impl {

        static constexpr auto pretty = "lx";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = lux_tag_t;

        constexpr lux_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exalux_ld    =     lux_impl<std::exa, long double>;
    using petalux_ld    =     lux_impl<std::peta, long double>;
    using teralux_ld    =     lux_impl<std::tera, long double>;
    using gigalux_ld    =     lux_impl<std::giga, long double>;
    using megalux_ld    =     lux_impl<std::mega, long double>;
    using kilolux_ld    =     lux_impl<std::kilo, long double>;
    using hectolux_ld    =     lux_impl<std::hecto, long double>;
    using decalux_ld    =     lux_impl<std::deca, long double>;
    using lux_ld    =     lux_impl<unity_ratio, long double>;
    using decilux_ld    =     lux_impl<std::deci, long double>;
    using centilux_ld    =     lux_impl<std::centi, long double>;
    using millilux_ld    =     lux_impl<std::milli, long double>;
    using microlux_ld    =     lux_impl<std::micro, long double>;
    using nanolux_ld    =     lux_impl<std::nano, long double>;
    using picolux_ld    =     lux_impl<std::pico, long double>;
    using femtolux_ld    =     lux_impl<std::femto, long double>;
    using attolux_ld    =     lux_impl<std::atto, long double>;
    using exalux_ull    =     lux_impl<std::exa, unsigned long long>;
    using petalux_ull    =     lux_impl<std::peta, unsigned long long>;
    using teralux_ull    =     lux_impl<std::tera, unsigned long long>;
    using gigalux_ull    =     lux_impl<std::giga, unsigned long long>;
    using megalux_ull    =     lux_impl<std::mega, unsigned long long>;
    using kilolux_ull    =     lux_impl<std::kilo, unsigned long long>;
    using hectolux_ull    =     lux_impl<std::hecto, unsigned long long>;
    using decalux_ull    =     lux_impl<std::deca, unsigned long long>;
    using lux_ull    =     lux_impl<unity_ratio, unsigned long long>;
    using decilux_ull    =     lux_impl<std::deci, unsigned long long>;
    using centilux_ull    =     lux_impl<std::centi, unsigned long long>;
    using millilux_ull    =     lux_impl<std::milli, unsigned long long>;
    using microlux_ull    =     lux_impl<std::micro, unsigned long long>;
    using nanolux_ull    =     lux_impl<std::nano, unsigned long long>;
    using picolux_ull    =     lux_impl<std::pico, unsigned long long>;
    using femtolux_ull    =     lux_impl<std::femto, unsigned long long>;
    using attolux_ull    =     lux_impl<std::atto, unsigned long long>;

    constexpr exalux_ld operator""_Elx(long double val) {
        return static_cast<exalux_ld>(val);
    }
    constexpr petalux_ld operator""_Plx(long double val) {
        return static_cast<petalux_ld>(val);
    }
    constexpr teralux_ld operator""_Tlx(long double val) {
        return static_cast<teralux_ld>(val);
    }
    constexpr gigalux_ld operator""_Glx(long double val) {
        return static_cast<gigalux_ld>(val);
    }
    constexpr megalux_ld operator""_Mlx(long double val) {
        return static_cast<megalux_ld>(val);
    }
    constexpr kilolux_ld operator""_klx(long double val) {
        return static_cast<kilolux_ld>(val);
    }
    constexpr hectolux_ld operator""_hlx(long double val) {
        return static_cast<hectolux_ld>(val);
    }
    constexpr decalux_ld operator""_dalx(long double val) {
        return static_cast<decalux_ld>(val);
    }
    constexpr lux_ld operator""_lx(long double val) {
        return static_cast<lux_ld>(val);
    }
    constexpr decilux_ld operator""_dlx(long double val) {
        return static_cast<decilux_ld>(val);
    }
    constexpr centilux_ld operator""_clx(long double val) {
        return static_cast<centilux_ld>(val);
    }
    constexpr millilux_ld operator""_mlx(long double val) {
        return static_cast<millilux_ld>(val);
    }
    constexpr microlux_ld operator""_ulx(long double val) {
        return static_cast<microlux_ld>(val);
    }
    constexpr nanolux_ld operator""_nlx(long double val) {
        return static_cast<nanolux_ld>(val);
    }
    constexpr picolux_ld operator""_plx(long double val) {
        return static_cast<picolux_ld>(val);
    }
    constexpr femtolux_ld operator""_flx(long double val) {
        return static_cast<femtolux_ld>(val);
    }
    constexpr attolux_ld operator""_alx(long double val) {
        return static_cast<attolux_ld>(val);
    }
    constexpr exalux_ull operator""_Elx(unsigned long long val) {
        return static_cast<exalux_ull>(val);
    }
    constexpr petalux_ull operator""_Plx(unsigned long long val) {
        return static_cast<petalux_ull>(val);
    }
    constexpr teralux_ull operator""_Tlx(unsigned long long val) {
        return static_cast<teralux_ull>(val);
    }
    constexpr gigalux_ull operator""_Glx(unsigned long long val) {
        return static_cast<gigalux_ull>(val);
    }
    constexpr megalux_ull operator""_Mlx(unsigned long long val) {
        return static_cast<megalux_ull>(val);
    }
    constexpr kilolux_ull operator""_klx(unsigned long long val) {
        return static_cast<kilolux_ull>(val);
    }
    constexpr hectolux_ull operator""_hlx(unsigned long long val) {
        return static_cast<hectolux_ull>(val);
    }
    constexpr decalux_ull operator""_dalx(unsigned long long val) {
        return static_cast<decalux_ull>(val);
    }
    constexpr lux_ull operator""_lx(unsigned long long val) {
        return static_cast<lux_ull>(val);
    }
    constexpr decilux_ull operator""_dlx(unsigned long long val) {
        return static_cast<decilux_ull>(val);
    }
    constexpr centilux_ull operator""_clx(unsigned long long val) {
        return static_cast<centilux_ull>(val);
    }
    constexpr millilux_ull operator""_mlx(unsigned long long val) {
        return static_cast<millilux_ull>(val);
    }
    constexpr microlux_ull operator""_ulx(unsigned long long val) {
        return static_cast<microlux_ull>(val);
    }
    constexpr nanolux_ull operator""_nlx(unsigned long long val) {
        return static_cast<nanolux_ull>(val);
    }
    constexpr picolux_ull operator""_plx(unsigned long long val) {
        return static_cast<picolux_ull>(val);
    }
    constexpr femtolux_ull operator""_flx(unsigned long long val) {
        return static_cast<femtolux_ull>(val);
    }
    constexpr attolux_ull operator""_alx(unsigned long long val) {
        return static_cast<attolux_ull>(val);
    }

} // namespace potato::units