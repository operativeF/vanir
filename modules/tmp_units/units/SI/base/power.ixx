//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Watt;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using watt_tag_t = tmp::list_<tmp::list_<meter_l, meter_l, gram_l>, tmp::list_<second_l, second_l, second_l>>;

    template<typename T>
    concept WattC = std::same_as<typename T::impl, watt_tag_t>;

    template <typename RatioTypeT, typename P>
    struct watt_impl {

        static constexpr auto pretty = "W";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = watt_tag_t;

        constexpr watt_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exawatt_ld    =     watt_impl<std::exa, long double>;
    using petawatt_ld    =     watt_impl<std::peta, long double>;
    using terawatt_ld    =     watt_impl<std::tera, long double>;
    using gigawatt_ld    =     watt_impl<std::giga, long double>;
    using megawatt_ld    =     watt_impl<std::mega, long double>;
    using kilowatt_ld    =     watt_impl<std::kilo, long double>;
    using hectowatt_ld    =     watt_impl<std::hecto, long double>;
    using decawatt_ld    =     watt_impl<std::deca, long double>;
    using watt_ld    =     watt_impl<unity_ratio, long double>;
    using deciwatt_ld    =     watt_impl<std::deci, long double>;
    using centiwatt_ld    =     watt_impl<std::centi, long double>;
    using milliwatt_ld    =     watt_impl<std::milli, long double>;
    using microwatt_ld    =     watt_impl<std::micro, long double>;
    using nanowatt_ld    =     watt_impl<std::nano, long double>;
    using picowatt_ld    =     watt_impl<std::pico, long double>;
    using femtowatt_ld    =     watt_impl<std::femto, long double>;
    using attowatt_ld    =     watt_impl<std::atto, long double>;
    using exawatt_ull    =     watt_impl<std::exa, unsigned long long>;
    using petawatt_ull    =     watt_impl<std::peta, unsigned long long>;
    using terawatt_ull    =     watt_impl<std::tera, unsigned long long>;
    using gigawatt_ull    =     watt_impl<std::giga, unsigned long long>;
    using megawatt_ull    =     watt_impl<std::mega, unsigned long long>;
    using kilowatt_ull    =     watt_impl<std::kilo, unsigned long long>;
    using hectowatt_ull    =     watt_impl<std::hecto, unsigned long long>;
    using decawatt_ull    =     watt_impl<std::deca, unsigned long long>;
    using watt_ull    =     watt_impl<unity_ratio, unsigned long long>;
    using deciwatt_ull    =     watt_impl<std::deci, unsigned long long>;
    using centiwatt_ull    =     watt_impl<std::centi, unsigned long long>;
    using milliwatt_ull    =     watt_impl<std::milli, unsigned long long>;
    using microwatt_ull    =     watt_impl<std::micro, unsigned long long>;
    using nanowatt_ull    =     watt_impl<std::nano, unsigned long long>;
    using picowatt_ull    =     watt_impl<std::pico, unsigned long long>;
    using femtowatt_ull    =     watt_impl<std::femto, unsigned long long>;
    using attowatt_ull    =     watt_impl<std::atto, unsigned long long>;

    constexpr exawatt_ld operator""_EW(long double val) {
        return static_cast<exawatt_ld>(val);
    }
    constexpr petawatt_ld operator""_PW(long double val) {
        return static_cast<petawatt_ld>(val);
    }
    constexpr terawatt_ld operator""_TW(long double val) {
        return static_cast<terawatt_ld>(val);
    }
    constexpr gigawatt_ld operator""_GW(long double val) {
        return static_cast<gigawatt_ld>(val);
    }
    constexpr megawatt_ld operator""_MW(long double val) {
        return static_cast<megawatt_ld>(val);
    }
    constexpr kilowatt_ld operator""_kW(long double val) {
        return static_cast<kilowatt_ld>(val);
    }
    constexpr hectowatt_ld operator""_hW(long double val) {
        return static_cast<hectowatt_ld>(val);
    }
    constexpr decawatt_ld operator""_daW(long double val) {
        return static_cast<decawatt_ld>(val);
    }
    constexpr watt_ld operator""_W(long double val) {
        return static_cast<watt_ld>(val);
    }
    constexpr deciwatt_ld operator""_dW(long double val) {
        return static_cast<deciwatt_ld>(val);
    }
    constexpr centiwatt_ld operator""_cW(long double val) {
        return static_cast<centiwatt_ld>(val);
    }
    constexpr milliwatt_ld operator""_mW(long double val) {
        return static_cast<milliwatt_ld>(val);
    }
    constexpr microwatt_ld operator""_uW(long double val) {
        return static_cast<microwatt_ld>(val);
    }
    constexpr nanowatt_ld operator""_nW(long double val) {
        return static_cast<nanowatt_ld>(val);
    }
    constexpr picowatt_ld operator""_pW(long double val) {
        return static_cast<picowatt_ld>(val);
    }
    constexpr femtowatt_ld operator""_fW(long double val) {
        return static_cast<femtowatt_ld>(val);
    }
    constexpr attowatt_ld operator""_aW(long double val) {
        return static_cast<attowatt_ld>(val);
    }
    constexpr exawatt_ull operator""_EW(unsigned long long val) {
        return static_cast<exawatt_ull>(val);
    }
    constexpr petawatt_ull operator""_PW(unsigned long long val) {
        return static_cast<petawatt_ull>(val);
    }
    constexpr terawatt_ull operator""_TW(unsigned long long val) {
        return static_cast<terawatt_ull>(val);
    }
    constexpr gigawatt_ull operator""_GW(unsigned long long val) {
        return static_cast<gigawatt_ull>(val);
    }
    constexpr megawatt_ull operator""_MW(unsigned long long val) {
        return static_cast<megawatt_ull>(val);
    }
    constexpr kilowatt_ull operator""_kW(unsigned long long val) {
        return static_cast<kilowatt_ull>(val);
    }
    constexpr hectowatt_ull operator""_hW(unsigned long long val) {
        return static_cast<hectowatt_ull>(val);
    }
    constexpr decawatt_ull operator""_daW(unsigned long long val) {
        return static_cast<decawatt_ull>(val);
    }
    constexpr watt_ull operator""_W(unsigned long long val) {
        return static_cast<watt_ull>(val);
    }
    constexpr deciwatt_ull operator""_dW(unsigned long long val) {
        return static_cast<deciwatt_ull>(val);
    }
    constexpr centiwatt_ull operator""_cW(unsigned long long val) {
        return static_cast<centiwatt_ull>(val);
    }
    constexpr milliwatt_ull operator""_mW(unsigned long long val) {
        return static_cast<milliwatt_ull>(val);
    }
    constexpr microwatt_ull operator""_uW(unsigned long long val) {
        return static_cast<microwatt_ull>(val);
    }
    constexpr nanowatt_ull operator""_nW(unsigned long long val) {
        return static_cast<nanowatt_ull>(val);
    }
    constexpr picowatt_ull operator""_pW(unsigned long long val) {
        return static_cast<picowatt_ull>(val);
    }
    constexpr femtowatt_ull operator""_fW(unsigned long long val) {
        return static_cast<femtowatt_ull>(val);
    }
    constexpr attowatt_ull operator""_aW(unsigned long long val) {
        return static_cast<attowatt_ull>(val);
    }

} // namespace potato::units
