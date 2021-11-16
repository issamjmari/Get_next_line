#include "get_next_line.h"
#include "get_next_line_utils.c"

int	there_isn(char *s)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (s[i] == '\n')
			return (1);
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

	i = 0;
	rd = read(fd, &s, BUFFER_SIZE);
	s[BUFFER_SIZE] = '\0';
	stock = ft_strdup(s);
	while (rd != 0)
	{
		if (there_isn(s))
			return (ft_substr(stock, 0, ft_strlen(stock) - 1));
		else
		{
			rd = read (fd, &s, BUFFER_SIZE);
			stock = ft_strjoin(stock, s);
		}
	}
	return (0);
}