#include <stdio.h>

int main()
{
    int a, b;
    printf("Saisissez un nombre : ");
    scanf("%d", &a);
    scanf("%d", &b);

    float resultat = a / b;
    printf("Resultat : %f", resultat);

    return 0;
}