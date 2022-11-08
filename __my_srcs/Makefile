
SRCS	= printf/ft_printf_char.c
SRCS	+= printf/ft_printf_dec.c
SRCS	+= printf/ft_printf_hex.c
SRCS	+= printf/ft_printf_ptr.c
SRCS	+= printf/ft_printf_str.c
SRCS	+= printf/ft_printf.c
SRCS	+= printf/ft_printf_padstr.c

CLI = client.c
SRV = server.c

LIBFT = libft.a

CFLAGS = -Wall -Werror -Wextra

all: $(LIBFT) client server

$(LIBFT): 
	make -C libft/ bonus

client:
	gcc $(CFLAGS) $(SRCS) $(CLI) libft/$(LIBFT) -o client

server:
	gcc $(CFLAGS) $(SRCS) $(SRV) libft/$(LIBFT) -o server

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean 
	rm -f client
	rm -f server

re: fclean all

.PHONY: client server clean fclean re