#include "ft_printf.h"

void ft_process_u (va_list arg, t_struct *list)
{   
    intmax_t i;
    char *num_d;
    
    i = ft_cast_u(list, arg);
    num_d = ft_myitoa_unsigned(i , 10);
    if(i == 0)
			{
				if(list->dot && list->precision == 0)
				{
					ft_myputchar(list->width, ' ', list);
					list->width = 0;
					return;
				}
			}
    if(list->width <= list->precision)
			list->width = 0;
    if (list->minus)
    {
        ft_print_precision(i , list);
        ft_putstr(num_d, list);
        ft_print_width(i, list);
    }
    if (list->minus == 0)
    {
        ft_print_width(i, list);
        ft_print_precision(i , list);
        ft_putstr(num_d, list);
    }
    free(num_d);
}