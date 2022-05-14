//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Lux_Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using lux_second_tag_t = tmp::list_<tmp::list_<second_l, candela_l>, tmp::list_<meter_l, meter_l>>;

    template<typename T>
    concept Lux_SecondC = std::same_as<typename T::impl, lux_second_tag_t>;

    template <typename RatioTypeT, typename P>
    struct lux_second_impl {

        static constexpr auto pretty = "s·cd/m²";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = lux_second_tag_t;

        constexpr lux_second_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exalux_second_ld    =     lux_second_impl<std::exa, long double>;
    using petalux_second_ld    =     lux_second_impl<std::peta, long double>;
    using teralux_second_ld    =     lux_second_impl<std::tera, long double>;
    using gigalux_second_ld    =     lux_second_impl<std::giga, long double>;
    using megalux_second_ld    =     lux_second_impl<std::mega, long double>;
    using kilolux_second_ld    =     lux_second_impl<std::kilo, long double>;
    using hectolux_second_ld    =     lux_second_impl<std::hecto, long double>;
    using decalux_second_ld    =     lux_second_impl<std::deca, long double>;
    using lux_second_ld    =     lux_second_impl<unity_ratio, long double>;
    using decilux_second_ld    =     lux_second_impl<std::deci, long double>;
    using centilux_second_ld    =     lux_second_impl<std::centi, long double>;
    using millilux_second_ld    =     lux_second_impl<std::milli, long double>;
    using microlux_second_ld    =     lux_second_impl<std::micro, long double>;
    using nanolux_second_ld    =     lux_second_impl<std::nano, long double>;
    using picolux_second_ld    =     lux_second_impl<std::pico, long double>;
    using femtolux_second_ld    =     lux_second_impl<std::femto, long double>;
    using attolux_second_ld    =     lux_second_impl<std::atto, long double>;
    using exalux_second_ull    =     lux_second_impl<std::exa, unsigned long long>;
    using petalux_second_ull    =     lux_second_impl<std::peta, unsigned long long>;
    using teralux_second_ull    =     lux_second_impl<std::tera, unsigned long long>;
    using gigalux_second_ull    =     lux_second_impl<std::giga, unsigned long long>;
    using megalux_second_ull    =     lux_second_impl<std::mega, unsigned long long>;
    using kilolux_second_ull    =     lux_second_impl<std::kilo, unsigned long long>;
    using hectolux_second_ull    =     lux_second_impl<std::hecto, unsigned long long>;
    using decalux_second_ull    =     lux_second_impl<std::deca, unsigned long long>;
    using lux_second_ull    =     lux_second_impl<unity_ratio, unsigned long long>;
    using decilux_second_ull    =     lux_second_impl<std::deci, unsigned long long>;
    using centilux_second_ull    =     lux_second_impl<std::centi, unsigned long long>;
    using millilux_second_ull    =     lux_second_impl<std::milli, unsigned long long>;
    using microlux_second_ull    =     lux_second_impl<std::micro, unsigned long long>;
    using nanolux_second_ull    =     lux_second_impl<std::nano, unsigned long long>;
    using picolux_second_ull    =     lux_second_impl<std::pico, unsigned long long>;
    using femtolux_second_ull    =     lux_second_impl<std::femto, unsigned long long>;
    using attolux_second_ull    =     lux_second_impl<std::atto, unsigned long long>;

    constexpr exalux_second_ld operator""_Es_cd_per_sq_m(long double val) {
        return static_cast<exalux_second_ld>(val);
    }
    constexpr petalux_second_ld operator""_Ps_cd_per_sq_m(long double val) {
        return static_cast<petalux_second_ld>(val);
    }
    constexpr teralux_second_ld operator""_Ts_cd_per_sq_m(long double val) {
        return static_cast<teralux_second_ld>(val);
    }
    constexpr gigalux_second_ld operator""_Gs_cd_per_sq_m(long double val) {
        return static_cast<gigalux_second_ld>(val);
    }
    constexpr megalux_second_ld operator""_Ms_cd_per_sq_m(long double val) {
        return static_cast<megalux_second_ld>(val);
    }
    constexpr kilolux_second_ld operator""_ks_cd_per_sq_m(long double val) {
        return static_cast<kilolux_second_ld>(val);
    }
    constexpr hectolux_second_ld operator""_hs_cd_per_sq_m(long double val) {
        return static_cast<hectolux_second_ld>(val);
    }
    constexpr decalux_second_ld operator""_das_cd_per_sq_m(long double val) {
        return static_cast<decalux_second_ld>(val);
    }
    constexpr lux_second_ld operator""_s_cd_per_sq_m(long double val) {
        return static_cast<lux_second_ld>(val);
    }
    constexpr decilux_second_ld operator""_ds_cd_per_sq_m(long double val) {
        return static_cast<decilux_second_ld>(val);
    }
    constexpr centilux_second_ld operator""_cs_cd_per_sq_m(long double val) {
        return static_cast<centilux_second_ld>(val);
    }
    constexpr millilux_second_ld operator""_ms_cd_per_sq_m(long double val) {
        return static_cast<millilux_second_ld>(val);
    }
    constexpr microlux_second_ld operator""_us_cd_per_sq_m(long double val) {
        return static_cast<microlux_second_ld>(val);
    }
    constexpr nanolux_second_ld operator""_ns_cd_per_sq_m(long double val) {
        return static_cast<nanolux_second_ld>(val);
    }
    constexpr picolux_second_ld operator""_ps_cd_per_sq_m(long double val) {
        return static_cast<picolux_second_ld>(val);
    }
    constexpr femtolux_second_ld operator""_fs_cd_per_sq_m(long double val) {
        return static_cast<femtolux_second_ld>(val);
    }
    constexpr attolux_second_ld operator""_as_cd_per_sq_m(long double val) {
        return static_cast<attolux_second_ld>(val);
    }
    constexpr exalux_second_ull operator""_Es_cd_per_sq_m(unsigned long long val) {
        return static_cast<exalux_second_ull>(val);
    }
    constexpr petalux_second_ull operator""_Ps_cd_per_sq_m(unsigned long long val) {
        return static_cast<petalux_second_ull>(val);
    }
    constexpr teralux_second_ull operator""_Ts_cd_per_sq_m(unsigned long long val) {
        return static_cast<teralux_second_ull>(val);
    }
    constexpr gigalux_second_ull operator""_Gs_cd_per_sq_m(unsigned long long val) {
        return static_cast<gigalux_second_ull>(val);
    }
    constexpr megalux_second_ull operator""_Ms_cd_per_sq_m(unsigned long long val) {
        return static_cast<megalux_second_ull>(val);
    }
    constexpr kilolux_second_ull operator""_ks_cd_per_sq_m(unsigned long long val) {
        return static_cast<kilolux_second_ull>(val);
    }
    constexpr hectolux_second_ull operator""_hs_cd_per_sq_m(unsigned long long val) {
        return static_cast<hectolux_second_ull>(val);
    }
    constexpr decalux_second_ull operator""_das_cd_per_sq_m(unsigned long long val) {
        return static_cast<decalux_second_ull>(val);
    }
    constexpr lux_second_ull operator""_s_cd_per_sq_m(unsigned long long val) {
        return static_cast<lux_second_ull>(val);
    }
    constexpr decilux_second_ull operator""_ds_cd_per_sq_m(unsigned long long val) {
        return static_cast<decilux_second_ull>(val);
    }
    constexpr centilux_second_ull operator""_cs_cd_per_sq_m(unsigned long long val) {
        return static_cast<centilux_second_ull>(val);
    }
    constexpr millilux_second_ull operator""_ms_cd_per_sq_m(unsigned long long val) {
        return static_cast<millilux_second_ull>(val);
    }
    constexpr microlux_second_ull operator""_us_cd_per_sq_m(unsigned long long val) {
        return static_cast<microlux_second_ull>(val);
    }
    constexpr nanolux_second_ull operator""_ns_cd_per_sq_m(unsigned long long val) {
        return static_cast<nanolux_second_ull>(val);
    }
    constexpr picolux_second_ull operator""_ps_cd_per_sq_m(unsigned long long val) {
        return static_cast<picolux_second_ull>(val);
    }
    constexpr femtolux_second_ull operator""_fs_cd_per_sq_m(unsigned long long val) {
        return static_cast<femtolux_second_ull>(val);
    }
    constexpr attolux_second_ull operator""_as_cd_per_sq_m(unsigned long long val) {
        return static_cast<attolux_second_ull>(val);
    }

} // namespace potato::units
