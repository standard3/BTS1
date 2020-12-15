#include <stdio.h>

// Déclaration = prototype
int somme(int, int);

int main() {
    int s, a = 1, b = 3 ;
    // Appel
    s = somme(a, b);
    printf("%d + %d = %d\n", a, b, s);
    return 0;
}

// Définition
int somme(int x, int y) {
    return x + y;
}