/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:55:02 by gvico             #+#    #+#             */
/*   Updated: 2019/03/26 14:26:52 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fdlist	*get_file(int fd)
{
	t_fdlist			*cur;
	static t_fdlist		*files;

	cur = files;
	while (cur)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	cur->content = (char *)malloc(sizeof(char) * 1);
	(cur->content)[0] = '\0';
	cur->fd = fd;
	cur->ismalloc = 1;
	cur->next = files;
	files = cur;
	return (files);
}

int				get_next_line(const int fd, char **line)
{
	int				i;
	char			*buf;
	t_fdlist		*cur;

	MEMCHK(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1)));
	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	cur = get_file(fd);
	MEMCHK(*line = ft_strnew(1));
	while ((i = read(fd, buf, BUFF_SIZE)))
	{
		buf[i] = '\0';
		if (cur->ismalloc == 1)
			MEMCHK(cur->content = ft_strsjoin(cur->content, buf));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (!ft_strlen(cur->content))
		return (0);
	i = ft_strcpyuntil(line, cur->content, '\n');
	(i < (int)ft_strlen(cur->content)) ? cur->content += (i + 1)
	: ft_strclr(cur->content);
	free(buf);
	return (1);
}
