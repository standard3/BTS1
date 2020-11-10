#include <stdio.h>
#include <string.h>

int main()
{
    char ch1[] = "contenu de ch1", ch2[] = "contenu de ch2", ch3[100];

    // Première version avec strcat()
    strcat(ch3, ch1);
    strcat(ch3, " + ");
    strcat(ch3, ch2);
    printf("%s", ch3);

    printf("\n");

    // Deuxième version avec strcpy()
    strcpy(ch3, ch1);
    strcpy(ch3, " + ");
    strcpy(ch3, ch2);
    printf("%s", ch3);

    return 0;
}