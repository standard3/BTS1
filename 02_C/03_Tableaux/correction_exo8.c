#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    system("chcp 65001");

    char ch1[100], ch2[100];
    
    // Saisie
    puts("Saisir la chaîne 1 : ");
    gets(ch1);
    puts("Saisir la chaîne 2 : ");
    gets(ch2);

    // Résultat
    if (strcmp(ch1, ch2) == 0) {
        puts("Les deux chaînes sont identiques.");
    }
    else {
        puts("Les deux chaînes sont différentes.");
    }

    return 0;
}