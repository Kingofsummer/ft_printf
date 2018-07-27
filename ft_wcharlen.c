#include "ft_printf.h"
int ft_wcharlen(wchar_t *num)
{
	int i;
	i = 0;
	while(num[i])
		i++;
	return(i);
}
