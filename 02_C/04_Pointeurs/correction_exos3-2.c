#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(int argc, char ** argv) {
    /*
    Etat de la mémoire au démarrage du programme si on l'appelle de cette façon :
    > a.exe 12 42 91 3 85

    argc : 1 + n valeurs, ici, 6 
         ┌─────────┬──────┬──────┬──────┬─────┬──────┐
    argv │ "a.exe" │ "12" │ "42" │ "91" │ "3" │ "85" │
         └─────────┴──────┴──────┴──────┴─────┴──────┘
             0         1      2      3     4      5

    On ne peux pas initialiser la taille d'un tableau avec une variable.
    Comme nos tableaux odd et even ont une taille fixe, il faut s'assurer
    qu'on ne dépasse pas cette taille.
    */

    int values[SIZE], odd[SIZE], nbOdd = 0, even[SIZE], nbEven = 0, i, size;

    // On s'assure qu'il y a bien des valeurs à récupérer
    if (argc > 1) {

        // Assurons-nous de ne pas dépasser la taille du tableau ni de copier trop de données
        // Si argc - 1 (sans le nom du programme) est plus grand que SIZE on garde SIZE, 
        // sinon on prend argc - 1
        size = argc - 1 >= SIZE ? SIZE : argc - 1;

        // Le premier élément de argv est le nom du programme
        for (i = 1; i <= size; i++) {
            // argv est un tableau de chaînes de caractères, on doit les convertir en int
            values[i - 1] = atoi(argv[i]);
        }

        for (i = 0; i < size; i++) {
            if (*(values + i) % 2 == 0) {
                *(even + nbEven++) = *(values + i);
            }
            else {
                *(odd + nbOdd++) = *(values + i);
            }
        }

        printf("Pairs : ");
        for (i = 0; i < nbEven; i++) {
            printf("%d%s", *(even + i), i == nbEven - 1 ? "" : ", ");
        }
        printf("\nImpairs : ");
        for (i = 0; i < nbOdd; i++) {
            printf("%d%s", *(odd + i), i == nbOdd - 1 ? "" : ", ");
        }
    }
    else {
        puts("Pas de donnees en entree...");
    }
        
    return 0;
}