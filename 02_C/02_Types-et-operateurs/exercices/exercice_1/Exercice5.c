#include <stdio.h>

// Ecrire de deux manières différentes un algorithme qui demande à l’utilisateur un nombre compris entre 1 et 10 jusqu’à ce que la réponse convienne.
int solution1(int a)
{
    do
    {
        printf("Entrer un nombre entre 1 et 10 : ");
        scanf("%d", a);
    } while (a < 1 || a > 10);

    return a;
}

int solution2(int a)
{

    while (a < 1 || a > 10)
    {
        printf("Entrer un nombre entre 1 et 10 : ");
        scanf("%d", a);
    }

    return a;
}

int main()
{
    return 0;
}