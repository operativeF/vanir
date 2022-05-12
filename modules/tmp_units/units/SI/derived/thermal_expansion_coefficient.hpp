#ifndef POTATO_UNITS_THERMAL_EXPANSION_COEFFICIENT_HPP_INCLUDED
#define POTATO_UNITS_THERMAL_EXPANSION_COEFFICIENT_HPP_INCLUDED

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
        struct inverse_kelvin_impl {
            constexpr inverse_kelvin_impl<T, P>() : value(0) {}
            constexpr inverse_kelvin_impl<T, P>(P val) : value(val) {}

            P value;

            static constexpr auto pretty = "1/K";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<>, list_<kelvin_l>>;
        };

        using inverse_exakelvin    =     inverse_kelvin_impl<std::exa, long double>;
        using inverse_petakelvin    =     inverse_kelvin_impl<std::peta, long double>;
        using inverse_terakelvin    =     inverse_kelvin_impl<std::tera, long double>;
        using inverse_gigakelvin    =     inverse_kelvin_impl<std::giga, long double>;
        using inverse_megakelvin    =     inverse_kelvin_impl<std::mega, long double>;
        using inverse_kilokelvin    =     inverse_kelvin_impl<std::kilo, long double>;
        using inverse_hectokelvin    =     inverse_kelvin_impl<std::hecto, long double>;
        using inverse_decakelvin    =     inverse_kelvin_impl<std::deca, long double>;
        using inverse_kelvin    =     inverse_kelvin_impl<unity_ratio, long double>;
        using inverse_decikelvin    =     inverse_kelvin_impl<std::deci, long double>;
        using inverse_centikelvin    =     inverse_kelvin_impl<std::centi, long double>;
        using inverse_millikelvin    =     inverse_kelvin_impl<std::milli, long double>;
        using inverse_microkelvin    =     inverse_kelvin_impl<std::micro, long double>;
        using inverse_nanokelvin    =     inverse_kelvin_impl<std::nano, long double>;
        using inverse_picokelvin    =     inverse_kelvin_impl<std::pico, long double>;
        using inverse_femtokelvin    =     inverse_kelvin_impl<std::femto, long double>;
        using inverse_attokelvin    =     inverse_kelvin_impl<std::atto, long double>;

        constexpr inverse_exakelvin operator""_inv_K(long double val) {
            return static_cast<inverse_exakelvin>(val);
        }
        constexpr inverse_petakelvin operator""_inv_K(long double val) {
            return static_cast<inverse_petakelvin>(val);
        }
        constexpr inverse_terakelvin operator""_inv_K(long double val) {
            return static_cast<inverse_terakelvin>(val);
        }
        constexpr inverse_gigakelvin operator""_inv_K(long double val) {
            return static_cast<inverse_gigakelvin>(val);
        }
        constexpr inverse_megakelvin operator""_inv_K(long double val) {
            return static_cast<inverse_megakelvin>(val);
        }
        constexpr inverse_kilokelvin operator""_inv_K(long double val) {
            return static_cast<inverse_kilokelvin>(val);
        }
        constexpr inverse_hectokelvin operator""_inv_K(long double val) {
            return static_cast<inverse_hectokelvin>(val);
        }
        constexpr inverse_decakelvin operator""_inv_K(long double val) {
            return static_cast<inverse_decakelvin>(val);
        }
        constexpr inverse_kelvin operator""_inv_K(long double val) {
            return static_cast<inverse_kelvin>(val);
        }
        constexpr inverse_decikelvin operator""_inv_K(long double val) {
            return static_cast<inverse_decikelvin>(val);
        }
        constexpr inverse_centikelvin operator""_inv_K(long double val) {
            return static_cast<inverse_centikelvin>(val);
        }
        constexpr inverse_millikelvin operator""_inv_K(long double val) {
            return static_cast<inverse_millikelvin>(val);
        }
        constexpr inverse_microkelvin operator""_inv_K(long double val) {
            return static_cast<inverse_microkelvin>(val);
        }
        constexpr inverse_nanokelvin operator""_inv_K(long double val) {
            return static_cast<inverse_nanokelvin>(val);
        }
        constexpr inverse_picokelvin operator""_inv_K(long double val) {
            return static_cast<inverse_picokelvin>(val);
        }
        constexpr inverse_femtokelvin operator""_inv_K(long double val) {
            return static_cast<inverse_femtokelvin>(val);
        }
        constexpr inverse_attokelvin operator""_inv_K(long double val) {
            return static_cast<inverse_attokelvin>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_INVERSE_KELVIN_HPP_INCLUDED