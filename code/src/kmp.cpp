/**
* @file kmp.cpp
*/

#include "kmp.h"

void KmpAlgorithm::preprocessLPS(const std::string& pattern) { // Construct the lps array

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

std::vector<int> KmpAlgorithm::searchKMP(const std::string& text, const std::string& pattern) { // Conduct pattern searching
    std::vector<int> solution;

    int textSize = text.size();
    int patternSize = pattern.size();

    preprocessLPS(pattern);

    int textIndex = 0;
    int patternIndex = 0;
    
    while (textIndex < textSize) {
        incrementNumComparisons();
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

std::string KmpAlgorithm::readFileToString(const std::string& filePath) { // Convert file to text to be analyzed
    /*
        TO-DO: figure out how to make it such that avoiding newline characters doesn't cause the text to break near the end.
    */
    std::ifstream file(filePath); // Convert file path to ifstream to be read

    if (!file.is_open()) { // check if the file is open
        return "No file read.";
    }
  
    std::stringstream buffer;
    buffer << file.rdbuf(); // extract buffer stream from file
    std::string content = buffer.str(); // change to string
    file.close();

    content.erase(std::remove(content.begin(), content.end(), '\n'), content.end()); // remove the newline characters
    content.erase(std::remove(content.begin(), content.end(), '\r'), content.end()); // remove the return characters


    return content; // return text
}

size_t KmpAlgorithm::getNumComparisons() { // Return the number of comparisons done between characters in text
    return numComparisons;
}

void KmpAlgorithm::incrementNumComparisons() { // Increment the number of comparisons done between characters in text
    numComparisons += 1;
}

std::vector<int> KmpAlgorithm::getLps() { // Return the lps array constructed for a pattern
    return lps;
}

