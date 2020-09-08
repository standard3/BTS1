# Markdown 

## Présentation

Langage de balisage léger interprété et lisible en brut.

Il n'existe pas de norme mais les bases ont été posées par John GRUBER [ici](https://daringfireball.net/projects/markdown/syntax). 

## Cheatsheet allégée (GitHub)
---

### Titres

```md
# Niveau 1
## Niveau 2
### Niveau 3
```

# Niveau 1
## Niveau 2
### Niveau 3

---
### Mise en forme

```md
Italiques avec des *asterisques* ou des  _underscores_.

Gras avec des **asterisques** ou des __underscores__.

On peut imbriquer les mises en forme en utilisant des **asterisques et _underscores_**.

Barré avec deux tildes. ~~Je suis complètement barré.~~
```

Italiques avec des *asterisques* ou des  _underscores_.

Gras avec des **asterisques** ou des __underscores__.

On peut imbriquer les mises en forme en utilisant des **asterisques et _underscores_**.

Barré avec deux tildes : ~~Je suis complètement barré.~~

---

### Listes

#### Ordonnées

```md
1. Premier item
2. Deuxième item
```

1. Premier item
2. Deuxième item

#### Non-ordonnées

```md
* Il est possible d'utiliser des asterisques
- des signes moins
+ ou des signes plus
```

* Il est possible d'utiliser des asterisques
- des signes moins
+ ou des signes plus

#### Aligner des sous-paragraphes

```md
* Un item de liste

⋅⋅Il est possible d'indenter des sous-paragraphes en passant une ligne et en les alignant sur l'item précédent.
  
⋅⋅Pour passer à la ligne sans changer de paragraphe, faire suivre le⋅⋅
⋅⋅paragraphe de deux espaces

* Un autre item
```

* Un item de liste

  Il est possible d'indenter des sous-paragraphes en passant une ligne et en les alignant sur l'item précédent.
  
  Pour passer à la ligne sans changer de paragraphe, faire suivre le  
  paragraphe de deux espaces

* Un autre item

---

### Liens

#### Liens directs

```md
[Lien vers Google](https://www.google.fr)

[Lien vers Google avec un titre](https://www.google.fr "Accueil de Google France")

[Lien vers un élément du repository](00_vscode.md)

Les URLs seules et les URLs entre <> seront automatiquement transformées en lien : http://www.example.com or <http://www.example.com>.
```

[Lien vers Google](https://www.google.fr)

[Lien vers Google avec un titre](https://www.google.fr "Accueil de Google France")

[Lien vers un élément du repository](00_vscode.md)

Les URLs seules et les URLs entre <> seront automatiquement transformées en lien : http://www.example.com or <http://www.example.com>.

#### Liens via une référence

```md
[Lien via une référence textuelle][texte insensible à la casse]

[Lien via une référence numérique][1]

Ou utiliser la [référence seule].

Les références peuvent être n'importe où dans le document et sont invisibles.

[texte insensible à la casse]: https://www.google.fr
[1]: https://www.google.fr
[référence seule]: https://www.google.fr
```
[Lien via une référence textuelle][texte insensible à la casse]

[Lien via une référence numérique][1]

Ou utiliser la [référence seule].

Les références peuvent être n'importe où dans le document et sont invisibles.

[texte insensible à la casse]: https://www.google.fr
[1]: https://www.google.fr
[référence seule]: https://www.google.fr

---

### Images

#### Lien direct

```md
![alt text](img/markdown-logo.png "Titre de l'image")
```

![alt text](img/markdown-logo.png "Titre de l'image")

#### Lien via une référence

```md
![alt text][logo]

[logo]: img/markdown-logo.png "Titre de l'image"
```
![alt text][logo]

[logo]: img/markdown-logo.png "Titre de l'image"

---

### Code

    Afficher du `code en ligne` en l'entourant avec des `accents graves`.

    Afficher des blocs de codes en les entourant de 3 accents graves.
    ```
    Première ligne de code,
    Deuxième...
    ```

    Indiquer un langage après les accents d'ouverture pour activer la coloration syntaxique 

    ```js
    // Code Javascript
    var s = "JavaScript syntax highlighting";
    alert(s);
    ```

Afficher du `code en ligne` en l'entourant avec des `accents graves`.

Afficher des blocs de codes en les entourant de 3 accents graves.
```
Première ligne de code,
Deuxième...
```

Indiquer un langage après les accents d'ouverture pour activer la coloration syntaxique 

```js
// Code Javascript
var s = "JavaScript syntax highlighting";
alert(s);
```

---

### Tableaux

```md
| En-tête 1     | En-têtes 2      | En-têtes 3 |
| ------------- |:---------------:| ----------:|
| La colonne 3  | est alignée à   | droite     |
| La deuxième   | est centrée     | 12.00€     |
| Sur GitHub    | les lignes sont | zébrées    |

Chaque cellule de la ligne de séparation des en-têtes doit contenir au moins trois tirets.

En utilisant les deux points dans la ligne de séparation, on peut définir l'alignement de la colonne.

Les pipes extérieurs (|) sont optionnels et les espaces pour que le tableaux brut soit "joli" aussi :

Markdown | moins | joli...
--- | :---: | ---:
*mais* | `rendu` | **toujours correct**
1 | 2 | 3
```

| En-tête 1     | En-têtes 2      | En-têtes 3 |
| ------------- |:---------------:| ----------:|
| La colonne 3  | est alignée à   | droite     |
| La deuxième   | est centrée     | 12.00€     |
| Sur GitHub    | les lignes sont | zébrées    |

Chaque cellule de la ligne de séparation des en-têtes doit contenir au moins trois tirets.

En utilisant les deux points dans la ligne de séparation, on peut définir l'alignement de la colonne.

Les pipes extérieurs (|) sont optionnels et les espaces pour que le tableaux brut soit "joli" aussi :

Markdown | moins | joli...
--- | :---: | ---:
*mais* | `rendu` | **toujours correct**
1 | 2 | 3

---

### Citations

```md
> Les citations commencent par un chevron fermant (>) et on peut y **utliser** les *emphases*.
```

> Les citations commencent par un chevron fermant (>) et on peut y **utliser** les *emphases*.

---

### Ligne horizontale

```md
Utiliser 3 ou plus :
+ tirets
---
+ asterisques
***
+ underscores
_____
```

Utiliser 3 ou plus :
+ tirets
---
+ asterisques
***
+ underscores
_____