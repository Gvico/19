/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyuntil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:29:55 by gvico             #+#    #+#             */
/*   Updated: 2019/02/07 12:32:05 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcpyuntil(char **dst, char const *src, char c)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	while (src[len] && src[len] != c)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	if (!(*dst = ft_strjoin(*dst, str)))
		return (0);
	return (len);
}
