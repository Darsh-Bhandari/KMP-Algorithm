# KMP Algorithm Project

## Algorithm Summary
The KMP Algorithm is a pattern-finding algorithm that searches for occurrences of a particular pattern in a given text. The algorithm works by precomputing an array that corresponds to the maximum length of matching proper prefixes and suffixes in the pattern. After computing this array, the search algorithm can skip unnecessary character comparisons based on that information. The KMP Algorithm has a perceived runtime of O(n) where "n" is the length of the text. However, in the worst case, it will have a run time of O(n + m) where "m" is the length of the pattern. In the worst case, it will make "n" character comparisons of the text. This makes it significantly faster than naive pattern searching which has a run time of O(n^2) and will make "(n-m+1)*m" character comparisons.

## Project Description
In our project, the KMPAlgorithm class can read text files to be searched and return a vector with all locations of the occurrence of a provided pattern. Our algorithm is meant to be case sensitive, meaning that if the pattern is "HELLO", instances of the text "hello" will not be recognized. This was a deliberate design choice as we wanted our algorithm to be exact in where it finds the patterns. A further description of the KMPAlgorithm class's methods can be found below, and descriptions of the tests can be found in the final_report.pdf file located in the documents folder.

## Github Organization
This section highlights the organization of the repository.

- Code Folder
    - Build: Contains files necessary for running all executable files.
    - Entry: Contains "main.cpp", a file that contains the main method where the KMPAlgorithm class can be declared and utilized. Benchmarking code examples are included in the main.cpp file.
    - Src: Contains the header and source file for the KMP class. Called "kmp.h" and "kmp.cpp".
    - Tests: Contains "tests.cpp", a file that has a large number of tests to assess the correctness of our algorithm.
- Data Folder
    - Contains 7 different .txt files all of increasing magnitude based on their character lengths. These are used in the tests.cpp file to assert the correctness of the algorithm. The files have 10, 100, 1000, 10448, 101148, 506516, and 2462922 characters. Other than the file with 10 characters which is just a string of numbers, the rest are excerpts from novels such as The Hobbit, Lord of the Rings, and Harry Potter and the Sorcerer's Stone.
- Documents Folder
    - Feedback: Feedback given by our mentors on the state of our project, algorithm, and repository as a whole.
    - Log: PDF file that contains weekly updates on the tasks completed by each team member and goals to be completed for the week.
    - Proposal: PDF file that contains an initial proposal of our implementation of the KMP Algorithm. Since creating this proposal, we have added to our idea significantly and made modifications as such. 
    - Final_Report: PDF file that includes a summary of our datasets, demonstrates the correctness of our algorithm, and estimates the Big O runtime.
    - Presentation: A video file that summarizes the journey taken to develop this entire project. Includes summaries on our goals from the project, the development process, and our conclusions. 

## Function Description
This section provides brief descriptions on what each function does in the KMPAlgorithm class. The source code can be found in the "kmp.h" and "kmp.cpp" files.

- Public functions
    - void preprocessLPS(const std::string& pattern)
        - Construct the lps array that is used to keep track of whether or not certain characters should be skipped in pattern matching. (Used in the searchKMP method).
    - std::vector<int> searchKMP(const std::string& text, const std::string& pattern)
        - Conduct pattern searching using the lps array constructed in the preprocessLPS function.
    - std::string readFileToString(const std::string& filePath) 
        - Convert the provided txt file to a string that can be analyzed
    - void incrementNumComparisons()
        - Increment the number of comparisons done between characters in the text. (Used in the searchKMP method)
    - size_t getNumComparisons()
        - Return the number of comparisons done between characters in text. (Used to ensure correctness of algorithm in tests)
    - std::vector<int> getLps()
        - Return the lps array constructed for a pattern. (Used to ensure correctness of algorithm in tests)
- Private member variables
    - size_t numComparisons 
        - Keep track of the number of comparisons done in the pattern search
    - std::vector<int> lps
        - Store lps array for pattern matching

## Running Instructions
This section details how to run and utilize the code.

1. Clone the repository and ensure that you are in the cs225 Fall 2023 development container to ensure correct results.
2. Open the command line/terminal and make sure you are located in the KMP-Algorithm directory. If not, use the "cd" command in the terminal to enter the KMP-Algorithm directory.
3. Use "cd /code/" to enter the code folder.
4. Run the command "mkdir build" to create the build directory. 
5. Run the command "cd build" to enter the build directory.
6. Run "cmake .." to create the makefile necessary to run and compile your code.
7. Now, your code is ready to be run. Run "make" in the command line to compile the code. Now, run "./test" to run the tests file that contains our provided tests to ensure the correctness of the algorithm or run "./main" to run the main file.
8. Now that the code has been confirmed to be able to execute and tested to be correct, enter the "main.cpp" file. There, you will see the benchmarking examples that prove how fast the algorithm is. It can also be used as a reference on how to declare a KMPAlgorithm object and use it to obtain all occurances of a pattern in a text.
    - Declare a KMPAlgorithm object.
    - Either use the readFileToString method to read a txt file into a string or declare your own text in a string variable.
    - Declare a string variable for the pattern you want to search for.
    - Call the searchKMP method with the parameters of (yourText, yourPattern) to return a vector of all indices where the pattern is found.
    - Print out all values in the vector to see where any matches were found.
