/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:20:37 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/21 20:13:58 by aschenk          ###   ########.fr       */
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

// utils.c
void	exit_free_stacks(int exit_code, const char *error_message,
			t_stacks *stacks);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// Checks if 'stack a' is sorted from smallest to largest.
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

// Sorts 'stack a' with a size of three in ascending order.
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

// For each element in stack a, find a target in stack b
// target for a in b-> closest to but smaller than a
// if can't find target (no smaller value) -> target node is max in stack b
// void	set_target_a(t_stacks *stacks)
// {
// 	size_t	i;
// 	size_t	b_idx;
// 	int		target;

// 	i = 0;
// 	best_match = INT_MIN;
// 	while (a_index < stacks->size_a)
// 	{
// 		target = INT_MIN; // assign smallest INT as closest smaller
// 		// ?? t_stack_node *target_node = NULL;
// 		j = 0;
// 		while (b_index < stacks->size_b)
// 		{
// 			if (stacks->stack_b[j] < stacks->stack_a[i]
// 				&& stacks->stack_b[j] > best_match_index)
// 				target = stacks->stack_b[j];
// 			j++;
// 		}
// 		if (best_match_index == LONG_MIN)
//             a->target_node[i] = find_max(b->stack_a, b->size_a);
//         else
//             a->target_node[i] = target_node;

//         ++i;
//     }
// }





// void	current_index(t_stack *stacks, char x)
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

// void	sort_more_than_three(t_stacks *stacks);
// {
// 	if (stacks->size_a > 3)
// 		pb(stacks);
// 	if (stacks->size_a > 3)
// 		pb(stacks);
// 	while (stacks->size_a > 3)
// 	{


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
