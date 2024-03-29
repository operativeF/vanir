//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Gray_Per_Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using absorbed_dose_rate_tag_t = tmp::list_<Length<std::ratio<2, 1>>,
                                         Time<std::ratio<-3, 1>>,
                                         Mass<std::ratio<0, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept Gray_Per_SecondC = std::same_as<typename T::impl, absorbed_dose_rate_tag_t>;

    template <typename RatioTypeT, typename P>
    struct gray_per_second_impl {

        static constexpr auto pretty = "Gy/s";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = absorbed_dose_rate_tag_t;

        constexpr gray_per_second_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exagray_per_second_ld    =     gray_per_second_impl<std::exa, long double>;
    using petagray_per_second_ld    =     gray_per_second_impl<std::peta, long double>;
    using teragray_per_second_ld    =     gray_per_second_impl<std::tera, long double>;
    using gigagray_per_second_ld    =     gray_per_second_impl<std::giga, long double>;
    using megagray_per_second_ld    =     gray_per_second_impl<std::mega, long double>;
    using kilogray_per_second_ld    =     gray_per_second_impl<std::kilo, long double>;
    using hectogray_per_second_ld    =     gray_per_second_impl<std::hecto, long double>;
    using decagray_per_second_ld    =     gray_per_second_impl<std::deca, long double>;
    using gray_per_second_ld    =     gray_per_second_impl<unity_ratio, long double>;
    using decigray_per_second_ld    =     gray_per_second_impl<std::deci, long double>;
    using centigray_per_second_ld    =     gray_per_second_impl<std::centi, long double>;
    using milligray_per_second_ld    =     gray_per_second_impl<std::milli, long double>;
    using microgray_per_second_ld    =     gray_per_second_impl<std::micro, long double>;
    using nanogray_per_second_ld    =     gray_per_second_impl<std::nano, long double>;
    using picogray_per_second_ld    =     gray_per_second_impl<std::pico, long double>;
    using femtogray_per_second_ld    =     gray_per_second_impl<std::femto, long double>;
    using attogray_per_second_ld    =     gray_per_second_impl<std::atto, long double>;
    using exagray_per_second_ull    =     gray_per_second_impl<std::exa, unsigned long long>;
    using petagray_per_second_ull    =     gray_per_second_impl<std::peta, unsigned long long>;
    using teragray_per_second_ull    =     gray_per_second_impl<std::tera, unsigned long long>;
    using gigagray_per_second_ull    =     gray_per_second_impl<std::giga, unsigned long long>;
    using megagray_per_second_ull    =     gray_per_second_impl<std::mega, unsigned long long>;
    using kilogray_per_second_ull    =     gray_per_second_impl<std::kilo, unsigned long long>;
    using hectogray_per_second_ull    =     gray_per_second_impl<std::hecto, unsigned long long>;
    using decagray_per_second_ull    =     gray_per_second_impl<std::deca, unsigned long long>;
    using gray_per_second_ull    =     gray_per_second_impl<unity_ratio, unsigned long long>;
    using decigray_per_second_ull    =     gray_per_second_impl<std::deci, unsigned long long>;
    using centigray_per_second_ull    =     gray_per_second_impl<std::centi, unsigned long long>;
    using milligray_per_second_ull    =     gray_per_second_impl<std::milli, unsigned long long>;
    using microgray_per_second_ull    =     gray_per_second_impl<std::micro, unsigned long long>;
    using nanogray_per_second_ull    =     gray_per_second_impl<std::nano, unsigned long long>;
    using picogray_per_second_ull    =     gray_per_second_impl<std::pico, unsigned long long>;
    using femtogray_per_second_ull    =     gray_per_second_impl<std::femto, unsigned long long>;
    using attogray_per_second_ull    =     gray_per_second_impl<std::atto, unsigned long long>;

    consteval exagray_per_second_ld operator""_EGy_per_s(long double val) {
        return static_cast<exagray_per_second_ld>(val);
    }
    consteval petagray_per_second_ld operator""_PGy_per_s(long double val) {
        return static_cast<petagray_per_second_ld>(val);
    }
    consteval teragray_per_second_ld operator""_TGy_per_s(long double val) {
        return static_cast<teragray_per_second_ld>(val);
    }
    consteval gigagray_per_second_ld operator""_GGy_per_s(long double val) {
        return static_cast<gigagray_per_second_ld>(val);
    }
    consteval megagray_per_second_ld operator""_MGy_per_s(long double val) {
        return static_cast<megagray_per_second_ld>(val);
    }
    consteval kilogray_per_second_ld operator""_kGy_per_s(long double val) {
        return static_cast<kilogray_per_second_ld>(val);
    }
    consteval hectogray_per_second_ld operator""_hGy_per_s(long double val) {
        return static_cast<hectogray_per_second_ld>(val);
    }
    consteval decagray_per_second_ld operator""_daGy_per_s(long double val) {
        return static_cast<decagray_per_second_ld>(val);
    }
    consteval gray_per_second_ld operator""_Gy_per_s(long double val) {
        return static_cast<gray_per_second_ld>(val);
    }
    consteval decigray_per_second_ld operator""_dGy_per_s(long double val) {
        return static_cast<decigray_per_second_ld>(val);
    }
    consteval centigray_per_second_ld operator""_cGy_per_s(long double val) {
        return static_cast<centigray_per_second_ld>(val);
    }
    consteval milligray_per_second_ld operator""_mGy_per_s(long double val) {
        return static_cast<milligray_per_second_ld>(val);
    }
    consteval microgray_per_second_ld operator""_uGy_per_s(long double val) {
        return static_cast<microgray_per_second_ld>(val);
    }
    consteval nanogray_per_second_ld operator""_nGy_per_s(long double val) {
        return static_cast<nanogray_per_second_ld>(val);
    }
    consteval picogray_per_second_ld operator""_pGy_per_s(long double val) {
        return static_cast<picogray_per_second_ld>(val);
    }
    consteval femtogray_per_second_ld operator""_fGy_per_s(long double val) {
        return static_cast<femtogray_per_second_ld>(val);
    }
    consteval attogray_per_second_ld operator""_aGy_per_s(long double val) {
        return static_cast<attogray_per_second_ld>(val);
    }
    consteval exagray_per_second_ull operator""_EGy_per_s(unsigned long long val) {
        return static_cast<exagray_per_second_ull>(val);
    }
    consteval petagray_per_second_ull operator""_PGy_per_s(unsigned long long val) {
        return static_cast<petagray_per_second_ull>(val);
    }
    consteval teragray_per_second_ull operator""_TGy_per_s(unsigned long long val) {
        return static_cast<teragray_per_second_ull>(val);
    }
    consteval gigagray_per_second_ull operator""_GGy_per_s(unsigned long long val) {
        return static_cast<gigagray_per_second_ull>(val);
    }
    consteval megagray_per_second_ull operator""_MGy_per_s(unsigned long long val) {
        return static_cast<megagray_per_second_ull>(val);
    }
    consteval kilogray_per_second_ull operator""_kGy_per_s(unsigned long long val) {
        return static_cast<kilogray_per_second_ull>(val);
    }
    consteval hectogray_per_second_ull operator""_hGy_per_s(unsigned long long val) {
        return static_cast<hectogray_per_second_ull>(val);
    }
    consteval decagray_per_second_ull operator""_daGy_per_s(unsigned long long val) {
        return static_cast<decagray_per_second_ull>(val);
    }
    consteval gray_per_second_ull operator""_Gy_per_s(unsigned long long val) {
        return static_cast<gray_per_second_ull>(val);
    }
    consteval decigray_per_second_ull operator""_dGy_per_s(unsigned long long val) {
        return static_cast<decigray_per_second_ull>(val);
    }
    consteval centigray_per_second_ull operator""_cGy_per_s(unsigned long long val) {
        return static_cast<centigray_per_second_ull>(val);
    }
    consteval milligray_per_second_ull operator""_mGy_per_s(unsigned long long val) {
        return static_cast<milligray_per_second_ull>(val);
    }
    consteval microgray_per_second_ull operator""_uGy_per_s(unsigned long long val) {
        return static_cast<microgray_per_second_ull>(val);
    }
    consteval nanogray_per_second_ull operator""_nGy_per_s(unsigned long long val) {
        return static_cast<nanogray_per_second_ull>(val);
    }
    consteval picogray_per_second_ull operator""_pGy_per_s(unsigned long long val) {
        return static_cast<picogray_per_second_ull>(val);
    }
    consteval femtogray_per_second_ull operator""_fGy_per_s(unsigned long long val) {
        return static_cast<femtogray_per_second_ull>(val);
    }
    consteval attogray_per_second_ull operator""_aGy_per_s(unsigned long long val) {
        return static_cast<attogray_per_second_ull>(val);
    }

} // namespace potato::units
