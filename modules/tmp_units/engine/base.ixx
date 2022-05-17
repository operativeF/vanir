//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Engine.Base;

import Boost.TMP;

import std.core;

namespace tmp = boost::tmp;

export namespace potato::units {
    using unity_ratio = std::ratio<1, 1>;

    // Base SI Units
    struct meter_l 	    : tmp::uint_<1> {};
    struct second_l     : tmp::uint_<2> {};
    struct gram_l       : tmp::uint_<3> {};
    struct mole_l 	    : tmp::uint_<4> {};
    struct ampere_l     : tmp::uint_<5> {};
    struct kelvin_l     : tmp::uint_<6> {};
    struct candela_l    : tmp::uint_<7> {};
    struct radian_l     : tmp::uint_<8> {};
    struct steradian_l  : tmp::uint_<9> {};
    struct decay_l      : tmp::uint_<10> {}; // For use with becquerels to disambiguate from hertz.
    struct dummy	    : tmp::uint_<11> {};

    template<typename T>
    concept Unitable = requires
    {
        T::value_type;
        T::impl;
        requires std::integral<typename T::value_type> || std::floating_point<typename T::value_type>;
    };

	template<typename UnitType, typename Ratio>
	struct UnitDims
	{
		using ratio = Ratio;
		using type  = UnitType;
	};

	template<typename Ratio>
	struct Length : UnitDims<meter_l, Ratio> { template<typename T> using Base = Length<T>; };

	template<typename Ratio>
	struct Time : UnitDims<second_l, Ratio> { template<typename T> using Base = Time<T>; };

	template<typename Ratio>
	struct Mass : UnitDims<gram_l, Ratio> { template<typename T> using Base = Mass<T>; };

	template<typename Ratio>
	struct AmountOfSubstance : UnitDims<mole_l, Ratio> { template<typename T> using Base = AmountOfSubstance<T>; };

	template<typename Ratio>
	struct ElectricCurrent : UnitDims<ampere_l, Ratio> { template<typename T> using Base = ElectricCurrent<T>; };

	template<typename Ratio>
	struct ThermodynamicTemperature : UnitDims<kelvin_l, Ratio> { template<typename T> using Base = ThermodynamicTemperature<T>; };

	template<typename Ratio>
	struct LuminousIntensity : UnitDims<candela_l, Ratio> { template<typename T> using Base = LuminousIntensity<T>; };

	template<typename Ratio>
	struct Radian : UnitDims<radian_l, Ratio> { template<typename T> using Base = Radian<T>; };

	template<typename Ratio>
	struct Steradian : UnitDims<steradian_l, Ratio> { template<typename T> using Base = Steradian<T>; };

	template<typename Ratio>
	struct Decay : UnitDims<decay_l, Ratio> { template<typename T> using Base = Decay<T>; };
} // namespace potato::units
