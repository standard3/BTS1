#include <stdio.h>

/* 
Ecrire un algorithme qui déclare un tableau de 5 notes, dont on fait ensuite saisir les valeurs
par l’utilisateur (notes comprises entre 0 et 20), après la saisie, affiche la moyenne des notes. 
*/
int main()
{
    int notes[5], somme = 0;
    double moyenne;

    for (int i = 0; i < 4; i++)
    {
        do
        {
            printf("Entrer la note n°%d", i+1);
            scanf("%d", notes[i]);
        } while (notes[i] < 0 || notes[i] > 20);
        somme += notes[i];
    }

    moyenne /= 5;
    printf("La moyenne des notes est %d", moyenne);

    return 0;
}