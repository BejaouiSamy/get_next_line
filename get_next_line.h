#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char	*get_next_line(int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_realloc(void *ptr, size_t newsize);
char	*handle_end(char *line, int *line_pos);
int	read_from_buffer(int fd, char *buffer, int *bytes_in_buffer, int *buffer_pos);
char	*extend_line(char *line, int *line_size);

#endif
