/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:20:44 by gvico             #+#    #+#             */
/*   Updated: 2019/05/08 09:54:27 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

int				check_connections(char *str);
int				check_tetro(char *str);
int				read_file(int fd);

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_etro
{
	char	*str;
	int		width;
	int		height;
	char	val;
}				t_etro;

#endif
