
#include <boost/nowide/args.hpp>

import Nil.MetaTest;

namespace ut = boost::ut;

int main(int argc, char** argv)
{
    using namespace ut;

    boost::nowide::args a(argc, argv);

    const auto result = ut::cfg<ut::override>.run(
        { .report_errors = true });  // explicitly run registered test suites and report errors

    return result;
}
