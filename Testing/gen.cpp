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
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<int> uni(10, 16);
        int test;
        test = uni(rng);
        inputFile << test << "\n";
        while (test--) {
            int n = uni(rng);
            string s;

            uniform_int_distribution<int> uni3(0, 9);
            for (int i = 0; i < n; i++) {
                int num = uni3(rng);
                s += to_string(num);
            }

            // inputFile << n << "\n";
            string ops = "+-*/";
            uniform_int_distribution<int> uni2(0, 3);
            for (int i = 1; i < s.size(); i++) {
                char c = ops[uni2(rng)];
                s.insert(i, 1, c);
                i++;
            }
            inputFile << s << "\n";
        }
        inputFile.close();
    } else {
        cerr << "Unable to open " << inputFileName << " for writing!" << endl;
        exit(1);
    }
}

int main() {
    // Generate 10 input files
    for (int i = 0; i < 10; i++) {
        generateInput(i);
    }

    // Compile sol.cpp
    if (system("g++ sol.cpp -o sol") != 0) {
        cerr << "Compilation of sol.cpp failed!" << endl;
        return 1;
    }

    // Run sol for each input file and generate corresponding output files
    for (int i = 0; i < 10; i++) {
        string inputFileName = "in" + to_string(i) + ".txt";
        string outputFileName = "out" + to_string(i) + ".txt";
        string command = "./sol < " + inputFileName + " > " + outputFileName;
        if (system(command.c_str()) != 0) {
            cerr << "Execution of sol failed for " << inputFileName << "!" << endl;
            return 1;
        }
    }

    cout << "Input processed by sol.cpp, and output written to out0.txt to out9.txt." << endl;
    return 0;
}