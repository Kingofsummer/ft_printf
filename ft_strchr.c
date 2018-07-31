/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:04:11 by afedoren          #+#    #+#             */
/*   Updated: 2018/07/29 14:33:03 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char tmp;

	tmp = ((char)c);
	while (*s != tmp && *s)
	{
		s++;
	}
	if (*s != tmp)
		return (NULL);
	return ((char*)s);
}
