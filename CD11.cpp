#include <stdio.h>

int main() {
    // Intermediate representation (IR)
    int a = 10;
    int b = 20;
    int c = a + b;

    // Generate machine code
    printf("MOV R1, %d\n", a);  // Load 'a' into register R1
    printf("ADD R1, %d\n", b);  // Add 'b' to R1
    printf("MOV %d, R1\n", c);  // Store result in 'c'

    return 0;
}
