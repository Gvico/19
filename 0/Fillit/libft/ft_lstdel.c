/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 08:34:09 by gvico             #+#    #+#             */
/*   Updated: 2018/07/06 08:37:47 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nxt;
	t_list	*cur;

	nxt = *alst;
	while (nxt != NULL)
	{
		cur = nxt;
		del(cur->content, cur->content_size);
		nxt = cur->next;
		free(cur);
	}
	*alst = NULL;
}
