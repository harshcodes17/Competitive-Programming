#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

// Function to apply an operation
double applyOperation(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

// Function to perform SAMDOB order operations on the expression
double evaluateSAMDOB(std::string expression) {
    std::stack<double> values;
    std::stack<char> ops;

    // Process the expression character by character
    for (size_t i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ')
            continue;

        if (isdigit(expression[i])) {
            double val = 0;

            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                if (expression[i] == '.') {
                    i++;
                    double decimal = 0.1;
                    while (i < expression.length() && isdigit(expression[i])) {
                        val += (expression[i] - '0') * decimal;
                        decimal /= 10;
                        i++;
                    }
                    i--;
                } else {
                    val = (val * 10) + (expression[i] - '0');
                }
                i++;
            }
            i--;

            values.push(val);
        } else if (expression[i] == '(') {
            ops.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double val2 = values.top();
                values.pop();
                
                double val1 = values.top();
                values.pop();
                
                char op = ops.top();
                ops.pop();
                
                values.push(applyOperation(val1, val2, op));
            }
            ops.pop();
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!ops.empty() && (
                (expression[i] == '+' || expression[i] == '-') ||
                (expression[i] == '*' || expression[i] == '/') 
            )) {
                double val2 = values.top();
                values.pop();
                
                double val1 = values.top();
                values.pop();
                
                char op = ops.top();
                ops.pop();
                
                values.push(applyOperation(val1, val2, op));
            }

            ops.push(expression[i]);
        }
    }

    while (!ops.empty()) {
        double val2 = values.top();
        values.pop();
        
        double val1 = values.top();
        values.pop();
        
        char op = ops.top();
        ops.pop();
        
        values.push(applyOperation(val1, val2, op));
    }

    return values.top();
}

int main() {
    std::string expression;
    // std::cout << "Enter the arithmetic expression: ";
    std::getline(std::cin, expression);

    double result = evaluateSAMDOB(expression);
    // std::cout << "The result according to SAMDOB order is: " << result << std::endl;
    std::cout<<result<<std::endl;
    return 0;
}
