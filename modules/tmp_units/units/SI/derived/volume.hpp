#ifndef POTATO_UNITS_VOLUME_HPP_INCLUDED
#define POTATO_UNITS_VOLUME_HPP_INCLUDED

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
        struct cubic_meter_impl {
            // Deduce value to determine correct stored value.
            using DV = call_<if_<is_<unsigned long long>, always_<long long>, always_<P>>, P>;

            constexpr cubic_meter_impl<T, P>() : value(0) {}
            constexpr cubic_meter_impl<T, P>(DV val) : value(val) {}

            template <typename U, typename R>
            constexpr const cubic_meter_impl<T, P>(const cubic_meter_impl<U, R>& other) {
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

            static constexpr auto pretty = "m³";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<meter_l, meter_l, meter_l>, list_<>>;
        };

        using cubic_exameter_ld    =     cubic_meter_impl<std::exa, long double>;
        using cubic_petameter_ld    =     cubic_meter_impl<std::peta, long double>;
        using cubic_terameter_ld    =     cubic_meter_impl<std::tera, long double>;
        using cubic_gigameter_ld    =     cubic_meter_impl<std::giga, long double>;
        using cubic_megameter_ld    =     cubic_meter_impl<std::mega, long double>;
        using cubic_kilometer_ld    =     cubic_meter_impl<std::kilo, long double>;
        using cubic_hectometer_ld    =     cubic_meter_impl<std::hecto, long double>;
        using cubic_decameter_ld    =     cubic_meter_impl<std::deca, long double>;
        using cubic_meter_ld    =     cubic_meter_impl<unity_ratio, long double>;
        using cubic_decimeter_ld    =     cubic_meter_impl<std::deci, long double>;
        using cubic_centimeter_ld    =     cubic_meter_impl<std::centi, long double>;
        using cubic_millimeter_ld    =     cubic_meter_impl<std::milli, long double>;
        using cubic_micrometer_ld    =     cubic_meter_impl<std::micro, long double>;
        using cubic_nanometer_ld    =     cubic_meter_impl<std::nano, long double>;
        using cubic_picometer_ld    =     cubic_meter_impl<std::pico, long double>;
        using cubic_femtometer_ld    =     cubic_meter_impl<std::femto, long double>;
        using cubic_attometer_ld    =     cubic_meter_impl<std::atto, long double>;
        using cubic_exameter_ull    =     cubic_meter_impl<std::exa, unsigned long long>;
        using cubic_petameter_ull    =     cubic_meter_impl<std::peta, unsigned long long>;
        using cubic_terameter_ull    =     cubic_meter_impl<std::tera, unsigned long long>;
        using cubic_gigameter_ull    =     cubic_meter_impl<std::giga, unsigned long long>;
        using cubic_megameter_ull    =     cubic_meter_impl<std::mega, unsigned long long>;
        using cubic_kilometer_ull    =     cubic_meter_impl<std::kilo, unsigned long long>;
        using cubic_hectometer_ull    =     cubic_meter_impl<std::hecto, unsigned long long>;
        using cubic_decameter_ull    =     cubic_meter_impl<std::deca, unsigned long long>;
        using cubic_meter_ull    =     cubic_meter_impl<unity_ratio, unsigned long long>;
        using cubic_decimeter_ull    =     cubic_meter_impl<std::deci, unsigned long long>;
        using cubic_centimeter_ull    =     cubic_meter_impl<std::centi, unsigned long long>;
        using cubic_millimeter_ull    =     cubic_meter_impl<std::milli, unsigned long long>;
        using cubic_micrometer_ull    =     cubic_meter_impl<std::micro, unsigned long long>;
        using cubic_nanometer_ull    =     cubic_meter_impl<std::nano, unsigned long long>;
        using cubic_picometer_ull    =     cubic_meter_impl<std::pico, unsigned long long>;
        using cubic_femtometer_ull    =     cubic_meter_impl<std::femto, unsigned long long>;
        using cubic_attometer_ull    =     cubic_meter_impl<std::atto, unsigned long long>;

        constexpr cubic_exameter_ld operator""_cubic_Em(long double val) {
            return static_cast<cubic_exameter_ld>(val);
        }
        constexpr cubic_petameter_ld operator""_cubic_Pm(long double val) {
            return static_cast<cubic_petameter_ld>(val);
        }
        constexpr cubic_terameter_ld operator""_cubic_Tm(long double val) {
            return static_cast<cubic_terameter_ld>(val);
        }
        constexpr cubic_gigameter_ld operator""_cubic_Gm(long double val) {
            return static_cast<cubic_gigameter_ld>(val);
        }
        constexpr cubic_megameter_ld operator""_cubic_Mm(long double val) {
            return static_cast<cubic_megameter_ld>(val);
        }
        constexpr cubic_kilometer_ld operator""_cubic_km(long double val) {
            return static_cast<cubic_kilometer_ld>(val);
        }
        constexpr cubic_hectometer_ld operator""_cubic_hm(long double val) {
            return static_cast<cubic_hectometer_ld>(val);
        }
        constexpr cubic_decameter_ld operator""_cubic_dam(long double val) {
            return static_cast<cubic_decameter_ld>(val);
        }
        constexpr cubic_meter_ld operator""_cubic_m(long double val) {
            return static_cast<cubic_meter_ld>(val);
        }
        constexpr cubic_decimeter_ld operator""_cubic_dm(long double val) {
            return static_cast<cubic_decimeter_ld>(val);
        }
        constexpr cubic_centimeter_ld operator""_cubic_cm(long double val) {
            return static_cast<cubic_centimeter_ld>(val);
        }
        constexpr cubic_millimeter_ld operator""_cubic_mm(long double val) {
            return static_cast<cubic_millimeter_ld>(val);
        }
        constexpr cubic_micrometer_ld operator""_cubic_um(long double val) {
            return static_cast<cubic_micrometer_ld>(val);
        }
        constexpr cubic_nanometer_ld operator""_cubic_nm(long double val) {
            return static_cast<cubic_nanometer_ld>(val);
        }
        constexpr cubic_picometer_ld operator""_cubic_pm(long double val) {
            return static_cast<cubic_picometer_ld>(val);
        }
        constexpr cubic_femtometer_ld operator""_cubic_fm(long double val) {
            return static_cast<cubic_femtometer_ld>(val);
        }
        constexpr cubic_attometer_ld operator""_cubic_am(long double val) {
            return static_cast<cubic_attometer_ld>(val);
        }
        constexpr cubic_exameter_ull operator""_cubic_Em(unsigned long long val) {
            return static_cast<cubic_exameter_ull>(val);
        }
        constexpr cubic_petameter_ull operator""_cubic_Pm(unsigned long long val) {
            return static_cast<cubic_petameter_ull>(val);
        }
        constexpr cubic_terameter_ull operator""_cubic_Tm(unsigned long long val) {
            return static_cast<cubic_terameter_ull>(val);
        }
        constexpr cubic_gigameter_ull operator""_cubic_Gm(unsigned long long val) {
            return static_cast<cubic_gigameter_ull>(val);
        }
        constexpr cubic_megameter_ull operator""_cubic_Mm(unsigned long long val) {
            return static_cast<cubic_megameter_ull>(val);
        }
        constexpr cubic_kilometer_ull operator""_cubic_km(unsigned long long val) {
            return static_cast<cubic_kilometer_ull>(val);
        }
        constexpr cubic_hectometer_ull operator""_cubic_hm(unsigned long long val) {
            return static_cast<cubic_hectometer_ull>(val);
        }
        constexpr cubic_decameter_ull operator""_cubic_dam(unsigned long long val) {
            return static_cast<cubic_decameter_ull>(val);
        }
        constexpr cubic_meter_ull operator""_cubic_m(unsigned long long val) {
            return static_cast<cubic_meter_ull>(val);
        }
        constexpr cubic_decimeter_ull operator""_cubic_dm(unsigned long long val) {
            return static_cast<cubic_decimeter_ull>(val);
        }
        constexpr cubic_centimeter_ull operator""_cubic_cm(unsigned long long val) {
            return static_cast<cubic_centimeter_ull>(val);
        }
        constexpr cubic_millimeter_ull operator""_cubic_mm(unsigned long long val) {
            return static_cast<cubic_millimeter_ull>(val);
        }
        constexpr cubic_micrometer_ull operator""_cubic_um(unsigned long long val) {
            return static_cast<cubic_micrometer_ull>(val);
        }
        constexpr cubic_nanometer_ull operator""_cubic_nm(unsigned long long val) {
            return static_cast<cubic_nanometer_ull>(val);
        }
        constexpr cubic_picometer_ull operator""_cubic_pm(unsigned long long val) {
            return static_cast<cubic_picometer_ull>(val);
        }
        constexpr cubic_femtometer_ull operator""_cubic_fm(unsigned long long val) {
            return static_cast<cubic_femtometer_ull>(val);
        }
        constexpr cubic_attometer_ull operator""_cubic_am(unsigned long long val) {
            return static_cast<cubic_attometer_ull>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_CUBIC_METER_HPP_INCLUDED