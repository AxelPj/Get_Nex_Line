/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:19:22 by axelpeti          #+#    #+#             */
/*   Updated: 2024/12/09 11:10:49 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(int nmemb, int size)
{
	void			*tab;
	size_t			total_size;
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	total_size = (size_t)nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tab = malloc(total_size);
	if (!tab)
		return (NULL);
	ptr = (unsigned char *)tab;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (tab);
}

int	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	j = 0;
	i = 0;
	s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (s1 && s1[i])
		s[k++] = s1[i++];
	while (s2 && s2[j])
		s[k++] = s2[j++];
	s[k] = '\0';
	return (free(s1), s);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	size_t	i;

	i = 0;
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

int	ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if ((char)c == '\0')
		return (i);
	return (-1);
}
