/**
* @file kmp.cpp
*/

#include "kmp.h"

int numComparisons = 0;

void preprocessLPS(const std::string& pattern, std::vector<int>& lps) {

    // Set the begining variables with the suffix starting at 0 and the first index being at 1
    int previous = 0;
    int current = 1;

    // Push back 0 into the 0th index as that is how all lps vectors begin
    lps.push_back(0);

    while (static_cast<unsigned>(current) < pattern.size()) { // Continue the loop until there are no more characters in pattern

        if (pattern[previous] == pattern[current]) { // If the suffix and the current character match, increment the place of the suffix 
                                                     // and current in the pattern. Push back value of the suffix
            previous++; 
            lps.push_back(previous);
            current++;
        } else if (previous != 0) { // If they don't match and the suffix isn't at the begining of the pattern, move the suffix back 
                                    // by one for next comparison
            previous = lps.at(previous - 1);
        } else if (previous == 0) { // If they don't match and the suffix is at the begining of the pattern, set the next value in the 
                                    // lps vector to zero and increment current character to look at
            lps.push_back(0); 
            current++;
        }
    }

    return;
}

std::vector<int> searchKMP(const std::string& text, const std::string& pattern) {
    std::vector<int> solution;

    int textSize = text.size();
    int patternSize = pattern.size();

    std::vector<int> lps;
    preprocessLPS(pattern, lps);

    int textIndex = 0;
    int patternIndex = 0;
    
    while (textIndex < textSize) {
        numComparisons++;
        if (pattern[patternIndex] == text[textIndex]) {
            textIndex++;
            patternIndex++;
        }
        if (patternIndex == patternSize) {
            int match = textIndex - patternIndex;
            solution.push_back(match);
            patternIndex = lps[patternIndex - 1];
        } else if (textIndex < textSize && pattern[patternIndex] != text[textIndex]) {
            if (patternIndex != 0)
                patternIndex = lps[patternIndex - 1];
            else {
                textIndex++;
            }
        }
    } 

    std::cout << "numComparisons = " << numComparisons << std::endl;
    std::cout << "textlength  = " << (textSize) << std::endl;

    return solution;
}

std::string readFileToString(const std::string& filePath) {
    std::ifstream file(filePath);
  
    std::stringstream content;
    char current;

    while (file.get(current)) {
        if (current != '\n') {
            content << current;
        }
    }

    file.close();

    return content.str();
}

size_t getNumComparisons() {
    return numComparisons;
}

