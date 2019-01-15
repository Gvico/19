/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:51:50 by gvico             #+#    #+#             */
/*   Updated: 2019/01/15 10:01:42 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		buff;
	t_list	*tmp;

	tmp = lst;
	while (lst->next)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			buff = lst->data;
			lst->data = lst->next->data;
			lst->next->data = buff;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
