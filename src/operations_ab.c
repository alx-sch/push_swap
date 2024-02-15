/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:42:43 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/15 19:12:01 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

//	FILE
void	ss(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rrr(t_stacks *stacks);

// libft
int		ft_printf(const char *format, ...);

// swap a & b at the same time
// Swap the first 2 elements at the top of both stacks.
// Do nothing if there is only one or no elements.
void	ss(t_stacks *stacks)
{
	int	temp;

	ft_printf("ss\n");
	if (stacks->size_a >= 2)
	{
		temp = stacks->stack_a[1];
		stacks->stack_a[1] = stacks->stack_a[0];
		stacks->stack_a[0] = temp;
	}
	if (stacks->size_b >= 2)
	{
		temp = stacks->stack_b[1];
		stacks->stack_b[1] = stacks->stack_b[0];
		stacks->stack_b[0] = temp;
	}
}

// rotate a & b at the same time
// Shift up all elements of both stacks by 1.
// The first elements become the last ones.
void	rr(t_stacks *stacks)
{
	int		temp;
	size_t	i;

	i = 0;
	temp = stacks->stack_a[0];
	ft_printf("rr\n");
	while (i < stacks->size_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[stacks->size_a - 1] = temp;
	i = 0;
	temp = stacks->stack_b[0];
	while (i < stacks->size_b - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->size_b - 1] = temp;
}

// reverse rotate a & b
// Shift down all elements of both stacks by 1.
// The last elements become the first ones.
void	rrr(t_stacks *stacks)
{
	int		temp;
	size_t	i;

	temp = stacks->stack_a[stacks->size_a - 1];
	i = stacks->size_a - 1;
	ft_printf("rrr\n");
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = temp;
	temp = stacks->stack_b[stacks->size_b - 1];
	i = stacks->size_b - 1;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = temp;
}
