//  Copyright 2018-2019 Odin Holmes.
//            2022      Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

import Boost.TMP;
import Boost.TMP.Tests;

int main() {
	return any_of_test::run() ||
           all_of_test::run() ||
           size_test::run()   ||
           sort_test::run()   ||
           swap_test::run()   ||
           take_test::run()   ||
           tee_test::run()    ||
           transform_test::run()
           ;
}

