# Types, opérateurs et I/O

## Exercice 8

En utilisant le formatage du printf, écrire un programme qui affiche l’entier ```n = 123``` de ces façons suivantes :

```
123
__123
000123
123__
```

> _ représente un espace

On fera une version avec quatre printf et une version avec un seul printf.

## Exercice 9

En utilisant le formatage du printf, écrire un programme qui affiche l’entier ```n = 17``` en décimal, en hexadécimal, en octal.

## Exercice 10

En utilisant le formatage du printf, écrire un programme qui affiche l’adresse de l’entier ```n=17``` en hexadécimal.

## Exercice 11

En utilisant le formatage du printf, écrire un programme qui affiche le réel ```n = 31.41592``` de ces façons suivantes :

```
31.415920
31.416
___31.4159
31.41592085
___31.415920
31.415920___
```

> _ représente un espace

## Exercice 12

Ecrire un programme qui quand on saisie 12345 affecte 12 à une variable a et 345 à une variable b. Utiliser un seul scanf.

## Exercice 13

Ecrire un programme qui quand on saisie Q123 affecte Q à une variable a et 123 à une variable b. Utiliser un seul scanf.

## Exercice 14

Ecrire un programme qui demande à l’utilisateur de choisir une opération parmi l’addition ou la multiplication, puis de fournir deux nombres entiers ; il affiche alors le résultat correspondant.

## Exercice 15

Ecrire un programme qui déclare la variable constante ```PI = 3.14``` et la variable ```r``` contenant la valeur 20. Déclarer trois variables ```d```, ```p``` et ```s``` et affecter respectivement à ces variables les valeurs du diamètre, du périmètre et de la surface d'un cercle dont le rayon est ```r```. On affichera à l'écran le contenu de ces différentes variables selon le format suivant :
```
Un cercle de rayon 20cm
pour diamètre 40cm,
pour circonférence 125.60cm,
pour surface 1256.00 cm².
```

## Exercice 16

Ecrire un programme qui demande à l’utilisateur saisir deux nombres et qui affiche la division de ces deux nombres.

## Exercice 17 

Ecrire un programme qui demande à l’utilisateur de saisir des notes et qui affiche la moyenne des notes saisies. Le nombre de notes sera saisi par l'utilisateur.

## Exercice 18

Ecrire un programme qui affiche le modulo et la division de deux nombres de valeurs 5 et 2. Le programme affiche :
```
La division de 5 par 2 est 2.500000 et le modulo est 1.
```

## Exercice 19

Pour chaque instruction, évaluer la valeur de chaque variable :

```c
int main ()
{
    int a = 20, b = 5, c = -10, d = 2, e = 12, x;
    x = (4 * e) + 3 * ((2 * b) + 7);	// a =    b =    c =    d =    e =    x =    
    x = a == (b = 5);                   // a =    b =    c =    d =    e =    x =    
    a += (e + 5);                       // a =    b =    c =    d =    e =    x =    
    x = a != (c *= (-d));               // a =    b =    c =    d =    e =    x =    
    return 0;
}
```

## Exercice 20

En utilisant seulement les opérateurs ++ et/ou -- sur a et/ou sur b, modifier le programme suivant pour avoir les
résultats en commentaires :

```c
int main ()
{
    int a = 5, b = 5, somme;
    somme = a + b;  
    // a= 5   b= 5   somme= 10
    somme = a + b;  
    // a= 6   b= 5   somme= 10
    somme = a + b;  
    // a= 7   b= 5   somme= 12
    somme = a + b;  
    // a= 6   b= 5   somme= 11
    somme = a + b;  
    // a= 5   b= 4   somme= 11
    return 0;
}
```

## Exercice 21

Écrire plus simplement l’instruction suivante et vérifier :

```c
int main ()
{
    int a, b, z;
    z = (a > b ? a : b) + (a <= b ? a : b);
    z = ...
    return 0;
}
```

## Exercice 22

En utilisant l'opérateur conditionnel, compléter le programme suivant qui prend la valeur :
+ -1 si n est négatif,
+ 0 si n est nul,
+ 1 si n est positif.

```c
int main ()
{
    int n, x;
    x = ...
    return 0;
}
```