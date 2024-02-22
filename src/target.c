/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:09:00 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/22 19:18:28 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// THIS FILE

#include "libft/libft.h"
#include "push_swap.h"

// FILE
void		find_target_a(t_stacks *stacks);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// stacks_utils.c
int			find_max_val(const t_stacks *stacks, char x);
size_t		find_idx(const t_stacks *stacks, const char x, int value);

// Finds a target index in 'stack B' for each element in 'stack A'. It searches
// for a target that is closest but smaller than the 'stack A' element. If no
// suitable target is found, it selects the max. value from 'stack B' as target.
void	find_target_a(t_stacks *stk)
{
	size_t	i;
	size_t	j;
	size_t	target;

	i = 0;
	while (i < stk->size_a)
	{
		target = SIZE_MAX;
		j = 0;
		while (j < stk->size_b)
		{
			if (stk->stack_b[j] < stk->stack_a[i]
				&& (target == SIZE_MAX
					|| stk->stack_b[j] > stk->stack_b[target]))
				target = j;
			j++;
		}
		if (target == SIZE_MAX)
			stk->target_a[i] = find_idx(stk, 'b', find_max_val(stk, 'b'));
		else
			stk->target_a[i] = target;
		i++;
	}
}
