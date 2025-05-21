// This file contains utility functions for manipulating arrays of strings.

#include "libft/libft.h"
#include "push_swap.h"

// FILE
void	free_arr(char **array);
int		count_tokens_in_str(const char *string);
int		count_args(int argc, char **argv);

// arg_check_2.c
char	*concatenate_args(int argc, char **argv);

// libft
char	**ft_split(const char *s, char c);

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
int	count_tokens_in_str(const char *string)
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
