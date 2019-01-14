/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:03:18 by gvico             #+#    #+#             */
/*   Updated: 2019/01/14 13:02:22 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// OLD VERSION, BEFORE RESET

#include "get_next_line.h"

char	*read_fd(char *line, char *rest, int fd)
{
	char		*buf;
	int			i;

	if ((buf = ft_strnew(BUFF_SIZE + 1)) == NULL)
		return (NULL);
	while ()
	{
		// Trouver une condition pour la boucle
		i = 0;
		if ((read(fd, buf, BUFF_SIZE)) == -1)
			return (NULL);
		while (buf[i] != '\n' && buf[i] != NULL && buf[i] != EOF)
			i++;
		if (buf[i] == '\n')
		{
			buf[i] == '\0';
			ft_strjoin(line, buf);
			// Mettre le reste dans rest
			rest = ft_strsub(buf, i + 1, BUFF_SIZE - i);
			// GNL doit retourner 1
		}
		ft_strjoin(line, buf);
		ft_strclr(buf);
	}
}

int		get_next_line(const int fd, char **line)
{
	int			i;
	int			ret;
	static char	*rest = ft_strnew(BUFF_SIZE + 1);

	if (fd == -1 || read(fd, buf, 0) < 0 || !line)
		return (-1);
	if (*rest)
	{
		ft_strcat(*line, rest);
		ft_strclr(rest);
	}
	// if ((rest = read_fd(*line, rest)) == NULL)
}
