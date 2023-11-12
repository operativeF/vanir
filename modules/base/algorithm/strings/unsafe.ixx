module;

#if defined(__GNUC__) || defined(__clang__)
#include <cstdint>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>
#endif // defined(__GNUC__) || defined(__clang__)

export module Utils.Strings.Unsafe;

#if _MSC_VER
import std;
#endif // _MSC_VER

// Generally unsafe utilities to be used in circumstances where
// speed is important and / or lifetimes are a certainty.
export namespace vanir::unsafe
{

// From an input string_view, split the view on each delimiter and store each split in a vector.
// Delimiter not included.
constexpr std::vector<std::string_view> StrViewSplit(std::string_view strView, char delim)
{
    std::vector<std::string_view> output;

    std::size_t first{0};

    while (first < strView.size())
    {
        const auto second = strView.find_first_of(delim, first);

        if (first != second)
            output.emplace_back(strView.substr(first, second - first));

        if (second == std::string_view::npos)
            break;

        first = second + 1;
    }

    return output;
}

} // namespace vanir::unsafe
