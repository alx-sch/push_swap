# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 19:39:15 by aschenk           #+#    #+#              #
#    Updated: 2024/02/13 10:23:43 by aschenk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap
CC =		cc
CFLAGS =	-Wall -Wextra -Werror -Iinclude
SRCS =		$(wildcard src/*.c)
OBJS =		$(SRCS:src/%.c=obj/%.o)

TOTAL_SRCS := $(words $(SRCS))
SRC_NUM := 0

# Target 'all' is the default target, building program specified by $(NAME).
all:	$(NAME)

# Target $(NAME) depends on object files $(OBJS) and libft library.
$(NAME):	$(OBJS) obj/libft/libft.a
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Lobj/libft -lft
	@echo "$(NAME) successfully built."

# Rule to define how to generate object files (%.o) from corresponding
# source files (%.c). Each .o file depends on the associated .c file and the
# push_swap header file (include/push_swap.h)
# -c:		Generates o. files without linking.
# -o $@:	Output file name;  '$@' is replaced with target name (the o. file).
# -$<:		Represents the first prerequisite (the c. file).
obj/%.o: src/%.c include/push_swap.h
	@mkdir -p $(@D)
	@$(eval SRC_NUM := $(shell expr $(SRC_NUM) + 1))
	@$(eval PERCENT := $(shell printf "%.0f" $(shell echo "scale=4; $(SRC_NUM) / $(TOTAL_SRCS) * 100" | bc)))
	@printf "\rBuilding $(NAME): ["
	@$(eval PROGRESS := $(shell expr $(PERCENT) / 5))
	@printf "%0.s#" $(shell seq 1 $(PROGRESS)) # Printing "=" to represent progress
	@if [ $(PERCENT) -lt 100 ]; then printf "%0.s-" $(shell seq 1 $(shell expr 20 - $(PROGRESS))); fi
	@printf "] %d%%  " $(PERCENT)
	@$(CC) $(CFLAGS) -c -o $@ $<

# Build the libft library by calling make in the src/libft directory
# (-C changes directory). This target will be executed if libft.a is missing or
# if any of the .c files in the src/libft directory are modified.
obj/libft/libft.a: $(wildcard src/libft/*.c) | obj/libft
	@printf "\n"
	@make -C src/libft

# Create the obj/libft directory if it doesn't exist.
obj/libft:
	@mkdir -p obj/libft

# Target to remove all generated files.
clean:
	@rm -rf obj
	@echo "Cleaned up successfully."

# Target to remove all generated files and the program executable.
fclean:	clean
	@rm -f $(NAME)
	@echo "Full cleaned up successfully."

# Target to remove all generated files, the program executable,
# and then rebuild the program.
re:	fclean all
	@echo "Project rebuilt successfully."

.PHONY: all clean fclean re
