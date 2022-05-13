//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Steradian;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.BaseUnit;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename RatioTypeT, typename P>
    struct steradian_impl : base_unit_<RatioTypeT, P> {

        using base_unit_<RatioTypeT, P>::base_unit_;
        template <typename U, typename R>
        constexpr const steradian_impl<RatioTypeT, P>(const steradian_impl<U, R>& other) {
            using scale_greater = call_<if_<lift_<std::ratio_greater>,
                always_<std::ratio_divide<U, RatioTypeT>>,
                always_<unity_ratio>>,
                RatioTypeT, U>;
            using scale_lesser = call_<if_<lift_<std::ratio_less>,
                always_<std::ratio_divide<RatioTypeT, U>>,
                always_<unity_ratio>>,
                RatioTypeT, U>;
            this->value = (other.value * scale_greater::num * scale_lesser::den) / (scale_greater::den * scale_lesser::num);
        }

        static constexpr auto pretty = "sr";

        using is_any_impl = false_;

        using mod_ratio = RatioTypeT;
        using numer_type = base_unit_<RatioTypeT, P>::value_type;
        using impl      = list_<list_<steradian_l>, list_<>>;
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

    constexpr exasteradian_ld operator""_Esr(long double val) {
        return static_cast<exasteradian_ld>(val);
    }
    constexpr petasteradian_ld operator""_Psr(long double val) {
        return static_cast<petasteradian_ld>(val);
    }
    constexpr terasteradian_ld operator""_Tsr(long double val) {
        return static_cast<terasteradian_ld>(val);
    }
    constexpr gigasteradian_ld operator""_Gsr(long double val) {
        return static_cast<gigasteradian_ld>(val);
    }
    constexpr megasteradian_ld operator""_Msr(long double val) {
        return static_cast<megasteradian_ld>(val);
    }
    constexpr kilosteradian_ld operator""_ksr(long double val) {
        return static_cast<kilosteradian_ld>(val);
    }
    constexpr hectosteradian_ld operator""_hsr(long double val) {
        return static_cast<hectosteradian_ld>(val);
    }
    constexpr decasteradian_ld operator""_dasr(long double val) {
        return static_cast<decasteradian_ld>(val);
    }
    constexpr steradian_ld operator""_sr(long double val) {
        return static_cast<steradian_ld>(val);
    }
    constexpr decisteradian_ld operator""_dsr(long double val) {
        return static_cast<decisteradian_ld>(val);
    }
    constexpr centisteradian_ld operator""_csr(long double val) {
        return static_cast<centisteradian_ld>(val);
    }
    constexpr millisteradian_ld operator""_msr(long double val) {
        return static_cast<millisteradian_ld>(val);
    }
    constexpr microsteradian_ld operator""_usr(long double val) {
        return static_cast<microsteradian_ld>(val);
    }
    constexpr nanosteradian_ld operator""_nsr(long double val) {
        return static_cast<nanosteradian_ld>(val);
    }
    constexpr picosteradian_ld operator""_psr(long double val) {
        return static_cast<picosteradian_ld>(val);
    }
    constexpr femtosteradian_ld operator""_fsr(long double val) {
        return static_cast<femtosteradian_ld>(val);
    }
    constexpr attosteradian_ld operator""_asr(long double val) {
        return static_cast<attosteradian_ld>(val);
    }
    constexpr exasteradian_ull operator""_Esr(unsigned long long val) {
        return static_cast<exasteradian_ull>(val);
    }
    constexpr petasteradian_ull operator""_Psr(unsigned long long val) {
        return static_cast<petasteradian_ull>(val);
    }
    constexpr terasteradian_ull operator""_Tsr(unsigned long long val) {
        return static_cast<terasteradian_ull>(val);
    }
    constexpr gigasteradian_ull operator""_Gsr(unsigned long long val) {
        return static_cast<gigasteradian_ull>(val);
    }
    constexpr megasteradian_ull operator""_Msr(unsigned long long val) {
        return static_cast<megasteradian_ull>(val);
    }
    constexpr kilosteradian_ull operator""_ksr(unsigned long long val) {
        return static_cast<kilosteradian_ull>(val);
    }
    constexpr hectosteradian_ull operator""_hsr(unsigned long long val) {
        return static_cast<hectosteradian_ull>(val);
    }
    constexpr decasteradian_ull operator""_dasr(unsigned long long val) {
        return static_cast<decasteradian_ull>(val);
    }
    constexpr steradian_ull operator""_sr(unsigned long long val) {
        return static_cast<steradian_ull>(val);
    }
    constexpr decisteradian_ull operator""_dsr(unsigned long long val) {
        return static_cast<decisteradian_ull>(val);
    }
    constexpr centisteradian_ull operator""_csr(unsigned long long val) {
        return static_cast<centisteradian_ull>(val);
    }
    constexpr millisteradian_ull operator""_msr(unsigned long long val) {
        return static_cast<millisteradian_ull>(val);
    }
    constexpr microsteradian_ull operator""_usr(unsigned long long val) {
        return static_cast<microsteradian_ull>(val);
    }
    constexpr nanosteradian_ull operator""_nsr(unsigned long long val) {
        return static_cast<nanosteradian_ull>(val);
    }
    constexpr picosteradian_ull operator""_psr(unsigned long long val) {
        return static_cast<picosteradian_ull>(val);
    }
    constexpr femtosteradian_ull operator""_fsr(unsigned long long val) {
        return static_cast<femtosteradian_ull>(val);
    }
    constexpr attosteradian_ull operator""_asr(unsigned long long val) {
        return static_cast<attosteradian_ull>(val);
    }

} // namespace potato::units
