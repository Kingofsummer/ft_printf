#include "ft_printf.h"

void ft_process_cc(va_list arg, t_struct *list)
{
    wchar_t i;
    int len_bytes;
    i = va_arg(arg, wchar_t);
    len_bytes = ft_count_bytes(i);
    ft_put_wchar(i, len_bytes, list);
        
    //printf("%d", list->i);
}
int ft_count_bytes(wchar_t i)
{
    if (i <= 127)
        return (1);
    else if (i <= 2047)
        return (2);
    else if (i <= 65535)
        return (3);
    else
        return (4);
}
void     ft_put_wchar(wchar_t c, int len_bytes, t_struct * list)
{
    if (len_bytes == 1 || MB_CUR_MAX  == 1)
    {
        ft_putchar(c);
        list->i++;
    }
    else if (len_bytes == 2 )
    {
        ft_putchar((c >> 6) | 0xC0);
        ft_putchar((c & 0x3F) | 0x80);
        list->i += 2;
    }
    else if (len_bytes == 3)
    {
        ft_putchar((c >> 12) | 0xE0);
        ft_putchar(((c >> 6) & 0x3F) | 0x80);
        ft_putchar((c & 0x3F) | 0x80);
        list->i += 3;
    }
    else if (len_bytes == 4)
    {
        ft_putchar((c >> 18) | 0xF0);
        ft_putchar(((c >> 12) & 0x3F) | 0x80);
        ft_putchar(((c >> 6) & 0x3F) | 0x80);
        ft_putchar((c & 0x3F) | 0x80);
        list->i += 4;
    }
}