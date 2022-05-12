#ifndef POTATO_UNITS_DOSE EQUIVALENT_HPP_INCLUDED
#define POTATO_UNITS_DOSE EQUIVALENT_HPP_INCLUDED

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
        struct sievert_impl {
            constexpr sievert_impl<T, P>() : value(0) {}
            constexpr sievert_impl<T, P>(P val) : value(val) {}

            P value;

            static constexpr auto pretty = "Sv";

            using is_any_impl = false_;

            using mod_ratio = T;
            using base      = list_<list_<length_l, length_l>, list_<time_l, time_l>>;
            using impl      = list_<list_<meter_l, meter_l>, list_<second_l, second_l>>;
        };

        using exasievert    =     sievert_impl<std::exa, long double>;
        using petasievert    =     sievert_impl<std::peta, long double>;
        using terasievert    =     sievert_impl<std::tera, long double>;
        using gigasievert    =     sievert_impl<std::giga, long double>;
        using megasievert    =     sievert_impl<std::mega, long double>;
        using kilosievert    =     sievert_impl<std::kilo, long double>;
        using hectosievert    =     sievert_impl<std::hecto, long double>;
        using decasievert    =     sievert_impl<std::deca, long double>;
        using sievert    =     sievert_impl<unity_ratio, long double>;
        using decisievert    =     sievert_impl<std::deci, long double>;
        using centisievert    =     sievert_impl<std::centi, long double>;
        using millisievert    =     sievert_impl<std::milli, long double>;
        using microsievert    =     sievert_impl<std::micro, long double>;
        using nanosievert    =     sievert_impl<std::nano, long double>;
        using picosievert    =     sievert_impl<std::pico, long double>;
        using femtosievert    =     sievert_impl<std::femto, long double>;
        using attosievert    =     sievert_impl<std::atto, long double>;

        constexpr exasievert operator""_ESv(long double val) {
            return static_cast<exasievert>(val);
        }
        constexpr petasievert operator""_PSv(long double val) {
            return static_cast<petasievert>(val);
        }
        constexpr terasievert operator""_TSv(long double val) {
            return static_cast<terasievert>(val);
        }
        constexpr gigasievert operator""_GSv(long double val) {
            return static_cast<gigasievert>(val);
        }
        constexpr megasievert operator""_MSv(long double val) {
            return static_cast<megasievert>(val);
        }
        constexpr kilosievert operator""_kSv(long double val) {
            return static_cast<kilosievert>(val);
        }
        constexpr hectosievert operator""_hSv(long double val) {
            return static_cast<hectosievert>(val);
        }
        constexpr decasievert operator""_daSv(long double val) {
            return static_cast<decasievert>(val);
        }
        constexpr sievert operator""_Sv(long double val) {
            return static_cast<sievert>(val);
        }
        constexpr decisievert operator""_dSv(long double val) {
            return static_cast<decisievert>(val);
        }
        constexpr centisievert operator""_cSv(long double val) {
            return static_cast<centisievert>(val);
        }
        constexpr millisievert operator""_mSv(long double val) {
            return static_cast<millisievert>(val);
        }
        constexpr microsievert operator""_uSv(long double val) {
            return static_cast<microsievert>(val);
        }
        constexpr nanosievert operator""_nSv(long double val) {
            return static_cast<nanosievert>(val);
        }
        constexpr picosievert operator""_pSv(long double val) {
            return static_cast<picosievert>(val);
        }
        constexpr femtosievert operator""_fSv(long double val) {
            return static_cast<femtosievert>(val);
        }
        constexpr attosievert operator""_aSv(long double val) {
            return static_cast<attosievert>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_SIEVERT_HPP_INCLUDED