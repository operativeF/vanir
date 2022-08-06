
import Nil.MetaTest;

import Boost.TMP.Units;

namespace ut = boost::ut;

using namespace potato::units;

constexpr auto getVoltageDrop(OhmC auto resistance, AmpereC auto current)
{
    return resistance * current;
}

static constexpr auto vd_across = getVoltageDrop(10.0_ohm, 1.0_A);

static_assert(vd_across == 10.0_V);

ut::suite TmpUnitOperationsTests = []
{
    using namespace ut;
    using namespace potato::units;

    "Comparison Operators"_test = [&]
    {   
        auto two_mA = 1.0_ohm * 1.0_mA;

        expect(two_mA == 1.0_mV);
        expect(two_mA == 0.001_V);
        expect(two_mA == 1000.0_uV);

        auto one_mA = 1_V / 1.0_kohm;
        expect(one_mA == 1.0_mA);

        auto less_than_one_mA = 1.0_V / 10.0_kohm;
        expect(one_mA > less_than_one_mA);

        expect(100_pA < 1000_mA);
        expect(10_A > 10000_nA);
        expect(10.0_pA != 10.1_pA);
    };

    "Negation Operators"_test = [&]
    {
        auto neg_one_volt = -1.0_V;

        // Binary negation operations
        expect(neg_one_volt * (-1) == 1.0_V);
        expect((-1) * neg_one_volt == 1.0_V);

        // Unary negation operations
        expect(-neg_one_volt == 1.0_V);
        expect(-(-neg_one_volt) == -1.0_V);
    };

    "Binary Math Operators"_test = [&]
    {
        auto neg_one_volt = -1.0_V;
        auto pos_one_volt = 1.0_V;

        expect((neg_one_volt + pos_one_volt) == 0.0_V);
        expect((neg_one_volt + neg_one_volt) == -2.0_V);

        expect((neg_one_volt - neg_one_volt)   == 0.0_V);
        expect((neg_one_volt - -neg_one_volt)  == -2.0_V);
        expect((-neg_one_volt - -neg_one_volt) == 0.0_V);

        expect((neg_one_volt * pos_one_volt) / (neg_one_volt) ==  1.0_V);

        expect((neg_one_volt * neg_one_volt) / (neg_one_volt) == -1.0_V);
        expect((neg_one_volt * pos_one_volt) / (pos_one_volt) == -1.0_V);

        expect(-(neg_one_volt * pos_one_volt) / (neg_one_volt)  == -1.0_V);
        expect( (neg_one_volt * pos_one_volt) / -(neg_one_volt) == -1.0_V);

        // Multiply by inverse
        expect((1 / neg_one_volt) * (pos_one_volt * pos_one_volt) == -1.0_V);
        expect((-1 / neg_one_volt) * (pos_one_volt * pos_one_volt) == 1.0_V);
        expect((pos_one_volt * pos_one_volt) * (1 / neg_one_volt) == -1.0_V);
        expect((pos_one_volt * pos_one_volt) * (-1 / neg_one_volt) == 1.0_V);

        expect((1 / (1 / neg_one_volt)) == -1.0_V);
    };

    "Addition Ops on Scaled Units"_test = [&]
    {
        auto one_millivolt = 1.0_mV;
        auto one_volt = 1.0_V;
        auto one_kilovolt = 1.0_kV;
        auto one_microvolt = 1.0_uV;

        auto one_mV_V = (one_millivolt + one_volt);
        auto one_V_mV = (one_volt + one_millivolt);

        auto one_kV_V = (one_kilovolt + one_volt);
        auto one_V_kV = (one_volt + one_kilovolt);

        auto one_mV_uV = (one_millivolt + one_microvolt);
        auto one_uV_mV = (one_microvolt + one_millivolt);

        auto one_mV_kV = (one_millivolt + one_kilovolt);
        auto one_kV_mV = (one_kilovolt + one_millivolt);

        expect(one_mV_V == 1.001_V) << one_mV_V.value;
        expect(one_V_mV == 1.001_V) << one_V_mV.value;

        expect(one_kV_V == 1.001_kV) << one_kV_V.value;
        expect(one_V_kV == 1.001_kV) << one_V_kV.value;

        expect(one_mV_uV == 1.001_mV) << one_mV_uV.value;
        expect(one_uV_mV == 1.001_mV) << one_mV_uV.value;

        expect(one_mV_kV == 1.000001_kV) << one_mV_kV.value;
        expect(one_kV_mV == 1.000001_kV) << one_kV_mV.value;
    };

    "Subtraction Ops on Scaled Units"_test = [&]
    {
        auto one_millivolt = 1.0_mV;
        auto one_volt = 1.0_V;
        auto one_kilovolt = 1.0_kV;
        auto one_microvolt = 1.0_uV;

        auto one_V_minus_one_mV = one_volt - one_millivolt;
        auto one_mV_minus_one_V = one_millivolt - one_volt;
        auto one_kV_minus_one_V = one_kilovolt - one_volt;
        auto one_V_minus_one_kV = one_volt - one_kilovolt;

        expect(one_V_minus_one_mV == 0.999_V) << one_V_minus_one_mV.value;
        expect(one_mV_minus_one_V == -0.999_V) << one_mV_minus_one_V.value;
        expect(one_kV_minus_one_V == 999.0_V) << one_kV_minus_one_V.value;
        expect(one_V_minus_one_kV == -999.0_V) << one_V_minus_one_kV.value;
    };

    "Operations Resulting in Conversions"_test = [&]
    {
        auto vd = getVoltageDrop(1.0_ohm, 1.0_A);

        expect(vd == 1.0_V);
    };
};
