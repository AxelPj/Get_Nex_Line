#include "my_get_next_line.h"

char	*my_readline(int fd, char *stash)
{
	char	*buf;
	int		bytes;

	buf = my_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && my_strchr(stash, '\n') == -1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buf), free(stash), stash = NULL, NULL);
		buf[bytes] = '\0';
		if (!stash)
			stash = my_strdup(buf);
		else
			stash = my_strjoin(stash, buf);
	}
	return (free (buf), stash);
}

char	*my_recover_beforen(char *stash)
{
	int		i;
	int		pos;
	char	*line;

	i = 0;
	pos = my_strchr(stash, '\n');
	if (pos == -1)
		pos = my_strlen(stash) + 1;
	line = my_calloc(pos + 2, sizeof(char));
	if (!line)
		return (free(stash), stash = NULL, NULL);
	while (stash[i] && i <= pos)
	{
		line[i] = stash[i];
		i++;
	}
	return (line);
}

char	*my_recover_aftern(char *stash)
{
	int		i;
	int		j;
	int		pos;
	char	*newstash;

	j = 0;
	i = my_strchr(stash, '\n');
	if (i == -1)
		return (free(stash), stash = NULL, NULL);
	pos = my_strlen(stash);
	i++;
	newstash = my_calloc(pos - i + 1, sizeof(char));
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
	stash = my_readline(fd, stash);
	if (!stash)
		return (NULL);
	if (stash[0] == '\0')
		return (free(stash), stash = NULL, NULL);
	line = my_recover_beforen(stash);
	stash = my_recover_aftern(stash);
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