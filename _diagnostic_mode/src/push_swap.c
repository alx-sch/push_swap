#include "libft/libft.h"
#include "push_swap.h"

// sorting.c
bool	is_sorted(const t_stacks *stacks);
bool	is_circularly_sorted(const t_stacks *stacks);
void	sort_stack(t_stacks *stacks);
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
		else if (is_circularly_sorted(stacks))
			sort_stack(stacks);
		else
			sort_more_than_three(stacks);
	}
	ft_printf("\n'A' is sorted!\n");
	exit_free_stacks(EXIT_SUCCESS, "", stacks);
}
