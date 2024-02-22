/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:55:48 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/22 21:30:56 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

// stacks_init.c
void	check_args_init_stacks(int argc, char **argv, t_stacks *stacks);
void	exit_free_stacks(int exit_code, char *error_message, t_stacks *stacks);

// sorting.c
bool	is_sorted_a(const t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_more_than_three(t_stacks *stacks);

// moves_a.c
void	sa(t_stacks *stacks);

// libft
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_printf(const char *format, ...);

//	+++++++++++++
//	++ PROGRAM ++
//	+++++++++++++

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
	i = 0;
	ft_printf("\nStack B: ");
	while (i < stacks->size_b)
	{
		ft_printf("%d ", stacks->stack_b[i]);
		i++;
	}
	i = 0;
	ft_printf("\nTarget for A: ");
	while (i < stacks->size_a)
	{
		ft_printf("%d ", stacks->target_a[i]);
		i++;
	}
	i = 0;
	ft_printf("\nCost for A: ");
	while (i < stacks->size_a)
	{
		ft_printf("%d ", stacks->cost_a[i]);
		i++;
	}
	i = 0;
	ft_printf("\nRR A: ");
	while (i < stacks->size_a)
	{
		ft_printf("%d ", stacks->rr_a[i]);
		i++;
	}
	i = 0;
	ft_printf("\nRRR A: ");
	while (i < stacks->size_a)
	{
		ft_printf("%d ", stacks->rrr_a[i]);
		i++;
	}
	ft_printf("\n\n");
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
	{
		ft_printf("Error\n");
		exit(EXIT_MALLOC_FAILURE);
	}
	check_args_init_stacks(argc, argv, stacks);
	if (!is_sorted_a(stacks))
	{
		if (stacks->size_a == 2)
			sa(stacks);
		else if (stacks->size_a == 3)
			sort_three(stacks);
		else
			sort_more_than_three(stacks);
	}
	print_stacks(stacks);
	exit_free_stacks(EXIT_SUCCESS, "", stacks);
}

/*
// TESTING MOVES

// moves_a.c
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

	/// TESTING MOVES
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
