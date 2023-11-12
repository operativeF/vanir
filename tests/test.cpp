
import boost.ut;

namespace ut = boost::ut;

int main(int argc, char** argv)
{
    using namespace ut;

    const auto result = ut::cfg<ut::override>.run(
        { .report_errors = true });  // explicitly run registered test suites and report errors

    return 0;
}
