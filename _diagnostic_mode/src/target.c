// This find contains functions to set the targets for the elements in stack 'A'
// and 'B'. A target represents the element in the opposite stack that is
// closest in value (and smaller or larger for a descending or ascending sorting
// order, respectively).

#include "libft/libft.h"
#include "push_swap.h"

// FILE
void	set_target_a(t_stacks *stacks);
void	set_target_b(t_stacks *stacks);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// stacks_utils.c
int		find_max_val(const t_stacks *stacks, char x);
int		find_min_val(const t_stacks *stacks, const char x);
size_t	find_idx(const t_stacks *stacks, const char x, int value);
void	print_stacks(t_stacks *stacks);

// Sets the target index in 'stack B' for each element in 'stack A'.
// It iterates through each element in 'stack A' and searches for a target in
// 'stack B' that is closest but smaller than the 'stack A' element. If no
// suitable target is found, it selects the max. value in 'stack B' as target.
void	set_target_a(t_stacks *stk)
{
	size_t	i;
	size_t	j;
	size_t	target;

	i = 0;
	ft_printf("\n-- Setting targets for stack 'A' elements --\n");
	while (i < stk->size_a)
	{
		target = SIZE_MAX;
		j = 0;
		ft_printf("\nFinding Target for A[%d]: %d\n", i, stk->stack_a[i]);
		while (j < stk->size_b)
		{
			if (stk->stack_b[j] < stk->stack_a[i]
				&& (target == SIZE_MAX
					|| stk->stack_b[j] > stk->stack_b[target]))
				target = j;
			ft_printf("B[%d]: %d > %d; target: B[%d]\n",
				j, stk->stack_a[i], stk->stack_b[j], target);
			j++;
		}
		if (target == SIZE_MAX)
			stk->target_a[i] = find_idx(stk, 'b', find_max_val(stk, 'b'));
		else
			stk->target_a[i] = target;
		ft_printf("-> Target for A[%d] is B[%d]\n", i, target);
		i++;
	}
	print_stacks(stk);
}

// Sets the target index in 'stack A' for the top element in stack 'B'.
// The target is closest but larger than the stack 'B' element. If no
// suitable target is found, it selects the min. value in 'stack A' as
// target.
// Note: As stack 'B' is already sorted, there is no need to iterate
// through the entire stack again. The target is either the top element
// of stack 'A' or one of the two bottom elements of stack 'A'.
void	set_target_b(t_stacks *stk)
{
	size_t	j;
	size_t	target;

	target = SIZE_MAX;
	j = 0;
	ft_printf("\n-- Setting target for B[0] element --\n");
	ft_printf("\nFinding Target for B[0]: %d\n", stk->stack_b[0]);
	while (j < stk->size_a)
	{
		if (stk->stack_a[j] > stk->stack_b[0]
			&& (target == SIZE_MAX
				|| stk->stack_a[j] < stk->stack_a[target]))
			target = j;
		ft_printf("A[%d]: %d < %d; target: A[%d]\n",
			j, stk->stack_b[0], stk->stack_a[j], target);
		j++;
	}
	if (target == SIZE_MAX)
		stk->target_b = find_idx(stk, 'a', find_min_val(stk, 'a'));
	else
		stk->target_b = target;
	ft_printf("Target for B[0]: %d is A[%d]: %d\n\n", stk->stack_b[0], target, stk->stack_a[stk->target_b]);
}
