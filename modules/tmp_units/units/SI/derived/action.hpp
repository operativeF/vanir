#ifndef POTATO_UNITS_ACTION_HPP_INCLUDED
#define POTATO_UNITS_ACTION_HPP_INCLUDED

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
        struct joule_second_impl {
            // Deduce value to determine correct stored value.
            using DV = call_<if_<is_<unsigned long long>, always_<long long>, always_<P>>, P>;

            constexpr joule_second_impl<T, P>() : value(0) {}
            constexpr joule_second_impl<T, P>(DV val) : value(val) {}

            template <typename U, typename R>
            constexpr const joule_second_impl<T, P>(const joule_second_impl<U, R>& other) {
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

            static constexpr auto pretty = "J·s";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<meter_l, meter_l, gram_l>, list_<second_l>>;
        };

        using exajoule_second_ld    =     joule_second_impl<std::exa, long double>;
        using petajoule_second_ld    =     joule_second_impl<std::peta, long double>;
        using terajoule_second_ld    =     joule_second_impl<std::tera, long double>;
        using gigajoule_second_ld    =     joule_second_impl<std::giga, long double>;
        using megajoule_second_ld    =     joule_second_impl<std::mega, long double>;
        using kilojoule_second_ld    =     joule_second_impl<std::kilo, long double>;
        using hectojoule_second_ld    =     joule_second_impl<std::hecto, long double>;
        using decajoule_second_ld    =     joule_second_impl<std::deca, long double>;
        using joule_second_ld    =     joule_second_impl<unity_ratio, long double>;
        using decijoule_second_ld    =     joule_second_impl<std::deci, long double>;
        using centijoule_second_ld    =     joule_second_impl<std::centi, long double>;
        using millijoule_second_ld    =     joule_second_impl<std::milli, long double>;
        using microjoule_second_ld    =     joule_second_impl<std::micro, long double>;
        using nanojoule_second_ld    =     joule_second_impl<std::nano, long double>;
        using picojoule_second_ld    =     joule_second_impl<std::pico, long double>;
        using femtojoule_second_ld    =     joule_second_impl<std::femto, long double>;
        using attojoule_second_ld    =     joule_second_impl<std::atto, long double>;
        using exajoule_second_ull    =     joule_second_impl<std::exa, unsigned long long>;
        using petajoule_second_ull    =     joule_second_impl<std::peta, unsigned long long>;
        using terajoule_second_ull    =     joule_second_impl<std::tera, unsigned long long>;
        using gigajoule_second_ull    =     joule_second_impl<std::giga, unsigned long long>;
        using megajoule_second_ull    =     joule_second_impl<std::mega, unsigned long long>;
        using kilojoule_second_ull    =     joule_second_impl<std::kilo, unsigned long long>;
        using hectojoule_second_ull    =     joule_second_impl<std::hecto, unsigned long long>;
        using decajoule_second_ull    =     joule_second_impl<std::deca, unsigned long long>;
        using joule_second_ull    =     joule_second_impl<unity_ratio, unsigned long long>;
        using decijoule_second_ull    =     joule_second_impl<std::deci, unsigned long long>;
        using centijoule_second_ull    =     joule_second_impl<std::centi, unsigned long long>;
        using millijoule_second_ull    =     joule_second_impl<std::milli, unsigned long long>;
        using microjoule_second_ull    =     joule_second_impl<std::micro, unsigned long long>;
        using nanojoule_second_ull    =     joule_second_impl<std::nano, unsigned long long>;
        using picojoule_second_ull    =     joule_second_impl<std::pico, unsigned long long>;
        using femtojoule_second_ull    =     joule_second_impl<std::femto, unsigned long long>;
        using attojoule_second_ull    =     joule_second_impl<std::atto, unsigned long long>;

        constexpr exajoule_second_ld operator""_EJ_s(long double val) {
            return static_cast<exajoule_second_ld>(val);
        }
        constexpr petajoule_second_ld operator""_PJ_s(long double val) {
            return static_cast<petajoule_second_ld>(val);
        }
        constexpr terajoule_second_ld operator""_TJ_s(long double val) {
            return static_cast<terajoule_second_ld>(val);
        }
        constexpr gigajoule_second_ld operator""_GJ_s(long double val) {
            return static_cast<gigajoule_second_ld>(val);
        }
        constexpr megajoule_second_ld operator""_MJ_s(long double val) {
            return static_cast<megajoule_second_ld>(val);
        }
        constexpr kilojoule_second_ld operator""_kJ_s(long double val) {
            return static_cast<kilojoule_second_ld>(val);
        }
        constexpr hectojoule_second_ld operator""_hJ_s(long double val) {
            return static_cast<hectojoule_second_ld>(val);
        }
        constexpr decajoule_second_ld operator""_daJ_s(long double val) {
            return static_cast<decajoule_second_ld>(val);
        }
        constexpr joule_second_ld operator""_J_s(long double val) {
            return static_cast<joule_second_ld>(val);
        }
        constexpr decijoule_second_ld operator""_dJ_s(long double val) {
            return static_cast<decijoule_second_ld>(val);
        }
        constexpr centijoule_second_ld operator""_cJ_s(long double val) {
            return static_cast<centijoule_second_ld>(val);
        }
        constexpr millijoule_second_ld operator""_mJ_s(long double val) {
            return static_cast<millijoule_second_ld>(val);
        }
        constexpr microjoule_second_ld operator""_uJ_s(long double val) {
            return static_cast<microjoule_second_ld>(val);
        }
        constexpr nanojoule_second_ld operator""_nJ_s(long double val) {
            return static_cast<nanojoule_second_ld>(val);
        }
        constexpr picojoule_second_ld operator""_pJ_s(long double val) {
            return static_cast<picojoule_second_ld>(val);
        }
        constexpr femtojoule_second_ld operator""_fJ_s(long double val) {
            return static_cast<femtojoule_second_ld>(val);
        }
        constexpr attojoule_second_ld operator""_aJ_s(long double val) {
            return static_cast<attojoule_second_ld>(val);
        }
        constexpr exajoule_second_ull operator""_EJ_s(unsigned long long val) {
            return static_cast<exajoule_second_ull>(val);
        }
        constexpr petajoule_second_ull operator""_PJ_s(unsigned long long val) {
            return static_cast<petajoule_second_ull>(val);
        }
        constexpr terajoule_second_ull operator""_TJ_s(unsigned long long val) {
            return static_cast<terajoule_second_ull>(val);
        }
        constexpr gigajoule_second_ull operator""_GJ_s(unsigned long long val) {
            return static_cast<gigajoule_second_ull>(val);
        }
        constexpr megajoule_second_ull operator""_MJ_s(unsigned long long val) {
            return static_cast<megajoule_second_ull>(val);
        }
        constexpr kilojoule_second_ull operator""_kJ_s(unsigned long long val) {
            return static_cast<kilojoule_second_ull>(val);
        }
        constexpr hectojoule_second_ull operator""_hJ_s(unsigned long long val) {
            return static_cast<hectojoule_second_ull>(val);
        }
        constexpr decajoule_second_ull operator""_daJ_s(unsigned long long val) {
            return static_cast<decajoule_second_ull>(val);
        }
        constexpr joule_second_ull operator""_J_s(unsigned long long val) {
            return static_cast<joule_second_ull>(val);
        }
        constexpr decijoule_second_ull operator""_dJ_s(unsigned long long val) {
            return static_cast<decijoule_second_ull>(val);
        }
        constexpr centijoule_second_ull operator""_cJ_s(unsigned long long val) {
            return static_cast<centijoule_second_ull>(val);
        }
        constexpr millijoule_second_ull operator""_mJ_s(unsigned long long val) {
            return static_cast<millijoule_second_ull>(val);
        }
        constexpr microjoule_second_ull operator""_uJ_s(unsigned long long val) {
            return static_cast<microjoule_second_ull>(val);
        }
        constexpr nanojoule_second_ull operator""_nJ_s(unsigned long long val) {
            return static_cast<nanojoule_second_ull>(val);
        }
        constexpr picojoule_second_ull operator""_pJ_s(unsigned long long val) {
            return static_cast<picojoule_second_ull>(val);
        }
        constexpr femtojoule_second_ull operator""_fJ_s(unsigned long long val) {
            return static_cast<femtojoule_second_ull>(val);
        }
        constexpr attojoule_second_ull operator""_aJ_s(unsigned long long val) {
            return static_cast<attojoule_second_ull>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_JOULE_SECOND_HPP_INCLUDED