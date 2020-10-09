#include <stdio.h>

int main() {
    int n, i, max = 0;

    for (i = 1; i <= 5; i++) {
        printf("Entrez un nombre : ");
        scanf("%d", &n);

        if (i == 1 || n > max) {
            max = n;
        }
    }

    printf("Le nombre le plus grand est : %d", max);

    return 0;
}