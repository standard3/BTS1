#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int input;
    int sizeArray = 0;
    int *array = (int*) malloc(sizeArray * sizeof(int)); // On créer un tableau de 1

    system("chcp 65001");
    while(1)
    {
        printf("Saisir entier (-1 pour arrêter): ");
        scanf("%d", &input);
        if (input != -1)
        {
            sizeArray++;
            array = (int*) realloc(array, sizeArray * sizeof(int));
            *(array + (sizeArray - 1)) = input;
        }
        else
            break;
    }

    printf("Tableau[%d] : ", sizeArray);
    for (int i = 0; i < sizeArray; i++)
        printf("[%d] ", *(array + i)); // Afficher tableau + mémoire allouée

    printf("\nTotal d'octets alloués : %d", sizeArray * sizeof(int));
    
    free(array);

    return 0;
}