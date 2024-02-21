/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:06:47 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/21 21:07:06 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

// FILE
void	free_arr(char **array);
int		count_tokens_in_str(char *string);
int		count_args(int argc, char **argv);
void	exit_free_stacks(int exit_code, char *error_message, t_stacks *stacks);

// arg_check_2.c
char	*concatenate_args(int argc, char **argv);

// libft
char	**ft_split(const char *s, char c);
int		ft_printf(const char *format, ...);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// Frees the memory allocated for an array of strings.
void	free_arr(char **array)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

// Returns the number of tokens (separated by spaces) in a string.
int	count_tokens_in_str(char *string)
{
	size_t		num_tokens;
	char		**tokens;

	num_tokens = 0;
	tokens = ft_split(string, ' ');
	if (!tokens)
		return (num_tokens);
	while (tokens[num_tokens] != NULL)
		num_tokens++;
	free_arr(tokens);
	return (num_tokens);
}

// Counts the number of command-line arguments provided as input.
int	count_args(int argc, char **argv)
{
	char	*arg_str;
	size_t	num_tokens;

	arg_str = concatenate_args(argc, argv);
	num_tokens = count_tokens_in_str(arg_str);
	free(arg_str);
	return (num_tokens);
}

// Frees memory for a t_stacks structure including its members.
static void	free_stacks(t_stacks *stacks)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks->target);
	free(stacks->cost_a);
	free(stacks->cost_b);
	free(stacks);
}

// Prints error message and terminates program.
// Exit code retrievable via 'echo $?' in terminal.
void	exit_free_stacks(int exit_code, char *error_message, t_stacks *stacks)
{
	free_stacks(stacks);
	ft_printf("%s", error_message);
	exit(exit_code);
}
