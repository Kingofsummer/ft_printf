/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:28:40 by afedoren          #+#    #+#             */
/*   Updated: 2018/07/29 14:28:43 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	t_struct	*list;

	list = (t_struct*)malloc(sizeof(t_struct));
	ft_make_zero_struct(list);
	va_start(arg, format);
	while (*format)
	{
		ft_print_text(&format, list);
		ft_pars_all(&format, list);
		if (list->type == '\0')
		{
			break ;
		}
		ft_processing(arg, list);
		list->width = 0;
	}
	free(list);
	va_end(arg);
	return (list->i);
}
