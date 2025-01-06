#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[1024];
	static int	bytes_in_buff;
	static int	buffer_pos;
	int		line_size;
	int		line_pos;

	line_size = 1024;
	line_pos = 0;
	char	*line;
	line = malloc(1024);
	if (!line)
		return (NULL);
	while (1)
	{
		if (!read_from_buffer(fd, buffer, &bytes_in_buff, &buffer_pos))
			return (handle_end(line, &line_pos));
		line[line_pos++] = buffer[buffer_pos++];
		if(line_pos >= line_size && !(line = extend_line(line, &line_size)))
			return (NULL);
		if (line[line_pos - 1] == '\n')
			break;
	}
	line[line_pos] = '\0';
	return(line);
}

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
	}
	close (fd);
	return (0);
}
