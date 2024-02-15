/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:43:13 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/15 19:40:12 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// exit codes
# define EXIT_SUCCESS 0
# define EXIT_NO_ARGS 1
# define EXIT_MALLOC_FAILURE 2
# define EXIT_INVALID_INT_INPUT 3
# define EXIT_DUPLICATES 4

# include <stdbool.h> // bool
# include <limits.h> // INT_MAX, etc.

typedef struct s_stacks
{
	int		*stack_a;
	int		*stack_b;
	int		*stack_tmp;
	size_t	size_a;
	size_t	size_b;
	int		*b_target;
	int		*cost_a;
	int		*cost_b;
}	t_stacks;


// int	push_swap(const char *format, ...);

#endif
