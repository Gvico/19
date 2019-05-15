/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:32:06 by gvico             #+#    #+#             */
/*   Updated: 2019/05/15 14:17:36 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Gets the minimum and maximum x and y of the tetro and sets them in the points
*/

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

/*
** Converts a 'char *' to a 't_etro' tetro (with its index number)
*/

t_etro	*get_tetro(char *str, char index)
{
	t_etro	*tetro;
	t_point	*min;
	t_point	*max;
	char	**piece;
	int		i;

	min = new_point(0, 0);
	max = new_point(0, 0);
	get_limits(str, min, max);
	piece = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i <= max->y - min->y)
	{
		piece[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(piece[i], str + min->x + (i + min->y) * 5,
				max->x - min->x + 1);
		i++;
	}
	tetro = new_tetro(piece, max->x - min->x + 1, max->y - min->y + 1, index);
	free(min);
	free(max);
	return (tetro);
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
** Checks tetro structure:
** - '\n' every 4 characters
** - Only '#' or '.'
** - Only 4 '#'
** - No less than 20 characters
** - Blocks connections are good (see check_connections())
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
** To get one Tetromino, we must read 21 characters (Tetro + \n)
** ! Must do a list
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
