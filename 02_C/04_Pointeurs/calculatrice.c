#include <stdio.h>
#include <stdlib.h>

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
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case 'x':
            result = a * b;
            break;
        case '/':
            result = (float)a / (float)b;
            break;    
        default:
            printf("Erreur inconnue\n");
            break;
        }

        printf("%d %c %d = %2f", a, sign, b, result);
    }   

    return 0;
}