#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# include <wchar.h>
# include <locale.h>
# include <stdbool.h>
//#define lst (*list)


typedef enum 			e_len
{
	hh = 1,
	h,
	l,
	ll,
	j,
	z
}						t_len;

typedef struct			s_struct
{
	int					plus;
	int					minus;
	int					zero;
	int					space;
	int					hesh;
	int 				width;
	int					precision;
	t_len				len_size;
	char				type;
	int					neg;
	int					i;
	int					dot;
	int					onebyte;
}						t_struct;

int ft_printf( const char *format, ... );
void ft_make_zero_struct(t_struct *list);
t_struct *ft_pars_all(const char **format, t_struct *list);
const char *ft_print_text(const char **format, t_struct *list);
const char *ft_parse_flag(const char **format, t_struct *list);
const char *ft_parse_width(const char **format , t_struct *list);
const char *ft_parse_precision(const char **format , t_struct *list);
const char *ft_parse_length(const char **format , t_struct *list);
void ft_parse_ll_hh(const char **format, t_struct *list);
void ft_parse_l_h(const char **format, t_struct *list);
void ft_parse_j_z(const char **format, t_struct *list);
const char *ft_parse_type(const char **format, t_struct *list);
void ft_processing(va_list arg, t_struct *list, const char **format);
void ft_process_d (va_list arg, t_struct *list);
intmax_t ft_cast_d (t_struct *list,  va_list arg);
char *ft_myitoa_base(intmax_t i,  int base, t_struct *list);
char	*ft_strchr(const char *s, int c);
void  ft_i_minus(intmax_t i, int base);
size_t	ft_strlen(const char *s, t_struct *list);
void ft_myputchar(int i, char c, t_struct *list);
void	ft_putstr(const char *s,t_struct *list);
void	ft_putnbr(int n, t_struct *list);
void	ft_putchar(char c);
int ft_len_num(size_t numb, int base);
int ft_len_num_minus(ssize_t numb, int base);

void ft_print_precision (intmax_t i, t_struct *list);
void ft_print_arg(char *num_d, t_struct *list);
void ft_print_width(intmax_t i, t_struct *list);
void ft_process_s (va_list arg, t_struct *list);
void	ft_putstr1(const char *s,t_struct *list);
size_t	ft_strlen_s(const char *s);
void ft_print_width_s(char *str, t_struct *list);
void ft_myputstr(char *str, int i, t_struct *list);
void ft_print_precision_s (char *str, t_struct *list);
void ft_process_c (va_list arg, t_struct *list);
void ft_process_u (va_list arg, t_struct *list);
intmax_t ft_cast_u (t_struct * list, va_list arg);
void ft_process_x (va_list arg, t_struct *list);
intmax_t ft_cast_x (t_struct * list, va_list arg);
char	*ft_strdup(const char *s1);
void ft_print_d(intmax_t i , char *num_d, t_struct *list);
void ft_process_o (va_list arg, t_struct *list);
intmax_t ft_cast_o(t_struct * list, va_list arg);
void ft_print_o(intmax_t i , char *num_o, t_struct *list);
void ft_print_arg_o(char *num_o, t_struct *list);
void ft_print_width_o(intmax_t i, t_struct *list);
void ft_print_precision_o (intmax_t i, t_struct *list);
void ft_print_width_x(intmax_t i, t_struct *list);
void ft_print_x(intmax_t i , char *num_x, t_struct *list);
void ft_print_precision_x(intmax_t i, t_struct *list);
void ft_check_zero(intmax_t i, char *num_d, t_struct *list);
void ft_process_per (t_struct *list);
char *ft_myitoa_baseX(uintmax_t value, uintmax_t base, t_struct *list);
void ft_process_xx (va_list arg, t_struct *list);
void ft_print_precision_xx(intmax_t i, t_struct *list);
void ft_print_width_xx(intmax_t i, t_struct *list);
void ft_print_xx(intmax_t i , char *num_x, t_struct *list);
void ft_process_p (va_list arg, t_struct *list);
void ft_print_p(intmax_t i , char *num_p, t_struct *list, int len);
char			*ft_myitoa_unsigned(uintmax_t value, uintmax_t base);
void ft_process_uu (va_list arg, t_struct *list);
void ft_process_oo (va_list arg, t_struct *list);
void ft_process_dd (va_list arg, t_struct *list);
void ft_process_cc(va_list arg, t_struct *list);
int ft_count_bytes(wchar_t i);
void     ft_put_wchar(wchar_t c, int len_bytes, t_struct * list);
void ft_process_ss(va_list arg, t_struct *list);

int ft_wcharlen(wchar_t *num);
int ft_wstrlen(wchar_t *num);
void	ft_putstr_vova(wchar_t *s,t_struct *list);
void ft_print_width_ss(wchar_t *str, t_struct *list);
void ft_print_precision_ss (wchar_t *str, t_struct *list);
void ft_process_else (t_struct *list);
int ft_wstrlen_prec(wchar_t *num, t_struct *list);





#endif