#include "ft_printf.h"

void ft_myputstr(char *str, int i, t_struct *list)
{
	//printf("i===%d", list->i);
	while (i-- > 0)
	{
		write(1, str, 1);
		 list->i++;
		str++;
	}
}