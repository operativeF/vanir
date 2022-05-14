//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Lumen_Per_Watt;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using lumen_per_watt_tag_t = tmp::list_<tmp::list_<second_l, second_l, second_l, candela_l>, tmp::list_<meter_l, meter_l, gram_l>>;

    template<typename T>
    concept Lumen_Per_WattC = std::same_as<typename T::impl, lumen_per_watt_tag_t>;

    template <typename RatioTypeT, typename P>
    struct lumen_per_watt_impl {

        static constexpr auto pretty = "lm/W";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = lumen_per_watt_tag_t;

        constexpr lumen_per_watt_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exalumen_per_watt_ld    =     lumen_per_watt_impl<std::exa, long double>;
    using petalumen_per_watt_ld    =     lumen_per_watt_impl<std::peta, long double>;
    using teralumen_per_watt_ld    =     lumen_per_watt_impl<std::tera, long double>;
    using gigalumen_per_watt_ld    =     lumen_per_watt_impl<std::giga, long double>;
    using megalumen_per_watt_ld    =     lumen_per_watt_impl<std::mega, long double>;
    using kilolumen_per_watt_ld    =     lumen_per_watt_impl<std::kilo, long double>;
    using hectolumen_per_watt_ld    =     lumen_per_watt_impl<std::hecto, long double>;
    using decalumen_per_watt_ld    =     lumen_per_watt_impl<std::deca, long double>;
    using lumen_per_watt_ld    =     lumen_per_watt_impl<unity_ratio, long double>;
    using decilumen_per_watt_ld    =     lumen_per_watt_impl<std::deci, long double>;
    using centilumen_per_watt_ld    =     lumen_per_watt_impl<std::centi, long double>;
    using millilumen_per_watt_ld    =     lumen_per_watt_impl<std::milli, long double>;
    using microlumen_per_watt_ld    =     lumen_per_watt_impl<std::micro, long double>;
    using nanolumen_per_watt_ld    =     lumen_per_watt_impl<std::nano, long double>;
    using picolumen_per_watt_ld    =     lumen_per_watt_impl<std::pico, long double>;
    using femtolumen_per_watt_ld    =     lumen_per_watt_impl<std::femto, long double>;
    using attolumen_per_watt_ld    =     lumen_per_watt_impl<std::atto, long double>;
    using exalumen_per_watt_ull    =     lumen_per_watt_impl<std::exa, unsigned long long>;
    using petalumen_per_watt_ull    =     lumen_per_watt_impl<std::peta, unsigned long long>;
    using teralumen_per_watt_ull    =     lumen_per_watt_impl<std::tera, unsigned long long>;
    using gigalumen_per_watt_ull    =     lumen_per_watt_impl<std::giga, unsigned long long>;
    using megalumen_per_watt_ull    =     lumen_per_watt_impl<std::mega, unsigned long long>;
    using kilolumen_per_watt_ull    =     lumen_per_watt_impl<std::kilo, unsigned long long>;
    using hectolumen_per_watt_ull    =     lumen_per_watt_impl<std::hecto, unsigned long long>;
    using decalumen_per_watt_ull    =     lumen_per_watt_impl<std::deca, unsigned long long>;
    using lumen_per_watt_ull    =     lumen_per_watt_impl<unity_ratio, unsigned long long>;
    using decilumen_per_watt_ull    =     lumen_per_watt_impl<std::deci, unsigned long long>;
    using centilumen_per_watt_ull    =     lumen_per_watt_impl<std::centi, unsigned long long>;
    using millilumen_per_watt_ull    =     lumen_per_watt_impl<std::milli, unsigned long long>;
    using microlumen_per_watt_ull    =     lumen_per_watt_impl<std::micro, unsigned long long>;
    using nanolumen_per_watt_ull    =     lumen_per_watt_impl<std::nano, unsigned long long>;
    using picolumen_per_watt_ull    =     lumen_per_watt_impl<std::pico, unsigned long long>;
    using femtolumen_per_watt_ull    =     lumen_per_watt_impl<std::femto, unsigned long long>;
    using attolumen_per_watt_ull    =     lumen_per_watt_impl<std::atto, unsigned long long>;

    constexpr exalumen_per_watt_ld operator""_Elm_per_W(long double val) {
        return static_cast<exalumen_per_watt_ld>(val);
    }
    constexpr petalumen_per_watt_ld operator""_Plm_per_W(long double val) {
        return static_cast<petalumen_per_watt_ld>(val);
    }
    constexpr teralumen_per_watt_ld operator""_Tlm_per_W(long double val) {
        return static_cast<teralumen_per_watt_ld>(val);
    }
    constexpr gigalumen_per_watt_ld operator""_Glm_per_W(long double val) {
        return static_cast<gigalumen_per_watt_ld>(val);
    }
    constexpr megalumen_per_watt_ld operator""_Mlm_per_W(long double val) {
        return static_cast<megalumen_per_watt_ld>(val);
    }
    constexpr kilolumen_per_watt_ld operator""_klm_per_W(long double val) {
        return static_cast<kilolumen_per_watt_ld>(val);
    }
    constexpr hectolumen_per_watt_ld operator""_hlm_per_W(long double val) {
        return static_cast<hectolumen_per_watt_ld>(val);
    }
    constexpr decalumen_per_watt_ld operator""_dalm_per_W(long double val) {
        return static_cast<decalumen_per_watt_ld>(val);
    }
    constexpr lumen_per_watt_ld operator""_lm_per_W(long double val) {
        return static_cast<lumen_per_watt_ld>(val);
    }
    constexpr decilumen_per_watt_ld operator""_dlm_per_W(long double val) {
        return static_cast<decilumen_per_watt_ld>(val);
    }
    constexpr centilumen_per_watt_ld operator""_clm_per_W(long double val) {
        return static_cast<centilumen_per_watt_ld>(val);
    }
    constexpr millilumen_per_watt_ld operator""_mlm_per_W(long double val) {
        return static_cast<millilumen_per_watt_ld>(val);
    }
    constexpr microlumen_per_watt_ld operator""_ulm_per_W(long double val) {
        return static_cast<microlumen_per_watt_ld>(val);
    }
    constexpr nanolumen_per_watt_ld operator""_nlm_per_W(long double val) {
        return static_cast<nanolumen_per_watt_ld>(val);
    }
    constexpr picolumen_per_watt_ld operator""_plm_per_W(long double val) {
        return static_cast<picolumen_per_watt_ld>(val);
    }
    constexpr femtolumen_per_watt_ld operator""_flm_per_W(long double val) {
        return static_cast<femtolumen_per_watt_ld>(val);
    }
    constexpr attolumen_per_watt_ld operator""_alm_per_W(long double val) {
        return static_cast<attolumen_per_watt_ld>(val);
    }
    constexpr exalumen_per_watt_ull operator""_Elm_per_W(unsigned long long val) {
        return static_cast<exalumen_per_watt_ull>(val);
    }
    constexpr petalumen_per_watt_ull operator""_Plm_per_W(unsigned long long val) {
        return static_cast<petalumen_per_watt_ull>(val);
    }
    constexpr teralumen_per_watt_ull operator""_Tlm_per_W(unsigned long long val) {
        return static_cast<teralumen_per_watt_ull>(val);
    }
    constexpr gigalumen_per_watt_ull operator""_Glm_per_W(unsigned long long val) {
        return static_cast<gigalumen_per_watt_ull>(val);
    }
    constexpr megalumen_per_watt_ull operator""_Mlm_per_W(unsigned long long val) {
        return static_cast<megalumen_per_watt_ull>(val);
    }
    constexpr kilolumen_per_watt_ull operator""_klm_per_W(unsigned long long val) {
        return static_cast<kilolumen_per_watt_ull>(val);
    }
    constexpr hectolumen_per_watt_ull operator""_hlm_per_W(unsigned long long val) {
        return static_cast<hectolumen_per_watt_ull>(val);
    }
    constexpr decalumen_per_watt_ull operator""_dalm_per_W(unsigned long long val) {
        return static_cast<decalumen_per_watt_ull>(val);
    }
    constexpr lumen_per_watt_ull operator""_lm_per_W(unsigned long long val) {
        return static_cast<lumen_per_watt_ull>(val);
    }
    constexpr decilumen_per_watt_ull operator""_dlm_per_W(unsigned long long val) {
        return static_cast<decilumen_per_watt_ull>(val);
    }
    constexpr centilumen_per_watt_ull operator""_clm_per_W(unsigned long long val) {
        return static_cast<centilumen_per_watt_ull>(val);
    }
    constexpr millilumen_per_watt_ull operator""_mlm_per_W(unsigned long long val) {
        return static_cast<millilumen_per_watt_ull>(val);
    }
    constexpr microlumen_per_watt_ull operator""_ulm_per_W(unsigned long long val) {
        return static_cast<microlumen_per_watt_ull>(val);
    }
    constexpr nanolumen_per_watt_ull operator""_nlm_per_W(unsigned long long val) {
        return static_cast<nanolumen_per_watt_ull>(val);
    }
    constexpr picolumen_per_watt_ull operator""_plm_per_W(unsigned long long val) {
        return static_cast<picolumen_per_watt_ull>(val);
    }
    constexpr femtolumen_per_watt_ull operator""_flm_per_W(unsigned long long val) {
        return static_cast<femtolumen_per_watt_ull>(val);
    }
    constexpr attolumen_per_watt_ull operator""_alm_per_W(unsigned long long val) {
        return static_cast<attolumen_per_watt_ull>(val);
    }

} // namespace potato::units
