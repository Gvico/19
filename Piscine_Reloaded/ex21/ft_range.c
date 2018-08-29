/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:14:36 by gvico             #+#    #+#             */
/*   Updated: 2018/06/12 09:20:16 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *range;
	int i;

	i = 0;
	if (min >= max)
		return (NULL);
	range = (int*)malloc(sizeof(*range) * (max - min));
	while (i + min < max)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
