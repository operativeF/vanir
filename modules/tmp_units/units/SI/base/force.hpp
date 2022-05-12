#ifndef POTATO_UNITS_FORCE_HPP_INCLUDED
#define POTATO_UNITS_FORCE_HPP_INCLUDED

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
        struct newton_impl {
            // Deduce value to determine correct stored value.
            using DV = call_<if_<is_<unsigned long long>, always_<long long>, always_<P>>, P>;

            constexpr newton_impl<T, P>() : value(0) {}
            constexpr newton_impl<T, P>(DV val) : value(val) {}

            template <typename U, typename R>
            constexpr const newton_impl<T, P>(const newton_impl<U, R>& other) {
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

            static constexpr auto pretty = "F";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<gram_l, meter_l>, list_<second_l, second_l>>;
        };

        using exanewton_ld    =     newton_impl<std::exa, long double>;
        using petanewton_ld    =     newton_impl<std::peta, long double>;
        using teranewton_ld    =     newton_impl<std::tera, long double>;
        using giganewton_ld    =     newton_impl<std::giga, long double>;
        using meganewton_ld    =     newton_impl<std::mega, long double>;
        using kilonewton_ld    =     newton_impl<std::kilo, long double>;
        using hectonewton_ld    =     newton_impl<std::hecto, long double>;
        using decanewton_ld    =     newton_impl<std::deca, long double>;
        using newton_ld    =     newton_impl<unity_ratio, long double>;
        using decinewton_ld    =     newton_impl<std::deci, long double>;
        using centinewton_ld    =     newton_impl<std::centi, long double>;
        using millinewton_ld    =     newton_impl<std::milli, long double>;
        using micronewton_ld    =     newton_impl<std::micro, long double>;
        using nanonewton_ld    =     newton_impl<std::nano, long double>;
        using piconewton_ld    =     newton_impl<std::pico, long double>;
        using femtonewton_ld    =     newton_impl<std::femto, long double>;
        using attonewton_ld    =     newton_impl<std::atto, long double>;
        using exanewton_ull    =     newton_impl<std::exa, unsigned long long>;
        using petanewton_ull    =     newton_impl<std::peta, unsigned long long>;
        using teranewton_ull    =     newton_impl<std::tera, unsigned long long>;
        using giganewton_ull    =     newton_impl<std::giga, unsigned long long>;
        using meganewton_ull    =     newton_impl<std::mega, unsigned long long>;
        using kilonewton_ull    =     newton_impl<std::kilo, unsigned long long>;
        using hectonewton_ull    =     newton_impl<std::hecto, unsigned long long>;
        using decanewton_ull    =     newton_impl<std::deca, unsigned long long>;
        using newton_ull    =     newton_impl<unity_ratio, unsigned long long>;
        using decinewton_ull    =     newton_impl<std::deci, unsigned long long>;
        using centinewton_ull    =     newton_impl<std::centi, unsigned long long>;
        using millinewton_ull    =     newton_impl<std::milli, unsigned long long>;
        using micronewton_ull    =     newton_impl<std::micro, unsigned long long>;
        using nanonewton_ull    =     newton_impl<std::nano, unsigned long long>;
        using piconewton_ull    =     newton_impl<std::pico, unsigned long long>;
        using femtonewton_ull    =     newton_impl<std::femto, unsigned long long>;
        using attonewton_ull    =     newton_impl<std::atto, unsigned long long>;

        constexpr exanewton_ld operator""_EN(long double val) {
            return static_cast<exanewton_ld>(val);
        }
        constexpr petanewton_ld operator""_PN(long double val) {
            return static_cast<petanewton_ld>(val);
        }
        constexpr teranewton_ld operator""_TN(long double val) {
            return static_cast<teranewton_ld>(val);
        }
        constexpr giganewton_ld operator""_GN(long double val) {
            return static_cast<giganewton_ld>(val);
        }
        constexpr meganewton_ld operator""_MN(long double val) {
            return static_cast<meganewton_ld>(val);
        }
        constexpr kilonewton_ld operator""_kN(long double val) {
            return static_cast<kilonewton_ld>(val);
        }
        constexpr hectonewton_ld operator""_hN(long double val) {
            return static_cast<hectonewton_ld>(val);
        }
        constexpr decanewton_ld operator""_daN(long double val) {
            return static_cast<decanewton_ld>(val);
        }
        constexpr newton_ld operator""_N(long double val) {
            return static_cast<newton_ld>(val);
        }
        constexpr decinewton_ld operator""_dN(long double val) {
            return static_cast<decinewton_ld>(val);
        }
        constexpr centinewton_ld operator""_cN(long double val) {
            return static_cast<centinewton_ld>(val);
        }
        constexpr millinewton_ld operator""_mN(long double val) {
            return static_cast<millinewton_ld>(val);
        }
        constexpr micronewton_ld operator""_uN(long double val) {
            return static_cast<micronewton_ld>(val);
        }
        constexpr nanonewton_ld operator""_nN(long double val) {
            return static_cast<nanonewton_ld>(val);
        }
        constexpr piconewton_ld operator""_pN(long double val) {
            return static_cast<piconewton_ld>(val);
        }
        constexpr femtonewton_ld operator""_fN(long double val) {
            return static_cast<femtonewton_ld>(val);
        }
        constexpr attonewton_ld operator""_aN(long double val) {
            return static_cast<attonewton_ld>(val);
        }
        constexpr exanewton_ull operator""_EN(unsigned long long val) {
            return static_cast<exanewton_ull>(val);
        }
        constexpr petanewton_ull operator""_PN(unsigned long long val) {
            return static_cast<petanewton_ull>(val);
        }
        constexpr teranewton_ull operator""_TN(unsigned long long val) {
            return static_cast<teranewton_ull>(val);
        }
        constexpr giganewton_ull operator""_GN(unsigned long long val) {
            return static_cast<giganewton_ull>(val);
        }
        constexpr meganewton_ull operator""_MN(unsigned long long val) {
            return static_cast<meganewton_ull>(val);
        }
        constexpr kilonewton_ull operator""_kN(unsigned long long val) {
            return static_cast<kilonewton_ull>(val);
        }
        constexpr hectonewton_ull operator""_hN(unsigned long long val) {
            return static_cast<hectonewton_ull>(val);
        }
        constexpr decanewton_ull operator""_daN(unsigned long long val) {
            return static_cast<decanewton_ull>(val);
        }
        constexpr newton_ull operator""_N(unsigned long long val) {
            return static_cast<newton_ull>(val);
        }
        constexpr decinewton_ull operator""_dN(unsigned long long val) {
            return static_cast<decinewton_ull>(val);
        }
        constexpr centinewton_ull operator""_cN(unsigned long long val) {
            return static_cast<centinewton_ull>(val);
        }
        constexpr millinewton_ull operator""_mN(unsigned long long val) {
            return static_cast<millinewton_ull>(val);
        }
        constexpr micronewton_ull operator""_uN(unsigned long long val) {
            return static_cast<micronewton_ull>(val);
        }
        constexpr nanonewton_ull operator""_nN(unsigned long long val) {
            return static_cast<nanonewton_ull>(val);
        }
        constexpr piconewton_ull operator""_pN(unsigned long long val) {
            return static_cast<piconewton_ull>(val);
        }
        constexpr femtonewton_ull operator""_fN(unsigned long long val) {
            return static_cast<femtonewton_ull>(val);
        }
        constexpr attonewton_ull operator""_aN(unsigned long long val) {
            return static_cast<attonewton_ull>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_NEWTON_HPP_INCLUDED