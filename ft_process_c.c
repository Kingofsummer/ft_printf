#include "ft_printf.h"

void ft_process_c (va_list arg, t_struct *list)
{
    char c;
    char chr;
    int width;
    
    //printf("tyt");
    width = list->width;
    c = (unsigned long)va_arg(arg, long);
    if (list->zero && list->width)
        chr = '0';
    else
        chr = ' ';
    if (list->minus)
    {
        write(1,&c, 1);
        while (width-- > 1)
            write(1, &chr, 1);
    }
    if (list->minus == 0)
    {
        while (width-- > 1)
            write(1, &chr, 1);
        write(1,&c, 1);
    }
    list->i = (list->width > 0) ? (list->i = list->i + list->width) : (list->i + 1);
   // printf("list->i%d", list->i);
}
