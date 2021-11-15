#include "get_next_line.h"
char *get_next_line(int fd)
{
    char        s[BUFFER_SIZE + 1];
    int         rd;
    static char *temp;
    int         i;

    rd = read(fd, &s, BUFFER_SIZE);
    while (rd != 0)
    {
        temp = malloc(rd + 1);
        i = 0;
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
        printf("%s\n", temp);
        rd = read(fd, &s, BUFFER_SIZE);
    }
    printf("%s\n", temp);
    return 0;
}