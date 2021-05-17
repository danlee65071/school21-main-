#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd;
	char *line;
	int i;
	int b = 0;
	
	fd = open("text.txt", O_RDONLY);
	i = 1;
	//printf("%d\n", get_next_line(10000, &line));
	while (i > 0) {
		i = get_next_line(fd, &line);
		printf("|%s|\n%d\n", line, b);
		b++;
	}
//	get_next_line(fd, &line);
//	printf("%s\n", line);
//	get_next_line(fd, &line);
//	printf("%s\n", line);
	close(fd);
}
