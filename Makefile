# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/25 01:41:20 by thou              #+#    #+#              #
#    Updated: 2017/12/30 16:45:31 by thou             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK					=	\033[30;1m
RED						=	\033[31;1m
GREEN					=	\033[32;1m
YELLOW					=	\033[33;1m
BLUE					=	\033[34;1m
PURPLE					=	\033[35;1m
CYAN					=	\033[36;1m
WHITE					=	\033[37;1m
RESET					=	\033[0m
CLEAR					=	\033[H\e[J

NAME	=	thou.filler
FLAG	=	-Wall -Wextra -Werror
INC		=	-I includes -I libft/includes
SRC_DIR	=	src/
SRC_BASE=	main.c get.c free.c count.c
SRC		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ_DIR	=	obj/
OBJ		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
LIB		=	./libft
LFT		=	./libft/libft.a

all: $(LFT) $(NAME)

$(LFT):
	@make -C $(LIB)

$(NAME): $(OBJ)
	@gcc $(FLAG) -o $(NAME) $(OBJ) $(INC) -L$(LIB) -lft -lncurses
	@echo "\033[48;5;15;38;5;25;1mMAKE $(NAME) DONE$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAG) $(INC) -o $@ -c $<

clean:
	@make clean -C $(LIB)
	@make clean -C ./visualisateur
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Clean	./obj$(GREEN)			[ OK ]$(RESET)"


fclean:
	@make fclean -C $(LIB)
	@make fclean -C ./visualisateur
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Clean	./obj$(GREEN)			[ OK ]$(RESET)"
	@rm -rf $(NAME)
	@echo "$(YELLOW)Clean	$(NAME)$(GREEN)		[ OK ]$(RESET)"

re: fclean all
