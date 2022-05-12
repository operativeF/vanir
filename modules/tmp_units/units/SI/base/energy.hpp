#ifndef POTATO_UNITS_ENERGY_HPP_INCLUDED
#define POTATO_UNITS_ENERGY_HPP_INCLUDED

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
        struct joule_impl {
            // Deduce value to determine correct stored value.
            using DV = call_<if_<is_<unsigned long long>, always_<long long>, always_<P>>, P>;

            constexpr joule_impl<T, P>() : value(0) {}
            constexpr joule_impl<T, P>(DV val) : value(val) {}

            template <typename U, typename R>
            constexpr const joule_impl<T, P>(const joule_impl<U, R>& other) {
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

            static constexpr auto pretty = "J";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<meter_l, meter_l, gram_l>, list_<second_l, second_l>>;
        };

        using exajoule_ld    =     joule_impl<std::exa, long double>;
        using petajoule_ld    =     joule_impl<std::peta, long double>;
        using terajoule_ld    =     joule_impl<std::tera, long double>;
        using gigajoule_ld    =     joule_impl<std::giga, long double>;
        using megajoule_ld    =     joule_impl<std::mega, long double>;
        using kilojoule_ld    =     joule_impl<std::kilo, long double>;
        using hectojoule_ld    =     joule_impl<std::hecto, long double>;
        using decajoule_ld    =     joule_impl<std::deca, long double>;
        using joule_ld    =     joule_impl<unity_ratio, long double>;
        using decijoule_ld    =     joule_impl<std::deci, long double>;
        using centijoule_ld    =     joule_impl<std::centi, long double>;
        using millijoule_ld    =     joule_impl<std::milli, long double>;
        using microjoule_ld    =     joule_impl<std::micro, long double>;
        using nanojoule_ld    =     joule_impl<std::nano, long double>;
        using picojoule_ld    =     joule_impl<std::pico, long double>;
        using femtojoule_ld    =     joule_impl<std::femto, long double>;
        using attojoule_ld    =     joule_impl<std::atto, long double>;
        using exajoule_ull    =     joule_impl<std::exa, unsigned long long>;
        using petajoule_ull    =     joule_impl<std::peta, unsigned long long>;
        using terajoule_ull    =     joule_impl<std::tera, unsigned long long>;
        using gigajoule_ull    =     joule_impl<std::giga, unsigned long long>;
        using megajoule_ull    =     joule_impl<std::mega, unsigned long long>;
        using kilojoule_ull    =     joule_impl<std::kilo, unsigned long long>;
        using hectojoule_ull    =     joule_impl<std::hecto, unsigned long long>;
        using decajoule_ull    =     joule_impl<std::deca, unsigned long long>;
        using joule_ull    =     joule_impl<unity_ratio, unsigned long long>;
        using decijoule_ull    =     joule_impl<std::deci, unsigned long long>;
        using centijoule_ull    =     joule_impl<std::centi, unsigned long long>;
        using millijoule_ull    =     joule_impl<std::milli, unsigned long long>;
        using microjoule_ull    =     joule_impl<std::micro, unsigned long long>;
        using nanojoule_ull    =     joule_impl<std::nano, unsigned long long>;
        using picojoule_ull    =     joule_impl<std::pico, unsigned long long>;
        using femtojoule_ull    =     joule_impl<std::femto, unsigned long long>;
        using attojoule_ull    =     joule_impl<std::atto, unsigned long long>;

        constexpr exajoule_ld operator""_EJ(long double val) {
            return static_cast<exajoule_ld>(val);
        }
        constexpr petajoule_ld operator""_PJ(long double val) {
            return static_cast<petajoule_ld>(val);
        }
        constexpr terajoule_ld operator""_TJ(long double val) {
            return static_cast<terajoule_ld>(val);
        }
        constexpr gigajoule_ld operator""_GJ(long double val) {
            return static_cast<gigajoule_ld>(val);
        }
        constexpr megajoule_ld operator""_MJ(long double val) {
            return static_cast<megajoule_ld>(val);
        }
        constexpr kilojoule_ld operator""_kJ(long double val) {
            return static_cast<kilojoule_ld>(val);
        }
        constexpr hectojoule_ld operator""_hJ(long double val) {
            return static_cast<hectojoule_ld>(val);
        }
        constexpr decajoule_ld operator""_daJ(long double val) {
            return static_cast<decajoule_ld>(val);
        }
        constexpr joule_ld operator""_J(long double val) {
            return static_cast<joule_ld>(val);
        }
        constexpr decijoule_ld operator""_dJ(long double val) {
            return static_cast<decijoule_ld>(val);
        }
        constexpr centijoule_ld operator""_cJ(long double val) {
            return static_cast<centijoule_ld>(val);
        }
        constexpr millijoule_ld operator""_mJ(long double val) {
            return static_cast<millijoule_ld>(val);
        }
        constexpr microjoule_ld operator""_uJ(long double val) {
            return static_cast<microjoule_ld>(val);
        }
        constexpr nanojoule_ld operator""_nJ(long double val) {
            return static_cast<nanojoule_ld>(val);
        }
        constexpr picojoule_ld operator""_pJ(long double val) {
            return static_cast<picojoule_ld>(val);
        }
        constexpr femtojoule_ld operator""_fJ(long double val) {
            return static_cast<femtojoule_ld>(val);
        }
        constexpr attojoule_ld operator""_aJ(long double val) {
            return static_cast<attojoule_ld>(val);
        }
        constexpr exajoule_ull operator""_EJ(unsigned long long val) {
            return static_cast<exajoule_ull>(val);
        }
        constexpr petajoule_ull operator""_PJ(unsigned long long val) {
            return static_cast<petajoule_ull>(val);
        }
        constexpr terajoule_ull operator""_TJ(unsigned long long val) {
            return static_cast<terajoule_ull>(val);
        }
        constexpr gigajoule_ull operator""_GJ(unsigned long long val) {
            return static_cast<gigajoule_ull>(val);
        }
        constexpr megajoule_ull operator""_MJ(unsigned long long val) {
            return static_cast<megajoule_ull>(val);
        }
        constexpr kilojoule_ull operator""_kJ(unsigned long long val) {
            return static_cast<kilojoule_ull>(val);
        }
        constexpr hectojoule_ull operator""_hJ(unsigned long long val) {
            return static_cast<hectojoule_ull>(val);
        }
        constexpr decajoule_ull operator""_daJ(unsigned long long val) {
            return static_cast<decajoule_ull>(val);
        }
        constexpr joule_ull operator""_J(unsigned long long val) {
            return static_cast<joule_ull>(val);
        }
        constexpr decijoule_ull operator""_dJ(unsigned long long val) {
            return static_cast<decijoule_ull>(val);
        }
        constexpr centijoule_ull operator""_cJ(unsigned long long val) {
            return static_cast<centijoule_ull>(val);
        }
        constexpr millijoule_ull operator""_mJ(unsigned long long val) {
            return static_cast<millijoule_ull>(val);
        }
        constexpr microjoule_ull operator""_uJ(unsigned long long val) {
            return static_cast<microjoule_ull>(val);
        }
        constexpr nanojoule_ull operator""_nJ(unsigned long long val) {
            return static_cast<nanojoule_ull>(val);
        }
        constexpr picojoule_ull operator""_pJ(unsigned long long val) {
            return static_cast<picojoule_ull>(val);
        }
        constexpr femtojoule_ull operator""_fJ(unsigned long long val) {
            return static_cast<femtojoule_ull>(val);
        }
        constexpr attojoule_ull operator""_aJ(unsigned long long val) {
            return static_cast<attojoule_ull>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_JOULE_HPP_INCLUDED