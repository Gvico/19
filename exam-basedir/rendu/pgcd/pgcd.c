/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:29:21 by gvico             #+#    #+#             */
/*   Updated: 2018/10/16 13:45:56 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int n1;
	int n2;
	int pgcd;

	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	n1 = atoi(argv[1]);
	n2 = atoi(argv[2]);
	if (n1 >= n2)
		pgcd = n1;
	else
		pgcd = n2;
	while (!(n1 % pgcd == 0 && n2 % pgcd == 0))
		pgcd--;
	printf("%d\n", pgcd);
}
