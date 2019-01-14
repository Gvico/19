/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:32:56 by gvico             #+#    #+#             */
/*   Updated: 2019/01/14 13:03:58 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		errcheck(int fd, char **rest, char **line)
{
	if (fd == -1 || line == NULL)
		return (-1);
	if (*rest = NULL)
		if ((rest = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))) = NULL)
			return (-1);
	return (0);
}

char	*read_fd(char *rest, int fd)
{
		char	buff[BUFF_SIZE + 1];
		int		ret;

		while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			rest = ft_strjoin(rest, buff);
		}
		return (rest);
}

int		get_next_line(int const fd, char **line)
{
	static char	*rest;
	int			i;

	if (errcheck(fd, &rest, line) == -1)
		return (-1);
}
