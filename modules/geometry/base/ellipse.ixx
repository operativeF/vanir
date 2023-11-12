module;

export module Vanir.Geometry.Ellipse;

import Vanir.Geometry.Point;
import Vanir.Geometry.Line;

export namespace Vanir::Geo
{
    template<typename Scalar, std::size_t Dim>
    struct Ellipse
    {
        template<typename S>
        using point_type = Point<S, Dim>;

        template<typename ScalarT = Scalar>
        constexpr Ellipse(const point_type<ScalarT>& center,
                          const point_type<ScalarT>& ext_a,
                          const point_type<ScalarT>& ext_b)
        {
        }
    };
} // export
