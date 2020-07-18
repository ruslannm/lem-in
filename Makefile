# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgero <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/01 00:00:00 by lnickole          #+#    #+#              #
#    Updated: 2020/07/18 18:16:46 by rgero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LEM-IN			= lem-in
DIR_SRC				= sources
DIR_OBJ 			= objects
DIR_INC 			= includes

DIR_LIBFT 			= libft
NAME_LIBFT			= $(DIR_LIBFT)/libft.a
DIR_INC_LIBFT		= $(DIR_LIBFT)/includes

DIR_FT_PRINTF 		= ft_printf
NAME_FT_PRINTF		= $(DIR_FT_PRINTF)/libftprintf.a
DIR_INC_PRINTF		= $(DIR_FT_PRINTF)/includes

SRC_LIST_LEM-IN 	= add_rooms.c\
					bfs.c\
					count_ants.c\
					create_paths.c\
					create_tab.c\
					distribute_ants.c\
					exit_func.c\
					free_array.c\
					ft_arrintnew.c\
					hash.c\
					join_str.c\
					lem_in.c\
					links.c\
					print_paths.c\
					print_result.c\
					print_usage.c\
					queue.c \
					room_index.c\
					rooms.c\
					save_path.c\
					solution.c\
					utils.c

HEADERS				= lem_in.h

SRC_LEM-IN			= $(addprefix $(DIR_SRC)/, $(SRC_LIST_LEM-IN))
OBJ_LEM-IN			= $(addprefix $(DIR_OBJ)/, $(SRC_LIST_LEM-IN:.c=.o))
INC					= $(addprefix $(DIR_INC)/, $(HEADERS))

FLAGS			= -Wall -Wextra -Werror -g
GCC_LIBFT 		= -L $(DIR_LIBFT) -lft
GCC_FT_PRINTF	= -L $(DIR_FT_PRINTF) -lftprintf

all: $(NAME_LEM-IN)

$(NAME_LEM-IN): $(DIR_OBJ) $(OBJ_LEM-IN) $(NAME_LIBFT) $(NAME_FT_PRINTF) $(INC)
	@gcc $(FLAGS) $(OBJ_LEM-IN) -o $(NAME_LEM-IN) $(GCC_LIBFT) $(GCC_FT_PRINTF)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(NAME_LIBFT):
	@make -C $(DIR_LIBFT)/

$(NAME_FT_PRINTF):
	@make -C $(DIR_FT_PRINTF)/

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(INC)
	@gcc -c -I $(DIR_INC) -I $(DIR_INC_LIBFT) -I $(DIR_INC_PRINTF) $(FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(DIR_OBJ)
	@make clean -C $(DIR_LIBFT)/
	@make clean -C $(DIR_FT_PRINTF)/

fclean: clean
	@/bin/rm -f $(NAME_LEM-IN)
	@make fclean -C $(DIR_LIBFT)/
	@make fclean -C $(DIR_FT_PRINTF)/

re: fclean all

.PHONY: all clean fclean re