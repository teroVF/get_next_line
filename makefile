# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 11:03:17 by anvieira          #+#    #+#              #
#    Updated: 2022/12/15 15:49:46 by anvieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
NAME2 = get_next_line_bonus.a
CC = cc
FLAGS = -Wall -Werror -Wextra
INCLUDES = get_next_line.h
RM = rm
AR = ar rcs

#Colors

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
CYAN = \033[0;96m

#Sources

FUNCTION = get_next_line get_next_line_utils
BONUS_FUNCTION = get_next_line_bonus get_next_line_utils_bonus

SRC = $(addsuffix .c, $(FUNCTION))
OBJ = $(addsuffix .o, $(FUNCTION))
BONUS_SRC = $(addsuffix .c, $(BONUS_FUNCTION))
BONUS_OBJ = $(addsuffix .o, $(BONUS_FUNCTION))

all: 		$(NAME)

$(NAME):		$(OBJ)
			@$(AR) $@ $(OBJ)
			@echo "$(GREEN)Libft compiled!$(DEF_COLOR)"

%.o:		%.c
			@echo "$(YELLOW) Compiling: $< $(DEF_COLOR)"
			@$(CC) $(FLAGS) -c $< -o $@

bonus:		$(OBJ) $(BONUS_OBJ)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)Libft with bonus compiled!$(DEF_COLOR)"

clean:
			@$(RM) -f $(OBJ) $(BONUS_OBJ)
			@echo "$(BLUE)Libft objects files cleaned!$(DEF_COLOR)"

fclean:
			@$(RM) -f $(NAME) $(NAME2)
			@echo "$(CYAN)Libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for libft!$(DEF_COLOR)"


.PHONY:		all clean fclean re
