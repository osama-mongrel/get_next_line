#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	flag;
	size_t		bytes_read;
	char		*line;
	char		*slice;
	char		*old_line;
	char		*nlptr;

	nlptr = NULL;
	line = NULL;
	if (flag == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
		buffer[bytes_read] = '\0';
		flag = 1;
	}
	else
		bytes_read = ft_strlen(buffer);
	while (bytes_read > 0)
	{
		nlptr = ft_strchr(buffer, '\n');
		if (nlptr != NULL)
		{
			slice = slicer(buffer, nlptr);
			if (!slice)
			{
				printf("slice");
				return (NULL);
			}
			ft_strlcpy(buffer, nlptr + 1, BUFFER_SIZE);
			if (line == NULL)
				return (slice);
			old_line = line;
			line = joiner(line, slice);
			free(slice);
			if (!old_line)
				free(old_line);
			break ;
		}
		if (line == NULL)
		{
			line = joiner("", buffer);
			continue ;
		}
		old_line = line;
		line = joiner(line, buffer);
		free(old_line);
		flag = 0;
		bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	}
	return (line);
}
