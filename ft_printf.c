#include "ft_printf.h"

int ft_printf( const char *format, ... )
{
	va_list		arg;
	t_struct	*list;

	
	list = (t_struct*)malloc(sizeof(t_struct));
	ft_make_zero_struct(list);
	va_start(arg, format);
	while (*format)
	 {
		ft_print_text(&format, list);
	
		ft_pars_all(&format, list);
		 //printf("s--- %s\n", format);
		 if (list->type == '\0')
		{
			// printf("tyt");
			break;
		}
		
	//  printf("2list->type %c\n", list->type);
		ft_processing(arg, list, &format);
	}

	//printf("adadasa%d", list->i);
	//printf("%s\n", ft_myitoa_base((va_arg(arg, int)) , 10, list));
	//ft_make_zero_struct(list);
	// printf("-------------Struct---------\n");
	// printf("%d\n",list->plus);
	// printf("%d\n",list->minus);
	// printf("%d\n",list->zero);
	// printf("%d\n",list->space);
	// printf("%d\n",list->hesh);
	// printf("%d\n",list->width);
	// printf("%d\n",list->precision);
	// printf("%d\n",list->len_size);
	// printf("%c\n", list->type);
	// printf("%d\n", list->i);
	free(list);
	va_end(arg);
	
	
	

		
	return(list->i);
}
