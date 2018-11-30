/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:03:18 by gvico             #+#    #+#             */
/*   Updated: 2018/11/30 13:33:48 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_fd(char *line, char *rest)
{
	char		*buf;
	int			i;

	if ((buf = ft_strnew(BUFF_SIZE + 1)) == NULL)
		return (NULL);
	while ()
	{
		i = 0;
		ft_strclr(buf);
		if ((read(fd, buf, BUFF_SIZE)) == -1)
			return (NULL);
		while (buf[i] != '\n' && buf[i] != '\0' && buf[i] != EOF)
			i++;
		ft_strncat(line, buf, i);
		// ft_strsub ?
	}
}

int		get_next_line(const int fd, char **line)
{
	int			i;
	// char		buf[BUFF_SIZE + 1];
	static char	rest[BUFF_SIZE + 1];

	if (fd == -1 || read(fd, buf, 0) < 0 || !line)
		return (-1);
	if (*rest)
	{
		ft_strcat(*line, rest);
		ft_strclr(rest);
	}
}
