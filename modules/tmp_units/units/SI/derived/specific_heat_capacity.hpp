#ifndef POTATO_UNITS_SPECFIC_HEAT_CAPACITY_HPP_INCLUDED
#define POTATO_UNITS_SPECFIC_HEAT_CAPACITY_HPP_INCLUDED

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
        struct joule_per_kilogram_kelvin_impl {
            constexpr joule_per_kilogram_kelvin_impl<T, P>() : value(0) {}
            constexpr joule_per_kilogram_kelvin_impl<T, P>(P val) : value(val) {}

            P value;

            static constexpr auto pretty = "J/kg·K";

            using is_any_impl = false_;

            using mod_ratio = T;
            using base      = list_<list_<length_l, length_l>, list_<time_l, time_l, temperature_l>>;
            using impl      = list_<list_<meter_l, meter_l>, list_<second_l, second_l, kelvin_l>>;
        };

        using exajoule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<std::exa, long double>;
        using petajoule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<std::peta, long double>;
        using terajoule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<std::tera, long double>;
        using gigajoule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<std::giga, long double>;
        using megajoule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<std::mega, long double>;
        using kilojoule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<std::kilo, long double>;
        using hectojoule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<std::hecto, long double>;
        using decajoule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<std::deca, long double>;
        using joule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<unity_ratio, long double>;
        using decijoule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<std::deci, long double>;
        using centijoule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<std::centi, long double>;
        using millijoule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<std::milli, long double>;
        using microjoule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<std::micro, long double>;
        using nanojoule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<std::nano, long double>;
        using picojoule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<std::pico, long double>;
        using femtojoule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<std::femto, long double>;
        using attojoule_per_kilogram_kelvin    =     joule_per_kilogram_kelvin_impl<std::atto, long double>;

        constexpr exajoule_per_kilogram_kelvin operator""_EJ_per_kg_K(long double val) {
            return static_cast<exajoule_per_kilogram_kelvin>(val);
        }
        constexpr petajoule_per_kilogram_kelvin operator""_PJ_per_kg_K(long double val) {
            return static_cast<petajoule_per_kilogram_kelvin>(val);
        }
        constexpr terajoule_per_kilogram_kelvin operator""_TJ_per_kg_K(long double val) {
            return static_cast<terajoule_per_kilogram_kelvin>(val);
        }
        constexpr gigajoule_per_kilogram_kelvin operator""_GJ_per_kg_K(long double val) {
            return static_cast<gigajoule_per_kilogram_kelvin>(val);
        }
        constexpr megajoule_per_kilogram_kelvin operator""_MJ_per_kg_K(long double val) {
            return static_cast<megajoule_per_kilogram_kelvin>(val);
        }
        constexpr kilojoule_per_kilogram_kelvin operator""_kJ_per_kg_K(long double val) {
            return static_cast<kilojoule_per_kilogram_kelvin>(val);
        }
        constexpr hectojoule_per_kilogram_kelvin operator""_hJ_per_kg_K(long double val) {
            return static_cast<hectojoule_per_kilogram_kelvin>(val);
        }
        constexpr decajoule_per_kilogram_kelvin operator""_daJ_per_kg_K(long double val) {
            return static_cast<decajoule_per_kilogram_kelvin>(val);
        }
        constexpr joule_per_kilogram_kelvin operator""_J_per_kg_K(long double val) {
            return static_cast<joule_per_kilogram_kelvin>(val);
        }
        constexpr decijoule_per_kilogram_kelvin operator""_dJ_per_kg_K(long double val) {
            return static_cast<decijoule_per_kilogram_kelvin>(val);
        }
        constexpr centijoule_per_kilogram_kelvin operator""_cJ_per_kg_K(long double val) {
            return static_cast<centijoule_per_kilogram_kelvin>(val);
        }
        constexpr millijoule_per_kilogram_kelvin operator""_mJ_per_kg_K(long double val) {
            return static_cast<millijoule_per_kilogram_kelvin>(val);
        }
        constexpr microjoule_per_kilogram_kelvin operator""_uJ_per_kg_K(long double val) {
            return static_cast<microjoule_per_kilogram_kelvin>(val);
        }
        constexpr nanojoule_per_kilogram_kelvin operator""_nJ_per_kg_K(long double val) {
            return static_cast<nanojoule_per_kilogram_kelvin>(val);
        }
        constexpr picojoule_per_kilogram_kelvin operator""_pJ_per_kg_K(long double val) {
            return static_cast<picojoule_per_kilogram_kelvin>(val);
        }
        constexpr femtojoule_per_kilogram_kelvin operator""_fJ_per_kg_K(long double val) {
            return static_cast<femtojoule_per_kilogram_kelvin>(val);
        }
        constexpr attojoule_per_kilogram_kelvin operator""_aJ_per_kg_K(long double val) {
            return static_cast<attojoule_per_kilogram_kelvin>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_JOULE_PER_KILOGRAM_KELVIN_HPP_INCLUDED