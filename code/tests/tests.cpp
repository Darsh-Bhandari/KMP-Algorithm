#include "kmp.h"
#include <catch2/catch_test_macros.hpp>
#include <sstream>

TEST_CASE("PreprocessLPS Test1", "[weight=5]")
{
    std::string pattern = "AAAAA";
    std::vector<int> lps(pattern.size(), 0);
    preprocessLPS(pattern, lps);

    REQUIRE(lps == std::vector<int>{0, 1, 2, 3, 4});
}

TEST_CASE("PreprocessLPS Test2", "[weight=5]")
{
    std::string pattern = "ABCDEA";
    std::vector<int> lps(pattern.size(), 0);
    preprocessLPS(pattern, lps);

    REQUIRE(lps == std::vector<int>{0, 0, 0, 0, 0, 1});
}

TEST_CASE("SearchKMP Test", "[weight=5]")
{
    std::string text = readFileToString("KMP-Algorithm/data/Percy.txt");
    std::string pattern = "half-blood";

    std::vector<int> indices = searchKMP(text, pattern);

    std::vector<int> toCompare;
    toCompare.push_back(17);
    toCompare.push_back(88);

    REQUIRE(indices == toCompare);
}