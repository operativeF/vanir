#ifndef POTATO_UNITS_CATALYTIC_ACTIVITY_HPP_INCLUDED
#define POTATO_UNITS_CATALYTIC_ACTIVITY_HPP_INCLUDED

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
        struct katal_impl {
            // Deduce value to determine correct stored value.
            using DV = call_<if_<is_<unsigned long long>, always_<long long>, always_<P>>, P>;

            constexpr katal_impl<T, P>() : value(0) {}
            constexpr katal_impl<T, P>(DV val) : value(val) {}

            template <typename U, typename R>
            constexpr const katal_impl<T, P>(const katal_impl<U, R>& other) {
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

            static constexpr auto pretty = "kat";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<mole_l>, list_<second_l>>;
        };

        using exakatal_ld    =     katal_impl<std::exa, long double>;
        using petakatal_ld    =     katal_impl<std::peta, long double>;
        using terakatal_ld    =     katal_impl<std::tera, long double>;
        using gigakatal_ld    =     katal_impl<std::giga, long double>;
        using megakatal_ld    =     katal_impl<std::mega, long double>;
        using kilokatal_ld    =     katal_impl<std::kilo, long double>;
        using hectokatal_ld    =     katal_impl<std::hecto, long double>;
        using decakatal_ld    =     katal_impl<std::deca, long double>;
        using katal_ld    =     katal_impl<unity_ratio, long double>;
        using decikatal_ld    =     katal_impl<std::deci, long double>;
        using centikatal_ld    =     katal_impl<std::centi, long double>;
        using millikatal_ld    =     katal_impl<std::milli, long double>;
        using microkatal_ld    =     katal_impl<std::micro, long double>;
        using nanokatal_ld    =     katal_impl<std::nano, long double>;
        using picokatal_ld    =     katal_impl<std::pico, long double>;
        using femtokatal_ld    =     katal_impl<std::femto, long double>;
        using attokatal_ld    =     katal_impl<std::atto, long double>;
        using exakatal_ull    =     katal_impl<std::exa, unsigned long long>;
        using petakatal_ull    =     katal_impl<std::peta, unsigned long long>;
        using terakatal_ull    =     katal_impl<std::tera, unsigned long long>;
        using gigakatal_ull    =     katal_impl<std::giga, unsigned long long>;
        using megakatal_ull    =     katal_impl<std::mega, unsigned long long>;
        using kilokatal_ull    =     katal_impl<std::kilo, unsigned long long>;
        using hectokatal_ull    =     katal_impl<std::hecto, unsigned long long>;
        using decakatal_ull    =     katal_impl<std::deca, unsigned long long>;
        using katal_ull    =     katal_impl<unity_ratio, unsigned long long>;
        using decikatal_ull    =     katal_impl<std::deci, unsigned long long>;
        using centikatal_ull    =     katal_impl<std::centi, unsigned long long>;
        using millikatal_ull    =     katal_impl<std::milli, unsigned long long>;
        using microkatal_ull    =     katal_impl<std::micro, unsigned long long>;
        using nanokatal_ull    =     katal_impl<std::nano, unsigned long long>;
        using picokatal_ull    =     katal_impl<std::pico, unsigned long long>;
        using femtokatal_ull    =     katal_impl<std::femto, unsigned long long>;
        using attokatal_ull    =     katal_impl<std::atto, unsigned long long>;

        constexpr exakatal_ld operator""_Ekat(long double val) {
            return static_cast<exakatal_ld>(val);
        }
        constexpr petakatal_ld operator""_Pkat(long double val) {
            return static_cast<petakatal_ld>(val);
        }
        constexpr terakatal_ld operator""_Tkat(long double val) {
            return static_cast<terakatal_ld>(val);
        }
        constexpr gigakatal_ld operator""_Gkat(long double val) {
            return static_cast<gigakatal_ld>(val);
        }
        constexpr megakatal_ld operator""_Mkat(long double val) {
            return static_cast<megakatal_ld>(val);
        }
        constexpr kilokatal_ld operator""_kkat(long double val) {
            return static_cast<kilokatal_ld>(val);
        }
        constexpr hectokatal_ld operator""_hkat(long double val) {
            return static_cast<hectokatal_ld>(val);
        }
        constexpr decakatal_ld operator""_dakat(long double val) {
            return static_cast<decakatal_ld>(val);
        }
        constexpr katal_ld operator""_kat(long double val) {
            return static_cast<katal_ld>(val);
        }
        constexpr decikatal_ld operator""_dkat(long double val) {
            return static_cast<decikatal_ld>(val);
        }
        constexpr centikatal_ld operator""_ckat(long double val) {
            return static_cast<centikatal_ld>(val);
        }
        constexpr millikatal_ld operator""_mkat(long double val) {
            return static_cast<millikatal_ld>(val);
        }
        constexpr microkatal_ld operator""_ukat(long double val) {
            return static_cast<microkatal_ld>(val);
        }
        constexpr nanokatal_ld operator""_nkat(long double val) {
            return static_cast<nanokatal_ld>(val);
        }
        constexpr picokatal_ld operator""_pkat(long double val) {
            return static_cast<picokatal_ld>(val);
        }
        constexpr femtokatal_ld operator""_fkat(long double val) {
            return static_cast<femtokatal_ld>(val);
        }
        constexpr attokatal_ld operator""_akat(long double val) {
            return static_cast<attokatal_ld>(val);
        }
        constexpr exakatal_ull operator""_Ekat(unsigned long long val) {
            return static_cast<exakatal_ull>(val);
        }
        constexpr petakatal_ull operator""_Pkat(unsigned long long val) {
            return static_cast<petakatal_ull>(val);
        }
        constexpr terakatal_ull operator""_Tkat(unsigned long long val) {
            return static_cast<terakatal_ull>(val);
        }
        constexpr gigakatal_ull operator""_Gkat(unsigned long long val) {
            return static_cast<gigakatal_ull>(val);
        }
        constexpr megakatal_ull operator""_Mkat(unsigned long long val) {
            return static_cast<megakatal_ull>(val);
        }
        constexpr kilokatal_ull operator""_kkat(unsigned long long val) {
            return static_cast<kilokatal_ull>(val);
        }
        constexpr hectokatal_ull operator""_hkat(unsigned long long val) {
            return static_cast<hectokatal_ull>(val);
        }
        constexpr decakatal_ull operator""_dakat(unsigned long long val) {
            return static_cast<decakatal_ull>(val);
        }
        constexpr katal_ull operator""_kat(unsigned long long val) {
            return static_cast<katal_ull>(val);
        }
        constexpr decikatal_ull operator""_dkat(unsigned long long val) {
            return static_cast<decikatal_ull>(val);
        }
        constexpr centikatal_ull operator""_ckat(unsigned long long val) {
            return static_cast<centikatal_ull>(val);
        }
        constexpr millikatal_ull operator""_mkat(unsigned long long val) {
            return static_cast<millikatal_ull>(val);
        }
        constexpr microkatal_ull operator""_ukat(unsigned long long val) {
            return static_cast<microkatal_ull>(val);
        }
        constexpr nanokatal_ull operator""_nkat(unsigned long long val) {
            return static_cast<nanokatal_ull>(val);
        }
        constexpr picokatal_ull operator""_pkat(unsigned long long val) {
            return static_cast<picokatal_ull>(val);
        }
        constexpr femtokatal_ull operator""_fkat(unsigned long long val) {
            return static_cast<femtokatal_ull>(val);
        }
        constexpr attokatal_ull operator""_akat(unsigned long long val) {
            return static_cast<attokatal_ull>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_KATAL_HPP_INCLUDED