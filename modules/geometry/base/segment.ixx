
export module Vanir.Geometry.Segment;

import <Eigen/Dense>;

import Vanir.Geometry.Line;
import Vanir.Geometry.Point;

import std;

export namespace Vanir::Geo
{
    // A line vector, having a distinct start and end point.
    // Unlike the Line object, this has finite length and stores
    // information as two points (start and end).
    template<typename Scalar, std::size_t Dim>
    struct Segment
    {
        constexpr Segment() = default;

        constexpr Segment(const Point<Scalar, Dim>& ptA, const Point<Scalar, Dim>& ptB)
        {
            segment.col(0) << ptA.get();
            segment.col(1) << ptB.get();
        }

        constexpr auto get() const noexcept
        {
            return segment;
        }

        Eigen::Matrix<Scalar, Dim, 2> segment{};
    };

    // TODO: Use vector math.
    template<typename Scalar, std::size_t Dim>
    constexpr auto getPerpendicularBisector(const Segment<Scalar, Dim>& line_seg)
    {
        auto mid_x = std::midpoint(line_seg.get()(0, 1), line_seg.get()(0, 0));
        auto mid_y = std::midpoint(line_seg.get()(1, 1), line_seg.get()(1, 0));

        auto neg_recip_slope = -(line_seg.get()(0, 1) - line_seg.get()(0, 0)) / (line_seg.get()(1, 1) - line_seg.get()(1, 0));
        // y - y1 = m(x - x1)
        // y - mx + (-y1 + m * x1) = 0
        // -mx + y + c = 0
        return Line<Scalar, Dim>{-neg_recip_slope, 1, mid_x * neg_recip_slope - mid_y};
    }

    using Segment2d = Segment<double, 2>;
    using Segment2f = Segment<float, 2>;
    using Segment2i = Segment<int, 2>;

    using Segment3d = Segment<double, 3>;
    using Segment3f = Segment<float, 3>;
    using Segment3i = Segment<int, 3>;
} // export