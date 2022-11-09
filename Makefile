# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 12:04:42 by ejanssen          #+#    #+#              #
#    Updated: 2022/11/09 12:30:35 by ejanssen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#compiler stuff
CC		= gcc
CFLAGS = -Wall -Werror -Wextra

#sources
SRCS	= printf/ft_printf_char.c
SRCS	+= printf/ft_printf_dec.c
SRCS	+= printf/ft_printf_hex.c
SRCS	+= printf/ft_printf_ptr.c
SRCS	+= printf/ft_printf_str.c
SRCS	+= printf/ft_printf.c
SRCS	+= printf/ft_printf_padstr.c
SRCS	+= common.c

CLI = client.c
SRV = server.c

#additonal libraries
LIBFT = libft.a

all: $(LIBFT) client server

$(LIBFT): 
	make -C libft/ bonus

client:
	-@$(CC) $(CFLAGS) $(SRCS) $(CLI) libft/$(LIBFT) -o client

server:
	-@$(CC) $(CFLAGS) $(SRCS) $(SRV) libft/$(LIBFT) -o server

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean 
	rm -f client
	rm -f server

re: fclean all

.PHONY: client server clean fclean re