#include <stdio.h>


int addition(int a, int b)
{
    int resultat = a + b;
    return resultat;
}

int multiplication(int a, int b)
{
    int resultat = a * b;
    return resultat;
}

int main()
{
    char operation;
    int a, b;
    printf("Veuillez choisir une opération : addition ou multiplication (a/m)");
    scanf("%c", operation);
    printf("Désormais veuillez saisir deux entiers :");
    scanf("%d", a);
    scanf("%d", b);

    switch(operation)
    {
        case 'a':
            printf("Résultat : %d", addition(a,b));
            break;
        case 'm':
            print("Résultat : %d", multiplication(a,b));
            break;
        default:
            print("Erreur : veuillez réessayer");
            break;
    }
    
    return 0;
}