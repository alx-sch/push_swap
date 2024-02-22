/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:36:50 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/22 19:16:55 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// THIS FILE

#include "libft/libft.h"
#include "push_swap.h"

// FILE
void	calc_cost_a(t_stacks *stacks);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// single r depending on median
static void	calc_costs_r_a(t_stacks *stacks)
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
			stacks->cost_a[i] = i;
		else
			stacks->cost_a[i] = stacks->size_a - i;
		if (stacks->target_a[i] < median_b)
			stacks->cost_a[i] += stacks->target_a[i];
		else
			stacks->cost_a[i] += stacks->size_b - stacks->target_a[i];
		i++;
	}
}

// rr push up
// rr_to_top -> moves that are rrr
// |i - stacks->target[i]| -> moves that are single r (ra or rb)
static void	calc_costs_rr_a(t_stacks *s)
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
		if (nr_moves < s->cost_a[i])
		{
			s->cost_a[i] = nr_moves;
			s->rr_a[i] = 1;
		}
		i++;
	}
}

// rrr push down
// rrr_to_top -> moves that are rrr + final single rr (rra or rrb)
static void	calc_costs_rrr_a(t_stacks *s)
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
		if (nr_moves < s->cost_a[i])
		{
			s->cost_a[i] = nr_moves;
			s->rr_a[i] = 0;
			s->rrr_a[i] = 1;
		}
		i++;
	}
}

void	calc_cost_a(t_stacks *stacks)
{
	calc_costs_r_a(stacks);
	calc_costs_rr_a(stacks);
	calc_costs_rrr_a(stacks);
}
