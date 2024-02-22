/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:43:13 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/22 16:54:17 by aschenk          ###   ########.fr       */
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

//
//
// target -> target of stack a elements -> b value
//
typedef struct s_stacks
{
	size_t	size_a;
	size_t	size_b;
	int		*stack_a;
	int		*stack_b;
	size_t	*target_a;
	size_t	*target_b;
	int		*cost_a;
	int		*cost_b;
	int		*rr_a;
	int		*rrr_a;
	int		*rr_b;
	int		*rrr_b;
}	t_stacks;

#endif
