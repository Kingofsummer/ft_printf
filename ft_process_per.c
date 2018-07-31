/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_per.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:30:36 by afedoren          #+#    #+#             */
/*   Updated: 2018/07/29 14:30:38 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_per(t_struct *list)
{
	if (list->minus)
	{
		ft_myputchar(1, '%', list);
		ft_myputchar((list->width - 1), ' ', list);
	}
	if (!list->minus)
	{
		if (list->zero)
			ft_myputchar((list->width - 1), '0', list);
		else
			ft_myputchar((list->width - 1), ' ', list);
		ft_myputchar(1, '%', list);
	}
}
