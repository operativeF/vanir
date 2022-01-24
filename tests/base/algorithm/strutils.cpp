
import Nil.MetaTest;
import Utils.Strings.Modifying;

import <string_view>;

namespace ut = boost::ut;

ut::suite StrModifyingAlgorithmTests = []
{
    using namespace ut;
    using namespace nil::utils;

    "ReplaceAll"_test = []
    {
        "Non-Replacing"_test = []
        {
            std::string nonrep{"The quick fox jumped over the lazy dog."};

            ReplaceAll(nonrep, "slow", "fast");

            expect("The quick fox jumped over the lazy dog." == nonrep);

            ReplaceAll(nonrep, "", "");

            expect("The quick fox jumped over the lazy dog." == nonrep);
        };

        "Case sensitivity"_test = []
        {
            std::string repCS{"The QUICK fox."};

            ReplaceAll(repCS, "quick", "slow");

            expect("The QUICK fox." == repCS);

            ReplaceAll(repCS, "QUICK", "slow");

            expect("The slow fox." == repCS);
        };
    };

    "TrimLeadingSpace"_test = []
    {
        "String-based"_test = []
        {
            std::string lstr{"  leading space.  "};
            std::string emptyStr{""};
            std::string onlyStr{"     "};
            
            TrimLeadingSpace(lstr);
            TrimLeadingSpace(emptyStr);
            TrimLeadingSpace(onlyStr);

            expect(lstr == "leading space.  ");
            expect(emptyStr == "");
            expect(onlyStr == "");
        };

        "Container-based"_test = []
        {

        };
    };

    "TrimTrailingSpace"_test = []
    {

    };

    "TrimAllSpace"_test = []
    {

    };

    "ToUpper"_test = []
    {

    };

    "ToLower"_test = []
    {

    };

    "EraseSubstr"_test = []
    {

    };
};
