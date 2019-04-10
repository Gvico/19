/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:25:03 by gvico             #+#    #+#             */
/*   Updated: 2018/09/18 12:50:21 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		//ft_putstr_fd("usage: fillit input_file\n", 2);
		write(2, "usage: fillit input_file\n", 25);
		return (1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		write(2, "Open error!\n", 12);
		return (1);
	}
	return (0);
}
