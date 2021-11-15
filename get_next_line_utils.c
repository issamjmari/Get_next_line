#include "get_next_line.h"
size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        int             i;
        int             j;
        char    *new;
        int             ls1;
        int             ls2;

        if (!s1 || !s2)
                return (NULL);
        ls1 = ft_strlen(s1);
        ls2 = ft_strlen(s2);
        new = (char *) malloc ((ls1 + ls2 + 1));
        if (!new)
                return (NULL);
        i = 0;
        j = 0;
        while (i < ls1)
                new[i++] = s1[j++];
        j = 0;
        while (i < (ls1 + ls2))
                new[i++] = s2[j++];
        new[i] = '\0';
        return (new);
}
