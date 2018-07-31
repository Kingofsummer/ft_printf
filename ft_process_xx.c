/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_xx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:31:56 by afedoren          #+#    #+#             */
/*   Updated: 2018/07/29 14:31:58 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_xx(va_list arg, t_struct *list)
{
	intmax_t	i;
	char		*num_x;

	i = ft_cast_x(list, arg);
	num_x = ft_myitoax(i, 16);
	if (i == 0)
	{
		if (list->dot && !list->precision)
		{
			ft_myputchar(list->width, ' ', list);
			list->width = 0;
			return ;
		}
	}
	if (list->zero && list->minus)
		list->zero = 0;
	if (list->width <= list->precision)
		list->width = 0;
	ft_print_xx(i, num_x, list);
	free(num_x);
}

void	ft_print_xx(intmax_t i, char *num_x, t_struct *list)
{
	if (list->minus)
	{
		if (list->hesh)
			ft_print_ox(list);
		ft_print_precision_x(i, list);
		ft_putstr(num_x, list);
		ft_print_width_x(i, list);
	}
	else if (list->minus == 0)
	{
		if (list->hesh && list->zero && i != 0)
			ft_print_ox(list);
		ft_print_width_x(i, list);
		ft_print_precision_x(i, list);
		if (list->hesh && !list->zero && i != 0)
			ft_print_ox(list);
		ft_putstr(num_x, list);
	}
}

void	ft_print_width_xx(intmax_t i, t_struct *list)
{
	int		len_num;

	len_num = ft_len_num_minus(i, 16);
	if (list->precision > 0 && list->precision > len_num &&
	list->width > list->precision)
		list->width -= list->precision - len_num;
	if (list->zero && list->precision == 0)
		ft_myputchar(list->width - len_num, '0', list);
	else if (list->hesh && list->zero)
		ft_myputchar(list->width - (len_num + 2), '0', list);
	else if (list->hesh && !list->zero)
		ft_myputchar(list->width - (len_num + 2), ' ', list);
	else if (list->plus)
		ft_myputchar(list->width - (len_num + 1), ' ', list);
	else
		ft_myputchar(list->width - len_num, ' ', list);
}

void	ft_print_precision_xx(intmax_t i, t_struct *list)
{
	int len_num;

	len_num = ft_len_num_minus(i, 16);
	if (list->precision)
		ft_myputchar(list->precision - len_num, '0', list);
}

void	ft_print_ox(t_struct *list)
{
	write(1, "0X", 2);
	list->i += 2;
}
