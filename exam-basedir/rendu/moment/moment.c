/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:36:35 by exam              #+#    #+#             */
/*   Updated: 2019/01/30 11:44:47 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	cus_numlen(unsigned int nbr)
{
	int				len;

	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	if (len == 0)
		len++;
	return (len);
}

char			*cus_itoa(unsigned int nbr, int len)
{
	char			*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	return (str);
}

void			cus_cpy(char const *src, char *dst)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (dst[j])
		j++;
	while (src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
}

char			*mtime(unsigned int duration, char type)
{
	int				len;
	char			*nbr;
	char			*res;

	if (type == 5)
		duration /= 2592000;
	else if (type == 4)
		duration /= 86400;
	else if (type == 3)
		duration /= 3600;
	else if (type == 2)
		duration /= 60;

	len = cus_numlen(duration);
	nbr = cus_itoa(duration, len);
	res = (char *)malloc(sizeof(char) * (len + 10));

	cus_cpy(nbr, res);
	if (type == 5)
		cus_cpy(" month", res);
	else if (type == 4)
		cus_cpy(" day", res);
	else if (type == 3)
		cus_cpy(" hour", res);
	else if (type == 2)
		cus_cpy(" minute", res);
	else
		cus_cpy(" second", res);
	if (duration > 1 || duration == 0)
		cus_cpy("s", res);
	cus_cpy(" ago.\0", res);

	return (res);
}

char		*moment(unsigned int duration)
{
	char			*res;

	if (duration > 2591999)
		res = mtime(duration, 5);
	else if (duration > 86399)
		res = mtime(duration, 4);
	else if (duration > 3599)
		res = mtime(duration, 3);
	else if (duration > 59)
		res = mtime(duration, 2);
	else
		res = mtime(duration, 1);
	return (res);
}
