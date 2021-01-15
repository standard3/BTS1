#include <stdio.h>

void isSuite();

int tableau_des_selectionnes[5] = {1, 2, 3, 4, 5};
int tableau_face[5];

int main()
{
    for (int i = 0; i < 5; i++)
        printf("%d, ", tableau_des_selectionnes[i]);

    isSuite();
    printf("\n");

    for (int i = 0; i < 5; i++)
        printf("%d, ", tableau_face[i]);
}

void isSuite()
{
    
    for (int i = 0; i < 5; i++)
        tableau_face[i] = tableau_des_selectionnes[i];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (tableau_face[j] < tableau_face[j + 1])
            {
                int temp = tableau_face[j];
                tableau_face[j] = tableau_face[j + 1];
                tableau_face[j + 1] = temp;
            }
        }
    }
}