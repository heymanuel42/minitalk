# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 12:04:42 by ejanssen          #+#    #+#              #
#    Updated: 2022/11/11 09:03:39 by ejanssen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#compiler stuff
CC		= cc
CFLAGS = -Wall -Werror -Wextra

#sources
SRCS	= printf/ft_printf_char.c
SRCS	+= printf/ft_printf_dec.c
SRCS	+= printf/ft_printf_hex.c
SRCS	+= printf/ft_printf_ptr.c
SRCS	+= printf/ft_printf_str.c
SRCS	+= printf/ft_printf.c
SRCS	+= printf/ft_printf_padstr.c

CLI = client.c
SRV = server.c
COMMON = common.c

CLI_BONUS = client_bonus.c
SRV_BONUS = server_bonus.c
COMMON_BONUS = common_bonus.c

#additonal libraries
LIBFT = libft.a

NAME = minitalk
all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft/ bonus

$(NAME): client server

client:
	-@$(CC) $(CFLAGS) $(SRCS) $(COMMON) $(CLI) libft/$(LIBFT) -o client

server:
	-@$(CC) $(CFLAGS) $(SRCS) $(COMMON) $(SRV) libft/$(LIBFT) -o server

bonus:
	-@$(CC) $(CFLAGS) $(SRCS) $(COMMON_BONUS) $(CLI_BONUS) libft/$(LIBFT) -o client
	-@$(CC) $(CFLAGS) $(SRCS) $(COMMON_BONUS) $(SRV_BONUS) libft/$(LIBFT) -o server

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f client
	rm -f server

re: fclean all

.PHONY: client server clean fclean re bonus