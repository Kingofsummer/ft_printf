#include "ft_printf.h"

void ft_make_zero_struct(t_struct *list)
{
	list->plus = 0;
	list->minus = 0;
	list->zero = 0;
	list->space  = 0;
	list->hesh = 0;
	list->width = 0;
	list->precision = -1;
	list->len_size = 0;
	list->type = '\0';
	list->neg = 0;
	list->i = 0;
	list->dot = 0;
	list->onebyte = 0;
}