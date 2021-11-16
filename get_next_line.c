#include "get_next_line.h"
#include "get_next_line_utils.c"
#define BUFFER_SIZE 18

int	there_isn(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' || s[i] == '\0')
			return (i);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char			s[BUFFER_SIZE + 1];
	static char		*stock;
	int				i;
	int				rd;
	char			*temp;

	rd = read(fd, &s, BUFFER_SIZE);
	s[BUFFER_SIZE] = '\0';
	if (!stock)
		stock = ft_strdup(s);
	else
		stock = ft_strjoin(stock, s);
	while (rd != 0 && rd != -1)
	{
		i = there_isn(stock);
		if (i)
		{
			char *ret = ft_substr(stock, 0, i);
			stock = ft_substr(stock, i + 1, ft_strlen(stock));
			return (ret);
		}
		else
		{
			rd = read (fd, &s, BUFFER_SIZE);
			stock = ft_strjoin(stock, s);
		}
	}
	return (0);
}