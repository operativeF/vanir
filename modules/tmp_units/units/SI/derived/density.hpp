#ifndef POTATO_UNITS_DENSITY_HPP_INCLUDED
#define POTATO_UNITS_DENSITY_HPP_INCLUDED

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
        struct gram_per_cubic_meter_impl {
            // Deduce value to determine correct stored value.
            using DV = call_<if_<is_<unsigned long long>, always_<long long>, always_<P>>, P>;

            constexpr gram_per_cubic_meter_impl<T, P>() : value(0) {}
            constexpr gram_per_cubic_meter_impl<T, P>(DV val) : value(val) {}

            template <typename U, typename R>
            constexpr const gram_per_cubic_meter_impl<T, P>(const gram_per_cubic_meter_impl<U, R>& other) {
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

            static constexpr auto pretty = "g/m³";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<gram_l>, list_<meter_l, meter_l, meter_l>>;
        };

        using exagram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::exa, long double>;
        using petagram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::peta, long double>;
        using teragram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::tera, long double>;
        using gigagram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::giga, long double>;
        using megagram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::mega, long double>;
        using kilogram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::kilo, long double>;
        using hectogram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::hecto, long double>;
        using decagram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::deca, long double>;
        using gram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<unity_ratio, long double>;
        using decigram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::deci, long double>;
        using centigram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::centi, long double>;
        using milligram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::milli, long double>;
        using microgram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::micro, long double>;
        using nanogram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::nano, long double>;
        using picogram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::pico, long double>;
        using femtogram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::femto, long double>;
        using attogram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::atto, long double>;
        using exagram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::exa, unsigned long long>;
        using petagram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::peta, unsigned long long>;
        using teragram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::tera, unsigned long long>;
        using gigagram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::giga, unsigned long long>;
        using megagram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::mega, unsigned long long>;
        using kilogram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::kilo, unsigned long long>;
        using hectogram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::hecto, unsigned long long>;
        using decagram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::deca, unsigned long long>;
        using gram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<unity_ratio, unsigned long long>;
        using decigram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::deci, unsigned long long>;
        using centigram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::centi, unsigned long long>;
        using milligram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::milli, unsigned long long>;
        using microgram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::micro, unsigned long long>;
        using nanogram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::nano, unsigned long long>;
        using picogram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::pico, unsigned long long>;
        using femtogram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::femto, unsigned long long>;
        using attogram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::atto, unsigned long long>;

        constexpr exagram_per_cubic_meter_ld operator""_Eg_per_cubic_m(long double val) {
            return static_cast<exagram_per_cubic_meter_ld>(val);
        }
        constexpr petagram_per_cubic_meter_ld operator""_Pg_per_cubic_m(long double val) {
            return static_cast<petagram_per_cubic_meter_ld>(val);
        }
        constexpr teragram_per_cubic_meter_ld operator""_Tg_per_cubic_m(long double val) {
            return static_cast<teragram_per_cubic_meter_ld>(val);
        }
        constexpr gigagram_per_cubic_meter_ld operator""_Gg_per_cubic_m(long double val) {
            return static_cast<gigagram_per_cubic_meter_ld>(val);
        }
        constexpr megagram_per_cubic_meter_ld operator""_Mg_per_cubic_m(long double val) {
            return static_cast<megagram_per_cubic_meter_ld>(val);
        }
        constexpr kilogram_per_cubic_meter_ld operator""_kg_per_cubic_m(long double val) {
            return static_cast<kilogram_per_cubic_meter_ld>(val);
        }
        constexpr hectogram_per_cubic_meter_ld operator""_hg_per_cubic_m(long double val) {
            return static_cast<hectogram_per_cubic_meter_ld>(val);
        }
        constexpr decagram_per_cubic_meter_ld operator""_dag_per_cubic_m(long double val) {
            return static_cast<decagram_per_cubic_meter_ld>(val);
        }
        constexpr gram_per_cubic_meter_ld operator""_g_per_cubic_m(long double val) {
            return static_cast<gram_per_cubic_meter_ld>(val);
        }
        constexpr decigram_per_cubic_meter_ld operator""_dg_per_cubic_m(long double val) {
            return static_cast<decigram_per_cubic_meter_ld>(val);
        }
        constexpr centigram_per_cubic_meter_ld operator""_cg_per_cubic_m(long double val) {
            return static_cast<centigram_per_cubic_meter_ld>(val);
        }
        constexpr milligram_per_cubic_meter_ld operator""_mg_per_cubic_m(long double val) {
            return static_cast<milligram_per_cubic_meter_ld>(val);
        }
        constexpr microgram_per_cubic_meter_ld operator""_ug_per_cubic_m(long double val) {
            return static_cast<microgram_per_cubic_meter_ld>(val);
        }
        constexpr nanogram_per_cubic_meter_ld operator""_ng_per_cubic_m(long double val) {
            return static_cast<nanogram_per_cubic_meter_ld>(val);
        }
        constexpr picogram_per_cubic_meter_ld operator""_pg_per_cubic_m(long double val) {
            return static_cast<picogram_per_cubic_meter_ld>(val);
        }
        constexpr femtogram_per_cubic_meter_ld operator""_fg_per_cubic_m(long double val) {
            return static_cast<femtogram_per_cubic_meter_ld>(val);
        }
        constexpr attogram_per_cubic_meter_ld operator""_ag_per_cubic_m(long double val) {
            return static_cast<attogram_per_cubic_meter_ld>(val);
        }
        constexpr exagram_per_cubic_meter_ull operator""_Eg_per_cubic_m(unsigned long long val) {
            return static_cast<exagram_per_cubic_meter_ull>(val);
        }
        constexpr petagram_per_cubic_meter_ull operator""_Pg_per_cubic_m(unsigned long long val) {
            return static_cast<petagram_per_cubic_meter_ull>(val);
        }
        constexpr teragram_per_cubic_meter_ull operator""_Tg_per_cubic_m(unsigned long long val) {
            return static_cast<teragram_per_cubic_meter_ull>(val);
        }
        constexpr gigagram_per_cubic_meter_ull operator""_Gg_per_cubic_m(unsigned long long val) {
            return static_cast<gigagram_per_cubic_meter_ull>(val);
        }
        constexpr megagram_per_cubic_meter_ull operator""_Mg_per_cubic_m(unsigned long long val) {
            return static_cast<megagram_per_cubic_meter_ull>(val);
        }
        constexpr kilogram_per_cubic_meter_ull operator""_kg_per_cubic_m(unsigned long long val) {
            return static_cast<kilogram_per_cubic_meter_ull>(val);
        }
        constexpr hectogram_per_cubic_meter_ull operator""_hg_per_cubic_m(unsigned long long val) {
            return static_cast<hectogram_per_cubic_meter_ull>(val);
        }
        constexpr decagram_per_cubic_meter_ull operator""_dag_per_cubic_m(unsigned long long val) {
            return static_cast<decagram_per_cubic_meter_ull>(val);
        }
        constexpr gram_per_cubic_meter_ull operator""_g_per_cubic_m(unsigned long long val) {
            return static_cast<gram_per_cubic_meter_ull>(val);
        }
        constexpr decigram_per_cubic_meter_ull operator""_dg_per_cubic_m(unsigned long long val) {
            return static_cast<decigram_per_cubic_meter_ull>(val);
        }
        constexpr centigram_per_cubic_meter_ull operator""_cg_per_cubic_m(unsigned long long val) {
            return static_cast<centigram_per_cubic_meter_ull>(val);
        }
        constexpr milligram_per_cubic_meter_ull operator""_mg_per_cubic_m(unsigned long long val) {
            return static_cast<milligram_per_cubic_meter_ull>(val);
        }
        constexpr microgram_per_cubic_meter_ull operator""_ug_per_cubic_m(unsigned long long val) {
            return static_cast<microgram_per_cubic_meter_ull>(val);
        }
        constexpr nanogram_per_cubic_meter_ull operator""_ng_per_cubic_m(unsigned long long val) {
            return static_cast<nanogram_per_cubic_meter_ull>(val);
        }
        constexpr picogram_per_cubic_meter_ull operator""_pg_per_cubic_m(unsigned long long val) {
            return static_cast<picogram_per_cubic_meter_ull>(val);
        }
        constexpr femtogram_per_cubic_meter_ull operator""_fg_per_cubic_m(unsigned long long val) {
            return static_cast<femtogram_per_cubic_meter_ull>(val);
        }
        constexpr attogram_per_cubic_meter_ull operator""_ag_per_cubic_m(unsigned long long val) {
            return static_cast<attogram_per_cubic_meter_ull>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_GRAM_PER_CUBIC_METER_HPP_INCLUDED