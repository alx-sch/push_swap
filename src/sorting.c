/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:20:37 by aschenk           #+#    #+#             */
/*   Updated: 2024/02/16 17:32:26 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

// FILE
bool	is_sorted(int	*array, size_t size);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// Checks if an array of integers is sorted from smalles to largest.
bool	is_sorted(int	*array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (false);
		i++;
	}
	return (true);
}
