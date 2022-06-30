
import Vanir.Geometry;

import Nil.MetaTest;

import std.core;

namespace ut = boost::ut;

static constexpr double PrecisionValue{0.000001};

ut::suite PointTests = []
{
    using namespace ut;
    using namespace Vanir::Geo;

    "Point-to-Point Distance"_test = []
    {
        Point2d ptA(1, 1);
        Point2d ptB(3, 3);

        expect(length(ptA, ptB) == sqrt(8)) << length(ptA, ptB);
        expect(length(ptA, ptA) == 0) << length(ptA, ptA);
        expect(length(ptB, ptA) == sqrt(8)) << length(ptB, ptA);
    };

    "Point - Translate"_test = []
    {
        Point2d ptA(1, 1);
        Point2d ptB(3, -2);

        auto ptC = translate(ptA, ptB);

        expect(ptC == Point2d(4, -1));
    };
};

ut::suite GeometricShapesTest = []
{
    using namespace ut;
    using namespace Vanir::Geo;

    "Segment"_test = []
    {
        "Segment - Length"_test = []
        {
        };

        "Segment - Translate"_test = []
        {
        };
    };

    "Circle"_test = []
    {
        "Circle - Bounding box"_test = []
        {
            Circle2d circ{Segment2d{Point2d{-0.5, 0.0}, Point2d{0.5, 0.0}}};

            auto bb = bounding_box(circ);

            // Bottom-left, x
            expect(std::abs(bb.get()(0, 0) + 0.5) <= PrecisionValue) << bb.get()(0, 0);
            // Bottom-left, y
            expect(std::abs(bb.get()(1, 0) + 0.5) <= PrecisionValue) << bb.get()(1, 0);
            // Top-right, x
            expect(std::abs(bb.get()(0, 1) - 0.5) <= PrecisionValue) << bb.get()(0, 1);
            // Top-right, y
            expect(std::abs(bb.get()(1, 1) - 0.5)  <= PrecisionValue) << bb.get()(1, 1);
        };

        "Circle - 3 point construction"_test = []
        {
            Circle2d circ{Point2d{1.0, 1.0}, Point2d{2.0, 4.0}, Point2d{5.0, 3.0}};

            expect(std::abs(circ.getCenter()(0, 0) - 3.0) <= PrecisionValue) << circ.getCenter()(0, 0);
            expect(std::abs(circ.getCenter()(1, 0) - 2.0) <= PrecisionValue) << circ.getCenter()(1, 0);
        };
    };

    "Ellipse"_test = []
    {

    };

    "Polygon"_test = []
    {
        "Triangles"_test = []
        {
            // Equilateral triangle centered at (0, 0)
            Polygon2d<3> tri{Point2d{-sqrt(3.0)/2.0, -0.5}, Point2d{sqrt(3.0)/2.0, -0.5}, ConstrType::PointEdge};

            expect(std::abs(tri.get()(0, 0) - -std::sqrt(3.0)/2.0) <= PrecisionValue) << tri.get()(0, 0);
            expect(std::abs(tri.get()(1, 0) - -0.5) <= PrecisionValue) << tri.get()(1, 0);
            expect(std::abs(tri.get()(0, 1) - std::sqrt(3.0)/2.0) <= PrecisionValue) << tri.get()(0, 1);
            expect(std::abs(tri.get()(1, 1) - -0.5) <= PrecisionValue) << tri.get()(1, 1);
            expect(std::abs(tri.get()(0, 2) - 0.0) <= PrecisionValue) << tri.get()(0, 2);
            expect(std::abs(tri.get()(1, 2) - 1.0) <= PrecisionValue) << tri.get()(1, 2);

            // Equilateral triangle centered at (0, 0.5)
            Polygon2d<3> tri_1{Point2d{-sqrt(3.0)/2.0, 0.0}, Point2d{sqrt(3.0)/2.0, 0.0}, ConstrType::PointEdge};

            expect(std::abs(tri_1.get()(0, 0) - -std::sqrt(3.0)/2.0) <= PrecisionValue) << tri_1.get()(0, 0);
            expect(std::abs(tri_1.get()(1, 0) - 0.0) <= PrecisionValue) << tri_1.get()(1, 0);
            expect(std::abs(tri_1.get()(0, 1) - std::sqrt(3.0)/2.0) <= PrecisionValue) << tri_1.get()(0, 1);
            expect(std::abs(tri_1.get()(1, 1) - 0.0) <= PrecisionValue) << tri_1.get()(1, 1);
            expect(std::abs(tri_1.get()(0, 2) - 0.0) <= PrecisionValue) << tri_1.get()(0, 2);
            expect(std::abs(tri_1.get()(1, 2) - 1.5) <= PrecisionValue) << tri_1.get()(1, 2);
        };

        "Squares"_test = []
        {
            "Square - Create from two points"_test = []
            {
                auto sqr_d = sqrt(2.0)/2.0;
                // Square centered at (0, 0)
                Polygon2d<4> sq{Point2d{-sqr_d, -sqr_d}, Point2d{sqr_d, -sqr_d}, ConstrType::PointEdge};

                // Bottom-Left corner (-x, -y)
                expect(std::abs(sq.get()(0, 0) + sqr_d) <= PrecisionValue) << sq.get()(0, 0);
                expect(std::abs(sq.get()(1, 0) + sqr_d) <= PrecisionValue) << sq.get()(1, 0);

                // Bottom-Right corner (x, -y)
                expect(std::abs(sq.get()(0, 1) - sqr_d) <= PrecisionValue) << sq.get()(0, 1);
                expect(std::abs(sq.get()(1, 1) + sqr_d) <= PrecisionValue) << sq.get()(1, 1);

                // Mid-Right corner (x, y)
                expect(std::abs(sq.get()(0, 2) - sqr_d) <= PrecisionValue) << sq.get()(0, 2);
                expect(std::abs(sq.get()(1, 2) - sqr_d) <= PrecisionValue) << sq.get()(1, 2);

                // Top-Left corner (-x, y)
                expect(std::abs(sq.get()(0, 3) + sqr_d) <= PrecisionValue) << sq.get()(0, 3);
                expect(std::abs(sq.get()(1, 3) - sqr_d) <= PrecisionValue) << sq.get()(1, 3);
            };

            "Square - Bounding box"_test = []
            {
                Polygon2d<4> sqr{Point2d{-0.5, -0.5}, Point2d{0.5, -0.5}, ConstrType::PointEdge};

                auto bb = bounding_box(sqr);
                
                // Bottom-left, x
                expect(std::abs(bb.get()(0, 0) + 0.5) <= PrecisionValue) << bb.get()(0, 0);
                // Bottom-left, y
                expect(std::abs(bb.get()(1, 0) + 0.5) <= PrecisionValue) << bb.get()(1, 0);
                // Top-right, x
                expect(std::abs(bb.get()(0, 1) - 0.5) <= PrecisionValue) << bb.get()(0, 1);
                // Top-right, y
                expect(std::abs(bb.get()(1, 1) - 0.5) <= PrecisionValue) << bb.get()(1, 1);
            };
        };
    };
};
