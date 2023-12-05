/**
 * @file main.cpp
 */

#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>
#include <chrono>

#include "kmp.h"

using namespace std;

int main()
{
    // Manual calculation
    // std::string text = kmp.readFileToString("../../data/Hp-100-Characters.txt");

    std::cout << "Test Example" << std::endl;

    KmpAlgorithm kmp1;

    std::string manualText = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas non porttitor nulla, nec blandit sem";

    std::string pattern = "ip";

    size_t worstCaseNumComparisons = manualText.size();

    std::vector<int> indices = kmp1.searchKMP(manualText, pattern);

    std::cout << "Text: " << manualText << std::endl;
    std::cout << "Pattern: " << pattern << std::endl;
    std::cout << "Indices: ";

    for (unsigned i = 0; i < indices.size(); i++) {
        std::cout << indices[i] << " ";
    }
    std::cout << std::endl;

    // Benchmarking
    vector<string> flist = {"../../data/10-Characters.txt", "../../data/Hp-100-Characters.txt", "../../data/Percy-1000-Characters.txt", \
                 "../../data/Wonderland-10448-Characters.txt", "../../data/Lotr-101148-Characters.txt", "../../data/Hobbit-506516-Characters.txt", \
                 "../../data/Lotr-2462922-Characters.txt"}; // filedir list
    vector<string> fnames = {"10 Characters", "HP", "Percy", "Wonderland", "LoTR", "Hobbit", "Full LoTR"}; // filename list
    int nAvg = 100; // number of times to find average algo time
    std::cout << "Benchmarking for Datasets (100 runs)" << std::endl; 
    for (size_t i = 0; i < flist.size(); i++) { // loop through each dataset
        KmpAlgorithm kmp; // create kmp object
        string text = kmp.readFileToString(flist[i]); // read file text
        auto start = chrono::high_resolution_clock::now(); // start clock
        for (int k = 0; k < nAvg; k++) {
            kmp.searchKMP(text, "hellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohellohello"); // run algorithm
        }
        auto stop = chrono::high_resolution_clock::now(); // stop clock
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); // get time
        int avgTime = (int) duration.count(); // get avgTime
        std::cout << "Time taken for " << fnames[i] << " dataset: " << avgTime << " microseconds" << std::endl; // print time
    }
    return 0;
}