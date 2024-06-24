#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for the strings
#define MAX_LENGTH 100

// Function to check if a string matches the pattern "b(a)*"
int matches(const char* input) {
    if (input[0] != 'b') {
        return 0;
    }
    for (int i = 1; input[i] != '\0'; ++i) {
        if (input[i] != 'a') {
            return 0;
        }
    }
    return 1;
}

// Function to convert a string based on the non-left-recursive grammar
void convert(const char* input) {
    if (!matches(input)) {
        printf("The input string does not match the grammar S ? Sa | b\n");
        return;
    }

    // Print the initial state
    printf("S ? bS'\n");
    printf("S' ? ");
    
    // Print 'a' for each 'a' in the input string after the initial 'b'
    for (int i = 1; input[i] != '\0'; ++i) {
        printf("aS' | ");
    }
    
    // Print the final state
    printf("e\n");
}

int main() {
    char input[MAX_LENGTH];

    // Get the input string
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove the newline character if present
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    // Convert the input string based on the non-left-recursive grammar
    convert(input);

    return 0;
}
