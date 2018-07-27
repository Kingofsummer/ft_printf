#include "ft_printf.h"

const char *ft_parse_length(const char **format , t_struct *list)
{
	
	ft_parse_ll_hh(format, list);
	
	ft_parse_l_h(format, list);

	ft_parse_j_z(format, list);
	return (*format);
}

void ft_parse_ll_hh(const char **format, t_struct *list)
{
	if (**format == 'l' && *(*format + 1) == 'l' )
	{
		list->len_size = ll;
		*format = (*format + 2);
	}
	else if (**format == 'h' && *(*format + 1) == 'h' )
	{
		list->len_size = hh;
		*format = (*format + 2);
	}
} 
void ft_parse_l_h(const char **format, t_struct *list)
{
	if (**format == 'l')
	{
		list->len_size = l;
		*format = (*format + 1);
	}
	else if (**format == 'h')
	{
		list->len_size = h;
		*format = (*format + 1);
	}
} 
void ft_parse_j_z(const char **format, t_struct *list)
{
	if (**format == 'j')
	{
		list->len_size = j;
		*format = (*format + 1);
	}
	else if (**format == 'z')
	{
		list->len_size = z;
		*format = (*format + 1);
	}

}