/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:04:40 by gvico             #+#    #+#             */
/*   Updated: 2018/11/27 15:27:35 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	rstr_capitalizer(char *str)
{
	int		i;
	char	buff;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == ' ' || str[i + 1] == '	' || str[i + 1] == '\0') \
				&& (str[i] > 96 && str[i] < 123))
			buff = str[i] - 32;
		else if (str[i + 1] != ' ' && str[i + 1] != '	' \
				&& str[i + 1] != '\0' && str[i] > 64 && str[i] < 91)
			buff = str[i] + 32;
		else
			buff = str[i];
		write(1, &buff, 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		rstr_capitalizer(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
