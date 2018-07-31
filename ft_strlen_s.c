/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:33:22 by afedoren          #+#    #+#             */
/*   Updated: 2018/07/29 14:33:23 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_s(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
