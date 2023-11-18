/**
 * @file kmp.h
 */

#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

void preprocessLPS(const std::string& pattern, std::vector<int>& lps);

std::vector<int> searchKMP(const std::string& text, const std::string& pattern);

std::string readFileToString(const std::string& filePath);