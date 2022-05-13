//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Gray_Per_Second;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.BaseUnit;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename RatioTypeT, typename P>
    struct gray_per_second_impl : base_unit_<RatioTypeT, P> {

        using base_unit_<RatioTypeT, P>::base_unit_;
        template <typename U, typename R>
        constexpr const gray_per_second_impl<RatioTypeT, P>(const gray_per_second_impl<U, R>& other) {
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

        static constexpr auto pretty = "Gy/s";

        using is_any_impl = false_;

        using mod_ratio = RatioTypeT;
        using numer_type = base_unit_<RatioTypeT, P>::value_type;
        using impl      = list_<list_<meter_l, meter_l>, list_<second_l, second_l, second_l>>;
    };

    using exagray_per_second_ld    =     gray_per_second_impl<std::exa, long double>;
    using petagray_per_second_ld    =     gray_per_second_impl<std::peta, long double>;
    using teragray_per_second_ld    =     gray_per_second_impl<std::tera, long double>;
    using gigagray_per_second_ld    =     gray_per_second_impl<std::giga, long double>;
    using megagray_per_second_ld    =     gray_per_second_impl<std::mega, long double>;
    using kilogray_per_second_ld    =     gray_per_second_impl<std::kilo, long double>;
    using hectogray_per_second_ld    =     gray_per_second_impl<std::hecto, long double>;
    using decagray_per_second_ld    =     gray_per_second_impl<std::deca, long double>;
    using gray_per_second_ld    =     gray_per_second_impl<unity_ratio, long double>;
    using decigray_per_second_ld    =     gray_per_second_impl<std::deci, long double>;
    using centigray_per_second_ld    =     gray_per_second_impl<std::centi, long double>;
    using milligray_per_second_ld    =     gray_per_second_impl<std::milli, long double>;
    using microgray_per_second_ld    =     gray_per_second_impl<std::micro, long double>;
    using nanogray_per_second_ld    =     gray_per_second_impl<std::nano, long double>;
    using picogray_per_second_ld    =     gray_per_second_impl<std::pico, long double>;
    using femtogray_per_second_ld    =     gray_per_second_impl<std::femto, long double>;
    using attogray_per_second_ld    =     gray_per_second_impl<std::atto, long double>;
    using exagray_per_second_ull    =     gray_per_second_impl<std::exa, unsigned long long>;
    using petagray_per_second_ull    =     gray_per_second_impl<std::peta, unsigned long long>;
    using teragray_per_second_ull    =     gray_per_second_impl<std::tera, unsigned long long>;
    using gigagray_per_second_ull    =     gray_per_second_impl<std::giga, unsigned long long>;
    using megagray_per_second_ull    =     gray_per_second_impl<std::mega, unsigned long long>;
    using kilogray_per_second_ull    =     gray_per_second_impl<std::kilo, unsigned long long>;
    using hectogray_per_second_ull    =     gray_per_second_impl<std::hecto, unsigned long long>;
    using decagray_per_second_ull    =     gray_per_second_impl<std::deca, unsigned long long>;
    using gray_per_second_ull    =     gray_per_second_impl<unity_ratio, unsigned long long>;
    using decigray_per_second_ull    =     gray_per_second_impl<std::deci, unsigned long long>;
    using centigray_per_second_ull    =     gray_per_second_impl<std::centi, unsigned long long>;
    using milligray_per_second_ull    =     gray_per_second_impl<std::milli, unsigned long long>;
    using microgray_per_second_ull    =     gray_per_second_impl<std::micro, unsigned long long>;
    using nanogray_per_second_ull    =     gray_per_second_impl<std::nano, unsigned long long>;
    using picogray_per_second_ull    =     gray_per_second_impl<std::pico, unsigned long long>;
    using femtogray_per_second_ull    =     gray_per_second_impl<std::femto, unsigned long long>;
    using attogray_per_second_ull    =     gray_per_second_impl<std::atto, unsigned long long>;

    constexpr exagray_per_second_ld operator""_EGy_per_s(long double val) {
        return static_cast<exagray_per_second_ld>(val);
    }
    constexpr petagray_per_second_ld operator""_PGy_per_s(long double val) {
        return static_cast<petagray_per_second_ld>(val);
    }
    constexpr teragray_per_second_ld operator""_TGy_per_s(long double val) {
        return static_cast<teragray_per_second_ld>(val);
    }
    constexpr gigagray_per_second_ld operator""_GGy_per_s(long double val) {
        return static_cast<gigagray_per_second_ld>(val);
    }
    constexpr megagray_per_second_ld operator""_MGy_per_s(long double val) {
        return static_cast<megagray_per_second_ld>(val);
    }
    constexpr kilogray_per_second_ld operator""_kGy_per_s(long double val) {
        return static_cast<kilogray_per_second_ld>(val);
    }
    constexpr hectogray_per_second_ld operator""_hGy_per_s(long double val) {
        return static_cast<hectogray_per_second_ld>(val);
    }
    constexpr decagray_per_second_ld operator""_daGy_per_s(long double val) {
        return static_cast<decagray_per_second_ld>(val);
    }
    constexpr gray_per_second_ld operator""_Gy_per_s(long double val) {
        return static_cast<gray_per_second_ld>(val);
    }
    constexpr decigray_per_second_ld operator""_dGy_per_s(long double val) {
        return static_cast<decigray_per_second_ld>(val);
    }
    constexpr centigray_per_second_ld operator""_cGy_per_s(long double val) {
        return static_cast<centigray_per_second_ld>(val);
    }
    constexpr milligray_per_second_ld operator""_mGy_per_s(long double val) {
        return static_cast<milligray_per_second_ld>(val);
    }
    constexpr microgray_per_second_ld operator""_uGy_per_s(long double val) {
        return static_cast<microgray_per_second_ld>(val);
    }
    constexpr nanogray_per_second_ld operator""_nGy_per_s(long double val) {
        return static_cast<nanogray_per_second_ld>(val);
    }
    constexpr picogray_per_second_ld operator""_pGy_per_s(long double val) {
        return static_cast<picogray_per_second_ld>(val);
    }
    constexpr femtogray_per_second_ld operator""_fGy_per_s(long double val) {
        return static_cast<femtogray_per_second_ld>(val);
    }
    constexpr attogray_per_second_ld operator""_aGy_per_s(long double val) {
        return static_cast<attogray_per_second_ld>(val);
    }
    constexpr exagray_per_second_ull operator""_EGy_per_s(unsigned long long val) {
        return static_cast<exagray_per_second_ull>(val);
    }
    constexpr petagray_per_second_ull operator""_PGy_per_s(unsigned long long val) {
        return static_cast<petagray_per_second_ull>(val);
    }
    constexpr teragray_per_second_ull operator""_TGy_per_s(unsigned long long val) {
        return static_cast<teragray_per_second_ull>(val);
    }
    constexpr gigagray_per_second_ull operator""_GGy_per_s(unsigned long long val) {
        return static_cast<gigagray_per_second_ull>(val);
    }
    constexpr megagray_per_second_ull operator""_MGy_per_s(unsigned long long val) {
        return static_cast<megagray_per_second_ull>(val);
    }
    constexpr kilogray_per_second_ull operator""_kGy_per_s(unsigned long long val) {
        return static_cast<kilogray_per_second_ull>(val);
    }
    constexpr hectogray_per_second_ull operator""_hGy_per_s(unsigned long long val) {
        return static_cast<hectogray_per_second_ull>(val);
    }
    constexpr decagray_per_second_ull operator""_daGy_per_s(unsigned long long val) {
        return static_cast<decagray_per_second_ull>(val);
    }
    constexpr gray_per_second_ull operator""_Gy_per_s(unsigned long long val) {
        return static_cast<gray_per_second_ull>(val);
    }
    constexpr decigray_per_second_ull operator""_dGy_per_s(unsigned long long val) {
        return static_cast<decigray_per_second_ull>(val);
    }
    constexpr centigray_per_second_ull operator""_cGy_per_s(unsigned long long val) {
        return static_cast<centigray_per_second_ull>(val);
    }
    constexpr milligray_per_second_ull operator""_mGy_per_s(unsigned long long val) {
        return static_cast<milligray_per_second_ull>(val);
    }
    constexpr microgray_per_second_ull operator""_uGy_per_s(unsigned long long val) {
        return static_cast<microgray_per_second_ull>(val);
    }
    constexpr nanogray_per_second_ull operator""_nGy_per_s(unsigned long long val) {
        return static_cast<nanogray_per_second_ull>(val);
    }
    constexpr picogray_per_second_ull operator""_pGy_per_s(unsigned long long val) {
        return static_cast<picogray_per_second_ull>(val);
    }
    constexpr femtogray_per_second_ull operator""_fGy_per_s(unsigned long long val) {
        return static_cast<femtogray_per_second_ull>(val);
    }
    constexpr attogray_per_second_ull operator""_aGy_per_s(unsigned long long val) {
        return static_cast<attogray_per_second_ull>(val);
    }

} // namespace potato::units
