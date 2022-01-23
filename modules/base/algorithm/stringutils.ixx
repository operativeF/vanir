export module Utils.Strings;

export import Utils.Strings.Modifying;
export import Utils.Strings.Nonmodifying;
export import Utils.Strings.Unsafe;

import <algorithm>;

export template<size_t N>
struct StrLit
{
    constexpr StrLit(const char (&str)[N])
    {
        std::ranges::copy_n(str, N, value);
    }

    char value[N];
};
