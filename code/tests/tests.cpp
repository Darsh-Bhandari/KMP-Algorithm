#include <catch2/catch_test_macros.hpp>
#include <sstream>

#include "kmp.h"

TEST_CASE("PreprocessLPS Test1", "[weight=5]")
{
    KmpAlgorithm kmp;
    std::string pattern = "AAAAA";
    
    kmp.preprocessLPS(pattern);

    std::vector<int> actual = kmp.getLps();

    REQUIRE(actual == std::vector<int>{0, 1, 2, 3, 4});
}

TEST_CASE("PreprocessLPS Test2", "[weight=5]")
{
    std::string pattern = "ABCDEA";

    KmpAlgorithm kmp;
    kmp.preprocessLPS(pattern);

    std::vector<int> actual = kmp.getLps();
    

    REQUIRE(actual == std::vector<int>{0, 0, 0, 0, 0, 1});
}

TEST_CASE("SearchKMP Test", "[weight=5]")
{
    KmpAlgorithm kmp;
    std::string text = kmp.readFileToString("/workspaces/fa23_cs225_.release/KMP-Algorithm/data/Percy.txt");

    std::cout << text << std::endl;

    std::string pattern = "half-blood";

    size_t worstCaseNumComparisons = text.size();

    
    std::vector<int> indices = kmp.searchKMP(text, pattern);
    size_t actualNumOfComparisons = kmp.getNumComparisons();

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