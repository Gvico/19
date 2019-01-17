/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:03:24 by gvico             #+#    #+#             */
/*   Updated: 2019/01/17 08:57:03 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"

# define BUFF_SIZE 32
# define MEMCHK(x) if (!x) return (-1);

int	get_next_line(const int fd, char **line);

#endif
