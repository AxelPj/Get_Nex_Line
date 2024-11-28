/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:53:54 by axelpeti          #+#    #+#             */
/*   Updated: 2024/11/28 13:22:37 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

#ifndef BUFFER_SIZE		//macro BUFFER_SIZE
# define BUFFER_SIZE 100  // Valeur par défaut, tu peux changer cette taille à la compilation

char	*ft_strdup(const char *s);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s);
char	*ft_strjoin(char const *s1);
#endif



/* a chaque fois que jouvre un fichier j'envoie un pointeur, je doit verifier si ce pointeur n'est pas nul pour savoir
si louverture a fonctionnera la fin il faut penser a le fermer

mon but :
ouvrir dans ma fonction principal avec open, une fois ouverte verifier le pointeur, envoyer a une fonction auxiliaire qui permettra de lire une ligne (jusqu'au \n) ou jusqu'a la limite du buffer

l'envoyer dans le buffer puis a une fonction pour quel recupere dans le buffer les charractere a envoyer dans le terminal free le buffer et retourner sur la lecture jusqua la suite d'une ligne jusqu'au \n et ceux jusqu'a la fin du fichier

fonction : strlen, strcopy ou strdup car besoin malloc mais modifier pour free le buffer sauf si on free le buffer apres lappel de fonction strdup, */