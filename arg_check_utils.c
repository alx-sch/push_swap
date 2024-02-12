/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:06:47 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/12 13:10:10 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

// libft
char	**ft_split(char const *s, char c);
int		ft_printf(const char *format, ...);

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

// Prints error message and terminates program.
// Exit code retrievable via 'echo $?'.
void	exit_with_message(int exit_code, const char *error_message)
{
	ft_printf("%s", error_message);
	exit(exit_code);
}
