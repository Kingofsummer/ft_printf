/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:31:50 by afedoren          #+#    #+#             */
/*   Updated: 2018/07/30 15:31:52 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_print_text(const char **format, t_struct *list)
{
	while (**format)
	{
		if (**format != '%' && **format)
		{
			write(1, *format, 1);
			(*format)++;
			list->i++;
		}
		if (**format == '%' && *(*format + 1) == '%')
		{
			write(1, *format, 1);
			list->i++;
			if (*(*format + 2) != '\0')
				((*format)) += 2;
			else
				return ((*format) += 2);
		}
		if (**format == '%' && *(*format + 1) != '%')
			return ((*format) += 1);
	}
	if (**format)
		return (*(format) += 1);
	return (*format);
}

void		ft_checkzerod(t_struct *list, intmax_t i)
{
	if (i == 0)
	{
		if (list->dot && list->precision == 0)
		{
			ft_myputchar(list->width, ' ', list);
			list->width = 0;
			return ;
		}
	}
}

void		ft_checkspace(t_struct *list)
{
	if (list->space && list->zero && list->width)
	{
		write(1, " ", 1);
		list->width--;
		list->i++;
	}
}

int			ft_wstrlen(wchar_t *num)
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
		i++;
	}
	return (len);
}
