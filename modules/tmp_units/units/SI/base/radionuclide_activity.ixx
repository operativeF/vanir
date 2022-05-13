//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Becquerel;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.BaseUnit;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename RatioTypeT, typename P>
    struct becquerel_impl : base_unit_<RatioTypeT, P> {

        using base_unit_<RatioTypeT, P>::base_unit_;
        template <typename U, typename R>
        constexpr const becquerel_impl<RatioTypeT, P>(const becquerel_impl<U, R>& other) {
            using scale_greater = call_<if_<lift_<std::ratio_greater>,
                always_<std::ratio_divide<U, RatioTypeT>>,
                always_<unity_ratio>>,
                RatioTypeT, U>;
            using scale_lesser = call_<if_<lift_<std::ratio_less>,
                always_<std::ratio_divide<RatioTypeT, U>>,
                always_<unity_ratio>>,
                RatioTypeT, U>;
            this->value = (other.value * scale_greater::num * scale_lesser::den) / (scale_greater::den * scale_lesser::num);
        }

        static constexpr auto pretty = "Bq";

        using is_any_impl = false_;

        using mod_ratio = RatioTypeT;
        using numer_type = base_unit_<RatioTypeT, P>::value_type;
        using impl      = list_<list_<>, list_<decay_l>>;
    };

    using exabecquerel_ld    =     becquerel_impl<std::exa, long double>;
    using petabecquerel_ld    =     becquerel_impl<std::peta, long double>;
    using terabecquerel_ld    =     becquerel_impl<std::tera, long double>;
    using gigabecquerel_ld    =     becquerel_impl<std::giga, long double>;
    using megabecquerel_ld    =     becquerel_impl<std::mega, long double>;
    using kilobecquerel_ld    =     becquerel_impl<std::kilo, long double>;
    using hectobecquerel_ld    =     becquerel_impl<std::hecto, long double>;
    using decabecquerel_ld    =     becquerel_impl<std::deca, long double>;
    using becquerel_ld    =     becquerel_impl<unity_ratio, long double>;
    using decibecquerel_ld    =     becquerel_impl<std::deci, long double>;
    using centibecquerel_ld    =     becquerel_impl<std::centi, long double>;
    using millibecquerel_ld    =     becquerel_impl<std::milli, long double>;
    using microbecquerel_ld    =     becquerel_impl<std::micro, long double>;
    using nanobecquerel_ld    =     becquerel_impl<std::nano, long double>;
    using picobecquerel_ld    =     becquerel_impl<std::pico, long double>;
    using femtobecquerel_ld    =     becquerel_impl<std::femto, long double>;
    using attobecquerel_ld    =     becquerel_impl<std::atto, long double>;
    using exabecquerel_ull    =     becquerel_impl<std::exa, unsigned long long>;
    using petabecquerel_ull    =     becquerel_impl<std::peta, unsigned long long>;
    using terabecquerel_ull    =     becquerel_impl<std::tera, unsigned long long>;
    using gigabecquerel_ull    =     becquerel_impl<std::giga, unsigned long long>;
    using megabecquerel_ull    =     becquerel_impl<std::mega, unsigned long long>;
    using kilobecquerel_ull    =     becquerel_impl<std::kilo, unsigned long long>;
    using hectobecquerel_ull    =     becquerel_impl<std::hecto, unsigned long long>;
    using decabecquerel_ull    =     becquerel_impl<std::deca, unsigned long long>;
    using becquerel_ull    =     becquerel_impl<unity_ratio, unsigned long long>;
    using decibecquerel_ull    =     becquerel_impl<std::deci, unsigned long long>;
    using centibecquerel_ull    =     becquerel_impl<std::centi, unsigned long long>;
    using millibecquerel_ull    =     becquerel_impl<std::milli, unsigned long long>;
    using microbecquerel_ull    =     becquerel_impl<std::micro, unsigned long long>;
    using nanobecquerel_ull    =     becquerel_impl<std::nano, unsigned long long>;
    using picobecquerel_ull    =     becquerel_impl<std::pico, unsigned long long>;
    using femtobecquerel_ull    =     becquerel_impl<std::femto, unsigned long long>;
    using attobecquerel_ull    =     becquerel_impl<std::atto, unsigned long long>;

    constexpr exabecquerel_ld operator""_EBq(long double val) {
        return static_cast<exabecquerel_ld>(val);
    }
    constexpr petabecquerel_ld operator""_PBq(long double val) {
        return static_cast<petabecquerel_ld>(val);
    }
    constexpr terabecquerel_ld operator""_TBq(long double val) {
        return static_cast<terabecquerel_ld>(val);
    }
    constexpr gigabecquerel_ld operator""_GBq(long double val) {
        return static_cast<gigabecquerel_ld>(val);
    }
    constexpr megabecquerel_ld operator""_MBq(long double val) {
        return static_cast<megabecquerel_ld>(val);
    }
    constexpr kilobecquerel_ld operator""_kBq(long double val) {
        return static_cast<kilobecquerel_ld>(val);
    }
    constexpr hectobecquerel_ld operator""_hBq(long double val) {
        return static_cast<hectobecquerel_ld>(val);
    }
    constexpr decabecquerel_ld operator""_daBq(long double val) {
        return static_cast<decabecquerel_ld>(val);
    }
    constexpr becquerel_ld operator""_Bq(long double val) {
        return static_cast<becquerel_ld>(val);
    }
    constexpr decibecquerel_ld operator""_dBq(long double val) {
        return static_cast<decibecquerel_ld>(val);
    }
    constexpr centibecquerel_ld operator""_cBq(long double val) {
        return static_cast<centibecquerel_ld>(val);
    }
    constexpr millibecquerel_ld operator""_mBq(long double val) {
        return static_cast<millibecquerel_ld>(val);
    }
    constexpr microbecquerel_ld operator""_uBq(long double val) {
        return static_cast<microbecquerel_ld>(val);
    }
    constexpr nanobecquerel_ld operator""_nBq(long double val) {
        return static_cast<nanobecquerel_ld>(val);
    }
    constexpr picobecquerel_ld operator""_pBq(long double val) {
        return static_cast<picobecquerel_ld>(val);
    }
    constexpr femtobecquerel_ld operator""_fBq(long double val) {
        return static_cast<femtobecquerel_ld>(val);
    }
    constexpr attobecquerel_ld operator""_aBq(long double val) {
        return static_cast<attobecquerel_ld>(val);
    }
    constexpr exabecquerel_ull operator""_EBq(unsigned long long val) {
        return static_cast<exabecquerel_ull>(val);
    }
    constexpr petabecquerel_ull operator""_PBq(unsigned long long val) {
        return static_cast<petabecquerel_ull>(val);
    }
    constexpr terabecquerel_ull operator""_TBq(unsigned long long val) {
        return static_cast<terabecquerel_ull>(val);
    }
    constexpr gigabecquerel_ull operator""_GBq(unsigned long long val) {
        return static_cast<gigabecquerel_ull>(val);
    }
    constexpr megabecquerel_ull operator""_MBq(unsigned long long val) {
        return static_cast<megabecquerel_ull>(val);
    }
    constexpr kilobecquerel_ull operator""_kBq(unsigned long long val) {
        return static_cast<kilobecquerel_ull>(val);
    }
    constexpr hectobecquerel_ull operator""_hBq(unsigned long long val) {
        return static_cast<hectobecquerel_ull>(val);
    }
    constexpr decabecquerel_ull operator""_daBq(unsigned long long val) {
        return static_cast<decabecquerel_ull>(val);
    }
    constexpr becquerel_ull operator""_Bq(unsigned long long val) {
        return static_cast<becquerel_ull>(val);
    }
    constexpr decibecquerel_ull operator""_dBq(unsigned long long val) {
        return static_cast<decibecquerel_ull>(val);
    }
    constexpr centibecquerel_ull operator""_cBq(unsigned long long val) {
        return static_cast<centibecquerel_ull>(val);
    }
    constexpr millibecquerel_ull operator""_mBq(unsigned long long val) {
        return static_cast<millibecquerel_ull>(val);
    }
    constexpr microbecquerel_ull operator""_uBq(unsigned long long val) {
        return static_cast<microbecquerel_ull>(val);
    }
    constexpr nanobecquerel_ull operator""_nBq(unsigned long long val) {
        return static_cast<nanobecquerel_ull>(val);
    }
    constexpr picobecquerel_ull operator""_pBq(unsigned long long val) {
        return static_cast<picobecquerel_ull>(val);
    }
    constexpr femtobecquerel_ull operator""_fBq(unsigned long long val) {
        return static_cast<femtobecquerel_ull>(val);
    }
    constexpr attobecquerel_ull operator""_aBq(unsigned long long val) {
        return static_cast<attobecquerel_ull>(val);
    }

} // namespace potato::units
