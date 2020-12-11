#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char ** argv) {
    /*
    Etat de la mémoire au démarrage du programme si on l'appelle de cette façon :
    > a.exe 42 + 31

    argc : 4 
         ┌─────────┬──────┬─────┬──────┐
    argv │ "a.exe" │ "42" │ "+" │ "31" │
         └─────────┴──────┴─────┴──────┘
              0        1     2      3
    */

    int a, b;
    char * operateur;

    a = atoi(*(argv + 1));
    b = atoi(*(argv + 3));
    operateur = *(argv + 2);

    // Vérification du bon nombre d'arguments (nom du programme + 3 = 4)
    if (argc == 4) {
        
        // Pas de switch possible car les chaînes de caractères ne sont pas des types simples
        if (strcmp(argv[2], "+") == 0) {
            printf("= %d", a + b);
        }
        else if (strcmp(argv[2], "-") == 0) {
            printf("= %d", a - b);
        }
        else if (strcmp(argv[2], "x") == 0) {
            printf("= %d", a * b);
        }
        else if (strcmp(argv[2], "/") == 0) {
            // Pas de division par 0 (pas détectée par le compilateur...)
            if (atof(argv[3]) != 0.0) {
                printf("= %f", (float) a / (float) b);
            }
            else {
                printf("Division par 0...");
            }
        }
    }
    else {
        puts("Pas assez d'arguments...");
    }

    return 0;
}