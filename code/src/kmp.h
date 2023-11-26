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
        void preprocessLPS(const std::string& pattern);
        std::vector<int> searchKMP(const std::string& text, const std::string& pattern);
        std::string readFileToString(const std::string& filePath);
        void incrementNumComparisons();
        size_t getNumComparisons();
        std::vector<int> getLps();

    private:
        size_t numComparisons = 0;
        std::vector<int> lps;
        
};

