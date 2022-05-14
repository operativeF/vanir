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

    using farad_tag_t = tmp::list_<tmp::list_<second_l, second_l, second_l, second_l, ampere_l, ampere_l>, tmp::list_<meter_l, meter_l, gram_l>>;

    template<typename T>
    concept FaradC = std::same_as<typename T::impl, farad_tag_t>;

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
        using numer_type = DerivedValueType;
        using impl       = farad_tag_t;

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

    constexpr exafarad_ld operator""_EF(long double val) {
        return static_cast<exafarad_ld>(val);
    }
    constexpr petafarad_ld operator""_PF(long double val) {
        return static_cast<petafarad_ld>(val);
    }
    constexpr terafarad_ld operator""_TF(long double val) {
        return static_cast<terafarad_ld>(val);
    }
    constexpr gigafarad_ld operator""_GF(long double val) {
        return static_cast<gigafarad_ld>(val);
    }
    constexpr megafarad_ld operator""_MF(long double val) {
        return static_cast<megafarad_ld>(val);
    }
    constexpr kilofarad_ld operator""_kF(long double val) {
        return static_cast<kilofarad_ld>(val);
    }
    constexpr hectofarad_ld operator""_hF(long double val) {
        return static_cast<hectofarad_ld>(val);
    }
    constexpr decafarad_ld operator""_daF(long double val) {
        return static_cast<decafarad_ld>(val);
    }
    constexpr farad_ld operator""_F(long double val) {
        return static_cast<farad_ld>(val);
    }
    constexpr decifarad_ld operator""_dF(long double val) {
        return static_cast<decifarad_ld>(val);
    }
    constexpr centifarad_ld operator""_cF(long double val) {
        return static_cast<centifarad_ld>(val);
    }
    constexpr millifarad_ld operator""_mF(long double val) {
        return static_cast<millifarad_ld>(val);
    }
    constexpr microfarad_ld operator""_uF(long double val) {
        return static_cast<microfarad_ld>(val);
    }
    constexpr nanofarad_ld operator""_nF(long double val) {
        return static_cast<nanofarad_ld>(val);
    }
    constexpr picofarad_ld operator""_pF(long double val) {
        return static_cast<picofarad_ld>(val);
    }
    constexpr femtofarad_ld operator""_fF(long double val) {
        return static_cast<femtofarad_ld>(val);
    }
    constexpr attofarad_ld operator""_aF(long double val) {
        return static_cast<attofarad_ld>(val);
    }
    constexpr exafarad_ull operator""_EF(unsigned long long val) {
        return static_cast<exafarad_ull>(val);
    }
    constexpr petafarad_ull operator""_PF(unsigned long long val) {
        return static_cast<petafarad_ull>(val);
    }
    constexpr terafarad_ull operator""_TF(unsigned long long val) {
        return static_cast<terafarad_ull>(val);
    }
    constexpr gigafarad_ull operator""_GF(unsigned long long val) {
        return static_cast<gigafarad_ull>(val);
    }
    constexpr megafarad_ull operator""_MF(unsigned long long val) {
        return static_cast<megafarad_ull>(val);
    }
    constexpr kilofarad_ull operator""_kF(unsigned long long val) {
        return static_cast<kilofarad_ull>(val);
    }
    constexpr hectofarad_ull operator""_hF(unsigned long long val) {
        return static_cast<hectofarad_ull>(val);
    }
    constexpr decafarad_ull operator""_daF(unsigned long long val) {
        return static_cast<decafarad_ull>(val);
    }
    constexpr farad_ull operator""_F(unsigned long long val) {
        return static_cast<farad_ull>(val);
    }
    constexpr decifarad_ull operator""_dF(unsigned long long val) {
        return static_cast<decifarad_ull>(val);
    }
    constexpr centifarad_ull operator""_cF(unsigned long long val) {
        return static_cast<centifarad_ull>(val);
    }
    constexpr millifarad_ull operator""_mF(unsigned long long val) {
        return static_cast<millifarad_ull>(val);
    }
    constexpr microfarad_ull operator""_uF(unsigned long long val) {
        return static_cast<microfarad_ull>(val);
    }
    constexpr nanofarad_ull operator""_nF(unsigned long long val) {
        return static_cast<nanofarad_ull>(val);
    }
    constexpr picofarad_ull operator""_pF(unsigned long long val) {
        return static_cast<picofarad_ull>(val);
    }
    constexpr femtofarad_ull operator""_fF(unsigned long long val) {
        return static_cast<femtofarad_ull>(val);
    }
    constexpr attofarad_ull operator""_aF(unsigned long long val) {
        return static_cast<attofarad_ull>(val);
    }

} // namespace potato::units
