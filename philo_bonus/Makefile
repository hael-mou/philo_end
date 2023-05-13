# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 09:39:34 by hael-mou          #+#    #+#              #
#    Updated: 2023/05/13 12:37:35 by hael-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

# Directories :
SRC_DIR		=	src/
OBJ_DIR		=	obj/

# Files :
SRC_FILES	=	philo_diner\
				check_argument\
				philo_table\
				philo_create\
				philo_checker\
				routine\
				safe_int\
				time\
				utils
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# Command :
CC			=	cc
RM			=	rm -rf
CFLAGS		=	 -g -Wall -Wextra -Werror -fsanitize=thread
INCLUDE		=	-I include

# Colors :
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;40m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

# Compiling Rules :
$(OBJ_DIR)%.o: $(SRC_DIR)%.c include/*
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(MAGENTA) ># Philo Compiling :$(GREEN) $< $(DEF_COLOR)"

# Roles :
all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ $(INCLUDE) -o $@
	@echo "$(YELLOW) >># Program is created : Philo$(DEF_COLOR)"

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@if [ -d $(OBJ_DIR) ]; then\
		$(RM) $(OBJ_DIR);\
		echo "$(RED) # Remove : \"\
		\b\b\bPhilo Object files cleaned!\" $(DEF_COLOR)";\
	fi

fclean: clean
	@if [ -f $(NAME) ]; then\
		$(RM) $(NAME);\
		echo "$(GRAY) # Remove : \"\
		\b\b\b$(NAME) file cleaned!\" $(DEF_COLOR)";\
	fi

re: fclean all

.PHONY: all clean fclean re
