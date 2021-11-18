#include "/Users/ijmari/Desktop/get/get_next_line.h"

int	there_isn(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1); 
		i++;
	}
	return (0);
}
char	*ft_get_tilln(const char *stock)
{
	int	i;

	i = 0;
	if (!stock)
		return (NULL);
	while (stock[i] && stock[i] != '\n')		
		i++;
	return (ft_substr(stock, 0, i));
}
char	*ft_remain(char *stock)
{
	int		i;
	char	*temp;

	i = 0;
	if (!stock)
		return (NULL);
	while (stock[i])
	{
		if (stock[i] == '\n')
		{
			temp = ft_substr(stock, i + 1, ft_strlen(stock));
			free(stock);
			return (temp);
		}
		i++;
	}
	return (0);
}
char	*ft_form(int fd, char *stock)
{
	char	*temp;
	int		rd;

	temp = (char *) malloc (BUFFER_SIZE + 1);
	rd = 1;
	while (!there_isn(stock) && rd != 0)
	{
		rd = read (fd, temp, BUFFER_SIZE);
		if (rd == -1)
		{
			free (temp);
			return (NULL);
		}
		temp[rd] = '\0';
		stock = ft_strjoin(stock, temp);
	}
	free (temp);
	return (stock);
}
char	*get_next_line(int fd)
{
	char		*ret;
	static char	*stock;

	stock = ft_form(fd, stock);
	ret = ft_get_tilln(stock);
	stock = ft_remain(stock);
	return (ret);
}