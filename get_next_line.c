#include "get_next_line.h"
#include "get_next_line_utils.c"
#define BUFFER_SIZE 5
char	*ft_check(char *s)
{
	while (i < len)
		{
			if (stock[i] == '\n')
			{
				stock = ft_substr(s, 0, i);
				return (stock);
			}
			else if (stock[i + 1] == '\0')
			{
				temp = stock;
				read (fd, &s, BUFFER_SIZE);
				stock = ft_strjoin(temp, stock);
			}
			i++;
		}
}
char *get_next_line(int fd)
{
    char	s[BUFFER_SIZE];
    static	char	*stock;
    int         	i;
	int				rd;
	char			*temp;
	int				len;

    rd = read (fd, &s, BUFFER_SIZE);
	stock = ft_strdup(s);
	while (rd != 0)
	{
		i = 0;
		len = ft_strlen(stock);
		while (i < len)
		{
			if (stock[i] == '\n')
			{
				stock = ft_substr(s, 0, i);
				return (stock);
			}
			else if (stock[i + 1] == '\0')
			{
				temp = stock;
				read (fd, &s, BUFFER_SIZE);
				stock = ft_strjoin(temp, stock);
			}
			i++;
		}
	}
	return (0);
}