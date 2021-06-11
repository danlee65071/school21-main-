#include "get_next_line.h"

int main()
{
	int fd;
	int i;
	char *line;

	fd = open("text.txt", O_RDONLY);
	i = 0;
	while((i = get_next_line(fd, &line)) > 0)
	{
		printf("i = %d |%s|\n", i, line);
		free(line);
	}
	if (line)
	{
		printf("i = %d |%s|\n", i, line);
		free(line);
	}
	return 0;
}
