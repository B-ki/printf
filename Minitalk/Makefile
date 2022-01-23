CLIENT =	srcs/client.c
SERVER = 	srcs/server.c
OBJS_CLIENT = $(CLIENT:.c=.o)
OBJS_SERVER = $(SERVER:.c=.o)
LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = gcc
RM = rm -rf
CFLAGS = -Wextra -Wall -Werror
INCLUDES_DIR = ./includes/
INCLUDES = -I $(INCLUDES_DIR) -I $(LIBFT_DIR)

all: $(CLIENT) $(SERVER)

%.o: %.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

$(LIBFT):
			$(MAKE) bonus -C ./libft

client: $(OBJS_CLIENT) $(LIBFT)
			$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT) $(LIBFT) -o client

server: $(OBJS_SERVER) $(LIBFT)
			$(CC) $(CFLAGS) $(INCLUDES) $(SERVER) $(LIBFT) -o server

clean:		
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)


fclean: clean
			$(MAKE) fclean -C ./libft
			$(RM) client server

re:			fclean all

.PHONY: all clean fclean re
