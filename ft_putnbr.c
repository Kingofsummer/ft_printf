/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:05:51 by afedoren          #+#    #+#             */
/*   Updated: 2018/07/29 14:32:37 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int i, t_struct *list)
{
	char			p;
	intmax_t		z;

	z = i;
	if (i < 0)
		z = -z;
	if (z >= 10 || z <= -10)
	{
		ft_putnbr(z / 10, list);
		ft_putnbr(z % 10, list);
	}
	else
	{
		p = z + 48;
		write(1, &p, 1);
		list->i++;
	}
}
