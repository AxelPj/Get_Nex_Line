## 1. [Get Next Line](#get-next-line)

1. [Description du projet](#description-du-projet)
2. [Installation](#installation)
3. [Utilisation](#utilisation)
4. [Fonction `get_next_line`](#fonction-get-next-line)
5. [Détails techniques](#détails-techniques)
6. [Test et validation](#test-et-validation)
7. [Contribution](#contribution)

Le projet **Get Next Line** implémente une fonction en C qui lit une ligne depuis un fichier ou l'entrée standard. L'objectif est de développer une fonction similaire à `getline`, sans utiliser de bibliothèques externes, ni la fonction `read` pour gérer les fichiers.

## [Description du projet](#description-du-projet)

La fonction **get_next_line** lit une ligne depuis un fichier ou l'entrée standard. Elle doit être capable de lire des fichiers de taille variable, de gérer les EOF (fin de fichier) et les erreurs, et de renvoyer cette ligne sous forme de chaîne de caractères terminée par un caractère nul (`'\0'`).

### Fonctionnalités principales :
- Lecture d'une ligne complète à partir d'un fichier ou de l'entrée standard.
- Gestion des fichiers de taille inconnue.
- Retourner `NULL` lorsque la fin du fichier est atteinte ou lorsqu'une erreur se produit.
- Aucun buffer statique ou dynamique n'est requis pour une ligne déjà lue.

## [Installation](#installation)

Clonez ce repository sur votre machine locale en utilisant la commande suivante :

git clone https://github.com/AxelPj/get_next_line.git
Ensuite, vous pouvez compiler le projet avec le Makefile fourni ou en utilisant gcc directement :

gcc -Wall -Wextra -Werror -o get_next_line get_next_line.c

## [Utilisation](#utilisation)
Ajoutez le fichier get_next_line.c dans votre projet.
Utilisez la fonction get_next_line() pour lire des lignes d'un fichier ou de l'entrée standard.
Voici un exemple simple d'utilisation :

```
#include "get_next_line.h"

int main(void)
{
    char *line;
    int fd = open("fichier.txt", O_RDONLY); // ou STDIN_FILENO pour l'entrée standard

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Ligne lue : %s\n", line);
        free(line); // N'oubliez pas de libérer la mémoire
    }

    close(fd);
    return 0;
}
```

## [Fonction `get_next_line`](#fonction-get-next-line)
Prototype : 
``` char *get_next_line(int fd); ```

## Paramètre :
fd : Le descripteur de fichier à partir duquel on lit (peut être un fichier ou l'entrée standard).
Retour :
Retourne une ligne lue sous forme de chaîne de caractères. La ligne est terminée par un caractère nul.
Retourne NULL en cas d'erreur ou si la fin du fichier est atteinte.

## [Détails techniques](#détails-techniques)
La fonction utilise des buffers pour stocker les caractères lus jusqu'à la lecture complète d'une ligne.
Chaque appel de get_next_line lit les caractères du fichier jusqu'à ce qu'un saut de ligne ('\n') ou la fin du fichier (EOF) soit trouvé.
La gestion de la mémoire est importante, chaque ligne lue doit être libérée après usage pour éviter les fuites de mémoire.

## [Test et validation](#test-et-validation)
Le projet inclut une série de tests pour valider le bon fonctionnement de la fonction sur différents cas de figure, tels que :

Lecture d'un fichier ligne par ligne.
Gestion des fichiers vides ou avec seulement des retours à la ligne.
Lecture d'un fichier jusqu'à la fin.
Les tests peuvent être réalisés en ajoutant des fichiers de test ou en adaptant les appels dans le programme principal.

## [Contribution](#contribution)
Si vous souhaitez contribuer à ce projet, veuillez suivre ces étapes :

Fork ce repository.
Créez une branche pour votre fonctionnalité (git checkout -b feature/ma-fonctionnalite).
Committez vos changements (git commit -am 'Ajout de ma fonctionnalité').
Poussez sur la branche (git push origin feature/ma-fonctionnalite).
Créez une pull request.
