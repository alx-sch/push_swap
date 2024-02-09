/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:55:48 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/09 20:38:06 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int		ft_printf(const char *format, ...);
// char	*concatenate_args(int argc, char **argv);
// bool	is_valid_int_str(const char *str);
// int		*parse_str_to_int_arr(const char *str);

// arg_check_2.c
bool	check_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	if (!check_args(argc, argv))
		exit(EXIT_FAILURE);
	return (0);
}
