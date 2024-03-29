//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Hertz_Per_Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using frequency_drift_tag_t = tmp::list_<Length<std::ratio<0, 1>>,
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
    concept Hertz_Per_SecondC = std::same_as<typename T::impl, frequency_drift_tag_t>;

    template <typename RatioTypeT, typename P>
    struct hertz_per_second_impl {

        static constexpr auto pretty = "1/s²";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = frequency_drift_tag_t;

        constexpr hertz_per_second_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exahertz_per_second_ld    =     hertz_per_second_impl<std::exa, long double>;
    using petahertz_per_second_ld    =     hertz_per_second_impl<std::peta, long double>;
    using terahertz_per_second_ld    =     hertz_per_second_impl<std::tera, long double>;
    using gigahertz_per_second_ld    =     hertz_per_second_impl<std::giga, long double>;
    using megahertz_per_second_ld    =     hertz_per_second_impl<std::mega, long double>;
    using kilohertz_per_second_ld    =     hertz_per_second_impl<std::kilo, long double>;
    using hectohertz_per_second_ld    =     hertz_per_second_impl<std::hecto, long double>;
    using decahertz_per_second_ld    =     hertz_per_second_impl<std::deca, long double>;
    using hertz_per_second_ld    =     hertz_per_second_impl<unity_ratio, long double>;
    using decihertz_per_second_ld    =     hertz_per_second_impl<std::deci, long double>;
    using centihertz_per_second_ld    =     hertz_per_second_impl<std::centi, long double>;
    using millihertz_per_second_ld    =     hertz_per_second_impl<std::milli, long double>;
    using microhertz_per_second_ld    =     hertz_per_second_impl<std::micro, long double>;
    using nanohertz_per_second_ld    =     hertz_per_second_impl<std::nano, long double>;
    using picohertz_per_second_ld    =     hertz_per_second_impl<std::pico, long double>;
    using femtohertz_per_second_ld    =     hertz_per_second_impl<std::femto, long double>;
    using attohertz_per_second_ld    =     hertz_per_second_impl<std::atto, long double>;
    using exahertz_per_second_ull    =     hertz_per_second_impl<std::exa, unsigned long long>;
    using petahertz_per_second_ull    =     hertz_per_second_impl<std::peta, unsigned long long>;
    using terahertz_per_second_ull    =     hertz_per_second_impl<std::tera, unsigned long long>;
    using gigahertz_per_second_ull    =     hertz_per_second_impl<std::giga, unsigned long long>;
    using megahertz_per_second_ull    =     hertz_per_second_impl<std::mega, unsigned long long>;
    using kilohertz_per_second_ull    =     hertz_per_second_impl<std::kilo, unsigned long long>;
    using hectohertz_per_second_ull    =     hertz_per_second_impl<std::hecto, unsigned long long>;
    using decahertz_per_second_ull    =     hertz_per_second_impl<std::deca, unsigned long long>;
    using hertz_per_second_ull    =     hertz_per_second_impl<unity_ratio, unsigned long long>;
    using decihertz_per_second_ull    =     hertz_per_second_impl<std::deci, unsigned long long>;
    using centihertz_per_second_ull    =     hertz_per_second_impl<std::centi, unsigned long long>;
    using millihertz_per_second_ull    =     hertz_per_second_impl<std::milli, unsigned long long>;
    using microhertz_per_second_ull    =     hertz_per_second_impl<std::micro, unsigned long long>;
    using nanohertz_per_second_ull    =     hertz_per_second_impl<std::nano, unsigned long long>;
    using picohertz_per_second_ull    =     hertz_per_second_impl<std::pico, unsigned long long>;
    using femtohertz_per_second_ull    =     hertz_per_second_impl<std::femto, unsigned long long>;
    using attohertz_per_second_ull    =     hertz_per_second_impl<std::atto, unsigned long long>;

    consteval exahertz_per_second_ld operator""_Einv_square_s(long double val) {
        return static_cast<exahertz_per_second_ld>(val);
    }
    consteval petahertz_per_second_ld operator""_Pinv_square_s(long double val) {
        return static_cast<petahertz_per_second_ld>(val);
    }
    consteval terahertz_per_second_ld operator""_Tinv_square_s(long double val) {
        return static_cast<terahertz_per_second_ld>(val);
    }
    consteval gigahertz_per_second_ld operator""_Ginv_square_s(long double val) {
        return static_cast<gigahertz_per_second_ld>(val);
    }
    consteval megahertz_per_second_ld operator""_Minv_square_s(long double val) {
        return static_cast<megahertz_per_second_ld>(val);
    }
    consteval kilohertz_per_second_ld operator""_kinv_square_s(long double val) {
        return static_cast<kilohertz_per_second_ld>(val);
    }
    consteval hectohertz_per_second_ld operator""_hinv_square_s(long double val) {
        return static_cast<hectohertz_per_second_ld>(val);
    }
    consteval decahertz_per_second_ld operator""_dainv_square_s(long double val) {
        return static_cast<decahertz_per_second_ld>(val);
    }
    consteval hertz_per_second_ld operator""_inv_square_s(long double val) {
        return static_cast<hertz_per_second_ld>(val);
    }
    consteval decihertz_per_second_ld operator""_dinv_square_s(long double val) {
        return static_cast<decihertz_per_second_ld>(val);
    }
    consteval centihertz_per_second_ld operator""_cinv_square_s(long double val) {
        return static_cast<centihertz_per_second_ld>(val);
    }
    consteval millihertz_per_second_ld operator""_minv_square_s(long double val) {
        return static_cast<millihertz_per_second_ld>(val);
    }
    consteval microhertz_per_second_ld operator""_uinv_square_s(long double val) {
        return static_cast<microhertz_per_second_ld>(val);
    }
    consteval nanohertz_per_second_ld operator""_ninv_square_s(long double val) {
        return static_cast<nanohertz_per_second_ld>(val);
    }
    consteval picohertz_per_second_ld operator""_pinv_square_s(long double val) {
        return static_cast<picohertz_per_second_ld>(val);
    }
    consteval femtohertz_per_second_ld operator""_finv_square_s(long double val) {
        return static_cast<femtohertz_per_second_ld>(val);
    }
    consteval attohertz_per_second_ld operator""_ainv_square_s(long double val) {
        return static_cast<attohertz_per_second_ld>(val);
    }
    consteval exahertz_per_second_ull operator""_Einv_square_s(unsigned long long val) {
        return static_cast<exahertz_per_second_ull>(val);
    }
    consteval petahertz_per_second_ull operator""_Pinv_square_s(unsigned long long val) {
        return static_cast<petahertz_per_second_ull>(val);
    }
    consteval terahertz_per_second_ull operator""_Tinv_square_s(unsigned long long val) {
        return static_cast<terahertz_per_second_ull>(val);
    }
    consteval gigahertz_per_second_ull operator""_Ginv_square_s(unsigned long long val) {
        return static_cast<gigahertz_per_second_ull>(val);
    }
    consteval megahertz_per_second_ull operator""_Minv_square_s(unsigned long long val) {
        return static_cast<megahertz_per_second_ull>(val);
    }
    consteval kilohertz_per_second_ull operator""_kinv_square_s(unsigned long long val) {
        return static_cast<kilohertz_per_second_ull>(val);
    }
    consteval hectohertz_per_second_ull operator""_hinv_square_s(unsigned long long val) {
        return static_cast<hectohertz_per_second_ull>(val);
    }
    consteval decahertz_per_second_ull operator""_dainv_square_s(unsigned long long val) {
        return static_cast<decahertz_per_second_ull>(val);
    }
    consteval hertz_per_second_ull operator""_inv_square_s(unsigned long long val) {
        return static_cast<hertz_per_second_ull>(val);
    }
    consteval decihertz_per_second_ull operator""_dinv_square_s(unsigned long long val) {
        return static_cast<decihertz_per_second_ull>(val);
    }
    consteval centihertz_per_second_ull operator""_cinv_square_s(unsigned long long val) {
        return static_cast<centihertz_per_second_ull>(val);
    }
    consteval millihertz_per_second_ull operator""_minv_square_s(unsigned long long val) {
        return static_cast<millihertz_per_second_ull>(val);
    }
    consteval microhertz_per_second_ull operator""_uinv_square_s(unsigned long long val) {
        return static_cast<microhertz_per_second_ull>(val);
    }
    consteval nanohertz_per_second_ull operator""_ninv_square_s(unsigned long long val) {
        return static_cast<nanohertz_per_second_ull>(val);
    }
    consteval picohertz_per_second_ull operator""_pinv_square_s(unsigned long long val) {
        return static_cast<picohertz_per_second_ull>(val);
    }
    consteval femtohertz_per_second_ull operator""_finv_square_s(unsigned long long val) {
        return static_cast<femtohertz_per_second_ull>(val);
    }
    consteval attohertz_per_second_ull operator""_ainv_square_s(unsigned long long val) {
        return static_cast<attohertz_per_second_ull>(val);
    }

} // namespace potato::units
