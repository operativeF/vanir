#ifndef POTATO_UNITS_WAVENUMBER_HPP_INCLUDED
#define POTATO_UNITS_WAVENUMBER_HPP_INCLUDED

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
        struct inverse_meter_impl {
            constexpr inverse_meter_impl<T, P>() : value(0) {}
            constexpr inverse_meter_impl<T, P>(P val) : value(val) {}

            P value;

            static constexpr auto pretty = "1/m";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<>, list_<meter_l>>;
        };

        using inverse_exameter    =     inverse_meter_impl<std::exa, long double>;
        using inverse_petameter    =     inverse_meter_impl<std::peta, long double>;
        using inverse_terameter    =     inverse_meter_impl<std::tera, long double>;
        using inverse_gigameter    =     inverse_meter_impl<std::giga, long double>;
        using inverse_megameter    =     inverse_meter_impl<std::mega, long double>;
        using inverse_kilometer    =     inverse_meter_impl<std::kilo, long double>;
        using inverse_hectometer    =     inverse_meter_impl<std::hecto, long double>;
        using inverse_decameter    =     inverse_meter_impl<std::deca, long double>;
        using inverse_meter    =     inverse_meter_impl<unity_ratio, long double>;
        using inverse_decimeter    =     inverse_meter_impl<std::deci, long double>;
        using inverse_centimeter    =     inverse_meter_impl<std::centi, long double>;
        using inverse_millimeter    =     inverse_meter_impl<std::milli, long double>;
        using inverse_micrometer    =     inverse_meter_impl<std::micro, long double>;
        using inverse_nanometer    =     inverse_meter_impl<std::nano, long double>;
        using inverse_picometer    =     inverse_meter_impl<std::pico, long double>;
        using inverse_femtometer    =     inverse_meter_impl<std::femto, long double>;
        using inverse_attometer    =     inverse_meter_impl<std::atto, long double>;

        constexpr inverse_exameter operator""_inv_m(long double val) {
            return static_cast<inverse_exameter>(val);
        }
        constexpr inverse_petameter operator""_inv_m(long double val) {
            return static_cast<inverse_petameter>(val);
        }
        constexpr inverse_terameter operator""_inv_m(long double val) {
            return static_cast<inverse_terameter>(val);
        }
        constexpr inverse_gigameter operator""_inv_m(long double val) {
            return static_cast<inverse_gigameter>(val);
        }
        constexpr inverse_megameter operator""_inv_m(long double val) {
            return static_cast<inverse_megameter>(val);
        }
        constexpr inverse_kilometer operator""_inv_m(long double val) {
            return static_cast<inverse_kilometer>(val);
        }
        constexpr inverse_hectometer operator""_inv_m(long double val) {
            return static_cast<inverse_hectometer>(val);
        }
        constexpr inverse_decameter operator""_inv_m(long double val) {
            return static_cast<inverse_decameter>(val);
        }
        constexpr inverse_meter operator""_inv_m(long double val) {
            return static_cast<inverse_meter>(val);
        }
        constexpr inverse_decimeter operator""_inv_m(long double val) {
            return static_cast<inverse_decimeter>(val);
        }
        constexpr inverse_centimeter operator""_inv_m(long double val) {
            return static_cast<inverse_centimeter>(val);
        }
        constexpr inverse_millimeter operator""_inv_m(long double val) {
            return static_cast<inverse_millimeter>(val);
        }
        constexpr inverse_micrometer operator""_inv_m(long double val) {
            return static_cast<inverse_micrometer>(val);
        }
        constexpr inverse_nanometer operator""_inv_m(long double val) {
            return static_cast<inverse_nanometer>(val);
        }
        constexpr inverse_picometer operator""_inv_m(long double val) {
            return static_cast<inverse_picometer>(val);
        }
        constexpr inverse_femtometer operator""_inv_m(long double val) {
            return static_cast<inverse_femtometer>(val);
        }
        constexpr inverse_attometer operator""_inv_m(long double val) {
            return static_cast<inverse_attometer>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_INVERSE_METER_HPP_INCLUDED