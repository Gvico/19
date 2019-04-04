/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:03:12 by gvico             #+#    #+#             */
/*   Updated: 2019/04/03 10:43:15 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

/*
**	Test file
*/

int	main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	*line;
	int		i;

	if (argc == 1)
		return (0);
	i = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		write(2, "Open error\n", 11);
		return (-1);
	}
	if ((fd2 = open("get_next_line.c", O_RDONLY)) == -1)
	{
		write(2, "Open error\n", 11);
		return (-1);
	}
	while (get_next_line(fd, &line) && i < 15)
	{
		printf("%s\n", line);
		free(line);
		i++;
	}
	free(line);
	while (get_next_line(fd2, &line) && i < 30)
	{
		printf("%s\n", line);
		free(line);
		i++;
	}
	free(line);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	close(fd2);
	return (0);
}
