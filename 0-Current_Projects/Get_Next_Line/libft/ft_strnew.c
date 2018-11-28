/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:57:01 by gvico             #+#    #+#             */
/*   Updated: 2018/07/04 14:01:09 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *mem;

	mem = malloc(sizeof(char) * (size + 1));
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, size + 1);
	return (mem);
}
