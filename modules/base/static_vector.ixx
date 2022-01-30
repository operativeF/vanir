
export module Nil.SVector;

import <limits>;

import Boost.TMP;

export
{

using namespace boost::tmp;

template<size_t Capacity>
using size_type = call_<
                   if_<less_eq_<sizet_<std::numeric_limits<unsigned char>::max()>>,
                    always_<unsigned char>,
                    if_<less_eq_<sizet_<std::numeric_limits<unsigned short>::max()>>,
                     always_<unsigned short>,
                     if_<less_eq_<sizet_<std::numeric_limits<unsigned int>::max()>>,
                      always_<unsigned int>,
                      if_<less_eq_<sizet_<std::numeric_limits<unsigned long>::max()>>,
                       always_<unsigned long>,
                       if_<less_eq_<sizet_<std::numeric_limits<unsigned long long>::max()>>,
                        always_<unsigned long long>,
                        always_<size_t>
                       >
                      >
                     >
                    >
                   >, sizet_<Capacity>
                  >;



} // export