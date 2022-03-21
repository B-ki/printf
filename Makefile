NAME = libftprintf.a

SRCS =	srcs/ft_printf.c 		\
		srcs/print.c			\
		srcs/utils.c			\
		srcs/utils2_put.c		\
		srcs/utils3_size.c		\
		srcs/struct.c			\
		srcs/char.c				\
		srcs/string.c			\
		srcs/pointer.c			\
		srcs/int.c				\
		srcs/unsigned.c			\
		srcs/hexadecimal.c		\
		srcs/percent.c
						
OBJS = $(SRCS:.c=.o)
CC = gcc
RM = rm -rf
CFLAGS = -Wextra -Wall -Werror
INCLUDES = -I ./includes

all: $(NAME)

%.o: %.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
			$(MAKE) bonus -C ./libft
			cp libft/libft.a $(NAME)
			ar -rcs $(NAME) $(OBJS)

bonus:		$(NAME)

clean:		
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS)


fclean: clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
