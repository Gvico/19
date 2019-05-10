/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:20:44 by gvico             #+#    #+#             */
/*   Updated: 2019/05/10 10:51:49 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_etro
{
	char	**val;
	int		width;
	int		height;
	char	num;
}				t_etro;

int				check_connections(char *str);
int				check_tetro(char *str);
t_etro			*read_file(int fd);

void			free_tetro(t_etro *tetro);
t_etro			*new_tetro(char **val, int width, int height, char num);

#endif
