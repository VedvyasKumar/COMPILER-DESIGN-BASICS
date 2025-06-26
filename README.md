# COMPILER-DESIGN-BASICS

The provided C++ program is a simple yet effective implementation of a mini arithmetic expression parser and evaluator. It allows the user to input a mathematical expression using basic arithmetic operations—addition (+), subtraction (-), multiplication (*), and division (/)—and computes the correct result by following proper order of operations and respecting parentheses. This program demonstrates how to write a recursive descent parser, which is a foundational concept in compiler design and programming language interpreters.

Purpose and Functionality
The main goal of the program is to evaluate arithmetic expressions that are entered as strings. For example, if the user inputs 3 + 4 * (2 - 1), the program will calculate and output 7 by correctly applying the precedence rules (i.e., multiplication before addition, and expressions inside parentheses before others). The parsing and evaluation are done in one pass without building an abstract syntax tree, which keeps the code simple and efficient.

Core Components
At the heart of the program is a class called Parser, which contains all the logic necessary to analyze and compute the value of an arithmetic expression. The class has two primary members:

string input: Holds the input expression.

int pos: Tracks the current position within the input string during parsing.

To support the parsing process, the class uses helper functions:

peek(): Returns the current character without consuming it.

get(): Retrieves and consumes the current character, advancing the position.

skipWhitespace(): Skips over any whitespace characters in the input.

These helpers ensure the parser can move through the string cleanly and process meaningful characters without being affected by spacing.

Parsing Strategy
The parser uses a recursive descent strategy to evaluate expressions. This technique breaks down expressions into components (called grammar rules) and processes them in a hierarchical manner. The grammar used in this parser is:

ini
Copy
Edit
expression = term { ('+' | '-') term }
term       = factor { ('*' | '/') factor }
factor     = number | '(' expression ')'
This grammar reflects standard arithmetic operator precedence: parentheses are evaluated first, then multiplication and division, and finally addition and subtraction.

parseFactor() handles numbers or sub-expressions enclosed in parentheses.

parseTerm() evaluates multiplication and division operations.

parseExpression() evaluates addition and subtraction.

Each of these methods returns a double result, and the final result is computed step by step as the parser moves through the input string.

Error Handling
The parser includes basic error detection using C++ exceptions. For example, if the parser encounters an unexpected character (like an operator where a number is expected, or a missing closing parenthesis), it throws a runtime_error. This error is caught in the main() function, where a user-friendly error message is displayed.

For instance:

Input: (3 + 4

Output: Error: Expected ')'

This improves the robustness of the program and makes it more user-friendly.

Example Use
When the program runs, it prompts the user for an arithmetic expression:

mathematica
Copy
Edit
=== Mini Arithmetic Expression Compiler ===
Enter expression (e.g., 3 + 4 * (2 - 1)):
If the user enters 2 + 3 * 4, the parser correctly computes it as 14, not 20, by first performing the multiplication (3 * 4 = 12) and then the addition (2 + 12).

Limitations
Although the program works well for basic expressions, it has a few limitations:

It does not handle negative numbers or unary minus (e.g., -5 + 3 will cause an error).

It does not support exponentiation (^), variables, or functions like sqrt() or sin().

There is no support for advanced error messages with line/character positions.

Conclusion
This C++ program is a compact and clear example of an arithmetic expression evaluator. It effectively introduces key concepts in parsing and compiler design such as grammar rules, operator precedence, and recursive descent parsing. While it has room for further enhancements, it already provides a functional and educational foundation for evaluating mathematical expressions programmatically. It is especially useful for students learning how interpreters and compilers process expressions and how to implement basic parsing techniques in a structured way.






