/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:03:18 by gvico             #+#    #+#             */
/*   Updated: 2018/11/28 13:46:55 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int			i;
	char		buf[BUFF_SIZE + 1];
	static char	rest[BUFF_SIZE + 1];

	if (fd == -1 || read(fd, buffer, 0) < 0 || !line)
		return (-1);
	if (*rest)
		ft_strcpy(*line, rest);
/*
	i = 0;
	read(fd, buf, BUFF_SIZE);
	while (buf[i] != '\n' && i < BUFF_SIZE)
	{
		**line = buf[i];
		i++;
		*line++;
	}
*/
}
