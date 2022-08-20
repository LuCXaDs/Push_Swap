# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 16:45:18 by luserbu           #+#    #+#              #
#    Updated: 2022/08/18 23:05:24 by luserbu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	main.c error.c sort_a.c sort_b.c sort_algo.c radix.c split_number.c verif_int.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g

RM		=	rm -rf

LIBFT	=	libft/libft.a

PRINTF	=	printf/libftprintf.a

all:	$(NAME)

$(LIBFT):
	make -sC libft/

$(PRINTF):
	make -sC printf/

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
	echo "Compilation Success !"

clean:
	$(RM) $(OBJS)
	make -sC libft/ clean
	make -sC printf/ clean

fclean: clean
	$(RM) ${NAME}
	make -sC libft/ fclean
	make -sC printf/ fclean

re: fclean all
.PHONY: clean all re
.SILENT:
