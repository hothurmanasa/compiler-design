#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

// Function declarations
double parseExpression(char* expression);
double parseTerm(char* expression);
double parseFactor(char* expression);
double parseNumber(char* expression);

// Helper function to skip whitespace characters
void skipWhitespace(char** expression) {
    while (**expression && isspace(**expression)) {
        (*expression)++;
    }
}

// Function to parse and evaluate an expression
double parseExpression(char* expression) {
    double value = parseTerm(expression);
    skipWhitespace(&expression);

    while (*expression == '+' || *expression == '-') {
        char operator = *expression;
        expression++;
        double nextTerm = parseTerm(expression);
        if (operator == '+') {
            value += nextTerm;
        } else if (operator == '-') {
            value -= nextTerm;
        }
        skipWhitespace(&expression);
    }

    return value;
}

// Function to parse and evaluate a term (handles * and /)
double parseTerm(char* expression) {
    double value = parseFactor(expression);
    skipWhitespace(&expression);

    while (*expression == '*' || *expression == '/') {
        char operator = *expression;
        expression++;
        double nextFactor = parseFactor(expression);
        if (operator == '*') {
            value *= nextFactor;
        } else if (operator == '/') {
            if (nextFactor != 0) {
                value /= nextFactor;
            } else {
                fprintf(stderr, "Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
        }
        skipWhitespace(&expression);
    }

    return value;
}

// Function to parse and evaluate a factor (handles numbers and parentheses)
double parseFactor(char* expression) {
    skipWhitespace(&expression);

    if (*expression == '(') {
        expression++;
        double value = parseExpression(expression);
        skipWhitespace(&expression);
        if (*expression == ')') {
            expression++;
            return value;
        } else {
            fprintf(stderr, "Error: Missing closing parenthesis\n");
            exit(EXIT_FAILURE);
        }
    } else {
        return parseNumber(expression);
    }
}

// Function to parse and evaluate a number
double parseNumber(char* expression) {
    skipWhitespace(&expression);
    
    char* endPtr;
    double value = strtod(expression, &endPtr);
    
    if (expression == endPtr) {
        fprintf(stderr, "Error: Expected a number\n");
        exit(EXIT_FAILURE);
    }

    return value;
}

// Main function for testing
int main() {
    char expression[100];

    printf("Enter a mathematical expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove newline character if present
    expression[strcspn(expression, "\n")] = '\0';

    double result = parseExpression(expression);
    printf("Result: %lf\n", result);

    return 0;
}
