//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Anything;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;

import std.core;

namespace tmp = boost::tmp;

export namespace potato::units {
	template <typename RatioTypeT, typename P, typename Impl>
	struct anything_impl {

		using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<std::uint64_t>,
                tmp::always_<std::int64_t>,
                tmp::always_<long double>
            >, P>;

        using mod_ratio  = RatioTypeT;
        using value_type = DerivedValueType;
        using numer_type = DerivedValueType;

		constexpr anything_impl(value_type val) : value{val} {}

		value_type value;

		using is_any_impl = boost::tmp::true_;

		using impl = Impl;
	};
	
	template <typename P, typename Impl>
	using anything_ = anything_impl<unity_ratio, P, Impl>;

} // namespace potato::units
