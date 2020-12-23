#include <stdio.h>

#define SIZE 20

void swap(int *, int *);
void swapArrayMinMax(int[]);

int main()
{
    int tab[SIZE] = {10, 2, 3, 4, 5, 6, 7, 8, 9, 1, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    swapArrayMinMax(tab);
    return 0;
}

void swap(int * a, int * b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void swapArrayMinMax(int array[])
{
    int indexMin, indexMax;

    // Plus petite valeur
    int min = array[0];
    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] < min)
            indexMin = i;
    }

    // Plus grande valeur
    int max;
    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] > max)
            indexMax = i;
    }

    swap(&array[indexMin], &array[indexMax]);
}