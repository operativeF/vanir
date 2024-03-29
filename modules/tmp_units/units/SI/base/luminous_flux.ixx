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

namespace tmp = boost::tmp;
export namespace potato::units {

    using luminous_flux_tag_t = tmp::list_<Length<std::ratio<0, 1>>,
                                         Time<std::ratio<0, 1>>,
                                         Mass<std::ratio<0, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<1, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<1, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept LumenC = std::same_as<typename T::impl, luminous_flux_tag_t>;

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
        using impl       = luminous_flux_tag_t;

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

    consteval exalumen_ld operator""_Elm(long double val) {
        return static_cast<exalumen_ld>(val);
    }
    consteval petalumen_ld operator""_Plm(long double val) {
        return static_cast<petalumen_ld>(val);
    }
    consteval teralumen_ld operator""_Tlm(long double val) {
        return static_cast<teralumen_ld>(val);
    }
    consteval gigalumen_ld operator""_Glm(long double val) {
        return static_cast<gigalumen_ld>(val);
    }
    consteval megalumen_ld operator""_Mlm(long double val) {
        return static_cast<megalumen_ld>(val);
    }
    consteval kilolumen_ld operator""_klm(long double val) {
        return static_cast<kilolumen_ld>(val);
    }
    consteval hectolumen_ld operator""_hlm(long double val) {
        return static_cast<hectolumen_ld>(val);
    }
    consteval decalumen_ld operator""_dalm(long double val) {
        return static_cast<decalumen_ld>(val);
    }
    consteval lumen_ld operator""_lm(long double val) {
        return static_cast<lumen_ld>(val);
    }
    consteval decilumen_ld operator""_dlm(long double val) {
        return static_cast<decilumen_ld>(val);
    }
    consteval centilumen_ld operator""_clm(long double val) {
        return static_cast<centilumen_ld>(val);
    }
    consteval millilumen_ld operator""_mlm(long double val) {
        return static_cast<millilumen_ld>(val);
    }
    consteval microlumen_ld operator""_ulm(long double val) {
        return static_cast<microlumen_ld>(val);
    }
    consteval nanolumen_ld operator""_nlm(long double val) {
        return static_cast<nanolumen_ld>(val);
    }
    consteval picolumen_ld operator""_plm(long double val) {
        return static_cast<picolumen_ld>(val);
    }
    consteval femtolumen_ld operator""_flm(long double val) {
        return static_cast<femtolumen_ld>(val);
    }
    consteval attolumen_ld operator""_alm(long double val) {
        return static_cast<attolumen_ld>(val);
    }
    consteval exalumen_ull operator""_Elm(unsigned long long val) {
        return static_cast<exalumen_ull>(val);
    }
    consteval petalumen_ull operator""_Plm(unsigned long long val) {
        return static_cast<petalumen_ull>(val);
    }
    consteval teralumen_ull operator""_Tlm(unsigned long long val) {
        return static_cast<teralumen_ull>(val);
    }
    consteval gigalumen_ull operator""_Glm(unsigned long long val) {
        return static_cast<gigalumen_ull>(val);
    }
    consteval megalumen_ull operator""_Mlm(unsigned long long val) {
        return static_cast<megalumen_ull>(val);
    }
    consteval kilolumen_ull operator""_klm(unsigned long long val) {
        return static_cast<kilolumen_ull>(val);
    }
    consteval hectolumen_ull operator""_hlm(unsigned long long val) {
        return static_cast<hectolumen_ull>(val);
    }
    consteval decalumen_ull operator""_dalm(unsigned long long val) {
        return static_cast<decalumen_ull>(val);
    }
    consteval lumen_ull operator""_lm(unsigned long long val) {
        return static_cast<lumen_ull>(val);
    }
    consteval decilumen_ull operator""_dlm(unsigned long long val) {
        return static_cast<decilumen_ull>(val);
    }
    consteval centilumen_ull operator""_clm(unsigned long long val) {
        return static_cast<centilumen_ull>(val);
    }
    consteval millilumen_ull operator""_mlm(unsigned long long val) {
        return static_cast<millilumen_ull>(val);
    }
    consteval microlumen_ull operator""_ulm(unsigned long long val) {
        return static_cast<microlumen_ull>(val);
    }
    consteval nanolumen_ull operator""_nlm(unsigned long long val) {
        return static_cast<nanolumen_ull>(val);
    }
    consteval picolumen_ull operator""_plm(unsigned long long val) {
        return static_cast<picolumen_ull>(val);
    }
    consteval femtolumen_ull operator""_flm(unsigned long long val) {
        return static_cast<femtolumen_ull>(val);
    }
    consteval attolumen_ull operator""_alm(unsigned long long val) {
        return static_cast<attolumen_ull>(val);
    }

} // namespace potato::units
