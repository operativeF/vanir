//  Copyright 2018-2019 Odin Holmes.
//            2021-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Algorithm.NoneOf;

import Boost.TMP.Base.Identity;
import Boost.TMP.Base.Logic;

import Boost.TMP.Algorithm.FindIf;
import Boost.TMP.Algorithm.Transform;

import Boost.TMP.Detail.Dispatch;

import <cstddef>;

export namespace boost::tmp {
		template <typename F, typename C = identity_>
		struct none_of_;

		// @TODO: Make this shorting.
		namespace detail {
			template <std::size_t N, typename F, typename C>
			struct dispatch<N, none_of_<F, C>>
                : dispatch<N, and_<F, not_<C>>> {};
		} // namespace detail
} // export namespace boost::tmp
