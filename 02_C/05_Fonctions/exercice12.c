#include <stdio.h>

void call();

int main()
{
    for (int i = 0; i < 100; i++)
        call();

    return 0;
}

void call()
{
    static int count;
    count++;
    printf("%d\n", count);
}