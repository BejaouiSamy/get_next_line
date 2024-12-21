#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char *s;
	int len;
	int i;

	while (src[len])
		len++;
	s = (char *)malloc(sizeof(char) + (len + 1));
	if (!s)
		return NULL;
	s[len] = '\0';
	while(len >= 0)
	{
		s[len] = src[len];
		len--;
	}
	return (s);
}

int ft_strlen(int str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	size_t j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1))
	if (str == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int i;
	int j;

	i = 0;
	j = 0;
	if(!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen (s2) + 1);
	if (!new)
		return (NULL);
	while(s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_join(char *dest, char *s1, char *s2)
{
	size_t i;
	size_t j;

	i = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}