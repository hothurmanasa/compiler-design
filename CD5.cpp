#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to eliminate left factoring from the given grammar
void eliminate_left_factoring() {
    printf("Original Grammar:\n");
    printf("A ? aB | aC\n\n");
    
    printf("Transformed Grammar (after eliminating left factoring):\n");
    printf("A  ? aA'\n");
    printf("A' ? B | C\n");
}

int main() {
    eliminate_left_factoring();
    return 0;
}
