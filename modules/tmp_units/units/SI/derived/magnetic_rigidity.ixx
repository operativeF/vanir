//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Tesla_Meter;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

export namespace potato::units {
    namespace tmp = boost::tmp;

    template <typename RatioTypeT, typename P>
    struct tesla_meter_impl {

        static constexpr auto pretty = "T·m";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = tmp::list_<tmp::list_<meter_l, gram_l>, tmp::list_<second_l, second_l, ampere_l>>;

        constexpr tesla_meter_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exatesla_meter_ld    =     tesla_meter_impl<std::exa, long double>;
    using petatesla_meter_ld    =     tesla_meter_impl<std::peta, long double>;
    using teratesla_meter_ld    =     tesla_meter_impl<std::tera, long double>;
    using gigatesla_meter_ld    =     tesla_meter_impl<std::giga, long double>;
    using megatesla_meter_ld    =     tesla_meter_impl<std::mega, long double>;
    using kilotesla_meter_ld    =     tesla_meter_impl<std::kilo, long double>;
    using hectotesla_meter_ld    =     tesla_meter_impl<std::hecto, long double>;
    using decatesla_meter_ld    =     tesla_meter_impl<std::deca, long double>;
    using tesla_meter_ld    =     tesla_meter_impl<unity_ratio, long double>;
    using decitesla_meter_ld    =     tesla_meter_impl<std::deci, long double>;
    using centitesla_meter_ld    =     tesla_meter_impl<std::centi, long double>;
    using millitesla_meter_ld    =     tesla_meter_impl<std::milli, long double>;
    using microtesla_meter_ld    =     tesla_meter_impl<std::micro, long double>;
    using nanotesla_meter_ld    =     tesla_meter_impl<std::nano, long double>;
    using picotesla_meter_ld    =     tesla_meter_impl<std::pico, long double>;
    using femtotesla_meter_ld    =     tesla_meter_impl<std::femto, long double>;
    using attotesla_meter_ld    =     tesla_meter_impl<std::atto, long double>;
    using exatesla_meter_ull    =     tesla_meter_impl<std::exa, unsigned long long>;
    using petatesla_meter_ull    =     tesla_meter_impl<std::peta, unsigned long long>;
    using teratesla_meter_ull    =     tesla_meter_impl<std::tera, unsigned long long>;
    using gigatesla_meter_ull    =     tesla_meter_impl<std::giga, unsigned long long>;
    using megatesla_meter_ull    =     tesla_meter_impl<std::mega, unsigned long long>;
    using kilotesla_meter_ull    =     tesla_meter_impl<std::kilo, unsigned long long>;
    using hectotesla_meter_ull    =     tesla_meter_impl<std::hecto, unsigned long long>;
    using decatesla_meter_ull    =     tesla_meter_impl<std::deca, unsigned long long>;
    using tesla_meter_ull    =     tesla_meter_impl<unity_ratio, unsigned long long>;
    using decitesla_meter_ull    =     tesla_meter_impl<std::deci, unsigned long long>;
    using centitesla_meter_ull    =     tesla_meter_impl<std::centi, unsigned long long>;
    using millitesla_meter_ull    =     tesla_meter_impl<std::milli, unsigned long long>;
    using microtesla_meter_ull    =     tesla_meter_impl<std::micro, unsigned long long>;
    using nanotesla_meter_ull    =     tesla_meter_impl<std::nano, unsigned long long>;
    using picotesla_meter_ull    =     tesla_meter_impl<std::pico, unsigned long long>;
    using femtotesla_meter_ull    =     tesla_meter_impl<std::femto, unsigned long long>;
    using attotesla_meter_ull    =     tesla_meter_impl<std::atto, unsigned long long>;

