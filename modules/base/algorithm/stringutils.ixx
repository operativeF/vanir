export module Utils.Strings;

export import Utils.Strings.Modifying;
export import Utils.Strings.Nonmodifying;
export import Utils.Strings.Unsafe;

#ifdef __GNUC__
import <ranges>;
#elif __clang__
import std;
#elif _MSC_VER
import std;
#endif

export template<size_t N>
struct StrLit
{
    constexpr StrLit(const char (&str)[N])
    {
        std::ranges::copy_n(str, N, value);
    }

    char value[N];
};
