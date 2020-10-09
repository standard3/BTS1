#include <stdio.h>


int main()
{
    char a;
    int b;

    printf("Saisissez une lettre et un chiffre (collés) :");
    scanf("%c%3d", &a, &b);

    printf("a = %c, b = %d \n", a, b); // Vérifier la bonne affectation
    printf("Vous avez saisi %c%d", a, b);

    return 0;
}