//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Siemens;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using conductance_tag_t = tmp::list_<Length<std::ratio<-2, 1>>,
                                         Time<std::ratio<3, 1>>,
                                         Mass<std::ratio<-1, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<2, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept SiemensC = std::same_as<typename T::impl, conductance_tag_t>;

    template <typename RatioTypeT, typename P>
    struct siemens_impl {

        static constexpr auto pretty = "S";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = conductance_tag_t;

        constexpr siemens_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exasiemens_ld    =     siemens_impl<std::exa, long double>;
    using petasiemens_ld    =     siemens_impl<std::peta, long double>;
    using terasiemens_ld    =     siemens_impl<std::tera, long double>;
    using gigasiemens_ld    =     siemens_impl<std::giga, long double>;
    using megasiemens_ld    =     siemens_impl<std::mega, long double>;
    using kilosiemens_ld    =     siemens_impl<std::kilo, long double>;
    using hectosiemens_ld    =     siemens_impl<std::hecto, long double>;
    using decasiemens_ld    =     siemens_impl<std::deca, long double>;
    using siemens_ld    =     siemens_impl<unity_ratio, long double>;
    using decisiemens_ld    =     siemens_impl<std::deci, long double>;
    using centisiemens_ld    =     siemens_impl<std::centi, long double>;
    using millisiemens_ld    =     siemens_impl<std::milli, long double>;
    using microsiemens_ld    =     siemens_impl<std::micro, long double>;
    using nanosiemens_ld    =     siemens_impl<std::nano, long double>;
    using picosiemens_ld    =     siemens_impl<std::pico, long double>;
    using femtosiemens_ld    =     siemens_impl<std::femto, long double>;
    using attosiemens_ld    =     siemens_impl<std::atto, long double>;
    using exasiemens_ull    =     siemens_impl<std::exa, unsigned long long>;
    using petasiemens_ull    =     siemens_impl<std::peta, unsigned long long>;
    using terasiemens_ull    =     siemens_impl<std::tera, unsigned long long>;
    using gigasiemens_ull    =     siemens_impl<std::giga, unsigned long long>;
    using megasiemens_ull    =     siemens_impl<std::mega, unsigned long long>;
    using kilosiemens_ull    =     siemens_impl<std::kilo, unsigned long long>;
    using hectosiemens_ull    =     siemens_impl<std::hecto, unsigned long long>;
    using decasiemens_ull    =     siemens_impl<std::deca, unsigned long long>;
    using siemens_ull    =     siemens_impl<unity_ratio, unsigned long long>;
    using decisiemens_ull    =     siemens_impl<std::deci, unsigned long long>;
    using centisiemens_ull    =     siemens_impl<std::centi, unsigned long long>;
    using millisiemens_ull    =     siemens_impl<std::milli, unsigned long long>;
    using microsiemens_ull    =     siemens_impl<std::micro, unsigned long long>;
    using nanosiemens_ull    =     siemens_impl<std::nano, unsigned long long>;
    using picosiemens_ull    =     siemens_impl<std::pico, unsigned long long>;
    using femtosiemens_ull    =     siemens_impl<std::femto, unsigned long long>;
    using attosiemens_ull    =     siemens_impl<std::atto, unsigned long long>;

    constexpr exasiemens_ld operator""_ES(long double val) {
        return static_cast<exasiemens_ld>(val);
    }
    constexpr petasiemens_ld operator""_PS(long double val) {
        return static_cast<petasiemens_ld>(val);
    }
    constexpr terasiemens_ld operator""_TS(long double val) {
        return static_cast<terasiemens_ld>(val);
    }
    constexpr gigasiemens_ld operator""_GS(long double val) {
        return static_cast<gigasiemens_ld>(val);
    }
    constexpr megasiemens_ld operator""_MS(long double val) {
        return static_cast<megasiemens_ld>(val);
    }
    constexpr kilosiemens_ld operator""_kS(long double val) {
        return static_cast<kilosiemens_ld>(val);
    }
    constexpr hectosiemens_ld operator""_hS(long double val) {
        return static_cast<hectosiemens_ld>(val);
    }
    constexpr decasiemens_ld operator""_daS(long double val) {
        return static_cast<decasiemens_ld>(val);
    }
    constexpr siemens_ld operator""_S(long double val) {
        return static_cast<siemens_ld>(val);
    }
    constexpr decisiemens_ld operator""_dS(long double val) {
        return static_cast<decisiemens_ld>(val);
    }
    constexpr centisiemens_ld operator""_cS(long double val) {
        return static_cast<centisiemens_ld>(val);
    }
    constexpr millisiemens_ld operator""_mS(long double val) {
        return static_cast<millisiemens_ld>(val);
    }
    constexpr microsiemens_ld operator""_uS(long double val) {
        return static_cast<microsiemens_ld>(val);
    }
    constexpr nanosiemens_ld operator""_nS(long double val) {
        return static_cast<nanosiemens_ld>(val);
    }
    constexpr picosiemens_ld operator""_pS(long double val) {
        return static_cast<picosiemens_ld>(val);
    }
    constexpr femtosiemens_ld operator""_fS(long double val) {
        return static_cast<femtosiemens_ld>(val);
    }
    constexpr attosiemens_ld operator""_aS(long double val) {
        return static_cast<attosiemens_ld>(val);
    }
    constexpr exasiemens_ull operator""_ES(unsigned long long val) {
        return static_cast<exasiemens_ull>(val);
    }
    constexpr petasiemens_ull operator""_PS(unsigned long long val) {
        return static_cast<petasiemens_ull>(val);
    }
    constexpr terasiemens_ull operator""_TS(unsigned long long val) {
        return static_cast<terasiemens_ull>(val);
    }
    constexpr gigasiemens_ull operator""_GS(unsigned long long val) {
        return static_cast<gigasiemens_ull>(val);
    }
    constexpr megasiemens_ull operator""_MS(unsigned long long val) {
        return static_cast<megasiemens_ull>(val);
    }
    constexpr kilosiemens_ull operator""_kS(unsigned long long val) {
        return static_cast<kilosiemens_ull>(val);
    }
    constexpr hectosiemens_ull operator""_hS(unsigned long long val) {
        return static_cast<hectosiemens_ull>(val);
    }
    constexpr decasiemens_ull operator""_daS(unsigned long long val) {
        return static_cast<decasiemens_ull>(val);
    }
    constexpr siemens_ull operator""_S(unsigned long long val) {
        return static_cast<siemens_ull>(val);
    }
    constexpr decisiemens_ull operator""_dS(unsigned long long val) {
        return static_cast<decisiemens_ull>(val);
    }
    constexpr centisiemens_ull operator""_cS(unsigned long long val) {
        return static_cast<centisiemens_ull>(val);
    }
    constexpr millisiemens_ull operator""_mS(unsigned long long val) {
        return static_cast<millisiemens_ull>(val);
    }
    constexpr microsiemens_ull operator""_uS(unsigned long long val) {
        return static_cast<microsiemens_ull>(val);
    }
    constexpr nanosiemens_ull operator""_nS(unsigned long long val) {
        return static_cast<nanosiemens_ull>(val);
    }
    constexpr picosiemens_ull operator""_pS(unsigned long long val) {
        return static_cast<picosiemens_ull>(val);
    }
    constexpr femtosiemens_ull operator""_fS(unsigned long long val) {
        return static_cast<femtosiemens_ull>(val);
    }
    constexpr attosiemens_ull operator""_aS(unsigned long long val) {
        return static_cast<attosiemens_ull>(val);
    }

} // namespace potato::units
