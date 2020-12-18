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

# Commentaires

## Exercice 4

Commenter correctement les fonctions de l'exercice 2.

# Passage des arguments

## Exercice 5

1. Ecrire une fonction qui réalise le swap (l'échange des valeurs) de ses deux arguments entiers passés par valeur et qui ne renvoie rien. Ecrire le programme principal appelant cette fonction et afficher à l'écran le contenu des variables :

    + avant l'appel de la fonction
    + au début de la fonction
    + à la fin de la fonction
    + après l'appel de la fonction
    
    Qu'observez-vous ? Pourquoi ?

2. Réécrire le programme en passant les arguments de la fonction d'échange par adresse. Qu'observez-vous ? Pourquoi ?

## Exercice 6

Ecrire un programme permettant l'affichage de la somme des carrés de deux nombres a et b de type float rentrés au clavier.
+ Le calcul se fera dans une fonction sommeCarre qui retourne le résultat.
+ Le format à l'affichage de la valeur calculée sera : Taille minimale = 5 caractères, Précision = 2.

## Exercice 7

Ecrire une fonction qui demande de saisir un entier et informe le programme principal si l'entier est supérieur à 100.
Le programme principal affiche l'entier en indiquant son rang (<=100 ou >100).

# Passage de tableaux

## Exercice 8

Ecrire une fonction qui va permettre de trouver la valeur minimum d'un tableau d'entiers (à initialiser dans le programme) ainsi que son indice.

## Exercice 9

Ecrire une fonction qui va permuter les valeurs minimum et maximum d'un tableau d'entiers (à initialiser dans le programme). Cette fonction fera appel à une autre fonction pour la permutation (swap).