//  Copyright 2019-2021 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

#if defined(__GNUC__) || defined(__clang__)
#include <array>
#include <cstdint>
#endif // defined(__GNUC__ ) || defined(__clang__)

#if defined(__GNUC__)
#include <fmt/core.h>
#elif defined(__clang__)
#include <format>
#endif // defined(__GNUC__)

import boost.ut;
import Utils.Bitfield;

import Boost.TMP;

#if _MSC_VER
import std;
#endif // _MSC_VER

#if defined(__GNUC__)
namespace stfmt = fmt;
#elif defined(_MSC_VER) || defined(__clang__)
namespace stfmt = std;
#endif // defined(__GNUC__)

namespace ut = boost::ut;

// Exclusive bitflag example
enum class Borders
{
    Single,
    Double,
    Triple,
    Raised,
    _max_size
};

// Combinable bitflag example
enum class Styles
{
    Italic,
    Bold,
    Underline,
    Strikethrough,
    _max_size
};

using StyleFlags = vanir::utils::InclBitfield<Styles>;

ut::suite BitfieldTests = []
{
    using namespace ut;
    
    "Multiple value construction"_test = []
    {
        StyleFlags newStyles{Styles::Bold, Styles::Italic, Styles::Underline};

        constexpr auto newStylesSetFlags = StyleFlags{Styles::Italic, Styles::Bold, Styles::Underline};

        expect(newStyles == newStylesSetFlags);
    };

    "Toggle On / Off"_test = []
    {
        StyleFlags styles;

        styles.toggle(Styles::Italic);

        expect(styles == StyleFlags{Styles::Italic});

        styles.toggle(Styles::Italic);

        expect(styles == StyleFlags{});
    };

    "Set / Reset"_test = []
    {
        StyleFlags styles;

        styles.set(Styles::Bold);

        expect(styles == StyleFlags{Styles::Bold});

        styles.reset(Styles::Bold);

        expect(styles == StyleFlags{});
    };

    "Comparison operators"_test = []
    {
        StyleFlags newStyles;
        StyleFlags styles;

        expect(styles == newStyles);

        newStyles.set(Styles::Bold);
        expect(styles != newStyles);
    };
};

ut::suite BitfieldOpTests = []
{
    using namespace ut;
    using namespace vanir::utils;

    "& operator"_test = []
    {
        StyleFlags styles{Styles::Strikethrough, Styles::Bold};
        StyleFlags altStyles{Styles::Bold, Styles::Italic};
        StyleFlags emptyStyles{};

        auto resultStyle = styles & Styles::Bold;

        expect(resultStyle == StyleFlags{Styles::Bold});

        auto bothStyles = styles & altStyles;

        expect(bothStyles == StyleFlags{Styles::Bold});

        auto noStyles = styles & emptyStyles;
        auto stillNoStyles = emptyStyles & Styles::Bold;

        expect(noStyles == StyleFlags{});
        expect(stillNoStyles == StyleFlags{});
    };

    "&= operator"_test = []
    {
        StyleFlags styles{Styles::Strikethrough};

        styles &= Styles::Strikethrough;

        expect(styles == StyleFlags{Styles::Strikethrough});

        styles.set(Styles::Italic);

        styles &= Styles::Bold;

        expect(styles.as_value() == 0);
    };

    "|= operator"_test = []
    {
        StyleFlags styles;

        styles |= Styles::Bold;
        styles |= Styles::Strikethrough;

        expect(styles == StyleFlags{Styles::Bold, Styles::Strikethrough});
    };

    "^= operator"_test = []
    {
        StyleFlags styles;

        styles ^= Styles::Bold;

        expect(styles == StyleFlags{Styles::Bold});

        styles ^= Styles::Bold;

        expect(styles == StyleFlags{});
    };

    "Set All / Clear"_test = []
    {
        StyleFlags styles;

        styles.set_all();

        expect(styles.as_value() == StyleFlags::AllFlagsSet);
        expect(styles == StyleFlags{Styles::Italic, Styles::Bold, Styles::Underline, Styles::Strikethrough});

        styles.clear();

        expect(styles.as_value() == 0);
    };
};

template<typename T, std::size_t N>
struct check_array : std::array<T, N> {};

template<typename... Args>
check_array(Args...) -> check_array<std::common_type_t<Args...>, sizeof...(Args)>;

ut::suite BitfieldMetaTest = []
{
    using namespace ut;

    using namespace boost::tmp;
    using namespace vanir::utils;

    using resolute = bitfield<check_array{Styles::Bold, Styles::Underline}, check_array{Styles::Italic, Styles::Underline, Styles::Bold}>;

    // ERROR: C7595, Call to immediate function is not a constant expression.
    // resolute newres{Styles::Bold, Styles::Italic};

    // resolute oldres{Borders::Double, Borders::Single};

    // Throws.
    // resolute oldres{Styles::Bold, Styles::Italic, Styles::Underline};
};

ut::suite CombineBitfieldTest = []
{
    using namespace ut;
    using namespace vanir::utils;

    using cb = CombineBitfield<Borders, Styles>;

    cb newcb{Borders::Raised, Styles::Italic};

    expect(newcb.max_options == 8);

    expect(newcb.enum_offset(Borders::Double) == 0) << stfmt::format("{}", newcb.enum_offset(Borders::Double));
    expect(newcb.enum_offset(Styles::Bold) == 4) << stfmt::format("{}", newcb.enum_offset(Styles::Bold));

    expect(newcb.enum_offset_value(Borders::Triple) == 2) << stfmt::format("{}", newcb.enum_offset_value(Borders::Triple));
    expect(newcb.enum_offset_value(Styles::Strikethrough) == (static_cast<int>(Borders::_max_size) + static_cast<int>(Styles::Strikethrough)))
        << stfmt::format("{}", newcb.enum_offset_value(Styles::Strikethrough));

    "Operator tests"_test = []
    {
        cb optest{};

        const cb BoldTripleBitset{Styles::Bold, Borders::Triple};

        optest |= Styles::Bold;
        optest |= Borders::Triple;

        expect(optest == BoldTripleBitset);

        // Test clear
        optest.clear();

        expect(optest == cb{});
        expect(optest.empty());

        // Toggle bits
        optest ^= Borders::Single;
        optest ^= Styles::Underline;

        expect(optest == cb{Styles::Underline, Borders::Single});

        optest ^= Styles::Underline;

        expect(optest == cb{Borders::Single});

        optest ^= Borders::Single;

        expect(!optest);

        optest.set_all();
        expect(optest == cb{Borders::Single, Borders::Double, Borders::Triple, Borders::Raised,
                            Styles::Bold, Styles::Italic, Styles::Strikethrough, Styles::Underline});
        
        optest.toggle_all();

        expect(optest.empty());

        optest.set_all();
        optest.reset(Borders::Single);
        optest.toggle_all();

        const cb zero_bitset{Borders::Single};
        expect(zero_bitset.as_enum_value() == 0) << stfmt::format("{}", zero_bitset.as_enum_value());
        expect(zero_bitset.as_value() == 1) << stfmt::format("{}", zero_bitset.as_value());
    };
};
