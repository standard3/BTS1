#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addition(int, int);
int soustraction(int, int);
int multiplication(int, int);
float division(float, float);

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
            printf("= %d", addition(a, b));
        }
        else if (strcmp(argv[2], "-") == 0) {
            printf("= %d", soustraction(a, b));
        }
        else if (strcmp(argv[2], "x") == 0) {
            printf("= %d", multiplication(a, b));
        }
        else if (strcmp(argv[2], "/") == 0) {
            // Pas de division par 0 (pas détectée par le compilateur...)
            if (b != 0) {
                printf("= %f", division(a, b));
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

/**
 * Addition de 2 entiers
 * @param a Premier entier
 * @param b Second entier
 * @return le résultat de l'addition des 2 entiers
 * */
int addition(int x, int y) {
    return x + y;
}

/**
 * Soustraction de 2 entiers
 * @param a Premier entier
 * @param b Second entier
 * @return le résultat de la soustraction des 2 entiers
 * */
int soustraction(int x, int y) {
    return x - y;
}

/**
 * Multiplication de 2 entiers
 * @param a Premier entier
 * @param b Second entier
 * @return le résultat de la multiplication des 2 entiers
 * */
int multiplication(int x, int y) {
    return x * y;
}

/**
 * Division de 2 entiers
 * @param a Premier entier
 * @param b Second entier
 * @return le résultat de la division des 2 entiers
 * */
float division(float x, float y) {
    return x / y;
}