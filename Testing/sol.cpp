#include <bits/stdc++.h>
using namespace std;

// Function to find precedence of operators.
int precedence(char op) {
    if (op == '-' || op == '+') return 2;
    if (op == '*' || op == '/') return 1;
    return 0;
}

// Function to perform arithmetic operations.
int applyOp(int a, int b, char op, bool &valid) {
    if (op == '/' && b == 0) {
        valid = false;
        return -1;
    }
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int evaluate(string tokens, bool &valid) {
    int i;
    stack<int> values;
    stack<char> ops;
    for (i = 0; i < tokens.length(); i++) {
        if (tokens[i] == ' ')
            continue;
        else if (isdigit(tokens[i])) {
            int val = 0;
            while (i < tokens.length() && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op, valid));
                if (!valid) {
                    cout << "Infinity\n";
                    return -1;
                }
            }
            ops.push(tokens[i]);
        }
    }
    while (!ops.empty()) {
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(val1, val2, op, valid));
    }
    return values.top();
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the number of test cases
    while (t--) {
        string s;
        getline(cin, s); // Read the entire line including spaces
        bool valid = true;
        int ans = evaluate(s, valid);
        if (valid) {
            cout << ans << endl;
        }
    }
    return 0;
}