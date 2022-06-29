export module Vanir.Geometry.Triangle;

import Vanir.Geometry.Point;

import <Eigen/Dense>;

export namespace Vanir::Geo
{
    template<typename Scalar, size_t Dim>
    struct Triangle
    {
        using value_type  = typename Eigen::Matrix<Scalar, Dim, 3>;
        using comp_type   = typename Eigen::Matrix<Scalar, Dim, 1>;
        using scalar_type = Scalar;
        using width       = std::integral_constant<int, 3>;
        using dim         = std::integral_constant<int, Dim>;

        constexpr Triangle() = default;

        constexpr Triangle(const Point<scalar_type, Dim>& ptA,
                           const Point<scalar_type, Dim>& ptB,
                           const Point<scalar_type, Dim>& ptC)
        {
            tri.col(0) << ptA.pt;
            tri.col(1) << ptB.pt;
            tri.col(2) << ptC.pt;
        }

        constexpr Triangle(scalar_type sideA,
                           scalar_type sideB,
                           scalar_type sideC)
        {

        }

        constexpr auto get() const noexcept
        {
            return tri;
        }
        
        value_type tri{};
    };

    using Triangle2d = Triangle<double, 2>;
    using Triangle2f = Triangle<float, 2>;
    using Triangle2i = Triangle<int, 2>;

    using Triangle3d = Triangle<double, 3>;
    using Triangle3f = Triangle<float, 3>;
    using Triangle3i = Triangle<int, 3>;
} // export namespace Vanir::Geometry