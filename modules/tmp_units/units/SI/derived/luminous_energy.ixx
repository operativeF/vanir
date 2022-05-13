//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Lumen_Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

export namespace potato::units {
    namespace tmp = boost::tmp;

    template <typename RatioTypeT, typename P>
    struct lumen_second_impl {

        static constexpr auto pretty = "s·cd";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = tmp::list_<tmp::list_<second_l, candela_l>, tmp::list_<>>;

        constexpr lumen_second_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exalumen_second_ld    =     lumen_second_impl<std::exa, long double>;
    using petalumen_second_ld    =     lumen_second_impl<std::peta, long double>;
    using teralumen_second_ld    =     lumen_second_impl<std::tera, long double>;
    using gigalumen_second_ld    =     lumen_second_impl<std::giga, long double>;
    using megalumen_second_ld    =     lumen_second_impl<std::mega, long double>;
    using kilolumen_second_ld    =     lumen_second_impl<std::kilo, long double>;
    using hectolumen_second_ld    =     lumen_second_impl<std::hecto, long double>;
    using decalumen_second_ld    =     lumen_second_impl<std::deca, long double>;
    using lumen_second_ld    =     lumen_second_impl<unity_ratio, long double>;
    using decilumen_second_ld    =     lumen_second_impl<std::deci, long double>;
    using centilumen_second_ld    =     lumen_second_impl<std::centi, long double>;
    using millilumen_second_ld    =     lumen_second_impl<std::milli, long double>;
    using microlumen_second_ld    =     lumen_second_impl<std::micro, long double>;
    using nanolumen_second_ld    =     lumen_second_impl<std::nano, long double>;
    using picolumen_second_ld    =     lumen_second_impl<std::pico, long double>;
    using femtolumen_second_ld    =     lumen_second_impl<std::femto, long double>;
    using attolumen_second_ld    =     lumen_second_impl<std::atto, long double>;
    using exalumen_second_ull    =     lumen_second_impl<std::exa, unsigned long long>;
    using petalumen_second_ull    =     lumen_second_impl<std::peta, unsigned long long>;
    using teralumen_second_ull    =     lumen_second_impl<std::tera, unsigned long long>;
    using gigalumen_second_ull    =     lumen_second_impl<std::giga, unsigned long long>;
    using megalumen_second_ull    =     lumen_second_impl<std::mega, unsigned long long>;
    using kilolumen_second_ull    =     lumen_second_impl<std::kilo, unsigned long long>;
    using hectolumen_second_ull    =     lumen_second_impl<std::hecto, unsigned long long>;
    using decalumen_second_ull    =     lumen_second_impl<std::deca, unsigned long long>;
    using lumen_second_ull    =     lumen_second_impl<unity_ratio, unsigned long long>;
    using decilumen_second_ull    =     lumen_second_impl<std::deci, unsigned long long>;
    using centilumen_second_ull    =     lumen_second_impl<std::centi, unsigned long long>;
    using millilumen_second_ull    =     lumen_second_impl<std::milli, unsigned long long>;
    using microlumen_second_ull    =     lumen_second_impl<std::micro, unsigned long long>;
    using nanolumen_second_ull    =     lumen_second_impl<std::nano, unsigned long long>;
    using picolumen_second_ull    =     lumen_second_impl<std::pico, unsigned long long>;
    using femtolumen_second_ull    =     lumen_second_impl<std::femto, unsigned long long>;
    using attolumen_second_ull    =     lumen_second_impl<std::atto, unsigned long long>;

