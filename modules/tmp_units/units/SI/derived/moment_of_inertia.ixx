//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Gram_Square_Meter;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.BaseUnit;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename RatioTypeT, typename P>
    struct gram_square_meter_impl : base_unit_<RatioTypeT, P> {

        using base_unit_<RatioTypeT, P>::base_unit_;
        template <typename U, typename R>
        constexpr const gram_square_meter_impl<RatioTypeT, P>(const gram_square_meter_impl<U, R>& other) {
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

        static constexpr auto pretty = "kg·m²";

        using is_any_impl = false_;

        using mod_ratio = RatioTypeT;
        using numer_type = base_unit_<RatioTypeT, P>::value_type;
        using impl      = list_<list_<meter_l, meter_l, gram_l>, list_<>>;
    };

    using gram_square_exameter_ld    =     gram_square_meter_impl<std::exa, long double>;
    using gram_square_petameter_ld    =     gram_square_meter_impl<std::peta, long double>;
    using gram_square_terameter_ld    =     gram_square_meter_impl<std::tera, long double>;
    using gram_square_gigameter_ld    =     gram_square_meter_impl<std::giga, long double>;
    using gram_square_megameter_ld    =     gram_square_meter_impl<std::mega, long double>;
    using gram_square_kilometer_ld    =     gram_square_meter_impl<std::kilo, long double>;
    using gram_square_hectometer_ld    =     gram_square_meter_impl<std::hecto, long double>;
    using gram_square_decameter_ld    =     gram_square_meter_impl<std::deca, long double>;
    using gram_square_meter_ld    =     gram_square_meter_impl<unity_ratio, long double>;
    using gram_square_decimeter_ld    =     gram_square_meter_impl<std::deci, long double>;
    using gram_square_centimeter_ld    =     gram_square_meter_impl<std::centi, long double>;
    using gram_square_millimeter_ld    =     gram_square_meter_impl<std::milli, long double>;
    using gram_square_micrometer_ld    =     gram_square_meter_impl<std::micro, long double>;
    using gram_square_nanometer_ld    =     gram_square_meter_impl<std::nano, long double>;
    using gram_square_picometer_ld    =     gram_square_meter_impl<std::pico, long double>;
    using gram_square_femtometer_ld    =     gram_square_meter_impl<std::femto, long double>;
    using gram_square_attometer_ld    =     gram_square_meter_impl<std::atto, long double>;
    using gram_square_exameter_ull    =     gram_square_meter_impl<std::exa, unsigned long long>;
    using gram_square_petameter_ull    =     gram_square_meter_impl<std::peta, unsigned long long>;
    using gram_square_terameter_ull    =     gram_square_meter_impl<std::tera, unsigned long long>;
    using gram_square_gigameter_ull    =     gram_square_meter_impl<std::giga, unsigned long long>;
    using gram_square_megameter_ull    =     gram_square_meter_impl<std::mega, unsigned long long>;
    using gram_square_kilometer_ull    =     gram_square_meter_impl<std::kilo, unsigned long long>;
    using gram_square_hectometer_ull    =     gram_square_meter_impl<std::hecto, unsigned long long>;
    using gram_square_decameter_ull    =     gram_square_meter_impl<std::deca, unsigned long long>;
    using gram_square_meter_ull    =     gram_square_meter_impl<unity_ratio, unsigned long long>;
    using gram_square_decimeter_ull    =     gram_square_meter_impl<std::deci, unsigned long long>;
    using gram_square_centimeter_ull    =     gram_square_meter_impl<std::centi, unsigned long long>;
    using gram_square_millimeter_ull    =     gram_square_meter_impl<std::milli, unsigned long long>;
    using gram_square_micrometer_ull    =     gram_square_meter_impl<std::micro, unsigned long long>;
    using gram_square_nanometer_ull    =     gram_square_meter_impl<std::nano, unsigned long long>;
    using gram_square_picometer_ull    =     gram_square_meter_impl<std::pico, unsigned long long>;
    using gram_square_femtometer_ull    =     gram_square_meter_impl<std::femto, unsigned long long>;
    using gram_square_attometer_ull    =     gram_square_meter_impl<std::atto, unsigned long long>;

    constexpr gram_square_exameter_ld operator""_g_sq_Em(long double val) {
        return static_cast<gram_square_exameter_ld>(val);
    }
    constexpr gram_square_petameter_ld operator""_g_sq_Pm(long double val) {
        return static_cast<gram_square_petameter_ld>(val);
    }
    constexpr gram_square_terameter_ld operator""_g_sq_Tm(long double val) {
        return static_cast<gram_square_terameter_ld>(val);
    }
    constexpr gram_square_gigameter_ld operator""_g_sq_Gm(long double val) {
        return static_cast<gram_square_gigameter_ld>(val);
    }
    constexpr gram_square_megameter_ld operator""_g_sq_Mm(long double val) {
        return static_cast<gram_square_megameter_ld>(val);
    }
    constexpr gram_square_kilometer_ld operator""_g_sq_km(long double val) {
        return static_cast<gram_square_kilometer_ld>(val);
    }
    constexpr gram_square_hectometer_ld operator""_g_sq_hm(long double val) {
        return static_cast<gram_square_hectometer_ld>(val);
    }
    constexpr gram_square_decameter_ld operator""_g_sq_dam(long double val) {
        return static_cast<gram_square_decameter_ld>(val);
    }
    constexpr gram_square_meter_ld operator""_g_sq_m(long double val) {
        return static_cast<gram_square_meter_ld>(val);
    }
    constexpr gram_square_decimeter_ld operator""_g_sq_dm(long double val) {
        return static_cast<gram_square_decimeter_ld>(val);
    }
    constexpr gram_square_centimeter_ld operator""_g_sq_cm(long double val) {
        return static_cast<gram_square_centimeter_ld>(val);
    }
    constexpr gram_square_millimeter_ld operator""_g_sq_mm(long double val) {
        return static_cast<gram_square_millimeter_ld>(val);
    }
    constexpr gram_square_micrometer_ld operator""_g_sq_um(long double val) {
        return static_cast<gram_square_micrometer_ld>(val);
    }
    constexpr gram_square_nanometer_ld operator""_g_sq_nm(long double val) {
        return static_cast<gram_square_nanometer_ld>(val);
    }
    constexpr gram_square_picometer_ld operator""_g_sq_pm(long double val) {
        return static_cast<gram_square_picometer_ld>(val);
    }
    constexpr gram_square_femtometer_ld operator""_g_sq_fm(long double val) {
        return static_cast<gram_square_femtometer_ld>(val);
    }
    constexpr gram_square_attometer_ld operator""_g_sq_am(long double val) {
        return static_cast<gram_square_attometer_ld>(val);
    }
    constexpr gram_square_exameter_ull operator""_g_sq_Em(unsigned long long val) {
        return static_cast<gram_square_exameter_ull>(val);
    }
    constexpr gram_square_petameter_ull operator""_g_sq_Pm(unsigned long long val) {
        return static_cast<gram_square_petameter_ull>(val);
    }
    constexpr gram_square_terameter_ull operator""_g_sq_Tm(unsigned long long val) {
        return static_cast<gram_square_terameter_ull>(val);
    }
    constexpr gram_square_gigameter_ull operator""_g_sq_Gm(unsigned long long val) {
        return static_cast<gram_square_gigameter_ull>(val);
    }
    constexpr gram_square_megameter_ull operator""_g_sq_Mm(unsigned long long val) {
        return static_cast<gram_square_megameter_ull>(val);
    }
    constexpr gram_square_kilometer_ull operator""_g_sq_km(unsigned long long val) {
        return static_cast<gram_square_kilometer_ull>(val);
    }
    constexpr gram_square_hectometer_ull operator""_g_sq_hm(unsigned long long val) {
        return static_cast<gram_square_hectometer_ull>(val);
    }
    constexpr gram_square_decameter_ull operator""_g_sq_dam(unsigned long long val) {
        return static_cast<gram_square_decameter_ull>(val);
    }
    constexpr gram_square_meter_ull operator""_g_sq_m(unsigned long long val) {
        return static_cast<gram_square_meter_ull>(val);
    }
    constexpr gram_square_decimeter_ull operator""_g_sq_dm(unsigned long long val) {
        return static_cast<gram_square_decimeter_ull>(val);
    }
    constexpr gram_square_centimeter_ull operator""_g_sq_cm(unsigned long long val) {
        return static_cast<gram_square_centimeter_ull>(val);
    }
    constexpr gram_square_millimeter_ull operator""_g_sq_mm(unsigned long long val) {
        return static_cast<gram_square_millimeter_ull>(val);
    }
    constexpr gram_square_micrometer_ull operator""_g_sq_um(unsigned long long val) {
        return static_cast<gram_square_micrometer_ull>(val);
    }
    constexpr gram_square_nanometer_ull operator""_g_sq_nm(unsigned long long val) {
        return static_cast<gram_square_nanometer_ull>(val);
    }
    constexpr gram_square_picometer_ull operator""_g_sq_pm(unsigned long long val) {
        return static_cast<gram_square_picometer_ull>(val);
    }
    constexpr gram_square_femtometer_ull operator""_g_sq_fm(unsigned long long val) {
        return static_cast<gram_square_femtometer_ull>(val);
    }
    constexpr gram_square_attometer_ull operator""_g_sq_am(unsigned long long val) {
        return static_cast<gram_square_attometer_ull>(val);
    }

} // namespace potato::units
