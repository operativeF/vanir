
import Nil.MetaTest;

import Boost.TMP;

import Pupple.Element;

#ifdef __GNUC__
import <type_traits>;
#elif __clang__
import std;
#elif _MSC_VER
import std.core;
#endif

namespace tmp = boost::tmp;

namespace ut = boost::ut;

ut::suite ElementGetTest = []
{
    using namespace ut;

    pupple_element<1, int> get_integer{100};
    expect(get<1>(get_integer) == 100);

    const pupple_element<2, int> get_const_integer{100};
    expect(get<2>(get_const_integer) == 100);

    pupple_element<3, int> get_rvalue_integer{100};
    expect(get<3>(std::move(get_rvalue_integer)) == 100);
};

ut::suite ElementComparisonsTest = []
{
    using namespace ut;
    
    pupple_element<1, int> integer_A(100);
    pupple_element<2, int> integer_B(200);
    pupple_element<3, int> integer_C(100);

    pupple_element<1, int> same_value_different_key_type(100);
    pupple_element<1, unsigned> same_value_implicit_conv_type(100u);

    expect(integer_A != integer_B);
    expect(integer_A == integer_C);

    expect(integer_A == same_value_different_key_type);
    expect(integer_A == same_value_implicit_conv_type);

    expect(integer_A < integer_B);
    expect(integer_B > integer_A);

    expect(integer_A <= integer_C);
    expect(integer_B >= integer_C);
};

ut::suite ElementConstructTest = []
{
    using namespace ut;

    "Copy-construct from other element"_test = []
    {
        pupple_element<1, int> integer_A{1};
        
        auto integer_B = integer_A;

        auto integer_C{integer_A};

        expect(integer_A == integer_B);
        expect(integer_C == integer_A);
    };

    "Construction in-place"_test = []
    {
        struct NonMoveAndCopy
        {
            NonMoveAndCopy(int aa) : a{aa} {}
            NonMoveAndCopy(const NonMoveAndCopy&) = delete;
            NonMoveAndCopy& operator=(const NonMoveAndCopy&) = delete;
            NonMoveAndCopy& operator=(NonMoveAndCopy&&) = delete;
            NonMoveAndCopy(NonMoveAndCopy&&) = delete;

            auto operator<=>(const NonMoveAndCopy&) const = default;

            int a;
        };

        pupple_element<1, NonMoveAndCopy> nmac{1};
    };

    "Explicit construction"_test = []
    {
        struct ExpConstruct
        {
            constexpr ExpConstruct() = default;

            explicit constexpr ExpConstruct(unsigned int val)
                : a{val}
            {
            }

            unsigned int a;
        };

        // Will not compile:
        //pupple_element<1, ExpConstruct> erroneous{1};

        pupple_element<1, ExpConstruct> nmac{ExpConstruct{1}};
    };
};

