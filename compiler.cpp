#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Parser {
private:
    string input;
    int pos;

    char peek() {
        return (pos < input.size()) ? input[pos] : '\0';
    }

    char get() {
        return input[pos++];
    }

    void skipWhitespace() {
        while (isspace(peek())) get();
    }

    // factor = number | '(' expression ')'
    double parseFactor() {
        skipWhitespace();
        if (peek() == '(') {
            get(); // consume '('
            double result = parseExpression();
            if (get() != ')') throw runtime_error("Expected ')'");
            return result;
        }

        string number;
        while (isdigit(peek()) || peek() == '.') {
            number += get();
        }

        if (number.empty()) throw runtime_error("Expected number");
        return stod(number);
    }

    // term = factor { ('*' | '/') factor }
    double parseTerm() {
        double result = parseFactor();
        while (true) {
            skipWhitespace();
            char op = peek();
            if (op == '*' || op == '/') {
                get(); // consume operator
                double right = parseFactor();
                if (op == '*') result *= right;
                else if (op == '/') result /= right;
            } else {
                break;
            }
        }
        return result;
    }

    // expression = term { ('+' | '-') term }
    double parseExpression() {
        double result = parseTerm();
        while (true) {
            skipWhitespace();
            char op = peek();
            if (op == '+' || op == '-') {
                get(); // consume operator
                double right = parseTerm();
                if (op == '+') result += right;
                else if (op == '-') result -= right;
            } else {
                break;
            }
        }
        return result;
    }

public:
    double evaluate(const string& expr) {
        input = expr;
        pos = 0;
        return parseExpression();
    }
};

int main() {
    Parser parser;
    string expression;

    cout << "=== Mini Arithmetic Expression Compiler ===\n";
    cout << "Enter expression (e.g., 3 + 4 * (2 - 1)): ";
    getline(cin, expression);

    try {
        double result = parser.evaluate(expression);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
