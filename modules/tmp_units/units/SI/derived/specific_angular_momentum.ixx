//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Newton_Meter_Second_Per_Kilogram;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using specific_angular_momentum_tag_t = tmp::list_<Length<std::ratio<2, 1>>,
                                         Time<std::ratio<-1, 1>>,
                                         Mass<std::ratio<0, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept Newton_Meter_Second_Per_KilogramC = std::same_as<typename T::impl, specific_angular_momentum_tag_t>;

    template <typename RatioTypeT, typename P>
    struct newton_meter_second_per_kilogram_impl {

        static constexpr auto pretty = "N·m·s/kg";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = specific_angular_momentum_tag_t;

        constexpr newton_meter_second_per_kilogram_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exanewton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<std::exa, long double>;
    using petanewton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<std::peta, long double>;
    using teranewton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<std::tera, long double>;
    using giganewton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<std::giga, long double>;
    using meganewton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<std::mega, long double>;
    using kilonewton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<std::kilo, long double>;
    using hectonewton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<std::hecto, long double>;
    using decanewton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<std::deca, long double>;
    using newton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<unity_ratio, long double>;
    using decinewton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<std::deci, long double>;
    using centinewton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<std::centi, long double>;
    using millinewton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<std::milli, long double>;
    using micronewton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<std::micro, long double>;
    using nanonewton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<std::nano, long double>;
    using piconewton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<std::pico, long double>;
    using femtonewton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<std::femto, long double>;
    using attonewton_meter_second_per_kilogram_ld    =     newton_meter_second_per_kilogram_impl<std::atto, long double>;
    using exanewton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<std::exa, unsigned long long>;
    using petanewton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<std::peta, unsigned long long>;
    using teranewton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<std::tera, unsigned long long>;
    using giganewton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<std::giga, unsigned long long>;
    using meganewton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<std::mega, unsigned long long>;
    using kilonewton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<std::kilo, unsigned long long>;
    using hectonewton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<std::hecto, unsigned long long>;
    using decanewton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<std::deca, unsigned long long>;
    using newton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<unity_ratio, unsigned long long>;
    using decinewton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<std::deci, unsigned long long>;
    using centinewton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<std::centi, unsigned long long>;
    using millinewton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<std::milli, unsigned long long>;
    using micronewton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<std::micro, unsigned long long>;
    using nanonewton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<std::nano, unsigned long long>;
    using piconewton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<std::pico, unsigned long long>;
    using femtonewton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<std::femto, unsigned long long>;
    using attonewton_meter_second_per_kilogram_ull    =     newton_meter_second_per_kilogram_impl<std::atto, unsigned long long>;

    consteval exanewton_meter_second_per_kilogram_ld operator""_EN_m_s_per_kg(long double val) {
        return static_cast<exanewton_meter_second_per_kilogram_ld>(val);
    }
    consteval petanewton_meter_second_per_kilogram_ld operator""_PN_m_s_per_kg(long double val) {
        return static_cast<petanewton_meter_second_per_kilogram_ld>(val);
    }
    consteval teranewton_meter_second_per_kilogram_ld operator""_TN_m_s_per_kg(long double val) {
        return static_cast<teranewton_meter_second_per_kilogram_ld>(val);
    }
    consteval giganewton_meter_second_per_kilogram_ld operator""_GN_m_s_per_kg(long double val) {
        return static_cast<giganewton_meter_second_per_kilogram_ld>(val);
    }
    consteval meganewton_meter_second_per_kilogram_ld operator""_MN_m_s_per_kg(long double val) {
        return static_cast<meganewton_meter_second_per_kilogram_ld>(val);
    }
    consteval kilonewton_meter_second_per_kilogram_ld operator""_kN_m_s_per_kg(long double val) {
        return static_cast<kilonewton_meter_second_per_kilogram_ld>(val);
    }
    consteval hectonewton_meter_second_per_kilogram_ld operator""_hN_m_s_per_kg(long double val) {
        return static_cast<hectonewton_meter_second_per_kilogram_ld>(val);
    }
    consteval decanewton_meter_second_per_kilogram_ld operator""_daN_m_s_per_kg(long double val) {
        return static_cast<decanewton_meter_second_per_kilogram_ld>(val);
    }
    consteval newton_meter_second_per_kilogram_ld operator""_N_m_s_per_kg(long double val) {
        return static_cast<newton_meter_second_per_kilogram_ld>(val);
    }
    consteval decinewton_meter_second_per_kilogram_ld operator""_dN_m_s_per_kg(long double val) {
        return static_cast<decinewton_meter_second_per_kilogram_ld>(val);
    }
    consteval centinewton_meter_second_per_kilogram_ld operator""_cN_m_s_per_kg(long double val) {
        return static_cast<centinewton_meter_second_per_kilogram_ld>(val);
    }
    consteval millinewton_meter_second_per_kilogram_ld operator""_mN_m_s_per_kg(long double val) {
        return static_cast<millinewton_meter_second_per_kilogram_ld>(val);
    }
    consteval micronewton_meter_second_per_kilogram_ld operator""_uN_m_s_per_kg(long double val) {
        return static_cast<micronewton_meter_second_per_kilogram_ld>(val);
    }
    consteval nanonewton_meter_second_per_kilogram_ld operator""_nN_m_s_per_kg(long double val) {
        return static_cast<nanonewton_meter_second_per_kilogram_ld>(val);
    }
    consteval piconewton_meter_second_per_kilogram_ld operator""_pN_m_s_per_kg(long double val) {
        return static_cast<piconewton_meter_second_per_kilogram_ld>(val);
    }
    consteval femtonewton_meter_second_per_kilogram_ld operator""_fN_m_s_per_kg(long double val) {
        return static_cast<femtonewton_meter_second_per_kilogram_ld>(val);
    }
    consteval attonewton_meter_second_per_kilogram_ld operator""_aN_m_s_per_kg(long double val) {
        return static_cast<attonewton_meter_second_per_kilogram_ld>(val);
    }
    consteval exanewton_meter_second_per_kilogram_ull operator""_EN_m_s_per_kg(unsigned long long val) {
        return static_cast<exanewton_meter_second_per_kilogram_ull>(val);
    }
    consteval petanewton_meter_second_per_kilogram_ull operator""_PN_m_s_per_kg(unsigned long long val) {
        return static_cast<petanewton_meter_second_per_kilogram_ull>(val);
    }
    consteval teranewton_meter_second_per_kilogram_ull operator""_TN_m_s_per_kg(unsigned long long val) {
        return static_cast<teranewton_meter_second_per_kilogram_ull>(val);
    }
    consteval giganewton_meter_second_per_kilogram_ull operator""_GN_m_s_per_kg(unsigned long long val) {
        return static_cast<giganewton_meter_second_per_kilogram_ull>(val);
    }
    consteval meganewton_meter_second_per_kilogram_ull operator""_MN_m_s_per_kg(unsigned long long val) {
        return static_cast<meganewton_meter_second_per_kilogram_ull>(val);
    }
    consteval kilonewton_meter_second_per_kilogram_ull operator""_kN_m_s_per_kg(unsigned long long val) {
        return static_cast<kilonewton_meter_second_per_kilogram_ull>(val);
    }
    consteval hectonewton_meter_second_per_kilogram_ull operator""_hN_m_s_per_kg(unsigned long long val) {
        return static_cast<hectonewton_meter_second_per_kilogram_ull>(val);
    }
    consteval decanewton_meter_second_per_kilogram_ull operator""_daN_m_s_per_kg(unsigned long long val) {
        return static_cast<decanewton_meter_second_per_kilogram_ull>(val);
    }
    consteval newton_meter_second_per_kilogram_ull operator""_N_m_s_per_kg(unsigned long long val) {
        return static_cast<newton_meter_second_per_kilogram_ull>(val);
    }
    consteval decinewton_meter_second_per_kilogram_ull operator""_dN_m_s_per_kg(unsigned long long val) {
        return static_cast<decinewton_meter_second_per_kilogram_ull>(val);
    }
    consteval centinewton_meter_second_per_kilogram_ull operator""_cN_m_s_per_kg(unsigned long long val) {
        return static_cast<centinewton_meter_second_per_kilogram_ull>(val);
    }
    consteval millinewton_meter_second_per_kilogram_ull operator""_mN_m_s_per_kg(unsigned long long val) {
        return static_cast<millinewton_meter_second_per_kilogram_ull>(val);
    }
    consteval micronewton_meter_second_per_kilogram_ull operator""_uN_m_s_per_kg(unsigned long long val) {
        return static_cast<micronewton_meter_second_per_kilogram_ull>(val);
    }
    consteval nanonewton_meter_second_per_kilogram_ull operator""_nN_m_s_per_kg(unsigned long long val) {
        return static_cast<nanonewton_meter_second_per_kilogram_ull>(val);
    }
    consteval piconewton_meter_second_per_kilogram_ull operator""_pN_m_s_per_kg(unsigned long long val) {
        return static_cast<piconewton_meter_second_per_kilogram_ull>(val);
    }
    consteval femtonewton_meter_second_per_kilogram_ull operator""_fN_m_s_per_kg(unsigned long long val) {
        return static_cast<femtonewton_meter_second_per_kilogram_ull>(val);
    }
    consteval attonewton_meter_second_per_kilogram_ull operator""_aN_m_s_per_kg(unsigned long long val) {
        return static_cast<attonewton_meter_second_per_kilogram_ull>(val);
    }

} // namespace potato::units
