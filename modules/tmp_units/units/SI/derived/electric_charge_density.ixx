//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Unit.Coulomb_Per_Cubic_Meter;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;
export namespace potato::units {

    using electric_charge_density_tag_t = tmp::list_<Length<std::ratio<-3, 1>>,
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
    concept Coulomb_Per_Cubic_MeterC = std::same_as<typename T::impl, electric_charge_density_tag_t>;

    template <typename RatioTypeT, typename P>
    struct coulomb_per_cubic_meter_impl {

        static constexpr auto pretty = "C/m³";
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using impl       = electric_charge_density_tag_t;

        constexpr coulomb_per_cubic_meter_impl(value_type val) : value{val} {}

        using is_any_impl = tmp::false_;

        value_type value{};
    };

    using exacoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::exa, long double>;
    using petacoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::peta, long double>;
    using teracoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::tera, long double>;
    using gigacoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::giga, long double>;
    using megacoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::mega, long double>;
    using kilocoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::kilo, long double>;
    using hectocoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::hecto, long double>;
    using decacoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::deca, long double>;
    using coulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<unity_ratio, long double>;
    using decicoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::deci, long double>;
    using centicoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::centi, long double>;
    using millicoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::milli, long double>;
    using microcoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::micro, long double>;
    using nanocoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::nano, long double>;
    using picocoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::pico, long double>;
    using femtocoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::femto, long double>;
    using attocoulomb_per_cubic_meter_ld    =     coulomb_per_cubic_meter_impl<std::atto, long double>;
    using exacoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::exa, unsigned long long>;
    using petacoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::peta, unsigned long long>;
    using teracoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::tera, unsigned long long>;
    using gigacoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::giga, unsigned long long>;
    using megacoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::mega, unsigned long long>;
    using kilocoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::kilo, unsigned long long>;
    using hectocoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::hecto, unsigned long long>;
    using decacoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::deca, unsigned long long>;
    using coulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<unity_ratio, unsigned long long>;
    using decicoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::deci, unsigned long long>;
    using centicoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::centi, unsigned long long>;
    using millicoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::milli, unsigned long long>;
    using microcoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::micro, unsigned long long>;
    using nanocoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::nano, unsigned long long>;
    using picocoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::pico, unsigned long long>;
    using femtocoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::femto, unsigned long long>;
    using attocoulomb_per_cubic_meter_ull    =     coulomb_per_cubic_meter_impl<std::atto, unsigned long long>;

