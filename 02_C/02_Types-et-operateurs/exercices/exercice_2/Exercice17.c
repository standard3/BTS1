#include <stdio.h>

int main()
{
    int nbrNotes, somme = 0;
    float moyenne;

    printf("Combien de notes voulez-vous saisir ? ");
    scanf("%d", &nbrNotes);
    int notes[nbrNotes];

    for (int i = 0; i < nbrNotes; i++)
    {
        do
        {
            printf("Entrer la note n°%d: ", i+1);
            scanf("%d", &notes[i]);
        } while (notes[i] < 0 || notes[i] > 20);
        somme += notes[i];
    }

    moyenne = somme / nbrNotes;
    printf("La moyenne des notes est %.2f", moyenne);

    return 0;
}