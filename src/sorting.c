/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:20:37 by aschenk           #+#    #+#             */
/*   Updated: 2024/03/01 14:45:43 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This file implements functions for sorting the integer stack.

#include "libft/libft.h"
#include "push_swap.h"

// FILE
bool	is_sorted(const t_stacks *stacks);
bool	is_circularly_sorted(const t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_more_than_three(t_stacks *stacks);

// stacks_moves.c
void	move_cheapest_to_top(t_stacks *stacks);
void	move_b_target_to_top(t_stacks *stacks);

// stacks_utils.c
int		find_max_val(const t_stacks *stacks, const char x);
int		find_min_val(const t_stacks *stacks, const char x);
size_t	find_idx(const t_stacks *stacks, const char x, int value);

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

// Checks if stack 'A' is sorted in ascending order, when considered as
// a circular array (only rotating needed to get it 'linear' sorted).
bool	is_circularly_sorted(const t_stacks *stacks)
{
	size_t	min_index;
	size_t	i;
	size_t	size_a;

	min_index = find_idx(stacks, 'a', find_min_val(stacks, 'a'));
	i = min_index;
	size_a = stacks->size_a;
	while (i != (min_index - 1))
	{
		if (stacks->stack_a[i % size_a] > stacks->stack_a[(i + 1) % size_a])
			return (false);
		i = (i + 1) % size_a;
	}
	return (true);
}

// Sorts stack 'A' with a size of three in ascending order.
// First, it rotates the largest element to the bottom if it's not already in
// that position. Then, it swaps the top two elements, if top > middle.
void	sort_three(t_stacks *stacks)
{
	int	max_value;

	if (stacks->size_a > 3)
		return ;
	max_value = find_max_val(stacks, 'a');
	if (stacks->stack_a[0] == max_value)
		ra(stacks);
	else if (stacks->stack_a[1] == max_value)
		rra(stacks);
	if (stacks->stack_a[0] > stacks->stack_a[1])
		sa(stacks);
}

// Sorts stack 'A' is ascending order by moving the stack's min. value
// to the top using 'ra' or 'rra'.
void	sort_stack(t_stacks *stacks)
{
	int		min_value;
	size_t	idx_of_min_val;
	size_t	median_a;

	min_value = find_min_val(stacks, 'a');
	idx_of_min_val = find_idx(stacks, 'a', min_value);
	median_a = stacks->size_a / 2;
	if (stacks->size_a % 2 == 1)
		median_a += 1;
	if (idx_of_min_val < median_a)
		while (stacks->stack_a[0] != min_value)
			ra(stacks);
	else
		while (stacks->stack_a[0] != min_value)
			rra(stacks);
}

// This the main sorting algorithm for 'push_swap'.
// Step 1: Push elements from stack 'A' to stack 'B' in descending
// order until only three elements are left in stack 'A' or until stack 'A' is
// (circularly) sorted.
// This is achieved by repeatedly moving elements to 'B' in the cheapest
// possible way.
// Step 2: Sort the remaining three elements in stack 'A' in ascending order.
// Step 3: Move all elements from stack 'B' back to stack 'A', resulting in an
// ascending order.
// Step 4: Sort stack 'A' by rotating until the smallest value is at the top.
void	sort_more_than_three(t_stacks *stacks)
{
	if (stacks->size_a > 3)
		pb(stacks);
	if (is_circularly_sorted(stacks))
		sort_stack(stacks);
	if (stacks->size_a > 3 && !(is_sorted(stacks)))
		pb(stacks);
	if (is_circularly_sorted(stacks))
		sort_stack(stacks);
	while (stacks->size_a > 3 && !(is_sorted(stacks)))
	{
		move_cheapest_to_top(stacks);
		pb(stacks);
		if (is_circularly_sorted(stacks))
			sort_stack(stacks);
	}
	sort_three(stacks);
	while (stacks->size_b)
	{
		move_b_target_to_top(stacks);
		pa(stacks);
	}
	sort_stack(stacks);
}
