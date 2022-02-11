
import Nil.MetaTest;

import Boost.TMP;

import Pupple.Element;

namespace tmp = boost::tmp;

namespace ut = boost::ut;

ut::suite TestElementFunctions = []
{
    using namespace ut;

    pupple_element<tmp::int_<1>, int> get_integer(100);
    expect(get<tmp::int_<1>>(get_integer) == 100);

    const pupple_element<tmp::int_<2>, int> get_const_integer(100);
    expect(get<tmp::int_<2>>(get_const_integer) == 100);

    pupple_element<tmp::int_<3>, int> get_rvalue_integer(100);
    expect(get<tmp::int_<3>>(std::move(get_rvalue_integer)) == 100);
};

ut::suite TestElementComparisonOps = []
{
    using namespace ut;
    
    pupple_element<tmp::int_<1>, int> integer_A(100);
    pupple_element<tmp::int_<2>, int> integer_B(200);
    pupple_element<tmp::int_<3>, int> integer_C(100);

    pupple_element<tmp::uint_<1>, int> same_value_different_key_type(100);
    pupple_element<tmp::int_<1>, unsigned> same_value_implicit_conv_type(100);

    expect(integer_A != integer_B);
    expect(integer_A == integer_C);

    expect(integer_A == same_value_different_key_type);
    expect(integer_A == same_value_implicit_conv_type);

    expect(integer_A < integer_B);
    expect(integer_B > integer_A);

    expect(integer_A <= integer_C);
    expect(integer_B >= integer_C);
};
