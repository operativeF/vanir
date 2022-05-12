//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.Engine.Base;

import Boost.TMP;

import std.core;

export namespace potato::units {
        using unity_ratio = std::ratio<1, 1>;

        // Base SI Units
        struct meter_l 	    : boost::tmp::uint_<1> {};
        struct second_l     : boost::tmp::uint_<2> {};
        struct gram_l       : boost::tmp::uint_<3> {};
        struct mole_l 	    : boost::tmp::uint_<4> {};
        struct ampere_l     : boost::tmp::uint_<5> {};
        struct kelvin_l     : boost::tmp::uint_<6> {};
        struct candela_l    : boost::tmp::uint_<7> {};
        struct radian_l     : boost::tmp::uint_<8> {};
        struct steradian_l  : boost::tmp::uint_<9> {};
        struct decay_l      : boost::tmp::uint_<10> {}; // For use with becquerels to disambiguate from hertz.
        struct dummy	    : boost::tmp::uint_<11> {};
} // namespace potato::units
