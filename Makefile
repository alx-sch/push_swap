# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 19:39:15 by aschenk           #+#    #+#              #
#    Updated: 2024/02/05 20:29:10 by aschenk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap
CC =			cc
CFLAGS =		-Wall -Wextra -Werror
SRCS =			$(wildcard *.c)
OBJS =			${SRCS:.c=.o}

# Target 'all' is the default target, building program specified by $(NAME).
all:	$(NAME)

# Target $(NAME) depends on object files $(OBJS) and libft library.
$(NAME):	$(OBJS) libft/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft

# Rule to define how to generate object files (%.o) from corresponding
# source files (%.c). Each .o file depends on the associated .c file and the
# libft library header file (libft/libft.h)
# -c:		Generates o. files without linking.
# -o $@:	Output file name;  '$@' is replaced with target name (the o. file).
# -$<:		Represents the first prerequisite (the c. file).
$(OBJS):	%.o: %.c libft/libft.h
	$(CC) $(CFLAGS) -c -o $@ $<

# Build libft library by calling make in the libft directory (-C changes directory).
# This target will be executed if libft.a is missing or if any of the
# .c files in the libft directory are modified.
libft/libft.a: $(wildcard libft/*.c) libft/libft.h
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJS) libft/libft.a

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
