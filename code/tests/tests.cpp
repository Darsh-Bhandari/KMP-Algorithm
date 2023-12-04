#include <catch2/catch_test_macros.hpp>
#include <sstream>

#include "kmp.h"

TEST_CASE("Read File Test1", "[weight=5]")
{
    KmpAlgorithm kmp;
    std::string text = kmp.readFileToString("/workspaces/fa23_cs225_.release/KMP-Algorithm/data2/10-Characters.txt");

    REQUIRE(text == "4676343341");
}

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

TEST_CASE("PreprocessLPS Test3", "[weight=5]")
{
    std::string pattern = "aabbcdeaabacdg";

    KmpAlgorithm kmp;
    kmp.preprocessLPS(pattern);

    std::vector<int> actual = kmp.getLps();
    
    REQUIRE(actual == std::vector<int>{0, 1, 0, 0, 0, 0, 0, 1, 2, 3, 1, 0, 0, 0});
}

TEST_CASE("PreprocessLPS Test4", "[weight=5]")
{
    std::string pattern = "fbsjekgbqscfbgfjbsbdbf";

    KmpAlgorithm kmp;
    kmp.preprocessLPS(pattern);

    std::vector<int> actual = kmp.getLps();
    
    REQUIRE(actual == std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 1});
}

TEST_CASE("PreprocessLPS Test5", "[weight=5]")
{
    std::string pattern = "a";

    KmpAlgorithm kmp;
    kmp.preprocessLPS(pattern);

    std::vector<int> actual = kmp.getLps();
    
    REQUIRE(actual == std::vector<int>{0});
}

TEST_CASE("SearchKMP Test1 (10 Characters)", "[weight=5]")
{
    KmpAlgorithm kmp;
    std::string text = kmp.readFileToString("/workspaces/fa23_cs225_.release/KMP-Algorithm/data2/10-Characters.txt");

    std::string pattern = "34";

    size_t worstCaseNumComparisons = text.size();

    
    std::vector<int> indices = kmp.searchKMP(text, pattern);
    size_t actualNumOfComparisons = kmp.getNumComparisons();

    std::vector<int> toCompare;
    size_t normalStringSearch = text.find(pattern);
    while (normalStringSearch != std::string::npos) {
        toCompare.push_back(normalStringSearch);
        normalStringSearch = text.find(pattern, normalStringSearch + 1);
    }

    REQUIRE(indices == toCompare);
    REQUIRE(actualNumOfComparisons <= worstCaseNumComparisons);
}

TEST_CASE("SearchKMP Test2 (100 Characters)", "[weight=5]")
{
    KmpAlgorithm kmp;
    std::string text = kmp.readFileToString("/workspaces/fa23_cs225_.release/KMP-Algorithm/data2/Hp-100-Characters.txt");

    std::string pattern = "ri";

    size_t worstCaseNumComparisons = text.size();

    
    std::vector<int> indices = kmp.searchKMP(text, pattern);
    size_t actualNumOfComparisons = kmp.getNumComparisons();

    std::vector<int> toCompare;
    size_t normalStringSearch = text.find(pattern);
    while (normalStringSearch != std::string::npos) {
        toCompare.push_back(normalStringSearch);
        normalStringSearch = text.find(pattern, normalStringSearch + 1);
    }

    REQUIRE(indices == toCompare);
    REQUIRE(actualNumOfComparisons <= worstCaseNumComparisons);
}


TEST_CASE("SearchKMP Test3 (1,000 Characters)", "[weight=5]")
{
    KmpAlgorithm kmp;
    std::string text = kmp.readFileToString("/workspaces/fa23_cs225_.release/KMP-Algorithm/data/Percy.txt");

    std::string pattern = "half-blood";

    size_t worstCaseNumComparisons = text.size();

    
    std::vector<int> indices = kmp.searchKMP(text, pattern);
    size_t actualNumOfComparisons = kmp.getNumComparisons();

    std::vector<int> toCompare;
    size_t normalStringSearch = text.find(pattern);
    while (normalStringSearch != std::string::npos) {
        toCompare.push_back(normalStringSearch);
        normalStringSearch = text.find(pattern, normalStringSearch + 1);
    }

    REQUIRE(indices == toCompare);
    REQUIRE(actualNumOfComparisons <= worstCaseNumComparisons);
}

