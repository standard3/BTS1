# Exercices sur les pointeurs - PC

## Exercice 1

Ecrire, de deux façons différentes, un programme qui lit 10 nombres entiers dans un tableau avant d'en rechercher le plus grand et le plus petit :
+ en utilisant le formalisme tableau
+ en utilisant le formalisme pointeur

## Exercice 2

Ecrire un programme qui permet de saisir 10 entiers dans un tableau, puis ensuite qui le sépare en deux autres tableaux :
+ un tableau des éléments pairs
+ un tableau des éléments impairs

## Exercice 3

Soit le tableau :

```c
char * tab[] = {"AB1C", "D23", "E4F56", "7G", "HI8", "JKL90MN"};
```

A l'aide de pointeurs, extraire les chiffres de chaque chaine pour les convertir en entier, les ranger dans un tableau d'entier et finalement afficher les éléments du tableau.

L'affichage attendu est :

```
1, 23, 456, 7, 8, 90
```

## Exercice 4

Ecrire un programme qui lit un caractère ```c``` et une chaîne de caractères ```ch``` au clavier. Ensuite toutes les occurrences (majuscule et minuscule) de ```c``` dans ```ch``` seront éliminées. Utiliser les pointeurs et la fonction ```strcpy```.

## Exercice 5

Ecrire un programme qui lit une chaîne de caractères ```ch``` au clavier et qui compte les occurrences des lettres de l'alphabet en ne distinguant pas les majuscules et les minuscules. Utiliser des pointeurs. Ces occurrences seront mémorisées dans un tableau