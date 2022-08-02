
module;

#if defined(__GNUC__) || defined(__clang__)
#include <cstdint>
#include <ranges>
#include <string>
#include <string_view>
#endif // defined(__GNUC__) || defined(__clang__)

export module Utils.Strings.Modifying;

import Utils.Chars;

#if _MSC_VER
import std;
#endif // _MSC_VER

export namespace nil::utils
{

constexpr std::size_t ReplaceAll(std::string& instr, std::string_view candidate, std::string_view replacement)
{
    std::size_t count{ 0 };

    if(candidate.empty() || replacement.empty())
        return 0;

    for (std::string::size_type pos{};
        instr.npos != (pos = instr.find(candidate.data(), pos, candidate.length()));
        pos += replacement.length(), ++count)
    {
        instr.replace(pos, candidate.length(), replacement.data(), replacement.length());
    }

    return count;
}

// Trims all space leading and following, but not in the middle.
template<typename R>
constexpr void TrimAllSpace(R& str)
{
    auto it1 = std::ranges::find_if_not(str, isWhitespace);

    str.erase(str.begin(), it1);

    auto it2 = std::ranges::find_if_not(std::ranges::reverse_view(str), isWhitespace);

    str.erase(it2.base(), str.end());
}

template<typename R>
constexpr void TrimLeadingSpace(R& str)
{
    auto it = std::ranges::find_if_not(str, isWhitespace);

    str.erase(str.begin(), it);
}

template<typename R>
constexpr void TrimTrailingSpace(R& str)
{
    auto it = std::ranges::find_if_not(std::ranges::reverse_view(str), isWhitespace);

    str.erase(it.base(), str.end());
}

template<typename R>
constexpr void ToUpper(R& str)
{
    std::ranges::transform(str, str.begin(), [](auto c) noexcept { return ToUpperCh(c); });
}

template<typename R>
constexpr void ToLower(R& str)
{
    std::ranges::transform(str, str.begin(), [](auto c) noexcept { return ToLowerCh(c); });
}

constexpr void EraseSubstr(std::string& str, std::string_view subToErase)
{
    std::size_t pos{std::string::npos};

    while((pos = str.find(subToErase)) != std::string::npos)
    {
        str.erase(pos, subToErase.length());
    }
}

} // export namespace nil::utils
