NAME			=	so_long

SRCDIR 			=	srcs/

INCDIR			=	includes/

SRCFILES		=   ../ft_printf/ft_print_ptr.c\
                    ../ft_printf/ft_printf.c\
                    ../ft_printf/ft_printhex.c\
                    ../ft_printf/ft_utils.c\
                    ../gnl/get_next_line.c\
                    ../gnl/get_next_line_utils.c\
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


SRCS			=	$(addprefix $(SRCDIR), $(SRCFILES))

OBJS			=	$(SRCS:.c=.o)

INCS		=	-I $(INCDIR)

CC			= gcc

CFLAGS 		= -Wall -Werror -Wextra -Imlx

CFLAGS		+= $(INCS)

.PHONY:		all bonus clean fclean re

all:		$(NAME)

$(NAME):	$(SRCS) $(OBJS)
			$(CC) $(CFLAGS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)
			rm -f $(OBJS_TEST)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
