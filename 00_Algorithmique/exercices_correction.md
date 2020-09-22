# Exercices Algorithmique

## Exercice 1

Quelles seront les valeurs des variables A et B après exécution de chacune des instructions suivantes ?

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
1 : A = 7, B = ?
2 : A = 7, B = 11
3 : A = 5, B = 11
```

## Exercice 2

Ecrire un algorithme permettant d’échanger les valeurs de deux variables A et B de type entier.

> C'est ce qu'on appelle un "swap".

```
VARIABLES
    entier : A;
    entier : B;
    entier : C;
début
    C <- A;
    A <- B;
    B <- C;
fin
```

## Exercice 3

Ecrire un algorithme qui demande un nombre différent de 0 à l’utilisateur et l’informe ensuite si ce nombre est positif ou négatif.

```
VARIABLES
    entier : n;

DEBUT
    ECRIRE("Entrer un nombre (différent de 0) : ");
    LIRE(n);
    SI (n > 0) ALORS
        ECRIRE("C'est un nombre positif");
    SINON
        ECRIRE("C'est un nombre négatif");
    FIN SI
FIN
```

## Exercice 4

Reprendre l'exercice 3 en autorisant la saisie d'un 0 et en affichant que le nombre saisi est nul dans ce cas.

```
VARIABLES
    entier : n;
    
DEBUT
    ECRIRE("Entrer un nombre : ");
    LIRE(n);
    SI (n >= 0) ALORS
        SI (n == 0) ALORS
            ECRIRE("C'est un nombre nul");
        SINON
            ECRIRE("C'est un nombre positif");
        FIN SI
    SINON
        ECRIRE("C'est un nombre négatif");
    FIN SI
FIN
```

### Exercice 5

Ecrire un algorithme qui demande deux nombres à l’utilisateur et l’informe ensuite si, sans le calculer, leur produit est négatif ou positif ou nul.

```
VARIABLES
    entier : a;
    entier : b;
    
DEBUT
    ECRIRE("Entrer deux nombres : ");
    LIRE(a);
    LIRE(b);
    SI (a == 0 ou b == 0) ALORS
        ECRIRE("Le produit de " a " et " b " est nul");
    SINON
        SI ((a < 0 et b > 0) ou (a > 0 et b < 0)) ALORS
            ECRIRE("Le produit de " a " et " b " est négatif");
        SINON
            ECRIRE("Le produit de " a " et " b " est positif");
        FIN SI
    FIN SI
FIN
```

## Exercice 6

Ecrire de deux manières différentes un algorithme qui demande à l’utilisateur un nombre compris entre 1 et 10 jusqu’à ce que la réponse convienne.

Solution 1 :

```
VARIABLES
    entier : a;
    
DEBUT
    FAIRE 
        ECRIRE("Entrer un nombre entre 1 et 10 : ");
        LIRE(a);
    TANT QUE (a < 1 ou a > 10)
FIN
```

Solution 2 :

```
VARIABLES
    entier : a;
    
DEBUT
    a <- 0
    TANT QUE (a < 1 ou a > 10)
        ECRIRE("Entrer un nombre entre 1 et 10 : ");
        LIRE(a);
    FIN TANT QUE
FIN
```

## Exercice 7

Ecrire un algorithme qui demande à l'utilisateur un nombre, et qui calcule la somme des entiers jusqu’à ce nombre et l'affiche. 

**Exemple** : *si l’utilisateur saisit 5, le programme doit calculer : 1 + 2 + 3 + 4 + 5 = 15 puis afficher : 15*

```
VARIABLES
    entier : max;
    entier : i;
    entier : somme;
    
DEBUT
    ECRIRE("Donner un nombre : ");
    LIRE(max);
    somme <- 0;
    POUR i VARIANT DE 1 A max FAIRE
        somme <- somme + i;
    FIN POUR
    ECRIRE("La somme des entiers jusqu'à " max " est " somme);
FIN
```

## Exercice 8

Ecrire un algorithme qui demande successivement 5 nombres à l’utilisateur et qui affiche ensuite le plus grand parmi ces nombres.

```
VARIABLES
    entier : n;
    entier : i;
    entier : max;
DEBUT
    max <- 0;
    POUR i VARIANT DE 1 A 5 FAIRE
        ECRIRE("Entrez un nombre : ");
        LIRE(n);
        SI (i == 1) ou (n > max) ALORS
            max <- n;
        FIN SI
    FIN POUR
    ECRIRE("Le nombre le plus grand est : " max );
FIN
```

## Exercice 9

Ecrire un algorithme qui déclare un tableau de 5 notes, dont on fait ensuite saisir les valeurs par l’utilisateur (notes comprises entre 0 et 20), après la saisie, affiche la moyenne des notes.

```
VARIABLES
    tableau [5] de entier : notes;
    entier : i,
    entier : somme;
    reel : moyenne;

DEBUT
    somme <- 0;
    
    POUR i VARIANT DE 0 à 4 FAIRE
        FAIRE
            ECRIRE("Entrez la note n°" i + 1);
            LIRE(notes[i]);
        TANT QUE (notes[i] < 0 ou notes[i] > 20)
        somme<- somme + notes[i];
    FIN POUR
    
    moyenne <- somme / 5;
    ECRIRE("La moyenne des notes est " moyenne);
FIN
```

## Exercice 10

On vous demande régulièrement de modifier l'algorithme de l'exercice précédent pour changer le nombre de notes à saisir. Le modifier pour que cette modification soit réduite à la modification d'une seule valeur.

```
VARIABLES
    constante  NB_NOTES : 5;
    tableau [NB_NOTES] de entier : notes;
    entier : i,
    entier : somme;
    reel : moyenne;

DEBUT
    somme <- 0;
    
    POUR i VARIANT DE 0 à NB_NOTES - 1 FAIRE
        FAIRE
            ECRIRE("Entrez la note n°" i + 1);
            LIRE(notes[i]);
        TANT QUE (notes[i] < 0 ou notes[i] > 20)
        somme<- somme + notes[i];
    FIN POUR
    
    moyenne <- somme / NB_NOTES;
    ECRIRE("La moyenne des notes est " moyenne);
FIN
```

## Exercice 11

Ecrire la fonction ```occurence_max()``` qui renvoie le nombre d’occurrences de la lettre la plus présente dans un tableau de 10 caractères qui lui est passé en paramètre.

```
FONCTION occurence_max (tableau [10] de caractère : ch) : entier
VARIABLES
    entier : i;
    entier : j;
    entier : max;
    entier : cpt;

DEBUT
    max <- 0;
    POUR i VARIANT DE 0 A 9 FAIRE
        cpt <- 0;
        POUR j VARIANT DE 0 A 9 FAIRE
            SI (ch[j] == ch[i]) ALORS
                cpt <- cpt + 1;
            FIN SI
        FIN POUR
        SI (cpt > max) ALORS
            max <- cpt;
        FIN SI
    FIN POUR
    
    retour max;
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

Elle retourne le deuxième plus grand nombre du tableau d'entiers fourni en paramètre.
