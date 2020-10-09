#include <stdio.h>

// Reprendre l'exercice 3 en autorisant la saisie d'un 0 et en affichant que le nombre saisi est nul dans ce cas.
int main()
{
    int nombre;
    printf("Saisissez un nombre \n");
    scanf("%d", &nombre);

    if ( nombre >= 0)
    {
        if ( nombre == 0)
        {
            printf("C'est un nombre nul");
        }
        else
        {
            printf("C'est un nombre positif");
        }
    }
    else
    {
        printf("C'est un nomre négatif");
    }

    return 0;
}