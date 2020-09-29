#include <stdio.h>

// Ecrire un programme en C qui demande un nombre non nul à l’utilisateur et l’informe ensuite si ce nombre est positif ou négatif.
int main()
{
    int nombre;
    printf("Saisissez un nombre \n");
    scanf("%d", &nombre);

    if ( nombre > 0)
    {
        printf("C'est un nombre positif");
    }
    else
    {
        printf("C'est un nombre négatif");
    }

    return 0;
}