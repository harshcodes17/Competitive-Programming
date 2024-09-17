#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>

using namespace std;

int main() {
    // Writing to input.txt
    ofstream inputFile("input.txt");
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

            inputFile << n << "\n";
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
        cerr << "Unable to open input.txt for writing!" << endl;
        return 1;
    }

    cout << "Input written to input.txt." << endl;
    return 0;
}