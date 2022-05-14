//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Joule_Per_Mole_Kelvin;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using joule_per_mole_kelvin_tag_t = tmp::list_<tmp::list_<meter_l, meter_l, gram_l>, tmp::list_<second_l, second_l, mole_l, kelvin_l>>;

    template<typename T>
    concept Joule_Per_Mole_KelvinC = std::same_as<typename T::impl, joule_per_mole_kelvin_tag_t>;

    template <typename RatioTypeT, typename P>
    struct joule_per_mole_kelvin_impl {

        static constexpr auto pretty = "J/mol·K";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = joule_per_mole_kelvin_tag_t;

        constexpr joule_per_mole_kelvin_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exajoule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<std::exa, long double>;
    using petajoule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<std::peta, long double>;
    using terajoule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<std::tera, long double>;
    using gigajoule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<std::giga, long double>;
    using megajoule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<std::mega, long double>;
    using kilojoule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<std::kilo, long double>;
    using hectojoule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<std::hecto, long double>;
    using decajoule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<std::deca, long double>;
    using joule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<unity_ratio, long double>;
    using decijoule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<std::deci, long double>;
    using centijoule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<std::centi, long double>;
    using millijoule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<std::milli, long double>;
    using microjoule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<std::micro, long double>;
    using nanojoule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<std::nano, long double>;
    using picojoule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<std::pico, long double>;
    using femtojoule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<std::femto, long double>;
    using attojoule_per_mole_kelvin_ld    =     joule_per_mole_kelvin_impl<std::atto, long double>;
    using exajoule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<std::exa, unsigned long long>;
    using petajoule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<std::peta, unsigned long long>;
    using terajoule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<std::tera, unsigned long long>;
    using gigajoule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<std::giga, unsigned long long>;
    using megajoule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<std::mega, unsigned long long>;
    using kilojoule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<std::kilo, unsigned long long>;
    using hectojoule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<std::hecto, unsigned long long>;
    using decajoule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<std::deca, unsigned long long>;
    using joule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<unity_ratio, unsigned long long>;
    using decijoule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<std::deci, unsigned long long>;
    using centijoule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<std::centi, unsigned long long>;
    using millijoule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<std::milli, unsigned long long>;
    using microjoule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<std::micro, unsigned long long>;
    using nanojoule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<std::nano, unsigned long long>;
    using picojoule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<std::pico, unsigned long long>;
    using femtojoule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<std::femto, unsigned long long>;
    using attojoule_per_mole_kelvin_ull    =     joule_per_mole_kelvin_impl<std::atto, unsigned long long>;

    constexpr exajoule_per_mole_kelvin_ld operator""_EJ_per_mol_K(long double val) {
        return static_cast<exajoule_per_mole_kelvin_ld>(val);
    }
    constexpr petajoule_per_mole_kelvin_ld operator""_PJ_per_mol_K(long double val) {
        return static_cast<petajoule_per_mole_kelvin_ld>(val);
    }
    constexpr terajoule_per_mole_kelvin_ld operator""_TJ_per_mol_K(long double val) {
        return static_cast<terajoule_per_mole_kelvin_ld>(val);
    }
    constexpr gigajoule_per_mole_kelvin_ld operator""_GJ_per_mol_K(long double val) {
        return static_cast<gigajoule_per_mole_kelvin_ld>(val);
    }
    constexpr megajoule_per_mole_kelvin_ld operator""_MJ_per_mol_K(long double val) {
        return static_cast<megajoule_per_mole_kelvin_ld>(val);
    }
    constexpr kilojoule_per_mole_kelvin_ld operator""_kJ_per_mol_K(long double val) {
        return static_cast<kilojoule_per_mole_kelvin_ld>(val);
    }
    constexpr hectojoule_per_mole_kelvin_ld operator""_hJ_per_mol_K(long double val) {
        return static_cast<hectojoule_per_mole_kelvin_ld>(val);
    }
    constexpr decajoule_per_mole_kelvin_ld operator""_daJ_per_mol_K(long double val) {
        return static_cast<decajoule_per_mole_kelvin_ld>(val);
    }
    constexpr joule_per_mole_kelvin_ld operator""_J_per_mol_K(long double val) {
        return static_cast<joule_per_mole_kelvin_ld>(val);
    }
    constexpr decijoule_per_mole_kelvin_ld operator""_dJ_per_mol_K(long double val) {
        return static_cast<decijoule_per_mole_kelvin_ld>(val);
    }
    constexpr centijoule_per_mole_kelvin_ld operator""_cJ_per_mol_K(long double val) {
        return static_cast<centijoule_per_mole_kelvin_ld>(val);
    }
    constexpr millijoule_per_mole_kelvin_ld operator""_mJ_per_mol_K(long double val) {
        return static_cast<millijoule_per_mole_kelvin_ld>(val);
    }
    constexpr microjoule_per_mole_kelvin_ld operator""_uJ_per_mol_K(long double val) {
        return static_cast<microjoule_per_mole_kelvin_ld>(val);
    }
    constexpr nanojoule_per_mole_kelvin_ld operator""_nJ_per_mol_K(long double val) {
        return static_cast<nanojoule_per_mole_kelvin_ld>(val);
    }
    constexpr picojoule_per_mole_kelvin_ld operator""_pJ_per_mol_K(long double val) {
        return static_cast<picojoule_per_mole_kelvin_ld>(val);
    }
    constexpr femtojoule_per_mole_kelvin_ld operator""_fJ_per_mol_K(long double val) {
        return static_cast<femtojoule_per_mole_kelvin_ld>(val);
    }
    constexpr attojoule_per_mole_kelvin_ld operator""_aJ_per_mol_K(long double val) {
        return static_cast<attojoule_per_mole_kelvin_ld>(val);
    }
    constexpr exajoule_per_mole_kelvin_ull operator""_EJ_per_mol_K(unsigned long long val) {
        return static_cast<exajoule_per_mole_kelvin_ull>(val);
    }
    constexpr petajoule_per_mole_kelvin_ull operator""_PJ_per_mol_K(unsigned long long val) {
        return static_cast<petajoule_per_mole_kelvin_ull>(val);
    }
    constexpr terajoule_per_mole_kelvin_ull operator""_TJ_per_mol_K(unsigned long long val) {
        return static_cast<terajoule_per_mole_kelvin_ull>(val);
    }
    constexpr gigajoule_per_mole_kelvin_ull operator""_GJ_per_mol_K(unsigned long long val) {
        return static_cast<gigajoule_per_mole_kelvin_ull>(val);
    }
    constexpr megajoule_per_mole_kelvin_ull operator""_MJ_per_mol_K(unsigned long long val) {
        return static_cast<megajoule_per_mole_kelvin_ull>(val);
    }
    constexpr kilojoule_per_mole_kelvin_ull operator""_kJ_per_mol_K(unsigned long long val) {
        return static_cast<kilojoule_per_mole_kelvin_ull>(val);
    }
    constexpr hectojoule_per_mole_kelvin_ull operator""_hJ_per_mol_K(unsigned long long val) {
        return static_cast<hectojoule_per_mole_kelvin_ull>(val);
    }
    constexpr decajoule_per_mole_kelvin_ull operator""_daJ_per_mol_K(unsigned long long val) {
        return static_cast<decajoule_per_mole_kelvin_ull>(val);
    }
    constexpr joule_per_mole_kelvin_ull operator""_J_per_mol_K(unsigned long long val) {
        return static_cast<joule_per_mole_kelvin_ull>(val);
    }
    constexpr decijoule_per_mole_kelvin_ull operator""_dJ_per_mol_K(unsigned long long val) {
        return static_cast<decijoule_per_mole_kelvin_ull>(val);
    }
    constexpr centijoule_per_mole_kelvin_ull operator""_cJ_per_mol_K(unsigned long long val) {
        return static_cast<centijoule_per_mole_kelvin_ull>(val);
    }
    constexpr millijoule_per_mole_kelvin_ull operator""_mJ_per_mol_K(unsigned long long val) {
        return static_cast<millijoule_per_mole_kelvin_ull>(val);
    }
    constexpr microjoule_per_mole_kelvin_ull operator""_uJ_per_mol_K(unsigned long long val) {
        return static_cast<microjoule_per_mole_kelvin_ull>(val);
    }
    constexpr nanojoule_per_mole_kelvin_ull operator""_nJ_per_mol_K(unsigned long long val) {
        return static_cast<nanojoule_per_mole_kelvin_ull>(val);
    }
    constexpr picojoule_per_mole_kelvin_ull operator""_pJ_per_mol_K(unsigned long long val) {
        return static_cast<picojoule_per_mole_kelvin_ull>(val);
    }
    constexpr femtojoule_per_mole_kelvin_ull operator""_fJ_per_mol_K(unsigned long long val) {
        return static_cast<femtojoule_per_mole_kelvin_ull>(val);
    }
    constexpr attojoule_per_mole_kelvin_ull operator""_aJ_per_mol_K(unsigned long long val) {
        return static_cast<attojoule_per_mole_kelvin_ull>(val);
    }

} // namespace potato::units
