# CSV 2 XML

## Contexte

Vous êtes développeur dans l'équipe Data Management de la DSI d'une mutuelle d'assurances. Votre entreprise lance un nouveau produit d'assurance et décide de contacter par courrier tous ses clients majeurs dont le produit actuel arrive à échéance. 

Le système qui gère les comptes clients va générer tous les matins un fichier CSV contenant la liste des clients dont le produit actuel arrive à échéance avec leur date de naissance et leur adresse. 

Le service de communication, de son côté, est équipé d'un logiciel de génération de courrier à partir de fichiers XML. 

Le service client souhaite conserver une trace des courriers envoyés au client, un listing des comptes clients contactés devra être généré pour mettre à jour en retour le système qui gère les comptes clients.

Votre chef de projet vous demande de créer un programme qui va convertir le listing au format CSV en fichiers XML et créer le fichier CSV listant les clients contactés.

## Objectifs

Maîtriser les entrées/sorties vers les fichiers
+ Lire un fichier structuré
+ Manipuler les informations lues
+ Enregistrer les informations dans des fichiers indépendants

## Données en entrée

Le fichier ```20210202_input_npa.csv``` (séparateur : tabulation) sera généré quotidiennement dans le dossier ```export_npa``` par le progiciel qui gère les comptes clients et contiendra les données suivantes :

+ ID client unique
+ Prénom Nom
+ Date de naissance
+ Numéro
+ Voie
+ CP
+ Ville

Exemple : 
```
00040989	Anne-Sophie Cellier	29/06/2005	66	La Fourmengerie	53300	Soucé
00035338	Antoine Cano	20/07/1951	94	Village Epinard	53170	Ruillé-Froid-Fonds
00044688	Arthur Rodier	28/07/1905	160	Le Jardin des Petunias	53260	Forcé
```

## Données en sortie

### Fichier XML

Le logiciel de génération de courrier attend en entrée pour chaque client majeur un fichier XML au format suivant :

```xml
<?xml version="1.0" encoding="UTF-8"?>
<CLIENT>
    <LASTNAME>RODIER</LASTNAME>
    <FIRSTNAME>Arthur</FIRSTNAME>
    <ADDRESS>
        <STREET>160	Le Jardin des Petunias</STREET>
        <ZIPCODE>53260</ZIPCODE>
        <CITY>FORCE</CITY>
    </ADDRESS>
</CLIENT>
```

Les fichiers XML seront générés dans le dossier du fichier CSV et seront nommés suivant le schéma suivant : "courrier_npa_{id}.xml", exemple : ```courrier_npa_00040989.xml```.

### Listing de contact

Ce fichier CSV (séparateur : tabulation) contiendra pour chaque ligne du fichier ```20210202_input_npa.csv``` une ligne contenant les informations suivantes :

+ ID client unique
+ 1 si un fichier XML a été généré, 0 sinon

Exemple :
```
00040989	0
00035338	1
00044688	1
```

Le fichier sera nommé ```20210202_contacts_npa.csv```

## Tâches

1) Réaliser un schéma des différents systèmes et de leurs échanges pour montrer votre compréhension du sujet.
2) Créer un tableau de correspondance des données entre les fichiers pour visualiser comment sont distribuées les informations. Repérer les contrôles et transformations à réaliser.
3) Préparer votre jeu de tests.
4) Réaliser le logigramme de votre programme.
5) Préparer votre check-list de défis/difficultés.
6) Développer votre programme.