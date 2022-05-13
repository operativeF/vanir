//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Mole_Per_Cubic_Meter;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

export namespace potato::units {
    namespace tmp = boost::tmp;

    template <typename RatioTypeT, typename P>
    struct mole_per_cubic_meter_impl {

        static constexpr auto pretty = "mol/m³";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = tmp::list_<tmp::list_<mole_l>, tmp::list_<meter_l, meter_l, meter_l>>;

        constexpr mole_per_cubic_meter_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using examole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<std::exa, long double>;
    using petamole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<std::peta, long double>;
    using teramole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<std::tera, long double>;
    using gigamole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<std::giga, long double>;
    using megamole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<std::mega, long double>;
    using kilomole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<std::kilo, long double>;
    using hectomole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<std::hecto, long double>;
    using decamole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<std::deca, long double>;
    using mole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<unity_ratio, long double>;
    using decimole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<std::deci, long double>;
    using centimole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<std::centi, long double>;
    using millimole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<std::milli, long double>;
    using micromole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<std::micro, long double>;
    using nanomole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<std::nano, long double>;
    using picomole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<std::pico, long double>;
    using femtomole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<std::femto, long double>;
    using attomole_per_cubic_meter_ld    =     mole_per_cubic_meter_impl<std::atto, long double>;
    using examole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<std::exa, unsigned long long>;
    using petamole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<std::peta, unsigned long long>;
    using teramole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<std::tera, unsigned long long>;
    using gigamole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<std::giga, unsigned long long>;
    using megamole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<std::mega, unsigned long long>;
    using kilomole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<std::kilo, unsigned long long>;
    using hectomole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<std::hecto, unsigned long long>;
    using decamole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<std::deca, unsigned long long>;
    using mole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<unity_ratio, unsigned long long>;
    using decimole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<std::deci, unsigned long long>;
    using centimole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<std::centi, unsigned long long>;
    using millimole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<std::milli, unsigned long long>;
    using micromole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<std::micro, unsigned long long>;
    using nanomole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<std::nano, unsigned long long>;
    using picomole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<std::pico, unsigned long long>;
    using femtomole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<std::femto, unsigned long long>;
    using attomole_per_cubic_meter_ull    =     mole_per_cubic_meter_impl<std::atto, unsigned long long>;