TEST_CASE("SearchKMP Test4 (10,448 Characters)", "[weight=5]")
{
    KmpAlgorithm kmp;
    std::string text = kmp.readFileToString("/workspaces/fa23_cs225_.release/KMP-Algorithm/data2/Wonderland-10448-Characters.txt");

   std::string text = kmp.readFileToString(filePath);

    std::string pattern = "the";

    size_t worstCaseNumComparisons = text.size();
    
    std::vector<int> indices = kmp.searchKMP(text, pattern);
    size_t actualNumOfComparisons = kmp.getNumComparisons();

    std::vector<int> toCompare;
    size_t normalStringSearch = text.find(pattern);
    while (normalStringSearch != std::string::npos) {
        toCompare.push_back(normalStringSearch);
        normalStringSearch = text.find(pattern, normalStringSearch + 1);
    }

    

    REQUIRE(indices == toCompare);
    REQUIRE(actualNumOfComparisons <= worstCaseNumComparisons);
}

TEST_CASE("SearchKMP Test5 (101,148 Characters)", "[weight=5]")
{
    KmpAlgorithm kmp;
    std::string text = kmp.readFileToString("/workspaces/fa23_cs225_.release/KMP-Algorithm/data2/Lotr-101148-Characters.txt");

    std::string pattern = "Frodo";

    size_t worstCaseNumComparisons = text.size();

    std::vector<int> indices = kmp.searchKMP(text, pattern);
    size_t actualNumOfComparisons = kmp.getNumComparisons();

    std::vector<int> toCompare;
    size_t normalStringSearch = text.find(pattern);
    while (normalStringSearch != std::string::npos) {
        toCompare.push_back(normalStringSearch);
        normalStringSearch = text.find(pattern, normalStringSearch + 1);
    }

    REQUIRE(indices == toCompare);
    REQUIRE(actualNumOfComparisons <= worstCaseNumComparisons);

}

TEST_CASE("SearchKMP Test6 (101,148 Characters)", "[weight=5]")
{
    KmpAlgorithm kmp;
    std::string text = kmp.readFileToString("/workspaces/fa23_cs225_.release/KMP-Algorithm/data2/Lotr-101148-Characters.txt");

    std::string pattern = "pa";

    size_t worstCaseNumComparisons = text.size();

    std::vector<int> indices = kmp.searchKMP(text, pattern);
    size_t actualNumOfComparisons = kmp.getNumComparisons();

    std::vector<int> toCompare;
    size_t normalStringSearch = text.find(pattern);
    while (normalStringSearch != std::string::npos) {
        toCompare.push_back(normalStringSearch);
        normalStringSearch = text.find(pattern, normalStringSearch + 1);
    }

    REQUIRE(indices == toCompare);
    REQUIRE(actualNumOfComparisons <= worstCaseNumComparisons);

}

TEST_CASE("SearchKMP Test7 (506,516 Characters)", "[weight=5]")
{
    KmpAlgorithm kmp;
    std::string text = kmp.readFileToString("/workspaces/fa23_cs225_.release/KMP-Algorithm/data2/Hobbit-506516-Characters.txt");

    std::string pattern = "Gandalf";

    size_t worstCaseNumComparisons = text.size();

    std::vector<int> indices = kmp.searchKMP(text, pattern);
    size_t actualNumOfComparisons = kmp.getNumComparisons();

    std::vector<int> toCompare;
    size_t normalStringSearch = text.find(pattern);
    while (normalStringSearch != std::string::npos) {
        toCompare.push_back(normalStringSearch);
        normalStringSearch = text.find(pattern, normalStringSearch + 1);
    }

    REQUIRE(indices == toCompare);
    REQUIRE(actualNumOfComparisons <= worstCaseNumComparisons);

}

