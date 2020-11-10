#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char haystack[101], input[101];
    char needle = 'a';
    int i, count = 0;
    
    system("chcp 65001");

    /** On utilise gets() plutôt qu'un scanf 
     *  pour ne pas avoir de problème avec les espaces 
     *  et le scanf("%c") juste après qui prendrait 
     *  le \n à la fin de la saisie
     * */ 
    printf("Saisir une phrase (100 caractères max.) :\n");
    gets(haystack);
    
    do {
        printf("Saisir un caractère minuscule à rechercher :\n");
        gets(input);
        sscanf(input, "%1c", &needle);
    }
    while(needle < 97 || needle > 122);

    /** D'un coup d'oeil sur la table ascii, 
     *  on voit qu'on peut passer d'une minuscule à une majuscule
     *  en reculant de 32 caractères dans la table.
     * */
    for (i = 0; i < strlen(haystack); i++) {
        count += (haystack[i] == needle || haystack[i] == needle - 32);
    }
    
    printf("La phrase contient %d '%c'/'%c'", count, needle, needle - 32);

    return 0;
}