//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Engine.Operators;

import std.core;

import Boost.TMP;
import Boost.TMP.Units.Engine.Base;
import Boost.TMP.Units.Engine.Evaluators;

namespace tmp = boost::tmp;

export namespace potato::units {
	template<Unitable T>
	constexpr auto operator+(T&& aVal, T&& bVal) -> try_type_lookup_t<add_type<T, T>>{
		return aVal.value + bVal.value;
	}

	template<typename T, typename U>
	using scale_types = tmp::call_<
		tmp::if_<tmp::lift_<std::ratio_greater>,
			tmp::always_<unity_ratio>,
			tmp::if_<tmp::lift_<std::ratio_less>,
				tmp::always_<std::ratio_divide<typename T::mod_ratio, typename U::mod_ratio>>,
				tmp::always_<unity_ratio>>
		>, typename T::mod_ratio, typename U::mod_ratio>;
	
	// TODO: This is valid only for long double, must be specialized for integers.
	template <Unitable T, Unitable U>
	constexpr auto operator+(const T& aVal, const U& bVal) -> try_type_lookup_t<add_type<T, U>> {
		using aVal_scale = scale_types<T, U>;
		using bVal_scale = scale_types<U, T>;
		return (aVal.value * aVal_scale::num) / (aVal_scale::den) +
			   (bVal.value * bVal_scale::num) / (bVal_scale::den);
	}

	template <Unitable T>
	constexpr T operator-(const T& aVal, const T& bVal) {
		return aVal.value - bVal.value;
	}

	// Scaling for operator-
	template<typename T, typename U>
	using scale_sub_op = tmp::call_<
		tmp::if_<tmp::lift_<std::ratio_greater>,
			tmp::always_<unity_ratio>,
			tmp::if_<tmp::lift_<std::ratio_less>,
				tmp::always_<std::ratio_divide<typename T::mod_ratio, typename U::mod_ratio>>,
				tmp::always_<unity_ratio>>
		>, typename T::mod_ratio, typename U::mod_ratio>;

	template <Unitable T, Unitable U>
	constexpr auto operator-(const T& aVal, const U& bVal) -> try_type_lookup_t<add_type<T, U>> {
		using aVal_scale = scale_sub_op<T, U>;
		using bVal_scale = scale_sub_op<U, T>;
		return (aVal.value * aVal_scale::num) / (aVal_scale::den) -
			   (bVal.value * bVal_scale::num) / (bVal_scale::den);
	}

	template <typename T>
	constexpr T operator-(T aVal) {
		return -aVal.value;
	}

	template<typename T, typename U>
	using unitless_multiply = tmp::call_<
			tmp::if_<tmp::is_<long double>,
				tmp::always_<std::ratio_multiply<typename T::mod_ratio, typename U::mod_ratio>>,
				tmp::always_<unity_ratio>>,
			try_type_lookup_t<multi_type<T, U>>>;

	template <Unitable T, Unitable U>
	constexpr auto operator*(const T& aVal, const U& bVal) -> try_type_lookup_t<multi_type<T, U>> {
		using unitless_ratio = unitless_multiply<T, U>;
		return (aVal.value * bVal.value) * (unitless_ratio::num / unitless_ratio::den);
	}

	template<Unitable T>
	constexpr T operator*(const T& aVal, long double bVal) {
		return aVal.value * bVal;
	}

	template<Unitable T>
	constexpr T operator*(long double aVal, T bVal) {
		return aVal * bVal.value;
	}

	template<typename T, typename U>
	using unitless_divide = tmp::call_<
			tmp::if_<tmp::is_<long double>,
				tmp::always_<std::ratio_divide<typename T::mod_ratio, typename U::mod_ratio>>,
				tmp::always_<unity_ratio>>,
			try_type_lookup_t<div_type<T, U>>>;

	template<Unitable T, Unitable U>
	constexpr auto operator/(const T& aVal, const U& bVal) -> try_type_lookup_t<div_type<T, U>> {
		using unitless_ratio = unitless_divide<T, U>;
		return (aVal.value / bVal.value) * (unitless_ratio::num / unitless_ratio::den);
	}

	template<Unitable T>
	constexpr T operator/(const T& aVal, long double bVal) {
		return aVal.value / bVal;
	}

	template<Unitable T>
	constexpr auto operator/(long double aVal, const T& bVal) -> try_type_lookup_t<inverter<T>> {
		return aVal / bVal.value;
	}

	template <Unitable T, Unitable U> requires(std::same_as<typename T::impl, typename U::impl>)
	constexpr bool operator==(const T& aVal, const U& bVal) {
		// Check if both have same underlying type
		// TODO: Normalize to unit that would increase dynamic range
		// Convert to SI if comparing between imperial and SI units
		auto aVal_ = convertTo<T>()(aVal);
		auto bVal_ = convertTo<T>()(bVal);

		return (aVal_.value == bVal_.value);
	}

	template<Unitable T, Unitable U> requires(std::same_as<typename T::impl, typename U::impl>)
	constexpr auto operator<=>(const T& lhs, const U& rhs) {
		// TODO: Normalize to unit that would increase dynamic range
		auto lhs_cv = convertTo<T>()(lhs);
		auto rhs_cv = convertTo<T>()(rhs);

		return lhs_cv.value <=> rhs_cv.value;
	}

	template <typename T>
	auto pow(T base, int exp) -> try_type_lookup_t<multi_type<T, T>> {
		return std::pow(base.value, exp);
	}
} // namespace potato::units
