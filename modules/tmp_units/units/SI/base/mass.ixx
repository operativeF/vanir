//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Gram;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

export namespace potato::units {
    namespace tmp = boost::tmp;

    template <typename RatioTypeT, typename P>
    struct gram_impl {

        static constexpr auto pretty = "m";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;
        using impl       = tmp::list_<tmp::list_<gram_l>, tmp::list_<>>;

        constexpr gram_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exagram_ld    =     gram_impl<std::exa, long double>;
    using petagram_ld    =     gram_impl<std::peta, long double>;
    using teragram_ld    =     gram_impl<std::tera, long double>;
    using gigagram_ld    =     gram_impl<std::giga, long double>;
    using megagram_ld    =     gram_impl<std::mega, long double>;
    using kilogram_ld    =     gram_impl<std::kilo, long double>;
    using hectogram_ld    =     gram_impl<std::hecto, long double>;
    using decagram_ld    =     gram_impl<std::deca, long double>;
    using gram_ld    =     gram_impl<unity_ratio, long double>;
    using decigram_ld    =     gram_impl<std::deci, long double>;
    using centigram_ld    =     gram_impl<std::centi, long double>;
    using milligram_ld    =     gram_impl<std::milli, long double>;
    using microgram_ld    =     gram_impl<std::micro, long double>;
    using nanogram_ld    =     gram_impl<std::nano, long double>;
    using picogram_ld    =     gram_impl<std::pico, long double>;
    using femtogram_ld    =     gram_impl<std::femto, long double>;
    using attogram_ld    =     gram_impl<std::atto, long double>;
    using exagram_ull    =     gram_impl<std::exa, unsigned long long>;
    using petagram_ull    =     gram_impl<std::peta, unsigned long long>;
    using teragram_ull    =     gram_impl<std::tera, unsigned long long>;
    using gigagram_ull    =     gram_impl<std::giga, unsigned long long>;
    using megagram_ull    =     gram_impl<std::mega, unsigned long long>;
    using kilogram_ull    =     gram_impl<std::kilo, unsigned long long>;
    using hectogram_ull    =     gram_impl<std::hecto, unsigned long long>;
    using decagram_ull    =     gram_impl<std::deca, unsigned long long>;
    using gram_ull    =     gram_impl<unity_ratio, unsigned long long>;
    using decigram_ull    =     gram_impl<std::deci, unsigned long long>;
    using centigram_ull    =     gram_impl<std::centi, unsigned long long>;
    using milligram_ull    =     gram_impl<std::milli, unsigned long long>;
    using microgram_ull    =     gram_impl<std::micro, unsigned long long>;
    using nanogram_ull    =     gram_impl<std::nano, unsigned long long>;
    using picogram_ull    =     gram_impl<std::pico, unsigned long long>;
    using femtogram_ull    =     gram_impl<std::femto, unsigned long long>;
    using attogram_ull    =     gram_impl<std::atto, unsigned long long>;

    constexpr exagram_ld operator""_Eg(long double val) {
        return static_cast<exagram_ld>(val);
    }
    constexpr petagram_ld operator""_Pg(long double val) {
        return static_cast<petagram_ld>(val);
    }
    constexpr teragram_ld operator""_Tg(long double val) {
        return static_cast<teragram_ld>(val);
    }
    constexpr gigagram_ld operator""_Gg(long double val) {
        return static_cast<gigagram_ld>(val);
    }
    constexpr megagram_ld operator""_Mg(long double val) {
        return static_cast<megagram_ld>(val);
    }
    constexpr kilogram_ld operator""_kg(long double val) {
        return static_cast<kilogram_ld>(val);
    }
    constexpr hectogram_ld operator""_hg(long double val) {
        return static_cast<hectogram_ld>(val);
    }
    constexpr decagram_ld operator""_dag(long double val) {
        return static_cast<decagram_ld>(val);
    }
    constexpr gram_ld operator""_g(long double val) {
        return static_cast<gram_ld>(val);
    }
    constexpr decigram_ld operator""_dg(long double val) {
        return static_cast<decigram_ld>(val);
    }
    constexpr centigram_ld operator""_cg(long double val) {
        return static_cast<centigram_ld>(val);
    }
    constexpr milligram_ld operator""_mg(long double val) {
        return static_cast<milligram_ld>(val);
    }
    constexpr microgram_ld operator""_ug(long double val) {
        return static_cast<microgram_ld>(val);
    }
    constexpr nanogram_ld operator""_ng(long double val) {
        return static_cast<nanogram_ld>(val);
    }
    constexpr picogram_ld operator""_pg(long double val) {
        return static_cast<picogram_ld>(val);
    }
    constexpr femtogram_ld operator""_fg(long double val) {
        return static_cast<femtogram_ld>(val);
    }
    constexpr attogram_ld operator""_ag(long double val) {
        return static_cast<attogram_ld>(val);
    }
    constexpr exagram_ull operator""_Eg(unsigned long long val) {
        return static_cast<exagram_ull>(val);
    }
    constexpr petagram_ull operator""_Pg(unsigned long long val) {
        return static_cast<petagram_ull>(val);
    }
    constexpr teragram_ull operator""_Tg(unsigned long long val) {
        return static_cast<teragram_ull>(val);
    }
    constexpr gigagram_ull operator""_Gg(unsigned long long val) {
        return static_cast<gigagram_ull>(val);
    }
    constexpr megagram_ull operator""_Mg(unsigned long long val) {
        return static_cast<megagram_ull>(val);
    }
    constexpr kilogram_ull operator""_kg(unsigned long long val) {
        return static_cast<kilogram_ull>(val);
    }
    constexpr hectogram_ull operator""_hg(unsigned long long val) {
        return static_cast<hectogram_ull>(val);
    }
    constexpr decagram_ull operator""_dag(unsigned long long val) {
        return static_cast<decagram_ull>(val);
    }
    constexpr gram_ull operator""_g(unsigned long long val) {
        return static_cast<gram_ull>(val);
    }
    constexpr decigram_ull operator""_dg(unsigned long long val) {
        return static_cast<decigram_ull>(val);
    }
    constexpr centigram_ull operator""_cg(unsigned long long val) {
        return static_cast<centigram_ull>(val);
    }
    constexpr milligram_ull operator""_mg(unsigned long long val) {
        return static_cast<milligram_ull>(val);
    }
    constexpr microgram_ull operator""_ug(unsigned long long val) {
        return static_cast<microgram_ull>(val);
    }
    constexpr nanogram_ull operator""_ng(unsigned long long val) {
        return static_cast<nanogram_ull>(val);
    }
    constexpr picogram_ull operator""_pg(unsigned long long val) {
        return static_cast<picogram_ull>(val);
    }
    constexpr femtogram_ull operator""_fg(unsigned long long val) {
        return static_cast<femtogram_ull>(val);
    }
    constexpr attogram_ull operator""_ag(unsigned long long val) {
        return static_cast<attogram_ull>(val);
    }

} // namespace potato::units
