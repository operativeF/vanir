
module;

#if defined(__GNUC__) || defined(__clang__)
#include <cmath>
#include <numbers>
#endif // defined(__GNUC__) || defined(__clang__)

#include <Eigen/Dense>
#include <Eigen/Geometry>

export module Vanir.Geometry.Polygon;

import Vanir.Geometry.Point;
import Vanir.Geometry.Ops;

#ifdef _MSC_VER
import std;
#endif // _MSC_VER

export namespace Vanir::Geo
{
    enum class ConstrType
    {
        PointEdge,
        PointEdgeMirror,
        Circumscribed,
        Inscribed
    };

    // IMPROVEMENT: Consider implement tables as constexpr for csc / cot function results.
    // CONSIDER: Non-inverted sin methods or checking accuracy of invert / non-inverted functions.
    double circumradius(double side_length, double num_of_sides)
    {
        return 0.5 * side_length * (1.0 / std::sin(std::numbers::pi / num_of_sides));
    }

    double apothem(double side_length, double num_of_sides)
    {
        return 0.5 * side_length * (1.0 / std::tan(std::numbers::pi / num_of_sides));
    }

    template<typename Scalar, size_t NSides, size_t Dim>
    class Polygon
    {
    public:
        static constexpr auto   InteriorAngleSum   = (NSides - 2) * 180;
        static constexpr double InteriorAngle      = static_cast<double>(InteriorAngleSum) / NSides;
        // ACCURACY: Consider a table with inverses of sides.
        static constexpr double V2VRotationAngle = (2.0 * std::numbers::pi) / NSides;

        using value_type  = typename Eigen::Matrix<Scalar, Dim, NSides>;
        using comp_type   = typename Eigen::Matrix<Scalar, Dim, 1>;
        using scalar_type = Scalar;
        using width       = std::integral_constant<int, NSides>;
        using dim         = std::integral_constant<int, Dim>;

        // TODO: Make multiple constructors
        Polygon(const Point<scalar_type, Dim>& origin,
                const Point<scalar_type, Dim>& pt,
                ConstrType ct)
        {
            const auto sideLength   = (pt.get() - origin.get()).norm();
            const double cr = circumradius(sideLength, NSides);
            // Because the vector will be in the Quadrant III, instead of adding pi to
            // half the InteriorAngle, use the following identities to reduce precision loss:
            // cos(r/2 + pi) = -cos(r/2) and sin(r/2 + pi) = -sin(r/2)
            constexpr double angleAtOriginPtFromUnitZero = ToRadians(0.5 * InteriorAngle);
            const comp_type centerPt{origin.get()(0, 0) + cr * std::cos(angleAtOriginPtFromUnitZero), 
                                     origin.get()(1, 0) + cr * std::sin(angleAtOriginPtFromUnitZero)};

            // TODO: Factor out rotation, as both centerPts can be calculated beforehand
            // The number of rotations can then be just taken as a matrix input.
            const auto translateCoords = Eigen::Translation<scalar_type, Dim>(centerPt);

            for(auto i{0}; i != NSides; ++i)
            {
                // V(i) = T * Rot * T^-1 * StartingVec
                polyn.col(i) = translateCoords *
                               Eigen::Rotation2D(V2VRotationAngle * i) *
                               translateCoords.inverse() *
                               origin.get();
            }
        }

        const auto get() const noexcept
        {
            return polyn;
        }
        
    private:
        value_type polyn{};
    };

    template<size_t Sides>
    using Polygon2d = Polygon<double, Sides, 2>;
    template<size_t Sides>
    using Polygon2f = Polygon<float, Sides, 2>;
    template<size_t Sides>
    using Polygon2i = Polygon<int, Sides, 2>;

    template<size_t Sides>
    using Polygon3d = Polygon<double, Sides, 3>;
    template<size_t Sides>
    using Polygon3f = Polygon<float, Sides, 3>;
    template<size_t Sides>
    using Polygon3i = Polygon<int, Sides, 3>;

    using Tri2d = Polygon2d<3>;
    using Tri2f = Polygon2f<3>;
    using Tri2i = Polygon2i<3>;

    using Sqr2d = Polygon2d<4>;
    using Sqr2f = Polygon2d<4>;
} // export namespace Vanir::Geometry