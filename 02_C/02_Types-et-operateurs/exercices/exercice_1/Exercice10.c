#include <stdio.h>

// Ecrire la fonction occurence_max() qui renvoie le nombre d’occurrences de la lettre la plus présente dans un tableau de 10 caractères qui lui est passé en paramètre.
int occurence_max(char ch[10])
{
    int max = 0, cpt;

    for (int i = 0; i < 9; i++)
    {
        cpt = 0;
        for (int j = 0; j < 9; j++)
        {
            if (ch[j] == ch[i])
            {
                cpt++;
            }
        }
        if (cpt > max)
        {
            max = cpt;
        }
    }
    return max;
}

int main()
{
    return 0;
}