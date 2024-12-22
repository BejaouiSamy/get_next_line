#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd ;
	fd = open("my_txt_file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror ("error opening file");
		return (1);
	}
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
		//line = get_next_line(fd);
	}
	close (fd);
	return (0);
}