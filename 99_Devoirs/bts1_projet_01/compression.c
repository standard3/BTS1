#include <stdio.h>
#include <string.h>

#define MAX_KEY   20
#define MAX_VALUE 25

typedef struct Identifier
{
    char key[MAX_KEY];
    char value[MAX_VALUE];
} Identifier;

/* Algorithme
*   
*   Lire et stocker arguments d'appel (struct arguments[])
*   Lire et stocker le dictionnaire (struct dictionnary[])
*   Si mot pas dans dictionnary, append avec (key = dernièreLigne + 1; value = mot) 
*   Sinon trouver équivalence dans dictionnary et remplacer arguments[i].key et arguments[i].value
*   Afficher arguments[] dans sortie standard
*/

/* Règles
*   
*   Implémenter les valeurs numériques ou chaînes de caractères statiques (Surface...)
*   Implémenter système pour mettre en minuscule (pas d'accent)
*   Implémenter système pour détecter si un chiffre (oui = pas de compression, pas d'entrée dans grammar.csv, sinon ignorer)
*   Implémenter système pour prendre en compte les éléments numériques ET chaînes de caractères (ex: )
*/

// prepareData.exe "Cle 1" "Valeur 1" "Cle 2" "Valeur 2" ...
int main(int argc, char ** argv)
{
    if (!((argc - 1) % 2 == 0)) // Si impair
    {
        printf("Error : key without value (%d arguments)\n", argc);
        return -1;
    } 
    
    FILE * grammar = fopen("E:\\Projects\\bts1\\BTS1\\99_Devoirs\\bts1_projet_01\\gramar.csv", "rw");
    int grammarLinesCount;
    char ch;

    if (grammar != NULL)
    {
        while ((ch = fgetc(grammar)) != EOF)
            if (ch == '\n')
                grammarLinesCount++;
    }
    else
    {
        printf("Error : grammar file cannot be opened\n");
        return -1;
    }

    Identifier arguments  [argc - 1 / 2];
    Identifier dictionnary[grammarLinesCount];

    for (int i = 1; i < argc - 1 / 2; i ++)
    {
        if (i % 2 == 0) // pair   => value
            strcpy(arguments[i - 2].value, *(argv + i));
        else            // impair => key
            strcpy(arguments[i - 1].key, *(argv + i));
    }

    /*
    fseek(grammar, 0, SEEK_SET);
    for (int i = 0; i < grammarLinesCount; i++)
        fscanf(grammar, "%s:%s\n", &dictionnary[i].key, &dictionnary[i].value);
    */


    /* TEST */
    for (int i = 0; i < argc / 2; i++)
        printf("[%s:%s]\n", arguments[i].key, arguments[i].value);
    
    fclose(grammar);
    return 0;
}


// Format de fin : 1:200;:2;2:2;3:48;4:58,3,78;