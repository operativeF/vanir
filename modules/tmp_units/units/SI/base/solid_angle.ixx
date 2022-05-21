//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Steradian;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using solid_angle_tag_t = tmp::list_<Length<std::ratio<0, 1>>,
                                         Time<std::ratio<0, 1>>,
                                         Mass<std::ratio<0, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<1, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept SteradianC = std::same_as<typename T::impl, solid_angle_tag_t>;

    template <typename RatioTypeT, typename P>
    struct steradian_impl {

        static constexpr auto pretty = "sr";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = solid_angle_tag_t;

        constexpr steradian_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exasteradian_ld    =     steradian_impl<std::exa, long double>;
    using petasteradian_ld    =     steradian_impl<std::peta, long double>;
    using terasteradian_ld    =     steradian_impl<std::tera, long double>;
    using gigasteradian_ld    =     steradian_impl<std::giga, long double>;
    using megasteradian_ld    =     steradian_impl<std::mega, long double>;
    using kilosteradian_ld    =     steradian_impl<std::kilo, long double>;
    using hectosteradian_ld    =     steradian_impl<std::hecto, long double>;
    using decasteradian_ld    =     steradian_impl<std::deca, long double>;
    using steradian_ld    =     steradian_impl<unity_ratio, long double>;
    using decisteradian_ld    =     steradian_impl<std::deci, long double>;
    using centisteradian_ld    =     steradian_impl<std::centi, long double>;
    using millisteradian_ld    =     steradian_impl<std::milli, long double>;
    using microsteradian_ld    =     steradian_impl<std::micro, long double>;
    using nanosteradian_ld    =     steradian_impl<std::nano, long double>;
    using picosteradian_ld    =     steradian_impl<std::pico, long double>;
    using femtosteradian_ld    =     steradian_impl<std::femto, long double>;
    using attosteradian_ld    =     steradian_impl<std::atto, long double>;
    using exasteradian_ull    =     steradian_impl<std::exa, unsigned long long>;
    using petasteradian_ull    =     steradian_impl<std::peta, unsigned long long>;
    using terasteradian_ull    =     steradian_impl<std::tera, unsigned long long>;
    using gigasteradian_ull    =     steradian_impl<std::giga, unsigned long long>;
    using megasteradian_ull    =     steradian_impl<std::mega, unsigned long long>;
    using kilosteradian_ull    =     steradian_impl<std::kilo, unsigned long long>;
    using hectosteradian_ull    =     steradian_impl<std::hecto, unsigned long long>;
    using decasteradian_ull    =     steradian_impl<std::deca, unsigned long long>;
    using steradian_ull    =     steradian_impl<unity_ratio, unsigned long long>;
    using decisteradian_ull    =     steradian_impl<std::deci, unsigned long long>;
    using centisteradian_ull    =     steradian_impl<std::centi, unsigned long long>;
    using millisteradian_ull    =     steradian_impl<std::milli, unsigned long long>;
    using microsteradian_ull    =     steradian_impl<std::micro, unsigned long long>;
    using nanosteradian_ull    =     steradian_impl<std::nano, unsigned long long>;
    using picosteradian_ull    =     steradian_impl<std::pico, unsigned long long>;
    using femtosteradian_ull    =     steradian_impl<std::femto, unsigned long long>;
    using attosteradian_ull    =     steradian_impl<std::atto, unsigned long long>;

    consteval exasteradian_ld operator""_Esr(long double val) {
        return static_cast<exasteradian_ld>(val);
    }
    consteval petasteradian_ld operator""_Psr(long double val) {
        return static_cast<petasteradian_ld>(val);
    }
    consteval terasteradian_ld operator""_Tsr(long double val) {
        return static_cast<terasteradian_ld>(val);
    }
    consteval gigasteradian_ld operator""_Gsr(long double val) {
        return static_cast<gigasteradian_ld>(val);
    }
    consteval megasteradian_ld operator""_Msr(long double val) {
        return static_cast<megasteradian_ld>(val);
    }
    consteval kilosteradian_ld operator""_ksr(long double val) {
        return static_cast<kilosteradian_ld>(val);
    }
    consteval hectosteradian_ld operator""_hsr(long double val) {
        return static_cast<hectosteradian_ld>(val);
    }
    consteval decasteradian_ld operator""_dasr(long double val) {
        return static_cast<decasteradian_ld>(val);
    }
    consteval steradian_ld operator""_sr(long double val) {
        return static_cast<steradian_ld>(val);
    }
    consteval decisteradian_ld operator""_dsr(long double val) {
        return static_cast<decisteradian_ld>(val);
    }
    consteval centisteradian_ld operator""_csr(long double val) {
        return static_cast<centisteradian_ld>(val);
    }
    consteval millisteradian_ld operator""_msr(long double val) {
        return static_cast<millisteradian_ld>(val);
    }
    consteval microsteradian_ld operator""_usr(long double val) {
        return static_cast<microsteradian_ld>(val);
    }
    consteval nanosteradian_ld operator""_nsr(long double val) {
        return static_cast<nanosteradian_ld>(val);
    }
    consteval picosteradian_ld operator""_psr(long double val) {
        return static_cast<picosteradian_ld>(val);
    }
    consteval femtosteradian_ld operator""_fsr(long double val) {
        return static_cast<femtosteradian_ld>(val);
    }
    consteval attosteradian_ld operator""_asr(long double val) {
        return static_cast<attosteradian_ld>(val);
    }
    consteval exasteradian_ull operator""_Esr(unsigned long long val) {
        return static_cast<exasteradian_ull>(val);
    }
    consteval petasteradian_ull operator""_Psr(unsigned long long val) {
        return static_cast<petasteradian_ull>(val);
    }
    consteval terasteradian_ull operator""_Tsr(unsigned long long val) {
        return static_cast<terasteradian_ull>(val);
    }
    consteval gigasteradian_ull operator""_Gsr(unsigned long long val) {
        return static_cast<gigasteradian_ull>(val);
    }
    consteval megasteradian_ull operator""_Msr(unsigned long long val) {
        return static_cast<megasteradian_ull>(val);
    }
    consteval kilosteradian_ull operator""_ksr(unsigned long long val) {
        return static_cast<kilosteradian_ull>(val);
    }
    consteval hectosteradian_ull operator""_hsr(unsigned long long val) {
        return static_cast<hectosteradian_ull>(val);
    }
    consteval decasteradian_ull operator""_dasr(unsigned long long val) {
        return static_cast<decasteradian_ull>(val);
    }
    consteval steradian_ull operator""_sr(unsigned long long val) {
        return static_cast<steradian_ull>(val);
    }
    consteval decisteradian_ull operator""_dsr(unsigned long long val) {
        return static_cast<decisteradian_ull>(val);
    }
    consteval centisteradian_ull operator""_csr(unsigned long long val) {
        return static_cast<centisteradian_ull>(val);
    }
    consteval millisteradian_ull operator""_msr(unsigned long long val) {
        return static_cast<millisteradian_ull>(val);
    }
    consteval microsteradian_ull operator""_usr(unsigned long long val) {
        return static_cast<microsteradian_ull>(val);
    }
    consteval nanosteradian_ull operator""_nsr(unsigned long long val) {
        return static_cast<nanosteradian_ull>(val);
    }
    consteval picosteradian_ull operator""_psr(unsigned long long val) {
        return static_cast<picosteradian_ull>(val);
    }
    consteval femtosteradian_ull operator""_fsr(unsigned long long val) {
        return static_cast<femtosteradian_ull>(val);
    }
    consteval attosteradian_ull operator""_asr(unsigned long long val) {
        return static_cast<attosteradian_ull>(val);
    }

} // namespace potato::units
