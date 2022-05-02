
import Nil.MetaTest;

import Boost.TMP;

import Pupple;
import Pupple.Algorithm;

import fmt;

import std.core;
import std.memory;

namespace ut = boost::ut;
namespace tmp = boost::tmp;

ut::suite TestPuppleAppend = []
{
    using namespace ut;

    auto pupA = Tuple("first", 1);

    auto pupAB = append(pupA, "second", 2);

    const auto idealPupAppend = Tuple{"first", 1, "second", 2};

    expect(get<0>(pupAB) == "first");
    expect(get<1>(pupAB) == 1);
    expect(get<2>(pupAB) == "second");
    expect(get<3>(pupAB) == 2);

    "Test proper alignment order"_test = [=]
    {
        // Should be 24 bytes in size.
        expect(sizeof(pupAB) == 24);
    };
};

ut::suite SwapPupplesTest = []
{
    using namespace ut;

    const auto first  = Tuple{"first", 1};
    const auto second = Tuple{"second", 2};

    "specialized swap"_test = [=]
    {
        auto x = first;
        auto y = second;

        swap(x, y);

        expect(get<0>(x) == "second" && get<1>(x) == 2);
        expect(get<0>(y) == "first"  && get<1>(y) == 1);

        // Specialized swap shouldn't affect alignment / size.
        expect(sizeof(x) == sizeof(y)) << fmt::format("{} != {}", sizeof(x), sizeof(y));
    };

    "std::swap"_test = [=]
    {
        auto x = first;
        auto y = second;

        std::swap(x, y);

        expect(get<0>(x) == "second" && get<1>(x) == 2);
        expect(get<0>(y) == "first"  && get<1>(y) == 1);

        // Using std::swap shouldn't affect alignment / size.
        expect(sizeof(x) == sizeof(y)) << fmt::format("{} != {}", sizeof(x), sizeof(y));
    };
};

ut::suite ConcatPuppleTest = []
{
    using namespace ut;

    auto newtup = Tuple{'a', 1.0, 3};
    auto othertup = Tuple{'b', 2.0, 10};
    auto emptytup = Tuple{};

    auto cpptuple = std::tuple{'a', 1.0, 3};

    auto pcat = pupple_cat(newtup, othertup);
    auto ecat = pupple_cat(emptytup, othertup);
    // expect(sizeof(cpptuple) == 24) << fmt::format("{}", sizeof(cpptuple));
    expect(sizeof(newtup) == 16) << fmt::format("{}", sizeof(newtup));
    expect(sizeof(pcat) == 32) << fmt::format("{}", sizeof(newtup) + sizeof(othertup));
    expect(ecat == othertup);

    "Verify data alignments"_test = []
    {
        auto aligntup = Tuple{"first", 1, 2, "second"};
        auto aligned_actual = Tuple{"first", 1, 2, "second", "first", 1, 2, "second", "first", 1, 2, "second"};

        expect(sizeof(aligntup) == 24) << fmt::format("{} != 24", sizeof(aligntup));

        auto align3 = pupple_cat(aligntup, aligntup, aligntup);

        expect(sizeof(align3) == sizeof(aligned_actual)) << fmt::format("{} != {}", sizeof(align3), sizeof(aligned_actual));
    };
};

ut::suite ApplyPuppleTest = []
{
    using namespace ut;

    auto newtup = Tuple{1, 2};

    auto add_two = [](auto a, auto b){ return a + b; };

    auto added = tapply(add_two, newtup);

    expect(added == 3);
};
