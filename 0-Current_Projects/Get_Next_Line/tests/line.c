#include <unistd.h>
#include <stdlib.h>

void	test(char **line)
{
	char	*ptr;

	ptr = *line;
	(*line)[2] = 'V';
	ptr[2] = 'G';
}

int		main(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 6);
	test(&str);
	write(1, &(str[2]), 1);
	write(1, "\n", 1);
	return (0);
}
