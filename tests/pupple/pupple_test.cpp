
import Nil.MetaTest;

import Boost.TMP;

import Pupple;
import Pupple.Algorithm;

import fmt;

import std.core;
import std.memory;

namespace ut = boost::ut;
namespace tmp = boost::tmp;

static_assert(std::is_trivially_constructible_v<Tuple<>>, "Empty Tuple should be trivially constructible.");
static_assert(std::is_nothrow_constructible_v<Tuple<>>, "Empty Tuple should be nothrow constructible.");


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

ut::suite TestPuppleElementTypes = []
{
    using namespace ut;

    auto pupA = Tuple{1, 2, 3};

    struct finalPup final
    {
        int a{};

        auto operator<=>(const finalPup&) const = default;
    };

    auto pupB = Tuple{finalPup{1}};
    auto pupC = Tuple{finalPup{3}};

    expect(pupB != pupC);
};

ut::suite TestPuppleStorageAlignment = []
{
    using namespace ut;
    
    Tuple<char, int, char, int, char, double, char> new_tupple{'a', 1, 'c', 3, 'd', 5.0, 'e'};
    // std::tuple<char, int, char, int, char, double, char> stdtuple{'a', 1, 'c', 3, 'd', 5.0, 'e'};

    auto aggregateTuple      = Tuple{'a', 1, 'c', 3, 'd', 5.0, 'e'};
    auto otherAggregateTuple = Tuple{'b', 2, 'd', 5, 'j', 1.0, 'f'};
    auto implicitAggregate   = Tuple{'c', 3, 'e', 7, 'k', 4.0, 'h'};

    auto nestedAggregate     = Tuple{std::array{1, 2}, std::array{3, 4, 5}};
    auto nestedTupleAgg      = Tuple{Tuple{1, 2}, Tuple{3, 4}};
    auto nestedTupleOther    = Tuple{Tuple{1, 2}, Tuple{3, 5}};

    std::string_view nals = "not a long string."; // 32 bytes
    auto simple_arr = std::array{1, 3}; // 2 bytes
    std::string_view utils = "utils"; // 6 bytes

    
    auto nestedTupleComplexAlignment = Tuple{Tuple{1.0, utils, 2, 'h'}, Tuple{nals, simple_arr}};

    expect(aggregateTuple == new_tupple);
    expect(otherAggregateTuple != aggregateTuple);
    expect(implicitAggregate != otherAggregateTuple);
    expect(nestedTupleAgg != nestedTupleOther);

    // Size of new_tupple will be 20 bytes + 4 bytes padding.
    expect(sizeof(new_tupple) == 24) << fmt::format("{}", sizeof(new_tupple));
    expect(sizeof(nestedTupleAgg) == 16) << fmt::format("{}", sizeof(nestedTupleAgg));
    expect(sizeof(nestedTupleComplexAlignment) == 56) << fmt::format("{}", sizeof(nestedTupleComplexAlignment));
    // fmt::print("Size of Pupple: {} bytes.\n", sizeof(new_tupple));
    // fmt::print("Size of std::tuple: {} bytes.\n", sizeof(stdtuple));

    auto pos = get<5>(new_tupple);
    expect(pos == 5.0);
};

ut::suite MakePuppleTest = []
{
    using namespace ut;

    auto tupleToMakeFrom = Tuple{1, "nil", 3.0};

    struct constrFromTuple
    {
        int aa{};
        std::string_view ss{};
        double dd{};
    };

    auto madeP = make_from_pupple<constrFromTuple>(tupleToMakeFrom);
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

ut::suite StructuredBindingPuppleTest = []
{
    using namespace ut;

    "Bind to copy"_test = []
    {
        auto newtup = Tuple{"first", 1};

        auto [a, b] = newtup;

        expect(a == "first" && b == 1);
    };

    "Bind to reference"_test = []
    {
        auto othertup = Tuple{"first", 1};

        auto& [c, d] = othertup;

        c = "second";
        d = 2;

        expect(get<0>(othertup) == "second" && get<1>(othertup) == 2);
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

constexpr Tuple<char, int, char, int, char, double, char> constexpr_tupple{'a', 1, 'c', 3, 'd', 5.0, 'e'};

static_assert(get<0>(constexpr_tupple) == 'a');
static_assert(get<1>(constexpr_tupple) == 1);
static_assert(get<2>(constexpr_tupple) == 'c');
static_assert(get<3>(constexpr_tupple) == 3);
static_assert(get<4>(constexpr_tupple) == 'd');
static_assert(get<5>(constexpr_tupple) == 5.0);
static_assert(get<6>(constexpr_tupple) == 'e');

// TEST_CASE("Test pupple after removing item for storage alignment.")
// { 
// }