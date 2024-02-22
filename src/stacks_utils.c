/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:26:16 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/22 20:27:26 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// THIS FILE

#include "libft/libft.h"
#include "push_swap.h"

// FILE
int			find_max_val(const t_stacks *stacks, const char x);
size_t		find_idx(const t_stacks *stacks, const char x, int value);

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

// static void	copy_stack_entries(const t_stacks *ori, t_stacks *copy)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < ori->size_a)
// 	{
// 		copy->target_a[i] = ori->target_a[i];
// 		copy->cost_a[i] = ori->cost_a[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (i < ori->size_b)
// 	{
// 		copy->target_b[i] = ori->target_b[i];
// 		copy->cost_b[i] = ori->cost_b[i];
// 		i++;
// 	}
// }

// t_stacks	*copy_stacks(const t_stacks *ori)
// {
// 	t_stacks	*copy;
// 	size_t		i;

// 	copy = ft_calloc(1, sizeof(t_stacks));
// 	if (!copy)
// 	{
// 		ft_printf("Error\n");
// 		exit(EXIT_MALLOC_FAILURE);
// 	}
// 	copy->size_a = ori->size_a;
// 	copy->size_b = ori->size_b;
// 	copy->target_a = ft_calloc(copy->size_a, sizeof(size_t));
// 	copy->target_b = ft_calloc(copy->size_b, sizeof(size_t));
// 	copy->cost_a = ft_calloc(copy->size_a, sizeof(int));
// 	copy->cost_b = ft_calloc(copy->size_b, sizeof(int));
// 	if (!copy->target_a || !copy->target_b || !copy->cost_a || !copy->cost_b)
// 		exit_free_stacks(EXIT_MALLOC_FAILURE, "Error\n", copy);
// 	i = 0;
// 	copy_stack_entries(ori, copy);
// 	return (copy);
// }
