
export module Nil.SVector;

import <algorithm>;
import <limits>;
import <type_traits>;
import <vector>;

import Boost.TMP;

export
{

using namespace boost::tmp;

template<typename T, std::size_t N>
struct cs_vector
{
    consteval cs_vector(auto&&... ts)
    {
        auto vs = std::vector{ts...};

        std::ranges::copy_n(std::begin(vs), std::size(vs), std::begin(value));
    }

    constexpr cs_vector(T val[N])
    {
        std::ranges::copy_n(std::begin(val), std::size(val), std::begin(value));
    }

    T value[N]{};
};

template<typename... Ts>
cs_vector(Ts...) -> cs_vector<std::common_type_t<Ts...>, sizeof...(Ts)>;

} // export