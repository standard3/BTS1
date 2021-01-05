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
+ Le calcul se fera dans une fonction sommeCarres qui retourne le résultat.
+ Le format à l'affichage de la valeur calculée sera : Taille minimale = 5 caractères, Précision = 2.

## Exercice 7

Ecrire une fonction qui demande de saisir un entier et informe le programme principal si l'entier est supérieur à 100.
Le programme principal affiche l'entier en indiquant son rang (<=100 ou >100).

## Exercice 7 3/4

Corriger le programme suivant pour qu'il affiche à l'écran : 12.

Vous ne pouvez ajouter que les caractères suivants : * & ( )

```c
#include "stdio.h"

void fonction1(int);
void fonction2(int);
void fonction3(int);
void fonction4(int);
void fonction5(int);

int main() {
    int a = 4;
    fonction1(&a);
    printf("%d", a);
}

void fonction1(int b) {
    b++;
    fonction3(b);
}
void fonction2(int c) {
    c += 44;
    fonction5(c);
}
void fonction3(int d) {
    d = d * 2;
    fonction4(d);
}
void fonction4(int e) {
    e = e * 10;
    fonction2(e);
}
void fonction5(int f) {
    f = f / 12;
}
```

# Passage de tableaux

## Exercice 8

Ecrire une fonction qui va permettre de trouver la valeur minimum d'un tableau d'entiers (à initialiser dans le programme) ainsi que son indice.

## Exercice 9

Ecrire une fonction qui va permuter les valeurs minimum et maximum d'un tableau d'entiers (à initialiser dans le programme). Cette fonction fera appel à une autre fonction pour la permutation (swap).

# Chaîner les fonctions

## Exercice 10

Dans un programme, écrire en un minimum de lignes chacun des éléments suivants :
1) une fonction somme(a, b) qui renvoie la somme des deux entiers a et b
2) une fonction carre(a) qui renvoie qui renvoie le carre de l'entier a
3) une fonction racineCarree(a) qui renvoie la racine carrée de l'entier a
5) la fonction principale, qui affiche à l'écran la longueur de l'hypothénuse d'un triangle rectangle dont les longueurs des deux autres côtés sont passés en paramètre du programme.

Exemple de résultats attendus :
```
> hypothenuse.exe 1 1
1.414214
> hypothenuse.exe 1 2
2.236068
```

## Exercice 11

Ecrire le programme de l'exercice 10 en **une seule ligne** (contenu du main() :smiley:), en utilisant les fonctions de la bibliothèque math.h.

> La documentation est disponible sur internet.

## Exercice 12

Écrire une fonction qui se contente de comptabiliser le nombre de fois où elle a été appelée en affichant un message de temps en temps, à savoir :

+ au premier appel :    *** Appel #1 ***
+ au dixième appel :    *** Appel #10 ***
+ au centième appel :   *** Appel #100 ***
+ et ainsi de suite pour le millième, le dix millième appel...

On supposera que le nombre maximal d'appel ne peut dépasser la capacité d'un long (cf. limits.h). Pas de variable globale. La fonction ne retourne rien et ne possède pas de paramètre.
