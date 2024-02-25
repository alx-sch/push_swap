/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:06:07 by aschenk           #+#    #+#             */
/*   Updated: 2024/01/20 20:21:19 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

memcmp() is a function designed for comparing byte strings, functioning in a
manner similar to strncmp(). Notably, memcmp() operates on void pointers,
facilitating its use with byte strings. Its distinctive feature lies in the
addition of a third parameter, 'n', indicating the number of initial bytes
to be compared.

The return value of memcmp() hinges on the nature of the differences detected:
-	If no distinctions are found between the two strings, the return value is 0.
-	In cases where a difference is present, and the first differing character in
	the second string (s2) is greater than the corresponding byte in the first
	string (s1), the result will be negative.
-	If the first differing character in s2 is less than the character at the same
	position in s1, the result will be positive.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	i = 0;
	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		n;
	char	string1[50];
	char	string2[50];

	n = 9;
	strcpy(string1, "1234567890");
	strcpy(string2, "1234567");

	printf(" \n");
	printf("== TEST ==\nMemory 1: %s\nMemory 2: %s\nn:%d\n", string1,
		string2, n);
	printf("Result memcmp(): %d\n", memcmp(string1, string2, n));
	printf("Result 'my' ft_memcmp(): %d\n", ft_memcmp(string1,
		string2, n));

	return (0);
}
*/
