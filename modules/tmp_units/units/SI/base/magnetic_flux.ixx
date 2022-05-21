//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Weber;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using magnetic_flux_tag_t = tmp::list_<Length<std::ratio<2, 1>>,
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
    concept WeberC = std::same_as<typename T::impl, magnetic_flux_tag_t>;

    template <typename RatioTypeT, typename P>
    struct weber_impl {

        static constexpr auto pretty = "Wb";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = magnetic_flux_tag_t;

        constexpr weber_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exaweber_ld    =     weber_impl<std::exa, long double>;
    using petaweber_ld    =     weber_impl<std::peta, long double>;
    using teraweber_ld    =     weber_impl<std::tera, long double>;
    using gigaweber_ld    =     weber_impl<std::giga, long double>;
    using megaweber_ld    =     weber_impl<std::mega, long double>;
    using kiloweber_ld    =     weber_impl<std::kilo, long double>;
    using hectoweber_ld    =     weber_impl<std::hecto, long double>;
    using decaweber_ld    =     weber_impl<std::deca, long double>;
    using weber_ld    =     weber_impl<unity_ratio, long double>;
    using deciweber_ld    =     weber_impl<std::deci, long double>;
    using centiweber_ld    =     weber_impl<std::centi, long double>;
    using milliweber_ld    =     weber_impl<std::milli, long double>;
    using microweber_ld    =     weber_impl<std::micro, long double>;
    using nanoweber_ld    =     weber_impl<std::nano, long double>;
    using picoweber_ld    =     weber_impl<std::pico, long double>;
    using femtoweber_ld    =     weber_impl<std::femto, long double>;
    using attoweber_ld    =     weber_impl<std::atto, long double>;
    using exaweber_ull    =     weber_impl<std::exa, unsigned long long>;
    using petaweber_ull    =     weber_impl<std::peta, unsigned long long>;
    using teraweber_ull    =     weber_impl<std::tera, unsigned long long>;
    using gigaweber_ull    =     weber_impl<std::giga, unsigned long long>;
    using megaweber_ull    =     weber_impl<std::mega, unsigned long long>;
    using kiloweber_ull    =     weber_impl<std::kilo, unsigned long long>;
    using hectoweber_ull    =     weber_impl<std::hecto, unsigned long long>;
    using decaweber_ull    =     weber_impl<std::deca, unsigned long long>;
    using weber_ull    =     weber_impl<unity_ratio, unsigned long long>;
    using deciweber_ull    =     weber_impl<std::deci, unsigned long long>;
    using centiweber_ull    =     weber_impl<std::centi, unsigned long long>;
    using milliweber_ull    =     weber_impl<std::milli, unsigned long long>;
    using microweber_ull    =     weber_impl<std::micro, unsigned long long>;
    using nanoweber_ull    =     weber_impl<std::nano, unsigned long long>;
    using picoweber_ull    =     weber_impl<std::pico, unsigned long long>;
    using femtoweber_ull    =     weber_impl<std::femto, unsigned long long>;
    using attoweber_ull    =     weber_impl<std::atto, unsigned long long>;

    consteval exaweber_ld operator""_EWb(long double val) {
        return static_cast<exaweber_ld>(val);
    }
    consteval petaweber_ld operator""_PWb(long double val) {
        return static_cast<petaweber_ld>(val);
    }
    consteval teraweber_ld operator""_TWb(long double val) {
        return static_cast<teraweber_ld>(val);
    }
    consteval gigaweber_ld operator""_GWb(long double val) {
        return static_cast<gigaweber_ld>(val);
    }
    consteval megaweber_ld operator""_MWb(long double val) {
        return static_cast<megaweber_ld>(val);
    }
    consteval kiloweber_ld operator""_kWb(long double val) {
        return static_cast<kiloweber_ld>(val);
    }
    consteval hectoweber_ld operator""_hWb(long double val) {
        return static_cast<hectoweber_ld>(val);
    }
    consteval decaweber_ld operator""_daWb(long double val) {
        return static_cast<decaweber_ld>(val);
    }
    consteval weber_ld operator""_Wb(long double val) {
        return static_cast<weber_ld>(val);
    }
    consteval deciweber_ld operator""_dWb(long double val) {
        return static_cast<deciweber_ld>(val);
    }
    consteval centiweber_ld operator""_cWb(long double val) {
        return static_cast<centiweber_ld>(val);
    }
    consteval milliweber_ld operator""_mWb(long double val) {
        return static_cast<milliweber_ld>(val);
    }
    consteval microweber_ld operator""_uWb(long double val) {
        return static_cast<microweber_ld>(val);
    }
    consteval nanoweber_ld operator""_nWb(long double val) {
        return static_cast<nanoweber_ld>(val);
    }
    consteval picoweber_ld operator""_pWb(long double val) {
        return static_cast<picoweber_ld>(val);
    }
    consteval femtoweber_ld operator""_fWb(long double val) {
        return static_cast<femtoweber_ld>(val);
    }
    consteval attoweber_ld operator""_aWb(long double val) {
        return static_cast<attoweber_ld>(val);
    }
    consteval exaweber_ull operator""_EWb(unsigned long long val) {
        return static_cast<exaweber_ull>(val);
    }
    consteval petaweber_ull operator""_PWb(unsigned long long val) {
        return static_cast<petaweber_ull>(val);
    }
    consteval teraweber_ull operator""_TWb(unsigned long long val) {
        return static_cast<teraweber_ull>(val);
    }
    consteval gigaweber_ull operator""_GWb(unsigned long long val) {
        return static_cast<gigaweber_ull>(val);
    }
    consteval megaweber_ull operator""_MWb(unsigned long long val) {
        return static_cast<megaweber_ull>(val);
    }
    consteval kiloweber_ull operator""_kWb(unsigned long long val) {
        return static_cast<kiloweber_ull>(val);
    }
    consteval hectoweber_ull operator""_hWb(unsigned long long val) {
        return static_cast<hectoweber_ull>(val);
    }
    consteval decaweber_ull operator""_daWb(unsigned long long val) {
        return static_cast<decaweber_ull>(val);
    }
    consteval weber_ull operator""_Wb(unsigned long long val) {
        return static_cast<weber_ull>(val);
    }
    consteval deciweber_ull operator""_dWb(unsigned long long val) {
        return static_cast<deciweber_ull>(val);
    }
    consteval centiweber_ull operator""_cWb(unsigned long long val) {
        return static_cast<centiweber_ull>(val);
    }
    consteval milliweber_ull operator""_mWb(unsigned long long val) {
        return static_cast<milliweber_ull>(val);
    }
    consteval microweber_ull operator""_uWb(unsigned long long val) {
        return static_cast<microweber_ull>(val);
    }
    consteval nanoweber_ull operator""_nWb(unsigned long long val) {
        return static_cast<nanoweber_ull>(val);
    }
    consteval picoweber_ull operator""_pWb(unsigned long long val) {
        return static_cast<picoweber_ull>(val);
    }
    consteval femtoweber_ull operator""_fWb(unsigned long long val) {
        return static_cast<femtoweber_ull>(val);
    }
    consteval attoweber_ull operator""_aWb(unsigned long long val) {
        return static_cast<attoweber_ull>(val);
    }

} // namespace potato::units
