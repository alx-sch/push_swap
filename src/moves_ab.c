/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:42:43 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/22 19:17:15 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// THIS FILE

#include "libft/libft.h"
#include "push_swap.h"

//	FILE
void	ss(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rrr(t_stacks *stacks);

// libft
int		ft_printf(const char *format, ...);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// Swap A & B at the same time
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

// Helper fct for rr() (to keep the line limit)
static void	rotate_stack(int *stack, size_t size)
{
	int		temp;
	size_t	i;

	if (size < 2)
		return ;
	temp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = temp;
}

// Rotate A & B at the same time
// Shift up all elements of both stacks by 1.
// The first elements become the last ones.
void	rr(t_stacks *stacks)
{
	ft_printf("rr\n");
	rotate_stack(stacks->stack_a, stacks->size_a);
	rotate_stack(stacks->stack_b, stacks->size_b);
}

// Helper fct for rrr() (to keep the line limit)
static void	r_rotate_stack(int *stack, size_t size)
{
	int		temp;
	size_t	i;

	if (size < 2)
		return ;
	temp = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
}

// Reverse Rotate A & B
// Shift down all elements of both stacks by 1.
// The last elements become the first ones.
void	rrr(t_stacks *stacks)
{
	ft_printf("rrr\n");
	r_rotate_stack(stacks->stack_a, stacks->size_a);
	r_rotate_stack(stacks->stack_b, stacks->size_b);
}
