#include <stdio.h>
#include <string.h>

int main()
{
    char ch1[] = "contenu de ch1", ch2[] = "contenu de ch2", ch3[100];

    // Première version avec strcat()
    strcat(ch3, ch1);
    strcat(ch3, " + ");
    strcat(ch3, ch2);

    puts(ch3);

    printf("\n");

    // Deuxième version 

    for (int i = 0; i < strlen(ch1); i++)
    {
        ch3[i] = ch1[i]; 
    }
    
    ch3[strlen(ch1) + 1] = '+';

    for (int i = 0; i < strlen(ch2 - 1); i++)
    {
        ch3[i + strlen(ch1) + 3] = ch2[i];
    }

    puts(ch3);

    return 0;
}