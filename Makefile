# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/01 13:13:59 by wvenita           #+#    #+#              #
#    Updated: 2020/03/16 22:10:04 by wvenita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB			= libft/libft.a

HEADER_NAME = ft_push_swap.h
PS_NAME		= push_swap
CHECK_NAME	= checker

INC_DIR		= ./includes/
INC_LIBFT	= ./libft/
SRC_DIR		= ./srcs/
OBJ_DIR		= ./obj/

SRC_NAME_PS	= ft_push_swap.c\
				ft_create_stack.c\
				ft_cmd.c\
				ft_cmd_instr.c\
				ft_cmd_swap.c\
				ft_sort.c\
				ft_sort_utils.c\
				ft_clean.c\

SRC_NAME_CH	= ft_checker.c\
				ft_create_stack.c\
				ft_cmd.c\
				ft_cmd_instr.c\
				ft_cmd_swap.c\
				ft_sort.c\
				ft_sort_utils.c\
				ft_clean.c\

HAEDER		= $(addprefix $(INC_DIR), $(HEADER_NAME))
SRC_PS		= $(addprefix $(SRC_DIR), $(SRC_NAME_PS))
SRC_CHEK	= $(addprefix $(SRC_DIR), $(SRC_NAME_CH))
OBJ_PS		= $(addprefix $(OBJ_DIR), $(SRC_NAME_PS:.c=.o))
OBJ_CHECK	= $(addprefix $(OBJ_DIR), $(SRC_NAME_CH:.c=.o))

CC			= gcc
FLAGS		= -Wall -Wextra -Werror
GCC_LIBFT	= -L ./libft -lft

all: $(PS_NAME) $(CHECK_NAME)

$(PS_NAME): $(OBJ_DIR) $(OBJ_PS) $(LIB) $(HAEDER)
	$(CC) $(GCC_LIBFT) $(addprefix -I , $(INC_DIR)) $(OBJ_PS) $(FLAGS) -o $(PS_NAME)

$(CHECK_NAME): $(OBJ_DIR) $(OBJ_CHECK) $(LIB) $(HAEDER)
	$(CC) $(GCC_LIBFT) $(addprefix -I , $(INC_DIR)) $(OBJ_CHECK) $(FLAGS) -o $(CHECK_NAME)

$(OBJ_DIR):
	@mkdir -p obj

$(LIB):
	@make -C libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HAEDER)
	$(CC) -c -I $(INC_DIR) -I $(INC_LIBFT) $(FLAGS) $< -o $@

clean: 
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C libft/

fclean: clean
	/bin/rm -f $(PS_NAME) $(CHECK_NAME)
	@make fclean -C libft/

re: fclean all