    consteval exacoulomb_per_cubic_meter_ld operator""_EC_per_cubic_m(long double val) {
        return static_cast<exacoulomb_per_cubic_meter_ld>(val);
    }
    consteval petacoulomb_per_cubic_meter_ld operator""_PC_per_cubic_m(long double val) {
        return static_cast<petacoulomb_per_cubic_meter_ld>(val);
    }
    consteval teracoulomb_per_cubic_meter_ld operator""_TC_per_cubic_m(long double val) {
        return static_cast<teracoulomb_per_cubic_meter_ld>(val);
    }
    consteval gigacoulomb_per_cubic_meter_ld operator""_GC_per_cubic_m(long double val) {
        return static_cast<gigacoulomb_per_cubic_meter_ld>(val);
    }
    consteval megacoulomb_per_cubic_meter_ld operator""_MC_per_cubic_m(long double val) {
        return static_cast<megacoulomb_per_cubic_meter_ld>(val);
    }
    consteval kilocoulomb_per_cubic_meter_ld operator""_kC_per_cubic_m(long double val) {
        return static_cast<kilocoulomb_per_cubic_meter_ld>(val);
    }
    consteval hectocoulomb_per_cubic_meter_ld operator""_hC_per_cubic_m(long double val) {
        return static_cast<hectocoulomb_per_cubic_meter_ld>(val);
    }
    consteval decacoulomb_per_cubic_meter_ld operator""_daC_per_cubic_m(long double val) {
        return static_cast<decacoulomb_per_cubic_meter_ld>(val);
    }
    consteval coulomb_per_cubic_meter_ld operator""_C_per_cubic_m(long double val) {
        return static_cast<coulomb_per_cubic_meter_ld>(val);
    }
    consteval decicoulomb_per_cubic_meter_ld operator""_dC_per_cubic_m(long double val) {
        return static_cast<decicoulomb_per_cubic_meter_ld>(val);
    }
    consteval centicoulomb_per_cubic_meter_ld operator""_cC_per_cubic_m(long double val) {
        return static_cast<centicoulomb_per_cubic_meter_ld>(val);
    }
    consteval millicoulomb_per_cubic_meter_ld operator""_mC_per_cubic_m(long double val) {
        return static_cast<millicoulomb_per_cubic_meter_ld>(val);
    }
    consteval microcoulomb_per_cubic_meter_ld operator""_uC_per_cubic_m(long double val) {
        return static_cast<microcoulomb_per_cubic_meter_ld>(val);
    }
    consteval nanocoulomb_per_cubic_meter_ld operator""_nC_per_cubic_m(long double val) {
        return static_cast<nanocoulomb_per_cubic_meter_ld>(val);
    }
    consteval picocoulomb_per_cubic_meter_ld operator""_pC_per_cubic_m(long double val) {
        return static_cast<picocoulomb_per_cubic_meter_ld>(val);
    }
    consteval femtocoulomb_per_cubic_meter_ld operator""_fC_per_cubic_m(long double val) {
        return static_cast<femtocoulomb_per_cubic_meter_ld>(val);
    }
    consteval attocoulomb_per_cubic_meter_ld operator""_aC_per_cubic_m(long double val) {
        return static_cast<attocoulomb_per_cubic_meter_ld>(val);
    }
    consteval exacoulomb_per_cubic_meter_ull operator""_EC_per_cubic_m(unsigned long long val) {
        return static_cast<exacoulomb_per_cubic_meter_ull>(val);
    }
    consteval petacoulomb_per_cubic_meter_ull operator""_PC_per_cubic_m(unsigned long long val) {
        return static_cast<petacoulomb_per_cubic_meter_ull>(val);
    }
    consteval teracoulomb_per_cubic_meter_ull operator""_TC_per_cubic_m(unsigned long long val) {
        return static_cast<teracoulomb_per_cubic_meter_ull>(val);
    }
    consteval gigacoulomb_per_cubic_meter_ull operator""_GC_per_cubic_m(unsigned long long val) {
        return static_cast<gigacoulomb_per_cubic_meter_ull>(val);
    }
    consteval megacoulomb_per_cubic_meter_ull operator""_MC_per_cubic_m(unsigned long long val) {
        return static_cast<megacoulomb_per_cubic_meter_ull>(val);
    }
    consteval kilocoulomb_per_cubic_meter_ull operator""_kC_per_cubic_m(unsigned long long val) {
        return static_cast<kilocoulomb_per_cubic_meter_ull>(val);
    }
    consteval hectocoulomb_per_cubic_meter_ull operator""_hC_per_cubic_m(unsigned long long val) {
        return static_cast<hectocoulomb_per_cubic_meter_ull>(val);
    }
    consteval decacoulomb_per_cubic_meter_ull operator""_daC_per_cubic_m(unsigned long long val) {
        return static_cast<decacoulomb_per_cubic_meter_ull>(val);
    }
    consteval coulomb_per_cubic_meter_ull operator""_C_per_cubic_m(unsigned long long val) {
        return static_cast<coulomb_per_cubic_meter_ull>(val);
    }
    consteval decicoulomb_per_cubic_meter_ull operator""_dC_per_cubic_m(unsigned long long val) {
        return static_cast<decicoulomb_per_cubic_meter_ull>(val);
    }
    consteval centicoulomb_per_cubic_meter_ull operator""_cC_per_cubic_m(unsigned long long val) {
        return static_cast<centicoulomb_per_cubic_meter_ull>(val);
    }
    consteval millicoulomb_per_cubic_meter_ull operator""_mC_per_cubic_m(unsigned long long val) {
        return static_cast<millicoulomb_per_cubic_meter_ull>(val);
    }
    consteval microcoulomb_per_cubic_meter_ull operator""_uC_per_cubic_m(unsigned long long val) {
        return static_cast<microcoulomb_per_cubic_meter_ull>(val);
    }
    consteval nanocoulomb_per_cubic_meter_ull operator""_nC_per_cubic_m(unsigned long long val) {
        return static_cast<nanocoulomb_per_cubic_meter_ull>(val);
    }
    consteval picocoulomb_per_cubic_meter_ull operator""_pC_per_cubic_m(unsigned long long val) {
        return static_cast<picocoulomb_per_cubic_meter_ull>(val);
    }
    consteval femtocoulomb_per_cubic_meter_ull operator""_fC_per_cubic_m(unsigned long long val) {
        return static_cast<femtocoulomb_per_cubic_meter_ull>(val);
    }
    consteval attocoulomb_per_cubic_meter_ull operator""_aC_per_cubic_m(unsigned long long val) {
        return static_cast<attocoulomb_per_cubic_meter_ull>(val);
    }

} // namespace potato::units
