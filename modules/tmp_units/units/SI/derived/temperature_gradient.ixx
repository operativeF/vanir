//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Kelvin_Per_Watt;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using temperature_gradient_tag_t = tmp::list_<Length<std::ratio<-2, 1>>,
                                         Time<std::ratio<3, 1>>,
                                         Mass<std::ratio<-1, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<1, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept Kelvin_Per_WattC = std::same_as<typename T::impl, temperature_gradient_tag_t>;

    template <typename RatioTypeT, typename P>
    struct kelvin_per_watt_impl {

        static constexpr auto pretty = "K/W";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = temperature_gradient_tag_t;

        constexpr kelvin_per_watt_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exakelvin_per_watt_ld    =     kelvin_per_watt_impl<std::exa, long double>;
    using petakelvin_per_watt_ld    =     kelvin_per_watt_impl<std::peta, long double>;
    using terakelvin_per_watt_ld    =     kelvin_per_watt_impl<std::tera, long double>;
    using gigakelvin_per_watt_ld    =     kelvin_per_watt_impl<std::giga, long double>;
    using megakelvin_per_watt_ld    =     kelvin_per_watt_impl<std::mega, long double>;
    using kilokelvin_per_watt_ld    =     kelvin_per_watt_impl<std::kilo, long double>;
    using hectokelvin_per_watt_ld    =     kelvin_per_watt_impl<std::hecto, long double>;
    using decakelvin_per_watt_ld    =     kelvin_per_watt_impl<std::deca, long double>;
    using kelvin_per_watt_ld    =     kelvin_per_watt_impl<unity_ratio, long double>;
    using decikelvin_per_watt_ld    =     kelvin_per_watt_impl<std::deci, long double>;
    using centikelvin_per_watt_ld    =     kelvin_per_watt_impl<std::centi, long double>;
    using millikelvin_per_watt_ld    =     kelvin_per_watt_impl<std::milli, long double>;
    using microkelvin_per_watt_ld    =     kelvin_per_watt_impl<std::micro, long double>;
    using nanokelvin_per_watt_ld    =     kelvin_per_watt_impl<std::nano, long double>;
    using picokelvin_per_watt_ld    =     kelvin_per_watt_impl<std::pico, long double>;
    using femtokelvin_per_watt_ld    =     kelvin_per_watt_impl<std::femto, long double>;
    using attokelvin_per_watt_ld    =     kelvin_per_watt_impl<std::atto, long double>;
    using exakelvin_per_watt_ull    =     kelvin_per_watt_impl<std::exa, unsigned long long>;
    using petakelvin_per_watt_ull    =     kelvin_per_watt_impl<std::peta, unsigned long long>;
    using terakelvin_per_watt_ull    =     kelvin_per_watt_impl<std::tera, unsigned long long>;
    using gigakelvin_per_watt_ull    =     kelvin_per_watt_impl<std::giga, unsigned long long>;
    using megakelvin_per_watt_ull    =     kelvin_per_watt_impl<std::mega, unsigned long long>;
    using kilokelvin_per_watt_ull    =     kelvin_per_watt_impl<std::kilo, unsigned long long>;
    using hectokelvin_per_watt_ull    =     kelvin_per_watt_impl<std::hecto, unsigned long long>;
    using decakelvin_per_watt_ull    =     kelvin_per_watt_impl<std::deca, unsigned long long>;
    using kelvin_per_watt_ull    =     kelvin_per_watt_impl<unity_ratio, unsigned long long>;
    using decikelvin_per_watt_ull    =     kelvin_per_watt_impl<std::deci, unsigned long long>;
    using centikelvin_per_watt_ull    =     kelvin_per_watt_impl<std::centi, unsigned long long>;
    using millikelvin_per_watt_ull    =     kelvin_per_watt_impl<std::milli, unsigned long long>;
    using microkelvin_per_watt_ull    =     kelvin_per_watt_impl<std::micro, unsigned long long>;
    using nanokelvin_per_watt_ull    =     kelvin_per_watt_impl<std::nano, unsigned long long>;
    using picokelvin_per_watt_ull    =     kelvin_per_watt_impl<std::pico, unsigned long long>;
    using femtokelvin_per_watt_ull    =     kelvin_per_watt_impl<std::femto, unsigned long long>;
    using attokelvin_per_watt_ull    =     kelvin_per_watt_impl<std::atto, unsigned long long>;

    constexpr exakelvin_per_watt_ld operator""_EK_per_W(long double val) {
        return static_cast<exakelvin_per_watt_ld>(val);
    }
    constexpr petakelvin_per_watt_ld operator""_PK_per_W(long double val) {
        return static_cast<petakelvin_per_watt_ld>(val);
    }
    constexpr terakelvin_per_watt_ld operator""_TK_per_W(long double val) {
        return static_cast<terakelvin_per_watt_ld>(val);
    }
    constexpr gigakelvin_per_watt_ld operator""_GK_per_W(long double val) {
        return static_cast<gigakelvin_per_watt_ld>(val);
    }
    constexpr megakelvin_per_watt_ld operator""_MK_per_W(long double val) {
        return static_cast<megakelvin_per_watt_ld>(val);
    }
    constexpr kilokelvin_per_watt_ld operator""_kK_per_W(long double val) {
        return static_cast<kilokelvin_per_watt_ld>(val);
    }
    constexpr hectokelvin_per_watt_ld operator""_hK_per_W(long double val) {
        return static_cast<hectokelvin_per_watt_ld>(val);
    }
    constexpr decakelvin_per_watt_ld operator""_daK_per_W(long double val) {
        return static_cast<decakelvin_per_watt_ld>(val);
    }
    constexpr kelvin_per_watt_ld operator""_K_per_W(long double val) {
        return static_cast<kelvin_per_watt_ld>(val);
    }
    constexpr decikelvin_per_watt_ld operator""_dK_per_W(long double val) {
        return static_cast<decikelvin_per_watt_ld>(val);
    }
    constexpr centikelvin_per_watt_ld operator""_cK_per_W(long double val) {
        return static_cast<centikelvin_per_watt_ld>(val);
    }
    constexpr millikelvin_per_watt_ld operator""_mK_per_W(long double val) {
        return static_cast<millikelvin_per_watt_ld>(val);
    }
    constexpr microkelvin_per_watt_ld operator""_uK_per_W(long double val) {
        return static_cast<microkelvin_per_watt_ld>(val);
    }
    constexpr nanokelvin_per_watt_ld operator""_nK_per_W(long double val) {
        return static_cast<nanokelvin_per_watt_ld>(val);
    }
    constexpr picokelvin_per_watt_ld operator""_pK_per_W(long double val) {
        return static_cast<picokelvin_per_watt_ld>(val);
    }
    constexpr femtokelvin_per_watt_ld operator""_fK_per_W(long double val) {
        return static_cast<femtokelvin_per_watt_ld>(val);
    }
    constexpr attokelvin_per_watt_ld operator""_aK_per_W(long double val) {
        return static_cast<attokelvin_per_watt_ld>(val);
    }
    constexpr exakelvin_per_watt_ull operator""_EK_per_W(unsigned long long val) {
        return static_cast<exakelvin_per_watt_ull>(val);
    }
    constexpr petakelvin_per_watt_ull operator""_PK_per_W(unsigned long long val) {
        return static_cast<petakelvin_per_watt_ull>(val);
    }
    constexpr terakelvin_per_watt_ull operator""_TK_per_W(unsigned long long val) {
        return static_cast<terakelvin_per_watt_ull>(val);
    }
    constexpr gigakelvin_per_watt_ull operator""_GK_per_W(unsigned long long val) {
        return static_cast<gigakelvin_per_watt_ull>(val);
    }
    constexpr megakelvin_per_watt_ull operator""_MK_per_W(unsigned long long val) {
        return static_cast<megakelvin_per_watt_ull>(val);
    }
    constexpr kilokelvin_per_watt_ull operator""_kK_per_W(unsigned long long val) {
        return static_cast<kilokelvin_per_watt_ull>(val);
    }
    constexpr hectokelvin_per_watt_ull operator""_hK_per_W(unsigned long long val) {
        return static_cast<hectokelvin_per_watt_ull>(val);
    }
    constexpr decakelvin_per_watt_ull operator""_daK_per_W(unsigned long long val) {
        return static_cast<decakelvin_per_watt_ull>(val);
    }
    constexpr kelvin_per_watt_ull operator""_K_per_W(unsigned long long val) {
        return static_cast<kelvin_per_watt_ull>(val);
    }
    constexpr decikelvin_per_watt_ull operator""_dK_per_W(unsigned long long val) {
        return static_cast<decikelvin_per_watt_ull>(val);
    }
    constexpr centikelvin_per_watt_ull operator""_cK_per_W(unsigned long long val) {
        return static_cast<centikelvin_per_watt_ull>(val);
    }
    constexpr millikelvin_per_watt_ull operator""_mK_per_W(unsigned long long val) {
        return static_cast<millikelvin_per_watt_ull>(val);
    }
    constexpr microkelvin_per_watt_ull operator""_uK_per_W(unsigned long long val) {
        return static_cast<microkelvin_per_watt_ull>(val);
    }
    constexpr nanokelvin_per_watt_ull operator""_nK_per_W(unsigned long long val) {
        return static_cast<nanokelvin_per_watt_ull>(val);
    }
    constexpr picokelvin_per_watt_ull operator""_pK_per_W(unsigned long long val) {
        return static_cast<picokelvin_per_watt_ull>(val);
    }
    constexpr femtokelvin_per_watt_ull operator""_fK_per_W(unsigned long long val) {
        return static_cast<femtokelvin_per_watt_ull>(val);
    }
    constexpr attokelvin_per_watt_ull operator""_aK_per_W(unsigned long long val) {
        return static_cast<attokelvin_per_watt_ull>(val);
    }

} // namespace potato::units
