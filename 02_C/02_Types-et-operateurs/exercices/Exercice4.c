#include <stdio.h>

// Ecrire un algorithme qui demande deux nombres à l’utilisateur et l’informe ensuite si, sans le calculer, leur produit est négatif ou positif ou nul.
int main()
{
    int a, b;
    printf("Entrer deux nombres :");
    scanf("%d", &a);
    scanf("%d", &b);

    if (a == 0 || b == 0)
    {
        printf("Le produit de %d et %d est nul", a, b);
    }
    else
    {
        if ( (a < 0 && b > 0) || (a > 0 && b < 0))
        {
            printf("Le produit de %d et %d est negatif", a, b);
        }
        else
        {
            printf("Le produit de %d et %d est positif", a, b);
        }
        
    }

    return 0;
}