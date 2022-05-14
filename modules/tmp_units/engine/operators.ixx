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

export namespace potato::units {
	namespace tmp = boost::tmp;
	// Addition and subtraction need to be done in a different way for floating point and integers.
	// Floating point need to be scaled in a way that is correct.
	// 1.0_mA + 1.0_A -> 1.001_A
	// Whereas for integers:
	// 1_mA + 1_A -> 1001_mA
	// 1.) Determine if floating-point or integer
	// For floating-point, this involves the following:
	// 1.) Determine which unit is largest, if they're the same, skip and return whichever.
	// 2.) Scale the smallest unit to the larger one, if necessary.
	// For integers, this involves the following:
	// 1.) Determine which unit is largest, if they're the same, skip and return whichever.
	// 2.) Scale the largest unit to the smaller one, if necessary.

	namespace detail {
		template <typename A, typename B>
		using scales = tmp::list_<A, B>;
	
		template <typename T>
		using IsLongDouble = tmp::call_<tmp::is_<long double>, typename T::numer_type>;

		template <typename T, typename U>
		using check_if_ld = tmp::if_<tmp::is_<long double>, tmp::always_<tmp::false_>, tmp::always_<tmp::true_>>;

		template <typename T, typename U>
		using check_ratio_greater = std::ratio_greater<typename T::mod_ratio, typename U::mod_ratio>;

		template <typename T, typename U>
		using get_scale = tmp::call_<
				tmp::if_<tmp::lift_<check_if_ld>,
					tmp::if_<tmp::lift_<check_ratio_greater>, // Floating-Point, scale to largest
						tmp::always_<std::ratio_divide<typename T::mod_ratio, typename U::mod_ratio>>, // Scale U (B) to the largest
						tmp::always_<std::ratio_divide<typename T::mod_ratio, typename U::mod_ratio>>  // Scale T (A) to the largest
					>,
					tmp::if_<tmp::lift_<check_ratio_greater>, // Integer, scale to smallest
						tmp::always_<std::ratio_divide<typename T::mod_ratio, typename U::mod_ratio>>,  // Scale U (B) to the smallest
						tmp::always_<std::ratio_divide<typename U::mod_ratio, typename T::mod_ratio>> // Scale T (A) to the smallest
					>
				>, T, U>;
	} // namespace detail

	template<Unitable T>
	constexpr auto operator+(T&& aVal, T&& bVal) -> try_type_lookup<add_type<T, T>>{
		return aVal.value + bVal.value;
	}

	template<typename T, typename U>
	using scale_types = tmp::call_<
		tmp::if_<tmp::lift_<std::ratio_greater>,
			tmp::always_<std::ratio_divide<typename T::mod_ratio, typename U::mod_ratio>>,
			tmp::if_<tmp::lift_<std::ratio_less>,
				tmp::always_<std::ratio_divide<typename U::mod_ratio, typename T::mod_ratio>>,
				tmp::always_<unity_ratio>>
		>, typename T::mod_ratio, typename U::mod_ratio
	>;
	
	// TODO: This is valid only for long double, must be specialized for integers.
	template <Unitable T, Unitable U>
	constexpr auto operator+(const T& aVal, const U& bVal) -> try_type_lookup<add_type<T, U>> {
		using aVal_scale = scale_types<T, U>;
		using bVal_scale = scale_types<T, U>;
		return (aVal.value * aVal_scale::num * bVal_scale::num) / (aVal_scale::den * bVal_scale::den) +
				(bVal.value * bVal_scale::num * bVal_scale::num) / (aVal_scale::den * bVal_scale::den);
	}

	// Integers work with this:
	// template <typename T, typename U>
	// constexpr auto operator+(const T& aVal, const U& bVal) -> try_type_lookup<add_type<T, U>> {
	//     using aScale = detail::get_scale<T, U>;
	// 	using bScale = detail::get_scale<T, U>;
	//     return ((aScale::num * aVal.value) / aScale::den) + ((bScale::num * bVal.value) / bScale::den);
	// }

	template <Unitable T>
	constexpr T operator-(const T& aVal, const T& bVal) {
		return aVal.value - bVal.value;
	}

	template <Unitable T, Unitable U>
	constexpr auto operator-(const T& aVal, const U& bVal) -> try_type_lookup<U> {
		using aVal_scale = tmp::call_<
			tmp::if_<tmp::lift_<std::ratio_greater>,
				tmp::always_<std::ratio_divide<typename T::mod_ratio, typename U::mod_ratio>>,
				tmp::if_<tmp::lift_<std::ratio_less>,
					tmp::always_<std::ratio_divide<typename T::mod_ratio, typename U::mod_ratio>>,
					tmp::always_<unity_ratio>>
			>, typename T::mod_ratio, typename U::mod_ratio>;
		using bVal_scale = tmp::call_<
			tmp::if_<tmp::lift_<std::ratio_greater>,
				tmp::always_<std::ratio_divide<typename T::mod_ratio, typename U::mod_ratio>>,
				tmp::if_<tmp::lift_<std::ratio_less>,
					tmp::always_<std::ratio_divide<typename T::mod_ratio, typename U::mod_ratio>>,
					tmp::always_<unity_ratio>>
			>, typename U::mod_ratio, typename T::mod_ratio>;
		return (aVal.value * aVal_scale::num * bVal_scale::num) / (aVal_scale::den * bVal_scale::den) -
				(bVal.value * bVal_scale::num * bVal_scale::num) / (aVal_scale::den * bVal_scale::den);
	}

