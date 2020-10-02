#include <stdio.h>

// La fonction f retourne le deuxième plus grand nombre du tableau d'entiers fourni en paramètre.
int f(int t[10])
{
    int m = t[0], m2 = t[0];

    for (int i = 0; i < 9; i++)
    {
        if (t[i] > m)
        {
            m2 = m;
            m = t[i];
        }
        else if (t[i] > m2)
        {
            m2 = t[i];            
        }
    }
    return m2;
}

int main()
{
    int tableau[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("%d", f(tableau[10])); // Affiche la deuxième plus grande valeur du tableau tableau[]

    return 0;
}