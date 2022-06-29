export module Vanir.Geometry.Line;

import Vanir.Geometry.Point;

import <Eigen/Dense>;

import std.core;

export namespace Vanir::Geo
{
    template<typename Scalar, size_t Dim>
    struct Line
    {
        using value_type  = typename Eigen::Matrix<Scalar, Dim, 2>;
        using scalar_type = Scalar;
        using width       = std::integral_constant<int, 2>;
        using dim         = std::integral_constant<int, Dim>;

        constexpr Line() = default;

        constexpr Line(const Point<scalar_type, Dim>& ptA, const Point<scalar_type, Dim>& ptB)
        {
            line.col(0) << ptA.pt;
            line.col(1) << ptB.pt;
        }

        constexpr Line(const value_type& val)
            : line{val}
        {
        }

        constexpr auto get() const noexcept
        {
            return line;
        }

        template<size_t N>
        constexpr auto getPoint() const noexcept
        {
            return line.col(N);
        }

        constexpr auto getPerpendicularBisector() const noexcept
        {
            auto mid_x = std::midpoint(line(0, 0), line(1, 0));
            auto mid_y = std::midpoint(line(0, 1), line(1, 1));

            auto neg_recip_slope = - (line(1, 0) - line(0, 0)) / (line(1, 1) - line(0, 1));
        }
        
        value_type line{};
    };

    using Line2d = Line<double, 2>;
    using Line2f = Line<float, 2>;
    using Line2i = Line<int, 2>;

    using Line3d = Line<double, 3>;
    using Line3f = Line<float, 3>;
    using Line3i = Line<int, 3>;
} // export