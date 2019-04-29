/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 08:55:52 by gvico             #+#    #+#             */
/*   Updated: 2018/07/06 10:15:39 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*new;

	start = f(lst);
	if (start == NULL)
		return (NULL);
	new = start;
	while (lst->next)
	{
		lst = lst->next;
		new->next = f(lst);
		if (new->next == NULL)
			return (NULL);
		new = new->next;
	}
	return (start);
}
