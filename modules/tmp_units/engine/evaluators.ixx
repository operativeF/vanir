//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Engine.Evaluators;

import Boost.TMP;

import Boost.TMP.Units.Engine.Conversions;
import Boost.TMP.Units.Engine.TypeDispatcher;
import Boost.TMP.Units.Engine.Base;

import std.core;

export namespace potato::units {
	namespace tmp = boost::tmp;
	// TODO: Add automatic scaling of units by nearest 3rd power of 10 -> 1000 / 0.001 for long double units
	// TODO: Make these metafunctions lazy

	template <typename T>
	using get_actual_impl = dispatcher<typename T::impl>::template f<typename T::mod_ratio, decltype(T::value)>;

	namespace detail {

		template <bool RatioIsLessThan>
		struct select_ratio_impl;

		template <>
		struct select_ratio_impl<true> {
			template <typename T, typename U>
			using f = typename U::mod_ratio;
		};

		template <>
		struct select_ratio_impl<false> {
			template <typename T, typename U>
			using f = typename T::mod_ratio;
		};

		template <bool IsLongPrefix>
		struct select_prefix_impl;

		template <>
		struct select_prefix_impl<false> {
			template <typename T, typename U>
			using f = typename select_ratio_impl<std::ratio_less_v<typename T::mod_ratio, typename U::mod_ratio>>::template f<T, U>;
		};

		template <>
		struct select_prefix_impl<true> {
			template <typename T, typename U>
			using f = typename select_ratio_impl<std::ratio_less_v<typename U::mod_ratio, typename T::mod_ratio>>::template f<T, U>;
		};

		template <typename T, typename U>
		struct check_numer_type;

		template <>
		struct check_numer_type<unsigned long long, unsigned long long> {
			template <typename T, typename U>
			using f = typename select_prefix_impl<true>::template f<T, U>;
		};
	
		template <>
		struct check_numer_type<long double, long double> {
			template <typename T, typename U>
			using f = typename select_prefix_impl<false>::template f<T, U>;
		};

		struct select_cor_t {
			template <typename T, typename U>
			using f = typename check_numer_type<typename T::numer_type, typename U::numer_type>::template f<T, U>;
		};

		template <bool P>
		struct try_type_lookup;

		template <>
		struct try_type_lookup<false> {
			template <typename T>
			using f = get_actual_impl<T>;
		};

		template <>
		struct try_type_lookup<true> {
			template <typename T>
			using f = T;
		};

	} // namespace detail

	template <typename T, typename U>
	constexpr auto scaleTo(T aUnit) -> U {
		using scaling = std::ratio_divide<typename U::mod_ratio, typename T::mod_ratio>;
		return (aUnit.value * scaling::num) / scaling::den;
	}
	
	template <typename T>
	using try_type_lookup = tmp::call_<
		tmp::if_<tmp::is_<tmp::false_>,
			tmp::always_<T>,
			tmp::always_<get_actual_impl<T>>
		>, typename T::is_any_impl>;

	template <typename T, typename U>
	using select_prefix_ld = tmp::call_<
		tmp::if_<tmp::lift_<std::ratio_less>,
			tmp::always_<typename U::mod_ratio>,
			tmp::always_<typename T::mod_ratio>
		>, typename T::mod_ratio, typename U::mod_ratio>;

	template <typename T, typename U>
	using select_prefix_ull = tmp::call_<
		tmp::if_<tmp::lift_<std::ratio_less>,
			tmp::always_<typename T::mod_ratio>,
			tmp::always_<typename U::mod_ratio>
		>, typename T::mod_ratio, typename U::mod_ratio>;

	template <typename T, typename U>
	using add_type = typename dispatcher<typename U::impl>::template f<select_prefix_ld<T, U>, decltype(U::value)>;

	template <typename F, typename G>
	using multiplier = tmp::call_<tmp::set_multiplier_<>, F, G>;

	template <typename T, typename U>
	using multi_type = typename dispatcher<multiplier<typename T::impl, typename U::impl>>::template f<std::ratio_multiply<typename T::mod_ratio, typename U::mod_ratio>, decltype(U::value)>;

	template <typename F, typename G>
	using quotient = tmp::call_<tmp::set_divisor_<>, F, G>;

	template <typename T, typename U>
	using div_type = typename dispatcher<quotient<typename T::impl, typename U::impl>>::template f<std::ratio_divide<typename T::mod_ratio, typename U::mod_ratio>, decltype(U::value)>;

	template <typename F>
	using swap_invert = tmp::call_<
		tmp::unpack_<
			tmp::replace_if_<tmp::list_<dummy>, tmp::is_<tmp::list_<>>,
				tmp::swap_<
					tmp::replace_if_<tmp::list_<>, tmp::is_<tmp::list_<dummy>>
					>
				>
			>
		>, F>;

	template <typename F>
	using invert_ratio = typename std::ratio<F::den, F::num>;

	template <typename T>
	using inverter = typename dispatcher<swap_invert<typename T::impl>>::template f<invert_ratio<typename T::mod_ratio>, decltype(T::value)>;
} // namespace potato::units
