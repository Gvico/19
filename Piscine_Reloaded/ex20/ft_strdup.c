/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:06:43 by gvico             #+#    #+#             */
/*   Updated: 2018/06/12 09:13:06 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i] != '\0')
		i++;
	dest = (char*)malloc(sizeof(*dest) * (i + 1));
	dest[i + 1] = '\0';
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
	return (dest);
}
