
import Nil.MetaTest;

import Boost.TMP;

import Boost.TMP.Units;
import Boost.TMP.Units.Engine.Evaluators;
import Boost.TMP.Units.Engine.Conversions;
import Boost.TMP.Units.Engine.Operators;
import Boost.TMP.Units.Engine.TypeDispatcher;
import Boost.TMP.Units.Engine.Base;

import fmt;

#ifdef __GNUC__
import <tuple>;
import <utility>;
#elif __clang__
import std;
#elif _MSC_VER
import std.core;
#endif

namespace ut = boost::ut;

ut::suite TmpUnitOperatorsTest = []
{
    using namespace ut;
    using namespace potato::units;

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

ut::suite TmpUnitNegativeOperations = []
{
    using namespace ut;
    using namespace potato::units;

    auto negative_one_mA = -1.0_mA;
    auto zero_mA = negative_one_mA + 1.0_mA;

    expect(zero_mA == 0.0_mA);

    auto n_one_mA = -1_mA;
    auto zero_mA_int = n_one_mA + 1_mA;

    expect(zero_mA_int == 0_mA);

    auto negative_volt = -1.0_mA * 1.0_kohm;

    expect(negative_volt == -1.0_V);
};