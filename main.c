#include <stdio.h>
#include "get_next_line_bonus.h"
#include <fcntl.h>

int main(void)
{
	int		fd;
	int		fd2;
	fd = open("a.txt", O_RDONLY);
	fd2 = open("b.txt", O_RDONLY);
	printf("%s \n", get_next_line(fd));
	printf("%s \n", get_next_line(fd2));
	return 0;
}
