//  Copyright 2019-2021 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

module;

#if defined(__GNUC__) || defined(__clang__)
#include <cstdint>
#endif // defined(__GNUC__ ) || defined(__clang__)

export module Vanir.Geometry.Point;

import Eigen3_HU;

#if _MSC_VER
import std;
#endif // _MSC_VER

export namespace Vanir::Geo
{
    template<typename Scalar, std::size_t Dim>
    struct Point
    {
        using value_type  = typename Eigen::Matrix<Scalar, Dim, 1>;
        using scalar_type = Scalar;
        using width       = std::integral_constant<int, 1>;
        using dim         = std::integral_constant<int, Dim>;

        constexpr Point() = default;

        // TODO: Conditionally explicit?
        template<typename... Scalars> requires(sizeof...(Scalars) == Dim)
        constexpr Point(Scalars... ss)
        {
            pt = {ss...};
        }

        explicit constexpr Point(const value_type& mpt)
            : pt{mpt}
        {
        }

        constexpr auto get() const noexcept
        {
            return pt;
        }

        // TODO: OOB handling
        constexpr Scalar at(auto index) const
        {
            return pt(index, 1);
        }

        bool operator==(const Point&) const = default;
        auto operator<=>(const Point&) const = default;

        value_type pt{}; 
    };

    using Point2d  = Point<double, 2>;
    using Point2f  = Point<float, 2>;
    using Point2i  = Point<int, 2>;

    using Point3d  = Point<double, 3>;
    using Point3f  = Point<float, 3>;
    using Point3i  = Point<int, 3>;
} // export namespace Vanir::Geo