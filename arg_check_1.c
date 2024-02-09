/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:56:32 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/09 20:53:27 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	This file implements a function for validating a string representing
//	integer values and contains helper functions for this purpose.
//	Also implements a function to concatenate all provided command-line
//	arguments into a singl string.

#include "libft/libft.h"
#include "push_swap.h" // bool, INT_MAX, INT_MIN

//	FILE
bool	is_valid_int_str(const char *str);
char	*concatenate_args(int argc, char **argv);

//	libft
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

//	utils.c
void	free_arr(char **array);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

//	Checks if a string contains only digits
//	after an optional sign character ('+', '-').
static bool	is_numeric(const char *token)
{
	if (*token >= '0' && *token <= '9')
	{
		while (*token)
		{
			if (!(*token >= '0' && *token <= '9'))
				return (false);
			token++;
		}
		return (true);
	}
	else if (*token == '-' || *token == '+')
	{
		token++;
		if (*token == '\0' || !(*token >= '0' && *token <= '9'))
			return (false);
		while (*token)
		{
			if (!(*token >= '0' && *token <= '9'))
				return (false);
			token++;
		}
		return (true);
	}
	else
		return (false);
}

//	Checks if a string representation of an integer causes overflow
//	when converted to an actual integer value.
static bool	is_int_overflow(const char *token)
{
	int	sign;
	int	int_value;
	int	digit;

	sign = 1;
	int_value = 0;
	if (*token == '-')
	{
		sign = -1;
		token++;
	}
	else if (*token == '+')
		token++;
	while (*token >= '0' && *token <= '9')
	{
		digit = *token - '0';
		if ((sign == 1 && (int_value > INT_MAX / 10
					|| (int_value == INT_MAX / 10 && digit > INT_MAX % 10)))
			|| (sign == -1 && (int_value > INT_MAX / 10
					|| (int_value == INT_MAX / 10 && digit > -(INT_MIN % 10)))))
			return (true);
		int_value = int_value * 10 + digit;
		token++;
	}
	return (false);
}

//	Checks if a string represents the integer value 0 (incl. '+0' and '-0').
static bool	is_zero(const char *token)
{
	bool	is_zero;

	is_zero = (ft_strncmp(token, "0", 2)
			|| ft_strncmp(token, "+0", 3)
			|| ft_strncmp(token, "-0", 3));
	return (is_zero);
}

//	Checks if a string represents valid integer values.
bool	is_valid_int_str(const char *str)
{
	char	**tokens;
	int		i;
	int		int_value;

	tokens = ft_split(str, ' ');
	i = 0;
	if (!tokens)
		return (false);
	while (tokens[i])
	{
		int_value = ft_atoi(tokens[i]);
		if ((int_value == 0 && !is_zero(tokens[i]))
			|| !is_numeric(tokens[i])
			|| is_int_overflow(tokens[i]))
		{
			free_arr(tokens);
			return (false);
		}
		i++;
	}
	free_arr(tokens);
	return (true);
}

//	Concatenates all command-line arguments provided as input
//	into a single string separated by spaces.
char	*concatenate_args(int argc, char **argv)
{
	char	*concat_str;
	char	*arg_with_space_added;
	char	*temp;
	int		i;

	concat_str = "";
	i = 1;
	while (i < argc)
	{
		arg_with_space_added = ft_strjoin(argv[i], " ");
		if (!arg_with_space_added && i != 1)
		{
			free(concat_str);
			return (NULL);
		}
		temp = concat_str;
		concat_str = ft_strjoin(concat_str, arg_with_space_added);
		free(arg_with_space_added);
		if (i != 1)
			free(temp);
		if (!concat_str)
			return (NULL);
		i++;
	}
	return (concat_str);
}
