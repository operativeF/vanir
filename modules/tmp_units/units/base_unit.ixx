//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Units.BaseUnit;

import Boost.TMP;

namespace tmp = boost::tmp;

export namespace potato::units {
    template<typename UnitRatioT, typename V>
    struct base_unit_
    {
        using DerivedValueType = tmp::call_<
            tmp::if_<tmp::is_<unsigned long long>,
                tmp::always_<long long>,
                tmp::identity_
            >, V>;

        using value_type = DerivedValueType;

        constexpr base_unit_(value_type v) : value{v} {}

        value_type value{};
    };

} // namespace potato::units
