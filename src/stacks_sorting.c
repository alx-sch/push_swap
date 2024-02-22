/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:09:00 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/22 16:35:48 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

// FILE
void		find_target_a(t_stacks *stacks);
void		calc_costs_a(t_stacks *stacks);

// stacks_init.c
void		free_stacks(t_stacks *stacks);

// stacks_utils.c
int			find_max_val(const t_stacks *stacks, char x);
size_t		find_idx(const t_stacks *stacks, const char x, int value);
t_stacks	*copy_stacks(const t_stacks *ori);

// libft
void		*ft_calloc(size_t nmemb, size_t size);

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

void	calc_costs_rr_a(t_stacks *stacks)
{
	size_t		i;
	size_t		smaller_idx;
	long long	nr_moves;

	i = 0;
	while (i < stacks->size_a)
	{
		if (i < stacks->target_a[i])
			smaller_idx = i;
		else
			smaller_idx = stacks->target_a[i];
		nr_moves = i - stacks->target_a[i];
		if (nr_moves < 0)
			nr_moves *= -1;
		nr_moves = nr_moves + smaller_idx;
		if (nr_moves < stacks->cost_a[i])
			stacks->cost_a[i] = nr_moves;
		i++;
	}
}

// static void	test(t_stacks *stacks)
// {
// 	t_stacks	*stacks_cpy;
// 	size_t		i;
// 	//int			moves_rr;
// 	//int			moves_rrr;

// 	stacks_cpy = copy_stacks(stacks);
// 	i = 0;
// 	// while (i < stacks->size_a)
// 	// {
// 	// 	moves = i - stacks_cpy->target_a[i]




// 	// 	i++;
// 	// }


// 	free_stacks(stacks_cpy);
// }

// find_max_val(stk, 'b')
// which A element to push? The cheapest!
// formula: sum ( x moves to bring 'a' on top) +
// (x moves tp bring 'target' n top)
// amount of rotations
//
void	calc_costs_a(t_stacks *stacks)
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
	calc_costs_rr_a(stacks);
}
