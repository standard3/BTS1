#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addition(int, int);
void soustraction(int, int);
void multiplication(int, int);
void division(float, float);

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
            addition(a, b);
        }
        else if (strcmp(argv[2], "-") == 0) {
            soustraction(a, b);
        }
        else if (strcmp(argv[2], "x") == 0) {
            multiplication(a, b);
        }
        else if (strcmp(argv[2], "/") == 0) {
            // Pas de division par 0 (pas détectée par le compilateur...)
            if (b != 0) {
                division((float) a, (float) b);
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

void addition(int x, int y) {
    printf("= %d", x + y);
}

void soustraction(int x, int y) {
    printf("= %d", x - y);
}

void multiplication(int x, int y) {
    printf("= %d", x * y);
}

void division(float x, float y) {
    printf("= %f", x / y);
}