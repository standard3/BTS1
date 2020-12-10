#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    system("chcp 65001");
    char ch[100], c, C, * ptr;
    int i;

    // Saisie
    puts("Chaîne de caractères :");
    gets(ch);
    puts("Caractère à supprimer :");
    scanf("%c", &c);

    // Conversion en minuscule puis majuscule du 
    // caractère à chercher pour les comparaisons
    c = tolower(c);
    C = toupper(c);

    // On ne touche pas à ch pour savoir ou la chaîne commence, 
    // on utilise un autre pointeur
    ptr = ch;
    // Tant qu'on ne rencontre pas le caractère de fin de chaîne
    while (*ptr != '\0') {
        // Si le caractère pointé est le caractère recherché
        if (*ptr == c || *ptr == C) {
            // On écrase le caractère pointé en décalant la fin 
            // de la chaîne d'un caractère vers l'arrière.
            strcpy(ptr, ptr + 1);
        }
        // On fait avancer le pointeur
        ptr++;
    }

    // Affichage du résultat
    puts("Résultat final :");
    puts(ch);

    return 0;
}