module;

#include <Eigen/Dense>

export module Vanir.Geometry.Segment;

// TODO: Distinguish between a line (infinite) and line segment

import Vanir.Geometry.Point;

export namespace Vanir::Geo
{
    template<typename Scalar, std::size_t Dim>
    struct Segment
    {
        constexpr Segment() = default;

        constexpr Segment(const Point<Scalar, Dim>& ptA, const Point<Scalar, Dim>& ptB)
        {
            line.col(0) << ptA.pt;
            line.col(1) << ptB.pt;
        }

        template<typename T>
        constexpr auto scale(T val)
        {
            line = (line * val).eval();
        }

        Eigen::Matrix<Scalar, Dim, 2> line{};
    };

    using Segment2d = Segment<double, 2>;
    using Segment2f = Segment<float, 2>;
    using Segment2i = Segment<int, 2>;

    using Segment3d = Segment<double, 3>;
    using Segment3f = Segment<float, 3>;
    using Segment3i = Segment<int, 3>;
} // export