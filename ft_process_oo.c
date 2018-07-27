#include "ft_printf.h"

void ft_process_oo (va_list arg, t_struct *list)
{
    uintmax_t i;
    i = (unsigned long)va_arg(arg, long);
    char *num_o;
    num_o = ft_myitoa_unsigned(i, 8);
    if(i == 0)
	{
		if(list->dot && list->precision == 0 && !list->hesh)
		{
			ft_myputchar(list->width, ' ', list);
            list->width = 0;
			return;
        }
        else if(list->hesh && i == 0)
        {
                ft_myputchar(1, '0', list);
                return;
        }
	}
    if(list->width <= list->precision)
			list->width = 0;
    if(list->zero && list->minus)
			list->zero = 0;
    ft_print_o(i, num_o, list);
}