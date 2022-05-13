
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

    auto twoma = 1.0_ohm * 1.0_mA;

    expect(twoma == 1.0_mV);
};