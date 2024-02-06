/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:55:48 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/06 15:29:06 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int		ft_printf(const char *format, ...);
bool	is_int_string(const char *str);
int		*string_to_int_array(const char	*str);
int		count_tokens(char **tokens);




int	main(int arg_c, char **arg_v)
{
	int	*int_array;

	if (arg_c < 2)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (arg_c == 2)
	{
		if (!is_int_string(arg_v[1]))
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			int_array = string_to_int_array(arg_v[1]);
			ft_printf("%d\n", int_array[2]);
		}
	}
	return (0);
}
