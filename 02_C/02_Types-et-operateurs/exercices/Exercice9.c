#include <stdio.h>

/*
On vous demande régulièrement de modifier l'algorithme de l'exercice précédent pour changer le nombre de notes à saisir. 
Le modifier pour que cette modification soit réduite à la modification d'une seule valeur.
*/

#define NB_NOTES 5

int main()
{
    int notes[NB_NOTES];
    int somme = 0;
    double moyenne;

    for (int i = 0; i < NB_NOTES - 1; i++)
    {
        do
        {
            printf("Entrez la note n°%d", i+1);
            scanf("%d", notes[i]);
        } while ((notes[i] < 0) || (notes[i] > 20));
        somme += notes[i];
    }

    moyenne /= NB_NOTES;
    printf("La moyenne des notes est %d", moyenne);

    return 0;
}