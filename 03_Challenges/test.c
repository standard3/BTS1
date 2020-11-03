// Ecrire un programme en C capable de crypter et décrypter des messages via le chiffre de César.

#include <stdio.h>
#include <string.h>

void crypter(int decalage, char* message)
{
    char ch;
    int i;
    for (i = 0; message[i] != '\0'; ++i) // Nombre de lettres dans message
    {
        message[i] = tolower(message[i]);

        ch = message[i];

        if ( ch >= 'a' && ch <= 'z')
        {
            ch += decalage;

            if (ch > 'z')
            {
                ch -= 'z' + 'a' - 1;

            }
            message[i] = ch;
        }
    }
}

/*
char decrypter(int decalage, char message[])
{
    char ch;
    int i;
    for (i = 0; message[i] != '\0'; ++i)
    {
        while (message[i])
        {
            putchar(tolower(message[i])); // Convertir en lowercase
            i++;
        }

        ch = message[i];

        if ( ch >= 'a' && ch <= 'z')
        {
            ch -= decalage;

            if (ch > 'z')
            {
                ch += 'z' + 'a' + 1;
            }
            message[i] = ch;
        }
    }
    return *message;
}*/

int main()
{
    char message[100];
    int decalage = 0, taille, choix;

    printf("Entrer le message : ");
    scanf("%s", message);

    printf("\nEntrer le decalage : ");
    scanf("%d", &decalage);

    do
    {
        taille = strlen(message);
        printf("\nEntrer le choix :\n1. Crypter\n2. Decrypter\n");
        scanf("%d", &choix);

        if (choix == 1)
        {
            crypter(decalage, message);
            printf("Message crypte : %s", message);
        }
        else if (choix == 2)
        {
            //printf("Message decrypte : %s", decrypter(decalage, message));
        }
        else
        {
            printf("Mauvaise saisie, reesayer.\n");
        }
        
    } while (1);
    return 0;
}