//  Copyright 2018-2019 Odin Holmes.
//            2022 Thomas Figueroa.
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Test.Tee;

import Boost.TMP;

using namespace boost::tmp;

export namespace tee_test {
	int run() {
		{
			list_<list_<>>{}          = call_<tee_<listify_, listify_>>{};
			list_<list_<int>>{}       = call_<tee_<listify_, listify_>, int>{};
			list_<list_<int, bool>>{} = call_<tee_<listify_, listify_>, int, bool>{};
/*			list_<list_<int, bool>, int, bool>{} =
			        call_<tee_<listify_, forward_as_pack_, listify_>, int, bool>{};
			list_<list_<int, bool>, list_<int, bool>>{} =
			        call_<tee_<listify_, listify_, listify_>, int, bool>{};
			list_<list_<int, bool>, list_<int, bool>, int, bool>{} =
			        call_<tee_<listify_, listify_, identity_, listify_>, int, bool>{};
			list_<list_<int, bool>, list_<int, bool>, list_<int, bool>>{} =
			        call_<tee_<listify_, listify_, listify_, listify_>, int, bool>{};
			list_<list_<int, bool>, list_<int, bool>, list_<int, bool>, int, bool>{} =
			        call_<tee_<listify_, listify_, listify_, identity_, listify_>, int,
			              bool>{};
			list_<list_<int, bool>, list_<int, bool>, list_<int, bool>, list_<int, bool>>{} =
			        call_<tee_<listify_, listify_, listify_, listify_, listify_>, int, bool>{};
			list_<list_<int, bool>, list_<int, bool>, list_<int, bool>, list_<int, bool>, int,
			      bool>{} =
			        call_<tee_<listify_, listify_, listify_, listify_, forward_as_pack_, listify_>,
			              int, bool>{};*/
		}
		{
			true_{}  = call_<tee_<is_<int>, and_<>>, int>{};
			false_{} = call_<tee_<is_<int>, is_<int>, and_<>>, char>{};
			false_{} = call_<tee_<is_<int>, is_<int>, is_<int>, and_<>>, char>{};
			false_{} = call_<tee_<is_<int>, identity_, and_<>>,
			                 char>{}; // short circuiting should save from hard error
			false_{} = call_<tee_<is_<int>, identity_, is_<int>, and_<>>,
			                 char>{}; // short circuiting should save from hard error
		}
		{
			true_{}  = call_<tee_<is_<int>, or_<>>, int>{};
			false_{} = call_<tee_<is_<int>, is_<int>, or_<>>, char>{};
			false_{} = call_<tee_<is_<int>, is_<int>, is_<int>, or_<>>, char>{};
			true_{}  = call_<tee_<is_<int>, identity_, or_<>>,
                            int>{}; // short circuiting should save from hard error
            true_{}  = call_<tee_<is_<int>, identity_, is_<int>, or_<>>,
                            int>{}; // short circuiting should save from hard error
        }

        return 0;
    }
} // namespace tee_test
