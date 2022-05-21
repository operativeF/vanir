//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Pascal_Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using dynamic_viscosity_tag_t = tmp::list_<Length<std::ratio<-1, 1>>,
                                         Time<std::ratio<-1, 1>>,
                                         Mass<std::ratio<1, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept Pascal_SecondC = std::same_as<typename T::impl, dynamic_viscosity_tag_t>;

    template <typename RatioTypeT, typename P>
    struct pascal_second_impl {

        static constexpr auto pretty = "Pa·s";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = dynamic_viscosity_tag_t;

        constexpr pascal_second_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exapascal_second_ld    =     pascal_second_impl<std::exa, long double>;
    using petapascal_second_ld    =     pascal_second_impl<std::peta, long double>;
    using terapascal_second_ld    =     pascal_second_impl<std::tera, long double>;
    using gigapascal_second_ld    =     pascal_second_impl<std::giga, long double>;
    using megapascal_second_ld    =     pascal_second_impl<std::mega, long double>;
    using kilopascal_second_ld    =     pascal_second_impl<std::kilo, long double>;
    using hectopascal_second_ld    =     pascal_second_impl<std::hecto, long double>;
    using decapascal_second_ld    =     pascal_second_impl<std::deca, long double>;
    using pascal_second_ld    =     pascal_second_impl<unity_ratio, long double>;
    using decipascal_second_ld    =     pascal_second_impl<std::deci, long double>;
    using centipascal_second_ld    =     pascal_second_impl<std::centi, long double>;
    using millipascal_second_ld    =     pascal_second_impl<std::milli, long double>;
    using micropascal_second_ld    =     pascal_second_impl<std::micro, long double>;
    using nanopascal_second_ld    =     pascal_second_impl<std::nano, long double>;
    using picopascal_second_ld    =     pascal_second_impl<std::pico, long double>;
    using femtopascal_second_ld    =     pascal_second_impl<std::femto, long double>;
    using attopascal_second_ld    =     pascal_second_impl<std::atto, long double>;
    using exapascal_second_ull    =     pascal_second_impl<std::exa, unsigned long long>;
    using petapascal_second_ull    =     pascal_second_impl<std::peta, unsigned long long>;
    using terapascal_second_ull    =     pascal_second_impl<std::tera, unsigned long long>;
    using gigapascal_second_ull    =     pascal_second_impl<std::giga, unsigned long long>;
    using megapascal_second_ull    =     pascal_second_impl<std::mega, unsigned long long>;
    using kilopascal_second_ull    =     pascal_second_impl<std::kilo, unsigned long long>;
    using hectopascal_second_ull    =     pascal_second_impl<std::hecto, unsigned long long>;
    using decapascal_second_ull    =     pascal_second_impl<std::deca, unsigned long long>;
    using pascal_second_ull    =     pascal_second_impl<unity_ratio, unsigned long long>;
    using decipascal_second_ull    =     pascal_second_impl<std::deci, unsigned long long>;
    using centipascal_second_ull    =     pascal_second_impl<std::centi, unsigned long long>;
    using millipascal_second_ull    =     pascal_second_impl<std::milli, unsigned long long>;
    using micropascal_second_ull    =     pascal_second_impl<std::micro, unsigned long long>;
    using nanopascal_second_ull    =     pascal_second_impl<std::nano, unsigned long long>;
    using picopascal_second_ull    =     pascal_second_impl<std::pico, unsigned long long>;
    using femtopascal_second_ull    =     pascal_second_impl<std::femto, unsigned long long>;
    using attopascal_second_ull    =     pascal_second_impl<std::atto, unsigned long long>;

    consteval exapascal_second_ld operator""_EPa_s(long double val) {
        return static_cast<exapascal_second_ld>(val);
    }
    consteval petapascal_second_ld operator""_PPa_s(long double val) {
        return static_cast<petapascal_second_ld>(val);
    }
    consteval terapascal_second_ld operator""_TPa_s(long double val) {
        return static_cast<terapascal_second_ld>(val);
    }
    consteval gigapascal_second_ld operator""_GPa_s(long double val) {
        return static_cast<gigapascal_second_ld>(val);
    }
    consteval megapascal_second_ld operator""_MPa_s(long double val) {
        return static_cast<megapascal_second_ld>(val);
    }
    consteval kilopascal_second_ld operator""_kPa_s(long double val) {
        return static_cast<kilopascal_second_ld>(val);
    }
    consteval hectopascal_second_ld operator""_hPa_s(long double val) {
        return static_cast<hectopascal_second_ld>(val);
    }
    consteval decapascal_second_ld operator""_daPa_s(long double val) {
        return static_cast<decapascal_second_ld>(val);
    }
    consteval pascal_second_ld operator""_Pa_s(long double val) {
        return static_cast<pascal_second_ld>(val);
    }
    consteval decipascal_second_ld operator""_dPa_s(long double val) {
        return static_cast<decipascal_second_ld>(val);
    }
    consteval centipascal_second_ld operator""_cPa_s(long double val) {
        return static_cast<centipascal_second_ld>(val);
    }
    consteval millipascal_second_ld operator""_mPa_s(long double val) {
        return static_cast<millipascal_second_ld>(val);
    }
    consteval micropascal_second_ld operator""_uPa_s(long double val) {
        return static_cast<micropascal_second_ld>(val);
    }
    consteval nanopascal_second_ld operator""_nPa_s(long double val) {
        return static_cast<nanopascal_second_ld>(val);
    }
    consteval picopascal_second_ld operator""_pPa_s(long double val) {
        return static_cast<picopascal_second_ld>(val);
    }
    consteval femtopascal_second_ld operator""_fPa_s(long double val) {
        return static_cast<femtopascal_second_ld>(val);
    }
    consteval attopascal_second_ld operator""_aPa_s(long double val) {
        return static_cast<attopascal_second_ld>(val);
    }
    consteval exapascal_second_ull operator""_EPa_s(unsigned long long val) {
        return static_cast<exapascal_second_ull>(val);
    }
    consteval petapascal_second_ull operator""_PPa_s(unsigned long long val) {
        return static_cast<petapascal_second_ull>(val);
    }
    consteval terapascal_second_ull operator""_TPa_s(unsigned long long val) {
        return static_cast<terapascal_second_ull>(val);
    }
    consteval gigapascal_second_ull operator""_GPa_s(unsigned long long val) {
        return static_cast<gigapascal_second_ull>(val);
    }
    consteval megapascal_second_ull operator""_MPa_s(unsigned long long val) {
        return static_cast<megapascal_second_ull>(val);
    }
    consteval kilopascal_second_ull operator""_kPa_s(unsigned long long val) {
        return static_cast<kilopascal_second_ull>(val);
    }
    consteval hectopascal_second_ull operator""_hPa_s(unsigned long long val) {
        return static_cast<hectopascal_second_ull>(val);
    }
    consteval decapascal_second_ull operator""_daPa_s(unsigned long long val) {
        return static_cast<decapascal_second_ull>(val);
    }
    consteval pascal_second_ull operator""_Pa_s(unsigned long long val) {
        return static_cast<pascal_second_ull>(val);
    }
    consteval decipascal_second_ull operator""_dPa_s(unsigned long long val) {
        return static_cast<decipascal_second_ull>(val);
    }
    consteval centipascal_second_ull operator""_cPa_s(unsigned long long val) {
        return static_cast<centipascal_second_ull>(val);
    }
    consteval millipascal_second_ull operator""_mPa_s(unsigned long long val) {
        return static_cast<millipascal_second_ull>(val);
    }
    consteval micropascal_second_ull operator""_uPa_s(unsigned long long val) {
        return static_cast<micropascal_second_ull>(val);
    }
    consteval nanopascal_second_ull operator""_nPa_s(unsigned long long val) {
        return static_cast<nanopascal_second_ull>(val);
    }
    consteval picopascal_second_ull operator""_pPa_s(unsigned long long val) {
        return static_cast<picopascal_second_ull>(val);
    }
    consteval femtopascal_second_ull operator""_fPa_s(unsigned long long val) {
        return static_cast<femtopascal_second_ull>(val);
    }
    consteval attopascal_second_ull operator""_aPa_s(unsigned long long val) {
        return static_cast<attopascal_second_ull>(val);
    }

} // namespace potato::units
