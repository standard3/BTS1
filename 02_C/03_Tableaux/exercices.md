# Tableaux

## Exercice 1

1. Ecrire un programme qui permet de saisir 3 entiers et de les stocker dans un tableau.

```
Saisir un entier : 2
Saisir un entier : 6
Saisir un entier : 3
```

2. Afficher les 3 entiers avec un seul printf.

```
Les entiers sont 2, 6, 3
```

## Exercice 2

Ecrire un programme qui affiche le deuxième caractère d'une chaîne saisie au clavier.

## Exercice 3

Ecrire un programme qui affiche le nombre de fois où le caractère 'a' est présent dans la chaîne "It's gonna be legend... wait for it... dary!".

## Exercice 4

Reprendre l'exercice 4 :
1. En rendant le caractère et la chaîne saisissable par l'utilisateur.
2. En recherchant minuscule et majuscule du caractère saisi pour les 26 lettres non accentuées.

## Exercice 5

1. Initialiser un tableau avec le nombre de jours de chaque mois.
2. En se servant de ce tableau, écrire un programme qui affiche le numéro du jour dans l'année d'une date saisie (format JJ/MM) sans tenir compte des années bissextiles :)

```
Saisir une date : 07/09
C'est le 250ème jour de l'année !
```

> Avez-vous pensé à l'affichage du premier jour de l'année ?

## Exercice 6

Reprendre le code de l'exercice 5, permettre la saisie de date au format JJ/MM/AAAA et gérer le cas des années bissextiles !

```
Saisir une date : 07/09/2020
C'est le 251ème jour de l'année !
```

## Exercice 7

Créer un programme qui crée deux tableaux de tailles différentes (utiliser des constantes), puis les remplit chacun avec des chiffres, enfin les fusionne dans un seul nouveau tableau.

```
Premier tableau [4] : 1, 2, 3, 4
Deuxième tableau [3] : 5, 6, 7
Tableau fusionné [7] : 1, 2, 3, 4, 5, 6, 7
```

# Chaînes de caractères

## Exercice 8

En utilisant les fonctions sur les chaines écrire un programme qui demande la saisie de deux chaines de caractères et qui indique si les deux chaines sont identiques.

## Exercice 9

Soit les chaînes :

```
char ch1[] = "contenu de ch1", ch2[] = "contenu de ch2", ch3[100];
```

En utilisant les fonctions sur les chaînes, faire en sorte de 2 façons différentes que la chaîne ch3 contienne "contenu de ch1 + contenu de ch2".

## Exercice 10

Ecrire un algorithme puis coder en langage C un programme qui affiche le nombre de voyelles (non accentuées), de consonnes et des autres caractères restant (espaces, virgules ...) d'un texte saisi au clavier et terminé par la touche ENTREE. Le texte comportera au plus 50 caractères.

> On pourra utiliser la fonction Minuscule() en algorithmique et tolower() de la bibliothèque ctype.h en C qui permet de convertir un caractère (si possible) en minuscule.

