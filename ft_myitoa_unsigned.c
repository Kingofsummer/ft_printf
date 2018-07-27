#include "ft_printf.h"
static int	length(uintmax_t value, uintmax_t base)
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

char		*ft_myitoa_unsigned(uintmax_t value, uintmax_t base)
{
	char	*nbr;
	int		l;

	l = 0;
	l += length(value, base);
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