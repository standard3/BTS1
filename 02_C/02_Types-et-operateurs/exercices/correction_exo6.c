#include <stdio.h>

int main() {
    int max, i, somme = 0;

    printf("Donnez un nombre : ");
    scanf("%d", &max);

    for (i = 1; i <= max; i++) {
        somme += i;
    }

    printf("La somme des entiers jusqu'à %d est %d", max, somme);
    
    return 0;
}