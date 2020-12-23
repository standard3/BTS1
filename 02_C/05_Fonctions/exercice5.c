#include <stdio.h>

void swap(int *, int *);

int main()
{
    int a, b;
    a = 1;
    b = 2;

    printf("Avant appel : a = %d b = %d\n", a, b);
    swap(&a, &b);
    printf("Apres appel : a = %d b = %d\n", a, b);

    return 0;
}

void swap(int * a, int * b)
{
    int c = *a;
    *a = *b;
    *b = c;
}