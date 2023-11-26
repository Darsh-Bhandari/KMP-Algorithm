/**
 * @file kmp.h
 */

#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <fstream>

class KmpAlgorithm {
    public:
        void preprocessLPS(const std::string& pattern); // Construct the lps array
        std::vector<int> searchKMP(const std::string& text, const std::string& pattern); // Conduct pattern searching
        std::string readFileToString(const std::string& filePath); // Convert file to text to be analyzed
        void incrementNumComparisons(); // Increment the number of comparisons done between characters in text
        size_t getNumComparisons(); // Return the number of comparisons done between characters in text
        std::vector<int> getLps(); // Return the lps array constructed for a pattern

    private:
        size_t numComparisons = 0; // Keep track of number of comparisons done in pattern search
        std::vector<int> lps; // Store lps array for pattern matching
        
};

