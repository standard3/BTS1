#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    system("chcp 65001");
    char ch[100], * ptr;
    // Le tableau de l'alphabet est initialisé avec des 0
    // Chaque cellule correspond à une lettre
    int i, alphabet[26] = {0};

    // Saisie de la chaîne
    puts("Chaîne de caractères :");
    gets(ch);
    
    // Utilisation d'un pointeur pour progresser dans la chaîne
    ptr = ch;
    // Tant qu'on ne rencontre pas le caractère de fin de chaîne
    while (*ptr != '\0') {
        // Comme les caractères sont stockés comme des entiers,
        // on utilise la valeur décimale du caractère converti 
        // en minuscule moins la valeur du caractère 'a', ce qui 
        // donne un entier entre 0 et 25 pour les lettres.
        i = tolower(*ptr) - 'a';
        if (i >= 0 && i <= 26) {
            // On incrémente la cellule correspondante
            *(alphabet + i) += 1;
        }
        // On avance le pointeur au caractère suivant
        ptr++;
    }

    // Affichage du résultat
    puts("Occurences de chaque lettre :");
    for (i = 0; i < 26; i++) {
        // On fait l'opération inverse de la ligne 25
        // pour afficher les lettres
        printf("%c : %2d\n", 'a' + i, *(alphabet + i));
    }

    return 0;
}