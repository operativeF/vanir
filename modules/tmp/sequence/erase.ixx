//  Copyright 2018 Odin Holmes.
//            2021-2022 Thomas Figueroa.
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Sequence.Erase;

import Boost.TMP.Sequence.Drop;
import Boost.TMP.Sequence.PopFront;
import Boost.TMP.Sequence.Rotate;

import Boost.TMP.Base.Vocabulary;

#ifdef __GNUC__
import <cstdint>;
#elif __clang__
import std;
#elif _MSC_VER
import std.core;
#endif

// \brief
// Given a variadic parameter pack, remove the nth value in the pack.
// Reduces the size of the list by 1 as a result.
// FIXME: Add constraints so negative numbers aren't possible?
export namespace boost::tmp {
		template <typename N = sizet_<0>, typename C = listify_>
		struct erase_ {};

		namespace detail {
			template <std::size_t N, typename I, typename C>
			struct dispatch<N, erase_<I, C>> {
				template <typename... Ts>
				using f = typename dispatch<
				        N,
				        rotate_<I, pop_front_<rotate_<sizet_<(sizeof...(Ts) - I::value - 1)>, C>>>>::
				        template f<Ts...>;
			};
			template <typename I, typename C>
			struct dispatch<0, erase_<I, C>> {
				template <typename... Ts>
				using f = typename dispatch<1, C>::template f<nothing_>;
			};
		} // namespace detail
} // export namespace boost::tmp
