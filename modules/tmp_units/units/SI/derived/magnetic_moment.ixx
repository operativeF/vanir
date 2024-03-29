//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Weber_Meter;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using magnetic_moment_tag_t = tmp::list_<Length<std::ratio<3, 1>>,
                                         Time<std::ratio<-2, 1>>,
                                         Mass<std::ratio<1, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<1, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept Weber_MeterC = std::same_as<typename T::impl, magnetic_moment_tag_t>;

    template <typename RatioTypeT, typename P>
    struct weber_meter_impl {

        static constexpr auto pretty = "Wb·m";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = magnetic_moment_tag_t;

        constexpr weber_meter_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exaweber_meter_ld    =     weber_meter_impl<std::exa, long double>;
    using petaweber_meter_ld    =     weber_meter_impl<std::peta, long double>;
    using teraweber_meter_ld    =     weber_meter_impl<std::tera, long double>;
    using gigaweber_meter_ld    =     weber_meter_impl<std::giga, long double>;
    using megaweber_meter_ld    =     weber_meter_impl<std::mega, long double>;
    using kiloweber_meter_ld    =     weber_meter_impl<std::kilo, long double>;
    using hectoweber_meter_ld    =     weber_meter_impl<std::hecto, long double>;
    using decaweber_meter_ld    =     weber_meter_impl<std::deca, long double>;
    using weber_meter_ld    =     weber_meter_impl<unity_ratio, long double>;
    using deciweber_meter_ld    =     weber_meter_impl<std::deci, long double>;
    using centiweber_meter_ld    =     weber_meter_impl<std::centi, long double>;
    using milliweber_meter_ld    =     weber_meter_impl<std::milli, long double>;
    using microweber_meter_ld    =     weber_meter_impl<std::micro, long double>;
    using nanoweber_meter_ld    =     weber_meter_impl<std::nano, long double>;
    using picoweber_meter_ld    =     weber_meter_impl<std::pico, long double>;
    using femtoweber_meter_ld    =     weber_meter_impl<std::femto, long double>;
    using attoweber_meter_ld    =     weber_meter_impl<std::atto, long double>;
    using exaweber_meter_ull    =     weber_meter_impl<std::exa, unsigned long long>;
    using petaweber_meter_ull    =     weber_meter_impl<std::peta, unsigned long long>;
    using teraweber_meter_ull    =     weber_meter_impl<std::tera, unsigned long long>;
    using gigaweber_meter_ull    =     weber_meter_impl<std::giga, unsigned long long>;
    using megaweber_meter_ull    =     weber_meter_impl<std::mega, unsigned long long>;
    using kiloweber_meter_ull    =     weber_meter_impl<std::kilo, unsigned long long>;
    using hectoweber_meter_ull    =     weber_meter_impl<std::hecto, unsigned long long>;
    using decaweber_meter_ull    =     weber_meter_impl<std::deca, unsigned long long>;
    using weber_meter_ull    =     weber_meter_impl<unity_ratio, unsigned long long>;
    using deciweber_meter_ull    =     weber_meter_impl<std::deci, unsigned long long>;
    using centiweber_meter_ull    =     weber_meter_impl<std::centi, unsigned long long>;
    using milliweber_meter_ull    =     weber_meter_impl<std::milli, unsigned long long>;
    using microweber_meter_ull    =     weber_meter_impl<std::micro, unsigned long long>;
    using nanoweber_meter_ull    =     weber_meter_impl<std::nano, unsigned long long>;
    using picoweber_meter_ull    =     weber_meter_impl<std::pico, unsigned long long>;
    using femtoweber_meter_ull    =     weber_meter_impl<std::femto, unsigned long long>;
    using attoweber_meter_ull    =     weber_meter_impl<std::atto, unsigned long long>;

    consteval exaweber_meter_ld operator""_EWb_m(long double val) {
        return static_cast<exaweber_meter_ld>(val);
    }
    consteval petaweber_meter_ld operator""_PWb_m(long double val) {
        return static_cast<petaweber_meter_ld>(val);
    }
    consteval teraweber_meter_ld operator""_TWb_m(long double val) {
        return static_cast<teraweber_meter_ld>(val);
    }
    consteval gigaweber_meter_ld operator""_GWb_m(long double val) {
        return static_cast<gigaweber_meter_ld>(val);
    }
    consteval megaweber_meter_ld operator""_MWb_m(long double val) {
        return static_cast<megaweber_meter_ld>(val);
    }
    consteval kiloweber_meter_ld operator""_kWb_m(long double val) {
        return static_cast<kiloweber_meter_ld>(val);
    }
    consteval hectoweber_meter_ld operator""_hWb_m(long double val) {
        return static_cast<hectoweber_meter_ld>(val);
    }
    consteval decaweber_meter_ld operator""_daWb_m(long double val) {
        return static_cast<decaweber_meter_ld>(val);
    }
    consteval weber_meter_ld operator""_Wb_m(long double val) {
        return static_cast<weber_meter_ld>(val);
    }
    consteval deciweber_meter_ld operator""_dWb_m(long double val) {
        return static_cast<deciweber_meter_ld>(val);
    }
    consteval centiweber_meter_ld operator""_cWb_m(long double val) {
        return static_cast<centiweber_meter_ld>(val);
    }
    consteval milliweber_meter_ld operator""_mWb_m(long double val) {
        return static_cast<milliweber_meter_ld>(val);
    }
    consteval microweber_meter_ld operator""_uWb_m(long double val) {
        return static_cast<microweber_meter_ld>(val);
    }
    consteval nanoweber_meter_ld operator""_nWb_m(long double val) {
        return static_cast<nanoweber_meter_ld>(val);
    }
    consteval picoweber_meter_ld operator""_pWb_m(long double val) {
        return static_cast<picoweber_meter_ld>(val);
    }
    consteval femtoweber_meter_ld operator""_fWb_m(long double val) {
        return static_cast<femtoweber_meter_ld>(val);
    }
    consteval attoweber_meter_ld operator""_aWb_m(long double val) {
        return static_cast<attoweber_meter_ld>(val);
    }
    consteval exaweber_meter_ull operator""_EWb_m(unsigned long long val) {
        return static_cast<exaweber_meter_ull>(val);
    }
    consteval petaweber_meter_ull operator""_PWb_m(unsigned long long val) {
        return static_cast<petaweber_meter_ull>(val);
    }
    consteval teraweber_meter_ull operator""_TWb_m(unsigned long long val) {
        return static_cast<teraweber_meter_ull>(val);
    }
    consteval gigaweber_meter_ull operator""_GWb_m(unsigned long long val) {
        return static_cast<gigaweber_meter_ull>(val);
    }
    consteval megaweber_meter_ull operator""_MWb_m(unsigned long long val) {
        return static_cast<megaweber_meter_ull>(val);
    }
    consteval kiloweber_meter_ull operator""_kWb_m(unsigned long long val) {
        return static_cast<kiloweber_meter_ull>(val);
    }
    consteval hectoweber_meter_ull operator""_hWb_m(unsigned long long val) {
        return static_cast<hectoweber_meter_ull>(val);
    }
    consteval decaweber_meter_ull operator""_daWb_m(unsigned long long val) {
        return static_cast<decaweber_meter_ull>(val);
    }
    consteval weber_meter_ull operator""_Wb_m(unsigned long long val) {
        return static_cast<weber_meter_ull>(val);
    }
    consteval deciweber_meter_ull operator""_dWb_m(unsigned long long val) {
        return static_cast<deciweber_meter_ull>(val);
    }
    consteval centiweber_meter_ull operator""_cWb_m(unsigned long long val) {
        return static_cast<centiweber_meter_ull>(val);
    }
    consteval milliweber_meter_ull operator""_mWb_m(unsigned long long val) {
        return static_cast<milliweber_meter_ull>(val);
    }
    consteval microweber_meter_ull operator""_uWb_m(unsigned long long val) {
        return static_cast<microweber_meter_ull>(val);
    }
    consteval nanoweber_meter_ull operator""_nWb_m(unsigned long long val) {
        return static_cast<nanoweber_meter_ull>(val);
    }
    consteval picoweber_meter_ull operator""_pWb_m(unsigned long long val) {
        return static_cast<picoweber_meter_ull>(val);
    }
    consteval femtoweber_meter_ull operator""_fWb_m(unsigned long long val) {
        return static_cast<femtoweber_meter_ull>(val);
    }
    consteval attoweber_meter_ull operator""_aWb_m(unsigned long long val) {
        return static_cast<attoweber_meter_ull>(val);
    }

} // namespace potato::units
