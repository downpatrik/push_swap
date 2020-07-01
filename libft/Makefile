# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 12:47:46 by wvenita           #+#    #+#              #
#    Updated: 2020/03/16 20:17:47 by wvenita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
OBJ = \
		ft_atoi.o\
		ft_bzero.o\
		ft_isalnum.o\
		ft_isalpha.o\
		ft_isascii.o\
		ft_isdigit.o\
		ft_isprint.o\
		ft_isspace.o\
		ft_memccpy.o\
		ft_memchr.o\
		ft_memcmp.o\
		ft_memcpy.o\
		ft_memmove.o\
		ft_memset.o\
		ft_strcat.o\
		ft_strchr.o\
		ft_strcmp.o\
		ft_strcpy.o\
		ft_strdup.o\
		ft_strlcat.o\
		ft_strlen.o\
		ft_strncat.o\
		ft_strncmp.o\
		ft_strncpy.o\
		ft_strnstr.o\
		ft_strrchr.o\
		ft_strstr.o\
		ft_tolower.o\
		ft_toupper.o\
		ft_pow.o\
		ft_memalloc.o\
		ft_memdel.o\
		ft_strnew.o\
		ft_strdel.o\
		ft_strclr.o\
		ft_striter.o\
		ft_striteri.o\
		ft_strmap.o\
		ft_strmapi.o\
		ft_strequ.o\
		ft_strnequ.o\
		ft_strsub.o\
		ft_strjoin.o\
		ft_strtrim.o\
		ft_strsplit.o\
		ft_itoa.o\
		ft_putchar.o\
		ft_putstr.o\
		ft_putendl.o\
		ft_putnbr.o\
		ft_putchar_fd.o\
		ft_putstr_fd.o\
		ft_putendl_fd.o\
		ft_putnbr_fd.o\
		ft_strnlen.o\
		ft_memrcpy.o\
		ft_isupper.o\
		ft_islower.o\
		ft_abs.o\
		ft_lstnew.o\
		ft_lstdelone.o\
		ft_lstdel.o\
		ft_lstadd.o\
		ft_lstiter.o\
		ft_lstmap.o\
		ft_isxdigit.o\
		ft_atof.o\
		ft_strrev.o\
		ft_free_array.o\
		get_next_line.o\
		ft_error.o

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re