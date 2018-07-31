/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:36:22 by afedoren          #+#    #+#             */
/*   Updated: 2018/07/30 15:36:23 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_len_num(size_t numb, int base)
{
	int		i;

	i = 1;
	if (base == 0)
		return (0);
	while (numb / base)
	{
		i++;
		numb /= base;
	}
	return (i);
}

int			ft_len_num_minus(ssize_t numb, int base)
{
	int		i;

	i = 1;
	if (base == 0)
		return (0);
	if (numb < 0)
		i++;
	while (numb / base)
	{
		i++;
		numb /= base;
	}
	return (i);
}
