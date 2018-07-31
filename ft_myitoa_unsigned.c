/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myitoa_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:27:10 by afedoren          #+#    #+#             */
/*   Updated: 2018/07/29 14:27:12 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	length(uintmax_t value, uintmax_t base)
{
	int	i;

	i = 0;
	while (value >= base)
	{
		value /= base;
		i++;
	}
	return (i + 1);
}

char			*ft_myitoa_unsigned(uintmax_t value, uintmax_t base)
{
	char	*nbr;
	int		l;

	l = length(value, base);
	if (!(nbr = (char*)(malloc(sizeof(nbr) * (l)))))
		return (NULL);
	nbr[l] = '\0';
	while (l--)
	{
		nbr[l] = (value % base) + (value % base > 9 ? 'a' - 10 : '0');
		value /= base;
	}
	return (nbr);
}
