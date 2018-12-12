/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:37:28 by gvico             #+#    #+#             */
/*   Updated: 2018/12/12 10:01:04 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	epur_str(char const *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	while (*str)
	{
		ft_putchar(*str);
		str++;
		while (*str == ' ' || *str == '\t')
		{
			str++;
			if (*str != ' ' && *str != '\t' && *str != '\0')
				ft_putchar(' ');
		}
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	ft_putchar('\n');
	return (0);
}
