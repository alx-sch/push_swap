# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 19:39:15 by aschenk           #+#    #+#              #
#    Updated: 2024/02/22 21:23:39 by aschenk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap

SRCS :=		$(wildcard src/*.c)
OBJS :=		$(SRCS:src/%.c=obj/%.o)
HDRS := 	$(wildcard include/*.h)

LIBFT_DIR =	src/libft
LIBFT =		obj/libft/libft.a

CC =		cc
CFLAGS =	-Wall -Wextra -Werror -Iinclude
LIBS = 		-Lobj/libft -lft

TOTAL_SRCS := $(words $(SRCS))
SRC_NUM := 0

# Define ANSI escape codes for colors and styles
RESET = \033[0m
BOLD = \033[1m
RED = \033[31;2m
GREEN = \033[32m
YELLOW = \033[33m

# Target 'all' is the default target, building program specified by $(NAME).
all:	$(NAME)

# Target $(NAME) depends on object files $(OBJS) and libft library.
$(NAME):	$(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(BOLD)$(YELLOW)\n$(NAME) successfully compiled.$(RESET)"

# Rule to define how to generate object files (%.o) from corresponding
# source files (%.c). Each .o file depends on the associated .c file and the
# push_swap header file (include/push_swap.h)
# -c:		Generates o. files without linking.
# -o $@:	Output file name;  '$@' is replaced with target name (the o. file).
# -$<:		Represents the first prerequisite (the c. file).
obj/%.o: src/%.c $(HDRS)
	@mkdir -p $(@D)
	@$(eval SRC_NUM := $(shell expr $(SRC_NUM) + 1))
	@$(eval PERCENT := $(shell printf "%.0f" $(shell echo "scale=4; $(SRC_NUM) / $(TOTAL_SRCS) * 100" | bc)))
	@printf "$(BOLD)\rCompiling $(NAME): ["
	@$(eval PROGRESS := $(shell expr $(PERCENT) / 5))
	@printf "$(GREEN)%0.s#$(RESET)$(BOLD)" $(shell seq 1 $(PROGRESS))
	@if [ $(PERCENT) -lt 100 ]; then printf "%0.s-" $(shell seq 1 $(shell expr 20 - $(PROGRESS))); fi
	@printf "] "
	@if [ $(PERCENT) -eq 100 ]; then printf "$(GREEN)"; fi
	@printf "%d%% $(RESET)" $(PERCENT)
	@$(CC) $(CFLAGS) -c -o $@ $<

# Build the libft library by calling make in the src/libft directory
# (-C changes directory). This target will be executed if libft.a is missing or
# if any of the .c files in the src/libft directory are modified.
$(LIBFT): $(wildcard $(LIBFT_DIR)/*.c) $(wildcard $(LIBFT_DIR)/*.h)
	@mkdir -p obj/libft
	@echo ""
	@make -s -C $(LIBFT_DIR)

# Target to remove all generated files.
clean:
	@rm -rf obj
	@echo "$(BOLD)$(RED)Object files and libft.a removed.$(RESET)"

# Target to remove all generated files and the program executable.
fclean:	clean
	@rm -f $(NAME)
	@echo "$(BOLD)$(RED)$(NAME) removed.$(RESET)"

# Target to remove all generated files, the program executable,
# and then rebuild the program.
re:	fclean all

.PHONY: all clean fclean re
