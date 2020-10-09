#include <stdio.h>

int main()
{
    int a, b;

    printf("Saisissez quelque chose : ");
    scanf("%2d%3d", &a, &b);

    printf("a = %d, b = %d \n", a, b); // Vérifier la bonne affectation
    printf("Vous avez saisi %d%d", a, b);

    return 0;
}