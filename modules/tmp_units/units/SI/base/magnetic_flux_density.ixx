//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Tesla;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using magnetic_flux_density_tag_t = tmp::list_<Length<std::ratio<0, 1>>,
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
    concept TeslaC = std::same_as<typename T::impl, magnetic_flux_density_tag_t>;

    template <typename RatioTypeT, typename P>
    struct tesla_impl {

        static constexpr auto pretty = "T";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = magnetic_flux_density_tag_t;

        constexpr tesla_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exatesla_ld    =     tesla_impl<std::exa, long double>;
    using petatesla_ld    =     tesla_impl<std::peta, long double>;
    using teratesla_ld    =     tesla_impl<std::tera, long double>;
    using gigatesla_ld    =     tesla_impl<std::giga, long double>;
    using megatesla_ld    =     tesla_impl<std::mega, long double>;
    using kilotesla_ld    =     tesla_impl<std::kilo, long double>;
    using hectotesla_ld    =     tesla_impl<std::hecto, long double>;
    using decatesla_ld    =     tesla_impl<std::deca, long double>;
    using tesla_ld    =     tesla_impl<unity_ratio, long double>;
    using decitesla_ld    =     tesla_impl<std::deci, long double>;
    using centitesla_ld    =     tesla_impl<std::centi, long double>;
    using millitesla_ld    =     tesla_impl<std::milli, long double>;
    using microtesla_ld    =     tesla_impl<std::micro, long double>;
    using nanotesla_ld    =     tesla_impl<std::nano, long double>;
    using picotesla_ld    =     tesla_impl<std::pico, long double>;
    using femtotesla_ld    =     tesla_impl<std::femto, long double>;
    using attotesla_ld    =     tesla_impl<std::atto, long double>;
    using exatesla_ull    =     tesla_impl<std::exa, unsigned long long>;
    using petatesla_ull    =     tesla_impl<std::peta, unsigned long long>;
    using teratesla_ull    =     tesla_impl<std::tera, unsigned long long>;
    using gigatesla_ull    =     tesla_impl<std::giga, unsigned long long>;
    using megatesla_ull    =     tesla_impl<std::mega, unsigned long long>;
    using kilotesla_ull    =     tesla_impl<std::kilo, unsigned long long>;
    using hectotesla_ull    =     tesla_impl<std::hecto, unsigned long long>;
    using decatesla_ull    =     tesla_impl<std::deca, unsigned long long>;
    using tesla_ull    =     tesla_impl<unity_ratio, unsigned long long>;
    using decitesla_ull    =     tesla_impl<std::deci, unsigned long long>;
    using centitesla_ull    =     tesla_impl<std::centi, unsigned long long>;
    using millitesla_ull    =     tesla_impl<std::milli, unsigned long long>;
    using microtesla_ull    =     tesla_impl<std::micro, unsigned long long>;
    using nanotesla_ull    =     tesla_impl<std::nano, unsigned long long>;
    using picotesla_ull    =     tesla_impl<std::pico, unsigned long long>;
    using femtotesla_ull    =     tesla_impl<std::femto, unsigned long long>;
    using attotesla_ull    =     tesla_impl<std::atto, unsigned long long>;

    consteval exatesla_ld operator""_ET(long double val) {
        return static_cast<exatesla_ld>(val);
    }
    consteval petatesla_ld operator""_PT(long double val) {
        return static_cast<petatesla_ld>(val);
    }
    consteval teratesla_ld operator""_TT(long double val) {
        return static_cast<teratesla_ld>(val);
    }
    consteval gigatesla_ld operator""_GT(long double val) {
        return static_cast<gigatesla_ld>(val);
    }
    consteval megatesla_ld operator""_MT(long double val) {
        return static_cast<megatesla_ld>(val);
    }
    consteval kilotesla_ld operator""_kT(long double val) {
        return static_cast<kilotesla_ld>(val);
    }
    consteval hectotesla_ld operator""_hT(long double val) {
        return static_cast<hectotesla_ld>(val);
    }
    consteval decatesla_ld operator""_daT(long double val) {
        return static_cast<decatesla_ld>(val);
    }
    consteval tesla_ld operator""_T(long double val) {
        return static_cast<tesla_ld>(val);
    }
    consteval decitesla_ld operator""_dT(long double val) {
        return static_cast<decitesla_ld>(val);
    }
    consteval centitesla_ld operator""_cT(long double val) {
        return static_cast<centitesla_ld>(val);
    }
    consteval millitesla_ld operator""_mT(long double val) {
        return static_cast<millitesla_ld>(val);
    }
    consteval microtesla_ld operator""_uT(long double val) {
        return static_cast<microtesla_ld>(val);
    }
    consteval nanotesla_ld operator""_nT(long double val) {
        return static_cast<nanotesla_ld>(val);
    }
    consteval picotesla_ld operator""_pT(long double val) {
        return static_cast<picotesla_ld>(val);
    }
    consteval femtotesla_ld operator""_fT(long double val) {
        return static_cast<femtotesla_ld>(val);
    }
    consteval attotesla_ld operator""_aT(long double val) {
        return static_cast<attotesla_ld>(val);
    }
    consteval exatesla_ull operator""_ET(unsigned long long val) {
        return static_cast<exatesla_ull>(val);
    }
    consteval petatesla_ull operator""_PT(unsigned long long val) {
        return static_cast<petatesla_ull>(val);
    }
    consteval teratesla_ull operator""_TT(unsigned long long val) {
        return static_cast<teratesla_ull>(val);
    }
    consteval gigatesla_ull operator""_GT(unsigned long long val) {
        return static_cast<gigatesla_ull>(val);
    }
    consteval megatesla_ull operator""_MT(unsigned long long val) {
        return static_cast<megatesla_ull>(val);
    }
    consteval kilotesla_ull operator""_kT(unsigned long long val) {
        return static_cast<kilotesla_ull>(val);
    }
    consteval hectotesla_ull operator""_hT(unsigned long long val) {
        return static_cast<hectotesla_ull>(val);
    }
    consteval decatesla_ull operator""_daT(unsigned long long val) {
        return static_cast<decatesla_ull>(val);
    }
    consteval tesla_ull operator""_T(unsigned long long val) {
        return static_cast<tesla_ull>(val);
    }
    consteval decitesla_ull operator""_dT(unsigned long long val) {
        return static_cast<decitesla_ull>(val);
    }
    consteval centitesla_ull operator""_cT(unsigned long long val) {
        return static_cast<centitesla_ull>(val);
    }
    consteval millitesla_ull operator""_mT(unsigned long long val) {
        return static_cast<millitesla_ull>(val);
    }
    consteval microtesla_ull operator""_uT(unsigned long long val) {
        return static_cast<microtesla_ull>(val);
    }
    consteval nanotesla_ull operator""_nT(unsigned long long val) {
        return static_cast<nanotesla_ull>(val);
    }
    consteval picotesla_ull operator""_pT(unsigned long long val) {
        return static_cast<picotesla_ull>(val);
    }
    consteval femtotesla_ull operator""_fT(unsigned long long val) {
        return static_cast<femtotesla_ull>(val);
    }
    consteval attotesla_ull operator""_aT(unsigned long long val) {
        return static_cast<attotesla_ull>(val);
    }

} // namespace potato::units
