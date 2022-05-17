//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Coulomb;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using electric_charge_tag_t = tmp::list_<Length<std::ratio<0, 1>>,
                                         Time<std::ratio<1, 1>>,
                                         Mass<std::ratio<0, 1>>,
                                         AmountOfSubstance<std::ratio<0, 1>>,
                                         ElectricCurrent<std::ratio<1, 1>>,
                                         ThermodynamicTemperature<std::ratio<0, 1>>,
                                         LuminousIntensity<std::ratio<0, 1>>,
                                         Radian<std::ratio<0, 1>>,
                                         Steradian<std::ratio<0, 1>>,
                                         Decay<std::ratio<0, 1>>>;

    template<typename T>
    concept CoulombC = std::same_as<typename T::impl, electric_charge_tag_t>;

    template <typename RatioTypeT, typename P>
    struct coulomb_impl {

        static constexpr auto pretty = "C";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = electric_charge_tag_t;

        constexpr coulomb_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exacoulomb_ld    =     coulomb_impl<std::exa, long double>;
    using petacoulomb_ld    =     coulomb_impl<std::peta, long double>;
    using teracoulomb_ld    =     coulomb_impl<std::tera, long double>;
    using gigacoulomb_ld    =     coulomb_impl<std::giga, long double>;
    using megacoulomb_ld    =     coulomb_impl<std::mega, long double>;
    using kilocoulomb_ld    =     coulomb_impl<std::kilo, long double>;
    using hectocoulomb_ld    =     coulomb_impl<std::hecto, long double>;
    using decacoulomb_ld    =     coulomb_impl<std::deca, long double>;
    using coulomb_ld    =     coulomb_impl<unity_ratio, long double>;
    using decicoulomb_ld    =     coulomb_impl<std::deci, long double>;
    using centicoulomb_ld    =     coulomb_impl<std::centi, long double>;
    using millicoulomb_ld    =     coulomb_impl<std::milli, long double>;
    using microcoulomb_ld    =     coulomb_impl<std::micro, long double>;
    using nanocoulomb_ld    =     coulomb_impl<std::nano, long double>;
    using picocoulomb_ld    =     coulomb_impl<std::pico, long double>;
    using femtocoulomb_ld    =     coulomb_impl<std::femto, long double>;
    using attocoulomb_ld    =     coulomb_impl<std::atto, long double>;
    using exacoulomb_ull    =     coulomb_impl<std::exa, unsigned long long>;
    using petacoulomb_ull    =     coulomb_impl<std::peta, unsigned long long>;
    using teracoulomb_ull    =     coulomb_impl<std::tera, unsigned long long>;
    using gigacoulomb_ull    =     coulomb_impl<std::giga, unsigned long long>;
    using megacoulomb_ull    =     coulomb_impl<std::mega, unsigned long long>;
    using kilocoulomb_ull    =     coulomb_impl<std::kilo, unsigned long long>;
    using hectocoulomb_ull    =     coulomb_impl<std::hecto, unsigned long long>;
    using decacoulomb_ull    =     coulomb_impl<std::deca, unsigned long long>;
    using coulomb_ull    =     coulomb_impl<unity_ratio, unsigned long long>;
    using decicoulomb_ull    =     coulomb_impl<std::deci, unsigned long long>;
    using centicoulomb_ull    =     coulomb_impl<std::centi, unsigned long long>;
    using millicoulomb_ull    =     coulomb_impl<std::milli, unsigned long long>;
    using microcoulomb_ull    =     coulomb_impl<std::micro, unsigned long long>;
    using nanocoulomb_ull    =     coulomb_impl<std::nano, unsigned long long>;
    using picocoulomb_ull    =     coulomb_impl<std::pico, unsigned long long>;
    using femtocoulomb_ull    =     coulomb_impl<std::femto, unsigned long long>;
    using attocoulomb_ull    =     coulomb_impl<std::atto, unsigned long long>;

    constexpr exacoulomb_ld operator""_EC(long double val) {
        return static_cast<exacoulomb_ld>(val);
    }
    constexpr petacoulomb_ld operator""_PC(long double val) {
        return static_cast<petacoulomb_ld>(val);
    }
    constexpr teracoulomb_ld operator""_TC(long double val) {
        return static_cast<teracoulomb_ld>(val);
    }
    constexpr gigacoulomb_ld operator""_GC(long double val) {
        return static_cast<gigacoulomb_ld>(val);
    }
    constexpr megacoulomb_ld operator""_MC(long double val) {
        return static_cast<megacoulomb_ld>(val);
    }
    constexpr kilocoulomb_ld operator""_kC(long double val) {
        return static_cast<kilocoulomb_ld>(val);
    }
    constexpr hectocoulomb_ld operator""_hC(long double val) {
        return static_cast<hectocoulomb_ld>(val);
    }
    constexpr decacoulomb_ld operator""_daC(long double val) {
        return static_cast<decacoulomb_ld>(val);
    }
    constexpr coulomb_ld operator""_C(long double val) {
        return static_cast<coulomb_ld>(val);
    }
    constexpr decicoulomb_ld operator""_dC(long double val) {
        return static_cast<decicoulomb_ld>(val);
    }
    constexpr centicoulomb_ld operator""_cC(long double val) {
        return static_cast<centicoulomb_ld>(val);
    }
    constexpr millicoulomb_ld operator""_mC(long double val) {
        return static_cast<millicoulomb_ld>(val);
    }
    constexpr microcoulomb_ld operator""_uC(long double val) {
        return static_cast<microcoulomb_ld>(val);
    }
    constexpr nanocoulomb_ld operator""_nC(long double val) {
        return static_cast<nanocoulomb_ld>(val);
    }
    constexpr picocoulomb_ld operator""_pC(long double val) {
        return static_cast<picocoulomb_ld>(val);
    }
    constexpr femtocoulomb_ld operator""_fC(long double val) {
        return static_cast<femtocoulomb_ld>(val);
    }
    constexpr attocoulomb_ld operator""_aC(long double val) {
        return static_cast<attocoulomb_ld>(val);
    }
    constexpr exacoulomb_ull operator""_EC(unsigned long long val) {
        return static_cast<exacoulomb_ull>(val);
    }
    constexpr petacoulomb_ull operator""_PC(unsigned long long val) {
        return static_cast<petacoulomb_ull>(val);
    }
    constexpr teracoulomb_ull operator""_TC(unsigned long long val) {
        return static_cast<teracoulomb_ull>(val);
    }
    constexpr gigacoulomb_ull operator""_GC(unsigned long long val) {
        return static_cast<gigacoulomb_ull>(val);
    }
    constexpr megacoulomb_ull operator""_MC(unsigned long long val) {
        return static_cast<megacoulomb_ull>(val);
    }
    constexpr kilocoulomb_ull operator""_kC(unsigned long long val) {
        return static_cast<kilocoulomb_ull>(val);
    }
    constexpr hectocoulomb_ull operator""_hC(unsigned long long val) {
        return static_cast<hectocoulomb_ull>(val);
    }
    constexpr decacoulomb_ull operator""_daC(unsigned long long val) {
        return static_cast<decacoulomb_ull>(val);
    }
    constexpr coulomb_ull operator""_C(unsigned long long val) {
        return static_cast<coulomb_ull>(val);
    }
    constexpr decicoulomb_ull operator""_dC(unsigned long long val) {
        return static_cast<decicoulomb_ull>(val);
    }
    constexpr centicoulomb_ull operator""_cC(unsigned long long val) {
        return static_cast<centicoulomb_ull>(val);
    }
    constexpr millicoulomb_ull operator""_mC(unsigned long long val) {
        return static_cast<millicoulomb_ull>(val);
    }
    constexpr microcoulomb_ull operator""_uC(unsigned long long val) {
        return static_cast<microcoulomb_ull>(val);
    }
    constexpr nanocoulomb_ull operator""_nC(unsigned long long val) {
        return static_cast<nanocoulomb_ull>(val);
    }
    constexpr picocoulomb_ull operator""_pC(unsigned long long val) {
        return static_cast<picocoulomb_ull>(val);
    }
    constexpr femtocoulomb_ull operator""_fC(unsigned long long val) {
        return static_cast<femtocoulomb_ull>(val);
    }
    constexpr attocoulomb_ull operator""_aC(unsigned long long val) {
        return static_cast<attocoulomb_ull>(val);
    }

} // namespace potato::units
