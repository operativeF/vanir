
import Nil.MetaTest;

import fmt;

namespace ut = boost::ut;

ut::suite newsuite = []
{
    using namespace ut;

    expect(1_i == 1_i);

    fmt::print("{}", detail::eq_{1, 2});
};

int main(int argc, char** argv)
{
    using namespace ut;

    const auto result = ut::cfg<ut::override>.run(
        { .report_errors = true });  // explicitly run registered test suites and report errors

    return 0;
}
