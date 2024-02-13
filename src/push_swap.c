/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:55:48 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/12 13:01:12 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h" // exit codes

// arg_check_2.c
int		*check_args(int argc, char **argv);

//	+++++++++++++
//	++ PROGRAM ++
//	+++++++++++++

int	main(int argc, char **argv)
{
	int	*arg_arr;

	arg_arr = check_args(argc, argv);
	free(arg_arr);
	exit(EXIT_SUCCESS);
}
