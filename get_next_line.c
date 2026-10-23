#include "get_next_line.h"

char	*read_from_file(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;

	bytes_read = 1;
	while (!has_newline(stash) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
		if ((!stash && bytes_read == 0) || bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (stash[++i] != '\n')
		line[i] = stash[i];
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_stash(char *stash, char *line)
{
	char	*new_stash;
	int		i;
	int		j;

}
		

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*temp;
	char		*line;

	temp = read_from_file(fd, stash);
	if (!temp)
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = temp;
	line = extract_line(stash);
	stash = update_stash(stash, line);
	return (line);
}
