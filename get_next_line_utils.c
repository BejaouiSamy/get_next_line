#include "get_next_line.h"

void	*ft_realloc(void *ptr, size_t newsize)
{
	char	*newptr;
	size_t	cursize;

	if (ptr == 0)
		return (malloc(newsize));
	cursize = sizeof(ptr);
	if (newsize <= cursize)
		return (ptr);
	newptr = malloc(newsize);
	ft_memcpy(ptr, newptr, cursize);
	free(ptr);
	return (newptr);
}

char	*handle_end(char *line, int *line_pos)
{
	if (*line_pos > 0)
		line[*line_pos] = '\0';
	else
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	read_from_buffer(int fd, char *buffer, int *bytes_in_buffer, int *buffer_pos)
{
	if (*buffer_pos >= *bytes_in_buffer)
	{
		*bytes_in_buffer = read(fd, buffer, 1024);
		if (*bytes_in_buffer < 0)
			return (0);
		*buffer_pos = 0;
		if (*bytes_in_buffer <= 0)
			return (0);
	}
	return (1);
}

char	*extend_line(char *line, int *line_size)
{
	*line_size *= 2;
	char	*new_line;
	new_line = ft_realloc(line, *line_size);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	return (new_line);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{

	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
