/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:32:56 by gvico             #+#    #+#             */
/*   Updated: 2019/01/15 11:22:36 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		errcheck(int fd, char **rest, char **line)
{
	if (fd == -1 || line == NULL)
		return (-1);
	if (*rest == NULL)
		if ((*rest = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
			return (-1);
	return (0);
}

char	*read_fd(char *rest, int fd)
{
		int		ret;
		char	buff[BUFF_SIZE + 1];

		while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			rest = ft_strjoin(rest, buff);
		}
		return (rest);
}

int		get_next_line(const int fd, char **line)
{
	int			i;
	static char	*rest;

	if (errcheck(fd, &rest, line) == -1)
		return (-1);
	if (*rest)
		ft_strcpy(*line, rest);
	rest = read_fd(rest, fd);
	i = 0;
	if (rest[i])
	{
		while (rest[i] && rest[i] != '\n')
			i++;
		if (i == 0)
			(*line) = ft_strdup("");
		else
		{
			(*line) = ft_strsub(rest, 0, i);
			rest = &rest[i + 1];
		}
		return (1);
	}
	else
		(*line) = ft_strdup("");
	return (0);
}
