//  Copyright 2019-2021 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

module;

#if defined(__GNUC__) || defined(__clang__)
#include <cstdint>
#include <numbers>
#include <type_traits>
#endif // defined(__GNUC__ ) || defined(__clang__)

#include <Eigen/Dense>

export module Vanir.Geometry.Ops;

import Vanir.Geometry.Point;
import Vanir.Geometry.Segment;

#if _MSC_VER
import std;
#endif // _MSC_VER

export namespace Vanir::Geo
{
    constexpr auto ToRadians(auto degrees)
    {
        return degrees * std::numbers::pi / 180.0;
    }

    constexpr auto ToDegrees(auto radians)
    {
        return radians * 180.0 / std::numbers::pi;
    }

    constexpr auto perimeter(const auto& geoObj)
    {
        using geo_type = std::remove_reference_t<decltype(geoObj)>;

        auto obj = geoObj.get();

        typename geo_type::scalar_type value{};

        for(int i{0}; i != geo_type::width::value; ++i)
        {
            if(i == (geo_type::width::value - 1))
            {
                value += (obj.col(0) - obj.col(i)).norm();
            }
            else
            {
                value += (obj.col(i + 1) - obj.col(i)).norm();
            }
        }

        return value;
    }

    constexpr auto area(auto&& geoObj)
    {

    }

    constexpr auto volume(auto&& geoObj)
    {

    }

    constexpr auto translate(auto&& geoObj, auto&& trVec)
    {
        using trvec_type = std::remove_reference_t<decltype(trVec)>;
        using geoobj_type = std::remove_reference_t<decltype(geoObj)>;

        Eigen::Transform<trvec_type::scalar_type,
                         trvec_type::dim::value,
                         Eigen::TransformTraits::Affine> t;
        t = (Eigen::Translation<trvec_type::scalar_type,
                                trvec_type::dim::value>(trVec.get()));

        return geoobj_type{(t * geoObj.get()).eval()};
    }

    constexpr auto centroid(auto&& closedObj)
    {
        using obj_type = std::remove_reference_t<decltype(closedObj)>;
        using pt_type  = Point<obj_type::scalar_type, obj_type::dim::value>;
        return pt_type{(closedObj.get().rowwise().sum() / obj_type::width::value).eval()};
    }

    constexpr auto center_of_mass(auto&& geoObj)
    {

    }

    constexpr auto rotation(auto&& geoObj, auto angle, auto axis)
    {
            // auto sideLength   = (pt.get() - origin.get()).norm();
            // auto cr = circumradius(sideLength, NSides);
            // double angleAtOriginPtFromUnitZero = std::numbers::pi + (ToRadians(0.5 * InteriorAngle));
            // auto centerPt = comp_type{origin.get()(0, 0) - cr * std::cos(angleAtOriginPtFromUnitZero),
            //                           origin.get()(1, 0) - cr * std::sin(angleAtOriginPtFromUnitZero)};

            // TODO: Factor out rotation, as both centerPts can be calculated beforehand
            // The number of rotations can then be just taken as a matrix input.
            // auto translateCoords = Eigen::Translation<scalar_type, Dim>(centerPt);

            // for(auto i{0}; i < NSides; ++i)
            // {
            //     // V(i) = T * Rot * T^-1 * StartingVec
            //     polyn.col(i) = translateCoords *
            //                    Eigen::Rotation2D(V2VRotationAngle * i) *
            //                    translateCoords.inverse() *
            //                    origin.get();
            // }
    }

    constexpr auto resize(auto&& geoObj, auto&& scale)
    {
        
    }

    // Generate bounding box / square for regular polygons
    // Represented by a vector from the minimum-to-maximum points (diagonal)
    constexpr auto bounding_box(auto&& geoObj)
    {
        using obj_t    = std::remove_reference_t<decltype(geoObj)>;
        using scalar_t = typename obj_t::scalar_type;
        using dim_t    = typename obj_t::dim;

        if constexpr(!std::is_same_v<obj_t::value_type, Eigen::Matrix<scalar_t, dim_t::value, 2>>)
        {
            return Segment<scalar_t, dim_t::value>{
                Point<scalar_t, dim_t::value>{geoObj.get().row(0).minCoeff(),
                                              geoObj.get().row(1).minCoeff()},
                Point<scalar_t, dim_t::value>{geoObj.get().row(0).maxCoeff(),
                                              geoObj.get().row(1).maxCoeff()}                                                                    
            };
        }
        else // circle (always axis aligned)
        {
            return Segment<scalar_t, dim_t::value>{
                Point<scalar_t, dim_t::value>{geoObj.getCenter()(0, 0) - geoObj.getRadius(),
                                              geoObj.getCenter()(1, 0) - geoObj.getRadius()},
                Point<scalar_t, dim_t::value>{geoObj.getCenter()(0, 0) + geoObj.getRadius(),
                                              geoObj.getCenter()(1, 0) + geoObj.getRadius()}
            };
        }
    }

} // export namespace Vanir::Geometry