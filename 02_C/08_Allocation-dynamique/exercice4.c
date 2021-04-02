#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHAR_MAXIMUM 128

int main()
{
    char sizeArray = 0;
    char input[CHAR_MAXIMUM];
    char *storage = (char*) malloc(sizeof(input));

    system("chcp 65001");
    while(1)
    {
        printf("Saisir chaîne de caractères (< 128 caractères, vide pour arrêter) :\n");
        gets(input);
        if (input != "§")
        {
            if (strlen(input) > 127)
            {
                printf("Pas plus de 127 caractères !\n");
                break;
            }

            sizeArray++;
            storage = (char*) realloc(storage, sizeArray * CHAR_MAXIMUM);
            strcpy((storage + (sizeArray - 1)), input);
        }
        else
            break;
    }
    
    printf("storage[%d] : ", sizeArray);
    for (int i = 0; i < sizeArray; i++)
        printf("[%s] ", *(storage + i)); // Afficher tableau + mémoire allouée

    free(storage);


    return 0;
}