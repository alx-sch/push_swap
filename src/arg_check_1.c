/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:56:32 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/21 21:05:45 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	This file implements a function for validating a string representing
//	integer values and contains helper functions for this purpose.

#include "libft/libft.h"
#include "push_swap.h"

//	FILE
bool	is_valid_int_str(const char *str);

//	utils.c
void	free_arr(char **array);

//	libft
char	**ft_split(const char *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);

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
	size_t	i;
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
