# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 11:41:06 by aschenk           #+#    #+#              #
#    Updated: 2024/02/22 21:25:05 by aschenk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		../../obj/libft/libft.a
CC =		cc
CFLAGS =	-Wall -Wextra -Werror

# Macros
## FOR GET_NEXT_LINE()
BUFFER_SIZE ?= 42
FD_SIZE ?= 1024

SRCS :=		$(wildcard *.c) # use every .c file found
OBJS :=		$(SRCS:%.c=../../obj/libft/%.o)
HDRS := 	$(wildcard *.h)

# Define the total number of sorce files.
TOTAL_SRCS := $(words $(SRCS))
SRC_NUM := 0

# Define ANSI escape codes for colors and styles
RESET = \033[0m
BOLD = \033[1m
RED = \033[31;2m
GREEN = \033[32m
YELLOW = \033[33m

# Target 'all' is the default target, building library specified by $(NAME).
all:	$(NAME)

# Rule to compile .c files to .o files with specified macros.
# Prints progress bar.
../../obj/libft/%.o: %.c $(HDRS)
	@mkdir -p $(@D)
	@$(eval SRC_NUM := $(shell expr $(SRC_NUM) + 1))
	@$(eval PERCENT := $(shell printf "%.0f" $(shell echo "scale=4; $(SRC_NUM) / $(TOTAL_SRCS) * 100" | bc)))
	@printf "$(BOLD)\rCompiling libft: ["
	@$(eval PROGRESS := $(shell expr $(PERCENT) / 5))
	@printf "$(GREEN)%0.s#$(RESET)$(BOLD)" $(shell seq 1 $(PROGRESS))
	@if [ $(PERCENT) -lt 100 ]; then printf "%0.s-" $(shell seq 1 $(shell expr 20 - $(PROGRESS))); fi
	@printf "] "
	@if [ $(PERCENT) -eq 100 ]; then printf "$(GREEN)"; fi
	@printf "%d%% $(RESET)" $(PERCENT)
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -D FD_SIZE=$(FD_SIZE) -c $< -o $@

# Target $(NAME) depends on object files $(OBJS),
# and the 'ar rc' command creates the library.
$(NAME):	$(OBJS)
	@ar rcs $(NAME) $(OBJS)

# Target 'clean' removes object files.
clean:
	@$(eval SRC_NUM := $(words $(wildcard ../../obj/libft/*.o)))
	@rm -f $(OBJS)
	@echo "$(BOLD)$(RED)Object files cleaned."

# Target 'fclean' depends on 'clean' and removes the library as well.
fclean:	clean
	@rm -f $(NAME)
	@rm -rf ../../obj/libft
	@echo "$(BOLD)$(RED)Libft library removed.$(RESET)"
	@$(eval SRC_NUM := 0)

# Target 're' depends on 'fclean' and 'all', rebuilding the project from scratch.
re:	fclean all

# Marking rules as 'phony' to ensure that 'make' doesn't misinterpret them as files.
.PHONY: all clean fclean re
