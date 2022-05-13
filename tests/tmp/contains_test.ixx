//  Copyright 2018-2019 Odin Holmes.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Test.Contains;

import Boost.TMP;

using namespace boost::tmp;

export namespace contains_test {
	template <int>
	struct x;

	using xs0 = list_<x<1>, x<2>, x<3>, x<4>, x<5>, x<6>, x<7>, x<8>, x<9>, x<10>>;

	using result0 = call_<unpack_<contains_<is_<x<0>>>>, xs0>;
	using result1 = call_<unpack_<contains_<is_<x<1>>>>, xs0>;
	using result2 = call_<unpack_<contains_<is_<x<5>>>>, xs0>;
	using result3 = call_<unpack_<contains_<is_<x<10>>>>, xs0>;

	int run() {

		return 0;
	}
} // namespace contains_test
