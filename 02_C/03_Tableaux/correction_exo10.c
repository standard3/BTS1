#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    system("chcp 65001");

    /* Algorithme
    VARIABLES
        tableau de caractère [50] : input;
        tableau de caractère [6] : vowels;
        tableau de entier [3] : counts;
        entier : i, j;
        caractère : current;
        booleen : isVowel;
    DEBUT
        vowels <- ['e', 'a', 'i', 'o', 'u', 'y'];
        counts <- [0, 0, 0];
        Ecrire("Saisir un texte (50 caractères max.):");
        Lire(input);
        POUR i VARIANT DE 0 A 49 FAIRE
            current = Minuscule(current);
            isVowel <- FAUX;
            POUR j VARIANT DE 0 A 5 FAIRE
                SI current == vowels[j] ALORS
                    isVowel <- VRAI;
                FIN SI
            FIN POUR
            SI isVowel == VRAI ALORS
                counts[0] = counts[0] + 1;
            SINON SI current >= 'a' ET current <= 'z' ALORS
                counts[1] = counts[1] + 1;
            SINON
                counts[2] = counts[2] + 1;
            FIN SI
        FIN POUR
        Ecrire("Il y a "  " voyelles, %d consonnes et %d autres caractères.");
    FIN
    */

    int i, counts[3] = {0, 0, 0};
    char input[51], current;
    const char vowels[] = "eaiouy"; 
    // La fréquence d'apparition des vowels limitera les recherches
    // https://fr.wikipedia.org/wiki/Fr%C3%A9quence_d%27apparition_des_lettres_en_fran%C3%A7ais

    // Saisie
    puts("Saisir un texte (50 caractères max.):");
    gets(input);

    // Parcours caractère par caractère
    for (i = 0; i < strlen(input); i++) {
        current = tolower(input[i]);
        // Est-ce une voyelle ?
        if (strchr(vowels, current) != NULL) {
            counts[0]++;
        }
        // Est-ce une lettre autre ?
        else if (current >= 'a' && current <= 'z') {
            counts[1]++;
        }
        // Sinon c'est un autre caractère !
        else {
            counts[2]++;
        }
    }

    printf("Il y a %d voyelles, %d consonnes et %d autres caractères.", counts[0], counts[1], counts[2]);

    return 0;
}