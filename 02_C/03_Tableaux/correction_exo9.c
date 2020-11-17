#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    system("chcp 65001");

    const char ch1[] = "contenu de ch1", ch2[] = "contenu de ch2";
    char ch3[100] = "";
    
    // Méthode 1 - strcat
    strcat(ch3, ch1);
    strcat(ch3, " + ");
    strcat(ch3, ch2);

    puts(ch3);

    // Réinitialisation
    ch3[0] = '\0';
    puts(ch3);

    // Méthode 2
    sprintf(ch3, "%s %s %s", ch1, "+", ch2);
    puts(ch3);

    return 0;
}