#include "get_next_line.h"

char	*read_from_file(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	bytes_read = 1;
	while (!has_newline(stash) && bytes_read != 0)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((!stash && bytes_read == 0) || bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
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

	i = ft_strlen(line);
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (stash[i++])
		j++;
	new_stash = malloc(sizeof(char) * (j + 1));
	if (!new_stash)
		return (NULL);
	i = ft_strlen(line);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*temp;
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
			return (NULL);
	temp = read_from_file(fd, stash[fd]);
	if (!temp)
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	stash[fd] = temp;
	line = extract_line(stash[fd]);
	stash[fd] = update_stash(stash[fd], line);
	return (line);
}
