/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:09:00 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/25 12:58:26 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// THIS FILE

#include "libft/libft.h"
#include "push_swap.h"

// FILE
void		find_target_a(t_stacks *stacks);
void		find_target_b(t_stacks *stacks);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// stacks_utils.c
int			find_max_val(const t_stacks *stacks, char x);
int			find_min_val(const t_stacks *stacks, const char x);
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
		//ft_printf("\nFinding Target for A[%d]: %d\n", i, stk->stack_a[i]);
		while (j < stk->size_b)
		{
			if (stk->stack_b[j] < stk->stack_a[i]
				&& (target == SIZE_MAX
					|| stk->stack_b[j] > stk->stack_b[target]))
				target = j;
			//ft_printf("B[%d]: %d > %d; target: B[%d]\n",
			//	j, stk->stack_a[i], stk->stack_b[j], target);
			j++;
		}
		if (target == SIZE_MAX)
			stk->target_a[i] = find_idx(stk, 'b', find_max_val(stk, 'b'));
		else
			stk->target_a[i] = target;
		//ft_printf("Target found: B[%d]: %d\n",
		//	stk->target_a[i], stk->stack_b[stk->target_a[i]]);
		i++;
	}
}

// Finds a target index in 'stack A' for each element in 'stack B'. It searches
// for a target that is closest but bigger than the 'stack B' element. If no
// suitable target is found, it selects the min. value from 'stack A' as target.
void	find_target_b(t_stacks *stk)
{
	size_t	i;
	size_t	j;
	size_t	target;

	i = 0;
	while (i < stk->size_b)
	{
		target = SIZE_MAX;
		j = 0;
		//ft_printf("\nFinding Target for B[%d]: %d\n", i, stk->stack_b[i]);
		while (j < stk->size_a)
		{
			if (stk->stack_a[j] > stk->stack_b[i]
				&& (target == SIZE_MAX
					|| stk->stack_a[j] < stk->stack_a[target]))
				target = j;
			//ft_printf("A[%d]: %d < %d; target: A[%d]\n",
			//	j, stk->stack_b[i], stk->stack_a[j], target);
			j++;
		}
		if (target == SIZE_MAX)
			stk->target_b[i] = find_idx(stk, 'a', find_min_val(stk, 'a'));
		else
			stk->target_b[i] = target;
		//ft_printf("Target found: A[%d]: %d\n",
		//	stk->target_b[i], stk->stack_a[stk->target_b[i]]);
		i++;
	}
}
