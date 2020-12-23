#include <stdio.h>

#define  TRUE 1
#define FALSE 0

int isSuperiorTo100(int);

int main()
{
    int nbr = 20;

    if (isSuperiorTo100)
        printf("%d > 100", nbr);
    else
        printf("%d <= 100", nbr);
    
    return 0;
}

int isSuperiorTo100(int number)
{
    if (number > 100)
        return FALSE;
    else
        return TRUE;
}