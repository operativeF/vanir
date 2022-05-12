#ifndef POTATO_UNITS_FREQUENCY_HPP_INCLUDED
#define POTATO_UNITS_FREQUENCY_HPP_INCLUDED

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
        struct hertz_impl {
            // Deduce value to determine correct stored value.
            using DV = call_<if_<is_<unsigned long long>, always_<long long>, always_<P>>, P>;

            constexpr hertz_impl<T, P>() : value(0) {}
            constexpr hertz_impl<T, P>(DV val) : value(val) {}

            template <typename U, typename R>
            constexpr const hertz_impl<T, P>(const hertz_impl<U, R>& other) {
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

            static constexpr auto pretty = "Hz";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<>, list_<second_l>>;
        };

        using exahertz_ld    =     hertz_impl<std::exa, long double>;
        using petahertz_ld    =     hertz_impl<std::peta, long double>;
        using terahertz_ld    =     hertz_impl<std::tera, long double>;
        using gigahertz_ld    =     hertz_impl<std::giga, long double>;
        using megahertz_ld    =     hertz_impl<std::mega, long double>;
        using kilohertz_ld    =     hertz_impl<std::kilo, long double>;
        using hectohertz_ld    =     hertz_impl<std::hecto, long double>;
        using decahertz_ld    =     hertz_impl<std::deca, long double>;
        using hertz_ld    =     hertz_impl<unity_ratio, long double>;
        using decihertz_ld    =     hertz_impl<std::deci, long double>;
        using centihertz_ld    =     hertz_impl<std::centi, long double>;
        using millihertz_ld    =     hertz_impl<std::milli, long double>;
        using microhertz_ld    =     hertz_impl<std::micro, long double>;
        using nanohertz_ld    =     hertz_impl<std::nano, long double>;
        using picohertz_ld    =     hertz_impl<std::pico, long double>;
        using femtohertz_ld    =     hertz_impl<std::femto, long double>;
        using attohertz_ld    =     hertz_impl<std::atto, long double>;
        using exahertz_ull    =     hertz_impl<std::exa, unsigned long long>;
        using petahertz_ull    =     hertz_impl<std::peta, unsigned long long>;
        using terahertz_ull    =     hertz_impl<std::tera, unsigned long long>;
        using gigahertz_ull    =     hertz_impl<std::giga, unsigned long long>;
        using megahertz_ull    =     hertz_impl<std::mega, unsigned long long>;
        using kilohertz_ull    =     hertz_impl<std::kilo, unsigned long long>;
        using hectohertz_ull    =     hertz_impl<std::hecto, unsigned long long>;
        using decahertz_ull    =     hertz_impl<std::deca, unsigned long long>;
        using hertz_ull    =     hertz_impl<unity_ratio, unsigned long long>;
        using decihertz_ull    =     hertz_impl<std::deci, unsigned long long>;
        using centihertz_ull    =     hertz_impl<std::centi, unsigned long long>;
        using millihertz_ull    =     hertz_impl<std::milli, unsigned long long>;
        using microhertz_ull    =     hertz_impl<std::micro, unsigned long long>;
        using nanohertz_ull    =     hertz_impl<std::nano, unsigned long long>;
        using picohertz_ull    =     hertz_impl<std::pico, unsigned long long>;
        using femtohertz_ull    =     hertz_impl<std::femto, unsigned long long>;
        using attohertz_ull    =     hertz_impl<std::atto, unsigned long long>;

        constexpr exahertz_ld operator""_EHz(long double val) {
            return static_cast<exahertz_ld>(val);
        }
        constexpr petahertz_ld operator""_PHz(long double val) {
            return static_cast<petahertz_ld>(val);
        }
        constexpr terahertz_ld operator""_THz(long double val) {
            return static_cast<terahertz_ld>(val);
        }
        constexpr gigahertz_ld operator""_GHz(long double val) {
            return static_cast<gigahertz_ld>(val);
        }
        constexpr megahertz_ld operator""_MHz(long double val) {
            return static_cast<megahertz_ld>(val);
        }
        constexpr kilohertz_ld operator""_kHz(long double val) {
            return static_cast<kilohertz_ld>(val);
        }
        constexpr hectohertz_ld operator""_hHz(long double val) {
            return static_cast<hectohertz_ld>(val);
        }
        constexpr decahertz_ld operator""_daHz(long double val) {
            return static_cast<decahertz_ld>(val);
        }
        constexpr hertz_ld operator""_Hz(long double val) {
            return static_cast<hertz_ld>(val);
        }
        constexpr decihertz_ld operator""_dHz(long double val) {
            return static_cast<decihertz_ld>(val);
        }
        constexpr centihertz_ld operator""_cHz(long double val) {
            return static_cast<centihertz_ld>(val);
        }
        constexpr millihertz_ld operator""_mHz(long double val) {
            return static_cast<millihertz_ld>(val);
        }
        constexpr microhertz_ld operator""_uHz(long double val) {
            return static_cast<microhertz_ld>(val);
        }
        constexpr nanohertz_ld operator""_nHz(long double val) {
            return static_cast<nanohertz_ld>(val);
        }
        constexpr picohertz_ld operator""_pHz(long double val) {
            return static_cast<picohertz_ld>(val);
        }
        constexpr femtohertz_ld operator""_fHz(long double val) {
            return static_cast<femtohertz_ld>(val);
        }
        constexpr attohertz_ld operator""_aHz(long double val) {
            return static_cast<attohertz_ld>(val);
        }
        constexpr exahertz_ull operator""_EHz(unsigned long long val) {
            return static_cast<exahertz_ull>(val);
        }
        constexpr petahertz_ull operator""_PHz(unsigned long long val) {
            return static_cast<petahertz_ull>(val);
        }
        constexpr terahertz_ull operator""_THz(unsigned long long val) {
            return static_cast<terahertz_ull>(val);
        }
        constexpr gigahertz_ull operator""_GHz(unsigned long long val) {
            return static_cast<gigahertz_ull>(val);
        }
        constexpr megahertz_ull operator""_MHz(unsigned long long val) {
            return static_cast<megahertz_ull>(val);
        }
        constexpr kilohertz_ull operator""_kHz(unsigned long long val) {
            return static_cast<kilohertz_ull>(val);
        }
        constexpr hectohertz_ull operator""_hHz(unsigned long long val) {
            return static_cast<hectohertz_ull>(val);
        }
        constexpr decahertz_ull operator""_daHz(unsigned long long val) {
            return static_cast<decahertz_ull>(val);
        }
        constexpr hertz_ull operator""_Hz(unsigned long long val) {
            return static_cast<hertz_ull>(val);
        }
        constexpr decihertz_ull operator""_dHz(unsigned long long val) {
            return static_cast<decihertz_ull>(val);
        }
        constexpr centihertz_ull operator""_cHz(unsigned long long val) {
            return static_cast<centihertz_ull>(val);
        }
        constexpr millihertz_ull operator""_mHz(unsigned long long val) {
            return static_cast<millihertz_ull>(val);
        }
        constexpr microhertz_ull operator""_uHz(unsigned long long val) {
            return static_cast<microhertz_ull>(val);
        }
        constexpr nanohertz_ull operator""_nHz(unsigned long long val) {
            return static_cast<nanohertz_ull>(val);
        }
        constexpr picohertz_ull operator""_pHz(unsigned long long val) {
            return static_cast<picohertz_ull>(val);
        }
        constexpr femtohertz_ull operator""_fHz(unsigned long long val) {
            return static_cast<femtohertz_ull>(val);
        }
        constexpr attohertz_ull operator""_aHz(unsigned long long val) {
            return static_cast<attohertz_ull>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_HERTZ_HPP_INCLUDED