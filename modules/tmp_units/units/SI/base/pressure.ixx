//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Pascal;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using pressure_tag_t = tmp::list_<Length<std::ratio<-1, 1>>,
                                         Time<std::ratio<-2, 1>>,
                                         Mass<std::ratio<1, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept PascalC = std::same_as<typename T::impl, pressure_tag_t>;

    template <typename RatioTypeT, typename P>
    struct pascal_impl {

        static constexpr auto pretty = "Pa";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = pressure_tag_t;

        constexpr pascal_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exapascal_ld    =     pascal_impl<std::exa, long double>;
    using petapascal_ld    =     pascal_impl<std::peta, long double>;
    using terapascal_ld    =     pascal_impl<std::tera, long double>;
    using gigapascal_ld    =     pascal_impl<std::giga, long double>;
    using megapascal_ld    =     pascal_impl<std::mega, long double>;
    using kilopascal_ld    =     pascal_impl<std::kilo, long double>;
    using hectopascal_ld    =     pascal_impl<std::hecto, long double>;
    using decapascal_ld    =     pascal_impl<std::deca, long double>;
    using pascal_ld    =     pascal_impl<unity_ratio, long double>;
    using decipascal_ld    =     pascal_impl<std::deci, long double>;
    using centipascal_ld    =     pascal_impl<std::centi, long double>;
    using millipascal_ld    =     pascal_impl<std::milli, long double>;
    using micropascal_ld    =     pascal_impl<std::micro, long double>;
    using nanopascal_ld    =     pascal_impl<std::nano, long double>;
    using picopascal_ld    =     pascal_impl<std::pico, long double>;
    using femtopascal_ld    =     pascal_impl<std::femto, long double>;
    using attopascal_ld    =     pascal_impl<std::atto, long double>;
    using exapascal_ull    =     pascal_impl<std::exa, unsigned long long>;
    using petapascal_ull    =     pascal_impl<std::peta, unsigned long long>;
    using terapascal_ull    =     pascal_impl<std::tera, unsigned long long>;
    using gigapascal_ull    =     pascal_impl<std::giga, unsigned long long>;
    using megapascal_ull    =     pascal_impl<std::mega, unsigned long long>;
    using kilopascal_ull    =     pascal_impl<std::kilo, unsigned long long>;
    using hectopascal_ull    =     pascal_impl<std::hecto, unsigned long long>;
    using decapascal_ull    =     pascal_impl<std::deca, unsigned long long>;
    using pascal_ull    =     pascal_impl<unity_ratio, unsigned long long>;
    using decipascal_ull    =     pascal_impl<std::deci, unsigned long long>;
    using centipascal_ull    =     pascal_impl<std::centi, unsigned long long>;
    using millipascal_ull    =     pascal_impl<std::milli, unsigned long long>;
    using micropascal_ull    =     pascal_impl<std::micro, unsigned long long>;
    using nanopascal_ull    =     pascal_impl<std::nano, unsigned long long>;
    using picopascal_ull    =     pascal_impl<std::pico, unsigned long long>;
    using femtopascal_ull    =     pascal_impl<std::femto, unsigned long long>;
    using attopascal_ull    =     pascal_impl<std::atto, unsigned long long>;

    constexpr exapascal_ld operator""_EPa(long double val) {
        return static_cast<exapascal_ld>(val);
    }
    constexpr petapascal_ld operator""_PPa(long double val) {
        return static_cast<petapascal_ld>(val);
    }
    constexpr terapascal_ld operator""_TPa(long double val) {
        return static_cast<terapascal_ld>(val);
    }
    constexpr gigapascal_ld operator""_GPa(long double val) {
        return static_cast<gigapascal_ld>(val);
    }
    constexpr megapascal_ld operator""_MPa(long double val) {
        return static_cast<megapascal_ld>(val);
    }
    constexpr kilopascal_ld operator""_kPa(long double val) {
        return static_cast<kilopascal_ld>(val);
    }
    constexpr hectopascal_ld operator""_hPa(long double val) {
        return static_cast<hectopascal_ld>(val);
    }
    constexpr decapascal_ld operator""_daPa(long double val) {
        return static_cast<decapascal_ld>(val);
    }
    constexpr pascal_ld operator""_Pa(long double val) {
        return static_cast<pascal_ld>(val);
    }
    constexpr decipascal_ld operator""_dPa(long double val) {
        return static_cast<decipascal_ld>(val);
    }
    constexpr centipascal_ld operator""_cPa(long double val) {
        return static_cast<centipascal_ld>(val);
    }
    constexpr millipascal_ld operator""_mPa(long double val) {
        return static_cast<millipascal_ld>(val);
    }
    constexpr micropascal_ld operator""_uPa(long double val) {
        return static_cast<micropascal_ld>(val);
    }
    constexpr nanopascal_ld operator""_nPa(long double val) {
        return static_cast<nanopascal_ld>(val);
    }
    constexpr picopascal_ld operator""_pPa(long double val) {
        return static_cast<picopascal_ld>(val);
    }
    constexpr femtopascal_ld operator""_fPa(long double val) {
        return static_cast<femtopascal_ld>(val);
    }
    constexpr attopascal_ld operator""_aPa(long double val) {
        return static_cast<attopascal_ld>(val);
    }
    constexpr exapascal_ull operator""_EPa(unsigned long long val) {
        return static_cast<exapascal_ull>(val);
    }
    constexpr petapascal_ull operator""_PPa(unsigned long long val) {
        return static_cast<petapascal_ull>(val);
    }
    constexpr terapascal_ull operator""_TPa(unsigned long long val) {
        return static_cast<terapascal_ull>(val);
    }
    constexpr gigapascal_ull operator""_GPa(unsigned long long val) {
        return static_cast<gigapascal_ull>(val);
    }
    constexpr megapascal_ull operator""_MPa(unsigned long long val) {
        return static_cast<megapascal_ull>(val);
    }
    constexpr kilopascal_ull operator""_kPa(unsigned long long val) {
        return static_cast<kilopascal_ull>(val);
    }
    constexpr hectopascal_ull operator""_hPa(unsigned long long val) {
        return static_cast<hectopascal_ull>(val);
    }
    constexpr decapascal_ull operator""_daPa(unsigned long long val) {
        return static_cast<decapascal_ull>(val);
    }
    constexpr pascal_ull operator""_Pa(unsigned long long val) {
        return static_cast<pascal_ull>(val);
    }
    constexpr decipascal_ull operator""_dPa(unsigned long long val) {
        return static_cast<decipascal_ull>(val);
    }
    constexpr centipascal_ull operator""_cPa(unsigned long long val) {
        return static_cast<centipascal_ull>(val);
    }
    constexpr millipascal_ull operator""_mPa(unsigned long long val) {
        return static_cast<millipascal_ull>(val);
    }
    constexpr micropascal_ull operator""_uPa(unsigned long long val) {
        return static_cast<micropascal_ull>(val);
    }
    constexpr nanopascal_ull operator""_nPa(unsigned long long val) {
        return static_cast<nanopascal_ull>(val);
    }
    constexpr picopascal_ull operator""_pPa(unsigned long long val) {
        return static_cast<picopascal_ull>(val);
    }
    constexpr femtopascal_ull operator""_fPa(unsigned long long val) {
        return static_cast<femtopascal_ull>(val);
    }
    constexpr attopascal_ull operator""_aPa(unsigned long long val) {
        return static_cast<attopascal_ull>(val);
    }

} // namespace potato::units
