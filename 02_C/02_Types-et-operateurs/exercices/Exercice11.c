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
    return 0;
}