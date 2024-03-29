//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Farad;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using capacitance_tag_t = tmp::list_<Length<std::ratio<-2, 1>>,
                                         Time<std::ratio<4, 1>>,
                                         Mass<std::ratio<-1, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<2, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept FaradC = std::same_as<typename T::impl, capacitance_tag_t>;

    template <typename RatioTypeT, typename P>
    struct farad_impl {

        static constexpr auto pretty = "F";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = capacitance_tag_t;

        constexpr farad_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exafarad_ld    =     farad_impl<std::exa, long double>;
    using petafarad_ld    =     farad_impl<std::peta, long double>;
    using terafarad_ld    =     farad_impl<std::tera, long double>;
    using gigafarad_ld    =     farad_impl<std::giga, long double>;
    using megafarad_ld    =     farad_impl<std::mega, long double>;
    using kilofarad_ld    =     farad_impl<std::kilo, long double>;
    using hectofarad_ld    =     farad_impl<std::hecto, long double>;
    using decafarad_ld    =     farad_impl<std::deca, long double>;
    using farad_ld    =     farad_impl<unity_ratio, long double>;
    using decifarad_ld    =     farad_impl<std::deci, long double>;
    using centifarad_ld    =     farad_impl<std::centi, long double>;
    using millifarad_ld    =     farad_impl<std::milli, long double>;
    using microfarad_ld    =     farad_impl<std::micro, long double>;
    using nanofarad_ld    =     farad_impl<std::nano, long double>;
    using picofarad_ld    =     farad_impl<std::pico, long double>;
    using femtofarad_ld    =     farad_impl<std::femto, long double>;
    using attofarad_ld    =     farad_impl<std::atto, long double>;
    using exafarad_ull    =     farad_impl<std::exa, unsigned long long>;
    using petafarad_ull    =     farad_impl<std::peta, unsigned long long>;
    using terafarad_ull    =     farad_impl<std::tera, unsigned long long>;
    using gigafarad_ull    =     farad_impl<std::giga, unsigned long long>;
    using megafarad_ull    =     farad_impl<std::mega, unsigned long long>;
    using kilofarad_ull    =     farad_impl<std::kilo, unsigned long long>;
    using hectofarad_ull    =     farad_impl<std::hecto, unsigned long long>;
    using decafarad_ull    =     farad_impl<std::deca, unsigned long long>;
    using farad_ull    =     farad_impl<unity_ratio, unsigned long long>;
    using decifarad_ull    =     farad_impl<std::deci, unsigned long long>;
    using centifarad_ull    =     farad_impl<std::centi, unsigned long long>;
    using millifarad_ull    =     farad_impl<std::milli, unsigned long long>;
    using microfarad_ull    =     farad_impl<std::micro, unsigned long long>;
    using nanofarad_ull    =     farad_impl<std::nano, unsigned long long>;
    using picofarad_ull    =     farad_impl<std::pico, unsigned long long>;
    using femtofarad_ull    =     farad_impl<std::femto, unsigned long long>;
    using attofarad_ull    =     farad_impl<std::atto, unsigned long long>;

    consteval exafarad_ld operator""_EF(long double val) {
        return static_cast<exafarad_ld>(val);
    }
    consteval petafarad_ld operator""_PF(long double val) {
        return static_cast<petafarad_ld>(val);
    }
    consteval terafarad_ld operator""_TF(long double val) {
        return static_cast<terafarad_ld>(val);
    }
    consteval gigafarad_ld operator""_GF(long double val) {
        return static_cast<gigafarad_ld>(val);
    }
    consteval megafarad_ld operator""_MF(long double val) {
        return static_cast<megafarad_ld>(val);
    }
    consteval kilofarad_ld operator""_kF(long double val) {
        return static_cast<kilofarad_ld>(val);
    }
    consteval hectofarad_ld operator""_hF(long double val) {
        return static_cast<hectofarad_ld>(val);
    }
    consteval decafarad_ld operator""_daF(long double val) {
        return static_cast<decafarad_ld>(val);
    }
    consteval farad_ld operator""_F(long double val) {
        return static_cast<farad_ld>(val);
    }
    consteval decifarad_ld operator""_dF(long double val) {
        return static_cast<decifarad_ld>(val);
    }
    consteval centifarad_ld operator""_cF(long double val) {
        return static_cast<centifarad_ld>(val);
    }
    consteval millifarad_ld operator""_mF(long double val) {
        return static_cast<millifarad_ld>(val);
    }
    consteval microfarad_ld operator""_uF(long double val) {
        return static_cast<microfarad_ld>(val);
    }
    consteval nanofarad_ld operator""_nF(long double val) {
        return static_cast<nanofarad_ld>(val);
    }
    consteval picofarad_ld operator""_pF(long double val) {
        return static_cast<picofarad_ld>(val);
    }
    consteval femtofarad_ld operator""_fF(long double val) {
        return static_cast<femtofarad_ld>(val);
    }
    consteval attofarad_ld operator""_aF(long double val) {
        return static_cast<attofarad_ld>(val);
    }
    consteval exafarad_ull operator""_EF(unsigned long long val) {
        return static_cast<exafarad_ull>(val);
    }
    consteval petafarad_ull operator""_PF(unsigned long long val) {
        return static_cast<petafarad_ull>(val);
    }
    consteval terafarad_ull operator""_TF(unsigned long long val) {
        return static_cast<terafarad_ull>(val);
    }
    consteval gigafarad_ull operator""_GF(unsigned long long val) {
        return static_cast<gigafarad_ull>(val);
    }
    consteval megafarad_ull operator""_MF(unsigned long long val) {
        return static_cast<megafarad_ull>(val);
    }
    consteval kilofarad_ull operator""_kF(unsigned long long val) {
        return static_cast<kilofarad_ull>(val);
    }
    consteval hectofarad_ull operator""_hF(unsigned long long val) {
        return static_cast<hectofarad_ull>(val);
    }
    consteval decafarad_ull operator""_daF(unsigned long long val) {
        return static_cast<decafarad_ull>(val);
    }
    consteval farad_ull operator""_F(unsigned long long val) {
        return static_cast<farad_ull>(val);
    }
    consteval decifarad_ull operator""_dF(unsigned long long val) {
        return static_cast<decifarad_ull>(val);
    }
    consteval centifarad_ull operator""_cF(unsigned long long val) {
        return static_cast<centifarad_ull>(val);
    }
    consteval millifarad_ull operator""_mF(unsigned long long val) {
        return static_cast<millifarad_ull>(val);
    }
    consteval microfarad_ull operator""_uF(unsigned long long val) {
        return static_cast<microfarad_ull>(val);
    }
    consteval nanofarad_ull operator""_nF(unsigned long long val) {
        return static_cast<nanofarad_ull>(val);
    }
    consteval picofarad_ull operator""_pF(unsigned long long val) {
        return static_cast<picofarad_ull>(val);
    }
    consteval femtofarad_ull operator""_fF(unsigned long long val) {
        return static_cast<femtofarad_ull>(val);
    }
    consteval attofarad_ull operator""_aF(unsigned long long val) {
        return static_cast<attofarad_ull>(val);
    }

} // namespace potato::units
