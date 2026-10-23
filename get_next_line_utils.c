#include "get_next_line.h"

int	has_newline(char *stash)
{
	int	i;

	if (stash == NULL)
		return (0);
	i = 0;
	while (stash[i])
		if (stash[i++] == '\n')
			return (1);
	return (0);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*new_stash;
	int		i;
	int		j;

	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer) + 1));
	if (!new_stash)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		new_stash[i] = stash[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		new_stash[i++] = buffer[j++];
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	int		i;

	if (count && size > (size_t)-1 / count)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < count * size)
		p[i++] = '\0';
	return (p);
}

int	ft_strlen(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		;
	return (i);
}
