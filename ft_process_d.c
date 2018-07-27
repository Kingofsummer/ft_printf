#include "ft_printf.h"

void ft_process_d (va_list arg, t_struct *list)
	{
		intmax_t i;
		int len_num;
		char *num_d;
		int len_width;
		
		i = ft_cast_d(list, arg);
		
	 		num_d = ft_myitoa_base(i, 10, list);
			if (i == 0)
			{
				if (list->dot && list->precision == 0)
				{
					ft_myputchar(list->width, ' ', list);
					list->width = 0;
					return;
				}
			}
		if (list->space && list->zero && list->width)
		{
			write(1, " ", 1);
			list->width--;
			list->i++;
		}
		if (list->width <= list->precision)
			list->width = 0;
		if (list->zero && list->minus)
			list->zero = 0;
		if (list->space == 1 && list->width <= 0 && i >= 0 && list->plus == 0)
			ft_myputchar(1, ' ', list);
		ft_print_d(i, num_d,  list);
		free(num_d);
		list->neg = 0;
	}

	void ft_print_d(intmax_t i , char *num_d, t_struct *list)
	{
		if (list->minus)
		{
			if (list->neg)
				ft_myputchar(1, '-', list);
			if (list->plus && list->minus)
				ft_myputchar(1, '+', list);
			ft_print_precision(i, list);
			ft_print_arg(num_d, list);
			ft_print_width(i, list);
		}
		else if (list->minus == 0)
		{
			if (list->neg && list->zero && list->precision == 0)
				ft_myputchar(1, '-', list);
			if (list->plus && i >= 0 && list->precision == 0 )
			{
				list->width--;
				ft_myputchar(1, '+', list);
			}
			ft_print_width(i, list);
			if (list->plus && i > 0 && list->precision && list->width)
				ft_myputchar(1, '+', list);
			if (list->neg && list->precision)
				ft_myputchar(1, '-', list);
			ft_print_precision(i, list);
			if (list->neg && list->zero == 0 && list->precision == 0)
				ft_myputchar(1, '-', list);
			ft_print_arg(num_d, list);
		}
	}

	void ft_print_precision (intmax_t i, t_struct *list)
	{
		int len_num;
		len_num = ft_len_num_minus(i , 10);
		if(list->neg)
			ft_myputchar(list->precision - (len_num - 1), '0', list);
		else
			ft_myputchar(list->precision - len_num, '0', list);
	}

	void ft_print_width(intmax_t i, t_struct *list)
	{
		int len_num;

		len_num = ft_len_num_minus(i , 10);
		if (list->precision > 0 && list->precision > len_num && list->width > list->precision)
		{
			if(list->neg)
				list->width -= list->precision - len_num + 1;
			else
				list->width -= list->precision - len_num;
		}
		if (list->zero && list->precision == 0)
			ft_myputchar(list->width - len_num, '0', list);
		else if (list->plus)
			ft_myputchar(list->width - (len_num + 1), ' ', list);
		else if (list->neg && list->precision && !list->zero)
			ft_myputchar(list->width - (len_num ), ' ', list);
		else if (list->neg && list->precision )
			ft_myputchar(list->width - (len_num + 1), ' ', list);
		else
			ft_myputchar(list->width - len_num, ' ', list);
	}
	void ft_print_arg(char *num_d, t_struct *list)
	{
		ft_putstr(num_d,list);
	}