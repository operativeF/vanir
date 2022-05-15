//  Copyright 2018 Odin Holmes.
//            2022 Thomas Figueroa.
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Algorithm.Partition;

import Boost.TMP.Algorithm.Filter;
import Boost.TMP.Algorithm.RemoveIf;

import Boost.TMP.Base.Call;
import Boost.TMP.Base.Vocabulary;

import Boost.TMP.Detail.Dispatch;

import Boost.TMP.Sequence.Tee;

import std.core;

namespace boost::tmp {
	/// \brief
	/// Given a unary predicate, separate a list into a list of two lists, with the first being
	/// the values where the predicate holds.
	export template <typename F, typename C = listify_>
	struct partition_ {};

	namespace detail {
		template <std::size_t N, typename F, typename C>
		struct dispatch<N, partition_<F, C>> : dispatch<N, tee_<filter_<F>, remove_if_<F>, C>> {
		};
	} // namespace detail
} // namespace boost::tmp
