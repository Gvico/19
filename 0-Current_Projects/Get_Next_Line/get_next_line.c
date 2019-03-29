/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:55:02 by gvico             #+#    #+#             */
/*   Updated: 2019/03/22 10:33:41 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*cropstr(char *str, int i)
{
	char			*new;
	int				len;

	len = 0;
	while (str[i + len])
		len++;
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new[len] = '\0';
	while (--len >= 0)
		new[len] = str[i + len];
	free(str);
	return (new);
}

static t_list	*get_file(int fd)
{
	t_list			*cur;
	static t_list	*files;

	cur = files;
	while (cur)
	{
		if ((int)cur->content_size == fd)
			return (cur);
		cur = cur->next;
	}
	cur = ft_lstnew("\0", fd);
	ft_lstadd(&files, cur);
	return (files);
}

int				get_next_line(const int fd, char **line)
{
	int				i;
	char			*buf;
	t_list			*cur;

	MEMCHK(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1)));
	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	cur = get_file(fd);
	MEMCHK(*line = ft_strnew(1));
	while ((i = read(fd, buf, BUFF_SIZE)))
	{
		buf[i] = '\0';
		MEMCHK(cur->content = ft_strsjoin(cur->content, buf));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (!ft_strlen(cur->content))
		return (0);
	i = ft_strcjoin(line, cur->content, '\n');
	(i < (int)ft_strlen(cur->content))
	? cur->content = cropstr(cur->content, i + 1)
	: ft_strclr(cur->content);
	free(buf);
	return (1);
}
