//  Copyright 2018 Odin Holmes.
//            2021-2022 Thomas Figueroa.
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Sequence.Swap;

import Boost.TMP.Base.Vocabulary;

/// \brief Swaps two variadic parametic pack values. Must be only two values.
export namespace boost::tmp {
		template <typename C = listify_>
		struct swap_ {};
		namespace detail {
			template <typename C>
			struct dispatch<2, swap_<C>> {
				template <typename T, typename U>
				using f = typename dispatch<2, C>::template f<U, T>;
			};
		} // namespace detail
} // export namespace boost::tmp
