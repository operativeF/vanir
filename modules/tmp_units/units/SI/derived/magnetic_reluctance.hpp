#ifndef POTATO_UNITS_MAGNETIC_RELUCTANCE_HPP_INCLUDED
#define POTATO_UNITS_MAGNETIC_RELUCTANCE_HPP_INCLUDED

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
        struct inverse_henry_impl {
            constexpr inverse_henry_impl<T, P>() : value(0) {}
            constexpr inverse_henry_impl<T, P>(P val) : value(val) {}

            P value;

            static constexpr auto pretty = "1/H";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<second_l, second_l, ampere_l, ampere_l>, list_<meter_l, meter_l, gram_l>>;
        };

        using inverse_exahenry    =     inverse_henry_impl<std::exa, long double>;
        using inverse_petahenry    =     inverse_henry_impl<std::peta, long double>;
        using inverse_terahenry    =     inverse_henry_impl<std::tera, long double>;
        using inverse_gigahenry    =     inverse_henry_impl<std::giga, long double>;
        using inverse_megahenry    =     inverse_henry_impl<std::mega, long double>;
        using inverse_kilohenry    =     inverse_henry_impl<std::kilo, long double>;
        using inverse_hectohenry    =     inverse_henry_impl<std::hecto, long double>;
        using inverse_decahenry    =     inverse_henry_impl<std::deca, long double>;
        using inverse_henry    =     inverse_henry_impl<unity_ratio, long double>;
        using inverse_decihenry    =     inverse_henry_impl<std::deci, long double>;
        using inverse_centihenry    =     inverse_henry_impl<std::centi, long double>;
        using inverse_millihenry    =     inverse_henry_impl<std::milli, long double>;
        using inverse_microhenry    =     inverse_henry_impl<std::micro, long double>;
        using inverse_nanohenry    =     inverse_henry_impl<std::nano, long double>;
        using inverse_picohenry    =     inverse_henry_impl<std::pico, long double>;
        using inverse_femtohenry    =     inverse_henry_impl<std::femto, long double>;
        using inverse_attohenry    =     inverse_henry_impl<std::atto, long double>;

        constexpr inverse_exahenry operator""_inv_H(long double val) {
            return static_cast<inverse_exahenry>(val);
        }
        constexpr inverse_petahenry operator""_inv_H(long double val) {
            return static_cast<inverse_petahenry>(val);
        }
        constexpr inverse_terahenry operator""_inv_H(long double val) {
            return static_cast<inverse_terahenry>(val);
        }
        constexpr inverse_gigahenry operator""_inv_H(long double val) {
            return static_cast<inverse_gigahenry>(val);
        }
        constexpr inverse_megahenry operator""_inv_H(long double val) {
            return static_cast<inverse_megahenry>(val);
        }
        constexpr inverse_kilohenry operator""_inv_H(long double val) {
            return static_cast<inverse_kilohenry>(val);
        }
        constexpr inverse_hectohenry operator""_inv_H(long double val) {
            return static_cast<inverse_hectohenry>(val);
        }
        constexpr inverse_decahenry operator""_inv_H(long double val) {
            return static_cast<inverse_decahenry>(val);
        }
        constexpr inverse_henry operator""_inv_H(long double val) {
            return static_cast<inverse_henry>(val);
        }
        constexpr inverse_decihenry operator""_inv_H(long double val) {
            return static_cast<inverse_decihenry>(val);
        }
        constexpr inverse_centihenry operator""_inv_H(long double val) {
            return static_cast<inverse_centihenry>(val);
        }
        constexpr inverse_millihenry operator""_inv_H(long double val) {
            return static_cast<inverse_millihenry>(val);
        }
        constexpr inverse_microhenry operator""_inv_H(long double val) {
            return static_cast<inverse_microhenry>(val);
        }
        constexpr inverse_nanohenry operator""_inv_H(long double val) {
            return static_cast<inverse_nanohenry>(val);
        }
        constexpr inverse_picohenry operator""_inv_H(long double val) {
            return static_cast<inverse_picohenry>(val);
        }
        constexpr inverse_femtohenry operator""_inv_H(long double val) {
            return static_cast<inverse_femtohenry>(val);
        }
        constexpr inverse_attohenry operator""_inv_H(long double val) {
            return static_cast<inverse_attohenry>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_INVERSE_HENRY_HPP_INCLUDED