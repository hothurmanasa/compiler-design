#include <stdio.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

void lexicalAnalyzer(const char *input) {
    int charCount = 0, wordCount = 0, lineCount = 0;
    char ch, lastChar = ' ';

    while (*input) {
        ch = *input++;
        charCount++;

        if (ch == '\n') {
            lineCount++;
        }

        if ((isspace(lastChar) || ispunct(lastChar)) && !isspace(ch)) {
            wordCount++;
        }

        lastChar = ch;
    }

    // Count the last word if the input does not end with a space
    if (!isspace(lastChar) && lastChar != '\n') {
        wordCount++;
    }

    printf("Total characters: %d\n", charCount);
    printf("Total words: %d\n", wordCount);
    printf("Total lines: %d\n", lineCount);
}

int main() {
    const char *input = "Hello, world!\nThis is a sample text input.";
    lexicalAnalyzer(input);

    return 0;
}
