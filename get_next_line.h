#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 5

char	*get_next_line(int fd);
int		has_newline(char *stash);
char	*ft_strjoin(char *stash, char *buffer);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(char *s);

#endif
