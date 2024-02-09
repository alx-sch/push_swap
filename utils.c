/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:06:47 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/09 18:59:38 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

// libft
char	**ft_split(char const *s, char c);

// Frees the memory allocated for an array of strings.
void	free_arr(char **array)
{
	int	i;

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

// Returns the number of tokens in an array of strings.
int	count_tokens(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count] != NULL)
		count++;

	return (count);
}

// Returns the number of tokens (separated by spaces) in a string.
int	count_tokens_in_str(char *string)
{
	int		num_tokens;
	char	**tokens;

	tokens = ft_split(string, ' ');
	num_tokens = count_tokens(tokens);
	free_arr(tokens);

	return (num_tokens);
}
