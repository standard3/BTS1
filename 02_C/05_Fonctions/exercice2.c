#include <stdio.h>
#include <stdlib.h>

int   somme(int, int);
int   soustraction(int, int);
int   multiplication(int, int);
float division(int, int);

int main(int argc, char ** argv)
{
    if (argc != 4)
    {
        printf("Utilisation : calculatrice.exe var op var\nExemple : calculatrice.exe 2 + 3");
    }
    else
    {
        float result = 0;

        int a = atoi(*(argv + 1));
        char sign = **(argv + 2);
        int b = atoi(*(argv + 3));
    
        switch (sign)
        {
        case '+':
            result = somme(a, b);
            break;
        case '-':
            result = soustraction(a, b);
            break;
        case 'x':
            result = multiplication(a, b);
            break;
        case '/':
            if ((a || b) == 0)
            {
                printf("Erreur : impossible de diviser par 0\n");
                break;
            }
            result = division(a, b);
            break;
        default:
            printf("Erreur inconnue\n");
            break;
        }

        printf("%d %c %d = %2f", a, sign, b, result);
    }   
    return 0;
}
/**
 * Somme de deux entiers
 * @param a premier entier
 * @param b deuxième entier
 * @return Résultat de la somme des deux entiers
 */
int somme(int a, int b) { return a + b; }

/**
 * Soustraction de deux entiers
 * @param a premier entier
 * @param b deuxième entier
 * @return Résultat de la soustraction des deux entiers
 */
int soustraction(int a, int b) { return a - b; }

/**
 * Multiplication de deux entiers
 * @param a premier entier
 * @param b deuxième entier
 * @return Résultat de la multiplication des deux entiers
 */
int multiplication(int a, int b) { return a * b; }

/**
 * Division de deux réels
 * @param a premier réel
 * @param b deuxième réel
 * @return Résultat de la division des deux réels
 */
float division(int a, int b) { return (float)a / (float)b; }