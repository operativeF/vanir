
import Nil.MetaTest;

import <iostream>;
import <sstream>;

namespace ut = boost::ut;

ut::suite newsuite = []
{
    using namespace ut;

    expect(1_i == 1_i);

    std::cout << "print";
};

int main(int argc, char** argv)
{
    using namespace ut;

    const auto result = ut::cfg<ut::override>.run(
        { .report_errors = true });  // explicitly run registered test suites and report errors

    return 0;
}
