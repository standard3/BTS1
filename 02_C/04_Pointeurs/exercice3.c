#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 6

/*
* A l'aide de pointeurs, extraire les chiffres de chaque chaine pour
* les convertir en entier, les ranger dans un tableau d'entier et 
* finalement afficher les éléments du tableau.
*
* Affichage attendu :
*   1, 23, 456, 7, 8, 90
*/

int main()
{
    char * tab[SIZE] = {"AB1C", "D23", "E4F56", "7G", "HI8", "JKL90MN"};
    char c;
    int entier[20];
    int count = 0;
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < strlen(*(tab + i)); j++)
        {
            c = *(*(tab + i) + j);
            
            if (c >= '0' && c <= '9')
            {
                count++;
                entier[count] = c - 48;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d%s", *(entier + i), i == count - 1 ? "" : ", ");
    }

    return 0;
}