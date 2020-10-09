#include <stdio.h>

int main()
{
    int a = 5, b = 2;
    float resultat = 5 / 2;
    int reste = a % b;

    printf("La division de %d par %d est %f et le modulo est %d.", a, b, resultat, reste);
    
    return 0;
}