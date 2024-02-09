/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_arg_handling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:56:32 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/09 13:08:41 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

// libft
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);

// push_swap project
void	free_array(char **array);
int		count_tokens(char **tokens);

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

static bool	has_only_digits_after_sign(const char *token)
{
	if (!((*token >= '0' && *token <= '9') || *token == '-' || *token == '+'))
		return (false);
	token++;
	while (*token)
	{
		if (!(*token >= '0' && *token <= '9'))
			return (false);
		token++;
	}
	return (true);
}

bool	is_int_overflow(const char *token)
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

bool	is_valid_arg_input(const char *str)
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
		if ((int_value == 0 && *tokens[i] != '0')
			|| !has_only_digits_after_sign(tokens[i])
			|| is_int_overflow(tokens[i]))
		{
			free_array(tokens);
			return (false);
		}
		i++;
	}
	free_array(tokens);
	return (true);
}

int	*return_int_array(char *str)
{
	char	**tokens;
	int		num_tokens;
	int		i;
	int		*int_array;

	tokens = ft_split(str, ' ');
	i = 0;
	if (!tokens)
		return (NULL);
	num_tokens = count_tokens(tokens);
	int_array = (int *)ft_calloc(num_tokens, sizeof(int));
	if (!int_array)
	{
		free_array(tokens);
		return (NULL);
	}
	while (i < num_tokens)
	{
		int_array[i] = ft_atoi(tokens[i]);
		i++;
	}
	free_array(tokens);
	return (int_array);
}



bool	has_duplicates(int **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (ft_strncmp(array[i], array[j], ft_strlen(array[i])) == 0)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}











// bool	is_valid_args(const char *str)
// {
// 	char	**tokens;
// 	int		i;
// 	int		value;

// 	tokens = ft_split(str, ' ');
// 	i = 0;
// 	if (!tokens)
// 		return (false);
// 	while (tokens[i])
// 	{
// 		value = ft_atoi(tokens[i]);

// char	*normalize_int_str

// char	*extract_int(const char *str)
// {
// 	int		len;
// 	char	*int_string;

// 	len = strlen(str);
// 	int_string = (char *)ft_calloc(len * 2, sizeof(char *));
// 	if (!int_string)
// 		exit(EXIT_FAILURE);

//     int i = 0;
//     while (*str) {

//         while (*str && !is_valid_char(*str))
//             str++;

//         // Check if a valid integer starts here
//         if (*str) {
//             // Copy the valid integer to the result string
//             while (*str && (is_valid_char(*str) || *str == ' '))
//                 result[i++] = *str++;
//             // Add a space between integers
//             result[i++] = ' ';
//         }
//     }
//     // Null-terminate the result string
//     result[i] = '\0';

//     return result;
// }



// char	**standardize_number_string(char *str)
// {
// 	char	**substrings;
// 	char	**int_str_arr;
// 	int		i;

// 	i = 0;
// 	substrings = ft_split(str, ' ');
// 	if (!substrings)
// 		return (NULL);
// 	while (substrings[i])
// 		i++;
// 	int_str_arr = (char **)ft_calloc(i + 1, sizeof(char *));
// 	if (!int_str_arr)
// 	{
// 		free_array(substrings);
// 		return (NULL);
// 	}
// 	i = 0;
// 	while (substrings[i])
// 	{
// 		int_str_arr[i] = ft_itoa(ft_atoi(substrings[i]));
// 		if (!int_str_arr[i])
// 		{
// 			free_array(int_str_arr);
// 			free_array(substrings);
// 			return (NULL);
// 		}
// 		i++;
// 	}
// 	free_array(substrings);
// 	return (int_str_arr);
// }


int	*string_to_int_array(const char	*str)
{
	char	**tokens;
	int		size;
	int		*int_arr;
	int		i;

	tokens = ft_split(str, ' ');
	i = -1;
	if (tokens == NULL)
		exit(EXIT_FAILURE);
	size = count_tokens(tokens);
	int_arr = (int *)ft_calloc(size, sizeof(int));
	if (!int_arr)
		exit(EXIT_FAILURE);
	while (++i < size)
		int_arr[i] = ft_atoi(tokens[i]);
	free_array(tokens);
	return (int_arr);
}

int	*argv_to_int_array(int arg_c, char **arg_v)
{
	int	i;
	int	*int_arr;

	i = 1;
	int_arr = (int *)ft_calloc(arg_c - 1, sizeof(int));
	if (!int_arr)
		exit(EXIT_FAILURE);
	while (i <= arg_c)
	{
		if (!is_valid_arg_input(arg_v[i]))
		{
			free(int_arr);
			exit(EXIT_FAILURE);
		}
		int_arr[i - 1] = ft_atoi(arg_v[i]);
		i++;
	}
	return (int_arr);
}


int	main(int argc, char **argv)
{
	char	*concatenated_str;

	if (argc < 2)
		return (1);

	concatenated_str = concatenate_args(argc, argv);
	if (!concatenated_str)
		return (1);

	ft_printf("Concatenated arguments: %s\n", concatenated_str);

	free(concatenated_str);
	return (0);
}
