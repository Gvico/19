/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvico <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:05:21 by gvico             #+#    #+#             */
/*   Updated: 2018/06/13 09:45:52 by gvico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;

	i = nb - 1;
	if (nb > 0 && nb < 13)
	{
		while (i > 1)
		{
			nb *= i;
			i--;
		}
		return (nb);
	}
	else if (nb == 0)
		return (1);
	else
		return (0);
}
