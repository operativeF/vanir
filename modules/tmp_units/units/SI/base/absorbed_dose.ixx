//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Gray;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using absorbed_dose_tag_t = tmp::list_<Length<std::ratio<2, 1>>,
                                         Time<std::ratio<-2, 1>>,
                                         Mass<std::ratio<0, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept GrayC = std::same_as<typename T::impl, absorbed_dose_tag_t>;

    template <typename RatioTypeT, typename P>
    struct gray_impl {

        static constexpr auto pretty = "Gy";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = absorbed_dose_tag_t;

        constexpr gray_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exagray_ld    =     gray_impl<std::exa, long double>;
    using petagray_ld    =     gray_impl<std::peta, long double>;
    using teragray_ld    =     gray_impl<std::tera, long double>;
    using gigagray_ld    =     gray_impl<std::giga, long double>;
    using megagray_ld    =     gray_impl<std::mega, long double>;
    using kilogray_ld    =     gray_impl<std::kilo, long double>;
    using hectogray_ld    =     gray_impl<std::hecto, long double>;
    using decagray_ld    =     gray_impl<std::deca, long double>;
    using gray_ld    =     gray_impl<unity_ratio, long double>;
    using decigray_ld    =     gray_impl<std::deci, long double>;
    using centigray_ld    =     gray_impl<std::centi, long double>;
    using milligray_ld    =     gray_impl<std::milli, long double>;
    using microgray_ld    =     gray_impl<std::micro, long double>;
    using nanogray_ld    =     gray_impl<std::nano, long double>;
    using picogray_ld    =     gray_impl<std::pico, long double>;
    using femtogray_ld    =     gray_impl<std::femto, long double>;
    using attogray_ld    =     gray_impl<std::atto, long double>;
    using exagray_ull    =     gray_impl<std::exa, unsigned long long>;
    using petagray_ull    =     gray_impl<std::peta, unsigned long long>;
    using teragray_ull    =     gray_impl<std::tera, unsigned long long>;
    using gigagray_ull    =     gray_impl<std::giga, unsigned long long>;
    using megagray_ull    =     gray_impl<std::mega, unsigned long long>;
    using kilogray_ull    =     gray_impl<std::kilo, unsigned long long>;
    using hectogray_ull    =     gray_impl<std::hecto, unsigned long long>;
    using decagray_ull    =     gray_impl<std::deca, unsigned long long>;
    using gray_ull    =     gray_impl<unity_ratio, unsigned long long>;
    using decigray_ull    =     gray_impl<std::deci, unsigned long long>;
    using centigray_ull    =     gray_impl<std::centi, unsigned long long>;
    using milligray_ull    =     gray_impl<std::milli, unsigned long long>;
    using microgray_ull    =     gray_impl<std::micro, unsigned long long>;
    using nanogray_ull    =     gray_impl<std::nano, unsigned long long>;
    using picogray_ull    =     gray_impl<std::pico, unsigned long long>;
    using femtogray_ull    =     gray_impl<std::femto, unsigned long long>;
    using attogray_ull    =     gray_impl<std::atto, unsigned long long>;

    consteval exagray_ld operator""_EGy(long double val) {
        return static_cast<exagray_ld>(val);
    }
    consteval petagray_ld operator""_PGy(long double val) {
        return static_cast<petagray_ld>(val);
    }
    consteval teragray_ld operator""_TGy(long double val) {
        return static_cast<teragray_ld>(val);
    }
    consteval gigagray_ld operator""_GGy(long double val) {
        return static_cast<gigagray_ld>(val);
    }
    consteval megagray_ld operator""_MGy(long double val) {
        return static_cast<megagray_ld>(val);
    }
    consteval kilogray_ld operator""_kGy(long double val) {
        return static_cast<kilogray_ld>(val);
    }
    consteval hectogray_ld operator""_hGy(long double val) {
        return static_cast<hectogray_ld>(val);
    }
    consteval decagray_ld operator""_daGy(long double val) {
        return static_cast<decagray_ld>(val);
    }
    consteval gray_ld operator""_Gy(long double val) {
        return static_cast<gray_ld>(val);
    }
    consteval decigray_ld operator""_dGy(long double val) {
        return static_cast<decigray_ld>(val);
    }
    consteval centigray_ld operator""_cGy(long double val) {
        return static_cast<centigray_ld>(val);
    }
    consteval milligray_ld operator""_mGy(long double val) {
        return static_cast<milligray_ld>(val);
    }
    consteval microgray_ld operator""_uGy(long double val) {
        return static_cast<microgray_ld>(val);
    }
    consteval nanogray_ld operator""_nGy(long double val) {
        return static_cast<nanogray_ld>(val);
    }
    consteval picogray_ld operator""_pGy(long double val) {
        return static_cast<picogray_ld>(val);
    }
    consteval femtogray_ld operator""_fGy(long double val) {
        return static_cast<femtogray_ld>(val);
    }
    consteval attogray_ld operator""_aGy(long double val) {
        return static_cast<attogray_ld>(val);
    }
    consteval exagray_ull operator""_EGy(unsigned long long val) {
        return static_cast<exagray_ull>(val);
    }
    consteval petagray_ull operator""_PGy(unsigned long long val) {
        return static_cast<petagray_ull>(val);
    }
    consteval teragray_ull operator""_TGy(unsigned long long val) {
        return static_cast<teragray_ull>(val);
    }
    consteval gigagray_ull operator""_GGy(unsigned long long val) {
        return static_cast<gigagray_ull>(val);
    }
    consteval megagray_ull operator""_MGy(unsigned long long val) {
        return static_cast<megagray_ull>(val);
    }
    consteval kilogray_ull operator""_kGy(unsigned long long val) {
        return static_cast<kilogray_ull>(val);
    }
    consteval hectogray_ull operator""_hGy(unsigned long long val) {
        return static_cast<hectogray_ull>(val);
    }
    consteval decagray_ull operator""_daGy(unsigned long long val) {
        return static_cast<decagray_ull>(val);
    }
    consteval gray_ull operator""_Gy(unsigned long long val) {
        return static_cast<gray_ull>(val);
    }
    consteval decigray_ull operator""_dGy(unsigned long long val) {
        return static_cast<decigray_ull>(val);
    }
    consteval centigray_ull operator""_cGy(unsigned long long val) {
        return static_cast<centigray_ull>(val);
    }
    consteval milligray_ull operator""_mGy(unsigned long long val) {
        return static_cast<milligray_ull>(val);
    }
    consteval microgray_ull operator""_uGy(unsigned long long val) {
        return static_cast<microgray_ull>(val);
    }
    consteval nanogray_ull operator""_nGy(unsigned long long val) {
        return static_cast<nanogray_ull>(val);
    }
    consteval picogray_ull operator""_pGy(unsigned long long val) {
        return static_cast<picogray_ull>(val);
    }
    consteval femtogray_ull operator""_fGy(unsigned long long val) {
        return static_cast<femtogray_ull>(val);
    }
    consteval attogray_ull operator""_aGy(unsigned long long val) {
        return static_cast<attogray_ull>(val);
    }

} // namespace potato::units
