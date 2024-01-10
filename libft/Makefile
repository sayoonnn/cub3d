# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayoon <sayoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 17:33:26 by sayoon            #+#    #+#              #
#    Updated: 2023/10/26 08:17:51 by sayoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		= ft_atoi.c ft_bzero.c ft_calloc.c \
		  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
		  ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
		  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
		  ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
		  ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
		  ft_strcmp.c\
		  ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
		  ft_malloc.c\
		  \
		  ft_printf/ft_print_chars.c\
		  ft_printf/ft_print_diu.c\
		  ft_printf/ft_print_p.c\
		  ft_printf/ft_print_x.c\
		  ft_printf/ft_printf.c

OBJ		= $(SRC:.c=.o)

CC 		= cc
AR		= ar

CFLAGS	= -Wall -Wextra -Werror
ARFLAGS	= rcs

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $@ $^

%.o: %.c libft.h ft_printf/ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(B_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all bonus clean fclean re
