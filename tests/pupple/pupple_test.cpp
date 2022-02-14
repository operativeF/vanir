
import Nil.MetaTest;

import Boost.TMP;
import Pupple;

import <algorithm>;
import <array>;
import <string>;
import <tuple>;

namespace ut = boost::ut;
namespace tmp = boost::tmp;

ut::suite PuppleCopyConstructors = []
{
    using namespace ut;

    "Empty template copy constructors."_test = []
    {
        pupple<> src;
        pupple<> dest(src);
        expect(src == dest);
    };

    "Template copy constructors."_test = []
    {
        pupple<int> src(100);
        pupple<int> dest(src);
        expect(src == dest);
    };

    "Template two value copy constructors."_test = []
    {
        pupple<int, int> src(100, 200);
        pupple<int, int> dest(src);
        // auto pp = pupple{pupple{2, 3}, pupple{400, 400}};

        expect(src == dest);
    };

    "Template two value (implicit conversion) copy constructors."_test = []
    {
        // This should fail. A better error message should be created for this.
        pupple<int, int> src(100, 200);
        //pupple<long, long> dest(src);

        //CHECK(src == dest);
    };
};

ut::suite TestPuppleConstruction = []
{
    auto new_pupple = pupple<int, int, int>(1, 2, 3);

    auto made_pupple = make_pupple(1, 2, 3);
};

ut::suite TestPuppleAppend = []
{
    using namespace ut;

    auto pupA = make_pupple(1, 2, 3);
    auto pupB = make_pupple(4, 5, 6);

    auto pup_AB_append = append(pupA, 1, 2, pupple<int>(1));

    expect(get<0>(pup_AB_append) == 1);
    expect(get<1>(pup_AB_append) == 2);
    expect(get<2>(pup_AB_append) == 3);
    expect(get<5>(pup_AB_append) == pupple<int>(1));
};

ut::suite TestPuppleElementTypes = []
{
    using namespace ut;

    auto pupA = make_pupple(1, 2, 3);

    struct finalPup final
    {
        int a{};

        auto operator<=>(const finalPup&) const = default;
    };

    auto pupB = make_pupple(finalPup{1});
    auto pupC = make_pupple(finalPup{3});

    expect(pupB != pupC);
};

ut::suite TestPuppleStorageAlignment = []
{
    using namespace ut;
    
    Tuple<char, int, char, int, char, double, char> new_tupple{'a', 1, 'c', 3, 'd', 5.0, 'e'};
    std::tuple<char, int, char, int, char, double, char> stdtuple{'a', 1, 'c', 3, 'd', 5.0, 'e'};

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