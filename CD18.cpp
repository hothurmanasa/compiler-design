#include <stdio.h>

// Function to generate machine code
void generateMachineCode(const char *irStatement) {
    printf("Machine Code Generation:\n");

    // Example: Directly print the IR statement as machine code
    printf("MOV R1, %s\n", irStatement);
    printf("ADD R2, R1\n");
    printf("STORE R2, Result\n");
}

int main() {
    const char *irStatement = "t1 = 3 + (4 * 5)";
    generateMachineCode(irStatement);

    return 0;
}
