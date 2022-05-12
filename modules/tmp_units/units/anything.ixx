//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Anything;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.Engine.Evaluators;

export namespace potato::units {
	template <typename T, typename P, typename Impl>
	struct anything_impl {
		constexpr anything_impl<T, P, Impl>() : value(0) {
		}
		constexpr anything_impl<T, P, Impl>(P val) : value(val) {
		}

		template <typename E>
		constexpr auto operator=(E expression) -> decltype(try_type_lookup<E>) {
			return { expression.value };
		}

		P value;

		using is_any_impl = boost::tmp::true_;

		using mod_ratio = T;

		using impl = Impl;
	};
	
	template <typename P, typename Impl>
	using anything_ = anything_impl<unity_ratio, P, Impl>;

} // namespace potato::units
