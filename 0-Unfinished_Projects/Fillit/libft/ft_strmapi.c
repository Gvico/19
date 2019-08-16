/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 11:34:15 by gvico             #+#    #+#             */
/*   Updated: 2018/07/04 13:48:29 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (s == NULL || f == NULL)
		return (NULL);
	newstr = ft_strnew(ft_strlen(s));
	i = -1;
	j = -1;
	if (!newstr)
		return (NULL);
	while (s[++i])
		newstr[i] = (*f)(++j, s[i]);
	newstr[i] = '\0';
	return (newstr);
}
