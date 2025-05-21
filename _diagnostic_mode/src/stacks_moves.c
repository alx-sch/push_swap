// THIS FILE

#include "libft/libft.h"
#include "push_swap.h"

// FILE
void	r_to_top(t_stacks *stacks, const size_t element_to_move);
void	move_cheapest_to_top(t_stacks *stacks);
void	move_b_target_to_top(t_stacks *stacks);

// moves_a.c
void	ra(t_stacks *stacks);
void	rra(t_stacks *stacks);

// moves_b.c
void	rb(t_stacks *stacks);
void	rrb(t_stacks *stacks);

// moves_ab.c
void	rr(t_stacks *stacks);
void	rrr(t_stacks *stacks);

// target.c
void	set_target_a(t_stacks *stk);
void	set_target_b(t_stacks *stk);

// cost.c
void	calc_cost(t_stacks *stacks);
size_t	find_cheapest(const t_stacks *stacks);


//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// Moves a stack 'A' element and it's target to the top of their stacks
// using only 'single rotations' (ra, rra, rb, rrb).
void	r_to_top(t_stacks *stacks, const size_t element_to_move)
{
	int		a_value;
	int		b_value;
	size_t	median_a;
	size_t	median_b;

	a_value = stacks->stack_a[element_to_move];
	b_value = stacks->stack_b[stacks->target_a[element_to_move]];
	median_a = stacks->size_a / 2;
	median_b = stacks->size_b / 2;
	if (stacks->size_a % 2 == 1)
		median_a += 1;
	if (stacks->size_b % 2 == 1)
		median_b += 1;
	if (element_to_move < median_a)
		while (stacks->stack_a[0] != a_value)
			ra(stacks);
	else
		while (stacks->stack_a[0] != a_value)
			rra(stacks);
	if (stacks->target_a[element_to_move] < median_b)
		while (stacks->stack_b[0] != b_value)
			rb(stacks);
	else
		while (stacks->stack_b[0] != b_value)
			rrb(stacks);
}

// Moves a stack 'A' element and it's target to the top of their stacks
// using double rotations ('rr') and, if needed, 'single' rotations.
static void	rr_to_top(t_stacks *stacks, const size_t element_to_move)
{
	int	a_value;
	int	b_value;

	a_value = stacks->stack_a[element_to_move];
	b_value = stacks->stack_b[stacks->target_a[element_to_move]];
	while (stacks->stack_a[0] != a_value && stacks->stack_b[0] != b_value)
		rr(stacks);
	while (stacks->stack_a[0] != a_value)
		ra(stacks);
	while (stacks->stack_b[0] != b_value)
		rb(stacks);
}

// Moves a stack 'A' element and it's target to the top of their stacks
// using double reverse rotations ('rrr') and, if needed,
// 'single' reverse rotations.
static void	rrr_to_top(t_stacks *stacks, const size_t element_to_move)
{
	int	a_value;
	int	b_value;

	a_value = stacks->stack_a[element_to_move];
	b_value = stacks->stack_b[stacks->target_a[element_to_move]];
	while (stacks->stack_a[0] != a_value && stacks->stack_b[0] != b_value)
		rrr(stacks);
	while (stacks->stack_a[0] != a_value)
		rra(stacks);
	while (stacks->stack_b[0] != b_value)
		rrb(stacks);
}

// Moves the cheapest to push element in stack 'A' and it's corresponding target
// to the top of their respective stacks in the most cost-effective manner.
void	move_cheapest_to_top(t_stacks *stacks)
{
	size_t	element_to_move;

	set_target_a(stacks);
	calc_cost(stacks);
	element_to_move = find_cheapest(stacks);
	ft_printf("\n-- Move 'A' element + target that is cheapest to move to top--\n");
	ft_printf("-> A[%d] and B[%d] to the top:\n", element_to_move, stacks->target_a[element_to_move]);
	if (stacks->rr[element_to_move])
		rr_to_top(stacks, element_to_move);
	else if (stacks->rrr[element_to_move])
		rrr_to_top(stacks, element_to_move);
	else
		r_to_top(stacks, element_to_move);
}

// Moves the target of the first element in stack 'B' to the top of stack 'A'.
// This is achieved by either by rotating or reverse-rotating stack 'A',
// depending on which operation is more cost-efficient.
void	move_b_target_to_top(t_stacks *stacks)
{
	int		a_value;
	size_t	median_a;
	size_t	element_to_move;

	set_target_b(stacks);
	element_to_move = stacks->target_b;
	a_value = stacks->stack_a[element_to_move];
	median_a = stacks->size_a / 2;
	ft_printf("-- Moving B[0] target to top --\n");
	ft_printf("-> A[%d]: %d\n\n", element_to_move, a_value);
	if (stacks->size_a % 2 == 1)
		median_a += 1;
	if (element_to_move < median_a)
		while (stacks->stack_a[0] != a_value)
			ra(stacks);
	else
		while (stacks->stack_a[0] != a_value)
			rra(stacks);
}
