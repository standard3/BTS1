#include <stdio.h>

int main() {
    int n;

    printf("Entrer un nombre (différent de 0) : ");
    scanf("%d", &n);

    if (n > 0) { 
        printf("C'est un nombre positif");
    }
    else {
        printf("C'est un nombre négatif");
    }
    
    return 0;
}