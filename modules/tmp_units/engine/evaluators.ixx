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

namespace tmp = boost::tmp;

export namespace potato::units {
	// TODO: Add automatic scaling of units by nearest 3rd power of 10 -> 1000 / 0.001 for long double units
	// TODO: Make these metafunctions lazy

	template <typename T>
	using get_actual_impl = dispatcher<typename T::impl>::template f<
		typename T::mod_ratio, decltype(T::value)>;

	template <typename T, typename U>
	constexpr auto scaleTo(T aUnit) -> U {
		using scaling = std::ratio_divide<typename U::mod_ratio, typename T::mod_ratio>;
		return (aUnit.value * scaling::num) / scaling::den;
	}
	
	template <typename T>
	using try_type_lookup_t = tmp::call_<
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

	template<typename UnitL, typename UnitR>
	using multiplied_dimensions = typename UnitL::template Base<
		std::ratio_add<typename UnitL::ratio, typename UnitR::ratio>>;

	template<typename UnitT, typename I>
	using exponentiated_dimensions = typename UnitT::template Base<
		std::ratio_multiply<I, typename UnitT::ratio>>;

	template<typename UnitL, typename UnitR>
	using divided_dimensions = typename UnitL::template Base<
		std::ratio_subtract<typename UnitL::ratio, typename UnitR::ratio>>;

	using inversion_unit = tmp::list_<Length<std::ratio<-1, 1>>,
                                      Time<std::ratio<-1, 1>>,
                                      Mass<std::ratio<-1, 1>>,
                                      AmountOfSubstance<std::ratio<-1, 1>>,
                                      ElectricCurrent<std::ratio<-1, 1>>,
                                      ThermodynamicTemperature<std::ratio<-1, 1>>,
                                      LuminousIntensity<std::ratio<-1, 1>>,
                                      Radian<std::ratio<-1, 1>>,
                                      Steradian<std::ratio<-1, 1>>,
                                      Decay<std::ratio<-1, 1>>>;

	template<typename UnitL, typename UnitR>
	using invert_dimensions = typename UnitL::template Base<
		std::ratio_multiply<typename UnitL::ratio, typename UnitR::ratio>>;

	template<template<typename...> typename F, typename T, typename U>
	using zipped_units = tmp::call_<tmp::zip_<tmp::lift_<F>>, T, U>;

	template <typename T, typename U>
	using add_type = typename dispatcher<typename U::impl>::template f<
		select_prefix_ld<T, U>,
		decltype(U::value)>;

	template <typename T, typename U>
	using multi_type = typename dispatcher<
		zipped_units<multiplied_dimensions,
			         typename T::impl,
					 typename U::impl>>::template f<
					 	std::ratio_multiply<typename T::mod_ratio, typename U::mod_ratio>,
						decltype(U::value)>;

	template <typename T, typename U>
	using div_type = typename dispatcher<
		zipped_units<divided_dimensions,
		             typename T::impl,
					 typename U::impl>>::template f<
					 	std::ratio_divide<typename T::mod_ratio, typename U::mod_ratio>,
						decltype(U::value)>;

	template <typename F>
	using invert_ratio = typename std::ratio<F::den, F::num>;

	template <typename T>
	using inverter = typename dispatcher<
		zipped_units<invert_dimensions,
		             typename T::impl,
					 inversion_unit>>::template f<
					 	invert_ratio<typename T::mod_ratio>,
						decltype(T::value)>;
} // namespace potato::units
