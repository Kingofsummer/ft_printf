#include "ft_printf.h"

void	ft_putstr1(const char *s,t_struct *list)
{
	int		i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);

}
