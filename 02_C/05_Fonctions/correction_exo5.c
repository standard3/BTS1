#include <stdio.h>

void swapByValue(int, int);
void swapByAddress(int *, int *);

int main () {
    int x = 42, y = 2725;
    printf("x: %d, y: %d\n", x, y);
    //swapByValue(x, y);
    swapByAddress(&x, &y);
    printf("x: %d, y: %d\n", x, y);
    return 0;
}

void swapByValue(int a, int b) {
    printf("a: %d, b: %d\n", a, b);
    int temp = a;
    a = b;
    b = temp;
    printf("a: %d, b: %d\n", a, b);
}
void swapByAddress(int * a, int * b) {
    printf("a: %d, b: %d\n", *a, *b);
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("a: %d, b: %d\n", *a, *b);
}