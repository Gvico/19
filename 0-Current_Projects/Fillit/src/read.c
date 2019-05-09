/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:32:06 by gvico             #+#    #+#             */
/*   Updated: 2019/05/09 13:41:55 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_limits(char *str, t_point *min, t_point *max)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
		}
		i++;
	}
}

t_etro	*get_tetro(char *str)
{
	t_etro	*tetro;
	t_point	*min;
	t_point	*max;
	char	**piece;
	int		i;

	get_limits(str, min, max);
	i = 0;
}

/*
** Checks the number of connections between two '#'s.
** If there are 6 or 8, it is a tetromino!
*/

int		check_connections(char *str)
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

int		check_tetro(char *str)
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
	if (i != 20 || check_connections(str) != 0)
		return (-1);
	return (0);
}

/*
**	To get one Tetromino, we must read 21 characters (Tetro + \n)
**  Must do a list
** ! Don't forget to remove printf's
*/

t_etro	*read_file(int fd)
{
	char	*buf;

	if (fd < 1)
		return (NULL);
	buf = ft_strnew(21);
	while (read(fd, buf, 21))
	{
		if (check_tetro(buf) != 0)
		{
			free(buf);
			return (NULL);
		}
		printf("1 tetro read\n");
	}
	printf("Tetro format Ok !\n");
	return (0);
}
