/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:55:02 by gvico             #+#    #+#             */
/*   Updated: 2019/02/14 12:33:38 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_file(int fd, t_list **files)
{
	t_list			*cur;

	cur = *files;
	while (cur)
	{
		if ((int)cur->content_size == fd)
			return (cur);
		cur = cur->next;
	}
	cur = ft_lstnew("\0", fd);
	ft_lstadd(files, cur);
	return (*files);
}

int				get_next_line(const int fd, char **line)
{
	int				i;
	char			buf[BUFF_SIZE + 1];
	static t_list	*files;
	t_list			*cur;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	cur = get_file(fd, &files);
	MEMCHK((*line = ft_strnew(1)));
	while ((i = read(fd, buf, BUFF_SIZE)))
	{
		buf[i] = '\0';
		MEMCHK((cur->content = ft_strjoin(cur->content, buf)));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (!ft_strlen(cur->content))
		return (0);
	i = ft_strcpyuntil(line, cur->content, '\n');
	if (i < (int)ft_strlen(cur->content))
		cur->content += (i + 1);
	else
		ft_strclr(cur->content);
	return (1);
}
