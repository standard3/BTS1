# Allocation dynamique de mémoire

## Exercice 1

Afin de réaliser la saisie une chaîne de caractère, on désire allouer dynamiquement de la mémoire. La taille de cette chaîne sera de 25 caractères. Ecrire la ligne de code nécessaire à cette allocation :

1. avec la fonction malloc.
2. avec la fonction calloc.
3. avec la fonction realloc.

## Exercice 2

Ecrire un programme permettant de saisir un tableau de réels. Ce programme allouera la mémoire pour ce tableau dynamiquement. Le programme :
+ Demandera de saisir la taille n du tableau.
+ Allouera la mémoire nécessaire avec la fonction adaptée (penser à gérer le cas ou l’allocation s’avère impossible à effectuer).
+ Effectuera la saisie des n éléments du tableau.
+ Affichera le tableau.
+ Libèrera l’espace mémoire alloué.

## Exercice 3

On veut pouvoir saisir un tableau d’entiers. Le nombre d’entiers à saisir n’est pas connu à l’avance donc la taille du tableau grandira à chaque saisie.
+ Après la saisie, le tableau sera affiché avec un pointeur et la mémoire sera libérée.
+ Le programme affichera également la taille mémoire allouée.

## Exercice 4

Ecrire un programme qui permet à l'utilisateur de saisir un nombre indéfini de chaînes de caractères (127 caractères maximum). Les chaînes sont rangées successivement dans un tableau de pointeurs. La fin de la saisie sera signalée par une chaîne vide. Le programme affichera toutes les chaînes saisies avant de libérer la mémoire.