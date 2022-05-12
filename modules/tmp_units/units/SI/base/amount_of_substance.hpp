#ifndef POTATO_UNITS_AMOUNT_OF_SUBSTANCE_HPP_INCLUDED
#define POTATO_UNITS_AMOUNT_OF_SUBSTANCE_HPP_INCLUDED

//  Copyright 2019 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

#include <ratio>

#include <boost/tmp/vocabulary.hpp>
#include <potato/engine/base.hpp>

namespace potato {
    namespace units {
        using namespace boost::tmp;

        template <typename T, typename P>
        struct mole_impl {
            // Deduce value to determine correct stored value.
            using DV = call_<if_<is_<unsigned long long>, always_<long long>, always_<P>>, P>;

            constexpr mole_impl<T, P>() : value(0) {}
            constexpr mole_impl<T, P>(DV val) : value(val) {}

            template <typename U, typename R>
            constexpr const mole_impl<T, P>(const mole_impl<U, R>& other) {
                using scale_greater = call_<if_<lift_<std::ratio_greater>,
                    always_<std::ratio_divide<U, T>>,
                    always_<unity_ratio>>,
                    T, U>;
                using scale_lesser = call_<if_<lift_<std::ratio_less>,
                    always_<std::ratio_divide<T, U>>,
                    always_<unity_ratio>>,
                    T, U>;
                value = (other.value * scale_greater::num * scale_lesser::den) / (scale_greater::den * scale_lesser::num);
            }

            DV value = 0;

            static constexpr auto pretty = "mol";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<mole_l>, list_<>>;
        };

        using examole_ld    =     mole_impl<std::exa, long double>;
        using petamole_ld    =     mole_impl<std::peta, long double>;
        using teramole_ld    =     mole_impl<std::tera, long double>;
        using gigamole_ld    =     mole_impl<std::giga, long double>;
        using megamole_ld    =     mole_impl<std::mega, long double>;
        using kilomole_ld    =     mole_impl<std::kilo, long double>;
        using hectomole_ld    =     mole_impl<std::hecto, long double>;
        using decamole_ld    =     mole_impl<std::deca, long double>;
        using mole_ld    =     mole_impl<unity_ratio, long double>;
        using decimole_ld    =     mole_impl<std::deci, long double>;
        using centimole_ld    =     mole_impl<std::centi, long double>;
        using millimole_ld    =     mole_impl<std::milli, long double>;
        using micromole_ld    =     mole_impl<std::micro, long double>;
        using nanomole_ld    =     mole_impl<std::nano, long double>;
        using picomole_ld    =     mole_impl<std::pico, long double>;
        using femtomole_ld    =     mole_impl<std::femto, long double>;
        using attomole_ld    =     mole_impl<std::atto, long double>;
        using examole_ull    =     mole_impl<std::exa, unsigned long long>;
        using petamole_ull    =     mole_impl<std::peta, unsigned long long>;
        using teramole_ull    =     mole_impl<std::tera, unsigned long long>;
        using gigamole_ull    =     mole_impl<std::giga, unsigned long long>;
        using megamole_ull    =     mole_impl<std::mega, unsigned long long>;
        using kilomole_ull    =     mole_impl<std::kilo, unsigned long long>;
        using hectomole_ull    =     mole_impl<std::hecto, unsigned long long>;
        using decamole_ull    =     mole_impl<std::deca, unsigned long long>;
        using mole_ull    =     mole_impl<unity_ratio, unsigned long long>;
        using decimole_ull    =     mole_impl<std::deci, unsigned long long>;
        using centimole_ull    =     mole_impl<std::centi, unsigned long long>;
        using millimole_ull    =     mole_impl<std::milli, unsigned long long>;
        using micromole_ull    =     mole_impl<std::micro, unsigned long long>;
        using nanomole_ull    =     mole_impl<std::nano, unsigned long long>;
        using picomole_ull    =     mole_impl<std::pico, unsigned long long>;
        using femtomole_ull    =     mole_impl<std::femto, unsigned long long>;
        using attomole_ull    =     mole_impl<std::atto, unsigned long long>;

