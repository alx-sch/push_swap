/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:26:16 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/21 23:54:16 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

// FILE
void	check_args_init_stacks(int argc, char **argv, t_stacks *stacks);
void	exit_free_stacks(int exit_code, char *error_message, t_stacks *stacks);
int		find_max_val(const t_stacks *stacks, char x);

// arg_check_2.c
int		*check_and_get_args(int argc, char **argv, t_stacks *stacks);

// utils.c
int		count_args(int argc, char **argv);

// libft
void	*ft_calloc(size_t nmemb, size_t size);

// sorting.c
//void	mini_sort(t_stacks *stacks, int	*array, size_t size);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// Frees memory for a t_stacks structure including its members.
// Prints error message and terminates program.
// Exit code retrievable via 'echo $?' in terminal.
void	exit_free_stacks(int exit_code, char *error_message, t_stacks *stacks)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks->target_a);
	free(stacks->target_b);
	free(stacks->cost_a);
	free(stacks->cost_b);
	free(stacks);
	ft_printf("%s", error_message);
	exit(exit_code);
}


// Initializes the t_stacks structure with appropriate memory allocation and
// copies elements from the provided int array into stack_a.
static void	init_stacks(t_stacks *stacks, int *stack_a, size_t size)
{
	size_t	i;

	i = 0;
	stacks->size_a = size;
	stacks->size_b = 0;
	stacks->stack_a = ft_calloc(size, sizeof(int));
	stacks->stack_b = ft_calloc(size, sizeof(int));
	stacks->cost_a = ft_calloc(size, sizeof(int));
	stacks->cost_b = ft_calloc(size, sizeof(int));
	stacks->target_a = ft_calloc(size, sizeof(int));
	stacks->target_b = ft_calloc(size, sizeof(int));
	if (!stacks->stack_a || !stacks->stack_b || !stacks->cost_a
		|| !stacks->cost_b || !stacks->target_a || !stacks->target_b)
		exit_free_stacks(EXIT_MALLOC_FAILURE, "Error\n", stacks);
	while (i < size)
	{
		stacks->stack_a[i] = stack_a[i];
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

// Returns the maximum value in the specified stack.
// Parameters:
//	- stacks: Pointer to the t_stacks structure containing the stack data.
//	- x: Specifies the stack to search ('a' for stack_a,
//		 'b' (or anything else) for stack_b).
int	find_max_val(const t_stacks *stacks, char x)
{
	int		max;
	size_t	i;
	int		*stack_x;
	size_t	size_x;

	max = INT_MIN;
	i = 0;
	if (x == 'a')
	{
		stack_x = stacks->stack_a;
		size_x = stacks->size_a;
	}
	else
	{
		stack_x = stacks->stack_b;
		size_x = stacks->size_b;
	}
	while (i < size_x)
	{
		if (stack_x[i] > max)
			max = stack_x[i];
		i++;
	}
	return (max);
}

size_t	find_index(const t_stacks *stacks, char x, int value)
{
	size_t	i;
	int		*stack_x;
	size_t	size_x;

	i = 0;
	if (x == 'a')
	{
		stack_x = stacks->stack_a;
		size_x = stacks->size_a;
	}
	else
	{
		stack_x = stacks->stack_b;
		size_x = stacks->size_b;
	}
	while (i < size_x)
	{
		if (stack_x[i] == value)
			return (i);
		i++;
	}
	return (9999);
}
