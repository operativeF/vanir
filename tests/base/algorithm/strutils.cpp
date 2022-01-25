
import Nil.MetaTest;
import Utils.Strings.Modifying;

import <string_view>;
import <vector>;

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
            std::string lstr{" \tleading space. \t"};
            std::string emptyStr{""};
            std::string onlyStr{" \t "};
            
            TrimLeadingSpace(lstr);
            TrimLeadingSpace(emptyStr);
            TrimLeadingSpace(onlyStr);

            expect(lstr == "leading space. \t");
            expect(emptyStr == "");
            expect(onlyStr == "");
        };

        "Container-based"_test = []
        {
            std::vector<char> lc = {' ', '\t', 'l', 'e', ' '};
            std::vector<char> emptyC = {};
            std::vector<char> onlyC = {' ', '\t', ' '};
            
            TrimLeadingSpace(lc);
            TrimLeadingSpace(emptyC);
            TrimLeadingSpace(onlyC);

            expect(lc == std::vector{'l', 'e', ' '});
            expect(emptyC == std::vector<char>{});
            expect(onlyC == std::vector<char>{});
        };
    };

    "TrimTrailingSpace"_test = []
    {
        "String-based"_test = []
        {
            std::string tstr{" \ttrailing space. \t"};
            std::string emptyStr{""};
            std::string onlyStr{" \t "};
            
            TrimTrailingSpace(tstr);
            TrimTrailingSpace(emptyStr);
            TrimTrailingSpace(onlyStr);

            expect(tstr == " \ttrailing space.");
            expect(emptyStr == "");
            expect(onlyStr == "");
        };

        "Container-based"_test = []
        {
            std::vector<char> tc = {' ', '\t', 'l', 'e', ' '};
            std::vector<char> emptyC = {};
            std::vector<char> onlyC = {' ', '\t', ' '};
            
            TrimTrailingSpace(tc);
            TrimTrailingSpace(emptyC);
            TrimTrailingSpace(onlyC);

            expect(tc == std::vector{' ', '\t', 'l', 'e'});
            expect(emptyC == std::vector<char>{});
            expect(onlyC == std::vector<char>{});
        };
    };

    "TrimAllSpace"_test = []
    {
        "String-based"_test = []
        {
            std::string astr{" \tall space. \t"};
            std::string emptyStr{""};
            std::string onlyStr{" \t "};
            
            TrimAllSpace(astr);
            TrimAllSpace(emptyStr);
            TrimAllSpace(onlyStr);

            expect(astr == "all space.");
            expect(emptyStr == "");
            expect(onlyStr == "");
        };

        "Container-based"_test = []
        {
            std::vector<char> ac = {' ', '\t', 'l', ' ', 'e', ' '};
            std::vector<char> emptyC = {};
            std::vector<char> onlyC = {' ', '\t', ' '};
            
            TrimAllSpace(ac);
            TrimAllSpace(emptyC);
            TrimAllSpace(onlyC);

            expect(ac == std::vector{'l', ' ', 'e'});
            expect(emptyC == std::vector<char>{});
            expect(onlyC == std::vector<char>{});
        };
    };

    "Case conversion"_test = []
    {
        std::string allLow{"all lower case."};
        std::string allUp{"ALL UPPER CASE."};

        "ToUpper"_test = [=]() mutable
        {
            ToUpper(allLow);
            ToUpper(allUp);

            expect(allLow == "ALL LOWER CASE.");
            expect(allUp == "ALL UPPER CASE.");
        };

        "ToLower"_test = [=]() mutable
        {
            ToLower(allLow);
            ToLower(allUp);

            expect(allLow == "all lower case.");
            expect(allUp == "all upper case.");
        };
    };

    "EraseSubstr"_test = []
    {

    };
};

ut::suite StrNonModifyingAlgorithmTests = []
{

};