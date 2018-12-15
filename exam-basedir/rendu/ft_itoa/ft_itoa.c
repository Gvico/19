/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:08:00 by gvico             #+#    #+#             */
/*   Updated: 2018/12/15 15:24:23 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i] != '\0')
		i++;
	s2 = (char*)malloc(sizeof(*s2) * (i + 1));
	if (s2 == NULL)
		return (NULL);
	s2[i] = '\0';
	while (--i >= 0)
		s2[i] = s1[i];
	return (s2);
}

void	isneg(int *nbr, int *neg)
{
	if (*nbr < 0)
	{
		*neg = 1;
		*nbr *= -1;
	}
}

char	*ft_itoa(int nbr)
{
	int		n_tmp;
	int		len;
	int		neg;
	char	*str;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	n_tmp = nbr;
	len = 2;
	neg = 0;
	isneg(&nbr, &neg);
	while (n_tmp /= 10)
		len++;
	len += neg;
	str = (char *)malloc(sizeof(char) * len);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
