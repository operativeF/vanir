//  Copyright 2019 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

#include <cassert>
#include <limits>

#include <potato/engine/operators.hpp>

#include <potato/units/SI/base/electric_current.hpp>
#include <potato/units/SI/base/electromotive_force.hpp>
#include <potato/units/SI/base/length.hpp>
#include <potato/units/SI/base/resistance.hpp>

#include <potato/units/SI/derived/resistivity.hpp>

int main() {
    using namespace potato::units;

    constexpr auto ld_eps = std::numeric_limits<long double>::epsilon();

    // Basic functionality
    constexpr auto amp      = 1.0_A;
    constexpr auto two_amps = amp + amp;

    constexpr auto sq_amp    = 1.0_A * 1.0_A;
    constexpr auto unitless_ = 1.0_A / 1.0_A;

    constexpr auto still_an_amp = 1.0_A * 1.0_A / 1.0_A;

    constexpr auto still_an_amp_too =
            1.0_A + 1.0_A * 1.0_A / 1.0_A - 1.0_A +
            (1.0_A * 1.0_ohm + 1.0_A * 1.0_ohm * 1.0_V / (1.0_A * 1.0_ohm) - 1.0_V) / 1.0_ohm -
            1.0_A;

    static_assert((amp - 1.0_A).value < ld_eps, "");
    static_assert((two_amps - 2.0_A).value < ld_eps, "");
    //static_assert((unitless_ - 1.0) < ld_eps, "");
    static_assert((still_an_amp - 1.0_A).value < ld_eps, "");
    static_assert((still_an_amp_too - 1.0_A).value < ld_eps, "");

    constexpr auto one_volt  = 1.0_A * 1.0_ohm;
    constexpr auto two_volts = 1.0_A * 1.0_ohm + 1.0_ohm * 1.0_A;

    static_assert((one_volt - 1.0_V).value < ld_eps, "");
    static_assert((two_volts - 2.0_V).value < ld_eps, "");

    constexpr auto still_a_volt =
            1.0_A * 1.0_ohm + 1.0_A * 1.0_ohm * 1.0_V / (1.0_A * 1.0_ohm) - 1.0_V;

    static_assert((still_a_volt - 1.0_V).value < ld_eps, "");

    constexpr auto an_ohm_meter = 1.0_ohm * 1.0_m;

    constexpr auto im = 10.0_A;

    constexpr auto mim = 1.0_mA;

    constexpr milliampere_ull nin = 1_mA;
    constexpr auto nin_plus = 1_mA * 1_mA;
    constexpr kiloampere_ull nin_div = nin_plus / 1_nA;

    constexpr auto nim = 1_mA + 1_mA;
    constexpr auto non = -10_mA;
    constexpr auto nim2 = 10_mA + 1_A;

    constexpr auto test_ld_add = im + mim;
    constexpr auto test_ld_complex = 10.0_pA + 10.0_mA;
    constexpr auto test_ld_complex_2 = 1.0_pA + 1.0_nA;

    //static_assert(nim2 == 1010_mA, "Integer unit failure.");

    //constexpr exaampere   examim_plus = im +  mim;
    constexpr petaampere_ld  petamim_plus  = mim + im;
    constexpr teraampere_ld  teramim_plus  = im + mim;
    constexpr gigaampere_ld  gigamim_plus  = im + mim;
    constexpr megaampere_ld  megamim_plus  = im + mim;
    constexpr kiloampere_ld  kilomim_plus  = im + mim;
    constexpr hectoampere_ld hectomim_plus = im + mim;
    constexpr decaampere_ld  decamim_plus  = im + mim;
    constexpr ampere_ld      mim_plus      = im + mim;
    constexpr deciampere_ld  decimim_plus  = im + mim;
    constexpr centiampere_ld centimim_plus = im + mim;
    constexpr milliampere_ld millimim_plus = im + mim;
    constexpr microampere_ld micromim_plus = im + mim;
    constexpr nanoampere_ld  nanomim_plus  = im + mim;
    constexpr picoampere_ld  picomim_plus  = im + mim;
    constexpr femtoampere_ld femtomim_plus = im + mim;
    constexpr attoampere_ld  attomim_plus  = im + mim;

    constexpr auto test_ma_a = 1.0_A + 10.0_mA;

    // TODO: For integers that attempt to get converted up, it should throw a static_assert
    // as the value will otherwise get truncated.
    constexpr ampere_ull      ull_mim_plus      = nim; // Should assert!
    constexpr deciampere_ull  ull_decimim_plus  = nim; // Should assert!
    constexpr centiampere_ull ull_centimim_plus = nim; // Should assert!
    constexpr milliampere_ull ull_millimim_plus = nim + nim;
    constexpr microampere_ull ull_micromim_plus = nim + nim;
    constexpr nanoampere_ull  ull_nanomim_plus  = nim + nim;
    constexpr picoampere_ull  ull_picomim_plus  = nim + nim;
    constexpr femtoampere_ull ull_femtomim_plus = nim + nim;
    constexpr attoampere_ull  ull_attomim_plus  = nim + nim;

    return 0;
}
