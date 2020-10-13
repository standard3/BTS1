// Ecrire un programme en C capable de crypter et décrypter des messages via le chiffre de César.

#include <stdio.h>

int crypter(int decalage, char message[])
{
    int i = 0;

    while (message[i] != '\0')
    {
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            char c = message[i] - 'A';
            c += decalage;
            c = c % 26;
            message[i] = c + 'A';
        }
        i++;
    }
    return *message;
}

int decrypter(int decalage, char message[])
{
    
}

int main() 
{
    //char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'i', 'v', 'w', 'x', 'y', 'z'};
    char message[50] = {};
    int decalage;
    char choix;

    while(choix != 'q')
    {
        printf("Voulez-vous crypter ou decrypter un message ? (c/d)\n");
        printf("(q) pour quitter\n");
        scanf("%c", &choix);
        
        switch (choix)
        {
            case 'c': // Crypter
                printf("Quel est le message a crypter ? : ");
                scanf("%s", &message);

                printf("Quel est le decalage souhaite ? : ");
                scanf("%d", &decalage);

                printf("Message : %s", crypter(decalage, message));
                break;

            case 'd': // Décrypter
                printf("Quel est le message à decrypter ? : ");
                scanf("%s", &message);

                printf("Quel est le decalage imposé ? : ");
                scanf("%d", &decalage);

                printf("%s", crypter(decalage, message));
                break;

            case 'q':
                choix = 'q';
                break;

            default:
                printf("Saisie incorrecte, veuillez reessayer.\n");
                break;
        }
            
    }
    return 0;
}

// Boucle