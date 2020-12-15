#include <stdio.h>
#include <stdlib.h>

int   somme(int a, int b)          { return a + b; }
int   soustraction(int a, int b)   { return a - b; }
int   multiplication(int a, int b) { return a * b; }
float division(int a, int b)       { return a / b; }

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