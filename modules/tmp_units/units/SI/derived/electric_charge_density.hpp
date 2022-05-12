#ifndef POTATO_UNITS_ELECTRIC_CHARGE_DENSITY_HPP_INCLUDED
#define POTATO_UNITS_ELECTRIC_CHARGE_DENSITY_HPP_INCLUDED

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
        struct coulomb_per_cubic_meter_impl {
            // Deduce value to determine correct stored value.
            using DV = call_<if_<is_<unsigned long long>, always_<long long>, always_<P>>, P>;

            constexpr coulomb_per_cubic_meter_impl<T, P>() : value(0) {}
            constexpr coulomb_per_cubic_meter_impl<T, P>(DV val) : value(val) {}

            template <typename U, typename R>
            constexpr const coulomb_per_cubic_meter_impl<T, P>(const coulomb_per_cubic_meter_impl<U, R>& other) {
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

            static constexpr auto pretty = "C/m³";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<second_l, ampere_l>, list_<meter_l, meter_l, meter_l>>;
        };

        using exacoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::exa, long double>;
        using petacoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::peta, long double>;
        using teracoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::tera, long double>;
        using gigacoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::giga, long double>;
        using megacoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::mega, long double>;
        using kilocoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::kilo, long double>;
        using hectocoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::hecto, long double>;
        using decacoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::deca, long double>;
        using coulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<unity_ratio, long double>;
        using decicoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::deci, long double>;
        using centicoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::centi, long double>;
        using millicoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::milli, long double>;
        using microcoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::micro, long double>;
        using nanocoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::nano, long double>;
        using picocoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::pico, long double>;
        using femtocoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::femto, long double>;
        using attocoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::atto, long double>;
        using exacoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::exa, unsigned long long>;
        using petacoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::peta, unsigned long long>;
        using teracoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::tera, unsigned long long>;
        using gigacoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::giga, unsigned long long>;
        using megacoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::mega, unsigned long long>;
        using kilocoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::kilo, unsigned long long>;
        using hectocoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::hecto, unsigned long long>;
        using decacoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::deca, unsigned long long>;
        using coulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<unity_ratio, unsigned long long>;
        using decicoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::deci, unsigned long long>;
        using centicoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::centi, unsigned long long>;
        using millicoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::milli, unsigned long long>;
        using microcoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::micro, unsigned long long>;
        using nanocoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::nano, unsigned long long>;
        using picocoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::pico, unsigned long long>;
        using femtocoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::femto, unsigned long long>;
        using attocoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::atto, unsigned long long>;

        constexpr exacoulomb_per_cubic_meter_ld operator""_EC_per_cubic_m(long double val) {
            return static_cast<exacoulomb_per_cubic_meter_ld>(val);
        }
        constexpr petacoulomb_per_cubic_meter_ld operator""_PC_per_cubic_m(long double val) {
            return static_cast<petacoulomb_per_cubic_meter_ld>(val);
        }
        constexpr teracoulomb_per_cubic_meter_ld operator""_TC_per_cubic_m(long double val) {
            return static_cast<teracoulomb_per_cubic_meter_ld>(val);
        }
        constexpr gigacoulomb_per_cubic_meter_ld operator""_GC_per_cubic_m(long double val) {
            return static_cast<gigacoulomb_per_cubic_meter_ld>(val);
        }
        constexpr megacoulomb_per_cubic_meter_ld operator""_MC_per_cubic_m(long double val) {
            return static_cast<megacoulomb_per_cubic_meter_ld>(val);
        }
        constexpr kilocoulomb_per_cubic_meter_ld operator""_kC_per_cubic_m(long double val) {
            return static_cast<kilocoulomb_per_cubic_meter_ld>(val);
        }
        constexpr hectocoulomb_per_cubic_meter_ld operator""_hC_per_cubic_m(long double val) {
            return static_cast<hectocoulomb_per_cubic_meter_ld>(val);
        }
        constexpr decacoulomb_per_cubic_meter_ld operator""_daC_per_cubic_m(long double val) {
            return static_cast<decacoulomb_per_cubic_meter_ld>(val);
        }
        constexpr coulomb_per_cubic_meter_ld operator""_C_per_cubic_m(long double val) {
            return static_cast<coulomb_per_cubic_meter_ld>(val);
        }
        constexpr decicoulomb_per_cubic_meter_ld operator""_dC_per_cubic_m(long double val) {
            return static_cast<decicoulomb_per_cubic_meter_ld>(val);
        }
        constexpr centicoulomb_per_cubic_meter_ld operator""_cC_per_cubic_m(long double val) {
            return static_cast<centicoulomb_per_cubic_meter_ld>(val);
        }
        constexpr millicoulomb_per_cubic_meter_ld operator""_mC_per_cubic_m(long double val) {
            return static_cast<millicoulomb_per_cubic_meter_ld>(val);
        }
        constexpr microcoulomb_per_cubic_meter_ld operator""_uC_per_cubic_m(long double val) {
            return static_cast<microcoulomb_per_cubic_meter_ld>(val);
        }
        constexpr nanocoulomb_per_cubic_meter_ld operator""_nC_per_cubic_m(long double val) {
            return static_cast<nanocoulomb_per_cubic_meter_ld>(val);
        }
        constexpr picocoulomb_per_cubic_meter_ld operator""_pC_per_cubic_m(long double val) {
            return static_cast<picocoulomb_per_cubic_meter_ld>(val);
        }
        constexpr femtocoulomb_per_cubic_meter_ld operator""_fC_per_cubic_m(long double val) {
            return static_cast<femtocoulomb_per_cubic_meter_ld>(val);
        }
        constexpr attocoulomb_per_cubic_meter_ld operator""_aC_per_cubic_m(long double val) {
            return static_cast<attocoulomb_per_cubic_meter_ld>(val);
        }
        constexpr exacoulomb_per_cubic_meter_ull operator""_EC_per_cubic_m(unsigned long long val) {
            return static_cast<exacoulomb_per_cubic_meter_ull>(val);
        }
        constexpr petacoulomb_per_cubic_meter_ull operator""_PC_per_cubic_m(unsigned long long val) {
            return static_cast<petacoulomb_per_cubic_meter_ull>(val);
        }
        constexpr teracoulomb_per_cubic_meter_ull operator""_TC_per_cubic_m(unsigned long long val) {
            return static_cast<teracoulomb_per_cubic_meter_ull>(val);
        }
        constexpr gigacoulomb_per_cubic_meter_ull operator""_GC_per_cubic_m(unsigned long long val) {
            return static_cast<gigacoulomb_per_cubic_meter_ull>(val);
        }
        constexpr megacoulomb_per_cubic_meter_ull operator""_MC_per_cubic_m(unsigned long long val) {
            return static_cast<megacoulomb_per_cubic_meter_ull>(val);
        }
        constexpr kilocoulomb_per_cubic_meter_ull operator""_kC_per_cubic_m(unsigned long long val) {
            return static_cast<kilocoulomb_per_cubic_meter_ull>(val);
        }
        constexpr hectocoulomb_per_cubic_meter_ull operator""_hC_per_cubic_m(unsigned long long val) {
            return static_cast<hectocoulomb_per_cubic_meter_ull>(val);
        }
        constexpr decacoulomb_per_cubic_meter_ull operator""_daC_per_cubic_m(unsigned long long val) {
            return static_cast<decacoulomb_per_cubic_meter_ull>(val);
        }
        constexpr coulomb_per_cubic_meter_ull operator""_C_per_cubic_m(unsigned long long val) {
            return static_cast<coulomb_per_cubic_meter_ull>(val);
        }
        constexpr decicoulomb_per_cubic_meter_ull operator""_dC_per_cubic_m(unsigned long long val) {
            return static_cast<decicoulomb_per_cubic_meter_ull>(val);
        }
        constexpr centicoulomb_per_cubic_meter_ull operator""_cC_per_cubic_m(unsigned long long val) {
            return static_cast<centicoulomb_per_cubic_meter_ull>(val);
        }
        constexpr millicoulomb_per_cubic_meter_ull operator""_mC_per_cubic_m(unsigned long long val) {
            return static_cast<millicoulomb_per_cubic_meter_ull>(val);
        }
        constexpr microcoulomb_per_cubic_meter_ull operator""_uC_per_cubic_m(unsigned long long val) {
            return static_cast<microcoulomb_per_cubic_meter_ull>(val);
        }
        constexpr nanocoulomb_per_cubic_meter_ull operator""_nC_per_cubic_m(unsigned long long val) {
            return static_cast<nanocoulomb_per_cubic_meter_ull>(val);
        }
        constexpr picocoulomb_per_cubic_meter_ull operator""_pC_per_cubic_m(unsigned long long val) {
            return static_cast<picocoulomb_per_cubic_meter_ull>(val);
        }
        constexpr femtocoulomb_per_cubic_meter_ull operator""_fC_per_cubic_m(unsigned long long val) {
            return static_cast<femtocoulomb_per_cubic_meter_ull>(val);
        }
        constexpr attocoulomb_per_cubic_meter_ull operator""_aC_per_cubic_m(unsigned long long val) {
            return static_cast<attocoulomb_per_cubic_meter_ull>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_COULOMB_PER_CUBIC_METER_HPP_INCLUDED