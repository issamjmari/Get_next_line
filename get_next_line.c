#include "get_next_line.h"
#include "get_next_line_utils.c"
// void ft_stock(char *p)
// {
//     static 	char	*join;
//     static int		i;
// 	int				j;

// 	j = 0;
// 	if (i == 0)
// 	{
//     	while (p[j])
// 		{
// 			join[j] = p[j];
// 			j++;
// 		}
// 	}
// 	else
// 		join = ft_strjoin(join, p);
// 	i++;
// 	printf("%s\n", join);
// }

char *get_next_line(int fd)
{
    char        s[BUFFER_SIZE];
    int         rd;
    char		*temp;
    int         i;
	char		*stock;

    rd = read(fd, &s, BUFFER_SIZE);
    while (rd != 0)
    {
        i = 0;
        temp = malloc(rd + 1);
        while (s[i])
        {
            if (s[i] != '\n' && s[i] != '\0')
            {
                temp[i] = s[i];
                i++;
            }
            else
                return (&temp[0]);
        }
		stock = ft_strjoin(stock, temp);
		printf("%s\n", stock);
		free(temp);
        rd = read(fd, &s, BUFFER_SIZE);
    }
    return 0;
}