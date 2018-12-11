/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:52:04 by gvico             #+#    #+#             */
/*   Updated: 2018/12/11 15:43:35 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		cus_wordcount(char *str)
{
	int		words;

	words = 0;
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
			str++;
		if (*str && *str != ' ' && *str != '\t' & *str != '\n')
		{
			words++;
			while (*str && *str != ' ' && *str != '\t' && *str != '\n')
				str++;
		}
	}
	return (words);
}

int		cus_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != ' ' && str[i] != '	' && str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

char	*putword(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char *str)
{
	char	**words;
	int		i;

	words = (char **)malloc(sizeof(char *) * (cus_wordcount(str) + 1));
	i = 0;
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
			str++;
		if (*str)
		{
			words[i] = putword(str);
			i++;
			while (*str && *str != ' ' && *str != '\t' && *str != '\n')
				str++;
		}
	}
	words[i] = NULL;
	return (words);
}
