#include <stdio.h>

void count(int, int);

int main() 
{
    count(1, 10);
    return 0;
}

void count(int i, int max) 
{
    if (i > max)
    {
        return;
    }
    else
    {
        printf("%d\n", i);
        i++;
        count(i, max);
    }
}