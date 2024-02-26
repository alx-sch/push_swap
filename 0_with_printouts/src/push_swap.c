/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:55:48 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/26 17:13:51 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

// sorting.c
bool	is_sorted(const t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_more_than_three(t_stacks *stacks);

// stacks_init.c
void	check_args_init_stacks(int argc, char **argv, t_stacks *stacks);
void	exit_free_stacks(int exit_code, const char *error_message,
			t_stacks *stacks);

// stacks_utils.c
void	print_stacks(t_stacks *stacks);

// moves_a.c
void	sa(t_stacks *stacks);

// libft
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_printf(const char *format, ...);

//	+++++++++++++
//	++ PROGRAM ++
//	+++++++++++++

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
	print_stacks(stacks);
	if (!is_sorted(stacks))
	{
		if (stacks->size_a == 2)
			sa(stacks);
		else if (stacks->size_a == 3)
			sort_three(stacks);
		else
			sort_more_than_three(stacks);
	}
	exit_free_stacks(EXIT_SUCCESS, "", stacks);
}
