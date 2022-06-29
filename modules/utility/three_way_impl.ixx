
export module Vanir.Utils.ThreeWayImpl;

import std.core;

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
