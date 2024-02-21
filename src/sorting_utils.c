/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:09:00 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/22 00:18:11 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

// FILE
void	find_target_a(t_stacks *stacks);

// stacks.c
int		find_max_val(const t_stacks *stacks, char x);
size_t	find_index(const t_stacks *stacks, char x, int value);

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
			stk->target_a[i] = find_index(stk, 'b', find_max_val(stk, 'b'));
		else
			stk->target_a[i] = target;
		i++;
	}
}

// find_max_val(stk, 'b')
// which A element to push? The cheapest!
// formula: sum ( x moves to bring 'a' on top) +
// (x moves tp bring 'target' n top)
// void	cost_analysis(t_stacks *stacks)
// {
// 	size_t	i;

// 	i = 0;
// 	while(i < stacks->size_a)
// 	{
// 		stacks->cost_a[i] = i;
// 		if(i >= stack->size_a / 2)
// 			stacks->cost_a[i] = stacks->size_a - i;
// 		if(stacks->target_a >= stacks->size_b / 2)

// 	}
