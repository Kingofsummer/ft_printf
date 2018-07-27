#include "ft_printf.h"

void ft_processing(va_list arg, t_struct *list, const char **format)
{
  
     //printf("%s", *format);
     
	if(list->type == 'd' || list->type == 'i')
    {
        
		ft_process_d(arg, list);  
    }
    else if(list->type == 's' && list->len_size != l)
        ft_process_s(arg, list);

    else if (list->type == 'u')
        ft_process_u(arg,list);
    else if(list->type == 'U')
        ft_process_uu(arg, list);
    else if(list->type == 'x')
        ft_process_x(arg,list);
    else if(list->type == 'X')
        ft_process_xx(arg,list);
    else if(list->type == 'o' )
        ft_process_o(arg,list);
    else if(list->type == '%')
        ft_process_per(list);
    else if(list->type == 'p')
        ft_process_p(arg, list);
    else if(list->type == 'O')
        ft_process_oo(arg,list);
    else if(list->type == 'D')
        ft_process_dd(arg, list);
    else if(list->type == 'C' || (list->type == 'c' && list->len_size == l ))
        ft_process_cc(arg, list);
    else if(list->type == 'S' ||(list->type == 's' && list->len_size == l))
        ft_process_ss(arg, list);
    else if ((list->type == 'c' && list->len_size != l) )
    {
        ft_process_c(arg,list);
    } 
}

	
intmax_t ft_cast_x (t_struct * list, va_list arg)
{
    if(list->len_size == h)
        return ((unsigned int)va_arg(arg, int));
    if (list->len_size == l)
        return ((unsigned long)va_arg(arg, long));
    if (list->len_size == hh)
        return ((unsigned char)va_arg(arg, int));
    if (list->len_size == j)
        return ((intmax_t)va_arg(arg,intmax_t));
    if (list->len_size == ll)
        return ((unsigned long long)va_arg(arg, long long));
    if (list->len_size == z)
        return (va_arg(arg, size_t));
    return ((unsigned int)va_arg(arg, int));
}

intmax_t ft_cast_d (t_struct *list,  va_list arg)
{
	if (list->len_size == j)
		return ((intmax_t)va_arg(arg, intmax_t));
	if (list->len_size == ll)
		return (va_arg(arg, long long));
	if (list->len_size == l)
		return ((long) va_arg(arg, long));
	if (list->len_size == h)
		return ((short) va_arg(arg, int));
	if (list->len_size == hh)
		return ((signed char) va_arg(arg, int));
    if (list->len_size == z)
        return ((ptrdiff_t)va_arg(arg, size_t));
    
    
	return (va_arg(arg, int));
   
}
intmax_t ft_cast_o(t_struct * list, va_list arg)
{
    if (list->len_size == h)
        return ((unsigned short)va_arg(arg, int));
    if (list->len_size == l)
        return ((unsigned long)va_arg(arg, long));
    if (list->len_size == hh)
        return ((unsigned char)va_arg(arg, int));
    if (list->len_size == j)
        return ((uintmax_t)va_arg(arg, intmax_t));
    if (list->len_size == ll)
        return ((unsigned long long)va_arg(arg, long long));
    if (list->len_size == z)
        return (va_arg(arg, size_t));
    return((unsigned int)va_arg(arg, int));
    
}
intmax_t ft_cast_u (t_struct * list, va_list arg)
{
    if (list->len_size == h)
        return ((unsigned short)va_arg(arg, int));
    if (list->len_size == l)
        return ((unsigned long)va_arg(arg, long));
    if (list->len_size == hh)
        return ((unsigned char)va_arg(arg, int));
    if (list->len_size == j)
        return ((uintmax_t)va_arg(arg, intmax_t));
    if (list->len_size == ll)
        return ((unsigned long long)va_arg(arg,long long));
    if (list->len_size == z)
        return (va_arg(arg, size_t));
    return((unsigned int)va_arg(arg, int));
        //t треба опрацювати та z
}

int ft_len_num(size_t numb, int base)
{
    int i;
    i = 1;
    if(base == 0)
        return(0);

    while(numb / base)
    {
        i++;
        numb /= base;
    }
    return(i);
} 
int ft_len_num_minus(ssize_t numb, int base)
{
  int i;
    i = 1;
    if(base == 0)
        return(0);
	if(numb < 0)
		i++;
    while(numb / base)
    {
        i++;
        numb /= base;
    }
    //printf("%d", i );
    return(i);
} 