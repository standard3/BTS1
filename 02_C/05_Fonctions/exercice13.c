#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <limits.h> // LONG_MAX

void call();

int main()
{
    for (long i = 0; i < LONG_MAX; i++)
        call();

    return 0;
}

void call()
{
    static long count;
    static int a;
    count++;

    if (!a)
        a++;

    if (count == a)
    {
        printf("*** Appel #%d ***\n", count);
        a = pow(10, a);
    }
}