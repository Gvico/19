#include <unistd.h>

char	test()
{
	static char	test[8];

	if (!test[3])
		test[3] = '0';
	else
		test[3]++;
	return (test[3]);
}

int		main()
{
	char	buf;

	buf = 'X';
	while (buf != '9')
	{
		buf = test();
		write(1, &buf, 1);
	}
	return (0);
}
