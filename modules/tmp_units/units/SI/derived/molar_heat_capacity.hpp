#ifndef POTATO_UNITS_MOLAR_HEAT_CAPACITY_HPP_INCLUDED
#define POTATO_UNITS_MOLAR_HEAT_CAPACITY_HPP_INCLUDED

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
        struct joule_per_mole_kelvin_impl {
            // Deduce value to determine correct stored value.
            using DV = call_<if_<is_<unsigned long long>, always_<long long>, always_<P>>, P>;

            constexpr joule_per_mole_kelvin_impl<T, P>() : value(0) {}
            constexpr joule_per_mole_kelvin_impl<T, P>(DV val) : value(val) {}

            template <typename U, typename R>
            constexpr const joule_per_mole_kelvin_impl<T, P>(const joule_per_mole_kelvin_impl<U, R>& other) {
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

            static constexpr auto pretty = "J/mol·K";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<meter_l, meter_l, gram_l>, list_<second_l, second_l, mole_l, kelvin_l>>;
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

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_JOULE_PER_MOLE_KELVIN_HPP_INCLUDED