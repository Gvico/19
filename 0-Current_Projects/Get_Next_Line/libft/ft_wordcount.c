/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:08:43 by gvico             #+#    #+#             */
/*   Updated: 2018/07/06 11:10:39 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *s, char c)
{
	size_t i;
	size_t words;
	size_t len;

	i = 0;
	words = 0;
	len = ft_strlen(s);
	while (s[len] == c)
		len--;
	while (s[i] == c)
		i++;
	while (i < len)
	{
		while (s[i] != c)
			i++;
		words++;
		while (s[i] == c)
			i++;
	}
	return (words);
}
