/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 10:31:51 by gvico             #+#    #+#             */
/*   Updated: 2018/07/06 11:10:46 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	size_t	deb;
	size_t	fin;
	size_t	i;
	size_t	mots;
	char	**tab;

	mots = 0;
	tab = NULL;
	i = 0;
	if (s && (tab = (char **)malloc(sizeof(*tab) * (ft_wordcount(s, c) + 1))))
	{
		while (i < ft_strlen(s))
		{
			while (s[i] == c && s[i])
				i++;
			deb = i;
			while (s[i] != c && s[i])
				i++;
			fin = i;
			if ((fin - deb) > 0)
				tab[mots++] = ft_strsub(s, deb, fin - deb);
		}
		tab[mots] = 0;
	}
	return (tab);
}