    constexpr examole_per_cubic_meter_ld operator""_Emol_per_cubic_m(long double val) {
        return static_cast<examole_per_cubic_meter_ld>(val);
    }
    constexpr petamole_per_cubic_meter_ld operator""_Pmol_per_cubic_m(long double val) {
        return static_cast<petamole_per_cubic_meter_ld>(val);
    }
    constexpr teramole_per_cubic_meter_ld operator""_Tmol_per_cubic_m(long double val) {
        return static_cast<teramole_per_cubic_meter_ld>(val);
    }
    constexpr gigamole_per_cubic_meter_ld operator""_Gmol_per_cubic_m(long double val) {
        return static_cast<gigamole_per_cubic_meter_ld>(val);
    }
    constexpr megamole_per_cubic_meter_ld operator""_Mmol_per_cubic_m(long double val) {
        return static_cast<megamole_per_cubic_meter_ld>(val);
    }
    constexpr kilomole_per_cubic_meter_ld operator""_kmol_per_cubic_m(long double val) {
        return static_cast<kilomole_per_cubic_meter_ld>(val);
    }
    constexpr hectomole_per_cubic_meter_ld operator""_hmol_per_cubic_m(long double val) {
        return static_cast<hectomole_per_cubic_meter_ld>(val);
    }
    constexpr decamole_per_cubic_meter_ld operator""_damol_per_cubic_m(long double val) {
        return static_cast<decamole_per_cubic_meter_ld>(val);
    }
    constexpr mole_per_cubic_meter_ld operator""_mol_per_cubic_m(long double val) {
        return static_cast<mole_per_cubic_meter_ld>(val);
    }
    constexpr decimole_per_cubic_meter_ld operator""_dmol_per_cubic_m(long double val) {
        return static_cast<decimole_per_cubic_meter_ld>(val);
    }
    constexpr centimole_per_cubic_meter_ld operator""_cmol_per_cubic_m(long double val) {
        return static_cast<centimole_per_cubic_meter_ld>(val);
    }
    constexpr millimole_per_cubic_meter_ld operator""_mmol_per_cubic_m(long double val) {
        return static_cast<millimole_per_cubic_meter_ld>(val);
    }
    constexpr micromole_per_cubic_meter_ld operator""_umol_per_cubic_m(long double val) {
        return static_cast<micromole_per_cubic_meter_ld>(val);
    }
    constexpr nanomole_per_cubic_meter_ld operator""_nmol_per_cubic_m(long double val) {
        return static_cast<nanomole_per_cubic_meter_ld>(val);
    }
    constexpr picomole_per_cubic_meter_ld operator""_pmol_per_cubic_m(long double val) {
        return static_cast<picomole_per_cubic_meter_ld>(val);
    }
    constexpr femtomole_per_cubic_meter_ld operator""_fmol_per_cubic_m(long double val) {
        return static_cast<femtomole_per_cubic_meter_ld>(val);
    }
    constexpr attomole_per_cubic_meter_ld operator""_amol_per_cubic_m(long double val) {
        return static_cast<attomole_per_cubic_meter_ld>(val);
    }
    constexpr examole_per_cubic_meter_ull operator""_Emol_per_cubic_m(unsigned long long val) {
        return static_cast<examole_per_cubic_meter_ull>(val);
    }
    constexpr petamole_per_cubic_meter_ull operator""_Pmol_per_cubic_m(unsigned long long val) {
        return static_cast<petamole_per_cubic_meter_ull>(val);
    }
    constexpr teramole_per_cubic_meter_ull operator""_Tmol_per_cubic_m(unsigned long long val) {
        return static_cast<teramole_per_cubic_meter_ull>(val);
    }
    constexpr gigamole_per_cubic_meter_ull operator""_Gmol_per_cubic_m(unsigned long long val) {
        return static_cast<gigamole_per_cubic_meter_ull>(val);
    }
    constexpr megamole_per_cubic_meter_ull operator""_Mmol_per_cubic_m(unsigned long long val) {
        return static_cast<megamole_per_cubic_meter_ull>(val);
    }
    constexpr kilomole_per_cubic_meter_ull operator""_kmol_per_cubic_m(unsigned long long val) {
        return static_cast<kilomole_per_cubic_meter_ull>(val);
    }
    constexpr hectomole_per_cubic_meter_ull operator""_hmol_per_cubic_m(unsigned long long val) {
        return static_cast<hectomole_per_cubic_meter_ull>(val);
    }
    constexpr decamole_per_cubic_meter_ull operator""_damol_per_cubic_m(unsigned long long val) {
        return static_cast<decamole_per_cubic_meter_ull>(val);
    }
    constexpr mole_per_cubic_meter_ull operator""_mol_per_cubic_m(unsigned long long val) {
        return static_cast<mole_per_cubic_meter_ull>(val);
    }
    constexpr decimole_per_cubic_meter_ull operator""_dmol_per_cubic_m(unsigned long long val) {
        return static_cast<decimole_per_cubic_meter_ull>(val);
    }
    constexpr centimole_per_cubic_meter_ull operator""_cmol_per_cubic_m(unsigned long long val) {
        return static_cast<centimole_per_cubic_meter_ull>(val);
    }
    constexpr millimole_per_cubic_meter_ull operator""_mmol_per_cubic_m(unsigned long long val) {
        return static_cast<millimole_per_cubic_meter_ull>(val);
    }
    constexpr micromole_per_cubic_meter_ull operator""_umol_per_cubic_m(unsigned long long val) {
        return static_cast<micromole_per_cubic_meter_ull>(val);
    }
    constexpr nanomole_per_cubic_meter_ull operator""_nmol_per_cubic_m(unsigned long long val) {
        return static_cast<nanomole_per_cubic_meter_ull>(val);
    }
    constexpr picomole_per_cubic_meter_ull operator""_pmol_per_cubic_m(unsigned long long val) {
        return static_cast<picomole_per_cubic_meter_ull>(val);
    }
    constexpr femtomole_per_cubic_meter_ull operator""_fmol_per_cubic_m(unsigned long long val) {
        return static_cast<femtomole_per_cubic_meter_ull>(val);
    }
    constexpr attomole_per_cubic_meter_ull operator""_amol_per_cubic_m(unsigned long long val) {
        return static_cast<attomole_per_cubic_meter_ull>(val);
    }

} // namespace potato::units
