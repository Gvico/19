/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cropstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:44:13 by gvico             #+#    #+#             */
/*   Updated: 2019/04/03 13:49:05 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_cropstr(char *str, int i)
{
	char			*new;
	int				len;

	len = 0;
	while (str[i + len])
		len++;
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new[len] = '\0';
	while (--len >= 0)
		new[len] = str[i + len];
	free(str);
	return (new);
}
