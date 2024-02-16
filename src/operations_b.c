/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:42:43 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/16 16:45:29 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

//	FILE
void	sb(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rrb(t_stacks *stacks);

// libft
int		ft_printf(const char *format, ...);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// swap b
// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_stacks *stacks)
{
	int	temp;

	ft_printf("sb\n");
	if (stacks->size_b < 2)
		return ;
	temp = stacks->stack_b[1];
	stacks->stack_b[1] = stacks->stack_b[0];
	stacks->stack_b[0] = temp;
}

// push b
// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_stacks *stacks)
{
	size_t	i;

	i = stacks->size_b;
	ft_printf("pb\n");
	if (stacks->size_a == 0)
		return ;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = stacks->stack_a[0];
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->size_b++;
	stacks->size_a--;
}

// rotate b
// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_stacks *stacks)
{
	int		temp;
	size_t	i;

	i = 0;
	ft_printf("rb\n");
	if (stacks->size_b <= 1)
		return ;
	temp = stacks->stack_b[0];
	while (i < stacks->size_b - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->size_b - 1] = temp;
}

// reverse rotate b
// Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_stacks *stacks)
{
	int		temp;
	size_t	i;

	i = stacks->size_b - 1;
	ft_printf("rrb\n");
	if (stacks->size_b <= 1)
		return ;
	temp = stacks->stack_b[stacks->size_b - 1];
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = temp;
}
