/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:20:37 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/21 21:58:42 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

// FILE
bool	is_stack_sorted(const t_stacks *stacks);
void	sort_three(t_stacks *stacks);

// operations_a.c
void	sa(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rra(t_stacks *stacks);

// operations_b.c
void	pb(t_stacks *stacks);

// utils.c
void	exit_free_stacks(int exit_code, char *error_message, t_stacks *stacks);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// Checks if 'stack A' is sorted from smallest to largest.
// A stack with only one element is also considered 'sorted'.
bool	is_stack_sorted(const t_stacks *stacks)
{
	size_t	i;

	i = 0;
	while (i < stacks->size_a - 1)
	{
		if (stacks->stack_a[i] > stacks->stack_a[i + 1])
			return (false);
		i++;
	}
	return (true);
}

// Returns the maximum value in the specified stack.
// Parameters:
//	- stacks: Pointer to the t_stacks structure containing the stack data.
//	- x: Specifies the stack to search ('a' for stack_a,
//		 'b' (or anything else) for stack_b).
static int	find_max_in_stack(const t_stacks *stacks, char x)
{
	int			max;
	size_t		i;
	int			*stack_x;
	size_t		size_x;

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

// Sorts 'stack A' with a size of three in ascending order.
// First, it rotates the largest element to the bottom if it's not already in
// that position. Then, it swaps the top two elements, if top > middle.
void	sort_three(t_stacks *stacks)
{
	int	max_value;

	max_value = find_max_in_stack(stacks, 'a');
	if (stacks->stack_a[0] == max_value)
		ra(stacks);
	else if (stacks->stack_a[1] == max_value)
		rra(stacks);
	if (stacks->stack_a[0] > stacks->stack_a[1])
		sa(stacks);
}

// Finds a target in 'stack B' for each element in 'stack A'. It searches for a
// target that is closest but smaller than the 'stack A' element. If no suitable
// target is found, it selects the max. value from 'stack B' as the target.
void	set_target_a(t_stacks *stacks)
{
	size_t	i;
	size_t	j;
	int		target;

	i = 0;
	while (i < stacks->size_a)
	{
		target = INT_MIN;
		j = 0;
		while (j < stacks->size_b)
		{
			if (stacks->stack_b[j] < stacks->stack_a[i]
				&& stacks->stack_b[j] > target)
				target = stacks->stack_b[j];
			j++;
		}
		if (target == INT_MIN)
			stacks->target[i] = find_max_in_stack(stacks, 'b');
		else
			stacks->target[i] = target;
		i++;
	}
}

void	sort_more_than_three(t_stacks *stacks)
{
	if (stacks->size_a > 3)
		pb(stacks);
	if (stacks->size_a > 3)
		pb(stacks);
	set_target_a(stacks);
	//while (stacks->size_a > 3)
}




//void	current_index(t_stack *stacks, char x)
// {
// 	int	*stack;
// 	int	median;

// 	if (x == a)
// 	{
// 		stack = stacks->stack_a;
// 		median = stacks->size_a / 2;
// 	}
// 	else if (x == b)
// 	{
// 		stack = stacks->stack_a;
// 		median = stacks->size_b / 2;
// 	}
// 	while ()
// }


// 	}
// 	sort_three(stacks);

// }


// {
// 	bool	exit_success;

// 	exit_success = false;
// 	if (is_sorted(array, size))
// 		exit_success = true;
// 	if ()


// }


// void	small_sort(t_stacks *stacks)
// {
// 	bool	exit_success;

// 	exit_success = false;
// 	if (is_sorted(stacks))
// 		exit_success = true;
// 	else if (stacks->size_a == 2)
// 	{
// 		sa(stacks);
// 		exit_success = true;
// 	}
// 	else if (stacks->size_a == 3)
// 	{
// 		if (stacks->stack_a[2] == find_max_in_stack_a(stacks))
// 		{
// 			sa(stacks);
// 			exit_success = true;
// 		}



// 	}
// 	if (exit_success)
// 	{
// 		free(array);
// 		exit_free_stacks(EXIT_SUCCESS, "", stacks);
// 	}
// }
