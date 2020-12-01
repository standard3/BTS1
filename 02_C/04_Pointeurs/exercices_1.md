# Exercices sur les pointeurs - Papier

## Exercice 1

Soit :
```c
int a;
char tab[10];
```

Ecrire les expressions autrement (formalisme pointeur ou tableau) :

```c
1. *(&a)
2. *tab
3. *(tab + 0)
4. (*tab) + 1
5. &(tab[0])
6. &(tab[i])
7. ++tab[i]
```

## Exercice 2

Soit :
```c
char tab[10];
char *p;
p = tab + 1;
```

1. Quelle sera la différence en octets entre les deux adresses tab et p ?
2. Même question si tab et p sont déclarés pointeurs sur des entiers (int) ?

## Exercice 3

Représenter en mémoire les données déclarées dans le programme suivant, ainsi que leurs différentes valeurs, aux moments indiqués en commentaires dans l’exécution. Pour cela, représenter l’occupation des données en mémoire dans un tableau à 3 colonnes comme montré ci-dessous :

Adresse | Valeur | Identificateur
--- | --- | ---
0xFF09 | 3.14 | toto

Pour déterminer les adresses, on prendra les hypothèses suivantes :
+ les données sont réservées en mémoire dans l’ordre de leur déclaration
+ la première adresse démarre à 0xFF00  
+ l’architecture est 32 bits

Le programme :

```c
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int a = 10;
    int b = 5;
    int tab[3] = {1,2,3};
    int *p_int;
    // <-- Représenter l'occupation mémoire
    tab[0] = a;
    *(tab + 1) = b;
    p_int = tab + 2;
    // <-- Représenter l'occupation mémoire
    return 0;
}
```

## Exercice 4

Dans un programme, on trouve les déclarations suivantes :

```c
char c1[] = "Un" ;
char c2[] = "Deux" ;
char c3[] = "Trois" ;
char *tab[] = {c1, c2, c3} ;
```

Que désignent les expressions suivantes :
1. ```&tab[0]```
2. ```*tab```
3. ```tab[0]```
4. ```tab[1]```
5. ```*(tab + 1)```
6. ```**tab```
7. ```*tab[0]```
8. ```**(tab + 1)```
9. ```*tab[1]```
10. ```*(tab[2] + 1)```
11. ```tab[2][1]```

## Exercice 5

Qu’affiche le programme suivant. Expliquer.
```c
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char tab[2] = {'A','B'};
    char *ptr = tab;
    char **ptr_ptr = &ptr;

    printf("\n tab = %x", (int)tab);
    printf("\n *tab = %c", *tab);
    printf("\n &ptr = %x", (int)&ptr);
    printf("\n ptr = %x", (int)ptr);
    printf("\n *ptr = %c", *ptr);
    printf("\n &ptr_ptr = %x", (int)&ptr_ptr);
    printf("\n ptr_ptr = %x", (int)ptr_ptr);
    printf("\n *ptr_ptr = %x", (int)*ptr_ptr);
    printf("\n **ptr_ptr = %c", **ptr_ptr);
    return 0;
}
```
On suppose que :
+ ```tab``` a pour adresse ```22ff4e```
+ ```ptr``` a pour adresse ```22ff48```
+ ```ptr_ptr``` a pour adresse ```22ff44```