
#define ANKERL_NANOBENCH_IMPLEMENT
#include "nanobench.h"

import Pupple;
import Pupple.Algorithm;

import std.core;

int main() {
    ankerl::nanobench::Bench().run("std::tuple construction", [] {
        std::tuple d{"vectorman", 1.0, 2, 3.0, 4, "names", "values", "gneves", 3, 'a', 1, 2, 4, "larry the lobster"};
        ankerl::nanobench::doNotOptimizeAway(d);
    });

    ankerl::nanobench::Bench().run("Tuple construction", [] {
        Tuple dd{"vectorman", 1.0, 2, 3.0, 4, "names", "values", "gneves", 3, 'a', 1, 2, 4, "larry the lobster"};
        ankerl::nanobench::doNotOptimizeAway(dd);
    });

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

    std::tuple cc_stda{"vectorman", 1.0, 2, 3.0, 4, "names", "values", "gneves", 3, 'a', 1, 2, 4, "larry the lobster"};
    std::tuple cc_stdb{"bubsy", 3.0, 5, 10.0, 99, "values", "genos", "pulses", 32, 'a', 7, 44, -10, "gary the snail"};
    ankerl::nanobench::Bench().run("std::tuple concatenation", [&] {
        ankerl::nanobench::doNotOptimizeAway(cc_stda);
        ankerl::nanobench::doNotOptimizeAway(cc_stdb);
        auto stdpupcat = std::tuple_cat(cc_stda, cc_stdb);

        ankerl::nanobench::doNotOptimizeAway(stdpupcat);
    });

    Tuple cc_ppa{"vectorman", 1.0, 2, 3.0, 4, "names", "values", "gneves", 3, 'a', 1, 2, 4, "larry the lobster"};
    Tuple cc_ppb{"bubsy", 3.0, 5, 10.0, 99, "values", "genos", "pulses", 32, 'a', 7, 44, -10, "gary the snail"};
    ankerl::nanobench::Bench().run("Tuple concatenation", [&] {
        ankerl::nanobench::doNotOptimizeAway(cc_ppa);
        ankerl::nanobench::doNotOptimizeAway(cc_ppb);

        auto pupcat = pupple_cat(cc_ppa, cc_ppb);

        ankerl::nanobench::doNotOptimizeAway(pupcat);
    });
}
