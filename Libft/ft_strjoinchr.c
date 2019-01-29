/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 10:10:27 by gvico             #+#    #+#             */
/*   Updated: 2019/01/28 10:58:21 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinchr(char const *s1, char const c)
{
	char	*new;
	size_t	i;
	size_t	len;

	if (!s1 || !c)
		return (NULL);
	len = ft_strlen(s1);
	new = ft_strnew(len + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < len)
		*(new + 1) = *(s1 + i);
	*(new + 1) = c;
	return (new);
}
