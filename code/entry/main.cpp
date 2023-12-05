/**
 * @file main.cpp
 */

#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>

#include "kmp.h"

using namespace std;

int main()
{
    KmpAlgorithm kmp;

    // std::string text = kmp.readFileToString("/workspaces/fa23_cs225_.release/KMP-Algorithm/data2/Lotr-2462922-Characters.txt");
    std::string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas non porttitor nulla, nec blandit sem";

    std::string pattern = "ip";

    size_t worstCaseNumComparisons = text.size();

    std::vector<int> indices = kmp.searchKMP(text, pattern);

    for (unsigned i = 0; i < indices.size(); i++) {
        std::cout << indices[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}