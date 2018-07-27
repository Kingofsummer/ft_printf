#include "ft_printf.h"

t_struct *ft_pars_all(const char **format, t_struct *list)
{	
			ft_parse_flag(format, list);
			ft_parse_width(format, list);
			ft_parse_precision(format, list);
			ft_parse_length(format, list);
			ft_parse_type(format, list);
		
		//printf("list->type %c", list->type);
	return(list);
}

const char *ft_print_text(const char **format, t_struct *list)
{
	while (**format )
	{
		if (**format != '%' && **format)
		{
			write(1, *format, 1);
			(*format)++;
			list->i++;
		}
		if(**format == '%' && *(*format + 1) == '%')
		{
			write(1, *format , 1);
			list->i++;
			if(*(*format + 2) != '\0')
				((*format)) += 2;
			else
				return((*format) += 2);
		}
		if(**format  == '%' && *(*format + 1) != '%')
			return((*format) += 1);
	}	
	if(**format)
		return(*(format) += 1);
	return(*format);
}

const char *ft_parse_flag(const char **format, t_struct *list)
{
	while (**format)
	{	
		if (**format == '-')
			list->minus = 1;
		else if (**format == ' ')
			list->space = 1;
		else if (**format == '+')
			list->plus = 1;
		else if (**format == '#')
			list->hesh = 1;
		else if (**format == '0')
			list->zero = 1;
		else
			return (*format);
		(*format)++;
	}
		return (*format);
	
}

const char *ft_parse_width(const char **format , t_struct *list)
{
		if (**format >= '0' && **format <= '9')
		{
			while (**format >= '0' && **format <= '9' && **format != '.')
			{
				list->width = list->width * 10 + **(format) - '0';
				(*format)++;
			}
		}
		return (*format);
	
}
const char *ft_parse_precision(const char **format, t_struct *list)
{
	list->precision = 0;
		 if (**format == '.')
		 {
			list->dot = 1;
			while (*(*format + 1) >= '0' && *(*format + 1) <= '9')
			{
				list->precision = list->precision * 10 + *(*format + 1) - '0';
				(*format)++;
			}
			return (*format += 1);
		 }
	
	return (*format);
}
 
const char *ft_parse_type(const char **format, t_struct *list)
{
	if (ft_strchr("cCxXuUoOidDpsS%", *(*format)))
	{
		list->type = *(*format);
		(*format)++;
	}
	
	 else if(list->width != 0 && !ft_strchr("cCxXuUoOidDpsS%", *(*format)))
	{
		list->type = **format;
		 ft_process_else( list);
	 	return(*format += 1);
	}
	else if(!ft_strchr("cCxXuUoOidDpsS%", *(*format)))
		list->type = **format;
	
	return (*format);
}
