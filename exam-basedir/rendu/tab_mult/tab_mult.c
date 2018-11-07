/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:47:18 by exam              #+#    #+#             */
/*   Updated: 2018/11/07 14:44:28 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;
	char	buf;

	i = 0;
	while (str[i] != '\0')
	{
		buf = str[i];
		write(1, &buf, 1);
		i++;
	}
}

int		ft_pow10(const int nb)
{
	int puiss;
	int nbr;

	puiss = 1;
	nbr = nb;
	while (nbr > 0)
	{
		puiss *= 10;
		nbr--;
	}
	return (puiss);
}

int		cus_atoi(const char *str)
{
	int nbr;
	int len;
	int i;

	nbr = 0;
	len = 0;
	i = 0;
	while (str[len + 1] != '\0')
		len++;
	while (i <= len)
	{
		nbr += (str[i] - '0') * ft_pow10(len - i);
		i++;
	}
	return (nbr);
}

int		ft_numlen(const int nb)
{
	int len;
	int nbr;

	len = 0;
	nbr = nb;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

void	cus_itoa(const int nb)
{
	int		nbr;
	int		len;
	char	buf;

	nbr = nb;
	len = ft_numlen(nbr) - 1;
	while (len >= 0)
	{
		buf = (nbr / ft_pow10(len)) + '0';
		write(1, &buf, 1);
		nbr -= (nbr / ft_pow10(len)) * ft_pow10(len);
		len--;
	}
}

int		main(int argc, char **argv)
{
	int i;
	int nb;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	nb = cus_atoi(argv[1]);
	while (i <= 9)
	{
		cus_itoa(i);
		ft_putstr(" x ");
		cus_itoa(nb);
		ft_putstr(" = ");
		cus_itoa(nb * i);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
