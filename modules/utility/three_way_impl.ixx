//  Copyright 2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

module;

#if defined(__GNUC__) || defined(__clang__)
#include <compare>
#include <cstdint>
#include <type_traits>
#endif // defined(__GNUC__ ) || defined(__clang__)

export module Vanir.Utils.ThreeWayImpl;

#if _MSC_VER
import std;
#endif // _MSC_VER

export namespace Vanir::Utils
{
    template<class T>
    concept BooleanTestableImpl = std::convertible_to<T, bool>;

    template<class T>
    concept BooleanTestable = BooleanTestableImpl<T> && requires(T&& t)
    {
        { !static_cast<T&&>(t) } -> BooleanTestableImpl;
    };

    struct synth_three_way
    {
        template<typename T, typename U>
        constexpr auto operator()(const T& Left, const U& Right)
            requires requires {
                { Left < Right } -> BooleanTestable;
                { Right < Left } -> BooleanTestable;
            }
        {
            if constexpr(std::three_way_comparable_with<T, U>)
            {
                return Left <=> Right;
            }
            else
            {
                if(Left < Right)
                {
                    return std::weak_ordering::less;
                }
                else if (Right < Left)
                {
                    return std::weak_ordering::greater;
                }
                else
                {
                    return std::weak_ordering::equivalent;
                }
            }
        }
    };

    template<class T, class U = T>
    using synth_three_way_result = decltype(synth_three_way{}(std::declval<T&>(), std::declval<U&>()));
} // export namespace Vanir::Util
