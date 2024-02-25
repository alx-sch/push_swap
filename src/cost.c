/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:36:50 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/25 19:59:50 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This file implements functions to calculate the 'cost' (= number of moves
// needed to bring each stack 'A' element and its target to the top of their
// stacks). It also contains a function to determine the 'cheapest' stack 'A'
// element (= element in stack 'A' that needs the least number of moves to bring
// it and its target to the top).

#include "libft/libft.h"
#include "push_swap.h"

// FILE
void	calc_cost(t_stacks *stacks);
size_t	find_cheapest(const t_stacks *stacks);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// Calculates the 'cost' for each element in stack 'A' when only single rotation
// moves are used (ra, rra, rb, rrb). It first determines the cost required to
// bring the stack 'A' element to the top position, and then adds the cost
// required to bring the respective target element in stack 'B' to the top.
static void	calc_costs_r(t_stacks *stacks)
{
	size_t	i;
	size_t	median_a;
	size_t	median_b;

	i = 0;
	median_a = stacks->size_a / 2;
	median_b = stacks->size_b / 2;
	if (stacks->size_a % 2 == 1)
		median_a += 1;
	if (stacks->size_b % 2 == 1)
		median_b += 1;
	while (i < stacks->size_a)
	{
		if (i < median_a)
			stacks->cost[i] = i;
		else
			stacks->cost[i] = stacks->size_a - i;
		if (stacks->target_a[i] < median_b)
			stacks->cost[i] += stacks->target_a[i];
		else
			stacks->cost[i] += stacks->size_b - stacks->target_a[i];
		i++;
	}
}

// Calculates the 'cost' for each element in stack 'A' when 'rr' moves are used
// in conjunction with 'ra' or 'rb' moves if necessary.
// It first determines the cost required to bring either the stack 'A' element
// or its target to the top using 'rr' moves. Then, it determines the cost
// required to bring the other element to the top using 'ra' or 'rb'.
// If this combined cost is lower than the currently saved cost for the element,
// it updates the cost and raises the 'rr' flag.
static void	calc_costs_rr(t_stacks *s)
{
	size_t		i;
	size_t		rr_to_top;
	long long	rest_r_to_top;
	long long	nr_moves;

	i = 0;
	while (i < s->size_a)
	{
		if (i < s->target_a[i])
			rr_to_top = i;
		else
			rr_to_top = s->target_a[i];
		rest_r_to_top = i - s->target_a[i];
		if (rest_r_to_top < 0)
			rest_r_to_top *= -1;
		nr_moves = rr_to_top + rest_r_to_top;
		if (nr_moves < s->cost[i])
		{
			s->cost[i] = nr_moves;
			s->rr[i] = 1;
		}
		i++;
	}
}

// Calculates the 'cost' for each element in stack 'A' when 'rrr' moves are used
// in conjunction with 'rra' or 'rrb' moves if necessary.
// It first determines the cost required to bring either the stack 'A' element
// or its target to the top using 'rrr' moves. Then, it determines the cost
// required to bring the other element to the top using 'rra' or 'rrb'.
// If this combined cost is lower than the currently saved cost for the element,
// it updates the cost and raises the 'rrr' flag.
static void	calc_costs_rrr(t_stacks *s)
{
	size_t		i;
	size_t		rrr_to_top;
	long long	rest_rr_to_top;
	long long	nr_moves;

	i = 0;
	while (i < s->size_a)
	{
		if ((s->size_a - i) < (s->size_b - s->target_a[i]))
			rrr_to_top = s->size_a - i;
		else
			rrr_to_top = s->size_b - s->target_a[i];
		rest_rr_to_top = (s->size_a - i) - (s->size_b - s->target_a[i]);
		if (rest_rr_to_top < 0)
			rest_rr_to_top *= -1;
		nr_moves = rrr_to_top + rest_rr_to_top;
		if (nr_moves < s->cost[i])
		{
			s->cost[i] = nr_moves;
			s->rr[i] = 0;
			s->rrr[i] = 1;
		}
		i++;
	}
}

// Calculates the cost, finding the cheapest solution for each
// stack 'A' element, either by using 'single rotations' only (1),
// using 'rr' moves (2) or using 'rrr' moves (3).
void	calc_cost(t_stacks *stacks)
{
	size_t	i;

	i = 0;
	while (i < stacks->size_a)
	{
		stacks->rr[i] = 0;
		stacks->rrr[i] = 0;
		i++;
	}
	calc_costs_r(stacks);
	calc_costs_rr(stacks);
	calc_costs_rrr(stacks);
}

// Finds the cheapest element in stack 'A'.
size_t	find_cheapest(const t_stacks *stacks)
{
	size_t	i;
	size_t	idx_cheapest;

	i = 0;
	idx_cheapest = 0;
	while (i < stacks->size_a)
	{
		if (stacks->cost[i] < stacks->cost[idx_cheapest])
			idx_cheapest = i;
		i++;
	}
	return (idx_cheapest);
}
