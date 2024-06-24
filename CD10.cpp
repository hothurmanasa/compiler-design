#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    int charCount = 0, wordCount = 0, lineCount = 0;
    char ch, lastChar = ' ';

    printf("Enter text (Ctrl+D to end):\n");

    // Read input until EOF (Ctrl+D on Unix/Linux, Ctrl+Z on Windows)
    while (fgets(text, sizeof(text), stdin)) {
        lineCount++;

        for (int i = 0; text[i] != '\0'; i++) {
            ch = text[i];
            if (isalpha(ch) || isdigit(ch)) {
                charCount++;
            }
            if ((isspace(lastChar) || ispunct(lastChar)) && !isspace(ch)) {
                wordCount++;
            }
            lastChar = ch;
        }
    }

    printf("\nTotal characters: %d\n", charCount);
    printf("Total words: %d\n", wordCount);
    printf("Total lines: %d\n", lineCount);

    return 0;
}
