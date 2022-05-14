//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Ampere_Per_Square_Meter;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using ampere_per_square_meter_tag_t = tmp::list_<tmp::list_<ampere_l>, tmp::list_<meter_l, meter_l>>;

    template<typename T>
    concept Ampere_Per_Square_MeterC = std::same_as<typename T::impl, ampere_per_square_meter_tag_t>;

    template <typename RatioTypeT, typename P>
    struct ampere_per_square_meter_impl {

        static constexpr auto pretty = "A/m²";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = ampere_per_square_meter_tag_t;

        constexpr ampere_per_square_meter_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exaampere_per_square_meter_ld    =     ampere_per_square_meter_impl<std::exa, long double>;
    using petaampere_per_square_meter_ld    =     ampere_per_square_meter_impl<std::peta, long double>;
    using teraampere_per_square_meter_ld    =     ampere_per_square_meter_impl<std::tera, long double>;
    using gigaampere_per_square_meter_ld    =     ampere_per_square_meter_impl<std::giga, long double>;
    using megaampere_per_square_meter_ld    =     ampere_per_square_meter_impl<std::mega, long double>;
    using kiloampere_per_square_meter_ld    =     ampere_per_square_meter_impl<std::kilo, long double>;
    using hectoampere_per_square_meter_ld    =     ampere_per_square_meter_impl<std::hecto, long double>;
    using decaampere_per_square_meter_ld    =     ampere_per_square_meter_impl<std::deca, long double>;
    using ampere_per_square_meter_ld    =     ampere_per_square_meter_impl<unity_ratio, long double>;
    using deciampere_per_square_meter_ld    =     ampere_per_square_meter_impl<std::deci, long double>;
    using centiampere_per_square_meter_ld    =     ampere_per_square_meter_impl<std::centi, long double>;
    using milliampere_per_square_meter_ld    =     ampere_per_square_meter_impl<std::milli, long double>;
    using microampere_per_square_meter_ld    =     ampere_per_square_meter_impl<std::micro, long double>;
    using nanoampere_per_square_meter_ld    =     ampere_per_square_meter_impl<std::nano, long double>;
    using picoampere_per_square_meter_ld    =     ampere_per_square_meter_impl<std::pico, long double>;
    using femtoampere_per_square_meter_ld    =     ampere_per_square_meter_impl<std::femto, long double>;
    using attoampere_per_square_meter_ld    =     ampere_per_square_meter_impl<std::atto, long double>;
    using exaampere_per_square_meter_ull    =     ampere_per_square_meter_impl<std::exa, unsigned long long>;
    using petaampere_per_square_meter_ull    =     ampere_per_square_meter_impl<std::peta, unsigned long long>;
    using teraampere_per_square_meter_ull    =     ampere_per_square_meter_impl<std::tera, unsigned long long>;
    using gigaampere_per_square_meter_ull    =     ampere_per_square_meter_impl<std::giga, unsigned long long>;
    using megaampere_per_square_meter_ull    =     ampere_per_square_meter_impl<std::mega, unsigned long long>;
    using kiloampere_per_square_meter_ull    =     ampere_per_square_meter_impl<std::kilo, unsigned long long>;
    using hectoampere_per_square_meter_ull    =     ampere_per_square_meter_impl<std::hecto, unsigned long long>;
    using decaampere_per_square_meter_ull    =     ampere_per_square_meter_impl<std::deca, unsigned long long>;
    using ampere_per_square_meter_ull    =     ampere_per_square_meter_impl<unity_ratio, unsigned long long>;
    using deciampere_per_square_meter_ull    =     ampere_per_square_meter_impl<std::deci, unsigned long long>;
    using centiampere_per_square_meter_ull    =     ampere_per_square_meter_impl<std::centi, unsigned long long>;
    using milliampere_per_square_meter_ull    =     ampere_per_square_meter_impl<std::milli, unsigned long long>;
    using microampere_per_square_meter_ull    =     ampere_per_square_meter_impl<std::micro, unsigned long long>;
    using nanoampere_per_square_meter_ull    =     ampere_per_square_meter_impl<std::nano, unsigned long long>;
    using picoampere_per_square_meter_ull    =     ampere_per_square_meter_impl<std::pico, unsigned long long>;
    using femtoampere_per_square_meter_ull    =     ampere_per_square_meter_impl<std::femto, unsigned long long>;
    using attoampere_per_square_meter_ull    =     ampere_per_square_meter_impl<std::atto, unsigned long long>;

    constexpr exaampere_per_square_meter_ld operator""_EA_per_sq_m(long double val) {
        return static_cast<exaampere_per_square_meter_ld>(val);
    }
    constexpr petaampere_per_square_meter_ld operator""_PA_per_sq_m(long double val) {
        return static_cast<petaampere_per_square_meter_ld>(val);
    }
    constexpr teraampere_per_square_meter_ld operator""_TA_per_sq_m(long double val) {
        return static_cast<teraampere_per_square_meter_ld>(val);
    }
    constexpr gigaampere_per_square_meter_ld operator""_GA_per_sq_m(long double val) {
        return static_cast<gigaampere_per_square_meter_ld>(val);
    }
    constexpr megaampere_per_square_meter_ld operator""_MA_per_sq_m(long double val) {
        return static_cast<megaampere_per_square_meter_ld>(val);
    }
    constexpr kiloampere_per_square_meter_ld operator""_kA_per_sq_m(long double val) {
        return static_cast<kiloampere_per_square_meter_ld>(val);
    }
    constexpr hectoampere_per_square_meter_ld operator""_hA_per_sq_m(long double val) {
        return static_cast<hectoampere_per_square_meter_ld>(val);
    }
    constexpr decaampere_per_square_meter_ld operator""_daA_per_sq_m(long double val) {
        return static_cast<decaampere_per_square_meter_ld>(val);
    }
    constexpr ampere_per_square_meter_ld operator""_A_per_sq_m(long double val) {
        return static_cast<ampere_per_square_meter_ld>(val);
    }
    constexpr deciampere_per_square_meter_ld operator""_dA_per_sq_m(long double val) {
        return static_cast<deciampere_per_square_meter_ld>(val);
    }
    constexpr centiampere_per_square_meter_ld operator""_cA_per_sq_m(long double val) {
        return static_cast<centiampere_per_square_meter_ld>(val);
    }
    constexpr milliampere_per_square_meter_ld operator""_mA_per_sq_m(long double val) {
        return static_cast<milliampere_per_square_meter_ld>(val);
    }
    constexpr microampere_per_square_meter_ld operator""_uA_per_sq_m(long double val) {
        return static_cast<microampere_per_square_meter_ld>(val);
    }
    constexpr nanoampere_per_square_meter_ld operator""_nA_per_sq_m(long double val) {
        return static_cast<nanoampere_per_square_meter_ld>(val);
    }
    constexpr picoampere_per_square_meter_ld operator""_pA_per_sq_m(long double val) {
        return static_cast<picoampere_per_square_meter_ld>(val);
    }
    constexpr femtoampere_per_square_meter_ld operator""_fA_per_sq_m(long double val) {
        return static_cast<femtoampere_per_square_meter_ld>(val);
    }
    constexpr attoampere_per_square_meter_ld operator""_aA_per_sq_m(long double val) {
        return static_cast<attoampere_per_square_meter_ld>(val);
    }
    constexpr exaampere_per_square_meter_ull operator""_EA_per_sq_m(unsigned long long val) {
        return static_cast<exaampere_per_square_meter_ull>(val);
    }
    constexpr petaampere_per_square_meter_ull operator""_PA_per_sq_m(unsigned long long val) {
        return static_cast<petaampere_per_square_meter_ull>(val);
    }
    constexpr teraampere_per_square_meter_ull operator""_TA_per_sq_m(unsigned long long val) {
        return static_cast<teraampere_per_square_meter_ull>(val);
    }
    constexpr gigaampere_per_square_meter_ull operator""_GA_per_sq_m(unsigned long long val) {
        return static_cast<gigaampere_per_square_meter_ull>(val);
    }
    constexpr megaampere_per_square_meter_ull operator""_MA_per_sq_m(unsigned long long val) {
        return static_cast<megaampere_per_square_meter_ull>(val);
    }
    constexpr kiloampere_per_square_meter_ull operator""_kA_per_sq_m(unsigned long long val) {
        return static_cast<kiloampere_per_square_meter_ull>(val);
    }
    constexpr hectoampere_per_square_meter_ull operator""_hA_per_sq_m(unsigned long long val) {
        return static_cast<hectoampere_per_square_meter_ull>(val);
    }
    constexpr decaampere_per_square_meter_ull operator""_daA_per_sq_m(unsigned long long val) {
        return static_cast<decaampere_per_square_meter_ull>(val);
    }
    constexpr ampere_per_square_meter_ull operator""_A_per_sq_m(unsigned long long val) {
        return static_cast<ampere_per_square_meter_ull>(val);
    }
    constexpr deciampere_per_square_meter_ull operator""_dA_per_sq_m(unsigned long long val) {
        return static_cast<deciampere_per_square_meter_ull>(val);
    }
    constexpr centiampere_per_square_meter_ull operator""_cA_per_sq_m(unsigned long long val) {
        return static_cast<centiampere_per_square_meter_ull>(val);
    }
    constexpr milliampere_per_square_meter_ull operator""_mA_per_sq_m(unsigned long long val) {
        return static_cast<milliampere_per_square_meter_ull>(val);
    }
    constexpr microampere_per_square_meter_ull operator""_uA_per_sq_m(unsigned long long val) {
        return static_cast<microampere_per_square_meter_ull>(val);
    }
    constexpr nanoampere_per_square_meter_ull operator""_nA_per_sq_m(unsigned long long val) {
        return static_cast<nanoampere_per_square_meter_ull>(val);
    }
    constexpr picoampere_per_square_meter_ull operator""_pA_per_sq_m(unsigned long long val) {
        return static_cast<picoampere_per_square_meter_ull>(val);
    }
    constexpr femtoampere_per_square_meter_ull operator""_fA_per_sq_m(unsigned long long val) {
        return static_cast<femtoampere_per_square_meter_ull>(val);
    }
    constexpr attoampere_per_square_meter_ull operator""_aA_per_sq_m(unsigned long long val) {
        return static_cast<attoampere_per_square_meter_ull>(val);
    }

} // namespace potato::units
