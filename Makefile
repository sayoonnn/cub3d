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

SRC		=	main.c

OBJDIR	=	.objs
OBJ		=	$(SRC:%.c=$(OBJDIR)/%.o)

INC		= includes

LIBMLX	= minilibx
LIBMLXA	= minilibx/libmlx.a

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

all :
	@make $(NAME) -j8

$(NAME): $(OBJ) $(LIBMLXA)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBMLXA) -o $@
	@echo $(NAME) DONE ✅ 

$(LIBMLXA):
	@make -C $(LIBMLX)
	@echo LIBFT DONE ✅

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@make -C $(LIBMLX) clean
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
