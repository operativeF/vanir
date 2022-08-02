
//  Copyright 2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

module;

#if defined(__GNUC__) || defined(__clang__)
#include <cstdint>
#endif // defined(__GNUC__ ) || defined(__clang__)

export module Nil.SVector;

import Boost.TMP;

#if _MSC_VER
import std;
#endif // _MSC_VER

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