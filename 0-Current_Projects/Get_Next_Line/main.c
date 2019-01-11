#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	if (argc == 1)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		write(2, "Open error\n", 11);
		return (-1);
	}
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
