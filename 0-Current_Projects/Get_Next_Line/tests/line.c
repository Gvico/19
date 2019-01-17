/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:04:08 by gvico             #+#    #+#             */
/*   Updated: 2019/01/17 13:04:23 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/*
**		Test file
*/

void	test(char **line)
{
	char	*ptr;

	ptr = *line;
	(*line)[2] = 'V';
	ptr[2] = 'G';
}

int		main(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 6);
	test(&str);
	write(1, &(str[2]), 1);
	write(1, "\n", 1);
	return (0);
}
