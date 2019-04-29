/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:32:06 by gvico             #+#    #+#             */
/*   Updated: 2019/04/29 13:48:33 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_tetro_connect(char *str)
{
	int	i;
	int	conn;

	i = 0;
	conn = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (str[i - 1] == '#')
				conn++;
			if (str[i + 1] == '#')
				conn++;
			if (str[i - 5] == '#')
				conn++;
			if (str[i + 5] == '#')
				conn++;
		}
		i++;
	}
	if (conn == 6 || conn == 8)
		return (0);
	else
		return (-1);
}

/*
** Is checked:
** - '\n' every 4 characters
** - Only '#' or '.'
** - Only 4 '#'
** - No less than 20 characters
** - Blocks connections are good (see check_tetro_connect())
*/

int	check_tetro(char *str)
{
	int	i;
	int	blocs;

	i = 0;
	blocs = 0;
	while (str[i] && i < 20)
	{
		if ((i % 5 == 4 && str[i] != '\n')
				|| (i % 5 != 4 && (str[i] != '#' && str[i] != '.'))
				|| (str[i] == '#' && ++blocs > 4))
			return (-1);
		i++;
	}
	if (i != 20 || check_tetro_connect(str) != 0)
		return (-1);
	return (0);
}

/*
** 'int' type to be changed
**	To get one Tetromino, we must read 21 characters (Tetro + \n)
** ! Don't forget to remove printf's
*/

int	read_file(int fd)
{
	char	*buf;

	if (fd < 1)
		return (-1);
	buf = ft_strnew(21);
	while (read(fd, buf, 21))
	{
		if (check_tetro(buf) != 0)
		{
			free(buf);
			return (-1);
		}
		printf("1 tetro read\n");
	}
	printf("Tetro format Ok !\n");
	return (0);
}
