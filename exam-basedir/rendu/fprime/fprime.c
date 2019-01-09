/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:24:00 by exam              #+#    #+#             */
/*   Updated: 2019/01/09 10:36:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;
	int	nbr;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	nbr = atoi(argv[1]);
	if (nbr == 1)
	{
		printf("1\n");
		return (0);
	}
	while (nbr > 1)
	{
		i = 2;
		while (nbr % i != 0)
			i++;
		nbr /= i;
		printf("%d", i);
		if (nbr > 1)
			printf("*");
	}
	printf("\n");
	return (0);
}
