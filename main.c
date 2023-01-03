#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int i;
	int fd = open("texto.txt", O_RDWR);
	printf("%s\n", get_next_line(fd));
	return 0;
}

