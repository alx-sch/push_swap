/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:44:09 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/22 22:07:43 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// THIS FILE

#include "libft/libft.h"
#include "push_swap.h"

// FILE
void	bring_cheapest_to_top(t_stacks *stacks);

// target.c
void	find_target_a(t_stacks *stacks);

// cost_a.c
void	calc_cost_a(t_stacks *stacks);

// cost_utils.c
size_t	find_cheapest(const t_stacks *stacks, const char x);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// use similiar to fcts in cost_a.c
// static void	to_top_r(t_stacks *stacks)
// {}

// static void	to_top_rr(t_stacks *stacks)
// {}

// static void	to_top_rrr(t_stacks *stacks)
// {}


// brings the cheapest element in a to push to b along with it's target in
// stack b to the top of respective stacks.
void	bring_cheapest_to_top(t_stacks *stacks)
{
	size_t	element_to_move;

	find_target_a(stacks);
	calc_cost_a(stacks);
	element_to_move = find_cheapest(stacks, 'a');
	if (stacks->rr_a[element_to_move])
		ft_printf("\nMoving element %d with rr move\n", element_to_move);
	else if (stacks->rrr_a[element_to_move])
		ft_printf("\nMoving element %d with rrr move\n", element_to_move);
	else
		ft_printf("\nMoving element %d simple style\n", element_to_move);
}
