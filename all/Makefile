SRCS		= 	ft_printf.c \
				ft_printtypes.c \
				ft_printtypes2.c \
				ft_minus.c \
				ft_fzero.c \
				ft_noflag.c \
				ft_width_prec.c \
				ft_assignstruct.c \
				ft_padding.c \
				ft_subprintf.c \

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

bonus:		$(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re
