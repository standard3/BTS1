#include <stdio.h>

int main() {
    int a, b;

    printf("Entrer deux nombres :\n");
    scanf("%d", &a);
    scanf("%d", &b);

    if (a == 0 || b == 0) {
        printf("Le produit de %d et %d est nul", a, b);
    }
    else if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
        printf("Le produit de %d et %d est négatif", a, b);
    }
    else {
        printf("Le produit de %d et %d est positif", a, b);
    }

    return 0;
}