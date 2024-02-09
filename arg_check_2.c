/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:49:02 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/09 21:37:56 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	This file implements a function for validating command-line arguments,
//	ensuring they represent valid integer values without duplicates.
//	Valid input:
//		- 'Strings', if values are separated by space(s): './push_swap "42 -2"'
//		- Mix of sstring
//		-

#include "libft/libft.h"
#include "push_swap.h" // bool

//	FILE
bool	check_args(int argc, char **argv);

//	libft
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_printf(const char *format, ...);

//	utils.c
void	free_arr(char **array);
int		count_tokens(char **tokens);
int		count_tokens_in_str(char *string);

//	arg_check_1.c
bool	is_valid_int_str(const char *str);
char	*concatenate_args(int argc, char **argv);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

//	Parses a string representing integer values into an array of integers.
//	Return value of ft_atoi() is used as it is 'normalized' ("+042" == "42").
static int	*parse_str_to_int_arr(const char *str)
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
		free_arr(tokens);
		return (NULL);
	}
	while (i < num_tokens)
	{
		int_array[i] = ft_atoi(tokens[i]);
		i++;
	}
	free_arr(tokens);
	return (int_array);
}

//	Converts an array of integers to an array of strings using ft_itoa().
static char	**convert_int_arr_to_str_arr(int *int_array, char *str)
{
	int		num_tokens;
	char	**string_array;
	int		i;

	num_tokens = count_tokens_in_str(str);
	string_array = (char **)ft_calloc((num_tokens + 1), sizeof(char *));
	i = 0;
	if (!string_array)
		return (NULL);
	while (i < num_tokens)
	{
		string_array[i] = ft_itoa(int_array[i]);
		if (!string_array[i])
		{
			free_arr(string_array);
			return (NULL);
		}
		i++;
	}
	string_array[num_tokens] = NULL;
	return (string_array);
}

//	Checks if there are any duplicates in an array of strings.
static bool	has_duplicates(char **array)
{
	int	i;
	int	j;

	i = 0;
	if (!array)
		return (false);
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

//	Checks if command-line arguments are valid integer representations.
//	Prints error message if check fails.
static char	*check_args_pre(int argc, char **argv)
{
	char	*arg_str;

	if (argc < 2)
	{
		ft_printf("Error: Only 1 Arg\n");
		return (NULL);
	}
	arg_str = concatenate_args(argc, argv);
	if (!arg_str)
	{
		ft_printf("Error: No Concat\n");
		return (NULL);
	}
	if (!is_valid_int_str(arg_str))
	{
		ft_printf("Error: No valid ints\n");
		free(arg_str);
		return (NULL);
	}
	ft_printf("Arg string: '%s'\n", arg_str);
	return (arg_str);
}

void print_int_array(int *array, int size) {
	ft_printf("Int array: '");
    for (int i = 0; i < size; i++) {
        ft_printf("%d,", array[i]);
    }
	ft_printf("'\n");
}

void print_string_array(char **array) {
	ft_printf("Str array: '");
    for (int i = 0; array[i] != NULL; i++) {
        ft_printf("%s,", array[i]);
    }
	ft_printf("'\n");
}


//	Validates command-line arguments, ensuring they represent valid
//	integer values without duplicates. Prints error message if check fails.
bool	check_args(int argc, char **argv)
{
	char	*arg_str;
	int		*int_arr;
	char	**str_arr;

	arg_str = check_args_pre(argc, argv);
	if (!arg_str)
		return (false);
	int_arr = parse_str_to_int_arr(arg_str);
	ft_printf("No. args: %d\n", argc -1);
	print_int_array(int_arr, argc -1); /////
	str_arr = convert_int_arr_to_str_arr(int_arr, arg_str); //
	print_string_array(str_arr);
	free(arg_str);
	free(int_arr);
	if (has_duplicates(str_arr))
	{
		ft_printf("Error: Duplicates\n");
		free_arr(str_arr);
		return (false);
	}
	free_arr(str_arr);
	return (true);
}
