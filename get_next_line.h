#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>

# define BUFFER_SIZE 10

char	*get_next_line(int fd);
size_t	ft_strlen(char const *s);
char	*ft_strchr(char *s, char c);
size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize);
char	*slicer(char *start, char *end);
char	*joiner(char *s1, char *s2);

#endif
