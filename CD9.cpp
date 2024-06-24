#include <stdio.h>

int main() {
    char op = '+';
    char a = 'a';
    char b = 'b';
    char c = 'c';

    // Generate three-address code
    printf("t1 = %c %c %c\n", a, op, b);
    printf("t2 = t1 %c %c\n", op, c);

    return 0;
}
