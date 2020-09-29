#include <stdio.h>

// Ecrire un algorithme qui demande à l'utilisateur un nombre, et qui calcule la somme des entiers jusqu’à ce nombre et l'affiche.
int main()
{
    int max, somme;
    printf("Donner un nombre :");
    scanf("%d", max);

    for (int i = 1; i < max; i++)
    {
        somme += i;
    }

    printf("La somme des entiers jusqu'a %d est %d", max, somme);

    return 0;
}