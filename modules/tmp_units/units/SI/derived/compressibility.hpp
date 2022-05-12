#ifndef POTATO_UNITS_COMPRESSIBILITY_HPP_INCLUDED
#define POTATO_UNITS_COMPRESSIBILITY_HPP_INCLUDED

//  Copyright 2019 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt

#include <ratio>

#include <boost/tmp/vocabulary.hpp>
#include <potato/engine/base.hpp>

namespace potato {
    namespace units {
        using namespace boost::tmp;

        template <typename T, typename P>
        struct inverse_pascal_impl {
            constexpr inverse_pascal_impl<T, P>() : value(0) {}
            constexpr inverse_pascal_impl<T, P>(P val) : value(val) {}

            P value;

            static constexpr auto pretty = "1/Pa";

            using is_any_impl = false_;

            using mod_ratio = T;
            using impl      = list_<list_<meter_l>, list_<gram_l, second_l, second_l>>;
        };

        using inverse_exapascal    =     inverse_pascal_impl<std::exa, long double>;
        using inverse_petapascal    =     inverse_pascal_impl<std::peta, long double>;
        using inverse_terapascal    =     inverse_pascal_impl<std::tera, long double>;
        using inverse_gigapascal    =     inverse_pascal_impl<std::giga, long double>;
        using inverse_megapascal    =     inverse_pascal_impl<std::mega, long double>;
        using inverse_kilopascal    =     inverse_pascal_impl<std::kilo, long double>;
        using inverse_hectopascal    =     inverse_pascal_impl<std::hecto, long double>;
        using inverse_decapascal    =     inverse_pascal_impl<std::deca, long double>;
        using inverse_pascal    =     inverse_pascal_impl<unity_ratio, long double>;
        using inverse_decipascal    =     inverse_pascal_impl<std::deci, long double>;
        using inverse_centipascal    =     inverse_pascal_impl<std::centi, long double>;
        using inverse_millipascal    =     inverse_pascal_impl<std::milli, long double>;
        using inverse_micropascal    =     inverse_pascal_impl<std::micro, long double>;
        using inverse_nanopascal    =     inverse_pascal_impl<std::nano, long double>;
        using inverse_picopascal    =     inverse_pascal_impl<std::pico, long double>;
        using inverse_femtopascal    =     inverse_pascal_impl<std::femto, long double>;
        using inverse_attopascal    =     inverse_pascal_impl<std::atto, long double>;

        constexpr inverse_exapascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_exapascal>(val);
        }
        constexpr inverse_petapascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_petapascal>(val);
        }
        constexpr inverse_terapascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_terapascal>(val);
        }
        constexpr inverse_gigapascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_gigapascal>(val);
        }
        constexpr inverse_megapascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_megapascal>(val);
        }
        constexpr inverse_kilopascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_kilopascal>(val);
        }
        constexpr inverse_hectopascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_hectopascal>(val);
        }
        constexpr inverse_decapascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_decapascal>(val);
        }
        constexpr inverse_pascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_pascal>(val);
        }
        constexpr inverse_decipascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_decipascal>(val);
        }
        constexpr inverse_centipascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_centipascal>(val);
        }
        constexpr inverse_millipascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_millipascal>(val);
        }
        constexpr inverse_micropascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_micropascal>(val);
        }
        constexpr inverse_nanopascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_nanopascal>(val);
        }
        constexpr inverse_picopascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_picopascal>(val);
        }
        constexpr inverse_femtopascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_femtopascal>(val);
        }
        constexpr inverse_attopascal operator""_inv_Pa(long double val) {
            return static_cast<inverse_attopascal>(val);
        }

    } // namespace units
} // namespace potato

#endif // POTATO_UNITS_INVERSE_PASCAL_HPP_INCLUDED