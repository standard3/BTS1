# Les structures

## Différence entre tableau et structure

Un tableau permet de regrouper des éléments du même type, codés sur le même nombre de bits et de la même façon. Les structures permettent de remédier à cette lacune des tableaux, en regroupant des objets (variables) au sein d'une entité repérée par un suel nom de variable. Les objets contenus dans la structure sont appelés champs de la structure.

## Déclaration d'une structure

Lors de la déclaration de la structure, on indique les champs de la structure, càd le type et le nom des variables qui la composent :

```c
struct Nom_Structure
{
type_champ1 Nom_Champ1;
type_champ2 Nom_Champ2;
type_champ3 Nom_Champ3;
type_champ4 Nom_Champ4;
type_champ5 Nom_Champ5;
...
};
```

* Le nom des champs répond aux critères des noms de variable
* Deux champs ne peuvent avoir le même nom
* Les données peuvent être de n'importe quel type hormis de la structure dans laquelle elle se trouvent

Exemple de structure correcte :

```c
struct MaStructure 
{
         int Age;
         char Sexe;
         char Nom[12];
         float MoyenneScolaire;
         struct AutreStructure StructBis; /* en considérant que la structure AutreStructure est définie */ 
}; 
```

La déclaration d'une structure fonctionne sur le même principe que les variables (auto, static, ...).

### Exemple de déclaration de la structure "point"

```
struct point
{
       int x;
       int y;
};
```

Sa variable structurée : `struct point Laval, Bonchamp, ...;`

Exemple de création :

````C
struct point p;
p.x = 3;
p.y = 7;
````

Exemple de manipulation de la structure point (déplace le point de la question 10 de 3 sur abscisses et -2 sur ordonnées :

````C
p.x += 3;
p.y -= 2;
````

### Structure "student" qui répond à nos besoins

```
struct student
{
      char nom[31];
      char prenom[31];
      int age;
      int classe;  
};
```

## Définition d'une variable structurée

La définition d'une variable structurée est une opération qui consiste à créer une variable ayant comme type celui d'une structure que l'on a précédemment déclarée, càd la nommer et lui réserver un emplacement en mémoire.

Cela se définit comme suit : `struct nom_structure nom_var_structure;`

## Accéder à un élément contenu dans une structure

Chaque variable de type structure possède des champs repérés avec des noms uniques. Ceux-ci n'ont de contexte qu'au sein de la variable structurée.

Pour accéder au champs d'une structure, on utilise l'opérateur de champ (**.**) : `Pierre.Age = 18` ou `Pierre.Sexe = 'M'`




https://www.geeksforgeeks.org/difference-between-structure-and-array-in-c/

https://www.lct.jussieu.fr/pagesperso/jpp/structures.pdf
