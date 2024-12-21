#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	buffer[1024];
	static int bytes_in_buff;
	static int buffer_pos;

	//bytes_in_buff = 0;
	//buffer_pos = 0;
	char *line;
	line = malloc(1024);
	if (!line)
		return (NULL);
	int line_pos;
	line_pos = 0;
	while (1)
	{
		if (buffer_pos >= bytes_in_buff)
		{
			bytes_in_buff = read(fd, buffer, sizeof(buffer));
			buffer_pos = 0;
			if (bytes_in_buff <= 0)
			{
				free (line);
				return (NULL);
			}
		}
		char c;
		c = buffer[buffer_pos++];
		line[line_pos++] = c;
		if (c == '\n')
			break;
	}
	line[line_pos] = '\0';
	return (line);
}