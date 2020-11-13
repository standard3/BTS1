#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
*  Ecrire un algorithme puis coder en langage C un programme qui affiche le 
*  nombre de voyelles (non accentuées), de consonnes et des autres caractères 
*  restant (espaces, virgules ...) d'un texte saisi au clavier et 
*  terminé par la touche ENTREE. Le texte comportera au plus 50 caractères.
*/

int main()
{
    char texte[50];
    char consonnes[] = "bcdfghjklmnpqrstvwxz";
    char voyelles[] = "aeiouy";

    short countConsonnes = 0, countVoyelles = 0, countCaracteresSpeciaux = 0;

    printf("Saisir une chaine (50 char max): ");
    gets(texte);

    for (int i = 0; i < strlen(texte); i++)
    {
        // Met tout en minuscule
        texte[i] = tolower(texte[i]);

        // Check consonnes
        if (strchr(consonnes, texte[i]) != NULL)
        {
            countConsonnes += 1;
        }
        // Check voyelles
        else if (strchr(voyelles, texte[i]) != NULL)
        {
            countVoyelles += 1;
        }
        // Check caractères spéciaux
        else
        {
            countCaracteresSpeciaux += 1;
        }
    }

    printf("Voyelles : %d | Consonnes : %d | Caracteres speciaux : %d", countVoyelles, countConsonnes, countCaracteresSpeciaux);

    return 0;
}