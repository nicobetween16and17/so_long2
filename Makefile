NAME			=	so_long

NAMEBONUS		=	so_long_bonus

SRCDIR 			=	srcs/

SRCDIRBONUS 	=	srcs_bonus/

INCDIR			=	includes/

SRCBONUS		=   ../ft_printf/ft_print_ptr.c\
                    ../ft_printf/ft_printf.c\
                    ../ft_printf/ft_printhex.c\
                    ../ft_printf/ft_utils.c\
                    memory_usage.c\
                    controlls.c\
                    error_checking.c\
                    errors_displayed.c\
                    inputs.c\
                    parse_map.c\
                    main.c\
                    battle.c\
                    lst.c\
                    hooks.c\
                    util.c\
                    utils2.c\
                    init.c\
                    utils3.c\
                    utils4.c\
                    utils5.c\
                    path.c\
                    lst_pos.c\
                    error_handling.c\

SRC				=   ../ft_printf/ft_print_ptr.c\
                    ../ft_printf/ft_printf.c\
                    ../ft_printf/ft_printhex.c\
                    ../ft_printf/ft_utils.c\
                    main.c\
                    inputs.c\
                    error_checking.c\
                    errors_displayed.c\
                    parse_map.c\
                    utils1.c\
                    utils2.c\
                    path.c\
                    lst_pos.c\
                    error_handling.c\

SRCSBONUS		=	$(addprefix $(SRCDIRBONUS), $(SRCBONUS))

SRCS			=	$(addprefix $(SRCDIR), $(SRC))

OBJS			=	$(SRCS:.c=.o)

OBJSBONUS		=	$(SRCSBONUS:.c=.o)

CC			= gcc

CFLAGS 		= -Wall -Werror -Wextra -Imlx -I $(INCDIR)

all:		$(NAME)

$(NAME):	$(SRCS) $(OBJS)
			cd libft && make re && cd .. && cd mlx && make && cd ..
			$(CC) $(CFLAGS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

bonus:		$(NAMEBONUS)

$(NAMEBONUS):	$(SRCSBONUS) $(OBJSBONUS)
				cd libft && make bonus && cd .. && cd mlx && make && cd ..
				$(CC) $(CFLAGS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJSBONUS) -o $(NAMEBONUS)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS) $(OBJSBONUS)

fclean:		clean
			rm -f $(NAME) $(NAMEBONUS)
			cd libft && make fclean && cd .. && cd mlx && make clean && cd ..

re:			fclean all

rebonus:	fclean bonus