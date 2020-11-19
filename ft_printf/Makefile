SRCS		= 	ft_printf2.c

HEADERS		=	printf.h

OBJS		=	$(SRCS:.c=.o)

NAME		=	libftprintf.a

CFLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

RM			=	rm -f

LIBFT		=	libft

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)


$(NAME):	${OBJS}
			make -C $(LIBFT)
			cp libft/libft.a ./$(NAME)
			ar rc $(NAME) $(OBJS)
			ranlib ${NAME}

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re