    constexpr exalumen_second_ld operator""_Es_cd(long double val) {
        return static_cast<exalumen_second_ld>(val);
    }
    constexpr petalumen_second_ld operator""_Ps_cd(long double val) {
        return static_cast<petalumen_second_ld>(val);
    }
    constexpr teralumen_second_ld operator""_Ts_cd(long double val) {
        return static_cast<teralumen_second_ld>(val);
    }
    constexpr gigalumen_second_ld operator""_Gs_cd(long double val) {
        return static_cast<gigalumen_second_ld>(val);
    }
    constexpr megalumen_second_ld operator""_Ms_cd(long double val) {
        return static_cast<megalumen_second_ld>(val);
    }
    constexpr kilolumen_second_ld operator""_ks_cd(long double val) {
        return static_cast<kilolumen_second_ld>(val);
    }
    constexpr hectolumen_second_ld operator""_hs_cd(long double val) {
        return static_cast<hectolumen_second_ld>(val);
    }
    constexpr decalumen_second_ld operator""_das_cd(long double val) {
        return static_cast<decalumen_second_ld>(val);
    }
    constexpr lumen_second_ld operator""_s_cd(long double val) {
        return static_cast<lumen_second_ld>(val);
    }
    constexpr decilumen_second_ld operator""_ds_cd(long double val) {
        return static_cast<decilumen_second_ld>(val);
    }
    constexpr centilumen_second_ld operator""_cs_cd(long double val) {
        return static_cast<centilumen_second_ld>(val);
    }
    constexpr millilumen_second_ld operator""_ms_cd(long double val) {
        return static_cast<millilumen_second_ld>(val);
    }
    constexpr microlumen_second_ld operator""_us_cd(long double val) {
        return static_cast<microlumen_second_ld>(val);
    }
    constexpr nanolumen_second_ld operator""_ns_cd(long double val) {
        return static_cast<nanolumen_second_ld>(val);
    }
    constexpr picolumen_second_ld operator""_ps_cd(long double val) {
        return static_cast<picolumen_second_ld>(val);
    }
    constexpr femtolumen_second_ld operator""_fs_cd(long double val) {
        return static_cast<femtolumen_second_ld>(val);
    }
    constexpr attolumen_second_ld operator""_as_cd(long double val) {
        return static_cast<attolumen_second_ld>(val);
    }
    constexpr exalumen_second_ull operator""_Es_cd(unsigned long long val) {
        return static_cast<exalumen_second_ull>(val);
    }
    constexpr petalumen_second_ull operator""_Ps_cd(unsigned long long val) {
        return static_cast<petalumen_second_ull>(val);
    }
    constexpr teralumen_second_ull operator""_Ts_cd(unsigned long long val) {
        return static_cast<teralumen_second_ull>(val);
    }
    constexpr gigalumen_second_ull operator""_Gs_cd(unsigned long long val) {
        return static_cast<gigalumen_second_ull>(val);
    }
    constexpr megalumen_second_ull operator""_Ms_cd(unsigned long long val) {
        return static_cast<megalumen_second_ull>(val);
    }
    constexpr kilolumen_second_ull operator""_ks_cd(unsigned long long val) {
        return static_cast<kilolumen_second_ull>(val);
    }
    constexpr hectolumen_second_ull operator""_hs_cd(unsigned long long val) {
        return static_cast<hectolumen_second_ull>(val);
    }
    constexpr decalumen_second_ull operator""_das_cd(unsigned long long val) {
        return static_cast<decalumen_second_ull>(val);
    }
    constexpr lumen_second_ull operator""_s_cd(unsigned long long val) {
        return static_cast<lumen_second_ull>(val);
    }
    constexpr decilumen_second_ull operator""_ds_cd(unsigned long long val) {
        return static_cast<decilumen_second_ull>(val);
    }
    constexpr centilumen_second_ull operator""_cs_cd(unsigned long long val) {
        return static_cast<centilumen_second_ull>(val);
    }
    constexpr millilumen_second_ull operator""_ms_cd(unsigned long long val) {
        return static_cast<millilumen_second_ull>(val);
    }
    constexpr microlumen_second_ull operator""_us_cd(unsigned long long val) {
        return static_cast<microlumen_second_ull>(val);
    }
    constexpr nanolumen_second_ull operator""_ns_cd(unsigned long long val) {
        return static_cast<nanolumen_second_ull>(val);
    }
    constexpr picolumen_second_ull operator""_ps_cd(unsigned long long val) {
        return static_cast<picolumen_second_ull>(val);
    }
    constexpr femtolumen_second_ull operator""_fs_cd(unsigned long long val) {
        return static_cast<femtolumen_second_ull>(val);
    }
    constexpr attolumen_second_ull operator""_as_cd(unsigned long long val) {
        return static_cast<attolumen_second_ull>(val);
    }

} // namespace potato::units
