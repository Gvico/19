/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:55:02 by gvico             #+#    #+#             */
/*   Updated: 2019/01/28 12:02:36 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_file(t_list **file, int fd)
{
	t_list				*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	int						i;
	int						ret;
	char					buf[BUFF_SIZE + 1];
	static t_list	*file;
	t_list				*curr;

	if ((fd < 0 || !line || read(fd, buf, 0) < 0))
		return (-1);
	curr = get_file(&file, fd);
	MEMCHK((*line = ft_strnew(1)));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		MEMCHK((curr->content = ft_strjoin(curr->content, buf)));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(curr->content))
		return (0);
	i = ft_cpytochr(line, curr->content, '\n');
	if (i < (int)ft_strlen(curr->content))
		curr->content += (i + 1);
	else
		ft_strclr(curr->content);
	return (1);
}
