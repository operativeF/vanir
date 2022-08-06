module;

#include <Eigen/Dense>

export module Vanir.Geometry.Line;

import Vanir.Geometry.Point;

#if _MSC_VER
import std;
#endif // _MSC_VER

export namespace Vanir::Geo
{
    // An object that contains a matrix for a line /equation/.
    // Used for composing objects / intersections, not for synthesizing,
    // per se.
    // Kept in the form of [-mx, y, c] where c is some constant.
    // Solving a system of equations (2D) then is:
    // [-mx_1, y1, c1][x]   [0]
    // [-mx_2, y2, c2][y] = [0]
    //                [1]
    // or more generally, for n-dimensions: (m x n + 1) (rows x columns)
    // rowvec[-slope*x_11, y_12, ..., A_1n, c_1n] * colvec[x, y, ..., Zn, 1] = ZeroMatrix[m]
    // rowvec[-slope*x_21, y_22, ..., B_1n, c_2n]
    // ...
    // rowvec[-slope*x_m1, y_m2, ..., Z_mn, c_mn]
    // 
    template<typename Scalar, size_t Dim>
    struct Line
    {
        using dim         = std::integral_constant<int, size_t{Dim + 1}>;
        using value_type  = typename Eigen::Matrix<Scalar, dim::value, 1>;
        using scalar_type = Scalar;
        using width       = std::integral_constant<int, 3>;

        constexpr Line() = default;

        constexpr Line(const Point<scalar_type, dim::value>& ptA, const Point<scalar_type, dim::value>& ptB)
        {
            auto slope       = (ptA.get()(1) - ptB.get()(1)) / (ptA.get()(0) - ptB.get()(0));
            auto x_component = -slope;
            auto y_component = 1;
            auto const_coeff = slope * ptA.get()(0) - ptA.get()(1);
            line = {x_component, y_component, const_coeff};
        }

        // A line formed from the equation Ay - B*x + c = 0
        constexpr Line(scalar_type x_coeff, scalar_type y_coeff, scalar_type const_coeff)
        {
            line = {x_coeff, y_coeff, const_coeff};
        }

        constexpr Line(const value_type& val)
            : line{val}
        {
        }

        constexpr auto get() const noexcept
        {
            return line;
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