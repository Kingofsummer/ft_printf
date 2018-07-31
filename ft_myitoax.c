/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_itoa_baseX.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:26:16 by afedoren          #+#    #+#             */
/*   Updated: 2018/07/29 14:26:18 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			f1(uintmax_t value, uintmax_t base, char *str, int *i)
{
	char		*tmp;

	tmp = "0123456789ABCDEF";
	if (value >= base)
		f1(value / base, base, str, i);
	str[(*i)++] = tmp[(value % base)];
}

char			*ft_myitoax(uintmax_t value, uintmax_t base)
{
	int			i;
	char		*str;

	i = 0;
	if (!(str = (char*)malloc(32)))
		return (NULL);
	if (base > 16 || base < 2)
		return (0);
	f1(value, base, str, &i);
	str[i] = '\0';
	return (str);
}
