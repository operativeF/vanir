//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Gram_Per_Cubic_Meter;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using density_tag_t = tmp::list_<Length<std::ratio<-3, 1>>,
                                         Time<std::ratio<0, 1>>,
                                         Mass<std::ratio<1, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<0, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept Gram_Per_Cubic_MeterC = std::same_as<typename T::impl, density_tag_t>;

    template <typename RatioTypeT, typename P>
    struct gram_per_cubic_meter_impl {

        static constexpr auto pretty = "g/m³";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = density_tag_t;

        constexpr gram_per_cubic_meter_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exagram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::exa, long double>;
    using petagram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::peta, long double>;
    using teragram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::tera, long double>;
    using gigagram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::giga, long double>;
    using megagram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::mega, long double>;
    using kilogram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::kilo, long double>;
    using hectogram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::hecto, long double>;
    using decagram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::deca, long double>;
    using gram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<unity_ratio, long double>;
    using decigram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::deci, long double>;
    using centigram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::centi, long double>;
    using milligram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::milli, long double>;
    using microgram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::micro, long double>;
    using nanogram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::nano, long double>;
    using picogram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::pico, long double>;
    using femtogram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::femto, long double>;
    using attogram_per_cubic_meter_ld    =     gram_per_cubic_meter_impl<std::atto, long double>;
    using exagram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::exa, unsigned long long>;
    using petagram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::peta, unsigned long long>;
    using teragram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::tera, unsigned long long>;
    using gigagram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::giga, unsigned long long>;
    using megagram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::mega, unsigned long long>;
    using kilogram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::kilo, unsigned long long>;
    using hectogram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::hecto, unsigned long long>;
    using decagram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::deca, unsigned long long>;
    using gram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<unity_ratio, unsigned long long>;
    using decigram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::deci, unsigned long long>;
    using centigram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::centi, unsigned long long>;
    using milligram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::milli, unsigned long long>;
    using microgram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::micro, unsigned long long>;
    using nanogram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::nano, unsigned long long>;
    using picogram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::pico, unsigned long long>;
    using femtogram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::femto, unsigned long long>;
    using attogram_per_cubic_meter_ull    =     gram_per_cubic_meter_impl<std::atto, unsigned long long>;

    consteval exagram_per_cubic_meter_ld operator""_Eg_per_cubic_m(long double val) {
        return static_cast<exagram_per_cubic_meter_ld>(val);
    }
    consteval petagram_per_cubic_meter_ld operator""_Pg_per_cubic_m(long double val) {
        return static_cast<petagram_per_cubic_meter_ld>(val);
    }
    consteval teragram_per_cubic_meter_ld operator""_Tg_per_cubic_m(long double val) {
        return static_cast<teragram_per_cubic_meter_ld>(val);
    }
    consteval gigagram_per_cubic_meter_ld operator""_Gg_per_cubic_m(long double val) {
        return static_cast<gigagram_per_cubic_meter_ld>(val);
    }
    consteval megagram_per_cubic_meter_ld operator""_Mg_per_cubic_m(long double val) {
        return static_cast<megagram_per_cubic_meter_ld>(val);
    }
    consteval kilogram_per_cubic_meter_ld operator""_kg_per_cubic_m(long double val) {
        return static_cast<kilogram_per_cubic_meter_ld>(val);
    }
    consteval hectogram_per_cubic_meter_ld operator""_hg_per_cubic_m(long double val) {
        return static_cast<hectogram_per_cubic_meter_ld>(val);
    }
    consteval decagram_per_cubic_meter_ld operator""_dag_per_cubic_m(long double val) {
        return static_cast<decagram_per_cubic_meter_ld>(val);
    }
    consteval gram_per_cubic_meter_ld operator""_g_per_cubic_m(long double val) {
        return static_cast<gram_per_cubic_meter_ld>(val);
    }
    consteval decigram_per_cubic_meter_ld operator""_dg_per_cubic_m(long double val) {
        return static_cast<decigram_per_cubic_meter_ld>(val);
    }
    consteval centigram_per_cubic_meter_ld operator""_cg_per_cubic_m(long double val) {
        return static_cast<centigram_per_cubic_meter_ld>(val);
    }
    consteval milligram_per_cubic_meter_ld operator""_mg_per_cubic_m(long double val) {
        return static_cast<milligram_per_cubic_meter_ld>(val);
    }
    consteval microgram_per_cubic_meter_ld operator""_ug_per_cubic_m(long double val) {
        return static_cast<microgram_per_cubic_meter_ld>(val);
    }
    consteval nanogram_per_cubic_meter_ld operator""_ng_per_cubic_m(long double val) {
        return static_cast<nanogram_per_cubic_meter_ld>(val);
    }
    consteval picogram_per_cubic_meter_ld operator""_pg_per_cubic_m(long double val) {
        return static_cast<picogram_per_cubic_meter_ld>(val);
    }
    consteval femtogram_per_cubic_meter_ld operator""_fg_per_cubic_m(long double val) {
        return static_cast<femtogram_per_cubic_meter_ld>(val);
    }
    consteval attogram_per_cubic_meter_ld operator""_ag_per_cubic_m(long double val) {
        return static_cast<attogram_per_cubic_meter_ld>(val);
    }
    consteval exagram_per_cubic_meter_ull operator""_Eg_per_cubic_m(unsigned long long val) {
        return static_cast<exagram_per_cubic_meter_ull>(val);
    }
    consteval petagram_per_cubic_meter_ull operator""_Pg_per_cubic_m(unsigned long long val) {
        return static_cast<petagram_per_cubic_meter_ull>(val);
    }
    consteval teragram_per_cubic_meter_ull operator""_Tg_per_cubic_m(unsigned long long val) {
        return static_cast<teragram_per_cubic_meter_ull>(val);
    }
    consteval gigagram_per_cubic_meter_ull operator""_Gg_per_cubic_m(unsigned long long val) {
        return static_cast<gigagram_per_cubic_meter_ull>(val);
    }
    consteval megagram_per_cubic_meter_ull operator""_Mg_per_cubic_m(unsigned long long val) {
        return static_cast<megagram_per_cubic_meter_ull>(val);
    }
    consteval kilogram_per_cubic_meter_ull operator""_kg_per_cubic_m(unsigned long long val) {
        return static_cast<kilogram_per_cubic_meter_ull>(val);
    }
    consteval hectogram_per_cubic_meter_ull operator""_hg_per_cubic_m(unsigned long long val) {
        return static_cast<hectogram_per_cubic_meter_ull>(val);
    }
    consteval decagram_per_cubic_meter_ull operator""_dag_per_cubic_m(unsigned long long val) {
        return static_cast<decagram_per_cubic_meter_ull>(val);
    }
    consteval gram_per_cubic_meter_ull operator""_g_per_cubic_m(unsigned long long val) {
        return static_cast<gram_per_cubic_meter_ull>(val);
    }
    consteval decigram_per_cubic_meter_ull operator""_dg_per_cubic_m(unsigned long long val) {
        return static_cast<decigram_per_cubic_meter_ull>(val);
    }
    consteval centigram_per_cubic_meter_ull operator""_cg_per_cubic_m(unsigned long long val) {
        return static_cast<centigram_per_cubic_meter_ull>(val);
    }
    consteval milligram_per_cubic_meter_ull operator""_mg_per_cubic_m(unsigned long long val) {
        return static_cast<milligram_per_cubic_meter_ull>(val);
    }
    consteval microgram_per_cubic_meter_ull operator""_ug_per_cubic_m(unsigned long long val) {
        return static_cast<microgram_per_cubic_meter_ull>(val);
    }
    consteval nanogram_per_cubic_meter_ull operator""_ng_per_cubic_m(unsigned long long val) {
        return static_cast<nanogram_per_cubic_meter_ull>(val);
    }
    consteval picogram_per_cubic_meter_ull operator""_pg_per_cubic_m(unsigned long long val) {
        return static_cast<picogram_per_cubic_meter_ull>(val);
    }
    consteval femtogram_per_cubic_meter_ull operator""_fg_per_cubic_m(unsigned long long val) {
        return static_cast<femtogram_per_cubic_meter_ull>(val);
    }
    consteval attogram_per_cubic_meter_ull operator""_ag_per_cubic_m(unsigned long long val) {
        return static_cast<attogram_per_cubic_meter_ull>(val);
    }

} // namespace potato::units
