#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
	{
	int fd = open("", O_RDWR);
	int fd2 = open("texto.txt", O_RDWR);
	char *str;
	char *str1;
	printf("%ld", sizeof(char**));
	printf("%ld", sizeof(char*));
	printf("%ld", sizeof(char));
	str = get_next_line(fd);
	str1 = get_next_line(fd2);
	// str = get_next_line(fd);
	// str1 = get_next_line(fd);
	printf("%s", str);
	printf("%s", str1);
	str1 = get_next_line(fd2);
	printf("%s", str1);
	// str = get_next_line(fd);
	// str1 = get_next_line(fd);
	// printf("%s", str);
	// printf("%s", str1);
	// str = get_next_line(fd);
	// str1 = get_next_line(fd);
	// printf("%s", str);
	// printf("%s", str1);
	return 0;
}
