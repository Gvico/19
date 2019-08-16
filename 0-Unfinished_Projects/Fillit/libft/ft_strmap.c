/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:46:50 by gvico             #+#    #+#             */
/*   Updated: 2018/07/04 13:47:46 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	newstr = ft_strnew(ft_strlen(s));
	i = -1;
	if (newstr == NULL)
		return (NULL);
	while (s[++i])
		newstr[i] = (*f)(s[i]);
	newstr[i] = '\0';
	return (newstr);
}
