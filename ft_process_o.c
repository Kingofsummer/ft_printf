#include "ft_printf.h"

void ft_process_o (va_list arg, t_struct *list)
{
    uintmax_t i;
    i = ft_cast_o(list, arg);
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
    free(num_o);
}
void ft_print_o(intmax_t i , char *num_o, t_struct *list)
{
    if(list->minus)
    {
          if(list->hesh)
            ft_myputchar(1, '0', list);
        ft_print_precision_o(i , list);
        ft_print_arg_o(num_o, list);
        ft_print_width_o(i, list);
    }
    else if(list->minus ==0)
    {
        if( list->zero && list->precision == 0 && list->neg)
				ft_myputchar(1, '-', list);
        ft_print_width_o(i, list);
        ft_print_precision_o(i , list);
        if(list->hesh && !list->precision)
            ft_myputchar(1, '0', list);
        ft_print_arg_o(num_o, list);
    }
}
void ft_print_arg_o(char *num_o, t_struct *list)
{
	ft_putstr(num_o,list);
}
void ft_print_width_o(intmax_t i, t_struct *list)
{
    int len_num;

	len_num = ft_len_num_minus(i , 8);
    
    if (list->precision > 0 && list->precision > len_num && list->width > list->precision)
			list->width -= list->precision - len_num;
    if(i == 0)
        ft_myputchar(list->width, ' ', list);
    else if(list->zero)
        ft_myputchar(list->width - len_num, '0', list);
    else if(list->hesh && list->width)
        ft_myputchar(list->width - (len_num + 1), ' ', list);
    else
        ft_myputchar(list->width - len_num, ' ', list);
}
void ft_print_precision_o (intmax_t i, t_struct *list)
{
    int len_num;
		len_num = ft_len_num_minus(i , 8);
    if(list->precision)
       ft_myputchar(list->precision - len_num, '0', list); 
}