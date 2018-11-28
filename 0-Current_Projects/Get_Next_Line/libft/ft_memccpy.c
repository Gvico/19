/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 10:47:13 by gvico             #+#    #+#             */
/*   Updated: 2018/07/04 10:01:11 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = -1;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (++i < size)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			return (dest + i + 1);
	}
	return (NULL);
}
