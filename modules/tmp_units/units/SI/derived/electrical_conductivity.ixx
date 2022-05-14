//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Siemens_Per_Meter;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using siemens_per_meter_tag_t = tmp::list_<tmp::list_<second_l, second_l, second_l, ampere_l, ampere_l>, tmp::list_<meter_l, meter_l, meter_l, gram_l>>;

    template<typename T>
    concept Siemens_Per_MeterC = std::same_as<typename T::impl, siemens_per_meter_tag_t>;

    template <typename RatioTypeT, typename P>
    struct siemens_per_meter_impl {

        static constexpr auto pretty = "S/m";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = siemens_per_meter_tag_t;

        constexpr siemens_per_meter_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exasiemens_per_meter_ld    =     siemens_per_meter_impl<std::exa, long double>;
    using petasiemens_per_meter_ld    =     siemens_per_meter_impl<std::peta, long double>;
    using terasiemens_per_meter_ld    =     siemens_per_meter_impl<std::tera, long double>;
    using gigasiemens_per_meter_ld    =     siemens_per_meter_impl<std::giga, long double>;
    using megasiemens_per_meter_ld    =     siemens_per_meter_impl<std::mega, long double>;
    using kilosiemens_per_meter_ld    =     siemens_per_meter_impl<std::kilo, long double>;
    using hectosiemens_per_meter_ld    =     siemens_per_meter_impl<std::hecto, long double>;
    using decasiemens_per_meter_ld    =     siemens_per_meter_impl<std::deca, long double>;
    using siemens_per_meter_ld    =     siemens_per_meter_impl<unity_ratio, long double>;
    using decisiemens_per_meter_ld    =     siemens_per_meter_impl<std::deci, long double>;
    using centisiemens_per_meter_ld    =     siemens_per_meter_impl<std::centi, long double>;
    using millisiemens_per_meter_ld    =     siemens_per_meter_impl<std::milli, long double>;
    using microsiemens_per_meter_ld    =     siemens_per_meter_impl<std::micro, long double>;
    using nanosiemens_per_meter_ld    =     siemens_per_meter_impl<std::nano, long double>;
    using picosiemens_per_meter_ld    =     siemens_per_meter_impl<std::pico, long double>;
    using femtosiemens_per_meter_ld    =     siemens_per_meter_impl<std::femto, long double>;
    using attosiemens_per_meter_ld    =     siemens_per_meter_impl<std::atto, long double>;
    using exasiemens_per_meter_ull    =     siemens_per_meter_impl<std::exa, unsigned long long>;
    using petasiemens_per_meter_ull    =     siemens_per_meter_impl<std::peta, unsigned long long>;
    using terasiemens_per_meter_ull    =     siemens_per_meter_impl<std::tera, unsigned long long>;
    using gigasiemens_per_meter_ull    =     siemens_per_meter_impl<std::giga, unsigned long long>;
    using megasiemens_per_meter_ull    =     siemens_per_meter_impl<std::mega, unsigned long long>;
    using kilosiemens_per_meter_ull    =     siemens_per_meter_impl<std::kilo, unsigned long long>;
    using hectosiemens_per_meter_ull    =     siemens_per_meter_impl<std::hecto, unsigned long long>;
    using decasiemens_per_meter_ull    =     siemens_per_meter_impl<std::deca, unsigned long long>;
    using siemens_per_meter_ull    =     siemens_per_meter_impl<unity_ratio, unsigned long long>;
    using decisiemens_per_meter_ull    =     siemens_per_meter_impl<std::deci, unsigned long long>;
    using centisiemens_per_meter_ull    =     siemens_per_meter_impl<std::centi, unsigned long long>;
    using millisiemens_per_meter_ull    =     siemens_per_meter_impl<std::milli, unsigned long long>;
    using microsiemens_per_meter_ull    =     siemens_per_meter_impl<std::micro, unsigned long long>;
    using nanosiemens_per_meter_ull    =     siemens_per_meter_impl<std::nano, unsigned long long>;
    using picosiemens_per_meter_ull    =     siemens_per_meter_impl<std::pico, unsigned long long>;
    using femtosiemens_per_meter_ull    =     siemens_per_meter_impl<std::femto, unsigned long long>;
    using attosiemens_per_meter_ull    =     siemens_per_meter_impl<std::atto, unsigned long long>;

    constexpr exasiemens_per_meter_ld operator""_ES_per_m(long double val) {
        return static_cast<exasiemens_per_meter_ld>(val);
    }
    constexpr petasiemens_per_meter_ld operator""_PS_per_m(long double val) {
        return static_cast<petasiemens_per_meter_ld>(val);
    }
    constexpr terasiemens_per_meter_ld operator""_TS_per_m(long double val) {
        return static_cast<terasiemens_per_meter_ld>(val);
    }
    constexpr gigasiemens_per_meter_ld operator""_GS_per_m(long double val) {
        return static_cast<gigasiemens_per_meter_ld>(val);
    }
    constexpr megasiemens_per_meter_ld operator""_MS_per_m(long double val) {
        return static_cast<megasiemens_per_meter_ld>(val);
    }
    constexpr kilosiemens_per_meter_ld operator""_kS_per_m(long double val) {
        return static_cast<kilosiemens_per_meter_ld>(val);
    }
    constexpr hectosiemens_per_meter_ld operator""_hS_per_m(long double val) {
        return static_cast<hectosiemens_per_meter_ld>(val);
    }
    constexpr decasiemens_per_meter_ld operator""_daS_per_m(long double val) {
        return static_cast<decasiemens_per_meter_ld>(val);
    }
    constexpr siemens_per_meter_ld operator""_S_per_m(long double val) {
        return static_cast<siemens_per_meter_ld>(val);
    }
    constexpr decisiemens_per_meter_ld operator""_dS_per_m(long double val) {
        return static_cast<decisiemens_per_meter_ld>(val);
    }
    constexpr centisiemens_per_meter_ld operator""_cS_per_m(long double val) {
        return static_cast<centisiemens_per_meter_ld>(val);
    }
    constexpr millisiemens_per_meter_ld operator""_mS_per_m(long double val) {
        return static_cast<millisiemens_per_meter_ld>(val);
    }
    constexpr microsiemens_per_meter_ld operator""_uS_per_m(long double val) {
        return static_cast<microsiemens_per_meter_ld>(val);
    }
    constexpr nanosiemens_per_meter_ld operator""_nS_per_m(long double val) {
        return static_cast<nanosiemens_per_meter_ld>(val);
    }
    constexpr picosiemens_per_meter_ld operator""_pS_per_m(long double val) {
        return static_cast<picosiemens_per_meter_ld>(val);
    }
    constexpr femtosiemens_per_meter_ld operator""_fS_per_m(long double val) {
        return static_cast<femtosiemens_per_meter_ld>(val);
    }
    constexpr attosiemens_per_meter_ld operator""_aS_per_m(long double val) {
        return static_cast<attosiemens_per_meter_ld>(val);
    }
    constexpr exasiemens_per_meter_ull operator""_ES_per_m(unsigned long long val) {
        return static_cast<exasiemens_per_meter_ull>(val);
    }
    constexpr petasiemens_per_meter_ull operator""_PS_per_m(unsigned long long val) {
        return static_cast<petasiemens_per_meter_ull>(val);
    }
    constexpr terasiemens_per_meter_ull operator""_TS_per_m(unsigned long long val) {
        return static_cast<terasiemens_per_meter_ull>(val);
    }
    constexpr gigasiemens_per_meter_ull operator""_GS_per_m(unsigned long long val) {
        return static_cast<gigasiemens_per_meter_ull>(val);
    }
    constexpr megasiemens_per_meter_ull operator""_MS_per_m(unsigned long long val) {
        return static_cast<megasiemens_per_meter_ull>(val);
    }
    constexpr kilosiemens_per_meter_ull operator""_kS_per_m(unsigned long long val) {
        return static_cast<kilosiemens_per_meter_ull>(val);
    }
    constexpr hectosiemens_per_meter_ull operator""_hS_per_m(unsigned long long val) {
        return static_cast<hectosiemens_per_meter_ull>(val);
    }
    constexpr decasiemens_per_meter_ull operator""_daS_per_m(unsigned long long val) {
        return static_cast<decasiemens_per_meter_ull>(val);
    }
    constexpr siemens_per_meter_ull operator""_S_per_m(unsigned long long val) {
        return static_cast<siemens_per_meter_ull>(val);
    }
    constexpr decisiemens_per_meter_ull operator""_dS_per_m(unsigned long long val) {
        return static_cast<decisiemens_per_meter_ull>(val);
    }
    constexpr centisiemens_per_meter_ull operator""_cS_per_m(unsigned long long val) {
        return static_cast<centisiemens_per_meter_ull>(val);
    }
    constexpr millisiemens_per_meter_ull operator""_mS_per_m(unsigned long long val) {
        return static_cast<millisiemens_per_meter_ull>(val);
    }
    constexpr microsiemens_per_meter_ull operator""_uS_per_m(unsigned long long val) {
        return static_cast<microsiemens_per_meter_ull>(val);
    }
    constexpr nanosiemens_per_meter_ull operator""_nS_per_m(unsigned long long val) {
        return static_cast<nanosiemens_per_meter_ull>(val);
    }
    constexpr picosiemens_per_meter_ull operator""_pS_per_m(unsigned long long val) {
        return static_cast<picosiemens_per_meter_ull>(val);
    }
    constexpr femtosiemens_per_meter_ull operator""_fS_per_m(unsigned long long val) {
        return static_cast<femtosiemens_per_meter_ull>(val);
    }
    constexpr attosiemens_per_meter_ull operator""_aS_per_m(unsigned long long val) {
        return static_cast<attosiemens_per_meter_ull>(val);
    }

} // namespace potato::units
