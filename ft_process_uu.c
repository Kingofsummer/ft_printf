/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_uu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:31:23 by afedoren          #+#    #+#             */
/*   Updated: 2018/07/29 14:31:27 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_uu(va_list arg, t_struct *list)
{
	intmax_t	i;
	char		*num_d;

	i = (unsigned long)va_arg(arg, long);
	num_d = ft_myitoa_unsigned(i, 10);
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