        constexpr examole_ld operator""_Emol(long double val) {
            return static_cast<examole_ld>(val);
        }
        constexpr petamole_ld operator""_Pmol(long double val) {
            return static_cast<petamole_ld>(val);
        }
        constexpr teramole_ld operator""_Tmol(long double val) {
            return static_cast<teramole_ld>(val);
        }
        constexpr gigamole_ld operator""_Gmol(long double val) {
            return static_cast<gigamole_ld>(val);
        }
        constexpr megamole_ld operator""_Mmol(long double val) {
            return static_cast<megamole_ld>(val);
        }
        constexpr kilomole_ld operator""_kmol(long double val) {
            return static_cast<kilomole_ld>(val);
        }
        constexpr hectomole_ld operator""_hmol(long double val) {
            return static_cast<hectomole_ld>(val);
        }
        constexpr decamole_ld operator""_damol(long double val) {
            return static_cast<decamole_ld>(val);
        }
        constexpr mole_ld operator""_mol(long double val) {
            return static_cast<mole_ld>(val);
        }
        constexpr decimole_ld operator""_dmol(long double val) {
            return static_cast<decimole_ld>(val);
        }
        constexpr centimole_ld operator""_cmol(long double val) {
            return static_cast<centimole_ld>(val);
        }
        constexpr millimole_ld operator""_mmol(long double val) {
            return static_cast<millimole_ld>(val);
        }
        constexpr micromole_ld operator""_umol(long double val) {
            return static_cast<micromole_ld>(val);
        }
        constexpr nanomole_ld operator""_nmol(long double val) {
            return static_cast<nanomole_ld>(val);
        }
        constexpr picomole_ld operator""_pmol(long double val) {
            return static_cast<picomole_ld>(val);
        }
        constexpr femtomole_ld operator""_fmol(long double val) {
            return static_cast<femtomole_ld>(val);
        }
        constexpr attomole_ld operator""_amol(long double val) {
            return static_cast<attomole_ld>(val);
        }
        constexpr examole_ull operator""_Emol(unsigned long long val) {
            return static_cast<examole_ull>(val);
        }
        constexpr petamole_ull operator""_Pmol(unsigned long long val) {
            return static_cast<petamole_ull>(val);
        }
        constexpr teramole_ull operator""_Tmol(unsigned long long val) {
            return static_cast<teramole_ull>(val);
        }
        constexpr gigamole_ull operator""_Gmol(unsigned long long val) {
            return static_cast<gigamole_ull>(val);
        }
        constexpr megamole_ull operator""_Mmol(unsigned long long val) {
            return static_cast<megamole_ull>(val);
        }
        constexpr kilomole_ull operator""_kmol(unsigned long long val) {
            return static_cast<kilomole_ull>(val);
        }
        constexpr hectomole_ull operator""_hmol(unsigned long long val) {
            return static_cast<hectomole_ull>(val);
        }
        constexpr decamole_ull operator""_damol(unsigned long long val) {
            return static_cast<decamole_ull>(val);
        }
        constexpr mole_ull operator""_mol(unsigned long long val) {
            return static_cast<mole_ull>(val);
        }
        constexpr decimole_ull operator""_dmol(unsigned long long val) {
            return static_cast<decimole_ull>(val);
        }
        constexpr centimole_ull operator""_cmol(unsigned long long val) {
            return static_cast<centimole_ull>(val);
        }
        constexpr millimole_ull operator""_mmol(unsigned long long val) {
            return static_cast<millimole_ull>(val);
        }
        constexpr micromole_ull operator""_umol(unsigned long long val) {
            return static_cast<micromole_ull>(val);
        }
        constexpr nanomole_ull operator""_nmol(unsigned long long val) {
            return static_cast<nanomole_ull>(val);
        }
        constexpr picomole_ull operator""_pmol(unsigned long long val) {
            return static_cast<picomole_ull>(val);
        }
        constexpr femtomole_ull operator""_fmol(unsigned long long val) {
            return static_cast<femtomole_ull>(val);
        }
        constexpr attomole_ull operator""_amol(unsigned long long val) {
            return static_cast<attomole_ull>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_MOLE_HPP_INCLUDED