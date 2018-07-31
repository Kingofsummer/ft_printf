/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:26:39 by afedoren          #+#    #+#             */
/*   Updated: 2018/07/29 14:26:41 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	len(intmax_t value, int base)
{
	int	i;

	i = 0;
	while (value >= base)
	{
		value = value / base;
		i++;
	}
	return (i + 1);
}

char			*ft_myitoa_base(intmax_t value, int base, t_struct *list)
{
	char		*nbr;
	size_t		size;

	if (value == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	if (value < 0 && base == 10)
	{
		list->neg = 1;
		value *= -1;
	}
	size = len(value, base);
	if (!(nbr = (char*)malloc(sizeof(nbr) * size)))
		return (NULL);
	nbr[size] = '\0';
	while (size--)
	{
		nbr[size] = (value % base) + (value % base > 9 ? 'a' - 10 : '0');
		value /= base;
	}
	return (nbr);
}
