# Exercices Algorithmique

## Exercice 1

Quelles seront les valeurs des VARIABLES A et B après exécution de chacune des instructions suivantes ?

```
VARIABLES
    entier : A;
    entier : B;

DEBUT
    A <- 7 ;        // Instruction 1
    B <- A + 4 ;    // Instruction 2
    A <- 5 ;        // Instruction 3
FIN
```

```
1 : 
2 : 
3 : 
```

## Exercice 2

Ecrire un algorithme permettant d’échanger les valeurs de deux VARIABLES A et B de type entier.

> C'est ce qu'on appelle un "swap".

```

```

## Exercice 3

Ecrire un algorithme qui demande un nombre à l’utilisateur et l’informe ensuite SI ce nombre est poSItif ou négatif ou nul.

```
VARIABLES
    entier : nombre;

DEBUT

Ecrire("Veuillez saisir un nombre :");
Lire(nombre)
SI nombre > 0 ALORS :
    Ecrire("Le nombre " nombre " est poSItif.");
SINON 
    SI nombre == 0 :
        Ecrire("Le nombre " nombre " est nul");
    SINON
        SI nombre < 0 :
            Ecrire("Le nombre " nombre " est négatif.");
        FIN SI
    FIN SI
FIN SI
FIN
```

## Exercice 4

Reprendre l'exercice 3 en autorisant la saisie d'un 0 et en affichant que le nombre saiSI est nul dans ce cas.

```

```

## Exercice 5

Ecrire un algorithme qui demande deux nombres à l’utilisateur et l’informe ensuite si, sans le calculer, leur produit est négatif ou positif ou nul.

```
VARIABLES
    entier : a;
    entier : b;

DEBUT

Ecrire("Veuillez choisir un nombre a :");
Lire(a);
Ecrire("Veuillez choisir un nombre b:");
Lire(b);
SI a < 0 ouex b < 0 ALORS :
    Ecrire("Le produit sera négatif");
SINON SI a == 0 ou b == 0 ALORS :
    Ecrire("Le produit sera nul");
SINON
    Ecrire("Le produit sera positif");
FIN SI

FIN

```

## Exercice 6

Ecrire de deux manières différentes un algorithme qui demande à l’utilisateur un nombre compris entre 1 et 10 jusqu’à ce que la réponse convienne.

Solution 1 :

```
VARIABLES
    entier : nombre;
DEBUT

FAIRE
    Ecrire("Veuillez saisir un nombre compris entre 1 et 10 :");
    Lire(nombre);
    SI nombre > 1 et nombre < 10 ALORS :
        Ecrire("Vous avez bien répondu.");
    SINON
        Ecrire("Le chiffre n'est pas compris entre 1 et 10, veuillez réessayer.");
    FIN SI
TANT QUE nombre < 1 et nombre > 10

FIN
```

Solution 2 :

```
Même chose qu'en haut mais remplacer la boucle 'FAIRE TANT QUE' par 'TANT QUE' + déclarer une variable input
```

## Exercice 7

Ecrire un algorithme qui demande à l'utilisateur un nombre, et qui calcule la somme des entiers jusqu’à ce nombre et l'affiche. 

**Exemple** : *Si l’utilisateur saisit 5, le programme doit calculer : 1 + 2 + 3 + 4 + 5 = 15 puis afficher : 15*

```
VARIABLES
    entier : nombre;
    entier : a;
    entier : i;
DEBUT

i <- 0;
a <- 0;
Ecrire("Veuillez saisir un nombre :");
Lire(nombre);
TANT QUE i <= nombre :
    a <- i + a;
    i <- i + 1;
FIN TANT QUE
Ecrire("La somme des entiers de " nombre " est égale à " a ".");

FIN
```

## Exercice 8

Ecrire un algorithme qui demande successivement 5 nombres à l’utilisateur et qui affiche ensuite le plus grand parmi ces nombres.

```
VARIABLES
    tableau[5] de réel : tab;
    entier : i;
    entier : plus_grand_nombre;

DEBUT

i <- 0;
plus_grand_nombre <- 0;
POUR i VARIANT DE 0 A 4 :
    Ecrire("Veuillez rentrer une valeur pour " i + 1 " :");
    Lire(tab[i]);
    SI i == 1 ou tab[i] > plus_grand_nombre :
        plus_grand_nombre <- tab[i];
    FIN SI
    i <- i + 1;
FIN POUR
Ecrire("Le nombre le plus grand est : " plus_grand_nombre);

FIN
```

## Exercice 9

Ecrire un algorithme qui déclare un tableau de 5 notes, dont on fait ensuite saisir les valeurs par l’utilisateur (notes comprises entre 0 et 20), après la saisie, affiche la moyenne des notes.

```
VARIABLES
    tableau[5] de entier : tab;
    entier : i;
    flottant : somme;

DEBUT

i <- 0;
somme <- 0;
POUR i VARIANT DE 0 A 4 :
    Ecrire("Veuillez rentrer la note " i + 1 " (doit être comprise entre 0 et 20):");
    Lire(tab[i]);
    SI tab[i] < 0 ou tab[i] > 20 :
        Ecrire("La note n'est pas comprise entre 0 et 20.");
        tab[i] <- 0  
    FIN SI
    i <- i + 1;
FIN POUR
i <- 0;
POUR i VARIANT DE 0 A 4 :
    somme <- somme + tab[i];
    i <- i + 1;
FIN POUR
Ecrire("La moyenne des notes est de : " somme/5);
FIN
```

## Exercice 10

On vous demande régulièrement de modifier l'algorithme de l'exercice précédent pour changer le nombre de notes à saisir. Le modifier pour que cette modification soit réduite à la modification d'une seule valeur.

```
VARIABLES

DEBUT

FIN
```

## Exercice 11

Ecrire la fonction ```occurence_max()``` qui renvoie le nombre d’occurrences de la lettre la plus présente dans un tableau de 10 caractères qui lui est passé en paramètre.

```
VARIABLES

DEBUT

FIN
```

## Exercice 12

Que fait la fonction ```f``` suivante :

```
FONCTION F (tableau [10] de entier : t) : entier
VARIABLES
    entier i;
    entier m;
    entier m2;
DEBUT
    m <- t[0] ;
    m2 <- t[0];
    POUR i VARIANT DE 0 A 9 FAIRE
        SI (t[i] > m) ALORS
            m2 <- m;
            m <- t[i];
        SINON
            SI (t[i] > m2) ALORS
                m2 <- t[i];
            FIN SI
        FIN SI
    FIN POUR
    RETOUR m2;
FIN
```
