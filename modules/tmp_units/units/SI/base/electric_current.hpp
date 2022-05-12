#ifndef POTATO_UNITS_ELECTRIC_CURRENT_HPP_INCLUDED
#define POTATO_UNITS_ELECTRIC_CURRENT_HPP_INCLUDED

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
        struct ampere_impl {
            constexpr ampere_impl<T, P>(P val) : value{val} {}

            template <typename U>
            constexpr ampere_impl<T, P>(const ampere_impl<U, P>& other) {
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

            P value = 0;

            static constexpr auto pretty = "I";

            using is_any_impl = false_;

            using mod_ratio = T;
            using numer_type = P;
            using impl      = list_<list_<ampere_l>, list_<>>;
        };

        using exaampere_ld    =     ampere_impl<std::exa, long double>;
        using petaampere_ld    =     ampere_impl<std::peta, long double>;
        using teraampere_ld    =     ampere_impl<std::tera, long double>;
        using gigaampere_ld    =     ampere_impl<std::giga, long double>;
        using megaampere_ld    =     ampere_impl<std::mega, long double>;
        using kiloampere_ld    =     ampere_impl<std::kilo, long double>;
        using hectoampere_ld    =     ampere_impl<std::hecto, long double>;
        using decaampere_ld    =     ampere_impl<std::deca, long double>;
        using ampere_ld    =     ampere_impl<unity_ratio, long double>;
        using deciampere_ld    =     ampere_impl<std::deci, long double>;
        using centiampere_ld    =     ampere_impl<std::centi, long double>;
        using milliampere_ld    =     ampere_impl<std::milli, long double>;
        using microampere_ld    =     ampere_impl<std::micro, long double>;
        using nanoampere_ld    =     ampere_impl<std::nano, long double>;
        using picoampere_ld    =     ampere_impl<std::pico, long double>;
        using femtoampere_ld    =     ampere_impl<std::femto, long double>;
        using attoampere_ld    =     ampere_impl<std::atto, long double>;
        using exaampere_ull    =     ampere_impl<std::exa, unsigned long long>;
        using petaampere_ull    =     ampere_impl<std::peta, unsigned long long>;
        using teraampere_ull    =     ampere_impl<std::tera, unsigned long long>;
        using gigaampere_ull    =     ampere_impl<std::giga, unsigned long long>;
        using megaampere_ull    =     ampere_impl<std::mega, unsigned long long>;
        using kiloampere_ull    =     ampere_impl<std::kilo, unsigned long long>;
        using hectoampere_ull    =     ampere_impl<std::hecto, unsigned long long>;
        using decaampere_ull    =     ampere_impl<std::deca, unsigned long long>;
        using ampere_ull    =     ampere_impl<unity_ratio, unsigned long long>;
        using deciampere_ull    =     ampere_impl<std::deci, unsigned long long>;
        using centiampere_ull    =     ampere_impl<std::centi, unsigned long long>;
        using milliampere_ull    =     ampere_impl<std::milli, unsigned long long>;
        using microampere_ull    =     ampere_impl<std::micro, unsigned long long>;
        using nanoampere_ull    =     ampere_impl<std::nano, unsigned long long>;
        using picoampere_ull    =     ampere_impl<std::pico, unsigned long long>;
        using femtoampere_ull    =     ampere_impl<std::femto, unsigned long long>;
        using attoampere_ull    =     ampere_impl<std::atto, unsigned long long>;

        constexpr exaampere_ld operator""_EA(long double val) {
            return {val};
        }
        constexpr petaampere_ld operator""_PA(long double val) {
            return {val};
        }
        constexpr teraampere_ld operator""_TA(long double val) {
            return {val};
        }
        constexpr gigaampere_ld operator""_GA(long double val) {
            return {val};
        }
        constexpr megaampere_ld operator""_MA(long double val) {
            return {val};
        }
        constexpr kiloampere_ld operator""_kA(long double val) {
            return {val};
        }
        constexpr hectoampere_ld operator""_hA(long double val) {
            return {val};
        }
        constexpr decaampere_ld operator""_daA(long double val) {
            return {val};
        }
        constexpr ampere_ld operator""_A(long double val) {
            return {val};
        }
        constexpr deciampere_ld operator""_dA(long double val) {
            return {val};
        }
        constexpr centiampere_ld operator""_cA(long double val) {
            return {val};
        }
        constexpr milliampere_ld operator""_mA(long double val) {
            return {val};
        }
        constexpr microampere_ld operator""_uA(long double val) {
            return {val};
        }
        constexpr nanoampere_ld operator""_nA(long double val) {
            return {val};
        }
        constexpr picoampere_ld operator""_pA(long double val) {
            return {val};
        }
        constexpr femtoampere_ld operator""_fA(long double val) {
            return {val};
        }
        constexpr attoampere_ld operator""_aA(long double val) {
            return {val};
        }
        constexpr exaampere_ull operator""_EA(unsigned long long val) {
            return {val};
        }
        constexpr petaampere_ull operator""_PA(unsigned long long val) {
            return {val};
        }
        constexpr teraampere_ull operator""_TA(unsigned long long val) {
            return {val};
        }
        constexpr gigaampere_ull operator""_GA(unsigned long long val) {
            return {val};
        }
        constexpr megaampere_ull operator""_MA(unsigned long long val) {
            return {val};
        }
        constexpr kiloampere_ull operator""_kA(unsigned long long val) {
            return {val};
        }
        constexpr hectoampere_ull operator""_hA(unsigned long long val) {
            return {val};
        }
        constexpr decaampere_ull operator""_daA(unsigned long long val) {
            return {val};
        }
        constexpr ampere_ull operator""_A(unsigned long long val) {
            return {val};
        }
        constexpr deciampere_ull operator""_dA(unsigned long long val) {
            return {val};
        }
        constexpr centiampere_ull operator""_cA(unsigned long long val) {
            return {val};
        }
        constexpr milliampere_ull operator""_mA(unsigned long long val) {
            return {val};
        }
        constexpr microampere_ull operator""_uA(unsigned long long val) {
            return {val};
        }
        constexpr nanoampere_ull operator""_nA(unsigned long long val) {
            return {val};
        }
        constexpr picoampere_ull operator""_pA(unsigned long long val) {
            return {val};
        }
        constexpr femtoampere_ull operator""_fA(unsigned long long val) {
            return {val};
        }
        constexpr attoampere_ull operator""_aA(unsigned long long val) {
            return {val};
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_AMPERE_HPP_INCLUDED