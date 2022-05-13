//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Pascal_Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.BaseUnit;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename RatioTypeT, typename P>
    struct pascal_second_impl : base_unit_<RatioTypeT, P> {

        using base_unit_<RatioTypeT, P>::base_unit_;
        template <typename U, typename R>
        constexpr const pascal_second_impl<RatioTypeT, P>(const pascal_second_impl<U, R>& other) {
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

        static constexpr auto pretty = "Pa·s";

        using is_any_impl = false_;

        using mod_ratio = RatioTypeT;
        using numer_type = base_unit_<RatioTypeT, P>::value_type;
        using impl      = list_<list_<gram_l>, list_<meter_l, second_l>>;
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

    constexpr exapascal_second_ld operator""_EPa_s(long double val) {
        return static_cast<exapascal_second_ld>(val);
    }
    constexpr petapascal_second_ld operator""_PPa_s(long double val) {
        return static_cast<petapascal_second_ld>(val);
    }
    constexpr terapascal_second_ld operator""_TPa_s(long double val) {
        return static_cast<terapascal_second_ld>(val);
    }
    constexpr gigapascal_second_ld operator""_GPa_s(long double val) {
        return static_cast<gigapascal_second_ld>(val);
    }
    constexpr megapascal_second_ld operator""_MPa_s(long double val) {
        return static_cast<megapascal_second_ld>(val);
    }
    constexpr kilopascal_second_ld operator""_kPa_s(long double val) {
        return static_cast<kilopascal_second_ld>(val);
    }
    constexpr hectopascal_second_ld operator""_hPa_s(long double val) {
        return static_cast<hectopascal_second_ld>(val);
    }
    constexpr decapascal_second_ld operator""_daPa_s(long double val) {
        return static_cast<decapascal_second_ld>(val);
    }
    constexpr pascal_second_ld operator""_Pa_s(long double val) {
        return static_cast<pascal_second_ld>(val);
    }
    constexpr decipascal_second_ld operator""_dPa_s(long double val) {
        return static_cast<decipascal_second_ld>(val);
    }
    constexpr centipascal_second_ld operator""_cPa_s(long double val) {
        return static_cast<centipascal_second_ld>(val);
    }
    constexpr millipascal_second_ld operator""_mPa_s(long double val) {
        return static_cast<millipascal_second_ld>(val);
    }
    constexpr micropascal_second_ld operator""_uPa_s(long double val) {
        return static_cast<micropascal_second_ld>(val);
    }
    constexpr nanopascal_second_ld operator""_nPa_s(long double val) {
        return static_cast<nanopascal_second_ld>(val);
    }
    constexpr picopascal_second_ld operator""_pPa_s(long double val) {
        return static_cast<picopascal_second_ld>(val);
    }
    constexpr femtopascal_second_ld operator""_fPa_s(long double val) {
        return static_cast<femtopascal_second_ld>(val);
    }
    constexpr attopascal_second_ld operator""_aPa_s(long double val) {
        return static_cast<attopascal_second_ld>(val);
    }
    constexpr exapascal_second_ull operator""_EPa_s(unsigned long long val) {
        return static_cast<exapascal_second_ull>(val);
    }
    constexpr petapascal_second_ull operator""_PPa_s(unsigned long long val) {
        return static_cast<petapascal_second_ull>(val);
    }
    constexpr terapascal_second_ull operator""_TPa_s(unsigned long long val) {
        return static_cast<terapascal_second_ull>(val);
    }
    constexpr gigapascal_second_ull operator""_GPa_s(unsigned long long val) {
        return static_cast<gigapascal_second_ull>(val);
    }
    constexpr megapascal_second_ull operator""_MPa_s(unsigned long long val) {
        return static_cast<megapascal_second_ull>(val);
    }
    constexpr kilopascal_second_ull operator""_kPa_s(unsigned long long val) {
        return static_cast<kilopascal_second_ull>(val);
    }
    constexpr hectopascal_second_ull operator""_hPa_s(unsigned long long val) {
        return static_cast<hectopascal_second_ull>(val);
    }
    constexpr decapascal_second_ull operator""_daPa_s(unsigned long long val) {
        return static_cast<decapascal_second_ull>(val);
    }
    constexpr pascal_second_ull operator""_Pa_s(unsigned long long val) {
        return static_cast<pascal_second_ull>(val);
    }
    constexpr decipascal_second_ull operator""_dPa_s(unsigned long long val) {
        return static_cast<decipascal_second_ull>(val);
    }
    constexpr centipascal_second_ull operator""_cPa_s(unsigned long long val) {
        return static_cast<centipascal_second_ull>(val);
    }
    constexpr millipascal_second_ull operator""_mPa_s(unsigned long long val) {
        return static_cast<millipascal_second_ull>(val);
    }
    constexpr micropascal_second_ull operator""_uPa_s(unsigned long long val) {
        return static_cast<micropascal_second_ull>(val);
    }
    constexpr nanopascal_second_ull operator""_nPa_s(unsigned long long val) {
        return static_cast<nanopascal_second_ull>(val);
    }
    constexpr picopascal_second_ull operator""_pPa_s(unsigned long long val) {
        return static_cast<picopascal_second_ull>(val);
    }
    constexpr femtopascal_second_ull operator""_fPa_s(unsigned long long val) {
        return static_cast<femtopascal_second_ull>(val);
    }
    constexpr attopascal_second_ull operator""_aPa_s(unsigned long long val) {
        return static_cast<attopascal_second_ull>(val);
    }

} // namespace potato::units
