/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 08:59:02 by gvico             #+#    #+#             */
/*   Updated: 2018/12/17 09:35:04 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_word(int i, int j, char *str)
{
	if (i == 1)
		i--;
	while (i <= j)
	{
		write(1, &(str[i]), 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] != '\0')
			i++;
		while (i)
		{
			j = i;
			i--;
			while (i && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
			print_word(i + 1, j - 1, argv[1]);
			if (i > 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
