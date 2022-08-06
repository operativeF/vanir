
module;

#if defined(__GNUC__) || defined(__clang__)
#include <ranges>
#endif // defined(__GNUC__) || defined(__clang__)

export module Utils.Strings;

export import Utils.Strings.Modifying;
export import Utils.Strings.Nonmodifying;
export import Utils.Strings.Unsafe;

#if _MSC_VER
import std;
#endif // _MSC_VER

export template<size_t N>
struct StrLit
{
    constexpr StrLit(const char (&str)[N])
    {
        std::ranges::copy_n(str, N, value);
    }

    char value[N];
};
