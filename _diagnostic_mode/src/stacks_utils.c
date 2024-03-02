/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:26:16 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/26 17:38:12 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This file implements functions responsible for finding the max. and min.
// values within the stacks, as well as finding the indices of specific values.

#include "libft/libft.h"
#include "push_swap.h"

// FILE
int		find_max_val(const t_stacks *stacks, const char x);
int		find_min_val(const t_stacks *stacks, const char x);
size_t	find_idx(const t_stacks *stacks, const char x, int value);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// Returns the maximum value in the specified stack.
// Parameters:
//	- stacks: Pointer to the t_stacks structure containing the stack data.
//	- x: Specifies the stack to search ('a' for stack_a,
//		 'b' (or anything else) for stack_b).
int	find_max_val(const t_stacks *stacks, const char x)
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

// Returns the minimum value in the specified stack.
// Parameters:
//	- stacks: Pointer to the t_stacks structure containing the stack data.
//	- x: Specifies the stack to search ('a' for stack_a,
//		 'b' (or anything else) for stack_b).
int	find_min_val(const t_stacks *stacks, const char x)
{
	int		min;
	size_t	i;
	int		*stack_x;
	size_t	size_x;

	min = INT_MAX;
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
		if (stack_x[i] < min)
			min = stack_x[i];
		i++;
	}
	return (min);
}

// Returns the index of a specified value within a stack. If the value does
// not exist within the stack, 'SIZE_MAX' is returned.
// Parameters:
//	- stacks: Pointer to the t_stacks structure containing the stack data.
//	- x: Specifies the stack to search ('a' for stack_a,
//		 'b' (or anything else) for stack_b).
//	- value: Integer value to find.
size_t	find_idx(const t_stacks *stacks, const char x, int value)
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
	return (SIZE_MAX);
}

void	print_stacks(t_stacks *stacks)
{
	size_t	i;

	i = 0;
	ft_printf("\n## Structure Status ##\n\nStack A: ");
	while (i < stacks->size_a)
	{
		ft_printf("%d ", stacks->stack_a[i]);
		i++;
	}
	i = 0;
	ft_printf("\nStack B: ");
	while (i < stacks->size_b)
	{
		ft_printf("%d ", stacks->stack_b[i]);
		i++;
	}
	i = 0;
	ft_printf("\n\nTarget for A: ");
	while (i < stacks->size_a)
	{
		ft_printf("%d ", stacks->target_a[i]);
		i++;
	}
	i = 0;
	ft_printf("\nCost for A: ");
	while (i < stacks->size_a)
	{
		ft_printf("%d ", stacks->cost[i]);
		i++;
	}
	i = 0;
	ft_printf("\nRR A: ");
	while (i < stacks->size_a)
	{
		ft_printf("%d ", stacks->rr[i]);
		i++;
	}
	i = 0;
	ft_printf("\nRRR A: ");
	while (i < stacks->size_a)
	{
		ft_printf("%d ", stacks->rrr[i]);
		i++;
	}
	i = 0;
	ft_printf("\nTarget for B[0]: %d\n", stacks->target_b);
}
