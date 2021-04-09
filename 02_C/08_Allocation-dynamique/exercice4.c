#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHAR_MAXIMUM 128

int main()
{
    char sizeArray = 0;
    char input[CHAR_MAXIMUM];
    char **array = NULL;

    //system("chcp 65001");
    while(1)
    {
        printf("Saisir chaîne de caractères (< 128 caractères, vide pour arrêter) :\n");
        fgets(input, CHAR_MAXIMUM, stdin);
        if (strcmp(input, "\n") != 0)
        {
            if (strlen(input) > 127)
            {
                printf("Pas plus de 127 caractères !\n");
                break;
            }

            sizeArray++;
            array = realloc(array, sizeArray * sizeof(char*));
            array[sizeArray - 1] = (char*) malloc((strlen(input) + 1) * sizeof(char));
            strncpy(array[sizeArray - 1], input, strlen(input) - 1);
            array[sizeArray - 1][strlen(input)] = '\0';
        }
        else
            break;
    }
    
    printf("array[%d] : ", sizeArray);
    for (int i = 0; i < sizeArray; i++)
        printf("[%s] ", *(array + i)); // Afficher tableau + mémoire allouée

    for (int i = 0; i < sizeArray; i++)
        free(array[i]);
    free(array);

    return 0;
}