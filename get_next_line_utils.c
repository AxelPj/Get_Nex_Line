/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:53:52 by axelpeti          #+#    #+#             */
/*   Updated: 2024/11/28 13:24:48 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int i;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	i = ft_strlen(s);
	dest = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1)
{
	char	*line;
	char 	*bufcpy;
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	line = (char *)malloc((ft_strlen(s1)) * sizeof(char));
	if (!line)
		return (NULL);
	while (s1[i] != '\n')
	{
		line[k] = s1[i];
		i++;
		k++;
	}
	return (line);
}