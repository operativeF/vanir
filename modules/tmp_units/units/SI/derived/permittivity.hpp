#ifndef POTATO_UNITS_PERMITTIVITY_HPP_INCLUDED
#define POTATO_UNITS_PERMITTIVITY_HPP_INCLUDED

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
        struct farad_per_meter_impl {
            // Deduce value to determine correct stored value.
            using DV = call_<if_<is_<unsigned long long>, always_<long long>, always_<P>>, P>;

            constexpr farad_per_meter_impl<T, P>() : value(0) {}
            constexpr farad_per_meter_impl<T, P>(DV val) : value(val) {}

            template <typename U, typename R>
            constexpr const farad_per_meter_impl<T, P>(const farad_per_meter_impl<U, R>& other) {
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

            static constexpr auto pretty = "F/m";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<second_l, second_l, second_l, second_l, ampere_l, ampere_l>, list_<meter_l, meter_l, meter_l, gram_l>>;
        };

        using exafarad_per_meter_ld    =     farad_per_meter_impl<std::exa, long double>;
        using petafarad_per_meter_ld    =     farad_per_meter_impl<std::peta, long double>;
        using terafarad_per_meter_ld    =     farad_per_meter_impl<std::tera, long double>;
        using gigafarad_per_meter_ld    =     farad_per_meter_impl<std::giga, long double>;
        using megafarad_per_meter_ld    =     farad_per_meter_impl<std::mega, long double>;
        using kilofarad_per_meter_ld    =     farad_per_meter_impl<std::kilo, long double>;
        using hectofarad_per_meter_ld    =     farad_per_meter_impl<std::hecto, long double>;
        using decafarad_per_meter_ld    =     farad_per_meter_impl<std::deca, long double>;
        using farad_per_meter_ld    =     farad_per_meter_impl<unity_ratio, long double>;
        using decifarad_per_meter_ld    =     farad_per_meter_impl<std::deci, long double>;
        using centifarad_per_meter_ld    =     farad_per_meter_impl<std::centi, long double>;
        using millifarad_per_meter_ld    =     farad_per_meter_impl<std::milli, long double>;
        using microfarad_per_meter_ld    =     farad_per_meter_impl<std::micro, long double>;
        using nanofarad_per_meter_ld    =     farad_per_meter_impl<std::nano, long double>;
        using picofarad_per_meter_ld    =     farad_per_meter_impl<std::pico, long double>;
        using femtofarad_per_meter_ld    =     farad_per_meter_impl<std::femto, long double>;
        using attofarad_per_meter_ld    =     farad_per_meter_impl<std::atto, long double>;
        using exafarad_per_meter_ull    =     farad_per_meter_impl<std::exa, unsigned long long>;
        using petafarad_per_meter_ull    =     farad_per_meter_impl<std::peta, unsigned long long>;
        using terafarad_per_meter_ull    =     farad_per_meter_impl<std::tera, unsigned long long>;
        using gigafarad_per_meter_ull    =     farad_per_meter_impl<std::giga, unsigned long long>;
        using megafarad_per_meter_ull    =     farad_per_meter_impl<std::mega, unsigned long long>;
        using kilofarad_per_meter_ull    =     farad_per_meter_impl<std::kilo, unsigned long long>;
        using hectofarad_per_meter_ull    =     farad_per_meter_impl<std::hecto, unsigned long long>;
        using decafarad_per_meter_ull    =     farad_per_meter_impl<std::deca, unsigned long long>;
        using farad_per_meter_ull    =     farad_per_meter_impl<unity_ratio, unsigned long long>;
        using decifarad_per_meter_ull    =     farad_per_meter_impl<std::deci, unsigned long long>;
        using centifarad_per_meter_ull    =     farad_per_meter_impl<std::centi, unsigned long long>;
        using millifarad_per_meter_ull    =     farad_per_meter_impl<std::milli, unsigned long long>;
        using microfarad_per_meter_ull    =     farad_per_meter_impl<std::micro, unsigned long long>;
        using nanofarad_per_meter_ull    =     farad_per_meter_impl<std::nano, unsigned long long>;
        using picofarad_per_meter_ull    =     farad_per_meter_impl<std::pico, unsigned long long>;
        using femtofarad_per_meter_ull    =     farad_per_meter_impl<std::femto, unsigned long long>;
        using attofarad_per_meter_ull    =     farad_per_meter_impl<std::atto, unsigned long long>;

        constexpr exafarad_per_meter_ld operator""_EF_per_m(long double val) {
            return static_cast<exafarad_per_meter_ld>(val);
        }
        constexpr petafarad_per_meter_ld operator""_PF_per_m(long double val) {
            return static_cast<petafarad_per_meter_ld>(val);
        }
        constexpr terafarad_per_meter_ld operator""_TF_per_m(long double val) {
            return static_cast<terafarad_per_meter_ld>(val);
        }
        constexpr gigafarad_per_meter_ld operator""_GF_per_m(long double val) {
            return static_cast<gigafarad_per_meter_ld>(val);
        }
        constexpr megafarad_per_meter_ld operator""_MF_per_m(long double val) {
            return static_cast<megafarad_per_meter_ld>(val);
        }
        constexpr kilofarad_per_meter_ld operator""_kF_per_m(long double val) {
            return static_cast<kilofarad_per_meter_ld>(val);
        }
        constexpr hectofarad_per_meter_ld operator""_hF_per_m(long double val) {
            return static_cast<hectofarad_per_meter_ld>(val);
        }
        constexpr decafarad_per_meter_ld operator""_daF_per_m(long double val) {
            return static_cast<decafarad_per_meter_ld>(val);
        }
        constexpr farad_per_meter_ld operator""_F_per_m(long double val) {
            return static_cast<farad_per_meter_ld>(val);
        }
        constexpr decifarad_per_meter_ld operator""_dF_per_m(long double val) {
            return static_cast<decifarad_per_meter_ld>(val);
        }
        constexpr centifarad_per_meter_ld operator""_cF_per_m(long double val) {
            return static_cast<centifarad_per_meter_ld>(val);
        }
        constexpr millifarad_per_meter_ld operator""_mF_per_m(long double val) {
            return static_cast<millifarad_per_meter_ld>(val);
        }
        constexpr microfarad_per_meter_ld operator""_uF_per_m(long double val) {
            return static_cast<microfarad_per_meter_ld>(val);
        }
        constexpr nanofarad_per_meter_ld operator""_nF_per_m(long double val) {
            return static_cast<nanofarad_per_meter_ld>(val);
        }
        constexpr picofarad_per_meter_ld operator""_pF_per_m(long double val) {
            return static_cast<picofarad_per_meter_ld>(val);
        }
        constexpr femtofarad_per_meter_ld operator""_fF_per_m(long double val) {
            return static_cast<femtofarad_per_meter_ld>(val);
        }
        constexpr attofarad_per_meter_ld operator""_aF_per_m(long double val) {
            return static_cast<attofarad_per_meter_ld>(val);
        }
        constexpr exafarad_per_meter_ull operator""_EF_per_m(unsigned long long val) {
            return static_cast<exafarad_per_meter_ull>(val);
        }
        constexpr petafarad_per_meter_ull operator""_PF_per_m(unsigned long long val) {
            return static_cast<petafarad_per_meter_ull>(val);
        }
        constexpr terafarad_per_meter_ull operator""_TF_per_m(unsigned long long val) {
            return static_cast<terafarad_per_meter_ull>(val);
        }
        constexpr gigafarad_per_meter_ull operator""_GF_per_m(unsigned long long val) {
            return static_cast<gigafarad_per_meter_ull>(val);
        }
        constexpr megafarad_per_meter_ull operator""_MF_per_m(unsigned long long val) {
            return static_cast<megafarad_per_meter_ull>(val);
        }
        constexpr kilofarad_per_meter_ull operator""_kF_per_m(unsigned long long val) {
            return static_cast<kilofarad_per_meter_ull>(val);
        }
        constexpr hectofarad_per_meter_ull operator""_hF_per_m(unsigned long long val) {
            return static_cast<hectofarad_per_meter_ull>(val);
        }
        constexpr decafarad_per_meter_ull operator""_daF_per_m(unsigned long long val) {
            return static_cast<decafarad_per_meter_ull>(val);
        }
        constexpr farad_per_meter_ull operator""_F_per_m(unsigned long long val) {
            return static_cast<farad_per_meter_ull>(val);
        }
        constexpr decifarad_per_meter_ull operator""_dF_per_m(unsigned long long val) {
            return static_cast<decifarad_per_meter_ull>(val);
        }
        constexpr centifarad_per_meter_ull operator""_cF_per_m(unsigned long long val) {
            return static_cast<centifarad_per_meter_ull>(val);
        }
        constexpr millifarad_per_meter_ull operator""_mF_per_m(unsigned long long val) {
            return static_cast<millifarad_per_meter_ull>(val);
        }
        constexpr microfarad_per_meter_ull operator""_uF_per_m(unsigned long long val) {
            return static_cast<microfarad_per_meter_ull>(val);
        }
        constexpr nanofarad_per_meter_ull operator""_nF_per_m(unsigned long long val) {
            return static_cast<nanofarad_per_meter_ull>(val);
        }
        constexpr picofarad_per_meter_ull operator""_pF_per_m(unsigned long long val) {
            return static_cast<picofarad_per_meter_ull>(val);
        }
        constexpr femtofarad_per_meter_ull operator""_fF_per_m(unsigned long long val) {
            return static_cast<femtofarad_per_meter_ull>(val);
        }
        constexpr attofarad_per_meter_ull operator""_aF_per_m(unsigned long long val) {
            return static_cast<attofarad_per_meter_ull>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_FARAD_PER_METER_HPP_INCLUDED