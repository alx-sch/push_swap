/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:21:44 by aschenk           #+#    #+#             */
/*   Updated: 2023/11/24 19:18:46 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function operates similarly to the memset() function, with the distinction
that it automatically writes the NUL character (ASCII: 0) without requiring you
to explicitly specify it. Notably, bzero() does not return any value.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	chars[11] = "ABCDEFGHIJ";
	char	my_chars[11];
	strcpy(my_chars, chars);
	int		bytes_to_zero = 4;

	printf("========================\n");
	printf("== TESTING FT_BZERO() ==\n");
	printf("========================\n\n");

	printf("Setting %d block(s) of memory to NUL:\n\n", bytes_to_zero);

	printf("Lib bzero():\n");
	int i = 0;
	printf("Before: '");
	while (i < 10)
	{
		printf("%c ", chars[i]);
		i++;
	}
	printf("'\n");
	bzero(chars + 5, bytes_to_zero * sizeof(char));
	printf("After: '");
	i = 0;
	while (i < 10)
	{
		printf("%c ", chars[i]);
		i++;
	}
	printf("'\n\n");

	printf("My ft_bzero():\n");
	i = 0;
	printf("Before: '");
	while (i < 10)
	{
		printf("%c ", my_chars[i]);
		i++;
	}
	printf("'\n");
	ft_bzero(my_chars + 5, bytes_to_zero * sizeof(char));
	printf("After (space introduced): '");
	i = 0;
	while (i < 10)
	{
		printf("%c ", my_chars[i]);
		i++;
	}
	printf("'\n\n");

	if (strcmp(chars, my_chars) == 0)
		printf("--> OK!\n\n");
	else
		printf("--> ERROR!\n\n");

	return (0);
}
*/
