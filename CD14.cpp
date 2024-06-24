#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Function declarations
int parseExpression(const char **input);
int parseTerm(const char **input);
int parseFactor(const char **input);
int parseNumber(const char **input);

// Helper function to handle syntax errors
void error(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

// Function to parse and evaluate an expression
int parseExpression(const char **input) {
    int value = parseTerm(input);  // Parse the first term

    while (**input == '+' || **input == '-') {
        char op = **input;
        (*input)++;
        int nextTerm = parseTerm(input);  // Parse the next term
        if (op == '+') {
            value += nextTerm;
        } else {  // op == '-'
            value -= nextTerm;
        }
    }

    return value;
}

// Function to parse and evaluate a term
int parseTerm(const char **input) {
    int value = parseFactor(input);  // Parse the first factor

    while (**input == '*' || **input == '/') {
        char op = **input;
        (*input)++;
        int nextFactor = parseFactor(input);  // Parse the next factor
        if (op == '*') {
            value *= nextFactor;
        } else {  // op == '/'
            if (nextFactor == 0) {
                error("Division by zero");
            }
            value /= nextFactor;
        }
    }

    return value;
}

// Function to parse and evaluate a factor
int parseFactor(const char **input) {
    int value;

    if (isdigit(**input)) {
        value = parseNumber(input);  // Parse a number
    } else if (**input == '(') {
        (*input)++;
        value = parseExpression(input);  // Parse an expression inside parentheses
        if (**input != ')') {
            error("Missing closing parenthesis");
        }
        (*input)++;
    } else {
        error("Unexpected character");
    }

    return value;
}

// Function to parse and evaluate a number
int parseNumber(const char **input) {
    int value = 0;

    while (isdigit(**input)) {
        value = value * 10 + (**input - '0');
        (*input)++;
    }

    return value;
}

int main() {
    const char *input = "3 + (4 * 5) - 6 / 2";
    int result = parseExpression(&input);
    printf("Result: %d\n", result);

    return 0;
}
