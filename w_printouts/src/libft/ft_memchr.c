/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:35:00 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 19:21:26 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memchr() function operates similarly to strchr(), with the distinction that
memchr() handles byte strings (void *) while strchr() is designed for 'literal'
strings (char *). Unlike strchr(), memchr() accommodates various data types,
making it versatile. Additionally, memchr() includes a third parameter, n,
indicating the number of bytes to search within the given data. This parameter
is essential because, unlike 'literal' strings, byte strings lack a
NUL-terminating character. Without this parameter, reading an unpredictable
number of bytes would occur in each invocation.

The casting to unsigned char in ft_memchr() is employed to ensure accurate
comparisons when searching for a particular byte within the memory block
indicated by s. This choice is motivated by the variability of character
representation in C, where the char type can be either signed or unsigned,
contingent on the compiler and platform. In contexts involving raw memory or
byte-wise operations, treating characters as unsigned is a common practice to
prevent unforeseen issues that may arise during value comparisons.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[] = "Hello, World!";
	char to_find = 'o';
	char *result;

	result = ft_memchr(str, to_find, sizeof(str));
	printf("String: '%s'\n", str);
	printf("Byte to be located: '%c'\n", to_find);

	if (result == NULL)
		printf("Character not found\n\n");
	else
		printf("Character found at position %ld\n\n", result - str);

	to_find = '\0';
	result = ft_memchr(str, to_find, sizeof(str));
	printf("String: '%s'\n", str);
	printf("Byte to be located: '%c'\n", to_find);
	if (result == NULL)
		printf("Character not found\n\n");
	else
		printf("Character found at position %ld\n\n", result - str);

	to_find = 'x';
	result = ft_memchr(str, to_find, sizeof(str));
	printf("String: '%s'\n", str);
	printf("Byte to be located: '%c'\n", to_find);
	if (result == NULL)
		printf("Character not found\n\n");
	else
		printf("Character found at position %ld\n\n", result - str);

	return (0);
}
*/
