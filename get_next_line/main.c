#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int main()
{
    int fd = open("42", O_RDONLY);
	char *line;
	int i = 0;

/*	while (i < 10) {
		get_next_line(fd, &line);
		printf("%s\n", line);
		i++;
	}*/
	get_next_line(fd, &line);
	printf("%s\n", line);
    get_next_line(fd, &line);
	printf("%s\n", line);
    get_next_line(fd, &line);
	printf("%s\n", line);
    get_next_line(fd, &line);
	printf("%s\n", line);
	close(fd);
}
