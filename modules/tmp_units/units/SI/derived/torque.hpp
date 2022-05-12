#ifndef POTATO_UNITS_TORQUE_HPP_INCLUDED
#define POTATO_UNITS_TORQUE_HPP_INCLUDED

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
        struct newton_meter_impl {
            // Deduce value to determine correct stored value.
            using DV = call_<if_<is_<unsigned long long>, always_<long long>, always_<P>>, P>;

            constexpr newton_meter_impl<T, P>() : value(0) {}
            constexpr newton_meter_impl<T, P>(DV val) : value(val) {}

            template <typename U>
            constexpr const newton_meter_impl<T, P>(const newton_meter_impl<U, DV>& other) {
            using scale = call_<if_<lift_<std::ratio_greater>,
                always_<std::ratio_divide<U, T>>,
                if_<lift_<std::ratio_less>,
                always_<std::ratio_divide<T, U>>,
                always_<unity_ratio>>>,
                T, U>;
                value       = other.value * (scale::num / scale::den);
            }

            DV value = 0;

            static constexpr auto pretty = "N·m";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<meter_l, meter_l, gram_l>, list_<second_l, second_l>>;
        };

        using exanewton_meter_ld    =     newton_meter_impl<std::exa, long double>;
        using petanewton_meter_ld    =     newton_meter_impl<std::peta, long double>;
        using teranewton_meter_ld    =     newton_meter_impl<std::tera, long double>;
        using giganewton_meter_ld    =     newton_meter_impl<std::giga, long double>;
        using meganewton_meter_ld    =     newton_meter_impl<std::mega, long double>;
        using kilonewton_meter_ld    =     newton_meter_impl<std::kilo, long double>;
        using hectonewton_meter_ld    =     newton_meter_impl<std::hecto, long double>;
        using decanewton_meter_ld    =     newton_meter_impl<std::deca, long double>;
        using newton_meter_ld    =     newton_meter_impl<unity_ratio, long double>;
        using decinewton_meter_ld    =     newton_meter_impl<std::deci, long double>;
        using centinewton_meter_ld    =     newton_meter_impl<std::centi, long double>;
        using millinewton_meter_ld    =     newton_meter_impl<std::milli, long double>;
        using micronewton_meter_ld    =     newton_meter_impl<std::micro, long double>;
        using nanonewton_meter_ld    =     newton_meter_impl<std::nano, long double>;
        using piconewton_meter_ld    =     newton_meter_impl<std::pico, long double>;
        using femtonewton_meter_ld    =     newton_meter_impl<std::femto, long double>;
        using attonewton_meter_ld    =     newton_meter_impl<std::atto, long double>;
        using exanewton_meter_ull    =     newton_meter_impl<std::exa, unsigned long long>;
        using petanewton_meter_ull    =     newton_meter_impl<std::peta, unsigned long long>;
        using teranewton_meter_ull    =     newton_meter_impl<std::tera, unsigned long long>;
        using giganewton_meter_ull    =     newton_meter_impl<std::giga, unsigned long long>;
        using meganewton_meter_ull    =     newton_meter_impl<std::mega, unsigned long long>;
        using kilonewton_meter_ull    =     newton_meter_impl<std::kilo, unsigned long long>;
        using hectonewton_meter_ull    =     newton_meter_impl<std::hecto, unsigned long long>;
        using decanewton_meter_ull    =     newton_meter_impl<std::deca, unsigned long long>;
        using newton_meter_ull    =     newton_meter_impl<unity_ratio, unsigned long long>;
        using decinewton_meter_ull    =     newton_meter_impl<std::deci, unsigned long long>;
        using centinewton_meter_ull    =     newton_meter_impl<std::centi, unsigned long long>;
        using millinewton_meter_ull    =     newton_meter_impl<std::milli, unsigned long long>;
        using micronewton_meter_ull    =     newton_meter_impl<std::micro, unsigned long long>;
        using nanonewton_meter_ull    =     newton_meter_impl<std::nano, unsigned long long>;
        using piconewton_meter_ull    =     newton_meter_impl<std::pico, unsigned long long>;
        using femtonewton_meter_ull    =     newton_meter_impl<std::femto, unsigned long long>;
        using attonewton_meter_ull    =     newton_meter_impl<std::atto, unsigned long long>;

        constexpr exanewton_meter_ld operator""_EN_m(long double val) {
            return static_cast<exanewton_meter_ld>(val);
        }
        constexpr petanewton_meter_ld operator""_PN_m(long double val) {
            return static_cast<petanewton_meter_ld>(val);
        }
        constexpr teranewton_meter_ld operator""_TN_m(long double val) {
            return static_cast<teranewton_meter_ld>(val);
        }
        constexpr giganewton_meter_ld operator""_GN_m(long double val) {
            return static_cast<giganewton_meter_ld>(val);
        }
        constexpr meganewton_meter_ld operator""_MN_m(long double val) {
            return static_cast<meganewton_meter_ld>(val);
        }
        constexpr kilonewton_meter_ld operator""_kN_m(long double val) {
            return static_cast<kilonewton_meter_ld>(val);
        }
        constexpr hectonewton_meter_ld operator""_hN_m(long double val) {
            return static_cast<hectonewton_meter_ld>(val);
        }
        constexpr decanewton_meter_ld operator""_daN_m(long double val) {
            return static_cast<decanewton_meter_ld>(val);
        }
        constexpr newton_meter_ld operator""_N_m(long double val) {
            return static_cast<newton_meter_ld>(val);
        }
        constexpr decinewton_meter_ld operator""_dN_m(long double val) {
            return static_cast<decinewton_meter_ld>(val);
        }
        constexpr centinewton_meter_ld operator""_cN_m(long double val) {
            return static_cast<centinewton_meter_ld>(val);
        }
        constexpr millinewton_meter_ld operator""_mN_m(long double val) {
            return static_cast<millinewton_meter_ld>(val);
        }
        constexpr micronewton_meter_ld operator""_uN_m(long double val) {
            return static_cast<micronewton_meter_ld>(val);
        }
        constexpr nanonewton_meter_ld operator""_nN_m(long double val) {
            return static_cast<nanonewton_meter_ld>(val);
        }
        constexpr piconewton_meter_ld operator""_pN_m(long double val) {
            return static_cast<piconewton_meter_ld>(val);
        }
        constexpr femtonewton_meter_ld operator""_fN_m(long double val) {
            return static_cast<femtonewton_meter_ld>(val);
        }
        constexpr attonewton_meter_ld operator""_aN_m(long double val) {
            return static_cast<attonewton_meter_ld>(val);
        }
        constexpr exanewton_meter_ull operator""_EN_m(unsigned long long val) {
            return static_cast<exanewton_meter_ull>(val);
        }
        constexpr petanewton_meter_ull operator""_PN_m(unsigned long long val) {
            return static_cast<petanewton_meter_ull>(val);
        }
        constexpr teranewton_meter_ull operator""_TN_m(unsigned long long val) {
            return static_cast<teranewton_meter_ull>(val);
        }
        constexpr giganewton_meter_ull operator""_GN_m(unsigned long long val) {
            return static_cast<giganewton_meter_ull>(val);
        }
        constexpr meganewton_meter_ull operator""_MN_m(unsigned long long val) {
            return static_cast<meganewton_meter_ull>(val);
        }
        constexpr kilonewton_meter_ull operator""_kN_m(unsigned long long val) {
            return static_cast<kilonewton_meter_ull>(val);
        }
        constexpr hectonewton_meter_ull operator""_hN_m(unsigned long long val) {
            return static_cast<hectonewton_meter_ull>(val);
        }
        constexpr decanewton_meter_ull operator""_daN_m(unsigned long long val) {
            return static_cast<decanewton_meter_ull>(val);
        }
        constexpr newton_meter_ull operator""_N_m(unsigned long long val) {
            return static_cast<newton_meter_ull>(val);
        }
        constexpr decinewton_meter_ull operator""_dN_m(unsigned long long val) {
            return static_cast<decinewton_meter_ull>(val);
        }
        constexpr centinewton_meter_ull operator""_cN_m(unsigned long long val) {
            return static_cast<centinewton_meter_ull>(val);
        }
        constexpr millinewton_meter_ull operator""_mN_m(unsigned long long val) {
            return static_cast<millinewton_meter_ull>(val);
        }
        constexpr micronewton_meter_ull operator""_uN_m(unsigned long long val) {
            return static_cast<micronewton_meter_ull>(val);
        }
        constexpr nanonewton_meter_ull operator""_nN_m(unsigned long long val) {
            return static_cast<nanonewton_meter_ull>(val);
        }
        constexpr piconewton_meter_ull operator""_pN_m(unsigned long long val) {
            return static_cast<piconewton_meter_ull>(val);
        }
        constexpr femtonewton_meter_ull operator""_fN_m(unsigned long long val) {
            return static_cast<femtonewton_meter_ull>(val);
        }
        constexpr attonewton_meter_ull operator""_aN_m(unsigned long long val) {
            return static_cast<attonewton_meter_ull>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_NEWTON_METER_HPP_INCLUDED