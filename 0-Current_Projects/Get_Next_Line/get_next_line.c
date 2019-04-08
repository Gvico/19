/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:55:02 by gvico             #+#    #+#             */
/*   Updated: 2019/04/08 13:54:28 by gvico            ###   ########.fr       */
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

int				free_file(int fd, t_list **files)
{
	t_list		*cur;
	t_list		*tmp;

	cur = *files;
	tmp = cur;
	if ((*files)->next)
	{
		if ((int)cur->content_size != fd)
		{
			while (cur->next && (int)cur->next->content_size != fd)
				cur = cur->next;
			tmp = cur->next;
			(cur->next->next != NULL) ? cur->next = cur->next->next
			: (cur->next = NULL);
		}
		else
			*files = (*files)->next;
	}
	else
		*files = NULL;
	free(tmp->content);
	free(tmp);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				i;
	char			*buf;
	t_list			*cur;
	static t_list	*files;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	MEMCHK(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1)));
	cur = get_file(fd, &files);
	MEMCHK(*line = ft_strnew(1));
	while ((i = read(fd, buf, BUFF_SIZE)))
	{
		buf[i] = '\0';
		MEMCHK(cur->content = ft_strsjoin(cur->content, buf));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	if (!ft_strlen(cur->content))
		return (free_file(fd, &files));
	i = ft_strcjoin(line, cur->content, '\n');
	(i < (int)ft_strlen(cur->content))
		? cur->content = ft_cropstr(cur->content, i + 1)
		: ft_strclr(cur->content);
	return (1);
}
