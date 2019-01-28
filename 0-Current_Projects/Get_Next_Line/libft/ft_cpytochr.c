/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpytochr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 12:00:23 by gvico             #+#    #+#             */
/*   Updated: 2019/01/28 12:01:54 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cpytochr(char **dst, const char *src, char c)
{
	int		i;
	int		count;
	int		pos;

	i = 0;
	count = 0;
	while (src[i] != c)
		i++;
	pos = i;
	if (!(*dst = ft_strnew(i)))
		return (0);
	while (src[count] && count < i)
	{
		if (!(*dst = ft_strjoinchr(*dst, src[count])))
			return (0);
		count++;
	}
	return (pos);
}
