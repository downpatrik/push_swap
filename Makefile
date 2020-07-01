# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 15:19:28 by wvenita           #+#    #+#              #
#    Updated: 2020/06/19 01:21:33 by wvenita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

NAMEPS	=	push_swap
NAMECH	=	checker

FLAGS	=	-Wall -Wextra -Werror

LIBDIR	=	libft
LIBLINK	=	-L $(LIBDIR) -lft
LIB		=	$(LIBDIR)/libft.a

SRCDIR	=	./src/
OBJDIR	=	./tmp/

SRCNPS	=	push_swap.c\
			ft_validation.c\
			ft_actions.c\
			ft_actions_2.c\
			ft_actions_3.c\
			ft_quick_sort.c\
			ft_separation.c\
			ft_initialization.c\
			ft_sort_3_and_5.c \
			ft_global_sort.c\
			ft_finding_place.c

SRCNCH 	=	checker.c\
			ft_validation.c\
			ft_actions.c\
			ft_actions_2.c\
			ft_actions_3.c\
			ft_quick_sort.c\
			ft_separation.c\
			ft_initialization.c

SRCPS	=	$(addprefix $(SRCDIR), $(SRCNPS))
SRCCH	=	$(addprefix $(SRCDIR), $(SRCNCH))
OBJPS	=	$(addprefix $(OBJDIR), $(SRCNPS:.c=.o))
OBJCH	=	$(addprefix $(OBJDIR), $(SRCNCH:.c=.o))

HEADERN	=	push_swap.h
HAEDER	=	$(addprefix $(INCDIR), $(HEADERN))
INCDIR	=	./include/
INCL	=	./libft/

CLEAR       = "\033[K"
EOC			= "\033[0;0m"
GREEN		= "\033[0;32m"
CR			= "\r"$(CLEAR)

all: $(LIB) $(NAMEPS) $(NAMECH)

$(NAMEPS): $(OBJDIR) $(OBJPS) $(LIB) $(HEADER)
		@$(CC) $(FLAGS) $(addprefix -I , $(INCDIR)) -o $@ $(OBJPS) $(LIBLINK)
		-@printf $(CR)$(GREEN)"✓ $@ is created\n"$(EOC)

$(NAMECH): $(OBJDIR) $(OBJCH) $(LIB) $(HEADER)
		@$(CC) $(FLAGS) $(addprefix -I , $(INCDIR)) -o $@ $(OBJCH) $(LIBLINK)
		-@printf $(CR)$(GREEN)"✓ $@ is created\n"$(EOC)

$(OBJDIR):
		@mkdir -p tmp

$(LIB):
		@make -C $(LIBDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
		@$(CC) -c -I $(INCDIR) -I $(INCL) $(FLAGS) $< -o $@

clean:
		@make -C $(LIBDIR) clean
		@rm -rf $(OBJDIR)

fclean: clean
		@rm -f $(NAMECH) $(NAMEPS)
		@make -C $(LIBDIR) fclean

re: fclean all

.PHONY: clean all re fclean