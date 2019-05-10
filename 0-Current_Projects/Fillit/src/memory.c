/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:41:02 by gvico             #+#    #+#             */
/*   Updated: 2019/05/10 10:49:35 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	free_tetro(t_etro *tetro)
{
	int	i;

	i = 0;
	while (i < tetro->height)
	{
		ft_memdel((void **)&(tetro->val[i]));
		i++;
	}
	ft_memdel((void **)&(tetro->val));
	ft_memdel((void **)&tetro);
}

t_etro	*new_tetro(char **val, int width, int height, char num)
{
	t_etro	*new;

	new = ft_memalloc(sizeof(t_etro));
	new->val = val;
	new->width = width;
	new->height = height;
	new->num = num;
	return (new);
}
