#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int c = a + b;
    int d = a * b;
    int e = c - d; // Redundant computation

    printf("Result: %d\n", e);

    return 0;
}