TEST_CASE("SearchKMP Test8 (506,516 Characters)", "[weight=5]")
{
    KmpAlgorithm kmp;
    std::string text = kmp.readFileToString("/workspaces/fa23_cs225_.release/KMP-Algorithm/data2/Hobbit-506516-Characters.txt");

    std::string pattern = "ed";

    size_t worstCaseNumComparisons = text.size();

    std::vector<int> indices = kmp.searchKMP(text, pattern);
    size_t actualNumOfComparisons = kmp.getNumComparisons();

    std::vector<int> toCompare;
    size_t normalStringSearch = text.find(pattern);
    while (normalStringSearch != std::string::npos) {
        toCompare.push_back(normalStringSearch);
        normalStringSearch = text.find(pattern, normalStringSearch + 1);
    }

    REQUIRE(indices == toCompare);
    REQUIRE(actualNumOfComparisons <= worstCaseNumComparisons);

}

TEST_CASE("SearchKMP Test9 (2,462,922 Characters)", "[weight=5]")
{
    KmpAlgorithm kmp;
    std::string text = kmp.readFileToString("/workspaces/fa23_cs225_.release/KMP-Algorithm/data2/Lotr-2462922-Characters.txt");

    std::string pattern = "ru";

    size_t worstCaseNumComparisons = text.size();

    std::vector<int> indices = kmp.searchKMP(text, pattern);
    size_t actualNumOfComparisons = kmp.getNumComparisons();

    std::vector<int> toCompare;
    size_t normalStringSearch = text.find(pattern);
    while (normalStringSearch != std::string::npos) {
        toCompare.push_back(normalStringSearch);
        normalStringSearch = text.find(pattern, normalStringSearch + 1);
    }

    REQUIRE(indices == toCompare);
    REQUIRE(actualNumOfComparisons <= worstCaseNumComparisons);

}

TEST_CASE("SearchKMP Test10 (2,462,922 Characters)", "[weight=5]")
{
    KmpAlgorithm kmp;
    std::string text = kmp.readFileToString("/workspaces/fa23_cs225_.release/KMP-Algorithm/data2/Lotr-2462922-Characters.txt");

    std::string pattern = "Baggins";

    size_t worstCaseNumComparisons = text.size();

    std::vector<int> indices = kmp.searchKMP(text, pattern);
    size_t actualNumOfComparisons = kmp.getNumComparisons();

    std::vector<int> toCompare;
    size_t normalStringSearch = text.find(pattern);
    while (normalStringSearch != std::string::npos) {
        toCompare.push_back(normalStringSearch);
        normalStringSearch = text.find(pattern, normalStringSearch + 1);
    }

    REQUIRE(indices == toCompare);
    REQUIRE(actualNumOfComparisons <= worstCaseNumComparisons);

}

TEST_CASE("SearchKMP Test11 (2,462,922 Characters)", "[weight=5]")
{
    KmpAlgorithm kmp;
    std::string text = kmp.readFileToString("/workspaces/fa23_cs225_.release/KMP-Algorithm/data2/Lotr-2462922-Characters.txt");

    std::string pattern = "BAGGINS";

    size_t worstCaseNumComparisons = text.size();

    std::vector<int> indices = kmp.searchKMP(text, pattern);
    size_t actualNumOfComparisons = kmp.getNumComparisons();

    std::vector<int> toCompare;
    size_t normalStringSearch = text.find(pattern);
    while (normalStringSearch != std::string::npos) {
        toCompare.push_back(normalStringSearch);
        normalStringSearch = text.find(pattern, normalStringSearch + 1);
    }

    REQUIRE(indices == toCompare);
    REQUIRE(actualNumOfComparisons <= worstCaseNumComparisons);

}

