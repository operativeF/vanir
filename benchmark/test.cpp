
#define ANKERL_NANOBENCH_IMPLEMENT
#include "nanobench.h"

import Pupple;
import Pupple.Algorithm;

import std.core;

static constexpr std::tuple cc_stda{"vectorman", 1.0, 2, 3.0, 4, "names", "values", "gneves", 3, 'a', 1, 2, 4, "larry the lobster"};
static constexpr std::tuple cc_stdb{"bubsy", 3.0, 5, 10.0, 99, "values", "genos", "pulses", 32, 'a', 7, 44, -10, "gary the snail"};

static constexpr Tuple cc_ppa{"vectorman", 1.0, 2, 3.0, 4, "names", "values", "gneves", 3, 'a', 1, 2, 4, "larry the lobster"};
static constexpr Tuple cc_ppb{"bubsy", 3.0, 5, 10.0, 99, "values", "genos", "pulses", 32, 'a', 7, 44, -10, "gary the snail"};

int main() {
    // tuple construction
    // Construction is done in place.
    ankerl::nanobench::Bench().run("std::tuple construction", [] {
        ankerl::nanobench::doNotOptimizeAway(std::tuple{"vectorman", 1.0, 2, 3.0, 4, "names", "values", "gneves", 3, 'a', 1, 2, 4, "larry the lobster"});
    });

    ankerl::nanobench::Bench().run("Tuple construction", [] {
        ankerl::nanobench::doNotOptimizeAway(Tuple{"vectorman", 1.0, 2, 3.0, 4, "names", "values", "gneves", 3, 'a', 1, 2, 4, "larry the lobster"});
    });

    // tuple swapping
    std::tuple aa{"vectorman", 1.0, 2, 3.0, 4, "names", "values", "gneves", 3, 'a', 1, 2, 4, "larry the lobster"};
    std::tuple bb{"bubsy", 3.0, 5, 10.0, 99, "values", "genos", "pulses", 32, 'a', 7, 44, -10, "gary the snail"};
    ankerl::nanobench::Bench().run("std::tuple swap", [&] {
        ankerl::nanobench::doNotOptimizeAway(aa);
        ankerl::nanobench::doNotOptimizeAway(bb);
        std::swap(aa, bb);
    });

    Tuple dd{"vectorman", 1.0, 2, 3.0, 4, "names", "values", "gneves", 3, 'a', 1, 2, 4, "larry the lobster"};
    Tuple ee{"bubsy", 3.0, 5, 10.0, 99, "values", "genos", "pulses", 32, 'a', 7, 44, -10, "gary the snail"};
    ankerl::nanobench::Bench().run("Tuple swap", [&] {
        ankerl::nanobench::doNotOptimizeAway(dd);
        ankerl::nanobench::doNotOptimizeAway(ee);
        swap(dd, ee);
    });

    // tuple concatenation
    // copies in static constexpr tuples to prevent benchmarking the construction
    // of said tuples.
    ankerl::nanobench::Bench().run("std::tuple concatenation", [=] {
        ankerl::nanobench::doNotOptimizeAway(std::tuple_cat(cc_stda, cc_stdb));
    });

    ankerl::nanobench::Bench().run("Tuple concatenation", [=] {
        ankerl::nanobench::doNotOptimizeAway(pupple_cat(cc_ppa, cc_ppb));
    });
}
