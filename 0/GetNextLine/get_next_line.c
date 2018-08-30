/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:03:18 by gvico             #+#    #+#             */
/*   Updated: 2018/08/14 12:30:11 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static int	cur = 0;
	static char *rest = (char *)malloc(BUFF_SIZE);
}
