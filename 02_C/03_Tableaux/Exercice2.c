#include <stdio.h>
#include <string.h>

int main()
{
    char chaine[20];

    printf("Saisir une chaine : ");
    gets(chaine);

    printf("Le deuxieme caractere est : %c", chaine[1]);

    return 0;
}