#include <stdio.h>
#include <conio.h>
#include <limits.h>

// max long : LONG_MAX

int main()
{
    for (long i = 1; i < LONG_MAX; i++)
    {
        if (i)
        {
            printf("*** Appel #%d ***\n", i);
        }
        
        //getch();
    }

    return 0;
}

void call()
{
    
}