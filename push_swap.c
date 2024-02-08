/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:55:48 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/08 19:08:35 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int		ft_printf(const char *format, ...);
char	*concatenate_args(int argc, char **argv);
bool	is_valid_args(const char *str);
int		*return_int_array(char *str);


// bool	is_int_string(const char *str);
// int		ft_strncmp(const char *s1, const char *s2, size_t n);
// size_t	ft_strlen(const char *str);
// //int		count_tokens(char **tokens);
// int		*string_to_int_array(const char	*str);
// int		*argv_to_int_array(int arg_c, char **arg_v);
// void	free_array(char **array);


bool	has_duplicates(char **array)
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

#include <stdio.h>

void printIntArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int	main(int argc, char **argv)
{
	char	*input_str;
	int		*int_arr;

	if (argc < 2)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}

	input_str = concatenate_args(argc, argv);
	if (!input_str)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}

	if (!is_valid_args(input_str))
	{
		ft_printf("Error\n");
		free(input_str);
		exit(EXIT_FAILURE);
	}

	int_arr = return_int_array(input_str);

	printIntArray(int_arr, 20);
	//ft_printf("%s", input_str);
	free(int_arr);
	free(input_str);
	// if (arg_c == 2)
	// {
	// 	if (!is_int_string(arg_v[1]))
	// 	{
	// 		ft_printf("Error\n");
	// 		exit(EXIT_FAILURE);
	// 	}
	// 	else
	// 		a_stack_arr = string_to_int_array(arg_v[1]);
	// }
	//else
		//a_stack_arr = argv_to_int_array(arg_c, arg_v);

	//free(a_stack_arr);

	argc = 0;
	argv = NULL;
	// i = 0;
	// input_str = "4 5 4 67";
	// array = ft_split(input_str, ' ');
	// if (!array)
	// {
	// 	ft_printf("Error\n");
	// 	exit (EXIT_FAILURE);
	// }

	// // while (array[i])
	// // {
	// // 	ft_printf("Entry: %s\n", array[i]);
	// // 	i++;
	// // }
	// if (has_duplicates(array))
	// 	ft_printf("Duplicates found!\n");
	// else
	// 	ft_printf("No duplicates found.\n");

	// free_array(array);

	return (0);
}
