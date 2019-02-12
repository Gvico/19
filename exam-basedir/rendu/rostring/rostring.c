/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:17:12 by gvico             #+#    #+#             */
/*   Updated: 2019/02/12 16:13:08 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		avcheck(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (0);
	else if (c != ' ' && c != '\t' && c != '\n')
		return (1);
	else
		return (-1);
}

void	put_firstword(char *str)
{
	int	i;
	int	b;

	i = 0;
	while (str[i] && avcheck(str[i]) == 0)
		i++;
	b = i;
	while (str[i] && avcheck(str[i]) == 1)
		i++;
	while (str[i] && avcheck(str[i]) == 0)
		i++;
	if (str[i])
		write(1, " ", 1);
	while (str[b] && avcheck(str[b]) == 1)
	{
		write(1, &(str[b]), 1);
		b++;
	}
}

int		main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i] && avcheck(argv[1][i]) == 0)
		i++;
	while (argv[1][i] && avcheck(argv[1][i]) == 1)
		i++;
	while (argv[1][i])
	{
		while (argv[1][i] && avcheck(argv[1][i]) == 0)
			i++;
		while (argv[1][i] && avcheck(argv[1][i]) == 1)
		{
			write(1, &(argv[1][i]), 1);
			i++;
		}
		if (argv[1][i] && avcheck(argv[1][i]) == 0)
		{
			write(1, " ", 1);
			while (argv[1][i] && avcheck(argv[1][i]) == 0)
				i++;
		}
	}
	put_firstword(argv[1]);
	write(1, "\n", 1);
	return (0);
}
