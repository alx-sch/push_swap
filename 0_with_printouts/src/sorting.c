/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:20:37 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/26 17:22:00 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This file implements functions for sorting the integer stack.

#include "libft/libft.h"
#include "push_swap.h"

// FILE
bool	is_sorted(const t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_more_than_three(t_stacks *stacks);

// stacks_moves.c
void	move_cheapest_to_top(t_stacks *stacks);
void	move_b_target_to_top(t_stacks *stacks);
void	r_to_top(t_stacks *stacks, const size_t element_to_move);

// stacks_utils.c
int		find_max_val(const t_stacks *stacks, const char x);
int		find_min_val(const t_stacks *stacks, const char x);
size_t	find_idx(const t_stacks *stacks, const char x, int value);
void	print_stacks(t_stacks *stacks);

// moves_a.c
void	sa(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rra(t_stacks *stacks);

// moves_b.c
void	pb(t_stacks *stacks);


//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// Checks if stack 'A' is sorted in ascending order.
bool	is_sorted(const t_stacks *stacks)
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

// Sorts 'stack A' with a size of three in ascending order.
// First, it rotates the largest element to the bottom if it's not already in
// that position. Then, it swaps the top two elements, if top > middle.
void	sort_three(t_stacks *stacks)
{
	int	max_value;

	max_value = find_max_val(stacks, 'a');
	ft_printf("\n-- Sorting three in 'A' in ascending order --\n\n");
	if (stacks->stack_a[0] == max_value)
		ra(stacks);
	else if (stacks->stack_a[1] == max_value)
		rra(stacks);
	if (stacks->stack_a[0] > stacks->stack_a[1])
		sa(stacks);
}

// Sorts stack 'A' is ascending order by moving the stack's min. value
// to the top using 'ra' or 'rra'.
static void	sort_stack(t_stacks *stacks)
{
	size_t	element_to_move;

	element_to_move = find_idx(stacks, 'a', find_min_val(stacks, 'a'));
	ft_printf("\n-- Rotating min. value in 'A' to top --\n\n");
	r_to_top(stacks, element_to_move);
}

// This the main sorting algorithm for 'push_swap'.
// Step 1: Push all but three elements from stack 'A' to stack 'B' in descending
// order. This is achieved by repeatedly moving elements to 'B' in the cheapest
// possible way.
// Step 2: Sort the remaining three elements in stack 'A' in ascending order.
// Step 3: Move all elements from stack 'B' back to stack 'A', resulting in an
// ascending order.
// Step 4: Sort stack 'A' by rotating until the smallest value is at the top.
void	sort_more_than_three(t_stacks *stacks)
{
	ft_printf("\n-- Initial pushing of top 'A' elements to 'B' --\n\n");
	if (stacks->size_a > 3)
		pb(stacks);
	if (stacks->size_a > 3)
		pb(stacks);
	print_stacks(stacks);
	while (stacks->size_a > 3)
	{
		move_cheapest_to_top(stacks);
		ft_printf("\n-- Pushing 'A' to 'B' --\n\n");
		pb(stacks);
	}
	sort_three(stacks);
	while (stacks->size_b)
	{
		move_b_target_to_top(stacks);
		ft_printf("\n-- Pushing 'B' to 'A' --\n\n");
		pa(stacks);
	}
	sort_stack(stacks);
}
