NAME			=	so_long

NAMEBONUS		=	so_long_bonus

NAMEBOSS = so_long_mum

SRCDIR 			=	srcs/

SRCDIRBONUS 	=	srcs_bonus/

SRCDIRBOSS	=	mum/

INCDIR			=	includes/

SRCBOSS	=			../ft_printf/ft_print_ptr.c\
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

SRCSBOSS		=	$(addprefix $(SRCDIRBOSS), $(SRCBOSS))

SRCSBONUS		=	$(addprefix $(SRCDIRBONUS), $(SRCBONUS))

SRCS			=	$(addprefix $(SRCDIR), $(SRC))

OBJS			=	$(SRCS:.c=.o)

OBJSBONUS		=	$(SRCSBONUS:.c=.o)

OBJSBOSS		=	$(SRCSBOSS:.c=.o)

CC			= gcc

CFLAGS 		= -Wall -Werror -Wextra -Imlx -I $(INCDIR)

all:		$(NAME)

$(NAME):	$(SRCS) $(OBJS)
			$(CC) $(CFLAGS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

bonus:		$(NAMEBONUS)

$(NAMEBONUS):	$(SRCSBONUS) $(OBJSBONUS)
				$(CC) $(CFLAGS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJSBONUS) -o $(NAMEBONUS)

boss:		$(NAMEBOSS)

$(NAMEBOSS):	$(SRCSBOSS) $(OBJSBOSS)
					$(CC) $(CFLAGS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJSBOSS) -o $(NAMEBOSS)
%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS) $(OBJSBONUS) $(OBJSBOSS)

fclean:		clean
			rm -f $(NAME) $(NAMEBONUS) $(NAMEBOSS)

re:			fclean all

rebonus:	fclean bonus

reboss:		fclean boss