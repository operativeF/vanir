#ifndef POTATO_UNITS_LUMINOUS_EXPOSURE_HPP_INCLUDED
#define POTATO_UNITS_LUMINOUS_EXPOSURE_HPP_INCLUDED

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
        struct lux_second_impl {
            // Deduce value to determine correct stored value.
            using DV = call_<if_<is_<unsigned long long>, always_<long long>, always_<P>>, P>;

            constexpr lux_second_impl<T, P>() : value(0) {}
            constexpr lux_second_impl<T, P>(DV val) : value(val) {}

            template <typename U, typename R>
            constexpr const lux_second_impl<T, P>(const lux_second_impl<U, R>& other) {
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

            static constexpr auto pretty = "s·cd/m²";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<second_l, candela_l>, list_<meter_l, meter_l>>;
        };

        using exalux_second_ld    =     lux_second_impl<std::exa, long double>;
        using petalux_second_ld    =     lux_second_impl<std::peta, long double>;
        using teralux_second_ld    =     lux_second_impl<std::tera, long double>;
        using gigalux_second_ld    =     lux_second_impl<std::giga, long double>;
        using megalux_second_ld    =     lux_second_impl<std::mega, long double>;
        using kilolux_second_ld    =     lux_second_impl<std::kilo, long double>;
        using hectolux_second_ld    =     lux_second_impl<std::hecto, long double>;
        using decalux_second_ld    =     lux_second_impl<std::deca, long double>;
        using lux_second_ld    =     lux_second_impl<unity_ratio, long double>;
        using decilux_second_ld    =     lux_second_impl<std::deci, long double>;
        using centilux_second_ld    =     lux_second_impl<std::centi, long double>;
        using millilux_second_ld    =     lux_second_impl<std::milli, long double>;
        using microlux_second_ld    =     lux_second_impl<std::micro, long double>;
        using nanolux_second_ld    =     lux_second_impl<std::nano, long double>;
        using picolux_second_ld    =     lux_second_impl<std::pico, long double>;
        using femtolux_second_ld    =     lux_second_impl<std::femto, long double>;
        using attolux_second_ld    =     lux_second_impl<std::atto, long double>;
        using exalux_second_ull    =     lux_second_impl<std::exa, unsigned long long>;
        using petalux_second_ull    =     lux_second_impl<std::peta, unsigned long long>;
        using teralux_second_ull    =     lux_second_impl<std::tera, unsigned long long>;
        using gigalux_second_ull    =     lux_second_impl<std::giga, unsigned long long>;
        using megalux_second_ull    =     lux_second_impl<std::mega, unsigned long long>;
        using kilolux_second_ull    =     lux_second_impl<std::kilo, unsigned long long>;
        using hectolux_second_ull    =     lux_second_impl<std::hecto, unsigned long long>;
        using decalux_second_ull    =     lux_second_impl<std::deca, unsigned long long>;
        using lux_second_ull    =     lux_second_impl<unity_ratio, unsigned long long>;
        using decilux_second_ull    =     lux_second_impl<std::deci, unsigned long long>;
        using centilux_second_ull    =     lux_second_impl<std::centi, unsigned long long>;
        using millilux_second_ull    =     lux_second_impl<std::milli, unsigned long long>;
        using microlux_second_ull    =     lux_second_impl<std::micro, unsigned long long>;
        using nanolux_second_ull    =     lux_second_impl<std::nano, unsigned long long>;
        using picolux_second_ull    =     lux_second_impl<std::pico, unsigned long long>;
        using femtolux_second_ull    =     lux_second_impl<std::femto, unsigned long long>;
        using attolux_second_ull    =     lux_second_impl<std::atto, unsigned long long>;

        constexpr exalux_second_ld operator""_Es_cd_per_sq_m(long double val) {
            return static_cast<exalux_second_ld>(val);
        }
        constexpr petalux_second_ld operator""_Ps_cd_per_sq_m(long double val) {
            return static_cast<petalux_second_ld>(val);
        }
        constexpr teralux_second_ld operator""_Ts_cd_per_sq_m(long double val) {
            return static_cast<teralux_second_ld>(val);
        }
        constexpr gigalux_second_ld operator""_Gs_cd_per_sq_m(long double val) {
            return static_cast<gigalux_second_ld>(val);
        }
        constexpr megalux_second_ld operator""_Ms_cd_per_sq_m(long double val) {
            return static_cast<megalux_second_ld>(val);
        }
        constexpr kilolux_second_ld operator""_ks_cd_per_sq_m(long double val) {
            return static_cast<kilolux_second_ld>(val);
        }
        constexpr hectolux_second_ld operator""_hs_cd_per_sq_m(long double val) {
            return static_cast<hectolux_second_ld>(val);
        }
        constexpr decalux_second_ld operator""_das_cd_per_sq_m(long double val) {
            return static_cast<decalux_second_ld>(val);
        }
        constexpr lux_second_ld operator""_s_cd_per_sq_m(long double val) {
            return static_cast<lux_second_ld>(val);
        }
        constexpr decilux_second_ld operator""_ds_cd_per_sq_m(long double val) {
            return static_cast<decilux_second_ld>(val);
        }
        constexpr centilux_second_ld operator""_cs_cd_per_sq_m(long double val) {
            return static_cast<centilux_second_ld>(val);
        }
        constexpr millilux_second_ld operator""_ms_cd_per_sq_m(long double val) {
            return static_cast<millilux_second_ld>(val);
        }
        constexpr microlux_second_ld operator""_us_cd_per_sq_m(long double val) {
            return static_cast<microlux_second_ld>(val);
        }
        constexpr nanolux_second_ld operator""_ns_cd_per_sq_m(long double val) {
            return static_cast<nanolux_second_ld>(val);
        }
        constexpr picolux_second_ld operator""_ps_cd_per_sq_m(long double val) {
            return static_cast<picolux_second_ld>(val);
        }
        constexpr femtolux_second_ld operator""_fs_cd_per_sq_m(long double val) {
            return static_cast<femtolux_second_ld>(val);
        }
        constexpr attolux_second_ld operator""_as_cd_per_sq_m(long double val) {
            return static_cast<attolux_second_ld>(val);
        }
        constexpr exalux_second_ull operator""_Es_cd_per_sq_m(unsigned long long val) {
            return static_cast<exalux_second_ull>(val);
        }
        constexpr petalux_second_ull operator""_Ps_cd_per_sq_m(unsigned long long val) {
            return static_cast<petalux_second_ull>(val);
        }
        constexpr teralux_second_ull operator""_Ts_cd_per_sq_m(unsigned long long val) {
            return static_cast<teralux_second_ull>(val);
        }
        constexpr gigalux_second_ull operator""_Gs_cd_per_sq_m(unsigned long long val) {
            return static_cast<gigalux_second_ull>(val);
        }
        constexpr megalux_second_ull operator""_Ms_cd_per_sq_m(unsigned long long val) {
            return static_cast<megalux_second_ull>(val);
        }
        constexpr kilolux_second_ull operator""_ks_cd_per_sq_m(unsigned long long val) {
            return static_cast<kilolux_second_ull>(val);
        }
        constexpr hectolux_second_ull operator""_hs_cd_per_sq_m(unsigned long long val) {
            return static_cast<hectolux_second_ull>(val);
        }
        constexpr decalux_second_ull operator""_das_cd_per_sq_m(unsigned long long val) {
            return static_cast<decalux_second_ull>(val);
        }
        constexpr lux_second_ull operator""_s_cd_per_sq_m(unsigned long long val) {
            return static_cast<lux_second_ull>(val);
        }
        constexpr decilux_second_ull operator""_ds_cd_per_sq_m(unsigned long long val) {
            return static_cast<decilux_second_ull>(val);
        }
        constexpr centilux_second_ull operator""_cs_cd_per_sq_m(unsigned long long val) {
            return static_cast<centilux_second_ull>(val);
        }
        constexpr millilux_second_ull operator""_ms_cd_per_sq_m(unsigned long long val) {
            return static_cast<millilux_second_ull>(val);
        }
        constexpr microlux_second_ull operator""_us_cd_per_sq_m(unsigned long long val) {
            return static_cast<microlux_second_ull>(val);
        }
        constexpr nanolux_second_ull operator""_ns_cd_per_sq_m(unsigned long long val) {
            return static_cast<nanolux_second_ull>(val);
        }
        constexpr picolux_second_ull operator""_ps_cd_per_sq_m(unsigned long long val) {
            return static_cast<picolux_second_ull>(val);
        }
        constexpr femtolux_second_ull operator""_fs_cd_per_sq_m(unsigned long long val) {
            return static_cast<femtolux_second_ull>(val);
        }
        constexpr attolux_second_ull operator""_as_cd_per_sq_m(unsigned long long val) {
            return static_cast<attolux_second_ull>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_LUX_SECOND_HPP_INCLUDED