//  Copyright 2018 Odin Holmes.
//            2021 Thomas Figueroa.
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Sequence.Container;

import Boost.TMP.Base.Comparison;
import Boost.TMP.Base.Lift;
import Boost.TMP.Base.Vocabulary;

import Boost.TMP.Detail.Dispatch;

export namespace boost::tmp {
		/// \brief
		template <typename C = identity_>
		struct container_ {};
		namespace detail {
			template <typename L, typename C>
			struct container_impl {
				using type = typename dispatch<1, C>::template f<nothing_>;
			};
			template <template <typename...> class Seq, typename C, typename... Ls>
			struct container_impl<Seq<Ls...>, C> {
				using type = typename dispatch<1, C>::template f<lift_<Seq>>;
			};

			template <typename C>
			struct dispatch<1, container_<C>> {
				template <typename L>
				using f = typename detail::container_impl<L, C>::type;
			};
		} // namespace detail
} // export namespace boost::tmp
