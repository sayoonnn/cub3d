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
			init_player.c\
			draw_wall.c\
			draw_screen.c\
			draw_floor_ceil.c\
			print_screen.c\
			player_moves.c\
			load_textures.c\
			print_err.c


vpath %.c	$(addprefix src, /.)

OBJDIR	=	.objs
OBJ		=	$(SRC:%.c=$(OBJDIR)/%.o)

INC		=	includes
HEADERS	=	includes/cub3d.h\
			includes/types.h

LIBFT	=	libft
LIBFTA	=	libft/libft.a

MLX		=	mlx
MLXA	=	mlx/libmlx.a

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -O3 
#-g -fsanitize=address
MLXFLAG	=	-framework OpenGL -framework AppKit

all :
	@make $(NAME) -j8

$(NAME): $(OBJ) $(LIBFTA) $(MLXA)
	@$(CC) $(CFLAGS) $(MLXFLAG) $(OBJ) $(LIBFTA) $(MLXA) -o $@
	@echo $(NAME) DONE ✅ 

$(LIBFTA):
	@make -C $(LIBFT)
	@echo LIBFT DONE ✅

$(MLXA):
	@make -C $(MLX)
	@echo MLX DONE ✅

$(OBJDIR)/%.o: %.c  $(HEADERS) | $(OBJDIR)
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
