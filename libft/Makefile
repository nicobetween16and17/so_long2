SRCS	=	ft_atoi.c \
 			ft_bzero.c \
 			ft_calloc.c \
 			ft_isalnum.c \
 			ft_isalpha.c \
 			ft_isascii.c \
 			ft_isdigit.c \
 			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c

NAME	=	libft.a

CFLAGS	=	-Wall -Werror -Wextra

CC		=	gcc

RM		=	rm -f

ARRCS	=	ar rcs

INCS	=	libft.h


BONUS	=	ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c

BONUSOBJS	=	${BONUS:.c=.o}

OBJS	=	${SRCS:.c=.o}

.c.o: 
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME}: ${OBJS}
		${ARRCS} ${NAME} ${OBJS}

all: ${NAME}

clean:
		${RM} ${OBJS} ${BONUSOBJS}

fclean: clean
		${RM} ${NAME}

re:	fclean all

bonus:	${OBJS} ${BONUSOBJS}
	${ARRCS} ${NAME} ${OBJS} ${BONUSOBJS}

.PHONY: all clean fclean re bonus
