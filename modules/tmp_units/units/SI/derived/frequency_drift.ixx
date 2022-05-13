//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Hertz_Per_Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.BaseUnit;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename RatioTypeT, typename P>
    struct hertz_per_second_impl : base_unit_<RatioTypeT, P> {

        using base_unit_<RatioTypeT, P>::base_unit_;
        template <typename U, typename R>
        constexpr const hertz_per_second_impl<RatioTypeT, P>(const hertz_per_second_impl<U, R>& other) {
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

        static constexpr auto pretty = "1/s²";

        using is_any_impl = false_;

        using mod_ratio = RatioTypeT;
        using numer_type = base_unit_<RatioTypeT, P>::value_type;
        using impl      = list_<list_<>, list_<second_l, second_l>>;
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

    constexpr exahertz_per_second_ld operator""_Einv_square_s(long double val) {
        return static_cast<exahertz_per_second_ld>(val);
    }
    constexpr petahertz_per_second_ld operator""_Pinv_square_s(long double val) {
        return static_cast<petahertz_per_second_ld>(val);
    }
    constexpr terahertz_per_second_ld operator""_Tinv_square_s(long double val) {
        return static_cast<terahertz_per_second_ld>(val);
    }
    constexpr gigahertz_per_second_ld operator""_Ginv_square_s(long double val) {
        return static_cast<gigahertz_per_second_ld>(val);
    }
    constexpr megahertz_per_second_ld operator""_Minv_square_s(long double val) {
        return static_cast<megahertz_per_second_ld>(val);
    }
    constexpr kilohertz_per_second_ld operator""_kinv_square_s(long double val) {
        return static_cast<kilohertz_per_second_ld>(val);
    }
    constexpr hectohertz_per_second_ld operator""_hinv_square_s(long double val) {
        return static_cast<hectohertz_per_second_ld>(val);
    }
    constexpr decahertz_per_second_ld operator""_dainv_square_s(long double val) {
        return static_cast<decahertz_per_second_ld>(val);
    }
    constexpr hertz_per_second_ld operator""_inv_square_s(long double val) {
        return static_cast<hertz_per_second_ld>(val);
    }
    constexpr decihertz_per_second_ld operator""_dinv_square_s(long double val) {
        return static_cast<decihertz_per_second_ld>(val);
    }
    constexpr centihertz_per_second_ld operator""_cinv_square_s(long double val) {
        return static_cast<centihertz_per_second_ld>(val);
    }
    constexpr millihertz_per_second_ld operator""_minv_square_s(long double val) {
        return static_cast<millihertz_per_second_ld>(val);
    }
    constexpr microhertz_per_second_ld operator""_uinv_square_s(long double val) {
        return static_cast<microhertz_per_second_ld>(val);
    }
    constexpr nanohertz_per_second_ld operator""_ninv_square_s(long double val) {
        return static_cast<nanohertz_per_second_ld>(val);
    }
    constexpr picohertz_per_second_ld operator""_pinv_square_s(long double val) {
        return static_cast<picohertz_per_second_ld>(val);
    }
    constexpr femtohertz_per_second_ld operator""_finv_square_s(long double val) {
        return static_cast<femtohertz_per_second_ld>(val);
    }
    constexpr attohertz_per_second_ld operator""_ainv_square_s(long double val) {
        return static_cast<attohertz_per_second_ld>(val);
    }
    constexpr exahertz_per_second_ull operator""_Einv_square_s(unsigned long long val) {
        return static_cast<exahertz_per_second_ull>(val);
    }
    constexpr petahertz_per_second_ull operator""_Pinv_square_s(unsigned long long val) {
        return static_cast<petahertz_per_second_ull>(val);
    }
    constexpr terahertz_per_second_ull operator""_Tinv_square_s(unsigned long long val) {
        return static_cast<terahertz_per_second_ull>(val);
    }
    constexpr gigahertz_per_second_ull operator""_Ginv_square_s(unsigned long long val) {
        return static_cast<gigahertz_per_second_ull>(val);
    }
    constexpr megahertz_per_second_ull operator""_Minv_square_s(unsigned long long val) {
        return static_cast<megahertz_per_second_ull>(val);
    }
    constexpr kilohertz_per_second_ull operator""_kinv_square_s(unsigned long long val) {
        return static_cast<kilohertz_per_second_ull>(val);
    }
    constexpr hectohertz_per_second_ull operator""_hinv_square_s(unsigned long long val) {
        return static_cast<hectohertz_per_second_ull>(val);
    }
    constexpr decahertz_per_second_ull operator""_dainv_square_s(unsigned long long val) {
        return static_cast<decahertz_per_second_ull>(val);
    }
    constexpr hertz_per_second_ull operator""_inv_square_s(unsigned long long val) {
        return static_cast<hertz_per_second_ull>(val);
    }
    constexpr decihertz_per_second_ull operator""_dinv_square_s(unsigned long long val) {
        return static_cast<decihertz_per_second_ull>(val);
    }
    constexpr centihertz_per_second_ull operator""_cinv_square_s(unsigned long long val) {
        return static_cast<centihertz_per_second_ull>(val);
    }
    constexpr millihertz_per_second_ull operator""_minv_square_s(unsigned long long val) {
        return static_cast<millihertz_per_second_ull>(val);
    }
    constexpr microhertz_per_second_ull operator""_uinv_square_s(unsigned long long val) {
        return static_cast<microhertz_per_second_ull>(val);
    }
    constexpr nanohertz_per_second_ull operator""_ninv_square_s(unsigned long long val) {
        return static_cast<nanohertz_per_second_ull>(val);
    }
    constexpr picohertz_per_second_ull operator""_pinv_square_s(unsigned long long val) {
        return static_cast<picohertz_per_second_ull>(val);
    }
    constexpr femtohertz_per_second_ull operator""_finv_square_s(unsigned long long val) {
        return static_cast<femtohertz_per_second_ull>(val);
    }
    constexpr attohertz_per_second_ull operator""_ainv_square_s(unsigned long long val) {
        return static_cast<attohertz_per_second_ull>(val);
    }

} // namespace potato::units
