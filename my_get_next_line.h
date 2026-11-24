#ifndef MY_GET_NEXT_LINE_H
# define MY_GET_NEXT_LINE_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

int		my_strlen(char *s);
void	*my_calloc(int nmemb, int size);
char	*my_strjoin(char *s1, char *s2);
int		my_strchr(char *s, int c);
char	*my_strdup(char *s);
char	*my_readline(int fd, char *stash);
char	*my_recover_aftern(char *stash);
char	*my_recover_beforen(char *stash);
char	*get_next_line(int fd);

#endif