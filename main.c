#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("text.txt", O_RDONLY);

	char *s = NULL;
	while ((s = get_next_line(fd)) != NULL)
		printf("%s", s);
	close(fd);
}
