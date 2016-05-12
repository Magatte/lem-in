# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pba <pba@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/09 11:34:20 by pba               #+#    #+#              #
#    Updated: 2016/05/03 17:04:44 by pba              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: mkdir_obj, clean

.SUFFIXES:

NAME		= lem-in
CFLAGS		= -Wall -Wextra -Werror -g
HPATH_LEM	= includes/
HPATH_LIBFT	= libft/includes/
SPATH		= src/
OPATH		= obj/

SRC			= lem_in.c \
			  check_ants.c \
			  check_anthill.c \
			  parser.c \
			  usage.c \
			  list_manager.c \
			  anthill_init.c \
			  options_init.c \
			  push_neighbours.c \
			  search_neighbours.c \
			  set_costs.c \
			  set_visited.c \
			  graph_init.c \
			  push_paths.c \
			  get_min_cost.c \
			  find_paths.c \
			  set_marks.c \
			  search_next.c \
			  sequences.c \
			  walking.c \
			  anthill_display.c \
			  free.c

OBJ			= $(SRC:%.c=$(OPATH)%.o)

all: mkdir_obj $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32;01mObject files created.\033[0m"
	@echo "\033[36;01mCompiling libft...\033[0m"
	@make re -C libft
	@echo "\033[32;01mlibft.a created.\033[0m"
	@gcc -o $(NAME) $(OBJ) -L./libft/ -lft
	@echo "\033[32;01mLink done.\033[0m"

$(OPATH)%.o: $(SPATH)%.c
	@gcc $(CFLAGS) -c $< -I $(HPATH_LEM) -I $(HPATH_LIBFT) -o $@

mkdir_obj:
	@mkdir -p $(OPATH)
	@echo "\033[32;01mobj/ folder created.\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "Objects deleted."

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) deleted."

re: fclean all
