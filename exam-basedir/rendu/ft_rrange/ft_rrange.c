/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:39:31 by gvico             #+#    #+#             */
/*   Updated: 2018/12/15 15:03:27 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	tab_length(int start, int end)
{
	int	length;

	if (end >= start)
		length = end - start + 1;
	else
		length = start - end + 1;
	return (length);
}

int	*ft_rrange(int start, int end)
{
	int	*tab;
	int	i;
	int	ord;

	tab = (int *)malloc(sizeof(int) * tab_length(start, end));
	i = 0;
	ord = 0;
	if (end < start)
		ord = 1;
	while (end != start)
	{
		tab[i] = end;
		if (ord == 0)
			end--;
		else
			end++;
		i++;
	}
	tab[i] = end;
	return (tab);
}
