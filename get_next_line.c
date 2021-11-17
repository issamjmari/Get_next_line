#include "get_next_line.h"

char *stock_n(int fd, char *s)
{
	char	*temp;
	char	*sum;
	int		rd;

	rd = read(fd, &s, BUFFER_SIZE);
	s[BUFFER_SIZE] = '\0';
	sum = ft_strdup(s);
	while (rd != 0)
	{
		rd = read(fd, &s, BUFFER_SIZE);
		s[BUFFER_SIZE] = '\0';
		sum = ft_strjoin(sum, s);
	}
	printf("%s\n", sum);
	return (0);
}
char	*get_next_line(int fd)
{
	char	*stock;
	char	s[BUFFER_SIZE + 1];

	stock = stock_n(fd, s);
	return (0);
}