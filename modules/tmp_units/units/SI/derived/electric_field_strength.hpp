#ifndef POTATO_UNITS_ELECTRIC_FIELD_STRENGTH_HPP_INCLUDED
#define POTATO_UNITS_ELECTRIC_FIELD_STRENGTH_HPP_INCLUDED

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
        struct volt_per_meter_impl {
            // Deduce value to determine correct stored value.
            using DV = call_<if_<is_<unsigned long long>, always_<long long>, always_<P>>, P>;

            constexpr volt_per_meter_impl<T, P>() : value(0) {}
            constexpr volt_per_meter_impl<T, P>(DV val) : value(val) {}

            template <typename U, typename R>
            constexpr const volt_per_meter_impl<T, P>(const volt_per_meter_impl<U, R>& other) {
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

            static constexpr auto pretty = "V/m";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<meter_l, gram_l>, list_<second_l, second_l, second_l, ampere_l>>;
        };

        using exavolt_per_meter_ld    =     volt_per_meter_impl<std::exa, long double>;
        using petavolt_per_meter_ld    =     volt_per_meter_impl<std::peta, long double>;
        using teravolt_per_meter_ld    =     volt_per_meter_impl<std::tera, long double>;
        using gigavolt_per_meter_ld    =     volt_per_meter_impl<std::giga, long double>;
        using megavolt_per_meter_ld    =     volt_per_meter_impl<std::mega, long double>;
        using kilovolt_per_meter_ld    =     volt_per_meter_impl<std::kilo, long double>;
        using hectovolt_per_meter_ld    =     volt_per_meter_impl<std::hecto, long double>;
        using decavolt_per_meter_ld    =     volt_per_meter_impl<std::deca, long double>;
        using volt_per_meter_ld    =     volt_per_meter_impl<unity_ratio, long double>;
        using decivolt_per_meter_ld    =     volt_per_meter_impl<std::deci, long double>;
        using centivolt_per_meter_ld    =     volt_per_meter_impl<std::centi, long double>;
        using millivolt_per_meter_ld    =     volt_per_meter_impl<std::milli, long double>;
        using microvolt_per_meter_ld    =     volt_per_meter_impl<std::micro, long double>;
        using nanovolt_per_meter_ld    =     volt_per_meter_impl<std::nano, long double>;
        using picovolt_per_meter_ld    =     volt_per_meter_impl<std::pico, long double>;
        using femtovolt_per_meter_ld    =     volt_per_meter_impl<std::femto, long double>;
        using attovolt_per_meter_ld    =     volt_per_meter_impl<std::atto, long double>;
        using exavolt_per_meter_ull    =     volt_per_meter_impl<std::exa, unsigned long long>;
        using petavolt_per_meter_ull    =     volt_per_meter_impl<std::peta, unsigned long long>;
        using teravolt_per_meter_ull    =     volt_per_meter_impl<std::tera, unsigned long long>;
        using gigavolt_per_meter_ull    =     volt_per_meter_impl<std::giga, unsigned long long>;
        using megavolt_per_meter_ull    =     volt_per_meter_impl<std::mega, unsigned long long>;
        using kilovolt_per_meter_ull    =     volt_per_meter_impl<std::kilo, unsigned long long>;
        using hectovolt_per_meter_ull    =     volt_per_meter_impl<std::hecto, unsigned long long>;
        using decavolt_per_meter_ull    =     volt_per_meter_impl<std::deca, unsigned long long>;
        using volt_per_meter_ull    =     volt_per_meter_impl<unity_ratio, unsigned long long>;
        using decivolt_per_meter_ull    =     volt_per_meter_impl<std::deci, unsigned long long>;
        using centivolt_per_meter_ull    =     volt_per_meter_impl<std::centi, unsigned long long>;
        using millivolt_per_meter_ull    =     volt_per_meter_impl<std::milli, unsigned long long>;
        using microvolt_per_meter_ull    =     volt_per_meter_impl<std::micro, unsigned long long>;
        using nanovolt_per_meter_ull    =     volt_per_meter_impl<std::nano, unsigned long long>;
        using picovolt_per_meter_ull    =     volt_per_meter_impl<std::pico, unsigned long long>;
        using femtovolt_per_meter_ull    =     volt_per_meter_impl<std::femto, unsigned long long>;
        using attovolt_per_meter_ull    =     volt_per_meter_impl<std::atto, unsigned long long>;

        constexpr exavolt_per_meter_ld operator""_EV_per_m(long double val) {
            return static_cast<exavolt_per_meter_ld>(val);
        }
        constexpr petavolt_per_meter_ld operator""_PV_per_m(long double val) {
            return static_cast<petavolt_per_meter_ld>(val);
        }
        constexpr teravolt_per_meter_ld operator""_TV_per_m(long double val) {
            return static_cast<teravolt_per_meter_ld>(val);
        }
        constexpr gigavolt_per_meter_ld operator""_GV_per_m(long double val) {
            return static_cast<gigavolt_per_meter_ld>(val);
        }
        constexpr megavolt_per_meter_ld operator""_MV_per_m(long double val) {
            return static_cast<megavolt_per_meter_ld>(val);
        }
        constexpr kilovolt_per_meter_ld operator""_kV_per_m(long double val) {
            return static_cast<kilovolt_per_meter_ld>(val);
        }
        constexpr hectovolt_per_meter_ld operator""_hV_per_m(long double val) {
            return static_cast<hectovolt_per_meter_ld>(val);
        }
        constexpr decavolt_per_meter_ld operator""_daV_per_m(long double val) {
            return static_cast<decavolt_per_meter_ld>(val);
        }
        constexpr volt_per_meter_ld operator""_V_per_m(long double val) {
            return static_cast<volt_per_meter_ld>(val);
        }
        constexpr decivolt_per_meter_ld operator""_dV_per_m(long double val) {
            return static_cast<decivolt_per_meter_ld>(val);
        }
        constexpr centivolt_per_meter_ld operator""_cV_per_m(long double val) {
            return static_cast<centivolt_per_meter_ld>(val);
        }
        constexpr millivolt_per_meter_ld operator""_mV_per_m(long double val) {
            return static_cast<millivolt_per_meter_ld>(val);
        }
        constexpr microvolt_per_meter_ld operator""_uV_per_m(long double val) {
            return static_cast<microvolt_per_meter_ld>(val);
        }
        constexpr nanovolt_per_meter_ld operator""_nV_per_m(long double val) {
            return static_cast<nanovolt_per_meter_ld>(val);
        }
        constexpr picovolt_per_meter_ld operator""_pV_per_m(long double val) {
            return static_cast<picovolt_per_meter_ld>(val);
        }
        constexpr femtovolt_per_meter_ld operator""_fV_per_m(long double val) {
            return static_cast<femtovolt_per_meter_ld>(val);
        }
        constexpr attovolt_per_meter_ld operator""_aV_per_m(long double val) {
            return static_cast<attovolt_per_meter_ld>(val);
        }
        constexpr exavolt_per_meter_ull operator""_EV_per_m(unsigned long long val) {
            return static_cast<exavolt_per_meter_ull>(val);
        }
        constexpr petavolt_per_meter_ull operator""_PV_per_m(unsigned long long val) {
            return static_cast<petavolt_per_meter_ull>(val);
        }
        constexpr teravolt_per_meter_ull operator""_TV_per_m(unsigned long long val) {
            return static_cast<teravolt_per_meter_ull>(val);
        }
        constexpr gigavolt_per_meter_ull operator""_GV_per_m(unsigned long long val) {
            return static_cast<gigavolt_per_meter_ull>(val);
        }
        constexpr megavolt_per_meter_ull operator""_MV_per_m(unsigned long long val) {
            return static_cast<megavolt_per_meter_ull>(val);
        }
        constexpr kilovolt_per_meter_ull operator""_kV_per_m(unsigned long long val) {
            return static_cast<kilovolt_per_meter_ull>(val);
        }
        constexpr hectovolt_per_meter_ull operator""_hV_per_m(unsigned long long val) {
            return static_cast<hectovolt_per_meter_ull>(val);
        }
        constexpr decavolt_per_meter_ull operator""_daV_per_m(unsigned long long val) {
            return static_cast<decavolt_per_meter_ull>(val);
        }
        constexpr volt_per_meter_ull operator""_V_per_m(unsigned long long val) {
            return static_cast<volt_per_meter_ull>(val);
        }
        constexpr decivolt_per_meter_ull operator""_dV_per_m(unsigned long long val) {
            return static_cast<decivolt_per_meter_ull>(val);
        }
        constexpr centivolt_per_meter_ull operator""_cV_per_m(unsigned long long val) {
            return static_cast<centivolt_per_meter_ull>(val);
        }
        constexpr millivolt_per_meter_ull operator""_mV_per_m(unsigned long long val) {
            return static_cast<millivolt_per_meter_ull>(val);
        }
        constexpr microvolt_per_meter_ull operator""_uV_per_m(unsigned long long val) {
            return static_cast<microvolt_per_meter_ull>(val);
        }
        constexpr nanovolt_per_meter_ull operator""_nV_per_m(unsigned long long val) {
            return static_cast<nanovolt_per_meter_ull>(val);
        }
        constexpr picovolt_per_meter_ull operator""_pV_per_m(unsigned long long val) {
            return static_cast<picovolt_per_meter_ull>(val);
        }
        constexpr femtovolt_per_meter_ull operator""_fV_per_m(unsigned long long val) {
            return static_cast<femtovolt_per_meter_ull>(val);
        }
        constexpr attovolt_per_meter_ull operator""_aV_per_m(unsigned long long val) {
            return static_cast<attovolt_per_meter_ull>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_VOLT_PER_METER_HPP_INCLUDED