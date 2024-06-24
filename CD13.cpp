#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Function declarations
int expr(const char **input);
int term(const char **input);
int factor(const char **input);
int number(const char **input);
int digit(const char **input);

// Helper function to handle syntax errors
void error(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

// Function to parse and evaluate an expression
int expr(const char **input) {
    int value = term(input);  // Parse the first term

    while (**input == '+' || **input == '-') {
        char op = **input;
        (*input)++;
        int nextTerm = term(input);  // Parse the next term
        if (op == '+') {
            value += nextTerm;
        } else {  // op == '-'
            value -= nextTerm;
        }
    }

    return value;
}

// Function to parse and evaluate a term
int term(const char **input) {
    int value = factor(input);  // Parse the first factor

    while (**input == '*' || **input == '/') {
        char op = **input;
        (*input)++;
        int nextFactor = factor(input);  // Parse the next factor
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
int factor(const char **input) {
    int value;

    if (isdigit(**input)) {
        value = number(input);  // Parse a number
    } else if (**input == '(') {
        (*input)++;
        value = expr(input);  // Parse an expression inside parentheses
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
int number(const char **input) {
    int value = 0;

    while (isdigit(**input)) {
        value = value * 10 + (**input - '0');
        (*input)++;
    }

    return value;
}

// Function to parse and evaluate a single digit
int digit(const char **input) {
    if (isdigit(**input)) {
        int value = **input - '0';
        (*input)++;
        return value;
    } else {
        error("Expected digit");
    }
}

int main() {
    const char *input = "3 + (4 * 5) - 6 / 2";
    int result = expr(&input);
    printf("Result: %d\n", result);

    return 0;
}
