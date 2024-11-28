/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:52:49 by axelpeti          #+#    #+#             */
/*   Updated: 2024/11/28 14:05:05 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*stach(char *buf)
{
	char		*bufcpy;
	char		*line;
	size_t		size;

	bufcpy = ft_strdup(buf);
	if (ft_strchr(bufcpy))
	{
		line = ft_strjoin(bufcpy);
		bufcpy = 
	}
	else
		get_next_line;
}

char	*get_next_line(int fd)
{
	char	*buffer;
	int 	bytes;
	char 	*line;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	line = (char *) malloc(ft_strlen() * sizeof (char *));
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1)
		return (NULL);
	while (bytes != 0)
	{
		line = stach(buffer);
	}
	return (line);
}
int main ()
{
	int fd;
	fd = open ("test.txt", O_RDONLY);
	get_next_line(fd);
	close(fd);
}