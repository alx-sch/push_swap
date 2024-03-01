/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:43:13 by aschenk           #+#    #+#             */
/*   Updated: 2024/03/01 11:45:20 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Exit codes, retrievable via 'echo $?'
# define EXIT_SUCCESS 0
# define EXIT_MALLOC_FAILURE 1
# define EXIT_INVALID_INT_INPUT 2
# define EXIT_DUPLICATES 3

# include <stdbool.h> // bool
# include <limits.h> // INT_MAX, etc.

// Structure 't_stacks' is used to manage the state of the stacks.
//
// size_a: Number of elements in stack 'A'.
// size_b: Number of elements in stack 'B'.
// stack_a: An array containing the elements of stack 'A'.
// stack_b: An array containing the elements of stack 'B'.
// target_a: An array storing the target indices in 'B' for each element in 'A'.
// target_b: The target index in stack 'A' for the first element in stack 'B'.
// cost:	An array representing the cost associated with moving respective
//			element in stack 'A' and its target in stack 'B' to the top.
// rr:	A flag array showing if double rotation(s) is required to move
//		respective element in stack 'A' and its target in stack 'B' to the top.
// rrr:	A flag array showing if double reverse-rotation(s) is required to move
//		respective element in stack 'A' and its target in stack 'B' to the top.
typedef struct s_stacks
{
	size_t	size_a;
	size_t	size_b;
	int		*stack_a;
	int		*stack_b;
	size_t	*target_a;
	size_t	target_b;
	int		*cost;
	int		*rr;
	int		*rrr;
}	t_stacks;

//	+++++++++++++
//	++ PROGRAM ++
//	+++++++++++++

// push_swap.c
int		main(int argc, char **argv);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

//	++++++++++++++++++++++
//	INPUT / ERROR HANDLING
//	++++++++++++++++++++++

// arg_check_1.c
bool	is_valid_int_str(const char *str);

// arg_check_2.c
int		*check_and_get_args(int argc, char **argv, t_stacks *stacks);
char	*concatenate_args(int argc, char **argv);

// arg_utils.c
void	free_arr(char **array);
int		count_tokens_in_str(const char *string);
int		count_args(int argc, char **argv);

//	+++++
//	MOVES
//	+++++

// moves_a.c
void	sa(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rra(t_stacks *stacks);

// moves_b.c
void	sb(t_stacks *stacks); // Not used in program.
void	pb(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rrb(t_stacks *stacks);

// moves_ab.c
void	ss(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rrr(t_stacks *stacks);

//	++++++++++++++++++
//	STACK MANIPULATION
//	++++++++++++++++++

// stacks_init.c
void	exit_free_stacks(int exit_code, const char *err_msg, t_stacks *stacks);
void	check_args_init_stacks(int argc, char **argv, t_stacks *stacks);

// stacks_moves.c
void	r_to_top(t_stacks *stacks, const size_t element_to_move);
void	move_cheapest_to_top(t_stacks *stacks);
void	move_b_target_to_top(t_stacks *stacks);

// stacks_utils.c
int		find_max_val(const t_stacks *stacks, const char x);
int		find_min_val(const t_stacks *stacks, const char x);
size_t	find_idx(const t_stacks *stacks, const char x, int value);

//	++++++
//	TARGET
//	++++++

// target.c
void	set_target_a(t_stacks *stacks);
void	set_target_b(t_stacks *stacks);

//	++++++++++++++++
//	COST CALCULATION
//	++++++++++++++++

// cost.c
void	calc_cost(t_stacks *stacks);
size_t	find_cheapest(const t_stacks *stacks);

//	+++++++++++++++++
//	SORTING ALGORITHM
//	+++++++++++++++++

// sorting.c
bool	is_sorted(const t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_more_than_three(t_stacks *stacks);

#endif
