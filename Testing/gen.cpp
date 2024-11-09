#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <cstdlib>

using namespace std;

void generateInput(int index) {
    // Writing to inX.txt
    string inputFileName = "in" + to_string(index) + ".txt";
    ofstream inputFile(inputFileName);
    
    if (inputFile.is_open()) {
        // Setting the maximum number of nodes for the test case
        static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> test(1, 1000);
        std::uniform_int_distribution<int> dist(1, 10000000);
        int testCount = test(rng);
        inputFile << testCount << endl;
        for (int i = 0; i < testCount; ++i) {
            inputFile << dist(rng) << endl;
        }
        inputFile.close();
        cout << "Test case generated in " << inputFileName << endl;
    } else {
        cerr << "Unable to open " << inputFileName << " for writing!" << endl;
        exit(1);
    }
}
int main() {
    // Generate 10 input files
    for (int i = 0; i < 10; i++) {
        generateInput(i+2);
    }

    // Compile sol.cpp
    if (system("g++ sol.cpp -o sol") != 0) {
        cerr << "Compilation of sol.cpp failed!" << endl;
        return 1;
    }

    // Run sol for each input file and generate corresponding output files
    for (int i = 0; i < 10 ; i++) {
        string inputFileName = "in" + to_string(i+2) + ".txt";
        string outputFileName = "out" + to_string(i+2) + ".txt";
        string command = "./sol < " + inputFileName + " > " + outputFileName;
        if (system(command.c_str()) != 0) {
            cerr << "Execution of sol failed for " << inputFileName << "!" << endl;
            return 1;
        }
    }

    cout << "Input processed by sol.cpp, and output written to out0.txt to out9.txt." << endl;
    return 0;
}