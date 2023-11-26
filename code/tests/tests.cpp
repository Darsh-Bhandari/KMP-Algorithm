#include <catch2/catch_test_macros.hpp>
#include <sstream>

#include "kmp.h"

TEST_CASE("PreprocessLPS Test1", "[weight=5]")
{
    std::string pattern = "AAAAA";
    std::vector<int> lps;
    preprocessLPS(pattern, lps);

    REQUIRE(lps == std::vector<int>{0, 1, 2, 3, 4});
}

TEST_CASE("PreprocessLPS Test2", "[weight=5]")
{
    std::string pattern = "ABCDEA";
    std::vector<int> lps;
    preprocessLPS(pattern, lps);

    REQUIRE(lps == std::vector<int>{0, 0, 0, 0, 0, 1});
}

TEST_CASE("SearchKMP Test", "[weight=5]")
{
    std::string text = readFileToString("/workspaces/fa23_cs225_.release/KMP-Algorithm/data/Percy.txt");

   // std::string text = readFileToString("/workspaces/fa23_cs225_.release/KMP-Algorithm/data/LotrBook.txt");

    std::cout << text << std::endl;

    std::string pattern = "half-blood";

    size_t worstCaseNumComparisons = text.size();

   //std::string pattern = "'I'm sure it is,' said Frodo. 'But we can't go any quicker, if we are to see Bilbo. I am going to Rivendell first, whatever happens.''Yes, I think you had better do that,'";

    std::vector<int> indices = searchKMP(text, pattern);
    size_t actualNumOfComparisons = getNumComparisons();

    std::vector<int> toCompare;
    size_t normalStringSearch = text.find(pattern);
    while (normalStringSearch != std::string::npos) {
        std::cout << normalStringSearch << std::endl;
        toCompare.push_back(normalStringSearch);
        normalStringSearch = text.find(pattern, normalStringSearch + 1);
    }

    REQUIRE(indices == toCompare);
    REQUIRE(actualNumOfComparisons <= worstCaseNumComparisons);
}