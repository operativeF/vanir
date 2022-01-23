//  Copyright 2018-2019 Odin Holmes.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

#include <memory>

#include <boost/tmp.hpp>
#include "test_util.hpp"

namespace logic_test {
	template <typename T>
	using is_even = bool_<(T::value % 2 == 0)>;
	int run() {

		bool_<false>{} = call_<and_<lift_<is_even>>, int_<1>, int_<1>, int_<1>, int_<1>, int_<1>,
		                       int_<1>, int_<1>, int_<1>, int_<1>>{};

		bool_<false>{} = call_<and_<lift_<is_even>>, int_<2>, int_<1>, int_<1>, int_<1>, int_<1>,
		                       int_<1>, int_<1>, int_<1>, int_<2>>{};

		bool_<true>{} = call_<and_<lift_<is_even>>, int_<2>, int_<2>, int_<2>>{};

		bool_<false>{} = call_<or_<lift_<is_even>>, int_<1>, int_<1>, int_<1>, int_<1>, int_<1>,
		                       int_<1>, int_<1>, int_<1>, int_<1>>{};

		bool_<true>{} = call_<or_<lift_<is_even>>, int_<1>, int_<1>, int_<1>, int_<1>, int_<1>,
		                      int_<1>, int_<1>, int_<1>, int_<2>>{};

		bool_<true>{} = call_<or_<lift_<is_even>>, int_<2>, int_<2>, int_<2>>{};

		return 0;
	}
} // namespace logic_test