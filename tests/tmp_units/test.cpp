//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

import Boost.TMP.Units;
import Boost.TMP.Units.Engine.Evaluators;
import Boost.TMP.Units.Engine.Conversions;
import Boost.TMP.Units.Engine.Operators;
import Boost.TMP.Units.Engine.TypeDispatcher;
import Boost.TMP.Units.Engine.Base;

import std.core;

import Nil.MetaTest;

import fmt;

namespace ut = boost::ut;

int main(int argc, char** argv)
{
    using namespace ut;

    const auto result = ut::cfg<ut::override>.run(
        { .report_errors = true });  // explicitly run registered test suites and report errors

    return 0;
}
