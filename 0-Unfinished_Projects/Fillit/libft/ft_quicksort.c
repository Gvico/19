/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:22:03 by gvico             #+#    #+#             */
/*   Updated: 2019/03/18 10:07:52 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	qs_partition(int *tab, int start, int end)
{
	int	piv;
	int	i;
	int	j;

	piv = tab[end];
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (tab[j] <= piv)
		{
			i++;
			ft_swap(&tab[i], &tab[j]);
		}
		j++;
	}
	ft_swap(&tab[i + 1], &tab[j]);
	return (i + 1);
}

void		ft_quicksort(int *tab, int start, int end)
{
	int	pi;

	if (start < end)
	{
		pi = qs_partition(tab, start, end);
		ft_quicksort(tab, start, pi - 1);
		ft_quicksort(tab, pi + 1, end);
	}
}
