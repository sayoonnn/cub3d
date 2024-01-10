# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayoon <sayoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 14:35:00 by sayoon            #+#    #+#              #
#    Updated: 2024/01/10 14:35:01 by sayoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

SRC		=	main.c\
			draw_screen.c\
			init_player.c

vpath %.c	$(addprefix src, /.)

OBJDIR	=	.objs
OBJ		=	$(SRC:%.c=$(OBJDIR)/%.o)

INC		=	includes


LIBFT	=	libft
LIBFTA	=	libft/libft.a

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g
MLXFLAG	=	-lmlx -framework OpenGL -framework AppKit

all :
	@make $(NAME) -j8

$(NAME): $(OBJ) $(LIBFTA)
	@$(CC) $(CFLAGS) $(MLXFLAG) $(OBJ) $(LIBFTA) -o $@
	@echo $(NAME) DONE ✅ 

$(LIBFTA):
	@make -C $(LIBFT)
	@echo LIBFT DONE ✅

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@make -C $(LIBFT) fclean
	@rm -rf $(OBJDIR)
	@echo CLEAN DONE ✅

fclean:
	@make clean
	@rm -f $(NAME)
	@echo FCLEAN DONE ✅

re: 
	@make fclean
	@make all

.PHONY:	all bonus clean fclean re
