#include "ft_printf.h"

void ft_myputchar(int i, char c, t_struct *list)
{
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
		list->i++;
	}
}