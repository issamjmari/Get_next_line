#include "get_next_line.h"

int	there_isn(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	if (!s[i])
		return (i);
	return (0);
}

char	*get_next_line(int fd)
{
	static char		*stock;
	char			s[BUFFER_SIZE + 1];
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
		// printf("i: %d\n", i);
		if (i)
		{
			char *ret = ft_substr(stock, 0, i);
			stock = ft_substr(stock, i + 1, ft_strlen(stock));
			// printf("stock: %s|\n", stock);
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