	template <typename T>
	constexpr T operator-(T aVal) {
		return -aVal.value;
	}

	template <Unitable T, Unitable U>
	constexpr auto operator*(const T& aVal, const U& bVal) -> try_type_lookup<multi_type<T, U>> {
		using unitless_multiply = tmp::call_<
				tmp::if_<tmp::is_<long double>,
					tmp::always_<std::ratio_multiply<typename T::mod_ratio, typename U::mod_ratio>>,
					tmp::always_<unity_ratio>>,
				try_type_lookup<multi_type<T, U>>>;
		return (aVal.value * bVal.value) * (unitless_multiply::num / unitless_multiply::den);
	}

	template <typename T>
	constexpr T operator*(const T& aVal, long double bVal) {
		return aVal.value * bVal;
	}

	template <typename T>
	constexpr T operator*(long double aVal, T bVal) {
		return aVal * bVal.value;
	}

	template <typename T, typename U>
	constexpr auto operator/(const T& aVal, const U& bVal) -> try_type_lookup<div_type<T, U>> {
		using unitless_divide = tmp::call_<
				tmp::if_<tmp::is_<long double>,
					tmp::always_<std::ratio_divide<typename T::mod_ratio, typename U::mod_ratio>>,
					tmp::always_<unity_ratio>>,
				try_type_lookup<div_type<T, U>>>;
		return (aVal.value / bVal.value) * (unitless_divide::num / unitless_divide::den);
	}

	template <typename T>
	constexpr T operator/(const T& aVal, long double bVal) {
		return aVal.value / bVal;
	}

	template <typename T>
	constexpr auto operator/(long double aVal, const T& bVal) -> try_type_lookup<inverter<T>> {
		return aVal / bVal.value;
	}

	template <typename T, typename U>
	constexpr bool operator==(const T& aVal, const U& bVal) {
		// Check if both have same underlying type
		// TODO: Normalize to unit that would increase dynamic range
		// Convert to SI if comparing between imperial and SI units
		auto aVal_ = convertTo<T>()(aVal);
		auto bVal_ = convertTo<T>()(bVal);

		return (aVal_.value == bVal_.value);
	}

	template <typename T, typename U>
	constexpr bool operator!=(const T& aVal, const U& bVal) {
		// Check if both have same underlying type
		static_assert(std::is_same_v<typename T::impl, typename U::impl>,
						"Underlying types need to be the same.");
		// TODO: Normalize to unit that would increase dynamic range
		auto aVal_ = convertTo<T>()(aVal);
		auto bVal_ = convertTo<T>()(bVal);

		return (aVal_.value != bVal_.value);
	}

	template <typename T, typename U>
	constexpr bool operator<(const T& aVal, const U& bVal) {
		// Check if both have same underlying type
		static_assert(std::is_same_v<typename T::impl, typename U::impl>,
						"Underlying types need to be the same.");
		// TODO: Normalize to unit that would increase dynamic range
		auto aVal_ = convertTo<T>()(aVal);
		auto bVal_ = convertTo<T>()(bVal);

		return (aVal_.value < bVal_.value);
	}

	template <typename T, typename U>
	constexpr bool operator>(const T& aVal, const U& bVal) {
		// Check if both have same underlying type

		// TODO: Normalize to unit that would increase dynamic range
		auto aVal_ = convertTo<T>()(aVal);
		auto bVal_ = convertTo<T>()(bVal);

		return (aVal_.value > bVal_.value);
	}

	template <typename T, typename U>
	constexpr bool operator>=(const T& aVal, const U& bVal) {
		// Check if both have same underlying type
		static_assert(std::is_same_v<typename T::impl, typename U::impl>,
						"Underlying types need to be the same.");
		// TODO: Normalize to unit that would increase dynamic range
		auto aVal_ = convertTo<T>()(aVal);
		auto bVal_ = convertTo<T>()(bVal);

		return (aVal_.value >= bVal_.value);
	}

	template <typename T, typename U>
	constexpr bool operator<=(const T& aVal, const U& bVal) {
		// Check if both have same underlying type
		static_assert(std::is_same_v<typename T::impl, typename U::impl>,
						"Underlying types need to be the same.");
		// TODO: Normalize to unit that would increase dynamic range
		auto aVal_ = convertTo<T>()(aVal);
		auto bVal_ = convertTo<T>()(bVal);

		return (aVal_.value <= bVal_.value);
	}

	template <typename T>
	auto pow(T base, int exp) -> try_type_lookup<multi_type<T, T>> {
		return std::pow(base.value, exp);
	}
} // namespace potato::units
