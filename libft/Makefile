# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 11:41:06 by aschenk           #+#    #+#              #
#    Updated: 2024/01/27 17:17:17 by aschenk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a
CC =			cc
CFLAGS =		-Wall -Wextra -Werror

# Macros
## FOR GET_NEXT_LINE()
BUFFER_SIZE ?= 42
FD_SIZE ?= 1024

SRCS =			$(wildcard *.c) # use every .c file found
OBJS =			${SRCS:.c=.o}

# Target 'all' is the default target, building library specified by $(NAME).
all:	$(NAME)

# Target $(NAME) depends on object files $(OBJS),
# and the 'ar rc' command creates the library.
$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

# Target 'clean' removes object files.
clean:
	rm -f $(OBJS)

# Target 'fclean' depends on 'clean' and removes the library as well.
fclean:	clean
	rm -f $(NAME)

# Target 're' depends on 'fclean' and 'all', rebuilding the project from scratch.
re:	fclean all

# Rule to compile .c files to .o files with specified macros.
%.o: %.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -D FD_SIZE=$(FD_SIZE) -c $< -o $@

# Marking rules as 'phony' to ensure that 'make' doesn't misinterpret them as files.
.PHONY: all clean fclean re
