#include "get_next_line.h"

int main()
{
	int fd = open("b", O_RDWR);
    char *ret = get_next_line(fd);

    int i = 0;
    while (ret)
    {
	    printf("%s\n", ret);
        ret = get_next_line(fd);
        i++;
    }
}
