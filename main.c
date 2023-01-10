#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int		fd;
	fd = open("a.txt", O_RDONLY);
	printf("%s \n", get_next_line(fd));
	return 0;
}
// int main(void)
// {
// 	int		fd;
// 	int		fd2;
// 	int		i;
// 	int		n;
// 	char *b = "";
// 	fd = open("a.txt", O_RDONLY);
// 	// fd1 = open("b.txt", O_RDONLY);
// 	fd2 = 4,

// 	i = check_empty(fd, b);
// 	printf("%d\n", i);

// 	return 0;
// }
