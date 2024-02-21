/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:42:43 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/21 22:00:03 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

//	FILE
void	sa(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rra(t_stacks *stacks);

// libft
int		ft_printf(const char *format, ...);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// Swap A
// Swap the first 2 elements at the top of 'stack A'.
// Do nothing if there is only one or no elements.
void	sa(t_stacks *stacks)
{
	int	temp;

	ft_printf("sa\n");
	if (stacks->size_a < 2)
		return ;
	temp = stacks->stack_a[1];
	stacks->stack_a[1] = stacks->stack_a[0];
	stacks->stack_a[0] = temp;
}

// Push A
// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_stacks *stacks)
{
	size_t	i;

	ft_printf("pa\n");
	if (stacks->size_b == 0)
		return ;
	i = stacks->size_a;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = stacks->stack_b[0];
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->size_a++;
	stacks->size_b--;
}

// Rotate A
// Shift up all elements of 'stack A' by 1.
// The first element becomes the last one.
void	ra(t_stacks *stacks)
{
	int		temp;
	size_t	i;

	ft_printf("ra\n");
	if (stacks->size_a <= 1)
		return ;
	i = 0;
	temp = stacks->stack_a[0];
	while (i < stacks->size_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[stacks->size_a - 1] = temp;
}

// Reverse Rotate A
// Shift down all elements of 'stack A' by 1.
// The last element becomes the first one.
void	rra(t_stacks *stacks)
{
	int		temp;
	size_t	i;

	ft_printf("rra\n");
	if (stacks->size_a <= 1)
		return ;
	i = stacks->size_a - 1;
	temp = stacks->stack_a[stacks->size_a - 1];
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = temp;
}
