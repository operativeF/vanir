#ifndef POTATO_UNITS_SNAP_HPP_INCLUDED
#define POTATO_UNITS_SNAP_HPP_INCLUDED

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
        struct meter_per_quartic_second_impl {
            // Deduce value to determine correct stored value.
            using DV = call_<if_<is_<unsigned long long>, always_<long long>, always_<P>>, P>;

            constexpr meter_per_quartic_second_impl<T, P>() : value(0) {}
            constexpr meter_per_quartic_second_impl<T, P>(DV val) : value(val) {}

            template <typename U, typename R>
            constexpr const meter_per_quartic_second_impl<T, P>(const meter_per_quartic_second_impl<U, R>& other) {
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

            static constexpr auto pretty = "m/s⁴";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<meter_l>, list_<second_l, second_l, second_l, second_l>>;
        };

        using exameter_per_quartic_second_ld    =     meter_per_quartic_second_impl<std::exa, long double>;
        using petameter_per_quartic_second_ld    =     meter_per_quartic_second_impl<std::peta, long double>;
        using terameter_per_quartic_second_ld    =     meter_per_quartic_second_impl<std::tera, long double>;
        using gigameter_per_quartic_second_ld    =     meter_per_quartic_second_impl<std::giga, long double>;
        using megameter_per_quartic_second_ld    =     meter_per_quartic_second_impl<std::mega, long double>;
        using kilometer_per_quartic_second_ld    =     meter_per_quartic_second_impl<std::kilo, long double>;
        using hectometer_per_quartic_second_ld    =     meter_per_quartic_second_impl<std::hecto, long double>;
        using decameter_per_quartic_second_ld    =     meter_per_quartic_second_impl<std::deca, long double>;
        using meter_per_quartic_second_ld    =     meter_per_quartic_second_impl<unity_ratio, long double>;
        using decimeter_per_quartic_second_ld    =     meter_per_quartic_second_impl<std::deci, long double>;
        using centimeter_per_quartic_second_ld    =     meter_per_quartic_second_impl<std::centi, long double>;
        using millimeter_per_quartic_second_ld    =     meter_per_quartic_second_impl<std::milli, long double>;
        using micrometer_per_quartic_second_ld    =     meter_per_quartic_second_impl<std::micro, long double>;
        using nanometer_per_quartic_second_ld    =     meter_per_quartic_second_impl<std::nano, long double>;
        using picometer_per_quartic_second_ld    =     meter_per_quartic_second_impl<std::pico, long double>;
        using femtometer_per_quartic_second_ld    =     meter_per_quartic_second_impl<std::femto, long double>;
        using attometer_per_quartic_second_ld    =     meter_per_quartic_second_impl<std::atto, long double>;
        using exameter_per_quartic_second_ull    =     meter_per_quartic_second_impl<std::exa, unsigned long long>;
        using petameter_per_quartic_second_ull    =     meter_per_quartic_second_impl<std::peta, unsigned long long>;
        using terameter_per_quartic_second_ull    =     meter_per_quartic_second_impl<std::tera, unsigned long long>;
        using gigameter_per_quartic_second_ull    =     meter_per_quartic_second_impl<std::giga, unsigned long long>;
        using megameter_per_quartic_second_ull    =     meter_per_quartic_second_impl<std::mega, unsigned long long>;
        using kilometer_per_quartic_second_ull    =     meter_per_quartic_second_impl<std::kilo, unsigned long long>;
        using hectometer_per_quartic_second_ull    =     meter_per_quartic_second_impl<std::hecto, unsigned long long>;
        using decameter_per_quartic_second_ull    =     meter_per_quartic_second_impl<std::deca, unsigned long long>;
        using meter_per_quartic_second_ull    =     meter_per_quartic_second_impl<unity_ratio, unsigned long long>;
        using decimeter_per_quartic_second_ull    =     meter_per_quartic_second_impl<std::deci, unsigned long long>;
        using centimeter_per_quartic_second_ull    =     meter_per_quartic_second_impl<std::centi, unsigned long long>;
        using millimeter_per_quartic_second_ull    =     meter_per_quartic_second_impl<std::milli, unsigned long long>;
        using micrometer_per_quartic_second_ull    =     meter_per_quartic_second_impl<std::micro, unsigned long long>;
        using nanometer_per_quartic_second_ull    =     meter_per_quartic_second_impl<std::nano, unsigned long long>;
        using picometer_per_quartic_second_ull    =     meter_per_quartic_second_impl<std::pico, unsigned long long>;
        using femtometer_per_quartic_second_ull    =     meter_per_quartic_second_impl<std::femto, unsigned long long>;
        using attometer_per_quartic_second_ull    =     meter_per_quartic_second_impl<std::atto, unsigned long long>;

        constexpr exameter_per_quartic_second_ld operator""_Em_per_quartic_s(long double val) {
            return static_cast<exameter_per_quartic_second_ld>(val);
        }
        constexpr petameter_per_quartic_second_ld operator""_Pm_per_quartic_s(long double val) {
            return static_cast<petameter_per_quartic_second_ld>(val);
        }
        constexpr terameter_per_quartic_second_ld operator""_Tm_per_quartic_s(long double val) {
            return static_cast<terameter_per_quartic_second_ld>(val);
        }
        constexpr gigameter_per_quartic_second_ld operator""_Gm_per_quartic_s(long double val) {
            return static_cast<gigameter_per_quartic_second_ld>(val);
        }
        constexpr megameter_per_quartic_second_ld operator""_Mm_per_quartic_s(long double val) {
            return static_cast<megameter_per_quartic_second_ld>(val);
        }
        constexpr kilometer_per_quartic_second_ld operator""_km_per_quartic_s(long double val) {
            return static_cast<kilometer_per_quartic_second_ld>(val);
        }
        constexpr hectometer_per_quartic_second_ld operator""_hm_per_quartic_s(long double val) {
            return static_cast<hectometer_per_quartic_second_ld>(val);
        }
        constexpr decameter_per_quartic_second_ld operator""_dam_per_quartic_s(long double val) {
            return static_cast<decameter_per_quartic_second_ld>(val);
        }
        constexpr meter_per_quartic_second_ld operator""_m_per_quartic_s(long double val) {
            return static_cast<meter_per_quartic_second_ld>(val);
        }
        constexpr decimeter_per_quartic_second_ld operator""_dm_per_quartic_s(long double val) {
            return static_cast<decimeter_per_quartic_second_ld>(val);
        }
        constexpr centimeter_per_quartic_second_ld operator""_cm_per_quartic_s(long double val) {
            return static_cast<centimeter_per_quartic_second_ld>(val);
        }
        constexpr millimeter_per_quartic_second_ld operator""_mm_per_quartic_s(long double val) {
            return static_cast<millimeter_per_quartic_second_ld>(val);
        }
        constexpr micrometer_per_quartic_second_ld operator""_um_per_quartic_s(long double val) {
            return static_cast<micrometer_per_quartic_second_ld>(val);
        }
        constexpr nanometer_per_quartic_second_ld operator""_nm_per_quartic_s(long double val) {
            return static_cast<nanometer_per_quartic_second_ld>(val);
        }
        constexpr picometer_per_quartic_second_ld operator""_pm_per_quartic_s(long double val) {
            return static_cast<picometer_per_quartic_second_ld>(val);
        }
        constexpr femtometer_per_quartic_second_ld operator""_fm_per_quartic_s(long double val) {
            return static_cast<femtometer_per_quartic_second_ld>(val);
        }
        constexpr attometer_per_quartic_second_ld operator""_am_per_quartic_s(long double val) {
            return static_cast<attometer_per_quartic_second_ld>(val);
        }
        constexpr exameter_per_quartic_second_ull operator""_Em_per_quartic_s(unsigned long long val) {
            return static_cast<exameter_per_quartic_second_ull>(val);
        }
        constexpr petameter_per_quartic_second_ull operator""_Pm_per_quartic_s(unsigned long long val) {
            return static_cast<petameter_per_quartic_second_ull>(val);
        }
        constexpr terameter_per_quartic_second_ull operator""_Tm_per_quartic_s(unsigned long long val) {
            return static_cast<terameter_per_quartic_second_ull>(val);
        }
        constexpr gigameter_per_quartic_second_ull operator""_Gm_per_quartic_s(unsigned long long val) {
            return static_cast<gigameter_per_quartic_second_ull>(val);
        }
        constexpr megameter_per_quartic_second_ull operator""_Mm_per_quartic_s(unsigned long long val) {
            return static_cast<megameter_per_quartic_second_ull>(val);
        }
        constexpr kilometer_per_quartic_second_ull operator""_km_per_quartic_s(unsigned long long val) {
            return static_cast<kilometer_per_quartic_second_ull>(val);
        }
        constexpr hectometer_per_quartic_second_ull operator""_hm_per_quartic_s(unsigned long long val) {
            return static_cast<hectometer_per_quartic_second_ull>(val);
        }
        constexpr decameter_per_quartic_second_ull operator""_dam_per_quartic_s(unsigned long long val) {
            return static_cast<decameter_per_quartic_second_ull>(val);
        }
        constexpr meter_per_quartic_second_ull operator""_m_per_quartic_s(unsigned long long val) {
            return static_cast<meter_per_quartic_second_ull>(val);
        }
        constexpr decimeter_per_quartic_second_ull operator""_dm_per_quartic_s(unsigned long long val) {
            return static_cast<decimeter_per_quartic_second_ull>(val);
        }
        constexpr centimeter_per_quartic_second_ull operator""_cm_per_quartic_s(unsigned long long val) {
            return static_cast<centimeter_per_quartic_second_ull>(val);
        }
        constexpr millimeter_per_quartic_second_ull operator""_mm_per_quartic_s(unsigned long long val) {
            return static_cast<millimeter_per_quartic_second_ull>(val);
        }
        constexpr micrometer_per_quartic_second_ull operator""_um_per_quartic_s(unsigned long long val) {
            return static_cast<micrometer_per_quartic_second_ull>(val);
        }
        constexpr nanometer_per_quartic_second_ull operator""_nm_per_quartic_s(unsigned long long val) {
            return static_cast<nanometer_per_quartic_second_ull>(val);
        }
        constexpr picometer_per_quartic_second_ull operator""_pm_per_quartic_s(unsigned long long val) {
            return static_cast<picometer_per_quartic_second_ull>(val);
        }
        constexpr femtometer_per_quartic_second_ull operator""_fm_per_quartic_s(unsigned long long val) {
            return static_cast<femtometer_per_quartic_second_ull>(val);
        }
        constexpr attometer_per_quartic_second_ull operator""_am_per_quartic_s(unsigned long long val) {
            return static_cast<attometer_per_quartic_second_ull>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_METER_PER_QUARTIC_SECOND_HPP_INCLUDED