# Correction des exercices sur les pointeurs

## Exercice 1

1. *(&a) : a
2. *tab : tab[0]
3. *(tab + 0) : tab[0]
4. (*tab) + 1 : tab[0] + 1
5. &(tab[0]) : tab
6. &(tab[i]) : (tab + i)
7. ++tab[i] : ++(*(tab + i))

## Exercice 2

1. sizeof(char) = 1 octet en C (standard, dépend pas de l’archi)
2. sizeof(int) = 4 octet pour machine 32 bits

## Exercice 3

1. Premier "arrêt"

adresse | identificateur | valeur
--- | --- | ---
0xFF00 | a | 10
0xFF04 | b | 5
0xFF08 | tab[0] | 1
0xFF0C | tab[1] | 2
0xFF10 | tab[2] | 3
0xFF14 | p_int | ?

2. Second "arrêt"

adresse | identificateur | valeur
--- | --- | ---
0xFF00 | a | 10
0xFF04 | b | 5
0xFF08 | tab[0] | 10
0xFF0C | tab[1] | 5
0xFF10 | tab[2] | 3
0xFF14 | p_int | 0xFF10

## Exercice 4

Rappels :

```char c1[] = "Un"``` ou ```char *c1 = "Un"```

c1 est un pointeur de caractère qui pointe sur une chaine de caractères.

```*c1 = 'U'``` et ```*(c1+1) = 'n'```

```char *tab[] = {c1, c2, c3}``` peut s'écrire ```char *tab[] = {"Un", "Deux", "Trois"}```

tab est un tableau de pointeurs de caratères qui pointent sur des chaines de caractères.

1. ```&tab[0]``` est l'adresse de la case 0 du tableau c’est donc la même adresse que ```tab```.
2. ```*tab``` et ```tab[0]``` représentent tous les deux le contenu de la case 0 du tableau donc l’adresse de la chaine ```c1``` : "Un".
```c
printf("%s", *tab); 
// Un
printf("%s", tab[0]); 
// Un
```
3. ```tab[1]``` et ```*(tab + 1)``` représentent tous les deux le contenu de la case 1 du tableau donc l’adresse de la chaine ```c2``` : "Deux".
4. ```**tab``` et ```*tab[0]```, ```tab[0]``` et ```*tab = c1``` donc ```*c1``` est le premier élément du tableau de caractères ```c1``` donc 'U'.
5. ```**(tab + 1)``` et ```*tab[1]```, ```*(tab+1)``` et ```tab[1] = c2```. ```*c2``` est le premier élément du tableau de caractères ```c2``` donc 'D'.
6. ```*(tab[2] + 1)``` et ```tab[2][1]```, ```tab[2] = c3```, ```tab[2] + 1 = c3 + 1``` et  ```*(c3+1) = 'r'```.

## Exercice 5

Etat de la mémoire :

adresse | identificateur | valeur
--- | --- | ---
22ff4e | tab[0] | 'A'
22ff4f | tab[1] | 'B'
22ff48 | ptr | 22ff4e
22ff44 | pt_ptr | 22ff48

Ce qui donne le résultat suivant :

```
tab = 22ff4e
*tab = A
&ptr = 22ff48
ptr = 22ff4e
*ptr = A
&ptr_ptr = 22ff44
ptr_ptr = 22ff48
*ptr_ptr = 22ff4e
**ptr_ptr = A
```

