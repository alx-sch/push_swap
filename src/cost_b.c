/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:36:50 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/23 15:11:16 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// THIS FILE

#include "libft/libft.h"
#include "push_swap.h"

// FILE
void	calc_cost_b(t_stacks *stacks);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// single r depending on median
static void	calc_costs_r_b(t_stacks *stacks)
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
	while (i < stacks->size_b)
	{
		if (i < median_b)
			stacks->cost_b[i] = i;
		else
			stacks->cost_b[i] = stacks->size_b - i;
		if (stacks->target_b[i] < median_a)
			stacks->cost_b[i] += stacks->target_b[i];
		else
			stacks->cost_b[i] += stacks->size_a - stacks->target_b[i];
		i++;
	}
}

// rr push up
// rr_to_top -> moves that are rrr
// |i - stacks->target[i]| -> moves that are single r (ra or rb)
static void	calc_costs_rr_b(t_stacks *s)
{
	size_t		i;
	size_t		rr_to_top;
	long long	rest_r_to_top;
	long long	nr_moves;

	i = 0;
	while (i < s->size_b)
	{
		if (i < s->target_b[i])
			rr_to_top = i;
		else
			rr_to_top = s->target_b[i];
		rest_r_to_top = i - s->target_b[i];
		if (rest_r_to_top < 0)
			rest_r_to_top *= -1;
		nr_moves = rr_to_top + rest_r_to_top;
		if (nr_moves < s->cost_b[i])
		{
			s->cost_b[i] = nr_moves;
			s->rr_b[i] = 1;
		}
		i++;
	}
}

// rrr push down
// rrr_to_top -> moves that are rrr + final single rr (rra or rrb)
static void	calc_costs_rrr_b(t_stacks *s)
{
	size_t		i;
	size_t		rrr_to_top;
	long long	rest_rr_to_top;
	long long	nr_moves;

	i = 0;
	while (i < s->size_b)
	{
		if ((s->size_b - i) < (s->size_a - s->target_b[i]))
			rrr_to_top = s->size_b - i;
		else
			rrr_to_top = s->size_a - s->target_b[i];
		rest_rr_to_top = (s->size_b - i) - (s->size_a - s->target_b[i]);
		if (rest_rr_to_top < 0)
			rest_rr_to_top *= -1;
		nr_moves = rrr_to_top + rest_rr_to_top;
		if (nr_moves < s->cost_b[i])
		{
			s->cost_b[i] = nr_moves;
			s->rr_b[i] = 0;
			s->rrr_b[i] = 1;
		}
		i++;
	}
}

// resets 'best strategy' to 0 before checking
void	calc_cost_b(t_stacks *stacks)
{
	size_t	i;

	i = 0;
	while (i < stacks->size_a)
	{
		stacks->rr_b[i] = 0;
		stacks->rrr_b[i] = 0;
		i++;
	}
	calc_costs_r_b(stacks);
	calc_costs_rr_b(stacks);
	calc_costs_rrr_b(stacks);
}
