//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Candela;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.BaseUnit;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename RatioTypeT, typename P>
    struct candela_impl : base_unit_<RatioTypeT, P> {

        using base_unit_<RatioTypeT, P>::base_unit_;
        template <typename U, typename R>
        constexpr const candela_impl<RatioTypeT, P>(const candela_impl<U, R>& other) {
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

        static constexpr auto pretty = "cd";

        using is_any_impl = false_;

        using mod_ratio = RatioTypeT;
        using numer_type = base_unit_<RatioTypeT, P>::value_type;
        using impl      = list_<list_<candela_l>, list_<>>;
    };

    using exacandela_ld    =     candela_impl<std::exa, long double>;
    using petacandela_ld    =     candela_impl<std::peta, long double>;
    using teracandela_ld    =     candela_impl<std::tera, long double>;
    using gigacandela_ld    =     candela_impl<std::giga, long double>;
    using megacandela_ld    =     candela_impl<std::mega, long double>;
    using kilocandela_ld    =     candela_impl<std::kilo, long double>;
    using hectocandela_ld    =     candela_impl<std::hecto, long double>;
    using decacandela_ld    =     candela_impl<std::deca, long double>;
    using candela_ld    =     candela_impl<unity_ratio, long double>;
    using decicandela_ld    =     candela_impl<std::deci, long double>;
    using centicandela_ld    =     candela_impl<std::centi, long double>;
    using millicandela_ld    =     candela_impl<std::milli, long double>;
    using microcandela_ld    =     candela_impl<std::micro, long double>;
    using nanocandela_ld    =     candela_impl<std::nano, long double>;
    using picocandela_ld    =     candela_impl<std::pico, long double>;
    using femtocandela_ld    =     candela_impl<std::femto, long double>;
    using attocandela_ld    =     candela_impl<std::atto, long double>;
    using exacandela_ull    =     candela_impl<std::exa, unsigned long long>;
    using petacandela_ull    =     candela_impl<std::peta, unsigned long long>;
    using teracandela_ull    =     candela_impl<std::tera, unsigned long long>;
    using gigacandela_ull    =     candela_impl<std::giga, unsigned long long>;
    using megacandela_ull    =     candela_impl<std::mega, unsigned long long>;
    using kilocandela_ull    =     candela_impl<std::kilo, unsigned long long>;
    using hectocandela_ull    =     candela_impl<std::hecto, unsigned long long>;
    using decacandela_ull    =     candela_impl<std::deca, unsigned long long>;
    using candela_ull    =     candela_impl<unity_ratio, unsigned long long>;
    using decicandela_ull    =     candela_impl<std::deci, unsigned long long>;
    using centicandela_ull    =     candela_impl<std::centi, unsigned long long>;
    using millicandela_ull    =     candela_impl<std::milli, unsigned long long>;
    using microcandela_ull    =     candela_impl<std::micro, unsigned long long>;
    using nanocandela_ull    =     candela_impl<std::nano, unsigned long long>;
    using picocandela_ull    =     candela_impl<std::pico, unsigned long long>;
    using femtocandela_ull    =     candela_impl<std::femto, unsigned long long>;
    using attocandela_ull    =     candela_impl<std::atto, unsigned long long>;

    constexpr exacandela_ld operator""_Ecd(long double val) {
        return static_cast<exacandela_ld>(val);
    }
    constexpr petacandela_ld operator""_Pcd(long double val) {
        return static_cast<petacandela_ld>(val);
    }
    constexpr teracandela_ld operator""_Tcd(long double val) {
        return static_cast<teracandela_ld>(val);
    }
    constexpr gigacandela_ld operator""_Gcd(long double val) {
        return static_cast<gigacandela_ld>(val);
    }
    constexpr megacandela_ld operator""_Mcd(long double val) {
        return static_cast<megacandela_ld>(val);
    }
    constexpr kilocandela_ld operator""_kcd(long double val) {
        return static_cast<kilocandela_ld>(val);
    }
    constexpr hectocandela_ld operator""_hcd(long double val) {
        return static_cast<hectocandela_ld>(val);
    }
    constexpr decacandela_ld operator""_dacd(long double val) {
        return static_cast<decacandela_ld>(val);
    }
    constexpr candela_ld operator""_cd(long double val) {
        return static_cast<candela_ld>(val);
    }
    constexpr decicandela_ld operator""_dcd(long double val) {
        return static_cast<decicandela_ld>(val);
    }
    constexpr centicandela_ld operator""_ccd(long double val) {
        return static_cast<centicandela_ld>(val);
    }
    constexpr millicandela_ld operator""_mcd(long double val) {
        return static_cast<millicandela_ld>(val);
    }
    constexpr microcandela_ld operator""_ucd(long double val) {
        return static_cast<microcandela_ld>(val);
    }
    constexpr nanocandela_ld operator""_ncd(long double val) {
        return static_cast<nanocandela_ld>(val);
    }
    constexpr picocandela_ld operator""_pcd(long double val) {
        return static_cast<picocandela_ld>(val);
    }
    constexpr femtocandela_ld operator""_fcd(long double val) {
        return static_cast<femtocandela_ld>(val);
    }
    constexpr attocandela_ld operator""_acd(long double val) {
        return static_cast<attocandela_ld>(val);
    }
    constexpr exacandela_ull operator""_Ecd(unsigned long long val) {
        return static_cast<exacandela_ull>(val);
    }
    constexpr petacandela_ull operator""_Pcd(unsigned long long val) {
        return static_cast<petacandela_ull>(val);
    }
    constexpr teracandela_ull operator""_Tcd(unsigned long long val) {
        return static_cast<teracandela_ull>(val);
    }
    constexpr gigacandela_ull operator""_Gcd(unsigned long long val) {
        return static_cast<gigacandela_ull>(val);
    }
    constexpr megacandela_ull operator""_Mcd(unsigned long long val) {
        return static_cast<megacandela_ull>(val);
    }
    constexpr kilocandela_ull operator""_kcd(unsigned long long val) {
        return static_cast<kilocandela_ull>(val);
    }
    constexpr hectocandela_ull operator""_hcd(unsigned long long val) {
        return static_cast<hectocandela_ull>(val);
    }
    constexpr decacandela_ull operator""_dacd(unsigned long long val) {
        return static_cast<decacandela_ull>(val);
    }
    constexpr candela_ull operator""_cd(unsigned long long val) {
        return static_cast<candela_ull>(val);
    }
    constexpr decicandela_ull operator""_dcd(unsigned long long val) {
        return static_cast<decicandela_ull>(val);
    }
    constexpr centicandela_ull operator""_ccd(unsigned long long val) {
        return static_cast<centicandela_ull>(val);
    }
    constexpr millicandela_ull operator""_mcd(unsigned long long val) {
        return static_cast<millicandela_ull>(val);
    }
    constexpr microcandela_ull operator""_ucd(unsigned long long val) {
        return static_cast<microcandela_ull>(val);
    }
    constexpr nanocandela_ull operator""_ncd(unsigned long long val) {
        return static_cast<nanocandela_ull>(val);
    }
    constexpr picocandela_ull operator""_pcd(unsigned long long val) {
        return static_cast<picocandela_ull>(val);
    }
    constexpr femtocandela_ull operator""_fcd(unsigned long long val) {
        return static_cast<femtocandela_ull>(val);
    }
    constexpr attocandela_ull operator""_acd(unsigned long long val) {
        return static_cast<attocandela_ull>(val);
    }

} // namespace potato::units
