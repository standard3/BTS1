#include <stdio.h>
#include <string.h>

int main()
{
    char ch1[100], ch2[100];

    printf("Chaine 1 : ");
    gets(ch1);

    printf("\nChaine 2 :" );
    gets(ch2);

    if (strcmp(ch1, ch2) == 0)
    {
        printf("Les chaines sont identiques.");
    }
    else
    {
        printf("Les chaines ne sont pas identiques.");
    }
    
    return 0;
}