#include <stdio.h>

int somme(int, int);

int main() {
    int s, a = 1, b = 3 ;
    s = somme(a, b);
    printf("%d + %d = %d\n", a, b, s);
    return 0;
}

int somme(int a, int b) { return a + b; }