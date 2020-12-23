#include <stdio.h>

#define SIZE 20

void smallerValue(int[]);

int main()
{
    int tab[SIZE] = {10, 2, 3, 4, 5, 6, 7, 8, 9, 1, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    smallerValue(tab);

    return 0;
}

void smallerValue(int array[])
{
    int index, min = array[0];
    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
            index = i;
        }
    }
    printf("Element le plus petit : %d\nEmplacement : %d\n", min, index);
}