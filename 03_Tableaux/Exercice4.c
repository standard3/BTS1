#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char chaine[60]; 
    char lettre;
    int compteur;

    printf("Saisissez une chaine : ");
    gets(chaine);

    printf("Quelle lettre souhaitez vous compter ? ");
    scanf("%c", &lettre);

    for (int i = 0; i < strlen(chaine); i++)
    { 
        if (chaine[i] == tolower(lettre) || chaine[i] == toupper(lettre)) 
        { 
            compteur += 1; 
        }
    }

    printf("La lettre %c est presente %d fois dans la chaine", lettre, compteur);

    return 0;
}