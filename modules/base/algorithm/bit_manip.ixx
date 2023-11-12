
module;

#if defined(__GNUC__) || defined(__clang__)
#include <bit>
#include <cstdint>
#endif // defined(__GNUC__) || defined(__clang__)


export module Utils.BitManip;

#if _MSC_VER
import std;
#endif // _MSC_VER

export namespace vanir::utils
{

template<typename V>
consteval auto ValToBitPos(V value)
{
    if(static_cast<std::uint64_t>(value) == std::uint64_t{0})
    {
        return 0;
    }
    else if(!std::has_single_bit(static_cast<std::uint64_t>(value)))
    {
        throw; // Value must be divisible by 2 (single-bit value)
    }

    return std::countr_zero(static_cast<std::uint64_t>(value));
}

// Create a bitmask value from multiple bit positions.
consteval auto InvBitmaskValue(auto... invalid_vals)
{
    // TODO: Use size_t literal
    return ((std::rotl(1ULL, invalid_vals)) | ...);
}

// FIXME: Wrong.
consteval auto InvBitmaskRange(auto start_val, auto end_val)
{
    return std::rotl(1ULL, end_val) - std::rotl(1ULL, start_val);
}

} // export
