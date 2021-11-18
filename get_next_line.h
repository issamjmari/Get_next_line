#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
size_t  ft_strlen(const char *s);
char *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strdup(const char *str);
int ft_strchr(const char *str, int c);
#endif