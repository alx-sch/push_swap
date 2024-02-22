/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:20:21 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/22 20:48:11 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// THIS FILE

#include "libft/libft.h"
#include "push_swap.h"

// FILE

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

size_t	find_cheapest(const t_stacks *stacks, const char x)
{
	size_t	i;
	size_t	idx_cheapest;
	int		*cost_x;
	size_t	size_x;

	i = 0;
	idx_cheapest = 0;
	if (x == 'a')
	{
		cost_x = stacks->cost_a;
		size_x = stacks->size_a;
	}
	else
	{
		cost_x = stacks->cost_b;
		size_x = stacks->size_b;
	}
	while (i < size_x)
	{
		if (cost_x[i] < cost_x[idx_cheapest])
			idx_cheapest = i;
		i++;
	}
	return (idx_cheapest);
}
