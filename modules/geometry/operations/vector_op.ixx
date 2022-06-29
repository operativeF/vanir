module;

export module Vanir.Geometry.VectorOperations;

import std.core;

export namespace Vanir::Geo
{ 
    constexpr auto length(auto&&... vec)
    {
        if constexpr((std::same_as<typename std::remove_reference_t<decltype(vec)>::width, std::integral_constant<int, 1>> && ...) &&
                      sizeof...(vec) == 2)
        { // Distance between two points; pack expansion is just for show.
            return (vec.pt - ...).norm();
        }
        else if constexpr((std::same_as<typename std::remove_reference_t<decltype(vec)>::width, std::integral_constant<int, 2>> && ...) &&
                           sizeof...(vec) == 1)
        { // Distance between two point given by a vector line; pack expansion is just for show.
            return ((vec.line.col(1) - vec.line.col(0)).norm(), ...);
        }
        else
        {
            consteval auto dummy = []() { throw; }; // Not a valid input for length calculation.
        }
    }

} // export namespace Vanir::Geo
