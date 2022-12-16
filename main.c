#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>

int main()
{
	char *c;
	int sz;
	int fd = open("foo.txt", O_RDWR);

	c = (char*) calloc(100, sizeof(char));
	printf("fd = %d\n", fd);
	sz = read(fd,c,4);

	printf("called read(%d, c, 10). returned that %d bytes were read.\n", fd, sz);
c[sz] = '\0';
printf("Those bytes are as follows: %s\n", c);
	sz = read(fd,c,4);
		printf("called read(%d, c, 10). returned that %d bytes were read.\n", fd, sz);
c[sz] = '\0';
printf("Those bytes are as follows: %s\n", c);
	sz = read(fd,c,4);
		printf("called read(%d, c, 10). returned that %d bytes were read.\n", fd, sz);
c[sz] = '\0';
printf("Those bytes are as follows: %s\n", c);
printf("Those bytes are as follows: %d\n", c[3]);
	sz = read(fd,c,4);
		printf("called read(%d, c, 10). returned that %d bytes were read.\n", fd, sz);
c[sz] = '\0';
printf("Those bytes are as follows: %s\n", c);
	sz = read(fd,c,4);
		printf("called read(%d, c, 10). returned that %d bytes were read.\n", fd, sz);
c[sz] = '\0';
printf("Those bytes are as follows: %s\n", c);
printf("Those bytes are as follows: %c\n", c[3]);

	return 0;
}

