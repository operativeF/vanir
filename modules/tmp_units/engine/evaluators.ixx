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


	// New evaluators
	template<typename... Ts>
	struct FullDims_ {};

	template<typename UnitType, typename Ratio>
	struct UnitDims
	{
		using ratio = Ratio;
		using type  = UnitType;
	};

	template<typename Ratio>
	struct Meter : UnitDims<meter_l, Ratio> { template<typename T> using Base = Meter<T>; };

	template<typename Ratio>
	struct Second : UnitDims<second_l, Ratio> { template<typename T> using Base = Second<T>; };

	template<typename Ratio>
	struct Gram : UnitDims<gram_l, Ratio> { template<typename T> using Base = Gram<T>; };

	template<typename Ratio>
	struct Mole : UnitDims<mole_l, Ratio> { template<typename T> using Base = Mole<T>; };

	template<typename Ratio>
	struct Ampere : UnitDims<ampere_l, Ratio> { template<typename T> using Base = Ampere<T>; };

	template<typename Ratio>
	struct Kelvin : UnitDims<kelvin_l, Ratio> { template<typename T> using Base = Kelvin<T>; };

	template<typename Ratio>
	struct Candela : UnitDims<candela_l, Ratio> { template<typename T> using Base = Candela<T>; };

	template<typename Ratio>
	struct Radian : UnitDims<radian_l, Ratio> { template<typename T> using Base = Radian<T>; };

	template<typename Ratio>
	struct Steradian : UnitDims<steradian_l, Ratio> { template<typename T> using Base = Steradian<T>; };

	template<typename Ratio>
	struct Decay : UnitDims<decay_l, Ratio> { template<typename T> using Base = Decay<T>; };

	using FullBaseDims = tmp::list_<
		Meter<std::ratio<3, 1>>, Second<std::ratio<3, 1>>, Gram<std::ratio<3, 1>>, Mole<std::ratio<3, 1>>, Ampere<std::ratio<3, 1>>,
		Kelvin<std::ratio<3, 1>>, Candela<std::ratio<3, 1>>, Radian<std::ratio<3, 1>>, Steradian<std::ratio<3, 1>>, Decay<std::ratio<3, 1>>>;

	template<typename UnitL, typename UnitR>
	using multiplied_dimensions = typename UnitL::template Base<std::ratio_add<typename UnitL::ratio, typename UnitR::ratio>>;

	template<typename UnitT, typename I>
	using exponentiated_dimensions = typename UnitT::template Base<std::ratio_multiply<I, typename UnitT::ratio>>;

	template<typename UnitL, typename UnitR>
	using divided_dimensions = typename UnitL::template Base<std::ratio_subtract<typename UnitL::ratio, typename UnitR::ratio>>;

	using OtherDims = tmp::list_<
		Meter<std::ratio<2, 1>>, Second<std::ratio<2, 1>>, Gram<std::ratio<2, 1>>, Mole<std::ratio<2, 1>>, Ampere<std::ratio<-2, 1>>,
		Kelvin<std::ratio<2, 1>>, Candela<std::ratio<2, 1>>, Radian<std::ratio<2, 1>>, Steradian<std::ratio<2, 1>>, Decay<std::ratio<2, 1>>>;

	using zipped_units = tmp::call_<tmp::zip_<tmp::lift_<multiplied_dimensions>>, FullBaseDims, OtherDims>::value;

} // namespace potato::units
