NAME =  libftprintf.a

CFLAGS = -O0

OBJECTS = $(SRC:.c=.o)

SRC =	ft_printf.c \
		ft_make_zero_struct.c \
		ft_pars_all.c \
		ft_parse_length.c \
		ft_processing.c \
		ft_myitoa_base.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_strchr.c \
		ft_putnbr.c \
		ft_putchar.c \
		ft_process_d.c \
		ft_myputchar.c \
		ft_process_s.c \
		ft_putstr1.c \
		ft_strlen_s.c \
		ft_myputstr.c \
		ft_process_c.c \
		ft_process_u.c \
		ft_process_x.c \
		ft_strdup.c \
		ft_process_o.c \
		ft_process_per.c \
		ft_my_itoa_baseX.c \
		ft_process_xx.c \
		ft_process_p.c \
		ft_myitoa_unsigned.c \
		ft_process_uu.c \
		ft_process_oo.c \
		ft_process_dd.c \
		ft_process_cc.c \
		ft_process_ss.c \
		ft_wcharlen.c \
		ft_letter.c \

all : $(NAME)

$(NAME) :
		gcc -c $(CFLAGS) $(SRC)
		ar -cru $(NAME) $(OBJECTS)
clean :
		rm -rf $(OBJECTS)

fclean : clean
		rm -rf $(NAME)

re : fclean all



