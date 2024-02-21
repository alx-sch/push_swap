/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:26:16 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/21 20:32:29 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

// FILE
void	check_args_init_stacks(int argc, char **argv, t_stacks *stacks);

// arg_check_2.c
int		*check_and_get_args(int argc, char **argv,
			t_stacks *stacks);

// sorting.c


// utils.c
int		count_args(int argc, char **argv);
void	exit_free_stacks(int exit_code, const char *error_message,
			t_stacks *stacks);

// libft
void	*ft_calloc(size_t nmemb, size_t size);

// sorting.c
//void	mini_sort(t_stacks *stacks, int	*array, size_t size);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

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
	stacks->target = ft_calloc(size, sizeof(int));
	if (!stacks->stack_a || !stacks->stack_b || !stacks->cost_a
		|| !stacks->cost_b || !stacks->target)
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
