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
