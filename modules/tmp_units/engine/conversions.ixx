//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Engine.Conversions;

import std.core;

export namespace potato::units {
		template <typename ConvType>
		struct convertTo {
			template <typename T>
			constexpr auto operator()(const T &val) -> ConvType {
				if (std::ratio_greater_v<typename ConvType::mod_ratio, typename T::mod_ratio>) {
					using conv_factor = std::ratio_divide<typename ConvType::mod_ratio, typename T::mod_ratio>;
					return val.value * conv_factor::den / conv_factor::num;
				}
				else {
					using conv_factor = std::ratio_divide<typename T::mod_ratio, typename ConvType::mod_ratio>;
					return val.value * conv_factor::num / conv_factor::den;
				}
			}
		};
} // namespace potato::units
