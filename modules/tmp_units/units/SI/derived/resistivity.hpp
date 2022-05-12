#ifndef POTATO_UNITS_RESISTIVITY_HPP_INCLUDED
#define POTATO_UNITS_RESISTIVITY_HPP_INCLUDED

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
        struct ohm_meter_impl {
            // Deduce value to determine correct stored value.
            using DV = call_<if_<is_<unsigned long long>, always_<long long>, always_<P>>, P>;

            constexpr ohm_meter_impl<T, P>() : value(0) {}
            constexpr ohm_meter_impl<T, P>(DV val) : value(val) {}

            template <typename U, typename R>
            constexpr const ohm_meter_impl<T, P>(const ohm_meter_impl<U, R>& other) {
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

            static constexpr auto pretty = "Ω·m";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<meter_l, meter_l, meter_l, gram_l>, list_<second_l, second_l, second_l, ampere_l, ampere_l>>;
        };

        using exaohm_meter_ld    =     ohm_meter_impl<std::exa, long double>;
        using petaohm_meter_ld    =     ohm_meter_impl<std::peta, long double>;
        using teraohm_meter_ld    =     ohm_meter_impl<std::tera, long double>;
        using gigaohm_meter_ld    =     ohm_meter_impl<std::giga, long double>;
        using megaohm_meter_ld    =     ohm_meter_impl<std::mega, long double>;
        using kiloohm_meter_ld    =     ohm_meter_impl<std::kilo, long double>;
        using hectoohm_meter_ld    =     ohm_meter_impl<std::hecto, long double>;
        using decaohm_meter_ld    =     ohm_meter_impl<std::deca, long double>;
        using ohm_meter_ld    =     ohm_meter_impl<unity_ratio, long double>;
        using deciohm_meter_ld    =     ohm_meter_impl<std::deci, long double>;
        using centiohm_meter_ld    =     ohm_meter_impl<std::centi, long double>;
        using milliohm_meter_ld    =     ohm_meter_impl<std::milli, long double>;
        using microohm_meter_ld    =     ohm_meter_impl<std::micro, long double>;
        using nanoohm_meter_ld    =     ohm_meter_impl<std::nano, long double>;
        using picoohm_meter_ld    =     ohm_meter_impl<std::pico, long double>;
        using femtoohm_meter_ld    =     ohm_meter_impl<std::femto, long double>;
        using attoohm_meter_ld    =     ohm_meter_impl<std::atto, long double>;
        using exaohm_meter_ull    =     ohm_meter_impl<std::exa, unsigned long long>;
        using petaohm_meter_ull    =     ohm_meter_impl<std::peta, unsigned long long>;
        using teraohm_meter_ull    =     ohm_meter_impl<std::tera, unsigned long long>;
        using gigaohm_meter_ull    =     ohm_meter_impl<std::giga, unsigned long long>;
        using megaohm_meter_ull    =     ohm_meter_impl<std::mega, unsigned long long>;
        using kiloohm_meter_ull    =     ohm_meter_impl<std::kilo, unsigned long long>;
        using hectoohm_meter_ull    =     ohm_meter_impl<std::hecto, unsigned long long>;
        using decaohm_meter_ull    =     ohm_meter_impl<std::deca, unsigned long long>;
        using ohm_meter_ull    =     ohm_meter_impl<unity_ratio, unsigned long long>;
        using deciohm_meter_ull    =     ohm_meter_impl<std::deci, unsigned long long>;
        using centiohm_meter_ull    =     ohm_meter_impl<std::centi, unsigned long long>;
        using milliohm_meter_ull    =     ohm_meter_impl<std::milli, unsigned long long>;
        using microohm_meter_ull    =     ohm_meter_impl<std::micro, unsigned long long>;
        using nanoohm_meter_ull    =     ohm_meter_impl<std::nano, unsigned long long>;
        using picoohm_meter_ull    =     ohm_meter_impl<std::pico, unsigned long long>;
        using femtoohm_meter_ull    =     ohm_meter_impl<std::femto, unsigned long long>;
        using attoohm_meter_ull    =     ohm_meter_impl<std::atto, unsigned long long>;

        constexpr exaohm_meter_ld operator""_Eohm_m(long double val) {
            return static_cast<exaohm_meter_ld>(val);
        }
        constexpr petaohm_meter_ld operator""_Pohm_m(long double val) {
            return static_cast<petaohm_meter_ld>(val);
        }
        constexpr teraohm_meter_ld operator""_Tohm_m(long double val) {
            return static_cast<teraohm_meter_ld>(val);
        }
        constexpr gigaohm_meter_ld operator""_Gohm_m(long double val) {
            return static_cast<gigaohm_meter_ld>(val);
        }
        constexpr megaohm_meter_ld operator""_Mohm_m(long double val) {
            return static_cast<megaohm_meter_ld>(val);
        }
        constexpr kiloohm_meter_ld operator""_kohm_m(long double val) {
            return static_cast<kiloohm_meter_ld>(val);
        }
        constexpr hectoohm_meter_ld operator""_hohm_m(long double val) {
            return static_cast<hectoohm_meter_ld>(val);
        }
        constexpr decaohm_meter_ld operator""_daohm_m(long double val) {
            return static_cast<decaohm_meter_ld>(val);
        }
        constexpr ohm_meter_ld operator""_ohm_m(long double val) {
            return static_cast<ohm_meter_ld>(val);
        }
        constexpr deciohm_meter_ld operator""_dohm_m(long double val) {
            return static_cast<deciohm_meter_ld>(val);
        }
        constexpr centiohm_meter_ld operator""_cohm_m(long double val) {
            return static_cast<centiohm_meter_ld>(val);
        }
        constexpr milliohm_meter_ld operator""_mohm_m(long double val) {
            return static_cast<milliohm_meter_ld>(val);
        }
        constexpr microohm_meter_ld operator""_uohm_m(long double val) {
            return static_cast<microohm_meter_ld>(val);
        }
        constexpr nanoohm_meter_ld operator""_nohm_m(long double val) {
            return static_cast<nanoohm_meter_ld>(val);
        }
        constexpr picoohm_meter_ld operator""_pohm_m(long double val) {
            return static_cast<picoohm_meter_ld>(val);
        }
        constexpr femtoohm_meter_ld operator""_fohm_m(long double val) {
            return static_cast<femtoohm_meter_ld>(val);
        }
        constexpr attoohm_meter_ld operator""_aohm_m(long double val) {
            return static_cast<attoohm_meter_ld>(val);
        }
        constexpr exaohm_meter_ull operator""_Eohm_m(unsigned long long val) {
            return static_cast<exaohm_meter_ull>(val);
        }
        constexpr petaohm_meter_ull operator""_Pohm_m(unsigned long long val) {
            return static_cast<petaohm_meter_ull>(val);
        }
        constexpr teraohm_meter_ull operator""_Tohm_m(unsigned long long val) {
            return static_cast<teraohm_meter_ull>(val);
        }
        constexpr gigaohm_meter_ull operator""_Gohm_m(unsigned long long val) {
            return static_cast<gigaohm_meter_ull>(val);
        }
        constexpr megaohm_meter_ull operator""_Mohm_m(unsigned long long val) {
            return static_cast<megaohm_meter_ull>(val);
        }
        constexpr kiloohm_meter_ull operator""_kohm_m(unsigned long long val) {
            return static_cast<kiloohm_meter_ull>(val);
        }
        constexpr hectoohm_meter_ull operator""_hohm_m(unsigned long long val) {
            return static_cast<hectoohm_meter_ull>(val);
        }
        constexpr decaohm_meter_ull operator""_daohm_m(unsigned long long val) {
            return static_cast<decaohm_meter_ull>(val);
        }
        constexpr ohm_meter_ull operator""_ohm_m(unsigned long long val) {
            return static_cast<ohm_meter_ull>(val);
        }
        constexpr deciohm_meter_ull operator""_dohm_m(unsigned long long val) {
            return static_cast<deciohm_meter_ull>(val);
        }
        constexpr centiohm_meter_ull operator""_cohm_m(unsigned long long val) {
            return static_cast<centiohm_meter_ull>(val);
        }
        constexpr milliohm_meter_ull operator""_mohm_m(unsigned long long val) {
            return static_cast<milliohm_meter_ull>(val);
        }
        constexpr microohm_meter_ull operator""_uohm_m(unsigned long long val) {
            return static_cast<microohm_meter_ull>(val);
        }
        constexpr nanoohm_meter_ull operator""_nohm_m(unsigned long long val) {
            return static_cast<nanoohm_meter_ull>(val);
        }
        constexpr picoohm_meter_ull operator""_pohm_m(unsigned long long val) {
            return static_cast<picoohm_meter_ull>(val);
        }
        constexpr femtoohm_meter_ull operator""_fohm_m(unsigned long long val) {
            return static_cast<femtoohm_meter_ull>(val);
        }
        constexpr attoohm_meter_ull operator""_aohm_m(unsigned long long val) {
            return static_cast<attoohm_meter_ull>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_OHM_METER_HPP_INCLUDED