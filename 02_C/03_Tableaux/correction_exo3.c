#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char haystack[] = "It's gonna be legend... wait for it... dary!";
    char needle = 'i';
    int i, count = 0;
    
    system("chcp 65001");

    // strlen() de la librairie string.h renvoie la longueur d'une chaîne de caractères.
    for (i = 0; i < strlen(haystack); i++) {
        // La condition haystack[i] == needle renvoie 1 si elle est vrai, 0 sinon.
        count += haystack[i] == needle;
    }
    
    printf("La phrase contient %d '%c'", count, needle);

    return 0;
}