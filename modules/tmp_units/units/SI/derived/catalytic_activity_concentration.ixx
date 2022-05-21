//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Katal_Per_Cubic_Meter;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using catalytic_activity_concentration_tag_t = tmp::list_<Length<std::ratio<-3, 1>>,
                                         Time<std::ratio<-1, 1>>,
                                         Mass<std::ratio<0, 1>>,
                                         AmountOfSubstance<std::ratio<1, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept Katal_Per_Cubic_MeterC = std::same_as<typename T::impl, catalytic_activity_concentration_tag_t>;

    template <typename RatioTypeT, typename P>
    struct katal_per_cubic_meter_impl {

        static constexpr auto pretty = "kat/m³";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = catalytic_activity_concentration_tag_t;

        constexpr katal_per_cubic_meter_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exakatal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<std::exa, long double>;
    using petakatal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<std::peta, long double>;
    using terakatal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<std::tera, long double>;
    using gigakatal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<std::giga, long double>;
    using megakatal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<std::mega, long double>;
    using kilokatal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<std::kilo, long double>;
    using hectokatal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<std::hecto, long double>;
    using decakatal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<std::deca, long double>;
    using katal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<unity_ratio, long double>;
    using decikatal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<std::deci, long double>;
    using centikatal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<std::centi, long double>;
    using millikatal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<std::milli, long double>;
    using microkatal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<std::micro, long double>;
    using nanokatal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<std::nano, long double>;
    using picokatal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<std::pico, long double>;
    using femtokatal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<std::femto, long double>;
    using attokatal_per_cubic_meter_ld    =     katal_per_cubic_meter_impl<std::atto, long double>;
    using exakatal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<std::exa, unsigned long long>;
    using petakatal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<std::peta, unsigned long long>;
    using terakatal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<std::tera, unsigned long long>;
    using gigakatal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<std::giga, unsigned long long>;
    using megakatal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<std::mega, unsigned long long>;
    using kilokatal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<std::kilo, unsigned long long>;
    using hectokatal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<std::hecto, unsigned long long>;
    using decakatal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<std::deca, unsigned long long>;
    using katal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<unity_ratio, unsigned long long>;
    using decikatal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<std::deci, unsigned long long>;
    using centikatal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<std::centi, unsigned long long>;
    using millikatal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<std::milli, unsigned long long>;
    using microkatal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<std::micro, unsigned long long>;
    using nanokatal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<std::nano, unsigned long long>;
    using picokatal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<std::pico, unsigned long long>;
    using femtokatal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<std::femto, unsigned long long>;
    using attokatal_per_cubic_meter_ull    =     katal_per_cubic_meter_impl<std::atto, unsigned long long>;

    consteval exakatal_per_cubic_meter_ld operator""_Ekat_per_cubic_m(long double val) {
        return static_cast<exakatal_per_cubic_meter_ld>(val);
    }
    consteval petakatal_per_cubic_meter_ld operator""_Pkat_per_cubic_m(long double val) {
        return static_cast<petakatal_per_cubic_meter_ld>(val);
    }
    consteval terakatal_per_cubic_meter_ld operator""_Tkat_per_cubic_m(long double val) {
        return static_cast<terakatal_per_cubic_meter_ld>(val);
    }
    consteval gigakatal_per_cubic_meter_ld operator""_Gkat_per_cubic_m(long double val) {
        return static_cast<gigakatal_per_cubic_meter_ld>(val);
    }
    consteval megakatal_per_cubic_meter_ld operator""_Mkat_per_cubic_m(long double val) {
        return static_cast<megakatal_per_cubic_meter_ld>(val);
    }
    consteval kilokatal_per_cubic_meter_ld operator""_kkat_per_cubic_m(long double val) {
        return static_cast<kilokatal_per_cubic_meter_ld>(val);
    }
    consteval hectokatal_per_cubic_meter_ld operator""_hkat_per_cubic_m(long double val) {
        return static_cast<hectokatal_per_cubic_meter_ld>(val);
    }
    consteval decakatal_per_cubic_meter_ld operator""_dakat_per_cubic_m(long double val) {
        return static_cast<decakatal_per_cubic_meter_ld>(val);
    }
    consteval katal_per_cubic_meter_ld operator""_kat_per_cubic_m(long double val) {
        return static_cast<katal_per_cubic_meter_ld>(val);
    }
    consteval decikatal_per_cubic_meter_ld operator""_dkat_per_cubic_m(long double val) {
        return static_cast<decikatal_per_cubic_meter_ld>(val);
    }
    consteval centikatal_per_cubic_meter_ld operator""_ckat_per_cubic_m(long double val) {
        return static_cast<centikatal_per_cubic_meter_ld>(val);
    }
    consteval millikatal_per_cubic_meter_ld operator""_mkat_per_cubic_m(long double val) {
        return static_cast<millikatal_per_cubic_meter_ld>(val);
    }
    consteval microkatal_per_cubic_meter_ld operator""_ukat_per_cubic_m(long double val) {
        return static_cast<microkatal_per_cubic_meter_ld>(val);
    }
    consteval nanokatal_per_cubic_meter_ld operator""_nkat_per_cubic_m(long double val) {
        return static_cast<nanokatal_per_cubic_meter_ld>(val);
    }
    consteval picokatal_per_cubic_meter_ld operator""_pkat_per_cubic_m(long double val) {
        return static_cast<picokatal_per_cubic_meter_ld>(val);
    }
    consteval femtokatal_per_cubic_meter_ld operator""_fkat_per_cubic_m(long double val) {
        return static_cast<femtokatal_per_cubic_meter_ld>(val);
    }
    consteval attokatal_per_cubic_meter_ld operator""_akat_per_cubic_m(long double val) {
        return static_cast<attokatal_per_cubic_meter_ld>(val);
    }
    consteval exakatal_per_cubic_meter_ull operator""_Ekat_per_cubic_m(unsigned long long val) {
        return static_cast<exakatal_per_cubic_meter_ull>(val);
    }
    consteval petakatal_per_cubic_meter_ull operator""_Pkat_per_cubic_m(unsigned long long val) {
        return static_cast<petakatal_per_cubic_meter_ull>(val);
    }
    consteval terakatal_per_cubic_meter_ull operator""_Tkat_per_cubic_m(unsigned long long val) {
        return static_cast<terakatal_per_cubic_meter_ull>(val);
    }
    consteval gigakatal_per_cubic_meter_ull operator""_Gkat_per_cubic_m(unsigned long long val) {
        return static_cast<gigakatal_per_cubic_meter_ull>(val);
    }
    consteval megakatal_per_cubic_meter_ull operator""_Mkat_per_cubic_m(unsigned long long val) {
        return static_cast<megakatal_per_cubic_meter_ull>(val);
    }
    consteval kilokatal_per_cubic_meter_ull operator""_kkat_per_cubic_m(unsigned long long val) {
        return static_cast<kilokatal_per_cubic_meter_ull>(val);
    }
    consteval hectokatal_per_cubic_meter_ull operator""_hkat_per_cubic_m(unsigned long long val) {
        return static_cast<hectokatal_per_cubic_meter_ull>(val);
    }
    consteval decakatal_per_cubic_meter_ull operator""_dakat_per_cubic_m(unsigned long long val) {
        return static_cast<decakatal_per_cubic_meter_ull>(val);
    }
    consteval katal_per_cubic_meter_ull operator""_kat_per_cubic_m(unsigned long long val) {
        return static_cast<katal_per_cubic_meter_ull>(val);
    }
    consteval decikatal_per_cubic_meter_ull operator""_dkat_per_cubic_m(unsigned long long val) {
        return static_cast<decikatal_per_cubic_meter_ull>(val);
    }
    consteval centikatal_per_cubic_meter_ull operator""_ckat_per_cubic_m(unsigned long long val) {
        return static_cast<centikatal_per_cubic_meter_ull>(val);
    }
    consteval millikatal_per_cubic_meter_ull operator""_mkat_per_cubic_m(unsigned long long val) {
        return static_cast<millikatal_per_cubic_meter_ull>(val);
    }
    consteval microkatal_per_cubic_meter_ull operator""_ukat_per_cubic_m(unsigned long long val) {
        return static_cast<microkatal_per_cubic_meter_ull>(val);
    }
    consteval nanokatal_per_cubic_meter_ull operator""_nkat_per_cubic_m(unsigned long long val) {
        return static_cast<nanokatal_per_cubic_meter_ull>(val);
    }
    consteval picokatal_per_cubic_meter_ull operator""_pkat_per_cubic_m(unsigned long long val) {
        return static_cast<picokatal_per_cubic_meter_ull>(val);
    }
    consteval femtokatal_per_cubic_meter_ull operator""_fkat_per_cubic_m(unsigned long long val) {
        return static_cast<femtokatal_per_cubic_meter_ull>(val);
    }
    consteval attokatal_per_cubic_meter_ull operator""_akat_per_cubic_m(unsigned long long val) {
        return static_cast<attokatal_per_cubic_meter_ull>(val);
    }

} // namespace potato::units
