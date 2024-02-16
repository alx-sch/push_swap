/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:55:48 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/16 17:31:55 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

// arg_check_2.c
int		*check_and_get_args(int argc, char **argv);

// stacks.c
void	check_args_init_stacks(int argc, char **argv, t_stacks *stacks);

// utils.c
void	exit_free_stacks(int exit_code, const char *error_message,
			t_stacks *stacks);

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
	t_stacks	*stacks;

	stacks = ft_calloc(1, sizeof(t_stacks));
	check_args_init_stacks(argc, argv, stacks);

	exit_free_stacks(EXIT_SUCCESS, "", stacks);
}

// TESTING OPERATIONS
/*
void	print_stacks(t_stacks *stacks)
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
	i = 0;
	ft_printf("Stack B: ");
	while (i < stacks->size_b)
	{
		ft_printf("%d ", stacks->stack_b[i]);
		i++;
	}
	ft_printf("\n\n");
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = ft_calloc(1, sizeof(t_stacks));
	check_args_init_stacks(argc, argv, stacks);

	/// TESTING OPERATIONS
	print_stacks(stacks);

	sa(stacks);
	print_stacks(stacks);

	pa(stacks);
	print_stacks(stacks);

	ra(stacks);
	print_stacks(stacks);

	rra(stacks);
	print_stacks(stacks);

	rrb(stacks);
	print_stacks(stacks);

	rb(stacks);
	print_stacks(stacks);

	pb(stacks);
	print_stacks(stacks);

	pb(stacks);
	print_stacks(stacks);

	pb(stacks);
	print_stacks(stacks);

	pb(stacks);
	print_stacks(stacks);

	ra(stacks);
	print_stacks(stacks);

	rra(stacks);
	print_stacks(stacks);

	pb(stacks);
	print_stacks(stacks);

	pb(stacks);
	print_stacks(stacks);

	sb(stacks);
	print_stacks(stacks);

	ss(stacks);
	print_stacks(stacks);

	rr(stacks);
	print_stacks(stacks);

	rrr(stacks);
	print_stacks(stacks);

	exit_free_stacks(EXIT_SUCCESS, "", stacks);
}
*/
