//  Copyright 2018 Odin Holmes.
//            2020-2022 Thomas Figueroa.
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Algorithm.Contains;

import Boost.TMP.Base.Comparison;
import Boost.TMP.Base.Identity;
import Boost.TMP.Base.Logic;

import Boost.TMP.Detail.Dispatch;

import std.core;

export namespace boost::tmp {
		template <typename V, typename C = identity_>
		struct contains_;

		namespace detail {
			template <std::size_t N, typename V, typename C>
			struct dispatch<N, contains_<V, C>> : dispatch<N, or_<is_<V>, C>> {};
		} // namespace detail
} // export namespace boost::tmp
