#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int sizeArray;

    puts("Saisir taille du tableau : ");
    scanf("%d", &sizeArray);

    float *array = (float*) malloc(sizeArray * sizeof(float)); 

    if (array != NULL)
    {
        printf("\nSaisir les %d valeurs du tableau :", sizeArray);

        for (int i = 0; i < sizeArray; i++)
        {
        printf("\n[%d] : ", i + 1);
        scanf("%f", (array + i));
        }

        for (int i = 0; i < sizeArray; i++)
            printf("[%.3f] ", *(array + i));

        free(array);
    }
    else
        printf("Impossible de créer le tableau, veuillez réessayer.\n");
    
    return 0;
}