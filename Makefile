NAME			=	so_long

SRCDIR 			=	srcs/

SRCDIRBONUS 	=	srcs/

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

SRC             =

SRCSBONUS			=	$(addprefix $(SRCDIRBONUS), $(SRCBONUS))

SRCSBONUS			=	$(addprefix $(SRCDIRBONUS), $(SRCBONUS))

OBJS			=	$(SRCS:.c=.o)

INCS		=	-I $(INCDIR)

CC			= gcc

CFLAGS 		= -Wall -Werror -Wextra -Imlx

CFLAGS		+= $(INCS)

.PHONY:		all bonus clean fclean re

all:		$(NAME)

$(NAME):	$(SRCS) $(OBJS)
			$(CC) $(CFLAGS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

bonus:		$(NAMEB)

$(NAMEB):	$(SRCSBONUS) $(OBJS)
			$(CC) $(CFLAGS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
