
import Nil.MetaTest;

import Boost.TMP;

import Pupple.Element;
import Pupple.Map;

namespace ut = boost::ut;
namespace tmp = boost::tmp;

ut::suite VerifyMapConstruction = []
{
    using namespace ut;

    using elemA = pupple_element<tmp::int_<0>, int>;
    using elemB = pupple_element<tmp::int_<1>, double>;
    using elemC = pupple_element<tmp::int_<2>, int>;

    using idi_map = map<elemA, elemB, elemC>;

    using contains_key_zero = has_key<tmp::int_<0>, idi_map>;
    using does_not_contain_key_four = has_key<tmp::int_<4>, idi_map>;

    expect(contains_key_zero::value == true);
    expect(does_not_contain_key_four::value == false);
};

ut::suite MapDataAlignTest = []
{
    using namespace ut;

    struct point
    {
        double x{0.0};
        double y{0.0};
        double z{0.0};
    };

    using elemA = pupple_element<tmp::int_<0>, point>;
    using elemB = pupple_element<tmp::int_<1>, bool>;
    using elemC = pupple_element<tmp::int_<2>, int>;

    using tlist = tmp::list_<elemA, elemB, elemC>;

    elemC elem_c(100);
    elemB elem_b(true);
    elemA elem_a{point{10.1, 20.2, 30.3}};

    map<elemA, elemB, elemC> ABC_map(std::move(elem_a), std::move(elem_b), std::move(elem_c));

    expect(get<tmp::int_<1>>(ABC_map) != false);

    // MESSAGE("Total size of ABC_map is: " << sizeof(ABC_map) << " bytes.");

    elemC elem_d(100);
    elemB elem_e(true);
    elemA elem_f{point{10.1, 20.2, 30.3}};

    smap<tlist> new_map(std::move(elem_f), std::move(elem_d), std::move(elem_e));
};
