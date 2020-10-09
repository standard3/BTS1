#include <stdio.h>

int main()
{
    int n = 123;

    // Premiere version
    printf("%d   \n", n);
    printf("%6d  \n", n);
    printf("%06d \n", n);
    printf("%-3d \n", n);

    // Deuxième version
    printf("%d\n %6d\n %06d\n %-3d\n", n, n, n, n);

    return 0;
}