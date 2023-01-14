#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int		fd;
	int	i;
	int n;
	int l;
	char *buf;
	char *buf2;
	char *buf3;

	fd = open("a.txt", O_RDONLY);
	buf = (char *) malloc(sizeof(char)* 10 + 1);
	i = read(fd, buf, 10);
	i = read(-1, buf, 10);
	i = read(fd, 0, 0);
	i = read(fd, buf, 10);
	buf[i] = '\0';
	buf2[n] = '\0';
	buf3[l] = '\0';
	printf("%s", buf);
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