    constexpr exatesla_meter_ld operator""_ET_m(long double val) {
        return static_cast<exatesla_meter_ld>(val);
    }
    constexpr petatesla_meter_ld operator""_PT_m(long double val) {
        return static_cast<petatesla_meter_ld>(val);
    }
    constexpr teratesla_meter_ld operator""_TT_m(long double val) {
        return static_cast<teratesla_meter_ld>(val);
    }
    constexpr gigatesla_meter_ld operator""_GT_m(long double val) {
        return static_cast<gigatesla_meter_ld>(val);
    }
    constexpr megatesla_meter_ld operator""_MT_m(long double val) {
        return static_cast<megatesla_meter_ld>(val);
    }
    constexpr kilotesla_meter_ld operator""_kT_m(long double val) {
        return static_cast<kilotesla_meter_ld>(val);
    }
    constexpr hectotesla_meter_ld operator""_hT_m(long double val) {
        return static_cast<hectotesla_meter_ld>(val);
    }
    constexpr decatesla_meter_ld operator""_daT_m(long double val) {
        return static_cast<decatesla_meter_ld>(val);
    }
    constexpr tesla_meter_ld operator""_T_m(long double val) {
        return static_cast<tesla_meter_ld>(val);
    }
    constexpr decitesla_meter_ld operator""_dT_m(long double val) {
        return static_cast<decitesla_meter_ld>(val);
    }
    constexpr centitesla_meter_ld operator""_cT_m(long double val) {
        return static_cast<centitesla_meter_ld>(val);
    }
    constexpr millitesla_meter_ld operator""_mT_m(long double val) {
        return static_cast<millitesla_meter_ld>(val);
    }
    constexpr microtesla_meter_ld operator""_uT_m(long double val) {
        return static_cast<microtesla_meter_ld>(val);
    }
    constexpr nanotesla_meter_ld operator""_nT_m(long double val) {
        return static_cast<nanotesla_meter_ld>(val);
    }
    constexpr picotesla_meter_ld operator""_pT_m(long double val) {
        return static_cast<picotesla_meter_ld>(val);
    }
    constexpr femtotesla_meter_ld operator""_fT_m(long double val) {
        return static_cast<femtotesla_meter_ld>(val);
    }
    constexpr attotesla_meter_ld operator""_aT_m(long double val) {
        return static_cast<attotesla_meter_ld>(val);
    }
    constexpr exatesla_meter_ull operator""_ET_m(unsigned long long val) {
        return static_cast<exatesla_meter_ull>(val);
    }
    constexpr petatesla_meter_ull operator""_PT_m(unsigned long long val) {
        return static_cast<petatesla_meter_ull>(val);
    }
    constexpr teratesla_meter_ull operator""_TT_m(unsigned long long val) {
        return static_cast<teratesla_meter_ull>(val);
    }
    constexpr gigatesla_meter_ull operator""_GT_m(unsigned long long val) {
        return static_cast<gigatesla_meter_ull>(val);
    }
    constexpr megatesla_meter_ull operator""_MT_m(unsigned long long val) {
        return static_cast<megatesla_meter_ull>(val);
    }
    constexpr kilotesla_meter_ull operator""_kT_m(unsigned long long val) {
        return static_cast<kilotesla_meter_ull>(val);
    }
    constexpr hectotesla_meter_ull operator""_hT_m(unsigned long long val) {
        return static_cast<hectotesla_meter_ull>(val);
    }
    constexpr decatesla_meter_ull operator""_daT_m(unsigned long long val) {
        return static_cast<decatesla_meter_ull>(val);
    }
    constexpr tesla_meter_ull operator""_T_m(unsigned long long val) {
        return static_cast<tesla_meter_ull>(val);
    }
    constexpr decitesla_meter_ull operator""_dT_m(unsigned long long val) {
        return static_cast<decitesla_meter_ull>(val);
    }
    constexpr centitesla_meter_ull operator""_cT_m(unsigned long long val) {
        return static_cast<centitesla_meter_ull>(val);
    }
    constexpr millitesla_meter_ull operator""_mT_m(unsigned long long val) {
        return static_cast<millitesla_meter_ull>(val);
    }
    constexpr microtesla_meter_ull operator""_uT_m(unsigned long long val) {
        return static_cast<microtesla_meter_ull>(val);
    }
    constexpr nanotesla_meter_ull operator""_nT_m(unsigned long long val) {
        return static_cast<nanotesla_meter_ull>(val);
    }
    constexpr picotesla_meter_ull operator""_pT_m(unsigned long long val) {
        return static_cast<picotesla_meter_ull>(val);
    }
    constexpr femtotesla_meter_ull operator""_fT_m(unsigned long long val) {
        return static_cast<femtotesla_meter_ull>(val);
    }
    constexpr attotesla_meter_ull operator""_aT_m(unsigned long long val) {
        return static_cast<attotesla_meter_ull>(val);
    }

} // namespace potato::units
