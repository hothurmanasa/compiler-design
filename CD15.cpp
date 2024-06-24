#include <stdio.h>

// Function to generate three-address code
void generateThreeAddressCode(const char *expression) {
    printf("Intermediate Code Generation:\n");

    int tempCount = 1; // Counter for temporary variables
    char tempVar[5];   // Buffer for temporary variable names

    // Read and parse the expression
    char op;
    int a, b, result;

    while (*expression) {
        if (*expression == '+' || *expression == '-' || *expression == '*' || *expression == '/') {
            op = *expression;
            expression++;
            if (*expression == ' ') {
                expression++;
            }
        } else {
            a = *expression - '0';
            expression++;
            while (isdigit(*expression)) {
                a = a * 10 + (*expression - '0');
                expression++;
            }
            sprintf(tempVar, "t%d", tempCount);
            tempCount++;
            printf("%s = %d\n", tempVar, a);
            result = a;
            continue;
        }
        b = *expression - '0';
        expression++;
        while (isdigit(*expression)) {
            b = b * 10 + (*expression - '0');
            expression++;
        }
        if (op == '+') {
            result = a + b;
        } else if (op == '-') {
            result = a - b;
        } else if (op == '*') {
            result = a * b;
        } else if (op == '/') {
            result = a / b;
        }
        sprintf(tempVar, "t%d", tempCount);
        tempCount++;
        printf("%s = %d %c %d\n", tempVar, a, op, b);
        printf("Result = %s\n", tempVar);
    }
}

int main() {
    const char *input = "3 + (4 * 5) - 6 / 2";
    generateThreeAddressCode(input);

    return 0;
}
