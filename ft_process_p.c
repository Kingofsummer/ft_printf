#include "ft_printf.h"
void ft_process_p (va_list arg, t_struct *list)
{
    unsigned long i;
    char *num_p;
    int len ;
    
    i = va_arg(arg, unsigned long);
    num_p = ft_myitoa_base(i , 16, list);
    len = ft_strlen_s(num_p);

    if(list->width && list->precision)
        list->width = list->width - len - list->precision;
    else
        list->width = list->width - len - list->precision - 2;
           if(i == 0)
			{
				if(list->dot && list->precision == 0)
				{
                    write(1, "0x", 2);
                    list->i += 2; 
					ft_myputchar(list->width, ' ', list);
					return;
				}
			}
    ft_print_p(i , num_p, list, len);
    free(num_p);
}
void ft_print_p(intmax_t i , char *num_p, t_struct *list, int len)
{
    if(list->minus == 0 && !list->zero)
    {
    
       ft_myputchar(list->width, ' ', list);
        write(1, "0x", 2);
            list->i += 2;
        ft_myputchar(list->precision - len, '0', list);
        ft_print_arg(num_p, list);
    }
    if(list->minus)
    {
        write(1, "0x", 2);
            list->i += 2;  
            ft_myputchar(list->precision - len, '0', list);
         ft_print_arg(num_p, list);
        ft_myputchar(list->width, ' ', list);
    }
    if(list->zero)
    {
        write(1, "0x", 2);
            list->i += 2; 
        ft_print_arg(num_p, list);
        ft_myputchar(list->width - len +1, '0', list);
    }
}