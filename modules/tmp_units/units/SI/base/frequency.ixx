//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Hertz;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using frequency_tag_t = tmp::list_<Length<std::ratio<0, 1>>,
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
    concept HertzC = std::same_as<typename T::impl, frequency_tag_t>;

    template <typename RatioTypeT, typename P>
    struct hertz_impl {

        static constexpr auto pretty = "Hz";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = frequency_tag_t;

        constexpr hertz_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exahertz_ld    =     hertz_impl<std::exa, long double>;
    using petahertz_ld    =     hertz_impl<std::peta, long double>;
    using terahertz_ld    =     hertz_impl<std::tera, long double>;
    using gigahertz_ld    =     hertz_impl<std::giga, long double>;
    using megahertz_ld    =     hertz_impl<std::mega, long double>;
    using kilohertz_ld    =     hertz_impl<std::kilo, long double>;
    using hectohertz_ld    =     hertz_impl<std::hecto, long double>;
    using decahertz_ld    =     hertz_impl<std::deca, long double>;
    using hertz_ld    =     hertz_impl<unity_ratio, long double>;
    using decihertz_ld    =     hertz_impl<std::deci, long double>;
    using centihertz_ld    =     hertz_impl<std::centi, long double>;
    using millihertz_ld    =     hertz_impl<std::milli, long double>;
    using microhertz_ld    =     hertz_impl<std::micro, long double>;
    using nanohertz_ld    =     hertz_impl<std::nano, long double>;
    using picohertz_ld    =     hertz_impl<std::pico, long double>;
    using femtohertz_ld    =     hertz_impl<std::femto, long double>;
    using attohertz_ld    =     hertz_impl<std::atto, long double>;
    using exahertz_ull    =     hertz_impl<std::exa, unsigned long long>;
    using petahertz_ull    =     hertz_impl<std::peta, unsigned long long>;
    using terahertz_ull    =     hertz_impl<std::tera, unsigned long long>;
    using gigahertz_ull    =     hertz_impl<std::giga, unsigned long long>;
    using megahertz_ull    =     hertz_impl<std::mega, unsigned long long>;
    using kilohertz_ull    =     hertz_impl<std::kilo, unsigned long long>;
    using hectohertz_ull    =     hertz_impl<std::hecto, unsigned long long>;
    using decahertz_ull    =     hertz_impl<std::deca, unsigned long long>;
    using hertz_ull    =     hertz_impl<unity_ratio, unsigned long long>;
    using decihertz_ull    =     hertz_impl<std::deci, unsigned long long>;
    using centihertz_ull    =     hertz_impl<std::centi, unsigned long long>;
    using millihertz_ull    =     hertz_impl<std::milli, unsigned long long>;
    using microhertz_ull    =     hertz_impl<std::micro, unsigned long long>;
    using nanohertz_ull    =     hertz_impl<std::nano, unsigned long long>;
    using picohertz_ull    =     hertz_impl<std::pico, unsigned long long>;
    using femtohertz_ull    =     hertz_impl<std::femto, unsigned long long>;
    using attohertz_ull    =     hertz_impl<std::atto, unsigned long long>;

    consteval exahertz_ld operator""_EHz(long double val) {
        return static_cast<exahertz_ld>(val);
    }
    consteval petahertz_ld operator""_PHz(long double val) {
        return static_cast<petahertz_ld>(val);
    }
    consteval terahertz_ld operator""_THz(long double val) {
        return static_cast<terahertz_ld>(val);
    }
    consteval gigahertz_ld operator""_GHz(long double val) {
        return static_cast<gigahertz_ld>(val);
    }
    consteval megahertz_ld operator""_MHz(long double val) {
        return static_cast<megahertz_ld>(val);
    }
    consteval kilohertz_ld operator""_kHz(long double val) {
        return static_cast<kilohertz_ld>(val);
    }
    consteval hectohertz_ld operator""_hHz(long double val) {
        return static_cast<hectohertz_ld>(val);
    }
    consteval decahertz_ld operator""_daHz(long double val) {
        return static_cast<decahertz_ld>(val);
    }
    consteval hertz_ld operator""_Hz(long double val) {
        return static_cast<hertz_ld>(val);
    }
    consteval decihertz_ld operator""_dHz(long double val) {
        return static_cast<decihertz_ld>(val);
    }
    consteval centihertz_ld operator""_cHz(long double val) {
        return static_cast<centihertz_ld>(val);
    }
    consteval millihertz_ld operator""_mHz(long double val) {
        return static_cast<millihertz_ld>(val);
    }
    consteval microhertz_ld operator""_uHz(long double val) {
        return static_cast<microhertz_ld>(val);
    }
    consteval nanohertz_ld operator""_nHz(long double val) {
        return static_cast<nanohertz_ld>(val);
    }
    consteval picohertz_ld operator""_pHz(long double val) {
        return static_cast<picohertz_ld>(val);
    }
    consteval femtohertz_ld operator""_fHz(long double val) {
        return static_cast<femtohertz_ld>(val);
    }
    consteval attohertz_ld operator""_aHz(long double val) {
        return static_cast<attohertz_ld>(val);
    }
    consteval exahertz_ull operator""_EHz(unsigned long long val) {
        return static_cast<exahertz_ull>(val);
    }
    consteval petahertz_ull operator""_PHz(unsigned long long val) {
        return static_cast<petahertz_ull>(val);
    }
    consteval terahertz_ull operator""_THz(unsigned long long val) {
        return static_cast<terahertz_ull>(val);
    }
    consteval gigahertz_ull operator""_GHz(unsigned long long val) {
        return static_cast<gigahertz_ull>(val);
    }
    consteval megahertz_ull operator""_MHz(unsigned long long val) {
        return static_cast<megahertz_ull>(val);
    }
    consteval kilohertz_ull operator""_kHz(unsigned long long val) {
        return static_cast<kilohertz_ull>(val);
    }
    consteval hectohertz_ull operator""_hHz(unsigned long long val) {
        return static_cast<hectohertz_ull>(val);
    }
    consteval decahertz_ull operator""_daHz(unsigned long long val) {
        return static_cast<decahertz_ull>(val);
    }
    consteval hertz_ull operator""_Hz(unsigned long long val) {
        return static_cast<hertz_ull>(val);
    }
    consteval decihertz_ull operator""_dHz(unsigned long long val) {
        return static_cast<decihertz_ull>(val);
    }
    consteval centihertz_ull operator""_cHz(unsigned long long val) {
        return static_cast<centihertz_ull>(val);
    }
    consteval millihertz_ull operator""_mHz(unsigned long long val) {
        return static_cast<millihertz_ull>(val);
    }
    consteval microhertz_ull operator""_uHz(unsigned long long val) {
        return static_cast<microhertz_ull>(val);
    }
    consteval nanohertz_ull operator""_nHz(unsigned long long val) {
        return static_cast<nanohertz_ull>(val);
    }
    consteval picohertz_ull operator""_pHz(unsigned long long val) {
        return static_cast<picohertz_ull>(val);
    }
    consteval femtohertz_ull operator""_fHz(unsigned long long val) {
        return static_cast<femtohertz_ull>(val);
    }
    consteval attohertz_ull operator""_aHz(unsigned long long val) {
        return static_cast<attohertz_ull>(val);
    }

} // namespace potato::units
