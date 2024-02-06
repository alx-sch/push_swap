/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:56:32 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/06 15:22:02 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);

static void	free_arr(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free (array[i]);
		i++;
	}
	free (array);
}

bool	is_int_string(const char *str)
{
	char	**tokens;
	int		i;
	int		value;

	tokens = ft_split(str, ' ');
	if (!tokens)
		return (false);
	i = 0;
	while (tokens[i])
	{
		value = ft_atoi(tokens[i]);
		if (value == 0 && tokens[i][0] != '0')
		{
			free_arr(tokens);
			return (false);
		}
		i++;
	}
	free_arr(tokens);
	return (true);
}

int	count_tokens(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count] != NULL)
		count++;
	return (count);
}

int	*string_to_int_array(const char	*str)
{
	char	**tokens;
	int		size;
	int		*int_arr;
	int		i;

	tokens = ft_split(str, ' ');
	if (tokens == NULL)
		exit(EXIT_FAILURE);
	size = count_tokens(tokens);
	int_arr = (int *)malloc(size * sizeof(int));
	if (!int_arr)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < size)
		int_arr[i] = ft_atoi(tokens[i]);
	free_arr(tokens);
	return (int_arr);
}
