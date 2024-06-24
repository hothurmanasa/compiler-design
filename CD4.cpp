#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to eliminate left recursion from the given grammar
void eliminate_left_recursion() {
    printf("Original Grammar:\n");
    printf("S ? Sa | b\n\n");
    
    printf("Transformed Grammar (after eliminating left recursion):\n");
    printf("S  ? bS'\n");
    printf("S' ? aS' | e\n");
}

int main() {
    eliminate_left_recursion();
    return 0;
}
