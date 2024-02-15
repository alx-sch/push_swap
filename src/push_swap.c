/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:55:48 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/15 19:34:59 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h" // exit codes

// arg_check_2.c
int		*check_args(int argc, char **argv);

// operations_a.c
void	sa(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rrr(t_stacks *stacks);

//	+++++++++++++
//	++ PROGRAM ++
//	+++++++++++++


int	main(int argc, char **argv)
{
	int			*arg_arr;

	arg_arr = check_args(argc, argv);
	free(arg_arr);
	exit(EXIT_SUCCESS);
}

/// TESTING OPERATIONS
/*
void	print_stack_a(t_stacks *stacks)
{
	size_t	i;

	i = 0;
	ft_printf("Stack A: ");
	while (i < stacks->size_a)
	{
		ft_printf("%d ", stacks->stack_a[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_stack_b(t_stacks *stacks)
{
	size_t	i;

	i = 0;
	ft_printf("Stack B: ");
	while (i < stacks->size_b)
	{
		ft_printf("%d ", stacks->stack_b[i]);
		i++;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	int			*arg_arr;
	t_stacks	stacks;
	size_t		i;

	stacks.size_a = 10;
	stacks.size_b = 10;
	stacks.stack_a = (int *)ft_calloc(stacks.size_a + stacks.size_b, sizeof(int));
	stacks.stack_b = (int *)ft_calloc(stacks.size_a + stacks.size_b, sizeof(int));

	i = 0;
	while (i < stacks.size_a)
	{
		stacks.stack_a[i] = 0 - i;
		i++;
	}
	i = 0;
	while (i < stacks.size_b)
	{
		stacks.stack_b[i] = 20 + i;
		i++;
	}

	print_stack_a(&stacks);
	print_stack_b(&stacks);

	sa(&stacks);
	print_stack_a(&stacks);
	print_stack_b(&stacks);
	ft_printf("");

	pa(&stacks);
	print_stack_a(&stacks);
	print_stack_b(&stacks);
	ft_printf("");

	ra(&stacks);
	print_stack_a(&stacks);
	print_stack_b(&stacks);
	ft_printf("");

	rra(&stacks);
	print_stack_a(&stacks);
	print_stack_b(&stacks);
	ft_printf("");

	rrb(&stacks);
	print_stack_a(&stacks);
	print_stack_b(&stacks);
	ft_printf("");

	rb(&stacks);
	print_stack_a(&stacks);
	print_stack_b(&stacks);
	ft_printf("");

	pb(&stacks);
	print_stack_a(&stacks);
	print_stack_b(&stacks);
	ft_printf("");

	sb(&stacks);
	print_stack_a(&stacks);
	print_stack_b(&stacks);
	ft_printf("");

	ss(&stacks);
	print_stack_a(&stacks);
	print_stack_b(&stacks);
	ft_printf("");

	rr(&stacks);
	print_stack_a(&stacks);
	print_stack_b(&stacks);
	ft_printf("");

	rrr(&stacks);
	print_stack_a(&stacks);
	print_stack_b(&stacks);
	ft_printf("");


	free(stacks.stack_a);
	free(stacks.stack_b);

	arg_arr = check_args(argc, argv);
	free(arg_arr);
	exit(EXIT_SUCCESS);
}
*/
