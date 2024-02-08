/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_arg_handling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:56:32 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/08 19:21:29 by aschenk          ###   ########.fr       */
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


int	ft_atoi_no_overflow(const char *nptr)
{
	int	sign;
	int	res;
	int	digit;

	sign = 1;
	res = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		sign = sign * -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		digit = *nptr - '0';
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10))
			return (0);
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (res * sign);
}

char	*concatenate_args(int argc, char **argv)
{
	char	*concat_str;
	char	*arg_with_space_str;
	char	*temp;
	int		i;

	concat_str = "";
	i = 1;
	while (i < argc)
	{
		arg_with_space_str = ft_strjoin(argv[i], " ");
		if (!arg_with_space_str && i != 1)
		{
			free(concat_str);
			return (NULL);
		}
		temp = concat_str;
		concat_str = ft_strjoin(concat_str, arg_with_space_str);
		free(arg_with_space_str);
		if (i != 1)
			free(temp);
		if (!concat_str)
			return (NULL);
		i++;
	}
	return (concat_str);
}

static bool	has_only_digits_after_sign(const char *str)
{
	if (!((*str >= '0' && *str <= '9') || *str == '-' || *str == '+'))
		return (false);
	str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (false);
		str++;
	}
	return (true);
}


bool	is_valid_args(const char *str)
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
			|| !has_only_digits_after_sign(tokens[i]))
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
	num_tokens = 0;
	i = 0;
	if (!tokens)
		return (NULL);
	while (tokens[num_tokens])
		num_tokens++;
	int_array = (int *)ft_calloc(num_tokens, sizeof(int));
	if (!int_array)
	{
		free_array(tokens);
		return (NULL);
	}
	while (i < num_tokens)
	{
		#add overflow check -> retunr (NULL);

		int_array[i] = ft_atoi(tokens[i]);
		i++;
	}
	free_array(tokens);
	return (int_array);
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
		if (!is_valid_args(arg_v[i]))
		{
			free(int_arr);
			exit(EXIT_FAILURE);
		}
		int_arr[i - 1] = ft_atoi(arg_v[i]);
		i++;
	}
	return (int_arr);
}
