/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:36:50 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/22 16:37:29 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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