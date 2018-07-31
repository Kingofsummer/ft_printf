/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:31:14 by afedoren          #+#    #+#             */
/*   Updated: 2018/07/29 14:31:17 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_u(va_list arg, t_struct *list)
{
	intmax_t	i;
	char		*num_d;

	i = ft_cast_u(list, arg);
	num_d = ft_myitoa_unsigned(i, 10);
	if (i == 0 && list->dot && list->precision == 0)
	{
		ft_checkzerou(list);
		return ;
	}
	if (list->width <= list->precision)
		list->width = 0;
	if (list->minus)
	{
		ft_print_precision(i, list);
		ft_putstr(num_d, list);
		ft_print_width(i, list);
	}
	if (list->minus == 0)
	{
		ft_print_width(i, list);
		ft_print_precision(i, list);
		ft_putstr(num_d, list);
	}
	free(num_d);
}

void	ft_checkzerou(t_struct *list)
{
	if (list->dot && list->precision == 0)
	{
		ft_myputchar(list->width, ' ', list);
		list->width = 0;
		return ;
	}
}
