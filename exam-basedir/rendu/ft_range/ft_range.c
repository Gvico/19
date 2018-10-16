/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:08:09 by gvico             #+#    #+#             */
/*   Updated: 2018/10/16 13:28:10 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int i = 0;
	int size = end - start;
	if (size > 0)
		size += 1;
	if (size < 0)
		size = (size * -1) + 1;
	if (size == 0)
		size = 1;
	int	*tab = (int *)malloc(sizeof(int) * size);

	while (i < size)
	{
		tab[i] = start;
		i++;
		if (end < start)
			start--;
		else
			start++;
	}
	return (tab);
}
