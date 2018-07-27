#include "ft_printf.h"

void ft_process_per (t_struct *list)
{

   if (list->minus)
   {
        ft_myputchar(1, '%', list);
        ft_myputchar((list->width - 1), ' ', list);
   }
   if (!list->minus)
   {
       if(list->zero)
            ft_myputchar((list->width - 1), '0', list);
        else
            ft_myputchar((list->width - 1), ' ', list);
        ft_myputchar(1, '%', list);
   }
}