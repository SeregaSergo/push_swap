# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bswag <bswag@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/20 17:19:13 by bswag             #+#    #+#              #
#    Updated: 2021/04/28 19:38:36 by bswag            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 =		checker
NAME2 =		push_swap
SRCS1 =		checker.c \
			fill_stack_a.c \
			operations.c \
			dbl_operations.c \
			printing.c
SRCS2 =		push_swap.c \
			fill_stack_a.c \
			operations.c \
			dbl_operations.c \
			printing.c
PATHSRC =	./srcs/
OBJS1 =		$(SRCS1:%.c=%.o)
OBJS2 =		$(SRCS2:%.c=%.o)
LIB =		libft.a
PATHLIB =	./libft/
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
PATHINC =	./includes/
DEPS =		$(PATHINC)push_swap.h

.PHONY: all clean fclean re bonus

all: $(NAME1) $(NAME2) 

$(NAME1): $(addprefix $(PATHSRC),$(OBJS1)) $(LIB)
	$(CC) $(CFLAGS) -I$(DEPS) -L$(PATHLIB) -lft $(addprefix $(PATHSRC),$(OBJS1)) -o $(NAME1)

$(NAME2): $(addprefix $(PATHSRC),$(OBJS2)) $(LIB)
	$(CC) $(CFLAGS) -I$(DEPS) -L$(PATHLIB) -lft $(addprefix $(PATHSRC),$(OBJS2)) -o $(NAME2)

$(LIB):
	$(MAKE) -C $(PATHLIB)

%.o: $(PATHSRC)%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
	
bonus: all

clean:
	/bin/rm -f $(addprefix $(PATHSRC), $(OBJS))

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
