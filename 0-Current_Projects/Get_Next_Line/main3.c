/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:03:12 by gvico             #+#    #+#             */
/*   Updated: 2019/04/05 14:16:14 by gvico            ###   ########.fr       */
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
	free(line);
	get_next_line(fd, &line);
	free(line);
	close(fd);
	return (0);
}
