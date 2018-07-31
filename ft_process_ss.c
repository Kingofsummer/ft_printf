/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_ss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:31:04 by afedoren          #+#    #+#             */
/*   Updated: 2018/07/29 14:31:05 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_ss(va_list arg, t_struct *list)
{
	wchar_t		*str;
	int			len_bytes;

	str = va_arg(arg, wchar_t *);
	if (list->dot && !list->precision)
	{
		(list->zero) ? ft_myputchar(list->width, '0', list)
		: ft_myputchar(list->width, ' ', list);
		return ;
	}
	if (!str)
	{
		write(1, "(null)", 6);
		list->i += 6;
		return ;
	}
	len_bytes = ft_wstrlen(str);
	if (list->minus == 0)
		ft_minusss(str, list);
	if (list->minus)
	{
		ft_putstr_vova(str, list);
		ft_print_width_ss(str, list);
	}
}

void	ft_minusss(wchar_t *str, t_struct *list)
{
	ft_print_width_ss(str, list);
	if (list->precision == 0)
		ft_putstr_vova(str, list);
	else
		ft_wstrlen_prec(str, list);
}

void	ft_print_width_ss(wchar_t *str, t_struct *list)
{
	int		len_str;

	len_str = ft_wstrlen(str);
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

void	ft_putstr_vova(wchar_t *s, t_struct *list)
{
	int	i;

	i = -1;
	if (!s)
		return ;
	while (s[++i])
	{
		ft_put_wchar(s[i], ft_count_bytes(s[i]), list);
	}
}

int		ft_wstrlen_prec(wchar_t *num, t_struct *list)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!num)
		return (len);
	while (num[i])
	{
		len += ft_count_bytes(num[i]);
		if (list->precision >= len)
		{
			ft_put_wchar(num[i], ft_count_bytes(num[i]), list);
		}
		else
			break ;
		i++;
	}
	return (len);
}
