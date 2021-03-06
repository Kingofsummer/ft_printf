/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:30:46 by afedoren          #+#    #+#             */
/*   Updated: 2018/07/29 14:30:49 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_s(va_list arg, t_struct *list)
{
	int		len_str;
	char	*str;

	str = va_arg(arg, char*);
	if (list->dot && !list->precision)
	{
		(list->zero) ? ft_myputchar(list->width, '0', list)
		: ft_myputchar(list->width, ' ', list);
		return ;
	}
	if (!list->precision)
		len_str = ft_strlen(str, list);
	if (!str)
	{
		write(1, "(null)", 6);
		list->i += 6;
		return ;
	}
	if (len_str == 0)
	{
		ft_print_width_s(str, list);
		return ;
	}
	(list->minus) ? ft_minuss(str, list) : ft_nminuss(str, list);
}

void	ft_minuss(char *str, t_struct *list)
{
	if (list->precision)
		ft_print_precision_s(str, list);
	else
		ft_putstr1(str);
	ft_print_width_s(str, list);
}

void	ft_nminuss(char *str, t_struct *list)
{
	if (list->width)
		ft_print_width_s(str, list);
	if (list->precision)
		ft_print_precision_s(str, list);
	else
		ft_putstr1(str);
}

void	ft_print_width_s(char *str, t_struct *list)
{
	int		len_str;

	len_str = ft_strlen_s(str);
	if (list->width && list->precision > len_str && len_str != 0)
	{
		list->width = list->width - len_str;
		ft_myputchar(list->width, ' ', list);
	}
	else if (list->precision < len_str && list->precision != 0)
		ft_myputchar(list->width - list->precision, ' ', list);
	else if (list->zero)
		ft_myputchar(list->width - len_str, '0', list);
	else
		ft_myputchar(list->width - len_str, ' ', list);
}

void	ft_print_precision_s(char *str, t_struct *list)
{
	int		len_str;

	len_str = ft_strlen_s(str);
	if (list->precision > len_str)
		list->precision = len_str;
	ft_myputstr(str, list->precision, list);
}
