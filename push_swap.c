/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:55:48 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/05 20:15:07 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	main(int arg_c, char **arg_v)
{
	int	i;

	if (arg_c < 2)
	{
		ft_printf("ERROR - Usage: %s <integer1> <integer2> ...\n", arg_v[0]);
		return (1);
	}
	ft_printf("Input integers: ");

	i = 1;
	while (i < arg_c)
	{
		ft_printf("%s ", arg_v[i]);
		i++;
	}

	ft_printf("\n");

	return (0);
}
