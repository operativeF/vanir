//  Copyright 2018-2019 Odin Holmes.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

#include <boost/tmp.hpp>
#include "test_util.hpp"

namespace erase_test {
	template <int>
	struct x;

	using xs0 = list_<x<1>, x<2>, x<3>, x<4>, x<5>, x<6>, x<7>, x<8>, x<9>, x<10>>;

	using result0 = call_<unpack_<erase_<uint_<0>>>, xs0>;
	using result1 = call_<unpack_<erase_<uint_<1>>>, xs0>;
	using result2 = call_<unpack_<erase_<uint_<9>>>, xs0>;

	int run() {

		list_<x<2>, x<3>, x<4>, x<5>, x<6>, x<7>, x<8>, x<9>, x<10>>{} = result0{};
		list_<x<1>, x<3>, x<4>, x<5>, x<6>, x<7>, x<8>, x<9>, x<10>>{} = result1{};
		list_<x<1>, x<2>, x<3>, x<4>, x<5>, x<6>, x<7>, x<8>, x<9>>{}  = result2{};

		return 0;
	}
} // namespace erase_test