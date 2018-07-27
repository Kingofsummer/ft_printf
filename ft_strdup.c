/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:40:01 by afedoren          #+#    #+#             */
/*   Updated: 2017/10/31 13:40:02 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*mal;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	mal = (char *)malloc(sizeof(char) * (i + 1));
	if (!mal)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		mal[i] = s1[i];
		i++;
	}
	mal[i] = '\0';
	return (mal);
}
