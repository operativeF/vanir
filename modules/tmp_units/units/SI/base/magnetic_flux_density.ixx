//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Tesla;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

export namespace potato::units {
    namespace tmp = boost::tmp;

    template <typename RatioTypeT, typename P>
    struct tesla_impl {

        static constexpr auto pretty = "T";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = tmp::list_<tmp::list_<gram_l>, tmp::list_<second_l, second_l, ampere_l>>;

        constexpr tesla_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exatesla_ld    =     tesla_impl<std::exa, long double>;
    using petatesla_ld    =     tesla_impl<std::peta, long double>;
    using teratesla_ld    =     tesla_impl<std::tera, long double>;
    using gigatesla_ld    =     tesla_impl<std::giga, long double>;
    using megatesla_ld    =     tesla_impl<std::mega, long double>;
    using kilotesla_ld    =     tesla_impl<std::kilo, long double>;
    using hectotesla_ld    =     tesla_impl<std::hecto, long double>;
    using decatesla_ld    =     tesla_impl<std::deca, long double>;
    using tesla_ld    =     tesla_impl<unity_ratio, long double>;
    using decitesla_ld    =     tesla_impl<std::deci, long double>;
    using centitesla_ld    =     tesla_impl<std::centi, long double>;
    using millitesla_ld    =     tesla_impl<std::milli, long double>;
    using microtesla_ld    =     tesla_impl<std::micro, long double>;
    using nanotesla_ld    =     tesla_impl<std::nano, long double>;
    using picotesla_ld    =     tesla_impl<std::pico, long double>;
    using femtotesla_ld    =     tesla_impl<std::femto, long double>;
    using attotesla_ld    =     tesla_impl<std::atto, long double>;
    using exatesla_ull    =     tesla_impl<std::exa, unsigned long long>;
    using petatesla_ull    =     tesla_impl<std::peta, unsigned long long>;
    using teratesla_ull    =     tesla_impl<std::tera, unsigned long long>;
    using gigatesla_ull    =     tesla_impl<std::giga, unsigned long long>;
    using megatesla_ull    =     tesla_impl<std::mega, unsigned long long>;
    using kilotesla_ull    =     tesla_impl<std::kilo, unsigned long long>;
    using hectotesla_ull    =     tesla_impl<std::hecto, unsigned long long>;
    using decatesla_ull    =     tesla_impl<std::deca, unsigned long long>;
    using tesla_ull    =     tesla_impl<unity_ratio, unsigned long long>;
    using decitesla_ull    =     tesla_impl<std::deci, unsigned long long>;
    using centitesla_ull    =     tesla_impl<std::centi, unsigned long long>;
    using millitesla_ull    =     tesla_impl<std::milli, unsigned long long>;
    using microtesla_ull    =     tesla_impl<std::micro, unsigned long long>;
    using nanotesla_ull    =     tesla_impl<std::nano, unsigned long long>;
    using picotesla_ull    =     tesla_impl<std::pico, unsigned long long>;
    using femtotesla_ull    =     tesla_impl<std::femto, unsigned long long>;
    using attotesla_ull    =     tesla_impl<std::atto, unsigned long long>;

    constexpr exatesla_ld operator""_ET(long double val) {
        return static_cast<exatesla_ld>(val);
    }
    constexpr petatesla_ld operator""_PT(long double val) {
        return static_cast<petatesla_ld>(val);
    }
    constexpr teratesla_ld operator""_TT(long double val) {
        return static_cast<teratesla_ld>(val);
    }
    constexpr gigatesla_ld operator""_GT(long double val) {
        return static_cast<gigatesla_ld>(val);
    }
    constexpr megatesla_ld operator""_MT(long double val) {
        return static_cast<megatesla_ld>(val);
    }
    constexpr kilotesla_ld operator""_kT(long double val) {
        return static_cast<kilotesla_ld>(val);
    }
    constexpr hectotesla_ld operator""_hT(long double val) {
        return static_cast<hectotesla_ld>(val);
    }
    constexpr decatesla_ld operator""_daT(long double val) {
        return static_cast<decatesla_ld>(val);
    }
    constexpr tesla_ld operator""_T(long double val) {
        return static_cast<tesla_ld>(val);
    }
    constexpr decitesla_ld operator""_dT(long double val) {
        return static_cast<decitesla_ld>(val);
    }
    constexpr centitesla_ld operator""_cT(long double val) {
        return static_cast<centitesla_ld>(val);
    }
    constexpr millitesla_ld operator""_mT(long double val) {
        return static_cast<millitesla_ld>(val);
    }
    constexpr microtesla_ld operator""_uT(long double val) {
        return static_cast<microtesla_ld>(val);
    }
    constexpr nanotesla_ld operator""_nT(long double val) {
        return static_cast<nanotesla_ld>(val);
    }
    constexpr picotesla_ld operator""_pT(long double val) {
        return static_cast<picotesla_ld>(val);
    }
    constexpr femtotesla_ld operator""_fT(long double val) {
        return static_cast<femtotesla_ld>(val);
    }
    constexpr attotesla_ld operator""_aT(long double val) {
        return static_cast<attotesla_ld>(val);
    }
    constexpr exatesla_ull operator""_ET(unsigned long long val) {
        return static_cast<exatesla_ull>(val);
    }
    constexpr petatesla_ull operator""_PT(unsigned long long val) {
        return static_cast<petatesla_ull>(val);
    }
    constexpr teratesla_ull operator""_TT(unsigned long long val) {
        return static_cast<teratesla_ull>(val);
    }
    constexpr gigatesla_ull operator""_GT(unsigned long long val) {
        return static_cast<gigatesla_ull>(val);
    }
    constexpr megatesla_ull operator""_MT(unsigned long long val) {
        return static_cast<megatesla_ull>(val);
    }
    constexpr kilotesla_ull operator""_kT(unsigned long long val) {
        return static_cast<kilotesla_ull>(val);
    }
    constexpr hectotesla_ull operator""_hT(unsigned long long val) {
        return static_cast<hectotesla_ull>(val);
    }
    constexpr decatesla_ull operator""_daT(unsigned long long val) {
        return static_cast<decatesla_ull>(val);
    }
    constexpr tesla_ull operator""_T(unsigned long long val) {
        return static_cast<tesla_ull>(val);
    }
    constexpr decitesla_ull operator""_dT(unsigned long long val) {
        return static_cast<decitesla_ull>(val);
    }
    constexpr centitesla_ull operator""_cT(unsigned long long val) {
        return static_cast<centitesla_ull>(val);
    }
    constexpr millitesla_ull operator""_mT(unsigned long long val) {
        return static_cast<millitesla_ull>(val);
    }
    constexpr microtesla_ull operator""_uT(unsigned long long val) {
        return static_cast<microtesla_ull>(val);
    }
    constexpr nanotesla_ull operator""_nT(unsigned long long val) {
        return static_cast<nanotesla_ull>(val);
    }
    constexpr picotesla_ull operator""_pT(unsigned long long val) {
        return static_cast<picotesla_ull>(val);
    }
    constexpr femtotesla_ull operator""_fT(unsigned long long val) {
        return static_cast<femtotesla_ull>(val);
    }
    constexpr attotesla_ull operator""_aT(unsigned long long val) {
        return static_cast<attotesla_ull>(val);
    }

} // namespace potato::units
