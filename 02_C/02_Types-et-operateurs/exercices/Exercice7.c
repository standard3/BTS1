#include <stdio.h>

// Ecrire un algorithme qui demande successivement 5 nombres à l’utilisateur et qui affiche ensuite le plus grand parmi ces nombres.
int main()
{
    int n, max = 0;

    for (int i = 1; i < 5; i++)
    {
        printf("Entrer un nombre : ");
        scanf("%d", n);

        if ((i == 1) || (n > max))
        {
            max = n;
        }
    }
    printf("Le nombre le plus grand est : %d", max);

    return 0;
}