# Get Next Line

## Présentation

Get Next Line est une bibliothèque C permettant de lire une ligne à partir d'un descripteur de fichier à chaque appel.

## Sommaire

- [À propos](#à-propos)
- [Fonctionnalités](#fonctionnalités)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Structure du projet](#structure-du-projet)
- [Contributions](#contributions)

## À propos

Ce projet fournit une fonction `get_next_line` qui renvoie la prochaine ligne disponible depuis un fichier ou depuis l'entrée standard. La fonction gère les fins de ligne, la fin de fichier et les tailles de mémoire dynamiques.

## Fonctionnalités

- Lecture ligne par ligne depuis un descripteur de fichier.
- Gestion configurable de la taille du tampon avec `BUFFER_SIZE`.
- Gestion des fins de fichier et des erreurs.
- Fonctions utilitaires préfixées `my_`.
- Compilation en bibliothèque statique.

## Installation

Clonez le dépôt puis compilez la bibliothèque :

```bash
git clone https://github.com/AxelPj/Get_Nex_Line.git
cd Get_Nex_Line
make
```

Pour compiler également la variante multi-descripteurs :

```bash
make bonus
```

## Utilisation

Incluez l'en-tête `my_get_next_line.h` et compilez votre programme avec la bibliothèque :

```c
#include "my_get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd = open("fichier.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

```bash
gcc -Wall -Wextra -Werror main.c libmy_get_next_line.a -I. -o main
./main
```

## Structure du projet

```text
Get_Nex_Line/
├── my_get_next_line.c
├── my_get_next_line.h
├── my_get_next_line_utils.c
├── my_get_next_line_bonus.c
├── my_get_next_line_bonus.h
├── my_get_next_line_utils_bonus.c
├── Makefile
└── README.md
```

## Contributions

Les contributions sont les bienvenues.

1. Forkez le dépôt.
2. Créez une branche dédiée.
3. Ajoutez vos modifications avec des tests adaptés.
4. Ouvrez une pull request avec une description claire des changements.
