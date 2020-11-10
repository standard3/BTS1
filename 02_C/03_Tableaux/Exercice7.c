#include <stdio.h>
#include <string.h>

#define A 4
#define B 3
#define C 7

int main()
{
    int a[A], b[B], c[C];

    for (int i = 0; i < A; i++)
        a[i] = i;

    for (int i = 0; i < B; i++)
        b[i] = A + i;

    // Affichage premier tableau
    printf("Premier tableau [%d] : ", A); 
    for (int i = 0; i < A; i++)
    {
        printf("%d%s ", a[i], i < A - 1 ? ", " : "");
    }
    
    printf("\n");

    // Affichage deuxième tableau
    printf("Deuxième tableau [%d] : ", B);
    for (int i = 0; i < B; i++)
    {
        printf("%d%s ", b[i], i < B - 1 ? ", " : "");
    }

    // Fusion
    for (int i = 0; i < A; i++)
        c[i] = a[i];

    for (int i = 0; i < B; i++)
        c[i + A] = b[i];

    printf("\n");

    // Affichage dernier tableau
    printf("Tableau fusion [%d] : ", C);
    for (int i = 0; i < C; i++)
    {
        printf("%d%s ", c[i], i < C - 1 ? ", " : "");
    }
    
    return 0;
}