//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Candela;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using luminous_intensity_tag_t = tmp::list_<Length<std::ratio<0, 1>>,
                                         Time<std::ratio<0, 1>>,
                                         Mass<std::ratio<0, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<1, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept CandelaC = std::same_as<typename T::impl, luminous_intensity_tag_t>;

    template <typename RatioTypeT, typename P>
    struct candela_impl {

        static constexpr auto pretty = "cd";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = luminous_intensity_tag_t;

        constexpr candela_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exacandela_ld    =     candela_impl<std::exa, long double>;
    using petacandela_ld    =     candela_impl<std::peta, long double>;
    using teracandela_ld    =     candela_impl<std::tera, long double>;
    using gigacandela_ld    =     candela_impl<std::giga, long double>;
    using megacandela_ld    =     candela_impl<std::mega, long double>;
    using kilocandela_ld    =     candela_impl<std::kilo, long double>;
    using hectocandela_ld    =     candela_impl<std::hecto, long double>;
    using decacandela_ld    =     candela_impl<std::deca, long double>;
    using candela_ld    =     candela_impl<unity_ratio, long double>;
    using decicandela_ld    =     candela_impl<std::deci, long double>;
    using centicandela_ld    =     candela_impl<std::centi, long double>;
    using millicandela_ld    =     candela_impl<std::milli, long double>;
    using microcandela_ld    =     candela_impl<std::micro, long double>;
    using nanocandela_ld    =     candela_impl<std::nano, long double>;
    using picocandela_ld    =     candela_impl<std::pico, long double>;
    using femtocandela_ld    =     candela_impl<std::femto, long double>;
    using attocandela_ld    =     candela_impl<std::atto, long double>;
    using exacandela_ull    =     candela_impl<std::exa, unsigned long long>;
    using petacandela_ull    =     candela_impl<std::peta, unsigned long long>;
    using teracandela_ull    =     candela_impl<std::tera, unsigned long long>;
    using gigacandela_ull    =     candela_impl<std::giga, unsigned long long>;
    using megacandela_ull    =     candela_impl<std::mega, unsigned long long>;
    using kilocandela_ull    =     candela_impl<std::kilo, unsigned long long>;
    using hectocandela_ull    =     candela_impl<std::hecto, unsigned long long>;
    using decacandela_ull    =     candela_impl<std::deca, unsigned long long>;
    using candela_ull    =     candela_impl<unity_ratio, unsigned long long>;
    using decicandela_ull    =     candela_impl<std::deci, unsigned long long>;
    using centicandela_ull    =     candela_impl<std::centi, unsigned long long>;
    using millicandela_ull    =     candela_impl<std::milli, unsigned long long>;
    using microcandela_ull    =     candela_impl<std::micro, unsigned long long>;
    using nanocandela_ull    =     candela_impl<std::nano, unsigned long long>;
    using picocandela_ull    =     candela_impl<std::pico, unsigned long long>;
    using femtocandela_ull    =     candela_impl<std::femto, unsigned long long>;
    using attocandela_ull    =     candela_impl<std::atto, unsigned long long>;

    consteval exacandela_ld operator""_Ecd(long double val) {
        return static_cast<exacandela_ld>(val);
    }
    consteval petacandela_ld operator""_Pcd(long double val) {
        return static_cast<petacandela_ld>(val);
    }
    consteval teracandela_ld operator""_Tcd(long double val) {
        return static_cast<teracandela_ld>(val);
    }
    consteval gigacandela_ld operator""_Gcd(long double val) {
        return static_cast<gigacandela_ld>(val);
    }
    consteval megacandela_ld operator""_Mcd(long double val) {
        return static_cast<megacandela_ld>(val);
    }
    consteval kilocandela_ld operator""_kcd(long double val) {
        return static_cast<kilocandela_ld>(val);
    }
    consteval hectocandela_ld operator""_hcd(long double val) {
        return static_cast<hectocandela_ld>(val);
    }
    consteval decacandela_ld operator""_dacd(long double val) {
        return static_cast<decacandela_ld>(val);
    }
    consteval candela_ld operator""_cd(long double val) {
        return static_cast<candela_ld>(val);
    }
    consteval decicandela_ld operator""_dcd(long double val) {
        return static_cast<decicandela_ld>(val);
    }
    consteval centicandela_ld operator""_ccd(long double val) {
        return static_cast<centicandela_ld>(val);
    }
    consteval millicandela_ld operator""_mcd(long double val) {
        return static_cast<millicandela_ld>(val);
    }
    consteval microcandela_ld operator""_ucd(long double val) {
        return static_cast<microcandela_ld>(val);
    }
    consteval nanocandela_ld operator""_ncd(long double val) {
        return static_cast<nanocandela_ld>(val);
    }
    consteval picocandela_ld operator""_pcd(long double val) {
        return static_cast<picocandela_ld>(val);
    }
    consteval femtocandela_ld operator""_fcd(long double val) {
        return static_cast<femtocandela_ld>(val);
    }
    consteval attocandela_ld operator""_acd(long double val) {
        return static_cast<attocandela_ld>(val);
    }
    consteval exacandela_ull operator""_Ecd(unsigned long long val) {
        return static_cast<exacandela_ull>(val);
    }
    consteval petacandela_ull operator""_Pcd(unsigned long long val) {
        return static_cast<petacandela_ull>(val);
    }
    consteval teracandela_ull operator""_Tcd(unsigned long long val) {
        return static_cast<teracandela_ull>(val);
    }
    consteval gigacandela_ull operator""_Gcd(unsigned long long val) {
        return static_cast<gigacandela_ull>(val);
    }
    consteval megacandela_ull operator""_Mcd(unsigned long long val) {
        return static_cast<megacandela_ull>(val);
    }
    consteval kilocandela_ull operator""_kcd(unsigned long long val) {
        return static_cast<kilocandela_ull>(val);
    }
    consteval hectocandela_ull operator""_hcd(unsigned long long val) {
        return static_cast<hectocandela_ull>(val);
    }
    consteval decacandela_ull operator""_dacd(unsigned long long val) {
        return static_cast<decacandela_ull>(val);
    }
    consteval candela_ull operator""_cd(unsigned long long val) {
        return static_cast<candela_ull>(val);
    }
    consteval decicandela_ull operator""_dcd(unsigned long long val) {
        return static_cast<decicandela_ull>(val);
    }
    consteval centicandela_ull operator""_ccd(unsigned long long val) {
        return static_cast<centicandela_ull>(val);
    }
    consteval millicandela_ull operator""_mcd(unsigned long long val) {
        return static_cast<millicandela_ull>(val);
    }
    consteval microcandela_ull operator""_ucd(unsigned long long val) {
        return static_cast<microcandela_ull>(val);
    }
    consteval nanocandela_ull operator""_ncd(unsigned long long val) {
        return static_cast<nanocandela_ull>(val);
    }
    consteval picocandela_ull operator""_pcd(unsigned long long val) {
        return static_cast<picocandela_ull>(val);
    }
    consteval femtocandela_ull operator""_fcd(unsigned long long val) {
        return static_cast<femtocandela_ull>(val);
    }
    consteval attocandela_ull operator""_acd(unsigned long long val) {
        return static_cast<attocandela_ull>(val);
    }

} // namespace potato::units
