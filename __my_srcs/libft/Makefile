# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 13:24:29 by ejanssen          #+#    #+#              #
#    Updated: 2022/11/08 17:22:01 by ejanssen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C 				= gcc
CFLAGS 			= -Wall -Werror -Wextra
SRC 			= ft_isalpha.c
SRC				+= ft_isdigit.c
SRC				+= ft_isalnum.c
SRC				+= ft_isascii.c
SRC				+= ft_isprint.c
SRC				+= ft_strlen.c
SRC				+= ft_toupper.c
SRC				+= ft_tolower.c
SRC				+= ft_strlcpy.c
SRC				+= ft_strlcat.c
SRC				+= ft_strchr.c
SRC				+= ft_strrchr.c
SRC				+= ft_strncmp.c
SRC				+= ft_strnstr.c
SRC				+= ft_atoi.c
SRC				+= ft_strdup.c
SRC				+= ft_calloc.c
SRC				+= ft_memset.c
SRC				+= ft_memcpy.c
SRC				+= ft_memmove.c
SRC				+= ft_bzero.c
SRC				+= ft_memchr.c
SRC				+= ft_memcmp.c

#PART TWO
SRC				+= ft_substr.c
SRC				+= ft_strjoin.c
SRC				+= ft_strtrim.c
SRC				+= ft_split.c
SRC				+= ft_itoa.c
SRC				+= ft_strmapi.c
SRC				+= ft_striteri.c
SRC				+= ft_putchar_fd.c
SRC				+= ft_putstr_fd.c
SRC				+= ft_putendl_fd.c
SRC				+= ft_putnbr_fd.c

#additional
SRC				+= ft_pow.c

#BONUS
SRCBONUS				= ft_lstnew_bonus.c
SRCBONUS				+= ft_lstadd_front_bonus.c
SRCBONUS				+= ft_lstsize_bonus.c
SRCBONUS				+= ft_lstlast_bonus.c
SRCBONUS				+= ft_lstadd_back_bonus.c
SRCBONUS				+= ft_lstdelone_bonus.c
SRCBONUS				+= ft_lstclear_bonus.c
SRCBONUS				+= ft_lstiter_bonus.c
SRCBONUS				+= ft_lstmap_bonus.c
SRCBONUS				+= $(SRC)


OBJECTS				= $(SRC:.c=.o)
OBJECS_BONUS		= $(SRCBONUS:.c=.o)
NAME				= libft.a

.PHONY: all
all: $(NAME)

.c.o:
	$(CC) -c $(CFLAGS) -o $@ $< $(INC)

.PHONY: bonus
bonus: $(OBJECS_BONUS)
	ar r $(NAME) $^

.PHONY: $(NAME)
$(NAME): $(OBJECTS)
	ar r $@ $^

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(OBJECS_BONUS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re : fclean all
