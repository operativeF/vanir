
module;

#if defined(__GNUC__) || defined(__clang__)
#include <numeric>
#endif // defined(__GNUC__) || defined(__clang__)

#include <Eigen/Dense>

export module Vanir.Geometry.Circle;

import Vanir.Geometry.Line;
import Vanir.Geometry.Point;
import Vanir.Geometry.Segment;

#if _MSC_VER
import std;
#endif // _MSC_VER

export namespace Vanir::Geo
{
    // Much like the Line object, this represents
    // an object that represents an equation of the circle.
    template<typename Scalar, std::size_t Dim>
    class Circle
    {
    public:
        using value_type  = typename Eigen::Matrix<Scalar, Dim, 2>;
        using scalar_type = Scalar;
        using width       = std::integral_constant<int, 2>;
        using dim         = std::integral_constant<int, Dim>;

        // TODO: Conditionally explicit?
        // A line that is the diameter of the circle
        explicit constexpr Circle(const Segment<scalar_type, Dim>& diameter)
        {
            circle.col(0) << diameter.get().col(0); // starting point
            circle.col(1) << std::midpoint(diameter.get()(0, 1), diameter.get()(0, 0)),
                             std::midpoint(diameter.get()(1, 1), diameter.get()(1, 0)); // center point
        }

        // 2 points, a center and radius
        constexpr Circle(const Point<scalar_type, Dim>& center,
                         const Point<scalar_type, Dim>& radii)
        {
            circle.col(0) << radii;  // starting point
            circle.col(1) << center; // center point 
        }

        // 3 points on the circumference of the circle
        constexpr Circle(const Point<scalar_type, Dim>& ptA,
                         const Point<scalar_type, Dim>& ptB,
                         const Point<scalar_type, Dim>& ptC)
        {
            auto chordBA = Segment<scalar_type, Dim>(ptB, ptA);
            auto chordCB = Segment<scalar_type, Dim>(ptC, ptB);

            // std::print("\nChord BA: (({}, {}), ({}, {}))", chordBA.get()(0, 0), chordBA.get()(1, 0), chordBA.get()(0, 1), chordBA.get()(1, 1));
            // std::print("\nChord CB: (({}, {}), ({}, {}))", chordCB.get()(0, 0), chordCB.get()(1, 0), chordCB.get()(0, 1), chordCB.get()(1, 1));

            Line<scalar_type, Dim> midBA{getPerpendicularBisector(chordBA)};
            Line<scalar_type, Dim> midCB{getPerpendicularBisector(chordCB)};

            // std::print("\nLine midBA: ({}, {}, {} = 0)\n", midBA.get()(0, 0), midBA.get()(1, 0), midBA.get()(2, 0));
            // std::print("\nLine midCB: ({}, {}, {} = 0)\n", midCB.get()(0, 0), midCB.get()(1, 0), midCB.get()(2, 0));

            Eigen::Matrix<scalar_type, Dim, 2> intersectMat;
            intersectMat << midBA.get()(0, 0), midBA.get()(1, 0),
                            midCB.get()(0, 0), midCB.get()(1, 0);
            Eigen::Matrix<scalar_type, Dim, 1> b;
            b << -midBA.get()(2, 0),
                 -midCB.get()(2, 0);
            Eigen::ColPivHouseholderQR<decltype(intersectMat)> dec(intersectMat);
            Eigen::Matrix<scalar_type, Dim, 1> intersectionPt = dec.solve(b);

            // std::print("\nIntersection: ({}, {})\n", intersectionPt(0, 0), intersectionPt(1, 0));

            circle.col(0) << (intersectionPt - ptA.get());
            circle.col(1) << intersectionPt;
        }

        constexpr Circle(const Segment<scalar_type, Dim>& tangentLineA,
                         const Segment<scalar_type, Dim>& tangentLineB,
                         const Point<scalar_type, Dim>& radii)
        {
        }

        constexpr auto get() const noexcept
        {
            return circle;
        }

        // Move both of these functions to circumradius / apothem
        constexpr double getRadius() const noexcept
        {
            return circle.norm();
        }

        constexpr auto getCenter() const noexcept
        {
            return circle.col(1);
        }

        bool operator==(const Circle&) const = default;
        auto operator<=>(const Circle&) const = default;

    private:
        value_type circle{}; 
    };

    using Circle2d  = Circle<double, 2>;
    using Circle2f  = Circle<float, 2>;
    using Circle2i  = Circle<int, 2>;

    using Circle3d  = Circle<double, 3>;
    using Circle3f  = Circle<float, 3>;
    using Circle3i  = Circle<int, 3>;
} // export namespace Vanir::Geo