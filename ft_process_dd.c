/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_dd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:29:50 by afedoren          #+#    #+#             */
/*   Updated: 2018/07/29 14:29:52 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_dd(va_list arg, t_struct *list)
{
	intmax_t	i;
	char		*num_d;

	i = (unsigned long)va_arg(arg, long);
	num_d = ft_myitoa_base(i, 10, list);
	if (i == 0)
	{
		if (list->dot && list->precision == 0)
		{
			ft_myputchar(list->width, ' ', list);
			list->width = 0;
			return ;
		}
	}
	if (list->width <= list->precision)
		list->width = 0;
	if (list->zero && list->minus)
		list->zero = 0;
	if (list->space == 1 && list->width <= 0 && i > 0 && list->plus == 0)
		ft_myputchar(1, ' ', list);
	(list->minus) ? ft_minusd(i, num_d, list) : ft_nminusd(i, num_d, list);
	free(num_d);
	list->neg = 0;
}
