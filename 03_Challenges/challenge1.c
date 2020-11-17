// Ecrire un programme en C capable de crypter et décrypter des messages via le chiffre de César.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char message[100];
    short decalage = 0; 
    short tailleMessage; 
    short choix;

    printf("Entrer le message : ");
    gets(message);

    printf("\nEntrer le decalage : ");
    scanf("%d", &decalage);

    tailleMessage = strlen(message);
    printf("\nEntrer le choix :\n1. Crypter\n2. Decrypter\n");
    scanf("%d", &choix);

    switch(choix)
    {
        case 1: // Crypter
            for (int i = 0; i < tailleMessage; i++) // Nombre de lettres dans message
            {
                message[i] = tolower(message[i]);

                if (message[i] + decalage > 'z')
                {
                    message[i] += decalage;
                    message[i] -= 26;
                }
                else
                {
                    message[i] += decalage;
                }
            }
            printf("Message crypte : %s", message);
            break;

        case 2: // Décrypter
            for (int i = 0; i < tailleMessage; i++) // Nombre de lettres dans message
            {
                message[i] = tolower(message[i]);

                if (message[i] - decalage < 'a')
                {
                    message[i] -= decalage;
                    message[i] += 26;
                }
                else
                {
                    message[i] -= decalage;
                }
            
            }
            printf("Message decrypte : %s", message);
            break;

        default:
            printf("Mauvaise saisie, reesayer.\n");
            break;
    }     
    return 0;
}