#include "get_next_line.h"

int main()
{
	int fd = open("main.c", O_RDWR);
    char *ret = get_next_line(fd);

    int i = 0;
    while (i < 19)
    {
	    printf("%s\n", ret);
        ret = get_next_line(fd);
        i++;
    }
}
