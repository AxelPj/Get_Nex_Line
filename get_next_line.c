/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:16:37 by axelpeti          #+#    #+#             */
/*   Updated: 2024/12/09 11:11:43 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readline(int fd, char *stash)
{
	char	*buf;
	int		bytes;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && ft_strchr(stash, '\n') == -1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buf), free(stash), stash = NULL, NULL);
		buf[bytes] = '\0';
		if (!stash)
			stash = ft_strdup(buf);
		else
			stash = ft_strjoin(stash, buf);
	}
	return (free (buf), stash);
}

char	*recover_beforen(char *stash)
{
	int		i;
	int		pos;
	char	*line;

	i = 0;
	pos = ft_strchr(stash, '\n');
	if (pos == -1)
		pos = ft_strlen(stash) + 1;
	line = ft_calloc(pos + 2, sizeof(char));
	if (!line)
		return (free(stash), stash = NULL, NULL);
	while (stash[i] && i <= pos)
	{
		line[i] = stash[i];
		i++;
	}
	return (line);
}

char	*recover_aftern(char *stash)
{
	int		i;
	int		j;
	int		pos;
	char	*newstash;

	j = 0;
	i = ft_strchr(stash, '\n');
	if (i == -1)
		return (free(stash), stash = NULL, NULL);
	pos = ft_strlen(stash);
	i++;
	newstash = ft_calloc(pos - i + 1, sizeof(char));
	if (!newstash)
		return (free(stash), stash = NULL, NULL);
	while (stash[i])
	{
		newstash[j] = stash[i];
		j++;
		i++;
	}
	free(stash);
	stash = NULL;
	return (newstash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = readline(fd, stash);
	if (!stash)
		return (NULL);
	if (stash[0] == '\0')
		return (free(stash), stash = NULL, NULL);
	line = recover_beforen(stash);
	stash = recover_aftern(stash);
	return (line);
}
/* 
int main(void)
{
	char	*line;
	int fd = open("41_no_nl", O_RDONLY);
	line = (get_next_line(fd));
	printf("line = %s", line);
	free(line);
	line = (get_next_line(fd));
	printf("line = %s", line);
	free(line);
	close(fd);
} */