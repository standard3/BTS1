#include <stdio.h>

int main() {
    char a;
    int b;
    printf("> ");
    scanf("%c%d", &a, &b);
    printf("a = '%c', b = %d", a, b);
    return 0;
}