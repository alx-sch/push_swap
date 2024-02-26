/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:26:16 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/26 11:16:58 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This file contains functions to initalize and free the 't_stacks' structure,
// containing stack 'A' and 'B' along with additional information (the struct's
// details are defined in the header file; check there for more info).

#include "libft/libft.h"
#include "push_swap.h"

// FILE
void	exit_free_stacks(int exit_code, const char *err_msg, t_stacks *stacks);
void	check_args_init_stacks(int argc, char **argv, t_stacks *stacks);

// arg_check_2.c
int		*check_and_get_args(int argc, char **argv, t_stacks *stacks);

// arg_utils.c
int		count_args(int argc, char **argv);

// libft
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_printf(const char *format, ...);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// Frees memory for a t_stacks structure including its members.
// Prints error message and terminates program.
// -> Exit code retrievable via 'echo $?' in terminal.
void	exit_free_stacks(int exit_code, const char *err_msg, t_stacks *s)
{
	free(s->stack_a);
	free(s->stack_b);
	free(s->target_a);
	free(s->cost);
	free(s->rr);
	free(s->rrr);
	free(s);
	ft_printf("%s", err_msg);
	exit(exit_code);
}

// Initializes the t_stacks structure with appropriate memory allocation and
// copies elements from the provided int array into stack_a.
static void	init_stacks(t_stacks *s, int *stack_a, size_t size)
{
	size_t	i;

	i = 0;
	s->size_a = size;
	s->size_b = 0;
	s->stack_a = ft_calloc(size, sizeof(int));
	s->stack_b = ft_calloc(size, sizeof(int));
	s->cost = ft_calloc(size, sizeof(int));
	s->target_a = ft_calloc(size, sizeof(size_t));
	s->target_b = SIZE_MAX;
	s->rr = ft_calloc(size, sizeof(int));
	s->rrr = ft_calloc(size, sizeof(int));
	if (!s->stack_a || !s->stack_b || !s->cost || !s->target_a || !s->rr
		|| !s->rrr)
		exit_free_stacks(EXIT_MALLOC_FAILURE, "Error\n", s);
	while (i < size)
	{
		s->stack_a[i] = stack_a[i];
		i++;
	}
	free(stack_a);
}

// First validates if the command-line arguments represent valid integers.
// Then checks if the provided arguments are already sorted. If so, the
// program exits successfully. Otherwise, the 'stacks' structure is initialized.
void	check_args_init_stacks(int argc, char **argv, t_stacks *stacks)
{
	int		*stack_a;
	size_t	size_stack_a;

	stack_a = check_and_get_args(argc, argv, stacks);
	size_stack_a = count_args(argc, argv);
	init_stacks(stacks, stack_a, size_stack_a);
}
