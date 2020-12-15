#include <stdio.h>
#include <stdlib.h>

void sum(int, int);
void soustraction(int, int);
void multiplication(int, int);
void division(int, int);

int main(int argc, char ** argv)
{
    if (argc != 4)
    {
        printf("Utilisation : calculatrice.exe var op var\nExemple : calculatrice.exe 2 + 3");
    }
    else
    {
        int a = atoi(*(argv + 1));
        char sign = **(argv + 2);
        int b = atoi(*(argv + 3));
    
        switch (sign)
        {
        case '+':
            sum(a, b);
            break;
        case '-':
            soustraction(a, b);
            break;
        case 'x':
            multiplication(a, b);
            break;
        case '/':
            if ((a || b) == 0)
            {
                printf("Erreur : impossible de diviser par 0\n");
                break;
            }
            division(a, b);
            break;    
        default:
            printf("Erreur inconnue\n");
            break;
        }
    }   
    return 0;
}

void sum(int a, int b)            { printf("%d + %d = %2f", a, b, a + b); }
void soustraction(int a, int b)   { printf("%d - %d = %2f", a, b, a - b); }
void multiplication(int a, int b) { printf("%d * %d = %2f", a, b, a * b); }
void division(int a, int b)       { printf("%d / %d = %2f", a, b, a / b); }