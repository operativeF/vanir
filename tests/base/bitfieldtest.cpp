
import Nil.MetaTest;
import Utils.Bitfield;

import Boost.TMP;

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

using StyleFlags = nil::utils::InclBitfield<Styles>;

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
    using namespace nil::utils;

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

ut::suite BitfieldMetaTest = []
{
    using namespace ut;

    using namespace boost::tmp;
    using namespace nil::utils;    
};
