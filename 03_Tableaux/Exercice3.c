#include <stdio.h>
#include <string.h>

int main()
{
    char chaine[50] = "It's gonna be legend... wait for it... dary!";
    int compteur;

    for (int i = 0; i < strlen(chaine); i++)
    { 
        if (chaine[i] == 'a') { compteur += 1; }
    }

    printf("La lettre 'a' est presente %d fois dans la chaine", compteur);

    return 0;
}