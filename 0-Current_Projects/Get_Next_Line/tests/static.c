/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:04:37 by gvico             #+#    #+#             */
/*   Updated: 2019/01/17 13:04:50 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
**		Test file
*/

char	test(void)
{
	static char	test[8];

	if (!test[3])
		test[3] = '0';
	else
		test[3]++;
	return (test[3]);
}

int		main(void)
{
	char	buf;

	buf = 'X';
	while (buf != '9')
	{
		buf = test();
		write(1, &buf, 1);
	}
	return (0);
}
