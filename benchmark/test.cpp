
#define ANKERL_NANOBENCH_IMPLEMENT
#include "nanobench.h"

import Pupple;
import Pupple.Algorithm;

import std.core;

int main() {
    ankerl::nanobench::Bench().run("Some tuple ops", [] {
        std::tuple d{1.0, 2, 3.0, 4, "names", "values", "gneves", 3, 'a'};
        ankerl::nanobench::doNotOptimizeAway(d);
    });

    ankerl::nanobench::Bench().run("Some pupple ops", [] {
        Tuple dd{1.0, 2, 3.0, 4, "names", "values", "gneves", 3, 'a'};
        ankerl::nanobench::doNotOptimizeAway(dd);
    });
}
