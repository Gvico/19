/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:54:09 by gvico             #+#    #+#             */
/*   Updated: 2018/07/06 11:00:58 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	size_t	i;
	size_t	n_len;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	n_len = ft_numlen(n);
	if ((str = (char *)malloc(sizeof(char) * (n_len + 1))) == NULL)
		return (NULL);
	str[n_len] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i += 1;
	}
	while (i < n_len--)
	{
		str[n_len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
