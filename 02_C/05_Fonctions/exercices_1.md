# Exercices sur les fonctions

## Exercice 1

Soit le programme suivant :
```c
#include <stdio.h>
int main() {
    int s, a = 1, b = 3 ;
    s = somme(a, b);
    printf("%d + %d = %d\n", a, b, s);
    return 0;
}
```

1. Déclarer et définir la fonction ```somme``` qui effectue la somme des valeurs passées en arguments.

## Exercice 2

Reprendre le code de l'[exercice 3.3 sur les paramètres du main](../04_Pointeurs/exercices_3.md/#Exercice-3) et remplacer les calculs (+, -, x et /) par des fonctions :

1. Créer les prototypes pour les fonctions : somme, soustraction, multiplication et division.
2. Définir les 4 fonctions
3. Faire appel aux 4 fonctions en lieu et place des calculs précédemment codés.

## Exercice 3

Reprendre le code de l'[exercice 3.3 sur les paramètres du main](../04_Pointeurs/exercices_3.md/#Exercice-3) et remplacer les calculs (+, -, x et /) et leur affichage par des fonctions :

1. Créer les prototypes pour les fonctions : somme, soustraction, multiplication et division.
2. Définir les 4 fonctions
3. Faire appel aux 4 fonctions en lieu et place des calculs précédemment codés.

## Exercice 4

Commenter correctement les fonctions de l'exercice 2.

## Exercice 5

1. Ecrire une fonction qui réalise le swap (l'échange des valeurs) de ses deux arguments entiers passés par valeur et qui ne renvoie rien. Ecrire le programme principal appelant cette fonction et afficher à l'écran le contenu des variables :

    + avant l'appel de la fonction
    + au début de la fonction
    + à la fin de la fonction
    + après l'appel de la fonction
    
    Qu'observez-vous ? Pourquoi ?

2. Réécrire le programme en passant les arguments de la fonction d'échange par adresse. Qu'observez-vous ? Pourquoi ?